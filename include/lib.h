#ifndef LIB_H
#define LIB_H

#include <time.h>

#define lib_on_init(callback)   lib_callback_t *lib_on_init   = (lib_callback_t *)(callback)
#define lib_on_load(callback)   lib_callback_t *lib_on_load   = (lib_callback_t *)(callback)
#define lib_on_update(callback) lib_callback_t *lib_on_update = (lib_callback_t *)(callback)
#define lib_on_unload(callback) lib_callback_t *lib_on_unload = (lib_callback_t *)(callback)
#define lib_on_deinit(callback) lib_callback_t *lib_on_deinit = (lib_callback_t *)(callback)

enum {
    LIB_INIT = 0,
    LIB_LOAD,
    LIB_UPDATE,
    LIB_UNLOAD,
    LIB_DEINIT,
    LIB_CALLBACKS_COUNT,
};

typedef struct lib lib_t;
typedef void (*lib_callback_t)(lib_t *);

struct lib {
    /* read only */
    char    library_name[100];
    char    backup_name[107];

    void   *handler;
    time_t  timestamp;

    lib_callback_t *callbacks[LIB_CALLBACKS_COUNT];

    /* read & write */
    void   *data;
    size_t  data_size;
};

void lib_init(lib_t *lib, char const *library_name);
void lib_update(lib_t *lib);
void lib_deinit(lib_t *lib);

#endif /* LIB_H */

#define LIB_IMPL
#ifdef LIB_IMPL

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include <sys/stat.h>
#include <dlfcn.h>

static bool lib_modified(lib_t *lib, time_t *timestamp)
{
    struct stat lib_stats;
    if (stat(lib->library_name, &lib_stats) != 0)
        return false;

    *timestamp = lib_stats.st_mtime;

    if (lib_stats.st_mtime == lib->timestamp || lib_stats.st_size == 0)
        return false;

    return true;
}

static void lib_create_backup(lib_t *lib)
{
    FILE *library;
    FILE *backup;

    char buffer[BUFSIZ];
    size_t size;

    library = fopen(lib->library_name, "rb");
    if (library == NULL)
        return;

    backup = fopen(lib->backup_name, "wb");
    if (backup == NULL) {
        fclose(library);
        return;
    }

    while ((size = fread(buffer, 1, BUFSIZ, library)) > 0)
        fwrite(buffer, 1, size, backup);

    fclose(library);
    fclose(backup);
}

void lib_init(lib_t *lib, char const *library_name)
{
    memset(lib, 0, sizeof(lib_t));

    strcpy(lib->library_name, library_name);
    strcpy(lib->backup_name, library_name);
    strcat(lib->backup_name, "-backup");
}

void lib_update(lib_t *lib)
{
    bool first_update = lib->handler == NULL;
    time_t timestamp;

    // Check if the file was modified for reload it
    if (!lib_modified(lib, &timestamp)) {
        // Generate the update event
        if (lib->callbacks[LIB_UPDATE] != NULL)
            (*lib->callbacks[LIB_UPDATE])(lib);

        return;
    }

    if (!first_update) {
        // Generate the unload event
        if (lib->callbacks[LIB_UNLOAD] != NULL)
            (*lib->callbacks[LIB_UNLOAD])(lib);

        // Unload the library and reset callbacks
        dlclose(lib->handler);
        // TODO: implemente default callbacks for log?
        memset(&lib->callbacks, 0, sizeof lib->callbacks);
    }

    // Load the library
    lib->handler = dlopen(lib->library_name, RTLD_LAZY | RTLD_LOCAL);
    if (lib->handler == NULL) {
        if (first_update)
            return;

        lib->handler = dlopen(lib->backup_name, RTLD_LAZY | RTLD_LOCAL);
        if (lib->handler == NULL)
            return;
    } else {
        // Create backup
        lib_create_backup(lib);

        // Update timestamp
        lib->timestamp = timestamp;
    }

    char const *callback_names[LIB_CALLBACKS_COUNT] = {
        "lib_on_init", "lib_on_load", "lib_on_update", "lib_on_unload", "lib_on_deinit"
    };

    for (int i = 0; i < LIB_CALLBACKS_COUNT; i++)
        lib->callbacks[i] = dlsym(lib->handler, callback_names[i]);

    if (first_update)
        // Generate the init event
        if (lib->callbacks[LIB_INIT] != NULL)
            (*lib->callbacks[LIB_INIT])(lib);

    // Generate the load event
    if (lib->callbacks[LIB_LOAD] != NULL)
        (*lib->callbacks[LIB_LOAD])(lib);
}

void lib_deinit(lib_t *lib)
{
    if (lib->handler != NULL) {
        // Generate the deinit event
        if (lib->callbacks[LIB_DEINIT] != NULL)
            (*lib->callbacks[LIB_DEINIT])(lib);

        dlclose(lib->handler);
    }

    remove(lib->backup_name);
    memset(lib, 0, sizeof(lib_t));
}

#endif /* LIB_IMPL */

