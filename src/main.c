#include <stdio.h>
#include <stdlib.h>

#define GLAD_GL_IMPLEMENTATION
#include <glad/gl.h>

#include <GLFW/glfw3.h>

#define LIB_IMPL
#include "lib.h"

#define WINDOW_TITLE  "OpenGL"
#define WINDOW_WIDTH  480
#define WINDOW_HEIGHT 360

int main(void)
{
    GLFWwindow *window = NULL;

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

    lib_t render_lib;
    lib_init(&render_lib, "target/lib/librender.so");

    /* Main loop */
    while (!glfwWindowShouldClose(window)) {
        glClearColor(0, 0, 0, 0);
        glClear(GL_COLOR_BUFFER_BIT);

        lib_update(&render_lib);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    lib_deinit(&render_lib);

    /* GLFW de-initialization */
    glfwDestroyWindow(window);
    glfwTerminate();

    return EXIT_SUCCESS;
}

