#include "render.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define GLAD_GL_IMPLEMENTATION
#include <glad/gl.h>

typedef struct state {
    GLuint vbo;
    GLuint ebo;
    GLuint vao;
    GLuint program;
} state_t;

void *render_init(GLADloadfunc loader)
{
    state_t *state = malloc(sizeof(state_t));

    if (state == NULL)
        return NULL;

    gladSetGLOnDemandLoader(loader);

    // Vertex buffer object
    glGenBuffers(1, &state->vbo);
    glGenBuffers(1, &state->ebo);

    // Program object

    // Vertex array object
    glGenVertexArrays(1, &state->vao);
    glBindVertexArray(state->vao);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, state->ebo);
    glBindBuffer(GL_ARRAY_BUFFER, state->vbo);

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 5, NULL);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 5, (void *)(sizeof(GLfloat) * 2));

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    return (void *) state;
}

void render_draw(void *data)
{
    state_t *state = (state_t *) data;

    // Vertices data
    GLfloat vertices[1845] = {
        -0.7f, -0.5f, 0,0.7f,0,
        +0.7f, -0.5f, 0,0.7f,0,
        +0.7f, +0.5f, 0,0.7f,0,
        -0.7f, +0.5f, 0,0.7f,0,

        -0.5f, +0.0f, 1,1,0,
        +0.0f, +0.3f, 1,1,0,
        +0.5f, +0.0f, 1,1,0,
        +0.0f, -0.3f, 1,1,0,
    };

    GLuint indices[] = {
        0, 1, 2,
        0, 2, 3,

        4, 5, 6,
        4, 6, 7,
    };

    vertices[40] = 0;
    vertices[41] = 0;

    vertices[42] = 0;
    vertices[43] = 0;
    vertices[44] = 0.9f;

    for (int i = 0; i < 360; i++) {
        vertices[i * 5 + 45] = cosf(i * (180.0f / 3.14159265f)) / 5;
        vertices[i * 5 + 46] = sinf(i * (180.0f / 3.14159265f)) / 5;

        vertices[i * 5 + 47] = 0;
        vertices[i * 5 + 48] = 0;
        vertices[i * 5 + 49] = 0.9f;
    }

    // Vertex buffer object
    glBindBuffer(GL_ARRAY_BUFFER, state->vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof vertices, vertices, GL_DYNAMIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, state->ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof indices, indices, GL_DYNAMIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

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
    GLuint vshader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vshader, 1, &vert_shader_source, NULL);
    glCompileShader(vshader);
    glGetShaderiv(vshader, GL_COMPILE_STATUS, &status);
    if (status == GL_FALSE) {
        char msg[1024];
        glGetShaderInfoLog(vshader, sizeof msg, NULL, msg);
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
    GLuint fshader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fshader, 1, &frag_shader_source, NULL);
    glCompileShader(fshader);
    glGetShaderiv(fshader, GL_COMPILE_STATUS, &status);
    if (status == GL_FALSE) {
        char msg[1024];
        glGetShaderInfoLog(fshader, sizeof msg, NULL, msg);
        printf("Shader compilation error: %s\n", msg);
    }

    // Program object
    state->program = glCreateProgram();
    glAttachShader(state->program, vshader);
    glAttachShader(state->program, fshader);
    glLinkProgram(state->program);
    glGetProgramiv(state->program, GL_LINK_STATUS, &status);
    if (status == GL_FALSE) {
        char msg[1024];
        glGetProgramInfoLog(state->program, sizeof msg, NULL, msg);
        printf("Program link error: %s", msg);
    }

    glDeleteShader(vshader);
    glDeleteShader(fshader);

    glBindVertexArray(state->vao);
    glUseProgram(state->program);

    glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(GLuint), GL_UNSIGNED_INT, 0);
    glDrawArrays(GL_TRIANGLE_FAN, 8, 360);

    glUseProgram(0);
    glBindVertexArray(0);

    glDeleteProgram(state->program);
}

void render_terminate(void *data)
{
    state_t *state = (state_t *) data;

    glDeleteProgram(state->program);
    glDeleteBuffers(1, &state->vbo);
    glDeleteVertexArrays(1, &state->vao);
}

render_t render = {
    render_init,
    render_draw,
    render_terminate,
    NULL,
};

