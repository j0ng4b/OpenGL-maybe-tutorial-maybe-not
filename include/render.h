#ifndef RENDER_H
#define RENDER_H

#undef GLAD_GL_IMPLEMENTATION
#include <glad/gl.h>

typedef struct render {
    void *(*init)(GLADloadfunc loader);
    void  (*draw)(void *);
    void  (*terminate)(void *);
    void *data;
} render_t;

#endif /* end of include guard: RENDER_H */

