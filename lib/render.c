#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GLAD_GL_IMPLEMENTATION
#include <glad/gl.h>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

#include "lib.h"

typedef struct state {
    GLuint vbo;
    GLuint ebo;
    GLuint vao;
    GLuint program;

    GLint middle_point_uniform;

    GLuint flag_texture;
    GLuint flag_vbo;
} state_t;

void render_init(lib_t *lib)
{
    state_t *state = malloc(sizeof(state_t));

    if (state == NULL)
        return;

    // Vertex buffer object
    glGenBuffers(1, &state->vbo);
    glGenBuffers(1, &state->flag_vbo);
    glGenBuffers(1, &state->ebo);

    // Program object
    state->program = glCreateProgram();

    // Vertex array object
    glGenVertexArrays(1, &state->vao);
    glBindVertexArray(state->vao);

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, state->ebo);
    glBindBuffer(GL_ARRAY_BUFFER, state->vbo);

    glVertexAttribPointer(0, 2, GL_DOUBLE, GL_FALSE, sizeof(GLdouble) * 5, NULL);
    glVertexAttribPointer(1, 3, GL_DOUBLE, GL_FALSE, sizeof(GLdouble) * 5, (void *)(sizeof(GLdouble) * 2));

    glBindBuffer(GL_ARRAY_BUFFER, state->flag_vbo);
    glVertexAttribPointer(2, 3, GL_DOUBLE, GL_FALSE, 0, NULL);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    lib->data = state;
    lib->data_size = sizeof(state_t);

    int text_width, text_height;
    stbi_set_flip_vertically_on_load(1);
    unsigned char *text_data = stbi_load("flag.png", &text_width, &text_height,
        NULL, STBI_rgb_alpha);
    if (text_data == NULL) {
        printf("%s\n", stbi_failure_reason());
        return;
    }

    // Textures
    glGenTextures(1, &state->flag_texture);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, state->flag_texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8UI, text_width, text_height, 0,
        GL_RGBA_INTEGER, GL_UNSIGNED_BYTE, text_data);

    stbi_image_free(text_data);
}

void render_load(lib_t *lib)
{
    if (lib->data_size != sizeof(state_t)) {
        lib->data = realloc(lib->data, sizeof(state_t));
        lib->data_size = sizeof(state_t);
    }

    state_t *state = (state_t *) lib->data;

    // Vertices data
    GLdouble vertices[1875] = {
        -0.7f, -0.5f, 0,0.7f,0,
        +0.7f, -0.5f, 0,0.7f,0,
        +0.7f, +0.5f, 0,0.7f,0,
        -0.7f, +0.5f, 0,0.7f,0,

        -0.5f, +0.0f, 1,1,0,
        +0.0f, +0.3f, 1,1,0,
        +0.5f, +0.0f, 1,1,0,
        +0.0f, -0.3f, 1,1,0,

        -1.0f, +1.0f, 0,0,0,
        -0.5f, +1.0f, 0,0,0,
        -0.5f, +0.6f, 0,0,0,
        -1.0f, +0.6f, 0,0,0,
    };

    GLdouble tex_coord[314] = {
        [24] = 0, 1, 1,
               1, 1, 1,
               1, 0, 1,
               0, 0, 1,
    };

    GLuint indices[] = {
        12, 0, 1, 2, 3, 0,
        12, 4, 5, 6, 7, 4,
        8, 9, 10,
        8, 10, 11
    };

    vertices[60] = 0;
    vertices[61] = 0;

    vertices[62] = 0;
    vertices[63] = 0;
    vertices[64] = 1;

    for (int i = 0; i <= 360; i++) {
        vertices[i * 5 + 65] = cos(i * (3.1415926535897932 / 180.0)) / 5.0;
        vertices[i * 5 + 66] = sin(i * (3.1415926535897932 / 180.0)) / 5.0;

        vertices[i * 5 + 67] = 0;
        vertices[i * 5 + 68] = 0;
        vertices[i * 5 + 69] = 0.75;
    }

    // Vertex buffer object
    glBindBuffer(GL_ARRAY_BUFFER, state->vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof vertices, vertices, GL_DYNAMIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, state->flag_vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof tex_coord, tex_coord, GL_DYNAMIC_DRAW);

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
        "layout (location = 2) in vec3 tex;\n"
        "out vec3 vcol;\n"
        "out vec3 vtex;\n"
        "uniform vec3 mpu;\n"
        "\n"
        "void main() {\n"
        "   if (pos.x == 0.0 && pos.y == 0.0)\n"
        "       vcol = mpu;\n"
        "   else\n"
        "       vcol = col;\n"
        "   vtex = tex;\n"
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
        "in vec3 vcol;\n"
        "in vec3 vtex;\n"
        "out vec4 col;\n"
        "uniform usampler2D tex;\n"
        "\n"
        "void main() {\n"
        "    col = vec4(vcol, 1);\n"
        "    if (vtex.z != 0) col = texture(tex, vtex.xy) / 255.0;\n"
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
    glDeleteProgram(state->program);
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

    state->middle_point_uniform = glGetUniformLocation(state->program, "mpu");
    glUniform1ui(glGetUniformLocation(state->program, "tex"), 0);
}

void render_update(lib_t *lib)
{
    state_t *state = (state_t *) lib->data;

    glBindVertexArray(state->vao);
    glUseProgram(state->program);

    glUniform3f(state->middle_point_uniform, 0, 1, 0);
    glDrawElements(GL_TRIANGLE_FAN, 6, GL_UNSIGNED_INT, 0);

    glUniform3f(state->middle_point_uniform, 0.8, 0.8, 0);
    glDrawElements(GL_TRIANGLE_FAN, 6, GL_UNSIGNED_INT, (void *)(sizeof(GLuint) * 6));

    glUniform3f(state->middle_point_uniform, 0, 0, 1);
    glDrawArrays(GL_TRIANGLE_FAN, 12, 362);

    glActiveTexture(GL_TEXTURE0);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (void *)(sizeof(GLuint) * 12));

    glUseProgram(0);
    glBindVertexArray(0);
}

void render_unload(lib_t *lib)
{
    (void) lib;
}

void render_deinit(lib_t *lib)
{
    state_t *state = (state_t *) lib->data;

    glDeleteTextures(1, &state->flag_texture);

    glDeleteProgram(state->program);

    glDeleteBuffers(1, &state->vbo);
    glDeleteBuffers(1, &state->flag_vbo);
    glDeleteBuffers(1, &state->ebo);

    glDeleteVertexArrays(1, &state->vao);

    free(lib->data);
}

lib_on_init(render_init);
lib_on_load(render_load);
lib_on_update(render_update);
lib_on_unload(render_unload);
lib_on_deinit(render_deinit);

