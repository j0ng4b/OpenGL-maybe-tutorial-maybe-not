#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <sys/stat.h>
#include <dlfcn.h>

#define GLAD_GL_IMPLEMENTATION
#include <glad/gl.h>

#include <GLFW/glfw3.h>

#include "render.h"

#define WINDOW_TITLE  "OpenGL"
#define WINDOW_WIDTH  480
#define WINDOW_HEIGHT 360

void load_code(render_t **render, void **lib, time_t *last_lib_mod_time)
{
    struct stat lib_stat;
    if (stat("target/lib/librender.so", &lib_stat) == 0)
        if (*last_lib_mod_time > 0
                && (lib_stat.st_mtim.tv_sec <= *last_lib_mod_time
                || lib_stat.st_size == 0))
            return;

    if (*lib != NULL)
        dlclose(*lib);

    void *new_lib = dlopen("target/lib/librender.so", RTLD_LAZY | RTLD_LOCAL);
    if (new_lib == NULL) {
        new_lib = dlopen("target/lib/librender-copy.so", RTLD_LAZY | RTLD_LOCAL);

        if (new_lib == NULL) {
            perror("Error");
            printf("Can't load render copy library due \"%s\"\n", dlerror());
            return;
        }
    } else {
        FILE *lib_origin = fopen("target/lib/librender.so", "rb");
        if (lib_origin == NULL) {
            perror("Can't open library file to copy: ");
            return;
        }

        FILE *lib_copy = fopen("target/lib/librender-copy.so", "wb");
        if (lib_copy == NULL) {
            perror("Can't open destination library file of copy: ");
            return;
        }

        char bytes[128];
        while (!feof(lib_origin)) {
            int bytes_readed = fread(bytes, sizeof(char), sizeof bytes, lib_origin);
            if (bytes_readed > 0)
                fwrite(bytes, sizeof(char), bytes_readed, lib_copy);
        }

        fclose(lib_origin);
        fclose(lib_copy);

        *last_lib_mod_time = lib_stat.st_mtim.tv_sec;
    }

    *lib = new_lib;

    dlerror();
    render_t *new_render = (render_t *) dlsym(new_lib, "render");
    if (new_render != NULL) {
        if (*render != NULL)
            new_render->data = (*render)->data;
        else
            new_render->data = NULL;
    } else {
        new_render = *render;
        printf("Can't load render functions: %s\n", dlerror());
    }

    *render = new_render;
}

int main(void)
{
    GLFWwindow *window = NULL;

    render_t *render = NULL;
    void *render_lib = NULL;
    time_t render_lib_mod_time = 0;

    /* GLFW initialization */
    if (!glfwInit())
        return EXIT_FAILURE;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE, NULL, NULL);
    if (window == NULL) {
        glfwTerminate();
        return EXIT_FAILURE;
    }
    glfwMakeContextCurrent(window);

    /* Glad initialization */
    gladSetGLOnDemandLoader((GLADloadfunc) glfwGetProcAddress);

    /* OpenGL initialization */
    glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);

    /* Main loop */
    while (!glfwWindowShouldClose(window)) {
        load_code(&render, &render_lib, &render_lib_mod_time);
        if (render->data == NULL)
            render->data = render->init((GLADloadfunc) glfwGetProcAddress);

        glClearColor(0, 0, 0, 0);
        glClear(GL_COLOR_BUFFER_BIT);

        render->draw(render->data);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    render->terminate(render->data);

    /* GLFW de-initialization */
    glfwDestroyWindow(window);
    glfwTerminate();

    return EXIT_SUCCESS;
}

