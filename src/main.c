#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define GLAD_GL_IMPLEMENTATION
#include <glad/gl.h>

#include <GLFW/glfw3.h>

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

    // Vertices data
    GLfloat vertices[] = {
         0.0f, 0.5f, 0, 1, 0,
         0.5f, 0.0f, 1, 0, 0,
        -0.5f, 0.0f, 0, 0, 1,
    };

    // Vertex buffer object
    GLuint vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof vertices, vertices, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    int status;

    // Vertex shader
    const char *vert_shader_source =
        "#version 330\n"
        "\n"
        "layout (location = 0) in vec2 pos;\n"
        "layout (location = 1) in vec3 col;\n"
        "out vec3 vcol;\n"
        "\n"
        "void main() {\n"
        "   vcol = col;\n"
        "   gl_Position = vec4(pos, 0, 1);\n"
        "}\n"
        "\n";
    GLuint vert_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vert_shader, 1, &vert_shader_source, NULL);
    glCompileShader(vert_shader);
    glGetShaderiv(vert_shader, GL_COMPILE_STATUS, &status);
    if (status == GL_FALSE) {
        char msg[1024];
        glGetShaderInfoLog(vert_shader, sizeof msg, NULL, msg);
        printf("Shader compilation error: %s\n", msg);
    }

    // Fragment shader
    const char *frag_shader_source =
        "#version 330\n"
        "\n"
        "in vec3 vcol;"
        "out vec4 col;\n"
        "\n"
        "void main() {\n"
        "    col = vec4(vcol, 1);"
        "}\n"
        "\n";
    GLuint frag_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(frag_shader, 1, &frag_shader_source, NULL);
    glCompileShader(frag_shader);
    glGetShaderiv(frag_shader, GL_COMPILE_STATUS, &status);
    if (status == GL_FALSE) {
        char msg[1024];
        glGetShaderInfoLog(frag_shader, sizeof msg, NULL, msg);
        printf("Shader compilation error: %s\n", msg);
    }

    // Program object
    GLuint prog = glCreateProgram();
    glAttachShader(prog, vert_shader);
    glAttachShader(prog, frag_shader);
    glLinkProgram(prog);
    glGetProgramiv(prog, GL_LINK_STATUS, &status);
    if (status == GL_FALSE) {
        char msg[1024];
        glGetProgramInfoLog(prog, sizeof msg, NULL, msg);
        printf("Program link error: %s", msg);
    }

    glDetachShader(prog, vert_shader);
    glDetachShader(prog, frag_shader);

    glDeleteShader(vert_shader);
    glDeleteShader(frag_shader);

    // Vertex array object
    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 5, NULL);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 5, (void *)(sizeof(GLfloat) * 2));
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    /* Main loop */
    while (!glfwWindowShouldClose(window)) {
        glClearColor(0, 0, 0, 0);
        glClear(GL_COLOR_BUFFER_BIT);

        glBindVertexArray(vao);
        glUseProgram(prog);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glUseProgram(0);
        glBindVertexArray(0);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    /* OpenGL de-initialization */
    glDeleteProgram(prog);
    glDeleteBuffers(1, &vbo);

    /* GLFW de-initialization */
    glfwDestroyWindow(window);
    glfwTerminate();

    return EXIT_SUCCESS;
}

