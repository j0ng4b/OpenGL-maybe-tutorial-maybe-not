/**
 * SPDX-License-Identifier: (WTFPL OR CC0-1.0) AND Apache-2.0
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glad/gl.h>

#ifndef GLAD_IMPL_UTIL_C_
#define GLAD_IMPL_UTIL_C_

#ifdef _MSC_VER
#define GLAD_IMPL_UTIL_SSCANF sscanf_s
#else
#define GLAD_IMPL_UTIL_SSCANF sscanf
#endif

#endif /* GLAD_IMPL_UTIL_C_ */

#ifdef __cplusplus
extern "C" {
#endif




static GLADloadfunc glad_global_on_demand_gl_loader_func = NULL;

void gladSetGLOnDemandLoader(GLADloadfunc loader) {
    glad_global_on_demand_gl_loader_func = loader;
}

static GLADapiproc glad_gl_on_demand_loader(const char *name) {
    GLADapiproc result = NULL;
    if (result == NULL && glad_global_on_demand_gl_loader_func != NULL) {
        result = glad_global_on_demand_gl_loader_func(name);
    }
    /* this provokes a segmentation fault if there was no loader or no loader returned something useful */
    return result;
}


static void GLAD_API_PTR glad_on_demand_impl_glActiveTexture(GLenum texture) {
    glad_glActiveTexture = (PFNGLACTIVETEXTUREPROC) glad_gl_on_demand_loader("glActiveTexture");
    glad_glActiveTexture(texture);
}
PFNGLACTIVETEXTUREPROC glad_glActiveTexture = glad_on_demand_impl_glActiveTexture;
static void GLAD_API_PTR glad_on_demand_impl_glAttachShader(GLuint program, GLuint shader) {
    glad_glAttachShader = (PFNGLATTACHSHADERPROC) glad_gl_on_demand_loader("glAttachShader");
    glad_glAttachShader(program, shader);
}
PFNGLATTACHSHADERPROC glad_glAttachShader = glad_on_demand_impl_glAttachShader;
static void GLAD_API_PTR glad_on_demand_impl_glBeginConditionalRender(GLuint id, GLenum mode) {
    glad_glBeginConditionalRender = (PFNGLBEGINCONDITIONALRENDERPROC) glad_gl_on_demand_loader("glBeginConditionalRender");
    glad_glBeginConditionalRender(id, mode);
}
PFNGLBEGINCONDITIONALRENDERPROC glad_glBeginConditionalRender = glad_on_demand_impl_glBeginConditionalRender;
static void GLAD_API_PTR glad_on_demand_impl_glBeginQuery(GLenum target, GLuint id) {
    glad_glBeginQuery = (PFNGLBEGINQUERYPROC) glad_gl_on_demand_loader("glBeginQuery");
    glad_glBeginQuery(target, id);
}
PFNGLBEGINQUERYPROC glad_glBeginQuery = glad_on_demand_impl_glBeginQuery;
static void GLAD_API_PTR glad_on_demand_impl_glBeginTransformFeedback(GLenum primitiveMode) {
    glad_glBeginTransformFeedback = (PFNGLBEGINTRANSFORMFEEDBACKPROC) glad_gl_on_demand_loader("glBeginTransformFeedback");
    glad_glBeginTransformFeedback(primitiveMode);
}
PFNGLBEGINTRANSFORMFEEDBACKPROC glad_glBeginTransformFeedback = glad_on_demand_impl_glBeginTransformFeedback;
static void GLAD_API_PTR glad_on_demand_impl_glBindAttribLocation(GLuint program, GLuint index, const GLchar * name) {
    glad_glBindAttribLocation = (PFNGLBINDATTRIBLOCATIONPROC) glad_gl_on_demand_loader("glBindAttribLocation");
    glad_glBindAttribLocation(program, index, name);
}
PFNGLBINDATTRIBLOCATIONPROC glad_glBindAttribLocation = glad_on_demand_impl_glBindAttribLocation;
static void GLAD_API_PTR glad_on_demand_impl_glBindBuffer(GLenum target, GLuint buffer) {
    glad_glBindBuffer = (PFNGLBINDBUFFERPROC) glad_gl_on_demand_loader("glBindBuffer");
    glad_glBindBuffer(target, buffer);
}
PFNGLBINDBUFFERPROC glad_glBindBuffer = glad_on_demand_impl_glBindBuffer;
static void GLAD_API_PTR glad_on_demand_impl_glBindBufferBase(GLenum target, GLuint index, GLuint buffer) {
    glad_glBindBufferBase = (PFNGLBINDBUFFERBASEPROC) glad_gl_on_demand_loader("glBindBufferBase");
    glad_glBindBufferBase(target, index, buffer);
}
PFNGLBINDBUFFERBASEPROC glad_glBindBufferBase = glad_on_demand_impl_glBindBufferBase;
static void GLAD_API_PTR glad_on_demand_impl_glBindBufferRange(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size) {
    glad_glBindBufferRange = (PFNGLBINDBUFFERRANGEPROC) glad_gl_on_demand_loader("glBindBufferRange");
    glad_glBindBufferRange(target, index, buffer, offset, size);
}
PFNGLBINDBUFFERRANGEPROC glad_glBindBufferRange = glad_on_demand_impl_glBindBufferRange;
static void GLAD_API_PTR glad_on_demand_impl_glBindFragDataLocation(GLuint program, GLuint color, const GLchar * name) {
    glad_glBindFragDataLocation = (PFNGLBINDFRAGDATALOCATIONPROC) glad_gl_on_demand_loader("glBindFragDataLocation");
    glad_glBindFragDataLocation(program, color, name);
}
PFNGLBINDFRAGDATALOCATIONPROC glad_glBindFragDataLocation = glad_on_demand_impl_glBindFragDataLocation;
static void GLAD_API_PTR glad_on_demand_impl_glBindFragDataLocationIndexed(GLuint program, GLuint colorNumber, GLuint index, const GLchar * name) {
    glad_glBindFragDataLocationIndexed = (PFNGLBINDFRAGDATALOCATIONINDEXEDPROC) glad_gl_on_demand_loader("glBindFragDataLocationIndexed");
    glad_glBindFragDataLocationIndexed(program, colorNumber, index, name);
}
PFNGLBINDFRAGDATALOCATIONINDEXEDPROC glad_glBindFragDataLocationIndexed = glad_on_demand_impl_glBindFragDataLocationIndexed;
static void GLAD_API_PTR glad_on_demand_impl_glBindFramebuffer(GLenum target, GLuint framebuffer) {
    glad_glBindFramebuffer = (PFNGLBINDFRAMEBUFFERPROC) glad_gl_on_demand_loader("glBindFramebuffer");
    glad_glBindFramebuffer(target, framebuffer);
}
PFNGLBINDFRAMEBUFFERPROC glad_glBindFramebuffer = glad_on_demand_impl_glBindFramebuffer;
static void GLAD_API_PTR glad_on_demand_impl_glBindRenderbuffer(GLenum target, GLuint renderbuffer) {
    glad_glBindRenderbuffer = (PFNGLBINDRENDERBUFFERPROC) glad_gl_on_demand_loader("glBindRenderbuffer");
    glad_glBindRenderbuffer(target, renderbuffer);
}
PFNGLBINDRENDERBUFFERPROC glad_glBindRenderbuffer = glad_on_demand_impl_glBindRenderbuffer;
static void GLAD_API_PTR glad_on_demand_impl_glBindSampler(GLuint unit, GLuint sampler) {
    glad_glBindSampler = (PFNGLBINDSAMPLERPROC) glad_gl_on_demand_loader("glBindSampler");
    glad_glBindSampler(unit, sampler);
}
PFNGLBINDSAMPLERPROC glad_glBindSampler = glad_on_demand_impl_glBindSampler;
static void GLAD_API_PTR glad_on_demand_impl_glBindTexture(GLenum target, GLuint texture) {
    glad_glBindTexture = (PFNGLBINDTEXTUREPROC) glad_gl_on_demand_loader("glBindTexture");
    glad_glBindTexture(target, texture);
}
PFNGLBINDTEXTUREPROC glad_glBindTexture = glad_on_demand_impl_glBindTexture;
static void GLAD_API_PTR glad_on_demand_impl_glBindVertexArray(GLuint array) {
    glad_glBindVertexArray = (PFNGLBINDVERTEXARRAYPROC) glad_gl_on_demand_loader("glBindVertexArray");
    glad_glBindVertexArray(array);
}
PFNGLBINDVERTEXARRAYPROC glad_glBindVertexArray = glad_on_demand_impl_glBindVertexArray;
static void GLAD_API_PTR glad_on_demand_impl_glBlendColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {
    glad_glBlendColor = (PFNGLBLENDCOLORPROC) glad_gl_on_demand_loader("glBlendColor");
    glad_glBlendColor(red, green, blue, alpha);
}
PFNGLBLENDCOLORPROC glad_glBlendColor = glad_on_demand_impl_glBlendColor;
static void GLAD_API_PTR glad_on_demand_impl_glBlendEquation(GLenum mode) {
    glad_glBlendEquation = (PFNGLBLENDEQUATIONPROC) glad_gl_on_demand_loader("glBlendEquation");
    glad_glBlendEquation(mode);
}
PFNGLBLENDEQUATIONPROC glad_glBlendEquation = glad_on_demand_impl_glBlendEquation;
static void GLAD_API_PTR glad_on_demand_impl_glBlendEquationSeparate(GLenum modeRGB, GLenum modeAlpha) {
    glad_glBlendEquationSeparate = (PFNGLBLENDEQUATIONSEPARATEPROC) glad_gl_on_demand_loader("glBlendEquationSeparate");
    glad_glBlendEquationSeparate(modeRGB, modeAlpha);
}
PFNGLBLENDEQUATIONSEPARATEPROC glad_glBlendEquationSeparate = glad_on_demand_impl_glBlendEquationSeparate;
static void GLAD_API_PTR glad_on_demand_impl_glBlendFunc(GLenum sfactor, GLenum dfactor) {
    glad_glBlendFunc = (PFNGLBLENDFUNCPROC) glad_gl_on_demand_loader("glBlendFunc");
    glad_glBlendFunc(sfactor, dfactor);
}
PFNGLBLENDFUNCPROC glad_glBlendFunc = glad_on_demand_impl_glBlendFunc;
static void GLAD_API_PTR glad_on_demand_impl_glBlendFuncSeparate(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha) {
    glad_glBlendFuncSeparate = (PFNGLBLENDFUNCSEPARATEPROC) glad_gl_on_demand_loader("glBlendFuncSeparate");
    glad_glBlendFuncSeparate(sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha);
}
PFNGLBLENDFUNCSEPARATEPROC glad_glBlendFuncSeparate = glad_on_demand_impl_glBlendFuncSeparate;
static void GLAD_API_PTR glad_on_demand_impl_glBlitFramebuffer(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter) {
    glad_glBlitFramebuffer = (PFNGLBLITFRAMEBUFFERPROC) glad_gl_on_demand_loader("glBlitFramebuffer");
    glad_glBlitFramebuffer(srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter);
}
PFNGLBLITFRAMEBUFFERPROC glad_glBlitFramebuffer = glad_on_demand_impl_glBlitFramebuffer;
static void GLAD_API_PTR glad_on_demand_impl_glBufferData(GLenum target, GLsizeiptr size, const void * data, GLenum usage) {
    glad_glBufferData = (PFNGLBUFFERDATAPROC) glad_gl_on_demand_loader("glBufferData");
    glad_glBufferData(target, size, data, usage);
}
PFNGLBUFFERDATAPROC glad_glBufferData = glad_on_demand_impl_glBufferData;
static void GLAD_API_PTR glad_on_demand_impl_glBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const void * data) {
    glad_glBufferSubData = (PFNGLBUFFERSUBDATAPROC) glad_gl_on_demand_loader("glBufferSubData");
    glad_glBufferSubData(target, offset, size, data);
}
PFNGLBUFFERSUBDATAPROC glad_glBufferSubData = glad_on_demand_impl_glBufferSubData;
static GLenum GLAD_API_PTR glad_on_demand_impl_glCheckFramebufferStatus(GLenum target) {
    glad_glCheckFramebufferStatus = (PFNGLCHECKFRAMEBUFFERSTATUSPROC) glad_gl_on_demand_loader("glCheckFramebufferStatus");
    return glad_glCheckFramebufferStatus(target);
}
PFNGLCHECKFRAMEBUFFERSTATUSPROC glad_glCheckFramebufferStatus = glad_on_demand_impl_glCheckFramebufferStatus;
static void GLAD_API_PTR glad_on_demand_impl_glClampColor(GLenum target, GLenum clamp) {
    glad_glClampColor = (PFNGLCLAMPCOLORPROC) glad_gl_on_demand_loader("glClampColor");
    glad_glClampColor(target, clamp);
}
PFNGLCLAMPCOLORPROC glad_glClampColor = glad_on_demand_impl_glClampColor;
static void GLAD_API_PTR glad_on_demand_impl_glClear(GLbitfield mask) {
    glad_glClear = (PFNGLCLEARPROC) glad_gl_on_demand_loader("glClear");
    glad_glClear(mask);
}
PFNGLCLEARPROC glad_glClear = glad_on_demand_impl_glClear;
static void GLAD_API_PTR glad_on_demand_impl_glClearBufferfi(GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil) {
    glad_glClearBufferfi = (PFNGLCLEARBUFFERFIPROC) glad_gl_on_demand_loader("glClearBufferfi");
    glad_glClearBufferfi(buffer, drawbuffer, depth, stencil);
}
PFNGLCLEARBUFFERFIPROC glad_glClearBufferfi = glad_on_demand_impl_glClearBufferfi;
static void GLAD_API_PTR glad_on_demand_impl_glClearBufferfv(GLenum buffer, GLint drawbuffer, const GLfloat * value) {
    glad_glClearBufferfv = (PFNGLCLEARBUFFERFVPROC) glad_gl_on_demand_loader("glClearBufferfv");
    glad_glClearBufferfv(buffer, drawbuffer, value);
}
PFNGLCLEARBUFFERFVPROC glad_glClearBufferfv = glad_on_demand_impl_glClearBufferfv;
static void GLAD_API_PTR glad_on_demand_impl_glClearBufferiv(GLenum buffer, GLint drawbuffer, const GLint * value) {
    glad_glClearBufferiv = (PFNGLCLEARBUFFERIVPROC) glad_gl_on_demand_loader("glClearBufferiv");
    glad_glClearBufferiv(buffer, drawbuffer, value);
}
PFNGLCLEARBUFFERIVPROC glad_glClearBufferiv = glad_on_demand_impl_glClearBufferiv;
static void GLAD_API_PTR glad_on_demand_impl_glClearBufferuiv(GLenum buffer, GLint drawbuffer, const GLuint * value) {
    glad_glClearBufferuiv = (PFNGLCLEARBUFFERUIVPROC) glad_gl_on_demand_loader("glClearBufferuiv");
    glad_glClearBufferuiv(buffer, drawbuffer, value);
}
PFNGLCLEARBUFFERUIVPROC glad_glClearBufferuiv = glad_on_demand_impl_glClearBufferuiv;
static void GLAD_API_PTR glad_on_demand_impl_glClearColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {
    glad_glClearColor = (PFNGLCLEARCOLORPROC) glad_gl_on_demand_loader("glClearColor");
    glad_glClearColor(red, green, blue, alpha);
}
PFNGLCLEARCOLORPROC glad_glClearColor = glad_on_demand_impl_glClearColor;
static void GLAD_API_PTR glad_on_demand_impl_glClearDepth(GLdouble depth) {
    glad_glClearDepth = (PFNGLCLEARDEPTHPROC) glad_gl_on_demand_loader("glClearDepth");
    glad_glClearDepth(depth);
}
PFNGLCLEARDEPTHPROC glad_glClearDepth = glad_on_demand_impl_glClearDepth;
static void GLAD_API_PTR glad_on_demand_impl_glClearStencil(GLint s) {
    glad_glClearStencil = (PFNGLCLEARSTENCILPROC) glad_gl_on_demand_loader("glClearStencil");
    glad_glClearStencil(s);
}
PFNGLCLEARSTENCILPROC glad_glClearStencil = glad_on_demand_impl_glClearStencil;
static GLenum GLAD_API_PTR glad_on_demand_impl_glClientWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout) {
    glad_glClientWaitSync = (PFNGLCLIENTWAITSYNCPROC) glad_gl_on_demand_loader("glClientWaitSync");
    return glad_glClientWaitSync(sync, flags, timeout);
}
PFNGLCLIENTWAITSYNCPROC glad_glClientWaitSync = glad_on_demand_impl_glClientWaitSync;
static void GLAD_API_PTR glad_on_demand_impl_glColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha) {
    glad_glColorMask = (PFNGLCOLORMASKPROC) glad_gl_on_demand_loader("glColorMask");
    glad_glColorMask(red, green, blue, alpha);
}
PFNGLCOLORMASKPROC glad_glColorMask = glad_on_demand_impl_glColorMask;
static void GLAD_API_PTR glad_on_demand_impl_glColorMaski(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a) {
    glad_glColorMaski = (PFNGLCOLORMASKIPROC) glad_gl_on_demand_loader("glColorMaski");
    glad_glColorMaski(index, r, g, b, a);
}
PFNGLCOLORMASKIPROC glad_glColorMaski = glad_on_demand_impl_glColorMaski;
static void GLAD_API_PTR glad_on_demand_impl_glCompileShader(GLuint shader) {
    glad_glCompileShader = (PFNGLCOMPILESHADERPROC) glad_gl_on_demand_loader("glCompileShader");
    glad_glCompileShader(shader);
}
PFNGLCOMPILESHADERPROC glad_glCompileShader = glad_on_demand_impl_glCompileShader;
static void GLAD_API_PTR glad_on_demand_impl_glCompressedTexImage1D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void * data) {
    glad_glCompressedTexImage1D = (PFNGLCOMPRESSEDTEXIMAGE1DPROC) glad_gl_on_demand_loader("glCompressedTexImage1D");
    glad_glCompressedTexImage1D(target, level, internalformat, width, border, imageSize, data);
}
PFNGLCOMPRESSEDTEXIMAGE1DPROC glad_glCompressedTexImage1D = glad_on_demand_impl_glCompressedTexImage1D;
static void GLAD_API_PTR glad_on_demand_impl_glCompressedTexImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void * data) {
    glad_glCompressedTexImage2D = (PFNGLCOMPRESSEDTEXIMAGE2DPROC) glad_gl_on_demand_loader("glCompressedTexImage2D");
    glad_glCompressedTexImage2D(target, level, internalformat, width, height, border, imageSize, data);
}
PFNGLCOMPRESSEDTEXIMAGE2DPROC glad_glCompressedTexImage2D = glad_on_demand_impl_glCompressedTexImage2D;
static void GLAD_API_PTR glad_on_demand_impl_glCompressedTexImage3D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void * data) {
    glad_glCompressedTexImage3D = (PFNGLCOMPRESSEDTEXIMAGE3DPROC) glad_gl_on_demand_loader("glCompressedTexImage3D");
    glad_glCompressedTexImage3D(target, level, internalformat, width, height, depth, border, imageSize, data);
}
PFNGLCOMPRESSEDTEXIMAGE3DPROC glad_glCompressedTexImage3D = glad_on_demand_impl_glCompressedTexImage3D;
static void GLAD_API_PTR glad_on_demand_impl_glCompressedTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void * data) {
    glad_glCompressedTexSubImage1D = (PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC) glad_gl_on_demand_loader("glCompressedTexSubImage1D");
    glad_glCompressedTexSubImage1D(target, level, xoffset, width, format, imageSize, data);
}
PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC glad_glCompressedTexSubImage1D = glad_on_demand_impl_glCompressedTexSubImage1D;
static void GLAD_API_PTR glad_on_demand_impl_glCompressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void * data) {
    glad_glCompressedTexSubImage2D = (PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC) glad_gl_on_demand_loader("glCompressedTexSubImage2D");
    glad_glCompressedTexSubImage2D(target, level, xoffset, yoffset, width, height, format, imageSize, data);
}
PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC glad_glCompressedTexSubImage2D = glad_on_demand_impl_glCompressedTexSubImage2D;
static void GLAD_API_PTR glad_on_demand_impl_glCompressedTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void * data) {
    glad_glCompressedTexSubImage3D = (PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC) glad_gl_on_demand_loader("glCompressedTexSubImage3D");
    glad_glCompressedTexSubImage3D(target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data);
}
PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC glad_glCompressedTexSubImage3D = glad_on_demand_impl_glCompressedTexSubImage3D;
static void GLAD_API_PTR glad_on_demand_impl_glCopyBufferSubData(GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size) {
    glad_glCopyBufferSubData = (PFNGLCOPYBUFFERSUBDATAPROC) glad_gl_on_demand_loader("glCopyBufferSubData");
    glad_glCopyBufferSubData(readTarget, writeTarget, readOffset, writeOffset, size);
}
PFNGLCOPYBUFFERSUBDATAPROC glad_glCopyBufferSubData = glad_on_demand_impl_glCopyBufferSubData;
static void GLAD_API_PTR glad_on_demand_impl_glCopyTexImage1D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border) {
    glad_glCopyTexImage1D = (PFNGLCOPYTEXIMAGE1DPROC) glad_gl_on_demand_loader("glCopyTexImage1D");
    glad_glCopyTexImage1D(target, level, internalformat, x, y, width, border);
}
PFNGLCOPYTEXIMAGE1DPROC glad_glCopyTexImage1D = glad_on_demand_impl_glCopyTexImage1D;
static void GLAD_API_PTR glad_on_demand_impl_glCopyTexImage2D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border) {
    glad_glCopyTexImage2D = (PFNGLCOPYTEXIMAGE2DPROC) glad_gl_on_demand_loader("glCopyTexImage2D");
    glad_glCopyTexImage2D(target, level, internalformat, x, y, width, height, border);
}
PFNGLCOPYTEXIMAGE2DPROC glad_glCopyTexImage2D = glad_on_demand_impl_glCopyTexImage2D;
static void GLAD_API_PTR glad_on_demand_impl_glCopyTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width) {
    glad_glCopyTexSubImage1D = (PFNGLCOPYTEXSUBIMAGE1DPROC) glad_gl_on_demand_loader("glCopyTexSubImage1D");
    glad_glCopyTexSubImage1D(target, level, xoffset, x, y, width);
}
PFNGLCOPYTEXSUBIMAGE1DPROC glad_glCopyTexSubImage1D = glad_on_demand_impl_glCopyTexSubImage1D;
static void GLAD_API_PTR glad_on_demand_impl_glCopyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) {
    glad_glCopyTexSubImage2D = (PFNGLCOPYTEXSUBIMAGE2DPROC) glad_gl_on_demand_loader("glCopyTexSubImage2D");
    glad_glCopyTexSubImage2D(target, level, xoffset, yoffset, x, y, width, height);
}
PFNGLCOPYTEXSUBIMAGE2DPROC glad_glCopyTexSubImage2D = glad_on_demand_impl_glCopyTexSubImage2D;
static void GLAD_API_PTR glad_on_demand_impl_glCopyTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height) {
    glad_glCopyTexSubImage3D = (PFNGLCOPYTEXSUBIMAGE3DPROC) glad_gl_on_demand_loader("glCopyTexSubImage3D");
    glad_glCopyTexSubImage3D(target, level, xoffset, yoffset, zoffset, x, y, width, height);
}
PFNGLCOPYTEXSUBIMAGE3DPROC glad_glCopyTexSubImage3D = glad_on_demand_impl_glCopyTexSubImage3D;
static GLuint GLAD_API_PTR glad_on_demand_impl_glCreateProgram(void) {
    glad_glCreateProgram = (PFNGLCREATEPROGRAMPROC) glad_gl_on_demand_loader("glCreateProgram");
    return glad_glCreateProgram();
}
PFNGLCREATEPROGRAMPROC glad_glCreateProgram = glad_on_demand_impl_glCreateProgram;
static GLuint GLAD_API_PTR glad_on_demand_impl_glCreateShader(GLenum type) {
    glad_glCreateShader = (PFNGLCREATESHADERPROC) glad_gl_on_demand_loader("glCreateShader");
    return glad_glCreateShader(type);
}
PFNGLCREATESHADERPROC glad_glCreateShader = glad_on_demand_impl_glCreateShader;
static void GLAD_API_PTR glad_on_demand_impl_glCullFace(GLenum mode) {
    glad_glCullFace = (PFNGLCULLFACEPROC) glad_gl_on_demand_loader("glCullFace");
    glad_glCullFace(mode);
}
PFNGLCULLFACEPROC glad_glCullFace = glad_on_demand_impl_glCullFace;
static void GLAD_API_PTR glad_on_demand_impl_glDeleteBuffers(GLsizei n, const GLuint * buffers) {
    glad_glDeleteBuffers = (PFNGLDELETEBUFFERSPROC) glad_gl_on_demand_loader("glDeleteBuffers");
    glad_glDeleteBuffers(n, buffers);
}
PFNGLDELETEBUFFERSPROC glad_glDeleteBuffers = glad_on_demand_impl_glDeleteBuffers;
static void GLAD_API_PTR glad_on_demand_impl_glDeleteFramebuffers(GLsizei n, const GLuint * framebuffers) {
    glad_glDeleteFramebuffers = (PFNGLDELETEFRAMEBUFFERSPROC) glad_gl_on_demand_loader("glDeleteFramebuffers");
    glad_glDeleteFramebuffers(n, framebuffers);
}
PFNGLDELETEFRAMEBUFFERSPROC glad_glDeleteFramebuffers = glad_on_demand_impl_glDeleteFramebuffers;
static void GLAD_API_PTR glad_on_demand_impl_glDeleteProgram(GLuint program) {
    glad_glDeleteProgram = (PFNGLDELETEPROGRAMPROC) glad_gl_on_demand_loader("glDeleteProgram");
    glad_glDeleteProgram(program);
}
PFNGLDELETEPROGRAMPROC glad_glDeleteProgram = glad_on_demand_impl_glDeleteProgram;
static void GLAD_API_PTR glad_on_demand_impl_glDeleteQueries(GLsizei n, const GLuint * ids) {
    glad_glDeleteQueries = (PFNGLDELETEQUERIESPROC) glad_gl_on_demand_loader("glDeleteQueries");
    glad_glDeleteQueries(n, ids);
}
PFNGLDELETEQUERIESPROC glad_glDeleteQueries = glad_on_demand_impl_glDeleteQueries;
static void GLAD_API_PTR glad_on_demand_impl_glDeleteRenderbuffers(GLsizei n, const GLuint * renderbuffers) {
    glad_glDeleteRenderbuffers = (PFNGLDELETERENDERBUFFERSPROC) glad_gl_on_demand_loader("glDeleteRenderbuffers");
    glad_glDeleteRenderbuffers(n, renderbuffers);
}
PFNGLDELETERENDERBUFFERSPROC glad_glDeleteRenderbuffers = glad_on_demand_impl_glDeleteRenderbuffers;
static void GLAD_API_PTR glad_on_demand_impl_glDeleteSamplers(GLsizei count, const GLuint * samplers) {
    glad_glDeleteSamplers = (PFNGLDELETESAMPLERSPROC) glad_gl_on_demand_loader("glDeleteSamplers");
    glad_glDeleteSamplers(count, samplers);
}
PFNGLDELETESAMPLERSPROC glad_glDeleteSamplers = glad_on_demand_impl_glDeleteSamplers;
static void GLAD_API_PTR glad_on_demand_impl_glDeleteShader(GLuint shader) {
    glad_glDeleteShader = (PFNGLDELETESHADERPROC) glad_gl_on_demand_loader("glDeleteShader");
    glad_glDeleteShader(shader);
}
PFNGLDELETESHADERPROC glad_glDeleteShader = glad_on_demand_impl_glDeleteShader;
static void GLAD_API_PTR glad_on_demand_impl_glDeleteSync(GLsync sync) {
    glad_glDeleteSync = (PFNGLDELETESYNCPROC) glad_gl_on_demand_loader("glDeleteSync");
    glad_glDeleteSync(sync);
}
PFNGLDELETESYNCPROC glad_glDeleteSync = glad_on_demand_impl_glDeleteSync;
static void GLAD_API_PTR glad_on_demand_impl_glDeleteTextures(GLsizei n, const GLuint * textures) {
    glad_glDeleteTextures = (PFNGLDELETETEXTURESPROC) glad_gl_on_demand_loader("glDeleteTextures");
    glad_glDeleteTextures(n, textures);
}
PFNGLDELETETEXTURESPROC glad_glDeleteTextures = glad_on_demand_impl_glDeleteTextures;
static void GLAD_API_PTR glad_on_demand_impl_glDeleteVertexArrays(GLsizei n, const GLuint * arrays) {
    glad_glDeleteVertexArrays = (PFNGLDELETEVERTEXARRAYSPROC) glad_gl_on_demand_loader("glDeleteVertexArrays");
    glad_glDeleteVertexArrays(n, arrays);
}
PFNGLDELETEVERTEXARRAYSPROC glad_glDeleteVertexArrays = glad_on_demand_impl_glDeleteVertexArrays;
static void GLAD_API_PTR glad_on_demand_impl_glDepthFunc(GLenum func) {
    glad_glDepthFunc = (PFNGLDEPTHFUNCPROC) glad_gl_on_demand_loader("glDepthFunc");
    glad_glDepthFunc(func);
}
PFNGLDEPTHFUNCPROC glad_glDepthFunc = glad_on_demand_impl_glDepthFunc;
static void GLAD_API_PTR glad_on_demand_impl_glDepthMask(GLboolean flag) {
    glad_glDepthMask = (PFNGLDEPTHMASKPROC) glad_gl_on_demand_loader("glDepthMask");
    glad_glDepthMask(flag);
}
PFNGLDEPTHMASKPROC glad_glDepthMask = glad_on_demand_impl_glDepthMask;
static void GLAD_API_PTR glad_on_demand_impl_glDepthRange(GLdouble n, GLdouble f) {
    glad_glDepthRange = (PFNGLDEPTHRANGEPROC) glad_gl_on_demand_loader("glDepthRange");
    glad_glDepthRange(n, f);
}
PFNGLDEPTHRANGEPROC glad_glDepthRange = glad_on_demand_impl_glDepthRange;
static void GLAD_API_PTR glad_on_demand_impl_glDetachShader(GLuint program, GLuint shader) {
    glad_glDetachShader = (PFNGLDETACHSHADERPROC) glad_gl_on_demand_loader("glDetachShader");
    glad_glDetachShader(program, shader);
}
PFNGLDETACHSHADERPROC glad_glDetachShader = glad_on_demand_impl_glDetachShader;
static void GLAD_API_PTR glad_on_demand_impl_glDisable(GLenum cap) {
    glad_glDisable = (PFNGLDISABLEPROC) glad_gl_on_demand_loader("glDisable");
    glad_glDisable(cap);
}
PFNGLDISABLEPROC glad_glDisable = glad_on_demand_impl_glDisable;
static void GLAD_API_PTR glad_on_demand_impl_glDisableVertexAttribArray(GLuint index) {
    glad_glDisableVertexAttribArray = (PFNGLDISABLEVERTEXATTRIBARRAYPROC) glad_gl_on_demand_loader("glDisableVertexAttribArray");
    glad_glDisableVertexAttribArray(index);
}
PFNGLDISABLEVERTEXATTRIBARRAYPROC glad_glDisableVertexAttribArray = glad_on_demand_impl_glDisableVertexAttribArray;
static void GLAD_API_PTR glad_on_demand_impl_glDisablei(GLenum target, GLuint index) {
    glad_glDisablei = (PFNGLDISABLEIPROC) glad_gl_on_demand_loader("glDisablei");
    glad_glDisablei(target, index);
}
PFNGLDISABLEIPROC glad_glDisablei = glad_on_demand_impl_glDisablei;
static void GLAD_API_PTR glad_on_demand_impl_glDrawArrays(GLenum mode, GLint first, GLsizei count) {
    glad_glDrawArrays = (PFNGLDRAWARRAYSPROC) glad_gl_on_demand_loader("glDrawArrays");
    glad_glDrawArrays(mode, first, count);
}
PFNGLDRAWARRAYSPROC glad_glDrawArrays = glad_on_demand_impl_glDrawArrays;
static void GLAD_API_PTR glad_on_demand_impl_glDrawArraysInstanced(GLenum mode, GLint first, GLsizei count, GLsizei instancecount) {
    glad_glDrawArraysInstanced = (PFNGLDRAWARRAYSINSTANCEDPROC) glad_gl_on_demand_loader("glDrawArraysInstanced");
    glad_glDrawArraysInstanced(mode, first, count, instancecount);
}
PFNGLDRAWARRAYSINSTANCEDPROC glad_glDrawArraysInstanced = glad_on_demand_impl_glDrawArraysInstanced;
static void GLAD_API_PTR glad_on_demand_impl_glDrawBuffer(GLenum buf) {
    glad_glDrawBuffer = (PFNGLDRAWBUFFERPROC) glad_gl_on_demand_loader("glDrawBuffer");
    glad_glDrawBuffer(buf);
}
PFNGLDRAWBUFFERPROC glad_glDrawBuffer = glad_on_demand_impl_glDrawBuffer;
static void GLAD_API_PTR glad_on_demand_impl_glDrawBuffers(GLsizei n, const GLenum * bufs) {
    glad_glDrawBuffers = (PFNGLDRAWBUFFERSPROC) glad_gl_on_demand_loader("glDrawBuffers");
    glad_glDrawBuffers(n, bufs);
}
PFNGLDRAWBUFFERSPROC glad_glDrawBuffers = glad_on_demand_impl_glDrawBuffers;
static void GLAD_API_PTR glad_on_demand_impl_glDrawElements(GLenum mode, GLsizei count, GLenum type, const void * indices) {
    glad_glDrawElements = (PFNGLDRAWELEMENTSPROC) glad_gl_on_demand_loader("glDrawElements");
    glad_glDrawElements(mode, count, type, indices);
}
PFNGLDRAWELEMENTSPROC glad_glDrawElements = glad_on_demand_impl_glDrawElements;
static void GLAD_API_PTR glad_on_demand_impl_glDrawElementsBaseVertex(GLenum mode, GLsizei count, GLenum type, const void * indices, GLint basevertex) {
    glad_glDrawElementsBaseVertex = (PFNGLDRAWELEMENTSBASEVERTEXPROC) glad_gl_on_demand_loader("glDrawElementsBaseVertex");
    glad_glDrawElementsBaseVertex(mode, count, type, indices, basevertex);
}
PFNGLDRAWELEMENTSBASEVERTEXPROC glad_glDrawElementsBaseVertex = glad_on_demand_impl_glDrawElementsBaseVertex;
static void GLAD_API_PTR glad_on_demand_impl_glDrawElementsInstanced(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei instancecount) {
    glad_glDrawElementsInstanced = (PFNGLDRAWELEMENTSINSTANCEDPROC) glad_gl_on_demand_loader("glDrawElementsInstanced");
    glad_glDrawElementsInstanced(mode, count, type, indices, instancecount);
}
PFNGLDRAWELEMENTSINSTANCEDPROC glad_glDrawElementsInstanced = glad_on_demand_impl_glDrawElementsInstanced;
static void GLAD_API_PTR glad_on_demand_impl_glDrawElementsInstancedBaseVertex(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei instancecount, GLint basevertex) {
    glad_glDrawElementsInstancedBaseVertex = (PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC) glad_gl_on_demand_loader("glDrawElementsInstancedBaseVertex");
    glad_glDrawElementsInstancedBaseVertex(mode, count, type, indices, instancecount, basevertex);
}
PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC glad_glDrawElementsInstancedBaseVertex = glad_on_demand_impl_glDrawElementsInstancedBaseVertex;
static void GLAD_API_PTR glad_on_demand_impl_glDrawRangeElements(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void * indices) {
    glad_glDrawRangeElements = (PFNGLDRAWRANGEELEMENTSPROC) glad_gl_on_demand_loader("glDrawRangeElements");
    glad_glDrawRangeElements(mode, start, end, count, type, indices);
}
PFNGLDRAWRANGEELEMENTSPROC glad_glDrawRangeElements = glad_on_demand_impl_glDrawRangeElements;
static void GLAD_API_PTR glad_on_demand_impl_glDrawRangeElementsBaseVertex(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void * indices, GLint basevertex) {
    glad_glDrawRangeElementsBaseVertex = (PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC) glad_gl_on_demand_loader("glDrawRangeElementsBaseVertex");
    glad_glDrawRangeElementsBaseVertex(mode, start, end, count, type, indices, basevertex);
}
PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC glad_glDrawRangeElementsBaseVertex = glad_on_demand_impl_glDrawRangeElementsBaseVertex;
static void GLAD_API_PTR glad_on_demand_impl_glEnable(GLenum cap) {
    glad_glEnable = (PFNGLENABLEPROC) glad_gl_on_demand_loader("glEnable");
    glad_glEnable(cap);
}
PFNGLENABLEPROC glad_glEnable = glad_on_demand_impl_glEnable;
static void GLAD_API_PTR glad_on_demand_impl_glEnableVertexAttribArray(GLuint index) {
    glad_glEnableVertexAttribArray = (PFNGLENABLEVERTEXATTRIBARRAYPROC) glad_gl_on_demand_loader("glEnableVertexAttribArray");
    glad_glEnableVertexAttribArray(index);
}
PFNGLENABLEVERTEXATTRIBARRAYPROC glad_glEnableVertexAttribArray = glad_on_demand_impl_glEnableVertexAttribArray;
static void GLAD_API_PTR glad_on_demand_impl_glEnablei(GLenum target, GLuint index) {
    glad_glEnablei = (PFNGLENABLEIPROC) glad_gl_on_demand_loader("glEnablei");
    glad_glEnablei(target, index);
}
PFNGLENABLEIPROC glad_glEnablei = glad_on_demand_impl_glEnablei;
static void GLAD_API_PTR glad_on_demand_impl_glEndConditionalRender(void) {
    glad_glEndConditionalRender = (PFNGLENDCONDITIONALRENDERPROC) glad_gl_on_demand_loader("glEndConditionalRender");
    glad_glEndConditionalRender();
}
PFNGLENDCONDITIONALRENDERPROC glad_glEndConditionalRender = glad_on_demand_impl_glEndConditionalRender;
static void GLAD_API_PTR glad_on_demand_impl_glEndQuery(GLenum target) {
    glad_glEndQuery = (PFNGLENDQUERYPROC) glad_gl_on_demand_loader("glEndQuery");
    glad_glEndQuery(target);
}
PFNGLENDQUERYPROC glad_glEndQuery = glad_on_demand_impl_glEndQuery;
static void GLAD_API_PTR glad_on_demand_impl_glEndTransformFeedback(void) {
    glad_glEndTransformFeedback = (PFNGLENDTRANSFORMFEEDBACKPROC) glad_gl_on_demand_loader("glEndTransformFeedback");
    glad_glEndTransformFeedback();
}
PFNGLENDTRANSFORMFEEDBACKPROC glad_glEndTransformFeedback = glad_on_demand_impl_glEndTransformFeedback;
static GLsync GLAD_API_PTR glad_on_demand_impl_glFenceSync(GLenum condition, GLbitfield flags) {
    glad_glFenceSync = (PFNGLFENCESYNCPROC) glad_gl_on_demand_loader("glFenceSync");
    return glad_glFenceSync(condition, flags);
}
PFNGLFENCESYNCPROC glad_glFenceSync = glad_on_demand_impl_glFenceSync;
static void GLAD_API_PTR glad_on_demand_impl_glFinish(void) {
    glad_glFinish = (PFNGLFINISHPROC) glad_gl_on_demand_loader("glFinish");
    glad_glFinish();
}
PFNGLFINISHPROC glad_glFinish = glad_on_demand_impl_glFinish;
static void GLAD_API_PTR glad_on_demand_impl_glFlush(void) {
    glad_glFlush = (PFNGLFLUSHPROC) glad_gl_on_demand_loader("glFlush");
    glad_glFlush();
}
PFNGLFLUSHPROC glad_glFlush = glad_on_demand_impl_glFlush;
static void GLAD_API_PTR glad_on_demand_impl_glFlushMappedBufferRange(GLenum target, GLintptr offset, GLsizeiptr length) {
    glad_glFlushMappedBufferRange = (PFNGLFLUSHMAPPEDBUFFERRANGEPROC) glad_gl_on_demand_loader("glFlushMappedBufferRange");
    glad_glFlushMappedBufferRange(target, offset, length);
}
PFNGLFLUSHMAPPEDBUFFERRANGEPROC glad_glFlushMappedBufferRange = glad_on_demand_impl_glFlushMappedBufferRange;
static void GLAD_API_PTR glad_on_demand_impl_glFramebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer) {
    glad_glFramebufferRenderbuffer = (PFNGLFRAMEBUFFERRENDERBUFFERPROC) glad_gl_on_demand_loader("glFramebufferRenderbuffer");
    glad_glFramebufferRenderbuffer(target, attachment, renderbuffertarget, renderbuffer);
}
PFNGLFRAMEBUFFERRENDERBUFFERPROC glad_glFramebufferRenderbuffer = glad_on_demand_impl_glFramebufferRenderbuffer;
static void GLAD_API_PTR glad_on_demand_impl_glFramebufferTexture(GLenum target, GLenum attachment, GLuint texture, GLint level) {
    glad_glFramebufferTexture = (PFNGLFRAMEBUFFERTEXTUREPROC) glad_gl_on_demand_loader("glFramebufferTexture");
    glad_glFramebufferTexture(target, attachment, texture, level);
}
PFNGLFRAMEBUFFERTEXTUREPROC glad_glFramebufferTexture = glad_on_demand_impl_glFramebufferTexture;
static void GLAD_API_PTR glad_on_demand_impl_glFramebufferTexture1D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level) {
    glad_glFramebufferTexture1D = (PFNGLFRAMEBUFFERTEXTURE1DPROC) glad_gl_on_demand_loader("glFramebufferTexture1D");
    glad_glFramebufferTexture1D(target, attachment, textarget, texture, level);
}
PFNGLFRAMEBUFFERTEXTURE1DPROC glad_glFramebufferTexture1D = glad_on_demand_impl_glFramebufferTexture1D;
static void GLAD_API_PTR glad_on_demand_impl_glFramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level) {
    glad_glFramebufferTexture2D = (PFNGLFRAMEBUFFERTEXTURE2DPROC) glad_gl_on_demand_loader("glFramebufferTexture2D");
    glad_glFramebufferTexture2D(target, attachment, textarget, texture, level);
}
PFNGLFRAMEBUFFERTEXTURE2DPROC glad_glFramebufferTexture2D = glad_on_demand_impl_glFramebufferTexture2D;
static void GLAD_API_PTR glad_on_demand_impl_glFramebufferTexture3D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset) {
    glad_glFramebufferTexture3D = (PFNGLFRAMEBUFFERTEXTURE3DPROC) glad_gl_on_demand_loader("glFramebufferTexture3D");
    glad_glFramebufferTexture3D(target, attachment, textarget, texture, level, zoffset);
}
PFNGLFRAMEBUFFERTEXTURE3DPROC glad_glFramebufferTexture3D = glad_on_demand_impl_glFramebufferTexture3D;
static void GLAD_API_PTR glad_on_demand_impl_glFramebufferTextureLayer(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer) {
    glad_glFramebufferTextureLayer = (PFNGLFRAMEBUFFERTEXTURELAYERPROC) glad_gl_on_demand_loader("glFramebufferTextureLayer");
    glad_glFramebufferTextureLayer(target, attachment, texture, level, layer);
}
PFNGLFRAMEBUFFERTEXTURELAYERPROC glad_glFramebufferTextureLayer = glad_on_demand_impl_glFramebufferTextureLayer;
static void GLAD_API_PTR glad_on_demand_impl_glFrontFace(GLenum mode) {
    glad_glFrontFace = (PFNGLFRONTFACEPROC) glad_gl_on_demand_loader("glFrontFace");
    glad_glFrontFace(mode);
}
PFNGLFRONTFACEPROC glad_glFrontFace = glad_on_demand_impl_glFrontFace;
static void GLAD_API_PTR glad_on_demand_impl_glGenBuffers(GLsizei n, GLuint * buffers) {
    glad_glGenBuffers = (PFNGLGENBUFFERSPROC) glad_gl_on_demand_loader("glGenBuffers");
    glad_glGenBuffers(n, buffers);
}
PFNGLGENBUFFERSPROC glad_glGenBuffers = glad_on_demand_impl_glGenBuffers;
static void GLAD_API_PTR glad_on_demand_impl_glGenFramebuffers(GLsizei n, GLuint * framebuffers) {
    glad_glGenFramebuffers = (PFNGLGENFRAMEBUFFERSPROC) glad_gl_on_demand_loader("glGenFramebuffers");
    glad_glGenFramebuffers(n, framebuffers);
}
PFNGLGENFRAMEBUFFERSPROC glad_glGenFramebuffers = glad_on_demand_impl_glGenFramebuffers;
static void GLAD_API_PTR glad_on_demand_impl_glGenQueries(GLsizei n, GLuint * ids) {
    glad_glGenQueries = (PFNGLGENQUERIESPROC) glad_gl_on_demand_loader("glGenQueries");
    glad_glGenQueries(n, ids);
}
PFNGLGENQUERIESPROC glad_glGenQueries = glad_on_demand_impl_glGenQueries;
static void GLAD_API_PTR glad_on_demand_impl_glGenRenderbuffers(GLsizei n, GLuint * renderbuffers) {
    glad_glGenRenderbuffers = (PFNGLGENRENDERBUFFERSPROC) glad_gl_on_demand_loader("glGenRenderbuffers");
    glad_glGenRenderbuffers(n, renderbuffers);
}
PFNGLGENRENDERBUFFERSPROC glad_glGenRenderbuffers = glad_on_demand_impl_glGenRenderbuffers;
static void GLAD_API_PTR glad_on_demand_impl_glGenSamplers(GLsizei count, GLuint * samplers) {
    glad_glGenSamplers = (PFNGLGENSAMPLERSPROC) glad_gl_on_demand_loader("glGenSamplers");
    glad_glGenSamplers(count, samplers);
}
PFNGLGENSAMPLERSPROC glad_glGenSamplers = glad_on_demand_impl_glGenSamplers;
static void GLAD_API_PTR glad_on_demand_impl_glGenTextures(GLsizei n, GLuint * textures) {
    glad_glGenTextures = (PFNGLGENTEXTURESPROC) glad_gl_on_demand_loader("glGenTextures");
    glad_glGenTextures(n, textures);
}
PFNGLGENTEXTURESPROC glad_glGenTextures = glad_on_demand_impl_glGenTextures;
static void GLAD_API_PTR glad_on_demand_impl_glGenVertexArrays(GLsizei n, GLuint * arrays) {
    glad_glGenVertexArrays = (PFNGLGENVERTEXARRAYSPROC) glad_gl_on_demand_loader("glGenVertexArrays");
    glad_glGenVertexArrays(n, arrays);
}
PFNGLGENVERTEXARRAYSPROC glad_glGenVertexArrays = glad_on_demand_impl_glGenVertexArrays;
static void GLAD_API_PTR glad_on_demand_impl_glGenerateMipmap(GLenum target) {
    glad_glGenerateMipmap = (PFNGLGENERATEMIPMAPPROC) glad_gl_on_demand_loader("glGenerateMipmap");
    glad_glGenerateMipmap(target);
}
PFNGLGENERATEMIPMAPPROC glad_glGenerateMipmap = glad_on_demand_impl_glGenerateMipmap;
static void GLAD_API_PTR glad_on_demand_impl_glGetActiveAttrib(GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLint * size, GLenum * type, GLchar * name) {
    glad_glGetActiveAttrib = (PFNGLGETACTIVEATTRIBPROC) glad_gl_on_demand_loader("glGetActiveAttrib");
    glad_glGetActiveAttrib(program, index, bufSize, length, size, type, name);
}
PFNGLGETACTIVEATTRIBPROC glad_glGetActiveAttrib = glad_on_demand_impl_glGetActiveAttrib;
static void GLAD_API_PTR glad_on_demand_impl_glGetActiveUniform(GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLint * size, GLenum * type, GLchar * name) {
    glad_glGetActiveUniform = (PFNGLGETACTIVEUNIFORMPROC) glad_gl_on_demand_loader("glGetActiveUniform");
    glad_glGetActiveUniform(program, index, bufSize, length, size, type, name);
}
PFNGLGETACTIVEUNIFORMPROC glad_glGetActiveUniform = glad_on_demand_impl_glGetActiveUniform;
static void GLAD_API_PTR glad_on_demand_impl_glGetActiveUniformBlockName(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei * length, GLchar * uniformBlockName) {
    glad_glGetActiveUniformBlockName = (PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC) glad_gl_on_demand_loader("glGetActiveUniformBlockName");
    glad_glGetActiveUniformBlockName(program, uniformBlockIndex, bufSize, length, uniformBlockName);
}
PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC glad_glGetActiveUniformBlockName = glad_on_demand_impl_glGetActiveUniformBlockName;
static void GLAD_API_PTR glad_on_demand_impl_glGetActiveUniformBlockiv(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint * params) {
    glad_glGetActiveUniformBlockiv = (PFNGLGETACTIVEUNIFORMBLOCKIVPROC) glad_gl_on_demand_loader("glGetActiveUniformBlockiv");
    glad_glGetActiveUniformBlockiv(program, uniformBlockIndex, pname, params);
}
PFNGLGETACTIVEUNIFORMBLOCKIVPROC glad_glGetActiveUniformBlockiv = glad_on_demand_impl_glGetActiveUniformBlockiv;
static void GLAD_API_PTR glad_on_demand_impl_glGetActiveUniformName(GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei * length, GLchar * uniformName) {
    glad_glGetActiveUniformName = (PFNGLGETACTIVEUNIFORMNAMEPROC) glad_gl_on_demand_loader("glGetActiveUniformName");
    glad_glGetActiveUniformName(program, uniformIndex, bufSize, length, uniformName);
}
PFNGLGETACTIVEUNIFORMNAMEPROC glad_glGetActiveUniformName = glad_on_demand_impl_glGetActiveUniformName;
static void GLAD_API_PTR glad_on_demand_impl_glGetActiveUniformsiv(GLuint program, GLsizei uniformCount, const GLuint * uniformIndices, GLenum pname, GLint * params) {
    glad_glGetActiveUniformsiv = (PFNGLGETACTIVEUNIFORMSIVPROC) glad_gl_on_demand_loader("glGetActiveUniformsiv");
    glad_glGetActiveUniformsiv(program, uniformCount, uniformIndices, pname, params);
}
PFNGLGETACTIVEUNIFORMSIVPROC glad_glGetActiveUniformsiv = glad_on_demand_impl_glGetActiveUniformsiv;
static void GLAD_API_PTR glad_on_demand_impl_glGetAttachedShaders(GLuint program, GLsizei maxCount, GLsizei * count, GLuint * shaders) {
    glad_glGetAttachedShaders = (PFNGLGETATTACHEDSHADERSPROC) glad_gl_on_demand_loader("glGetAttachedShaders");
    glad_glGetAttachedShaders(program, maxCount, count, shaders);
}
PFNGLGETATTACHEDSHADERSPROC glad_glGetAttachedShaders = glad_on_demand_impl_glGetAttachedShaders;
static GLint GLAD_API_PTR glad_on_demand_impl_glGetAttribLocation(GLuint program, const GLchar * name) {
    glad_glGetAttribLocation = (PFNGLGETATTRIBLOCATIONPROC) glad_gl_on_demand_loader("glGetAttribLocation");
    return glad_glGetAttribLocation(program, name);
}
PFNGLGETATTRIBLOCATIONPROC glad_glGetAttribLocation = glad_on_demand_impl_glGetAttribLocation;
static void GLAD_API_PTR glad_on_demand_impl_glGetBooleani_v(GLenum target, GLuint index, GLboolean * data) {
    glad_glGetBooleani_v = (PFNGLGETBOOLEANI_VPROC) glad_gl_on_demand_loader("glGetBooleani_v");
    glad_glGetBooleani_v(target, index, data);
}
PFNGLGETBOOLEANI_VPROC glad_glGetBooleani_v = glad_on_demand_impl_glGetBooleani_v;
static void GLAD_API_PTR glad_on_demand_impl_glGetBooleanv(GLenum pname, GLboolean * data) {
    glad_glGetBooleanv = (PFNGLGETBOOLEANVPROC) glad_gl_on_demand_loader("glGetBooleanv");
    glad_glGetBooleanv(pname, data);
}
PFNGLGETBOOLEANVPROC glad_glGetBooleanv = glad_on_demand_impl_glGetBooleanv;
static void GLAD_API_PTR glad_on_demand_impl_glGetBufferParameteri64v(GLenum target, GLenum pname, GLint64 * params) {
    glad_glGetBufferParameteri64v = (PFNGLGETBUFFERPARAMETERI64VPROC) glad_gl_on_demand_loader("glGetBufferParameteri64v");
    glad_glGetBufferParameteri64v(target, pname, params);
}
PFNGLGETBUFFERPARAMETERI64VPROC glad_glGetBufferParameteri64v = glad_on_demand_impl_glGetBufferParameteri64v;
static void GLAD_API_PTR glad_on_demand_impl_glGetBufferParameteriv(GLenum target, GLenum pname, GLint * params) {
    glad_glGetBufferParameteriv = (PFNGLGETBUFFERPARAMETERIVPROC) glad_gl_on_demand_loader("glGetBufferParameteriv");
    glad_glGetBufferParameteriv(target, pname, params);
}
PFNGLGETBUFFERPARAMETERIVPROC glad_glGetBufferParameteriv = glad_on_demand_impl_glGetBufferParameteriv;
static void GLAD_API_PTR glad_on_demand_impl_glGetBufferPointerv(GLenum target, GLenum pname, void ** params) {
    glad_glGetBufferPointerv = (PFNGLGETBUFFERPOINTERVPROC) glad_gl_on_demand_loader("glGetBufferPointerv");
    glad_glGetBufferPointerv(target, pname, params);
}
PFNGLGETBUFFERPOINTERVPROC glad_glGetBufferPointerv = glad_on_demand_impl_glGetBufferPointerv;
static void GLAD_API_PTR glad_on_demand_impl_glGetBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, void * data) {
    glad_glGetBufferSubData = (PFNGLGETBUFFERSUBDATAPROC) glad_gl_on_demand_loader("glGetBufferSubData");
    glad_glGetBufferSubData(target, offset, size, data);
}
PFNGLGETBUFFERSUBDATAPROC glad_glGetBufferSubData = glad_on_demand_impl_glGetBufferSubData;
static void GLAD_API_PTR glad_on_demand_impl_glGetCompressedTexImage(GLenum target, GLint level, void * img) {
    glad_glGetCompressedTexImage = (PFNGLGETCOMPRESSEDTEXIMAGEPROC) glad_gl_on_demand_loader("glGetCompressedTexImage");
    glad_glGetCompressedTexImage(target, level, img);
}
PFNGLGETCOMPRESSEDTEXIMAGEPROC glad_glGetCompressedTexImage = glad_on_demand_impl_glGetCompressedTexImage;
static void GLAD_API_PTR glad_on_demand_impl_glGetDoublev(GLenum pname, GLdouble * data) {
    glad_glGetDoublev = (PFNGLGETDOUBLEVPROC) glad_gl_on_demand_loader("glGetDoublev");
    glad_glGetDoublev(pname, data);
}
PFNGLGETDOUBLEVPROC glad_glGetDoublev = glad_on_demand_impl_glGetDoublev;
static GLenum GLAD_API_PTR glad_on_demand_impl_glGetError(void) {
    glad_glGetError = (PFNGLGETERRORPROC) glad_gl_on_demand_loader("glGetError");
    return glad_glGetError();
}
PFNGLGETERRORPROC glad_glGetError = glad_on_demand_impl_glGetError;
static void GLAD_API_PTR glad_on_demand_impl_glGetFloatv(GLenum pname, GLfloat * data) {
    glad_glGetFloatv = (PFNGLGETFLOATVPROC) glad_gl_on_demand_loader("glGetFloatv");
    glad_glGetFloatv(pname, data);
}
PFNGLGETFLOATVPROC glad_glGetFloatv = glad_on_demand_impl_glGetFloatv;
static GLint GLAD_API_PTR glad_on_demand_impl_glGetFragDataIndex(GLuint program, const GLchar * name) {
    glad_glGetFragDataIndex = (PFNGLGETFRAGDATAINDEXPROC) glad_gl_on_demand_loader("glGetFragDataIndex");
    return glad_glGetFragDataIndex(program, name);
}
PFNGLGETFRAGDATAINDEXPROC glad_glGetFragDataIndex = glad_on_demand_impl_glGetFragDataIndex;
static GLint GLAD_API_PTR glad_on_demand_impl_glGetFragDataLocation(GLuint program, const GLchar * name) {
    glad_glGetFragDataLocation = (PFNGLGETFRAGDATALOCATIONPROC) glad_gl_on_demand_loader("glGetFragDataLocation");
    return glad_glGetFragDataLocation(program, name);
}
PFNGLGETFRAGDATALOCATIONPROC glad_glGetFragDataLocation = glad_on_demand_impl_glGetFragDataLocation;
static void GLAD_API_PTR glad_on_demand_impl_glGetFramebufferAttachmentParameteriv(GLenum target, GLenum attachment, GLenum pname, GLint * params) {
    glad_glGetFramebufferAttachmentParameteriv = (PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC) glad_gl_on_demand_loader("glGetFramebufferAttachmentParameteriv");
    glad_glGetFramebufferAttachmentParameteriv(target, attachment, pname, params);
}
PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC glad_glGetFramebufferAttachmentParameteriv = glad_on_demand_impl_glGetFramebufferAttachmentParameteriv;
static void GLAD_API_PTR glad_on_demand_impl_glGetInteger64i_v(GLenum target, GLuint index, GLint64 * data) {
    glad_glGetInteger64i_v = (PFNGLGETINTEGER64I_VPROC) glad_gl_on_demand_loader("glGetInteger64i_v");
    glad_glGetInteger64i_v(target, index, data);
}
PFNGLGETINTEGER64I_VPROC glad_glGetInteger64i_v = glad_on_demand_impl_glGetInteger64i_v;
static void GLAD_API_PTR glad_on_demand_impl_glGetInteger64v(GLenum pname, GLint64 * data) {
    glad_glGetInteger64v = (PFNGLGETINTEGER64VPROC) glad_gl_on_demand_loader("glGetInteger64v");
    glad_glGetInteger64v(pname, data);
}
PFNGLGETINTEGER64VPROC glad_glGetInteger64v = glad_on_demand_impl_glGetInteger64v;
static void GLAD_API_PTR glad_on_demand_impl_glGetIntegeri_v(GLenum target, GLuint index, GLint * data) {
    glad_glGetIntegeri_v = (PFNGLGETINTEGERI_VPROC) glad_gl_on_demand_loader("glGetIntegeri_v");
    glad_glGetIntegeri_v(target, index, data);
}
PFNGLGETINTEGERI_VPROC glad_glGetIntegeri_v = glad_on_demand_impl_glGetIntegeri_v;
static void GLAD_API_PTR glad_on_demand_impl_glGetIntegerv(GLenum pname, GLint * data) {
    glad_glGetIntegerv = (PFNGLGETINTEGERVPROC) glad_gl_on_demand_loader("glGetIntegerv");
    glad_glGetIntegerv(pname, data);
}
PFNGLGETINTEGERVPROC glad_glGetIntegerv = glad_on_demand_impl_glGetIntegerv;
static void GLAD_API_PTR glad_on_demand_impl_glGetMultisamplefv(GLenum pname, GLuint index, GLfloat * val) {
    glad_glGetMultisamplefv = (PFNGLGETMULTISAMPLEFVPROC) glad_gl_on_demand_loader("glGetMultisamplefv");
    glad_glGetMultisamplefv(pname, index, val);
}
PFNGLGETMULTISAMPLEFVPROC glad_glGetMultisamplefv = glad_on_demand_impl_glGetMultisamplefv;
static void GLAD_API_PTR glad_on_demand_impl_glGetProgramInfoLog(GLuint program, GLsizei bufSize, GLsizei * length, GLchar * infoLog) {
    glad_glGetProgramInfoLog = (PFNGLGETPROGRAMINFOLOGPROC) glad_gl_on_demand_loader("glGetProgramInfoLog");
    glad_glGetProgramInfoLog(program, bufSize, length, infoLog);
}
PFNGLGETPROGRAMINFOLOGPROC glad_glGetProgramInfoLog = glad_on_demand_impl_glGetProgramInfoLog;
static void GLAD_API_PTR glad_on_demand_impl_glGetProgramiv(GLuint program, GLenum pname, GLint * params) {
    glad_glGetProgramiv = (PFNGLGETPROGRAMIVPROC) glad_gl_on_demand_loader("glGetProgramiv");
    glad_glGetProgramiv(program, pname, params);
}
PFNGLGETPROGRAMIVPROC glad_glGetProgramiv = glad_on_demand_impl_glGetProgramiv;
static void GLAD_API_PTR glad_on_demand_impl_glGetQueryObjecti64v(GLuint id, GLenum pname, GLint64 * params) {
    glad_glGetQueryObjecti64v = (PFNGLGETQUERYOBJECTI64VPROC) glad_gl_on_demand_loader("glGetQueryObjecti64v");
    glad_glGetQueryObjecti64v(id, pname, params);
}
PFNGLGETQUERYOBJECTI64VPROC glad_glGetQueryObjecti64v = glad_on_demand_impl_glGetQueryObjecti64v;
static void GLAD_API_PTR glad_on_demand_impl_glGetQueryObjectiv(GLuint id, GLenum pname, GLint * params) {
    glad_glGetQueryObjectiv = (PFNGLGETQUERYOBJECTIVPROC) glad_gl_on_demand_loader("glGetQueryObjectiv");
    glad_glGetQueryObjectiv(id, pname, params);
}
PFNGLGETQUERYOBJECTIVPROC glad_glGetQueryObjectiv = glad_on_demand_impl_glGetQueryObjectiv;
static void GLAD_API_PTR glad_on_demand_impl_glGetQueryObjectui64v(GLuint id, GLenum pname, GLuint64 * params) {
    glad_glGetQueryObjectui64v = (PFNGLGETQUERYOBJECTUI64VPROC) glad_gl_on_demand_loader("glGetQueryObjectui64v");
    glad_glGetQueryObjectui64v(id, pname, params);
}
PFNGLGETQUERYOBJECTUI64VPROC glad_glGetQueryObjectui64v = glad_on_demand_impl_glGetQueryObjectui64v;
static void GLAD_API_PTR glad_on_demand_impl_glGetQueryObjectuiv(GLuint id, GLenum pname, GLuint * params) {
    glad_glGetQueryObjectuiv = (PFNGLGETQUERYOBJECTUIVPROC) glad_gl_on_demand_loader("glGetQueryObjectuiv");
    glad_glGetQueryObjectuiv(id, pname, params);
}
PFNGLGETQUERYOBJECTUIVPROC glad_glGetQueryObjectuiv = glad_on_demand_impl_glGetQueryObjectuiv;
static void GLAD_API_PTR glad_on_demand_impl_glGetQueryiv(GLenum target, GLenum pname, GLint * params) {
    glad_glGetQueryiv = (PFNGLGETQUERYIVPROC) glad_gl_on_demand_loader("glGetQueryiv");
    glad_glGetQueryiv(target, pname, params);
}
PFNGLGETQUERYIVPROC glad_glGetQueryiv = glad_on_demand_impl_glGetQueryiv;
static void GLAD_API_PTR glad_on_demand_impl_glGetRenderbufferParameteriv(GLenum target, GLenum pname, GLint * params) {
    glad_glGetRenderbufferParameteriv = (PFNGLGETRENDERBUFFERPARAMETERIVPROC) glad_gl_on_demand_loader("glGetRenderbufferParameteriv");
    glad_glGetRenderbufferParameteriv(target, pname, params);
}
PFNGLGETRENDERBUFFERPARAMETERIVPROC glad_glGetRenderbufferParameteriv = glad_on_demand_impl_glGetRenderbufferParameteriv;
static void GLAD_API_PTR glad_on_demand_impl_glGetSamplerParameterIiv(GLuint sampler, GLenum pname, GLint * params) {
    glad_glGetSamplerParameterIiv = (PFNGLGETSAMPLERPARAMETERIIVPROC) glad_gl_on_demand_loader("glGetSamplerParameterIiv");
    glad_glGetSamplerParameterIiv(sampler, pname, params);
}
PFNGLGETSAMPLERPARAMETERIIVPROC glad_glGetSamplerParameterIiv = glad_on_demand_impl_glGetSamplerParameterIiv;
static void GLAD_API_PTR glad_on_demand_impl_glGetSamplerParameterIuiv(GLuint sampler, GLenum pname, GLuint * params) {
    glad_glGetSamplerParameterIuiv = (PFNGLGETSAMPLERPARAMETERIUIVPROC) glad_gl_on_demand_loader("glGetSamplerParameterIuiv");
    glad_glGetSamplerParameterIuiv(sampler, pname, params);
}
PFNGLGETSAMPLERPARAMETERIUIVPROC glad_glGetSamplerParameterIuiv = glad_on_demand_impl_glGetSamplerParameterIuiv;
static void GLAD_API_PTR glad_on_demand_impl_glGetSamplerParameterfv(GLuint sampler, GLenum pname, GLfloat * params) {
    glad_glGetSamplerParameterfv = (PFNGLGETSAMPLERPARAMETERFVPROC) glad_gl_on_demand_loader("glGetSamplerParameterfv");
    glad_glGetSamplerParameterfv(sampler, pname, params);
}
PFNGLGETSAMPLERPARAMETERFVPROC glad_glGetSamplerParameterfv = glad_on_demand_impl_glGetSamplerParameterfv;
static void GLAD_API_PTR glad_on_demand_impl_glGetSamplerParameteriv(GLuint sampler, GLenum pname, GLint * params) {
    glad_glGetSamplerParameteriv = (PFNGLGETSAMPLERPARAMETERIVPROC) glad_gl_on_demand_loader("glGetSamplerParameteriv");
    glad_glGetSamplerParameteriv(sampler, pname, params);
}
PFNGLGETSAMPLERPARAMETERIVPROC glad_glGetSamplerParameteriv = glad_on_demand_impl_glGetSamplerParameteriv;
static void GLAD_API_PTR glad_on_demand_impl_glGetShaderInfoLog(GLuint shader, GLsizei bufSize, GLsizei * length, GLchar * infoLog) {
    glad_glGetShaderInfoLog = (PFNGLGETSHADERINFOLOGPROC) glad_gl_on_demand_loader("glGetShaderInfoLog");
    glad_glGetShaderInfoLog(shader, bufSize, length, infoLog);
}
PFNGLGETSHADERINFOLOGPROC glad_glGetShaderInfoLog = glad_on_demand_impl_glGetShaderInfoLog;
static void GLAD_API_PTR glad_on_demand_impl_glGetShaderSource(GLuint shader, GLsizei bufSize, GLsizei * length, GLchar * source) {
    glad_glGetShaderSource = (PFNGLGETSHADERSOURCEPROC) glad_gl_on_demand_loader("glGetShaderSource");
    glad_glGetShaderSource(shader, bufSize, length, source);
}
PFNGLGETSHADERSOURCEPROC glad_glGetShaderSource = glad_on_demand_impl_glGetShaderSource;
static void GLAD_API_PTR glad_on_demand_impl_glGetShaderiv(GLuint shader, GLenum pname, GLint * params) {
    glad_glGetShaderiv = (PFNGLGETSHADERIVPROC) glad_gl_on_demand_loader("glGetShaderiv");
    glad_glGetShaderiv(shader, pname, params);
}
PFNGLGETSHADERIVPROC glad_glGetShaderiv = glad_on_demand_impl_glGetShaderiv;
static const GLubyte * GLAD_API_PTR glad_on_demand_impl_glGetString(GLenum name) {
    glad_glGetString = (PFNGLGETSTRINGPROC) glad_gl_on_demand_loader("glGetString");
    return glad_glGetString(name);
}
PFNGLGETSTRINGPROC glad_glGetString = glad_on_demand_impl_glGetString;
static const GLubyte * GLAD_API_PTR glad_on_demand_impl_glGetStringi(GLenum name, GLuint index) {
    glad_glGetStringi = (PFNGLGETSTRINGIPROC) glad_gl_on_demand_loader("glGetStringi");
    return glad_glGetStringi(name, index);
}
PFNGLGETSTRINGIPROC glad_glGetStringi = glad_on_demand_impl_glGetStringi;
static void GLAD_API_PTR glad_on_demand_impl_glGetSynciv(GLsync sync, GLenum pname, GLsizei count, GLsizei * length, GLint * values) {
    glad_glGetSynciv = (PFNGLGETSYNCIVPROC) glad_gl_on_demand_loader("glGetSynciv");
    glad_glGetSynciv(sync, pname, count, length, values);
}
PFNGLGETSYNCIVPROC glad_glGetSynciv = glad_on_demand_impl_glGetSynciv;
static void GLAD_API_PTR glad_on_demand_impl_glGetTexImage(GLenum target, GLint level, GLenum format, GLenum type, void * pixels) {
    glad_glGetTexImage = (PFNGLGETTEXIMAGEPROC) glad_gl_on_demand_loader("glGetTexImage");
    glad_glGetTexImage(target, level, format, type, pixels);
}
PFNGLGETTEXIMAGEPROC glad_glGetTexImage = glad_on_demand_impl_glGetTexImage;
static void GLAD_API_PTR glad_on_demand_impl_glGetTexLevelParameterfv(GLenum target, GLint level, GLenum pname, GLfloat * params) {
    glad_glGetTexLevelParameterfv = (PFNGLGETTEXLEVELPARAMETERFVPROC) glad_gl_on_demand_loader("glGetTexLevelParameterfv");
    glad_glGetTexLevelParameterfv(target, level, pname, params);
}
PFNGLGETTEXLEVELPARAMETERFVPROC glad_glGetTexLevelParameterfv = glad_on_demand_impl_glGetTexLevelParameterfv;
static void GLAD_API_PTR glad_on_demand_impl_glGetTexLevelParameteriv(GLenum target, GLint level, GLenum pname, GLint * params) {
    glad_glGetTexLevelParameteriv = (PFNGLGETTEXLEVELPARAMETERIVPROC) glad_gl_on_demand_loader("glGetTexLevelParameteriv");
    glad_glGetTexLevelParameteriv(target, level, pname, params);
}
PFNGLGETTEXLEVELPARAMETERIVPROC glad_glGetTexLevelParameteriv = glad_on_demand_impl_glGetTexLevelParameteriv;
static void GLAD_API_PTR glad_on_demand_impl_glGetTexParameterIiv(GLenum target, GLenum pname, GLint * params) {
    glad_glGetTexParameterIiv = (PFNGLGETTEXPARAMETERIIVPROC) glad_gl_on_demand_loader("glGetTexParameterIiv");
    glad_glGetTexParameterIiv(target, pname, params);
}
PFNGLGETTEXPARAMETERIIVPROC glad_glGetTexParameterIiv = glad_on_demand_impl_glGetTexParameterIiv;
static void GLAD_API_PTR glad_on_demand_impl_glGetTexParameterIuiv(GLenum target, GLenum pname, GLuint * params) {
    glad_glGetTexParameterIuiv = (PFNGLGETTEXPARAMETERIUIVPROC) glad_gl_on_demand_loader("glGetTexParameterIuiv");
    glad_glGetTexParameterIuiv(target, pname, params);
}
PFNGLGETTEXPARAMETERIUIVPROC glad_glGetTexParameterIuiv = glad_on_demand_impl_glGetTexParameterIuiv;
static void GLAD_API_PTR glad_on_demand_impl_glGetTexParameterfv(GLenum target, GLenum pname, GLfloat * params) {
    glad_glGetTexParameterfv = (PFNGLGETTEXPARAMETERFVPROC) glad_gl_on_demand_loader("glGetTexParameterfv");
    glad_glGetTexParameterfv(target, pname, params);
}
PFNGLGETTEXPARAMETERFVPROC glad_glGetTexParameterfv = glad_on_demand_impl_glGetTexParameterfv;
static void GLAD_API_PTR glad_on_demand_impl_glGetTexParameteriv(GLenum target, GLenum pname, GLint * params) {
    glad_glGetTexParameteriv = (PFNGLGETTEXPARAMETERIVPROC) glad_gl_on_demand_loader("glGetTexParameteriv");
    glad_glGetTexParameteriv(target, pname, params);
}
PFNGLGETTEXPARAMETERIVPROC glad_glGetTexParameteriv = glad_on_demand_impl_glGetTexParameteriv;
static void GLAD_API_PTR glad_on_demand_impl_glGetTransformFeedbackVarying(GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLsizei * size, GLenum * type, GLchar * name) {
    glad_glGetTransformFeedbackVarying = (PFNGLGETTRANSFORMFEEDBACKVARYINGPROC) glad_gl_on_demand_loader("glGetTransformFeedbackVarying");
    glad_glGetTransformFeedbackVarying(program, index, bufSize, length, size, type, name);
}
PFNGLGETTRANSFORMFEEDBACKVARYINGPROC glad_glGetTransformFeedbackVarying = glad_on_demand_impl_glGetTransformFeedbackVarying;
static GLuint GLAD_API_PTR glad_on_demand_impl_glGetUniformBlockIndex(GLuint program, const GLchar * uniformBlockName) {
    glad_glGetUniformBlockIndex = (PFNGLGETUNIFORMBLOCKINDEXPROC) glad_gl_on_demand_loader("glGetUniformBlockIndex");
    return glad_glGetUniformBlockIndex(program, uniformBlockName);
}
PFNGLGETUNIFORMBLOCKINDEXPROC glad_glGetUniformBlockIndex = glad_on_demand_impl_glGetUniformBlockIndex;
static void GLAD_API_PTR glad_on_demand_impl_glGetUniformIndices(GLuint program, GLsizei uniformCount, const GLchar *const* uniformNames, GLuint * uniformIndices) {
    glad_glGetUniformIndices = (PFNGLGETUNIFORMINDICESPROC) glad_gl_on_demand_loader("glGetUniformIndices");
    glad_glGetUniformIndices(program, uniformCount, uniformNames, uniformIndices);
}
PFNGLGETUNIFORMINDICESPROC glad_glGetUniformIndices = glad_on_demand_impl_glGetUniformIndices;
static GLint GLAD_API_PTR glad_on_demand_impl_glGetUniformLocation(GLuint program, const GLchar * name) {
    glad_glGetUniformLocation = (PFNGLGETUNIFORMLOCATIONPROC) glad_gl_on_demand_loader("glGetUniformLocation");
    return glad_glGetUniformLocation(program, name);
}
PFNGLGETUNIFORMLOCATIONPROC glad_glGetUniformLocation = glad_on_demand_impl_glGetUniformLocation;
static void GLAD_API_PTR glad_on_demand_impl_glGetUniformfv(GLuint program, GLint location, GLfloat * params) {
    glad_glGetUniformfv = (PFNGLGETUNIFORMFVPROC) glad_gl_on_demand_loader("glGetUniformfv");
    glad_glGetUniformfv(program, location, params);
}
PFNGLGETUNIFORMFVPROC glad_glGetUniformfv = glad_on_demand_impl_glGetUniformfv;
static void GLAD_API_PTR glad_on_demand_impl_glGetUniformiv(GLuint program, GLint location, GLint * params) {
    glad_glGetUniformiv = (PFNGLGETUNIFORMIVPROC) glad_gl_on_demand_loader("glGetUniformiv");
    glad_glGetUniformiv(program, location, params);
}
PFNGLGETUNIFORMIVPROC glad_glGetUniformiv = glad_on_demand_impl_glGetUniformiv;
static void GLAD_API_PTR glad_on_demand_impl_glGetUniformuiv(GLuint program, GLint location, GLuint * params) {
    glad_glGetUniformuiv = (PFNGLGETUNIFORMUIVPROC) glad_gl_on_demand_loader("glGetUniformuiv");
    glad_glGetUniformuiv(program, location, params);
}
PFNGLGETUNIFORMUIVPROC glad_glGetUniformuiv = glad_on_demand_impl_glGetUniformuiv;
static void GLAD_API_PTR glad_on_demand_impl_glGetVertexAttribIiv(GLuint index, GLenum pname, GLint * params) {
    glad_glGetVertexAttribIiv = (PFNGLGETVERTEXATTRIBIIVPROC) glad_gl_on_demand_loader("glGetVertexAttribIiv");
    glad_glGetVertexAttribIiv(index, pname, params);
}
PFNGLGETVERTEXATTRIBIIVPROC glad_glGetVertexAttribIiv = glad_on_demand_impl_glGetVertexAttribIiv;
static void GLAD_API_PTR glad_on_demand_impl_glGetVertexAttribIuiv(GLuint index, GLenum pname, GLuint * params) {
    glad_glGetVertexAttribIuiv = (PFNGLGETVERTEXATTRIBIUIVPROC) glad_gl_on_demand_loader("glGetVertexAttribIuiv");
    glad_glGetVertexAttribIuiv(index, pname, params);
}
PFNGLGETVERTEXATTRIBIUIVPROC glad_glGetVertexAttribIuiv = glad_on_demand_impl_glGetVertexAttribIuiv;
static void GLAD_API_PTR glad_on_demand_impl_glGetVertexAttribPointerv(GLuint index, GLenum pname, void ** pointer) {
    glad_glGetVertexAttribPointerv = (PFNGLGETVERTEXATTRIBPOINTERVPROC) glad_gl_on_demand_loader("glGetVertexAttribPointerv");
    glad_glGetVertexAttribPointerv(index, pname, pointer);
}
PFNGLGETVERTEXATTRIBPOINTERVPROC glad_glGetVertexAttribPointerv = glad_on_demand_impl_glGetVertexAttribPointerv;
static void GLAD_API_PTR glad_on_demand_impl_glGetVertexAttribdv(GLuint index, GLenum pname, GLdouble * params) {
    glad_glGetVertexAttribdv = (PFNGLGETVERTEXATTRIBDVPROC) glad_gl_on_demand_loader("glGetVertexAttribdv");
    glad_glGetVertexAttribdv(index, pname, params);
}
PFNGLGETVERTEXATTRIBDVPROC glad_glGetVertexAttribdv = glad_on_demand_impl_glGetVertexAttribdv;
static void GLAD_API_PTR glad_on_demand_impl_glGetVertexAttribfv(GLuint index, GLenum pname, GLfloat * params) {
    glad_glGetVertexAttribfv = (PFNGLGETVERTEXATTRIBFVPROC) glad_gl_on_demand_loader("glGetVertexAttribfv");
    glad_glGetVertexAttribfv(index, pname, params);
}
PFNGLGETVERTEXATTRIBFVPROC glad_glGetVertexAttribfv = glad_on_demand_impl_glGetVertexAttribfv;
static void GLAD_API_PTR glad_on_demand_impl_glGetVertexAttribiv(GLuint index, GLenum pname, GLint * params) {
    glad_glGetVertexAttribiv = (PFNGLGETVERTEXATTRIBIVPROC) glad_gl_on_demand_loader("glGetVertexAttribiv");
    glad_glGetVertexAttribiv(index, pname, params);
}
PFNGLGETVERTEXATTRIBIVPROC glad_glGetVertexAttribiv = glad_on_demand_impl_glGetVertexAttribiv;
static void GLAD_API_PTR glad_on_demand_impl_glHint(GLenum target, GLenum mode) {
    glad_glHint = (PFNGLHINTPROC) glad_gl_on_demand_loader("glHint");
    glad_glHint(target, mode);
}
PFNGLHINTPROC glad_glHint = glad_on_demand_impl_glHint;
static GLboolean GLAD_API_PTR glad_on_demand_impl_glIsBuffer(GLuint buffer) {
    glad_glIsBuffer = (PFNGLISBUFFERPROC) glad_gl_on_demand_loader("glIsBuffer");
    return glad_glIsBuffer(buffer);
}
PFNGLISBUFFERPROC glad_glIsBuffer = glad_on_demand_impl_glIsBuffer;
static GLboolean GLAD_API_PTR glad_on_demand_impl_glIsEnabled(GLenum cap) {
    glad_glIsEnabled = (PFNGLISENABLEDPROC) glad_gl_on_demand_loader("glIsEnabled");
    return glad_glIsEnabled(cap);
}
PFNGLISENABLEDPROC glad_glIsEnabled = glad_on_demand_impl_glIsEnabled;
static GLboolean GLAD_API_PTR glad_on_demand_impl_glIsEnabledi(GLenum target, GLuint index) {
    glad_glIsEnabledi = (PFNGLISENABLEDIPROC) glad_gl_on_demand_loader("glIsEnabledi");
    return glad_glIsEnabledi(target, index);
}
PFNGLISENABLEDIPROC glad_glIsEnabledi = glad_on_demand_impl_glIsEnabledi;
static GLboolean GLAD_API_PTR glad_on_demand_impl_glIsFramebuffer(GLuint framebuffer) {
    glad_glIsFramebuffer = (PFNGLISFRAMEBUFFERPROC) glad_gl_on_demand_loader("glIsFramebuffer");
    return glad_glIsFramebuffer(framebuffer);
}
PFNGLISFRAMEBUFFERPROC glad_glIsFramebuffer = glad_on_demand_impl_glIsFramebuffer;
static GLboolean GLAD_API_PTR glad_on_demand_impl_glIsProgram(GLuint program) {
    glad_glIsProgram = (PFNGLISPROGRAMPROC) glad_gl_on_demand_loader("glIsProgram");
    return glad_glIsProgram(program);
}
PFNGLISPROGRAMPROC glad_glIsProgram = glad_on_demand_impl_glIsProgram;
static GLboolean GLAD_API_PTR glad_on_demand_impl_glIsQuery(GLuint id) {
    glad_glIsQuery = (PFNGLISQUERYPROC) glad_gl_on_demand_loader("glIsQuery");
    return glad_glIsQuery(id);
}
PFNGLISQUERYPROC glad_glIsQuery = glad_on_demand_impl_glIsQuery;
static GLboolean GLAD_API_PTR glad_on_demand_impl_glIsRenderbuffer(GLuint renderbuffer) {
    glad_glIsRenderbuffer = (PFNGLISRENDERBUFFERPROC) glad_gl_on_demand_loader("glIsRenderbuffer");
    return glad_glIsRenderbuffer(renderbuffer);
}
PFNGLISRENDERBUFFERPROC glad_glIsRenderbuffer = glad_on_demand_impl_glIsRenderbuffer;
static GLboolean GLAD_API_PTR glad_on_demand_impl_glIsSampler(GLuint sampler) {
    glad_glIsSampler = (PFNGLISSAMPLERPROC) glad_gl_on_demand_loader("glIsSampler");
    return glad_glIsSampler(sampler);
}
PFNGLISSAMPLERPROC glad_glIsSampler = glad_on_demand_impl_glIsSampler;
static GLboolean GLAD_API_PTR glad_on_demand_impl_glIsShader(GLuint shader) {
    glad_glIsShader = (PFNGLISSHADERPROC) glad_gl_on_demand_loader("glIsShader");
    return glad_glIsShader(shader);
}
PFNGLISSHADERPROC glad_glIsShader = glad_on_demand_impl_glIsShader;
static GLboolean GLAD_API_PTR glad_on_demand_impl_glIsSync(GLsync sync) {
    glad_glIsSync = (PFNGLISSYNCPROC) glad_gl_on_demand_loader("glIsSync");
    return glad_glIsSync(sync);
}
PFNGLISSYNCPROC glad_glIsSync = glad_on_demand_impl_glIsSync;
static GLboolean GLAD_API_PTR glad_on_demand_impl_glIsTexture(GLuint texture) {
    glad_glIsTexture = (PFNGLISTEXTUREPROC) glad_gl_on_demand_loader("glIsTexture");
    return glad_glIsTexture(texture);
}
PFNGLISTEXTUREPROC glad_glIsTexture = glad_on_demand_impl_glIsTexture;
static GLboolean GLAD_API_PTR glad_on_demand_impl_glIsVertexArray(GLuint array) {
    glad_glIsVertexArray = (PFNGLISVERTEXARRAYPROC) glad_gl_on_demand_loader("glIsVertexArray");
    return glad_glIsVertexArray(array);
}
PFNGLISVERTEXARRAYPROC glad_glIsVertexArray = glad_on_demand_impl_glIsVertexArray;
static void GLAD_API_PTR glad_on_demand_impl_glLineWidth(GLfloat width) {
    glad_glLineWidth = (PFNGLLINEWIDTHPROC) glad_gl_on_demand_loader("glLineWidth");
    glad_glLineWidth(width);
}
PFNGLLINEWIDTHPROC glad_glLineWidth = glad_on_demand_impl_glLineWidth;
static void GLAD_API_PTR glad_on_demand_impl_glLinkProgram(GLuint program) {
    glad_glLinkProgram = (PFNGLLINKPROGRAMPROC) glad_gl_on_demand_loader("glLinkProgram");
    glad_glLinkProgram(program);
}
PFNGLLINKPROGRAMPROC glad_glLinkProgram = glad_on_demand_impl_glLinkProgram;
static void GLAD_API_PTR glad_on_demand_impl_glLogicOp(GLenum opcode) {
    glad_glLogicOp = (PFNGLLOGICOPPROC) glad_gl_on_demand_loader("glLogicOp");
    glad_glLogicOp(opcode);
}
PFNGLLOGICOPPROC glad_glLogicOp = glad_on_demand_impl_glLogicOp;
static void * GLAD_API_PTR glad_on_demand_impl_glMapBuffer(GLenum target, GLenum access) {
    glad_glMapBuffer = (PFNGLMAPBUFFERPROC) glad_gl_on_demand_loader("glMapBuffer");
    return glad_glMapBuffer(target, access);
}
PFNGLMAPBUFFERPROC glad_glMapBuffer = glad_on_demand_impl_glMapBuffer;
static void * GLAD_API_PTR glad_on_demand_impl_glMapBufferRange(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access) {
    glad_glMapBufferRange = (PFNGLMAPBUFFERRANGEPROC) glad_gl_on_demand_loader("glMapBufferRange");
    return glad_glMapBufferRange(target, offset, length, access);
}
PFNGLMAPBUFFERRANGEPROC glad_glMapBufferRange = glad_on_demand_impl_glMapBufferRange;
static void GLAD_API_PTR glad_on_demand_impl_glMultiDrawArrays(GLenum mode, const GLint * first, const GLsizei * count, GLsizei drawcount) {
    glad_glMultiDrawArrays = (PFNGLMULTIDRAWARRAYSPROC) glad_gl_on_demand_loader("glMultiDrawArrays");
    glad_glMultiDrawArrays(mode, first, count, drawcount);
}
PFNGLMULTIDRAWARRAYSPROC glad_glMultiDrawArrays = glad_on_demand_impl_glMultiDrawArrays;
static void GLAD_API_PTR glad_on_demand_impl_glMultiDrawElements(GLenum mode, const GLsizei * count, GLenum type, const void *const* indices, GLsizei drawcount) {
    glad_glMultiDrawElements = (PFNGLMULTIDRAWELEMENTSPROC) glad_gl_on_demand_loader("glMultiDrawElements");
    glad_glMultiDrawElements(mode, count, type, indices, drawcount);
}
PFNGLMULTIDRAWELEMENTSPROC glad_glMultiDrawElements = glad_on_demand_impl_glMultiDrawElements;
static void GLAD_API_PTR glad_on_demand_impl_glMultiDrawElementsBaseVertex(GLenum mode, const GLsizei * count, GLenum type, const void *const* indices, GLsizei drawcount, const GLint * basevertex) {
    glad_glMultiDrawElementsBaseVertex = (PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC) glad_gl_on_demand_loader("glMultiDrawElementsBaseVertex");
    glad_glMultiDrawElementsBaseVertex(mode, count, type, indices, drawcount, basevertex);
}
PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC glad_glMultiDrawElementsBaseVertex = glad_on_demand_impl_glMultiDrawElementsBaseVertex;
static void GLAD_API_PTR glad_on_demand_impl_glPixelStoref(GLenum pname, GLfloat param) {
    glad_glPixelStoref = (PFNGLPIXELSTOREFPROC) glad_gl_on_demand_loader("glPixelStoref");
    glad_glPixelStoref(pname, param);
}
PFNGLPIXELSTOREFPROC glad_glPixelStoref = glad_on_demand_impl_glPixelStoref;
static void GLAD_API_PTR glad_on_demand_impl_glPixelStorei(GLenum pname, GLint param) {
    glad_glPixelStorei = (PFNGLPIXELSTOREIPROC) glad_gl_on_demand_loader("glPixelStorei");
    glad_glPixelStorei(pname, param);
}
PFNGLPIXELSTOREIPROC glad_glPixelStorei = glad_on_demand_impl_glPixelStorei;
static void GLAD_API_PTR glad_on_demand_impl_glPointParameterf(GLenum pname, GLfloat param) {
    glad_glPointParameterf = (PFNGLPOINTPARAMETERFPROC) glad_gl_on_demand_loader("glPointParameterf");
    glad_glPointParameterf(pname, param);
}
PFNGLPOINTPARAMETERFPROC glad_glPointParameterf = glad_on_demand_impl_glPointParameterf;
static void GLAD_API_PTR glad_on_demand_impl_glPointParameterfv(GLenum pname, const GLfloat * params) {
    glad_glPointParameterfv = (PFNGLPOINTPARAMETERFVPROC) glad_gl_on_demand_loader("glPointParameterfv");
    glad_glPointParameterfv(pname, params);
}
PFNGLPOINTPARAMETERFVPROC glad_glPointParameterfv = glad_on_demand_impl_glPointParameterfv;
static void GLAD_API_PTR glad_on_demand_impl_glPointParameteri(GLenum pname, GLint param) {
    glad_glPointParameteri = (PFNGLPOINTPARAMETERIPROC) glad_gl_on_demand_loader("glPointParameteri");
    glad_glPointParameteri(pname, param);
}
PFNGLPOINTPARAMETERIPROC glad_glPointParameteri = glad_on_demand_impl_glPointParameteri;
static void GLAD_API_PTR glad_on_demand_impl_glPointParameteriv(GLenum pname, const GLint * params) {
    glad_glPointParameteriv = (PFNGLPOINTPARAMETERIVPROC) glad_gl_on_demand_loader("glPointParameteriv");
    glad_glPointParameteriv(pname, params);
}
PFNGLPOINTPARAMETERIVPROC glad_glPointParameteriv = glad_on_demand_impl_glPointParameteriv;
static void GLAD_API_PTR glad_on_demand_impl_glPointSize(GLfloat size) {
    glad_glPointSize = (PFNGLPOINTSIZEPROC) glad_gl_on_demand_loader("glPointSize");
    glad_glPointSize(size);
}
PFNGLPOINTSIZEPROC glad_glPointSize = glad_on_demand_impl_glPointSize;
static void GLAD_API_PTR glad_on_demand_impl_glPolygonMode(GLenum face, GLenum mode) {
    glad_glPolygonMode = (PFNGLPOLYGONMODEPROC) glad_gl_on_demand_loader("glPolygonMode");
    glad_glPolygonMode(face, mode);
}
PFNGLPOLYGONMODEPROC glad_glPolygonMode = glad_on_demand_impl_glPolygonMode;
static void GLAD_API_PTR glad_on_demand_impl_glPolygonOffset(GLfloat factor, GLfloat units) {
    glad_glPolygonOffset = (PFNGLPOLYGONOFFSETPROC) glad_gl_on_demand_loader("glPolygonOffset");
    glad_glPolygonOffset(factor, units);
}
PFNGLPOLYGONOFFSETPROC glad_glPolygonOffset = glad_on_demand_impl_glPolygonOffset;
static void GLAD_API_PTR glad_on_demand_impl_glPrimitiveRestartIndex(GLuint index) {
    glad_glPrimitiveRestartIndex = (PFNGLPRIMITIVERESTARTINDEXPROC) glad_gl_on_demand_loader("glPrimitiveRestartIndex");
    glad_glPrimitiveRestartIndex(index);
}
PFNGLPRIMITIVERESTARTINDEXPROC glad_glPrimitiveRestartIndex = glad_on_demand_impl_glPrimitiveRestartIndex;
static void GLAD_API_PTR glad_on_demand_impl_glProvokingVertex(GLenum mode) {
    glad_glProvokingVertex = (PFNGLPROVOKINGVERTEXPROC) glad_gl_on_demand_loader("glProvokingVertex");
    glad_glProvokingVertex(mode);
}
PFNGLPROVOKINGVERTEXPROC glad_glProvokingVertex = glad_on_demand_impl_glProvokingVertex;
static void GLAD_API_PTR glad_on_demand_impl_glQueryCounter(GLuint id, GLenum target) {
    glad_glQueryCounter = (PFNGLQUERYCOUNTERPROC) glad_gl_on_demand_loader("glQueryCounter");
    glad_glQueryCounter(id, target);
}
PFNGLQUERYCOUNTERPROC glad_glQueryCounter = glad_on_demand_impl_glQueryCounter;
static void GLAD_API_PTR glad_on_demand_impl_glReadBuffer(GLenum src) {
    glad_glReadBuffer = (PFNGLREADBUFFERPROC) glad_gl_on_demand_loader("glReadBuffer");
    glad_glReadBuffer(src);
}
PFNGLREADBUFFERPROC glad_glReadBuffer = glad_on_demand_impl_glReadBuffer;
static void GLAD_API_PTR glad_on_demand_impl_glReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void * pixels) {
    glad_glReadPixels = (PFNGLREADPIXELSPROC) glad_gl_on_demand_loader("glReadPixels");
    glad_glReadPixels(x, y, width, height, format, type, pixels);
}
PFNGLREADPIXELSPROC glad_glReadPixels = glad_on_demand_impl_glReadPixels;
static void GLAD_API_PTR glad_on_demand_impl_glRenderbufferStorage(GLenum target, GLenum internalformat, GLsizei width, GLsizei height) {
    glad_glRenderbufferStorage = (PFNGLRENDERBUFFERSTORAGEPROC) glad_gl_on_demand_loader("glRenderbufferStorage");
    glad_glRenderbufferStorage(target, internalformat, width, height);
}
PFNGLRENDERBUFFERSTORAGEPROC glad_glRenderbufferStorage = glad_on_demand_impl_glRenderbufferStorage;
static void GLAD_API_PTR glad_on_demand_impl_glRenderbufferStorageMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height) {
    glad_glRenderbufferStorageMultisample = (PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC) glad_gl_on_demand_loader("glRenderbufferStorageMultisample");
    glad_glRenderbufferStorageMultisample(target, samples, internalformat, width, height);
}
PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC glad_glRenderbufferStorageMultisample = glad_on_demand_impl_glRenderbufferStorageMultisample;
static void GLAD_API_PTR glad_on_demand_impl_glSampleCoverage(GLfloat value, GLboolean invert) {
    glad_glSampleCoverage = (PFNGLSAMPLECOVERAGEPROC) glad_gl_on_demand_loader("glSampleCoverage");
    glad_glSampleCoverage(value, invert);
}
PFNGLSAMPLECOVERAGEPROC glad_glSampleCoverage = glad_on_demand_impl_glSampleCoverage;
static void GLAD_API_PTR glad_on_demand_impl_glSampleMaski(GLuint maskNumber, GLbitfield mask) {
    glad_glSampleMaski = (PFNGLSAMPLEMASKIPROC) glad_gl_on_demand_loader("glSampleMaski");
    glad_glSampleMaski(maskNumber, mask);
}
PFNGLSAMPLEMASKIPROC glad_glSampleMaski = glad_on_demand_impl_glSampleMaski;
static void GLAD_API_PTR glad_on_demand_impl_glSamplerParameterIiv(GLuint sampler, GLenum pname, const GLint * param) {
    glad_glSamplerParameterIiv = (PFNGLSAMPLERPARAMETERIIVPROC) glad_gl_on_demand_loader("glSamplerParameterIiv");
    glad_glSamplerParameterIiv(sampler, pname, param);
}
PFNGLSAMPLERPARAMETERIIVPROC glad_glSamplerParameterIiv = glad_on_demand_impl_glSamplerParameterIiv;
static void GLAD_API_PTR glad_on_demand_impl_glSamplerParameterIuiv(GLuint sampler, GLenum pname, const GLuint * param) {
    glad_glSamplerParameterIuiv = (PFNGLSAMPLERPARAMETERIUIVPROC) glad_gl_on_demand_loader("glSamplerParameterIuiv");
    glad_glSamplerParameterIuiv(sampler, pname, param);
}
PFNGLSAMPLERPARAMETERIUIVPROC glad_glSamplerParameterIuiv = glad_on_demand_impl_glSamplerParameterIuiv;
static void GLAD_API_PTR glad_on_demand_impl_glSamplerParameterf(GLuint sampler, GLenum pname, GLfloat param) {
    glad_glSamplerParameterf = (PFNGLSAMPLERPARAMETERFPROC) glad_gl_on_demand_loader("glSamplerParameterf");
    glad_glSamplerParameterf(sampler, pname, param);
}
PFNGLSAMPLERPARAMETERFPROC glad_glSamplerParameterf = glad_on_demand_impl_glSamplerParameterf;
static void GLAD_API_PTR glad_on_demand_impl_glSamplerParameterfv(GLuint sampler, GLenum pname, const GLfloat * param) {
    glad_glSamplerParameterfv = (PFNGLSAMPLERPARAMETERFVPROC) glad_gl_on_demand_loader("glSamplerParameterfv");
    glad_glSamplerParameterfv(sampler, pname, param);
}
PFNGLSAMPLERPARAMETERFVPROC glad_glSamplerParameterfv = glad_on_demand_impl_glSamplerParameterfv;
static void GLAD_API_PTR glad_on_demand_impl_glSamplerParameteri(GLuint sampler, GLenum pname, GLint param) {
    glad_glSamplerParameteri = (PFNGLSAMPLERPARAMETERIPROC) glad_gl_on_demand_loader("glSamplerParameteri");
    glad_glSamplerParameteri(sampler, pname, param);
}
PFNGLSAMPLERPARAMETERIPROC glad_glSamplerParameteri = glad_on_demand_impl_glSamplerParameteri;
static void GLAD_API_PTR glad_on_demand_impl_glSamplerParameteriv(GLuint sampler, GLenum pname, const GLint * param) {
    glad_glSamplerParameteriv = (PFNGLSAMPLERPARAMETERIVPROC) glad_gl_on_demand_loader("glSamplerParameteriv");
    glad_glSamplerParameteriv(sampler, pname, param);
}
PFNGLSAMPLERPARAMETERIVPROC glad_glSamplerParameteriv = glad_on_demand_impl_glSamplerParameteriv;
static void GLAD_API_PTR glad_on_demand_impl_glScissor(GLint x, GLint y, GLsizei width, GLsizei height) {
    glad_glScissor = (PFNGLSCISSORPROC) glad_gl_on_demand_loader("glScissor");
    glad_glScissor(x, y, width, height);
}
PFNGLSCISSORPROC glad_glScissor = glad_on_demand_impl_glScissor;
static void GLAD_API_PTR glad_on_demand_impl_glShaderSource(GLuint shader, GLsizei count, const GLchar *const* string, const GLint * length) {
    glad_glShaderSource = (PFNGLSHADERSOURCEPROC) glad_gl_on_demand_loader("glShaderSource");
    glad_glShaderSource(shader, count, string, length);
}
PFNGLSHADERSOURCEPROC glad_glShaderSource = glad_on_demand_impl_glShaderSource;
static void GLAD_API_PTR glad_on_demand_impl_glStencilFunc(GLenum func, GLint ref, GLuint mask) {
    glad_glStencilFunc = (PFNGLSTENCILFUNCPROC) glad_gl_on_demand_loader("glStencilFunc");
    glad_glStencilFunc(func, ref, mask);
}
PFNGLSTENCILFUNCPROC glad_glStencilFunc = glad_on_demand_impl_glStencilFunc;
static void GLAD_API_PTR glad_on_demand_impl_glStencilFuncSeparate(GLenum face, GLenum func, GLint ref, GLuint mask) {
    glad_glStencilFuncSeparate = (PFNGLSTENCILFUNCSEPARATEPROC) glad_gl_on_demand_loader("glStencilFuncSeparate");
    glad_glStencilFuncSeparate(face, func, ref, mask);
}
PFNGLSTENCILFUNCSEPARATEPROC glad_glStencilFuncSeparate = glad_on_demand_impl_glStencilFuncSeparate;
static void GLAD_API_PTR glad_on_demand_impl_glStencilMask(GLuint mask) {
    glad_glStencilMask = (PFNGLSTENCILMASKPROC) glad_gl_on_demand_loader("glStencilMask");
    glad_glStencilMask(mask);
}
PFNGLSTENCILMASKPROC glad_glStencilMask = glad_on_demand_impl_glStencilMask;
static void GLAD_API_PTR glad_on_demand_impl_glStencilMaskSeparate(GLenum face, GLuint mask) {
    glad_glStencilMaskSeparate = (PFNGLSTENCILMASKSEPARATEPROC) glad_gl_on_demand_loader("glStencilMaskSeparate");
    glad_glStencilMaskSeparate(face, mask);
}
PFNGLSTENCILMASKSEPARATEPROC glad_glStencilMaskSeparate = glad_on_demand_impl_glStencilMaskSeparate;
static void GLAD_API_PTR glad_on_demand_impl_glStencilOp(GLenum fail, GLenum zfail, GLenum zpass) {
    glad_glStencilOp = (PFNGLSTENCILOPPROC) glad_gl_on_demand_loader("glStencilOp");
    glad_glStencilOp(fail, zfail, zpass);
}
PFNGLSTENCILOPPROC glad_glStencilOp = glad_on_demand_impl_glStencilOp;
static void GLAD_API_PTR glad_on_demand_impl_glStencilOpSeparate(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass) {
    glad_glStencilOpSeparate = (PFNGLSTENCILOPSEPARATEPROC) glad_gl_on_demand_loader("glStencilOpSeparate");
    glad_glStencilOpSeparate(face, sfail, dpfail, dppass);
}
PFNGLSTENCILOPSEPARATEPROC glad_glStencilOpSeparate = glad_on_demand_impl_glStencilOpSeparate;
static void GLAD_API_PTR glad_on_demand_impl_glTexBuffer(GLenum target, GLenum internalformat, GLuint buffer) {
    glad_glTexBuffer = (PFNGLTEXBUFFERPROC) glad_gl_on_demand_loader("glTexBuffer");
    glad_glTexBuffer(target, internalformat, buffer);
}
PFNGLTEXBUFFERPROC glad_glTexBuffer = glad_on_demand_impl_glTexBuffer;
static void GLAD_API_PTR glad_on_demand_impl_glTexImage1D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void * pixels) {
    glad_glTexImage1D = (PFNGLTEXIMAGE1DPROC) glad_gl_on_demand_loader("glTexImage1D");
    glad_glTexImage1D(target, level, internalformat, width, border, format, type, pixels);
}
PFNGLTEXIMAGE1DPROC glad_glTexImage1D = glad_on_demand_impl_glTexImage1D;
static void GLAD_API_PTR glad_on_demand_impl_glTexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void * pixels) {
    glad_glTexImage2D = (PFNGLTEXIMAGE2DPROC) glad_gl_on_demand_loader("glTexImage2D");
    glad_glTexImage2D(target, level, internalformat, width, height, border, format, type, pixels);
}
PFNGLTEXIMAGE2DPROC glad_glTexImage2D = glad_on_demand_impl_glTexImage2D;
static void GLAD_API_PTR glad_on_demand_impl_glTexImage2DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations) {
    glad_glTexImage2DMultisample = (PFNGLTEXIMAGE2DMULTISAMPLEPROC) glad_gl_on_demand_loader("glTexImage2DMultisample");
    glad_glTexImage2DMultisample(target, samples, internalformat, width, height, fixedsamplelocations);
}
PFNGLTEXIMAGE2DMULTISAMPLEPROC glad_glTexImage2DMultisample = glad_on_demand_impl_glTexImage2DMultisample;
static void GLAD_API_PTR glad_on_demand_impl_glTexImage3D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void * pixels) {
    glad_glTexImage3D = (PFNGLTEXIMAGE3DPROC) glad_gl_on_demand_loader("glTexImage3D");
    glad_glTexImage3D(target, level, internalformat, width, height, depth, border, format, type, pixels);
}
PFNGLTEXIMAGE3DPROC glad_glTexImage3D = glad_on_demand_impl_glTexImage3D;
static void GLAD_API_PTR glad_on_demand_impl_glTexImage3DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations) {
    glad_glTexImage3DMultisample = (PFNGLTEXIMAGE3DMULTISAMPLEPROC) glad_gl_on_demand_loader("glTexImage3DMultisample");
    glad_glTexImage3DMultisample(target, samples, internalformat, width, height, depth, fixedsamplelocations);
}
PFNGLTEXIMAGE3DMULTISAMPLEPROC glad_glTexImage3DMultisample = glad_on_demand_impl_glTexImage3DMultisample;
static void GLAD_API_PTR glad_on_demand_impl_glTexParameterIiv(GLenum target, GLenum pname, const GLint * params) {
    glad_glTexParameterIiv = (PFNGLTEXPARAMETERIIVPROC) glad_gl_on_demand_loader("glTexParameterIiv");
    glad_glTexParameterIiv(target, pname, params);
}
PFNGLTEXPARAMETERIIVPROC glad_glTexParameterIiv = glad_on_demand_impl_glTexParameterIiv;
static void GLAD_API_PTR glad_on_demand_impl_glTexParameterIuiv(GLenum target, GLenum pname, const GLuint * params) {
    glad_glTexParameterIuiv = (PFNGLTEXPARAMETERIUIVPROC) glad_gl_on_demand_loader("glTexParameterIuiv");
    glad_glTexParameterIuiv(target, pname, params);
}
PFNGLTEXPARAMETERIUIVPROC glad_glTexParameterIuiv = glad_on_demand_impl_glTexParameterIuiv;
static void GLAD_API_PTR glad_on_demand_impl_glTexParameterf(GLenum target, GLenum pname, GLfloat param) {
    glad_glTexParameterf = (PFNGLTEXPARAMETERFPROC) glad_gl_on_demand_loader("glTexParameterf");
    glad_glTexParameterf(target, pname, param);
}
PFNGLTEXPARAMETERFPROC glad_glTexParameterf = glad_on_demand_impl_glTexParameterf;
static void GLAD_API_PTR glad_on_demand_impl_glTexParameterfv(GLenum target, GLenum pname, const GLfloat * params) {
    glad_glTexParameterfv = (PFNGLTEXPARAMETERFVPROC) glad_gl_on_demand_loader("glTexParameterfv");
    glad_glTexParameterfv(target, pname, params);
}
PFNGLTEXPARAMETERFVPROC glad_glTexParameterfv = glad_on_demand_impl_glTexParameterfv;
static void GLAD_API_PTR glad_on_demand_impl_glTexParameteri(GLenum target, GLenum pname, GLint param) {
    glad_glTexParameteri = (PFNGLTEXPARAMETERIPROC) glad_gl_on_demand_loader("glTexParameteri");
    glad_glTexParameteri(target, pname, param);
}
PFNGLTEXPARAMETERIPROC glad_glTexParameteri = glad_on_demand_impl_glTexParameteri;
static void GLAD_API_PTR glad_on_demand_impl_glTexParameteriv(GLenum target, GLenum pname, const GLint * params) {
    glad_glTexParameteriv = (PFNGLTEXPARAMETERIVPROC) glad_gl_on_demand_loader("glTexParameteriv");
    glad_glTexParameteriv(target, pname, params);
}
PFNGLTEXPARAMETERIVPROC glad_glTexParameteriv = glad_on_demand_impl_glTexParameteriv;
static void GLAD_API_PTR glad_on_demand_impl_glTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void * pixels) {
    glad_glTexSubImage1D = (PFNGLTEXSUBIMAGE1DPROC) glad_gl_on_demand_loader("glTexSubImage1D");
    glad_glTexSubImage1D(target, level, xoffset, width, format, type, pixels);
}
PFNGLTEXSUBIMAGE1DPROC glad_glTexSubImage1D = glad_on_demand_impl_glTexSubImage1D;
static void GLAD_API_PTR glad_on_demand_impl_glTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void * pixels) {
    glad_glTexSubImage2D = (PFNGLTEXSUBIMAGE2DPROC) glad_gl_on_demand_loader("glTexSubImage2D");
    glad_glTexSubImage2D(target, level, xoffset, yoffset, width, height, format, type, pixels);
}
PFNGLTEXSUBIMAGE2DPROC glad_glTexSubImage2D = glad_on_demand_impl_glTexSubImage2D;
static void GLAD_API_PTR glad_on_demand_impl_glTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void * pixels) {
    glad_glTexSubImage3D = (PFNGLTEXSUBIMAGE3DPROC) glad_gl_on_demand_loader("glTexSubImage3D");
    glad_glTexSubImage3D(target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels);
}
PFNGLTEXSUBIMAGE3DPROC glad_glTexSubImage3D = glad_on_demand_impl_glTexSubImage3D;
static void GLAD_API_PTR glad_on_demand_impl_glTransformFeedbackVaryings(GLuint program, GLsizei count, const GLchar *const* varyings, GLenum bufferMode) {
    glad_glTransformFeedbackVaryings = (PFNGLTRANSFORMFEEDBACKVARYINGSPROC) glad_gl_on_demand_loader("glTransformFeedbackVaryings");
    glad_glTransformFeedbackVaryings(program, count, varyings, bufferMode);
}
PFNGLTRANSFORMFEEDBACKVARYINGSPROC glad_glTransformFeedbackVaryings = glad_on_demand_impl_glTransformFeedbackVaryings;
static void GLAD_API_PTR glad_on_demand_impl_glUniform1f(GLint location, GLfloat v0) {
    glad_glUniform1f = (PFNGLUNIFORM1FPROC) glad_gl_on_demand_loader("glUniform1f");
    glad_glUniform1f(location, v0);
}
PFNGLUNIFORM1FPROC glad_glUniform1f = glad_on_demand_impl_glUniform1f;
static void GLAD_API_PTR glad_on_demand_impl_glUniform1fv(GLint location, GLsizei count, const GLfloat * value) {
    glad_glUniform1fv = (PFNGLUNIFORM1FVPROC) glad_gl_on_demand_loader("glUniform1fv");
    glad_glUniform1fv(location, count, value);
}
PFNGLUNIFORM1FVPROC glad_glUniform1fv = glad_on_demand_impl_glUniform1fv;
static void GLAD_API_PTR glad_on_demand_impl_glUniform1i(GLint location, GLint v0) {
    glad_glUniform1i = (PFNGLUNIFORM1IPROC) glad_gl_on_demand_loader("glUniform1i");
    glad_glUniform1i(location, v0);
}
PFNGLUNIFORM1IPROC glad_glUniform1i = glad_on_demand_impl_glUniform1i;
static void GLAD_API_PTR glad_on_demand_impl_glUniform1iv(GLint location, GLsizei count, const GLint * value) {
    glad_glUniform1iv = (PFNGLUNIFORM1IVPROC) glad_gl_on_demand_loader("glUniform1iv");
    glad_glUniform1iv(location, count, value);
}
PFNGLUNIFORM1IVPROC glad_glUniform1iv = glad_on_demand_impl_glUniform1iv;
static void GLAD_API_PTR glad_on_demand_impl_glUniform1ui(GLint location, GLuint v0) {
    glad_glUniform1ui = (PFNGLUNIFORM1UIPROC) glad_gl_on_demand_loader("glUniform1ui");
    glad_glUniform1ui(location, v0);
}
PFNGLUNIFORM1UIPROC glad_glUniform1ui = glad_on_demand_impl_glUniform1ui;
static void GLAD_API_PTR glad_on_demand_impl_glUniform1uiv(GLint location, GLsizei count, const GLuint * value) {
    glad_glUniform1uiv = (PFNGLUNIFORM1UIVPROC) glad_gl_on_demand_loader("glUniform1uiv");
    glad_glUniform1uiv(location, count, value);
}
PFNGLUNIFORM1UIVPROC glad_glUniform1uiv = glad_on_demand_impl_glUniform1uiv;
static void GLAD_API_PTR glad_on_demand_impl_glUniform2f(GLint location, GLfloat v0, GLfloat v1) {
    glad_glUniform2f = (PFNGLUNIFORM2FPROC) glad_gl_on_demand_loader("glUniform2f");
    glad_glUniform2f(location, v0, v1);
}
PFNGLUNIFORM2FPROC glad_glUniform2f = glad_on_demand_impl_glUniform2f;
static void GLAD_API_PTR glad_on_demand_impl_glUniform2fv(GLint location, GLsizei count, const GLfloat * value) {
    glad_glUniform2fv = (PFNGLUNIFORM2FVPROC) glad_gl_on_demand_loader("glUniform2fv");
    glad_glUniform2fv(location, count, value);
}
PFNGLUNIFORM2FVPROC glad_glUniform2fv = glad_on_demand_impl_glUniform2fv;
static void GLAD_API_PTR glad_on_demand_impl_glUniform2i(GLint location, GLint v0, GLint v1) {
    glad_glUniform2i = (PFNGLUNIFORM2IPROC) glad_gl_on_demand_loader("glUniform2i");
    glad_glUniform2i(location, v0, v1);
}
PFNGLUNIFORM2IPROC glad_glUniform2i = glad_on_demand_impl_glUniform2i;
static void GLAD_API_PTR glad_on_demand_impl_glUniform2iv(GLint location, GLsizei count, const GLint * value) {
    glad_glUniform2iv = (PFNGLUNIFORM2IVPROC) glad_gl_on_demand_loader("glUniform2iv");
    glad_glUniform2iv(location, count, value);
}
PFNGLUNIFORM2IVPROC glad_glUniform2iv = glad_on_demand_impl_glUniform2iv;
static void GLAD_API_PTR glad_on_demand_impl_glUniform2ui(GLint location, GLuint v0, GLuint v1) {
    glad_glUniform2ui = (PFNGLUNIFORM2UIPROC) glad_gl_on_demand_loader("glUniform2ui");
    glad_glUniform2ui(location, v0, v1);
}
PFNGLUNIFORM2UIPROC glad_glUniform2ui = glad_on_demand_impl_glUniform2ui;
static void GLAD_API_PTR glad_on_demand_impl_glUniform2uiv(GLint location, GLsizei count, const GLuint * value) {
    glad_glUniform2uiv = (PFNGLUNIFORM2UIVPROC) glad_gl_on_demand_loader("glUniform2uiv");
    glad_glUniform2uiv(location, count, value);
}
PFNGLUNIFORM2UIVPROC glad_glUniform2uiv = glad_on_demand_impl_glUniform2uiv;
static void GLAD_API_PTR glad_on_demand_impl_glUniform3f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2) {
    glad_glUniform3f = (PFNGLUNIFORM3FPROC) glad_gl_on_demand_loader("glUniform3f");
    glad_glUniform3f(location, v0, v1, v2);
}
PFNGLUNIFORM3FPROC glad_glUniform3f = glad_on_demand_impl_glUniform3f;
static void GLAD_API_PTR glad_on_demand_impl_glUniform3fv(GLint location, GLsizei count, const GLfloat * value) {
    glad_glUniform3fv = (PFNGLUNIFORM3FVPROC) glad_gl_on_demand_loader("glUniform3fv");
    glad_glUniform3fv(location, count, value);
}
PFNGLUNIFORM3FVPROC glad_glUniform3fv = glad_on_demand_impl_glUniform3fv;
static void GLAD_API_PTR glad_on_demand_impl_glUniform3i(GLint location, GLint v0, GLint v1, GLint v2) {
    glad_glUniform3i = (PFNGLUNIFORM3IPROC) glad_gl_on_demand_loader("glUniform3i");
    glad_glUniform3i(location, v0, v1, v2);
}
PFNGLUNIFORM3IPROC glad_glUniform3i = glad_on_demand_impl_glUniform3i;
static void GLAD_API_PTR glad_on_demand_impl_glUniform3iv(GLint location, GLsizei count, const GLint * value) {
    glad_glUniform3iv = (PFNGLUNIFORM3IVPROC) glad_gl_on_demand_loader("glUniform3iv");
    glad_glUniform3iv(location, count, value);
}
PFNGLUNIFORM3IVPROC glad_glUniform3iv = glad_on_demand_impl_glUniform3iv;
static void GLAD_API_PTR glad_on_demand_impl_glUniform3ui(GLint location, GLuint v0, GLuint v1, GLuint v2) {
    glad_glUniform3ui = (PFNGLUNIFORM3UIPROC) glad_gl_on_demand_loader("glUniform3ui");
    glad_glUniform3ui(location, v0, v1, v2);
}
PFNGLUNIFORM3UIPROC glad_glUniform3ui = glad_on_demand_impl_glUniform3ui;
static void GLAD_API_PTR glad_on_demand_impl_glUniform3uiv(GLint location, GLsizei count, const GLuint * value) {
    glad_glUniform3uiv = (PFNGLUNIFORM3UIVPROC) glad_gl_on_demand_loader("glUniform3uiv");
    glad_glUniform3uiv(location, count, value);
}
PFNGLUNIFORM3UIVPROC glad_glUniform3uiv = glad_on_demand_impl_glUniform3uiv;
static void GLAD_API_PTR glad_on_demand_impl_glUniform4f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) {
    glad_glUniform4f = (PFNGLUNIFORM4FPROC) glad_gl_on_demand_loader("glUniform4f");
    glad_glUniform4f(location, v0, v1, v2, v3);
}
PFNGLUNIFORM4FPROC glad_glUniform4f = glad_on_demand_impl_glUniform4f;
static void GLAD_API_PTR glad_on_demand_impl_glUniform4fv(GLint location, GLsizei count, const GLfloat * value) {
    glad_glUniform4fv = (PFNGLUNIFORM4FVPROC) glad_gl_on_demand_loader("glUniform4fv");
    glad_glUniform4fv(location, count, value);
}
PFNGLUNIFORM4FVPROC glad_glUniform4fv = glad_on_demand_impl_glUniform4fv;
static void GLAD_API_PTR glad_on_demand_impl_glUniform4i(GLint location, GLint v0, GLint v1, GLint v2, GLint v3) {
    glad_glUniform4i = (PFNGLUNIFORM4IPROC) glad_gl_on_demand_loader("glUniform4i");
    glad_glUniform4i(location, v0, v1, v2, v3);
}
PFNGLUNIFORM4IPROC glad_glUniform4i = glad_on_demand_impl_glUniform4i;
static void GLAD_API_PTR glad_on_demand_impl_glUniform4iv(GLint location, GLsizei count, const GLint * value) {
    glad_glUniform4iv = (PFNGLUNIFORM4IVPROC) glad_gl_on_demand_loader("glUniform4iv");
    glad_glUniform4iv(location, count, value);
}
PFNGLUNIFORM4IVPROC glad_glUniform4iv = glad_on_demand_impl_glUniform4iv;
static void GLAD_API_PTR glad_on_demand_impl_glUniform4ui(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3) {
    glad_glUniform4ui = (PFNGLUNIFORM4UIPROC) glad_gl_on_demand_loader("glUniform4ui");
    glad_glUniform4ui(location, v0, v1, v2, v3);
}
PFNGLUNIFORM4UIPROC glad_glUniform4ui = glad_on_demand_impl_glUniform4ui;
static void GLAD_API_PTR glad_on_demand_impl_glUniform4uiv(GLint location, GLsizei count, const GLuint * value) {
    glad_glUniform4uiv = (PFNGLUNIFORM4UIVPROC) glad_gl_on_demand_loader("glUniform4uiv");
    glad_glUniform4uiv(location, count, value);
}
PFNGLUNIFORM4UIVPROC glad_glUniform4uiv = glad_on_demand_impl_glUniform4uiv;
static void GLAD_API_PTR glad_on_demand_impl_glUniformBlockBinding(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding) {
    glad_glUniformBlockBinding = (PFNGLUNIFORMBLOCKBINDINGPROC) glad_gl_on_demand_loader("glUniformBlockBinding");
    glad_glUniformBlockBinding(program, uniformBlockIndex, uniformBlockBinding);
}
PFNGLUNIFORMBLOCKBINDINGPROC glad_glUniformBlockBinding = glad_on_demand_impl_glUniformBlockBinding;
static void GLAD_API_PTR glad_on_demand_impl_glUniformMatrix2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) {
    glad_glUniformMatrix2fv = (PFNGLUNIFORMMATRIX2FVPROC) glad_gl_on_demand_loader("glUniformMatrix2fv");
    glad_glUniformMatrix2fv(location, count, transpose, value);
}
PFNGLUNIFORMMATRIX2FVPROC glad_glUniformMatrix2fv = glad_on_demand_impl_glUniformMatrix2fv;
static void GLAD_API_PTR glad_on_demand_impl_glUniformMatrix2x3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) {
    glad_glUniformMatrix2x3fv = (PFNGLUNIFORMMATRIX2X3FVPROC) glad_gl_on_demand_loader("glUniformMatrix2x3fv");
    glad_glUniformMatrix2x3fv(location, count, transpose, value);
}
PFNGLUNIFORMMATRIX2X3FVPROC glad_glUniformMatrix2x3fv = glad_on_demand_impl_glUniformMatrix2x3fv;
static void GLAD_API_PTR glad_on_demand_impl_glUniformMatrix2x4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) {
    glad_glUniformMatrix2x4fv = (PFNGLUNIFORMMATRIX2X4FVPROC) glad_gl_on_demand_loader("glUniformMatrix2x4fv");
    glad_glUniformMatrix2x4fv(location, count, transpose, value);
}
PFNGLUNIFORMMATRIX2X4FVPROC glad_glUniformMatrix2x4fv = glad_on_demand_impl_glUniformMatrix2x4fv;
static void GLAD_API_PTR glad_on_demand_impl_glUniformMatrix3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) {
    glad_glUniformMatrix3fv = (PFNGLUNIFORMMATRIX3FVPROC) glad_gl_on_demand_loader("glUniformMatrix3fv");
    glad_glUniformMatrix3fv(location, count, transpose, value);
}
PFNGLUNIFORMMATRIX3FVPROC glad_glUniformMatrix3fv = glad_on_demand_impl_glUniformMatrix3fv;
static void GLAD_API_PTR glad_on_demand_impl_glUniformMatrix3x2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) {
    glad_glUniformMatrix3x2fv = (PFNGLUNIFORMMATRIX3X2FVPROC) glad_gl_on_demand_loader("glUniformMatrix3x2fv");
    glad_glUniformMatrix3x2fv(location, count, transpose, value);
}
PFNGLUNIFORMMATRIX3X2FVPROC glad_glUniformMatrix3x2fv = glad_on_demand_impl_glUniformMatrix3x2fv;
static void GLAD_API_PTR glad_on_demand_impl_glUniformMatrix3x4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) {
    glad_glUniformMatrix3x4fv = (PFNGLUNIFORMMATRIX3X4FVPROC) glad_gl_on_demand_loader("glUniformMatrix3x4fv");
    glad_glUniformMatrix3x4fv(location, count, transpose, value);
}
PFNGLUNIFORMMATRIX3X4FVPROC glad_glUniformMatrix3x4fv = glad_on_demand_impl_glUniformMatrix3x4fv;
static void GLAD_API_PTR glad_on_demand_impl_glUniformMatrix4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) {
    glad_glUniformMatrix4fv = (PFNGLUNIFORMMATRIX4FVPROC) glad_gl_on_demand_loader("glUniformMatrix4fv");
    glad_glUniformMatrix4fv(location, count, transpose, value);
}
PFNGLUNIFORMMATRIX4FVPROC glad_glUniformMatrix4fv = glad_on_demand_impl_glUniformMatrix4fv;
static void GLAD_API_PTR glad_on_demand_impl_glUniformMatrix4x2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) {
    glad_glUniformMatrix4x2fv = (PFNGLUNIFORMMATRIX4X2FVPROC) glad_gl_on_demand_loader("glUniformMatrix4x2fv");
    glad_glUniformMatrix4x2fv(location, count, transpose, value);
}
PFNGLUNIFORMMATRIX4X2FVPROC glad_glUniformMatrix4x2fv = glad_on_demand_impl_glUniformMatrix4x2fv;
static void GLAD_API_PTR glad_on_demand_impl_glUniformMatrix4x3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) {
    glad_glUniformMatrix4x3fv = (PFNGLUNIFORMMATRIX4X3FVPROC) glad_gl_on_demand_loader("glUniformMatrix4x3fv");
    glad_glUniformMatrix4x3fv(location, count, transpose, value);
}
PFNGLUNIFORMMATRIX4X3FVPROC glad_glUniformMatrix4x3fv = glad_on_demand_impl_glUniformMatrix4x3fv;
static GLboolean GLAD_API_PTR glad_on_demand_impl_glUnmapBuffer(GLenum target) {
    glad_glUnmapBuffer = (PFNGLUNMAPBUFFERPROC) glad_gl_on_demand_loader("glUnmapBuffer");
    return glad_glUnmapBuffer(target);
}
PFNGLUNMAPBUFFERPROC glad_glUnmapBuffer = glad_on_demand_impl_glUnmapBuffer;
static void GLAD_API_PTR glad_on_demand_impl_glUseProgram(GLuint program) {
    glad_glUseProgram = (PFNGLUSEPROGRAMPROC) glad_gl_on_demand_loader("glUseProgram");
    glad_glUseProgram(program);
}
PFNGLUSEPROGRAMPROC glad_glUseProgram = glad_on_demand_impl_glUseProgram;
static void GLAD_API_PTR glad_on_demand_impl_glValidateProgram(GLuint program) {
    glad_glValidateProgram = (PFNGLVALIDATEPROGRAMPROC) glad_gl_on_demand_loader("glValidateProgram");
    glad_glValidateProgram(program);
}
PFNGLVALIDATEPROGRAMPROC glad_glValidateProgram = glad_on_demand_impl_glValidateProgram;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttrib1d(GLuint index, GLdouble x) {
    glad_glVertexAttrib1d = (PFNGLVERTEXATTRIB1DPROC) glad_gl_on_demand_loader("glVertexAttrib1d");
    glad_glVertexAttrib1d(index, x);
}
PFNGLVERTEXATTRIB1DPROC glad_glVertexAttrib1d = glad_on_demand_impl_glVertexAttrib1d;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttrib1dv(GLuint index, const GLdouble * v) {
    glad_glVertexAttrib1dv = (PFNGLVERTEXATTRIB1DVPROC) glad_gl_on_demand_loader("glVertexAttrib1dv");
    glad_glVertexAttrib1dv(index, v);
}
PFNGLVERTEXATTRIB1DVPROC glad_glVertexAttrib1dv = glad_on_demand_impl_glVertexAttrib1dv;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttrib1f(GLuint index, GLfloat x) {
    glad_glVertexAttrib1f = (PFNGLVERTEXATTRIB1FPROC) glad_gl_on_demand_loader("glVertexAttrib1f");
    glad_glVertexAttrib1f(index, x);
}
PFNGLVERTEXATTRIB1FPROC glad_glVertexAttrib1f = glad_on_demand_impl_glVertexAttrib1f;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttrib1fv(GLuint index, const GLfloat * v) {
    glad_glVertexAttrib1fv = (PFNGLVERTEXATTRIB1FVPROC) glad_gl_on_demand_loader("glVertexAttrib1fv");
    glad_glVertexAttrib1fv(index, v);
}
PFNGLVERTEXATTRIB1FVPROC glad_glVertexAttrib1fv = glad_on_demand_impl_glVertexAttrib1fv;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttrib1s(GLuint index, GLshort x) {
    glad_glVertexAttrib1s = (PFNGLVERTEXATTRIB1SPROC) glad_gl_on_demand_loader("glVertexAttrib1s");
    glad_glVertexAttrib1s(index, x);
}
PFNGLVERTEXATTRIB1SPROC glad_glVertexAttrib1s = glad_on_demand_impl_glVertexAttrib1s;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttrib1sv(GLuint index, const GLshort * v) {
    glad_glVertexAttrib1sv = (PFNGLVERTEXATTRIB1SVPROC) glad_gl_on_demand_loader("glVertexAttrib1sv");
    glad_glVertexAttrib1sv(index, v);
}
PFNGLVERTEXATTRIB1SVPROC glad_glVertexAttrib1sv = glad_on_demand_impl_glVertexAttrib1sv;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttrib2d(GLuint index, GLdouble x, GLdouble y) {
    glad_glVertexAttrib2d = (PFNGLVERTEXATTRIB2DPROC) glad_gl_on_demand_loader("glVertexAttrib2d");
    glad_glVertexAttrib2d(index, x, y);
}
PFNGLVERTEXATTRIB2DPROC glad_glVertexAttrib2d = glad_on_demand_impl_glVertexAttrib2d;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttrib2dv(GLuint index, const GLdouble * v) {
    glad_glVertexAttrib2dv = (PFNGLVERTEXATTRIB2DVPROC) glad_gl_on_demand_loader("glVertexAttrib2dv");
    glad_glVertexAttrib2dv(index, v);
}
PFNGLVERTEXATTRIB2DVPROC glad_glVertexAttrib2dv = glad_on_demand_impl_glVertexAttrib2dv;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttrib2f(GLuint index, GLfloat x, GLfloat y) {
    glad_glVertexAttrib2f = (PFNGLVERTEXATTRIB2FPROC) glad_gl_on_demand_loader("glVertexAttrib2f");
    glad_glVertexAttrib2f(index, x, y);
}
PFNGLVERTEXATTRIB2FPROC glad_glVertexAttrib2f = glad_on_demand_impl_glVertexAttrib2f;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttrib2fv(GLuint index, const GLfloat * v) {
    glad_glVertexAttrib2fv = (PFNGLVERTEXATTRIB2FVPROC) glad_gl_on_demand_loader("glVertexAttrib2fv");
    glad_glVertexAttrib2fv(index, v);
}
PFNGLVERTEXATTRIB2FVPROC glad_glVertexAttrib2fv = glad_on_demand_impl_glVertexAttrib2fv;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttrib2s(GLuint index, GLshort x, GLshort y) {
    glad_glVertexAttrib2s = (PFNGLVERTEXATTRIB2SPROC) glad_gl_on_demand_loader("glVertexAttrib2s");
    glad_glVertexAttrib2s(index, x, y);
}
PFNGLVERTEXATTRIB2SPROC glad_glVertexAttrib2s = glad_on_demand_impl_glVertexAttrib2s;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttrib2sv(GLuint index, const GLshort * v) {
    glad_glVertexAttrib2sv = (PFNGLVERTEXATTRIB2SVPROC) glad_gl_on_demand_loader("glVertexAttrib2sv");
    glad_glVertexAttrib2sv(index, v);
}
PFNGLVERTEXATTRIB2SVPROC glad_glVertexAttrib2sv = glad_on_demand_impl_glVertexAttrib2sv;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttrib3d(GLuint index, GLdouble x, GLdouble y, GLdouble z) {
    glad_glVertexAttrib3d = (PFNGLVERTEXATTRIB3DPROC) glad_gl_on_demand_loader("glVertexAttrib3d");
    glad_glVertexAttrib3d(index, x, y, z);
}
PFNGLVERTEXATTRIB3DPROC glad_glVertexAttrib3d = glad_on_demand_impl_glVertexAttrib3d;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttrib3dv(GLuint index, const GLdouble * v) {
    glad_glVertexAttrib3dv = (PFNGLVERTEXATTRIB3DVPROC) glad_gl_on_demand_loader("glVertexAttrib3dv");
    glad_glVertexAttrib3dv(index, v);
}
PFNGLVERTEXATTRIB3DVPROC glad_glVertexAttrib3dv = glad_on_demand_impl_glVertexAttrib3dv;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttrib3f(GLuint index, GLfloat x, GLfloat y, GLfloat z) {
    glad_glVertexAttrib3f = (PFNGLVERTEXATTRIB3FPROC) glad_gl_on_demand_loader("glVertexAttrib3f");
    glad_glVertexAttrib3f(index, x, y, z);
}
PFNGLVERTEXATTRIB3FPROC glad_glVertexAttrib3f = glad_on_demand_impl_glVertexAttrib3f;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttrib3fv(GLuint index, const GLfloat * v) {
    glad_glVertexAttrib3fv = (PFNGLVERTEXATTRIB3FVPROC) glad_gl_on_demand_loader("glVertexAttrib3fv");
    glad_glVertexAttrib3fv(index, v);
}
PFNGLVERTEXATTRIB3FVPROC glad_glVertexAttrib3fv = glad_on_demand_impl_glVertexAttrib3fv;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttrib3s(GLuint index, GLshort x, GLshort y, GLshort z) {
    glad_glVertexAttrib3s = (PFNGLVERTEXATTRIB3SPROC) glad_gl_on_demand_loader("glVertexAttrib3s");
    glad_glVertexAttrib3s(index, x, y, z);
}
PFNGLVERTEXATTRIB3SPROC glad_glVertexAttrib3s = glad_on_demand_impl_glVertexAttrib3s;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttrib3sv(GLuint index, const GLshort * v) {
    glad_glVertexAttrib3sv = (PFNGLVERTEXATTRIB3SVPROC) glad_gl_on_demand_loader("glVertexAttrib3sv");
    glad_glVertexAttrib3sv(index, v);
}
PFNGLVERTEXATTRIB3SVPROC glad_glVertexAttrib3sv = glad_on_demand_impl_glVertexAttrib3sv;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttrib4Nbv(GLuint index, const GLbyte * v) {
    glad_glVertexAttrib4Nbv = (PFNGLVERTEXATTRIB4NBVPROC) glad_gl_on_demand_loader("glVertexAttrib4Nbv");
    glad_glVertexAttrib4Nbv(index, v);
}
PFNGLVERTEXATTRIB4NBVPROC glad_glVertexAttrib4Nbv = glad_on_demand_impl_glVertexAttrib4Nbv;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttrib4Niv(GLuint index, const GLint * v) {
    glad_glVertexAttrib4Niv = (PFNGLVERTEXATTRIB4NIVPROC) glad_gl_on_demand_loader("glVertexAttrib4Niv");
    glad_glVertexAttrib4Niv(index, v);
}
PFNGLVERTEXATTRIB4NIVPROC glad_glVertexAttrib4Niv = glad_on_demand_impl_glVertexAttrib4Niv;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttrib4Nsv(GLuint index, const GLshort * v) {
    glad_glVertexAttrib4Nsv = (PFNGLVERTEXATTRIB4NSVPROC) glad_gl_on_demand_loader("glVertexAttrib4Nsv");
    glad_glVertexAttrib4Nsv(index, v);
}
PFNGLVERTEXATTRIB4NSVPROC glad_glVertexAttrib4Nsv = glad_on_demand_impl_glVertexAttrib4Nsv;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttrib4Nub(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w) {
    glad_glVertexAttrib4Nub = (PFNGLVERTEXATTRIB4NUBPROC) glad_gl_on_demand_loader("glVertexAttrib4Nub");
    glad_glVertexAttrib4Nub(index, x, y, z, w);
}
PFNGLVERTEXATTRIB4NUBPROC glad_glVertexAttrib4Nub = glad_on_demand_impl_glVertexAttrib4Nub;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttrib4Nubv(GLuint index, const GLubyte * v) {
    glad_glVertexAttrib4Nubv = (PFNGLVERTEXATTRIB4NUBVPROC) glad_gl_on_demand_loader("glVertexAttrib4Nubv");
    glad_glVertexAttrib4Nubv(index, v);
}
PFNGLVERTEXATTRIB4NUBVPROC glad_glVertexAttrib4Nubv = glad_on_demand_impl_glVertexAttrib4Nubv;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttrib4Nuiv(GLuint index, const GLuint * v) {
    glad_glVertexAttrib4Nuiv = (PFNGLVERTEXATTRIB4NUIVPROC) glad_gl_on_demand_loader("glVertexAttrib4Nuiv");
    glad_glVertexAttrib4Nuiv(index, v);
}
PFNGLVERTEXATTRIB4NUIVPROC glad_glVertexAttrib4Nuiv = glad_on_demand_impl_glVertexAttrib4Nuiv;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttrib4Nusv(GLuint index, const GLushort * v) {
    glad_glVertexAttrib4Nusv = (PFNGLVERTEXATTRIB4NUSVPROC) glad_gl_on_demand_loader("glVertexAttrib4Nusv");
    glad_glVertexAttrib4Nusv(index, v);
}
PFNGLVERTEXATTRIB4NUSVPROC glad_glVertexAttrib4Nusv = glad_on_demand_impl_glVertexAttrib4Nusv;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttrib4bv(GLuint index, const GLbyte * v) {
    glad_glVertexAttrib4bv = (PFNGLVERTEXATTRIB4BVPROC) glad_gl_on_demand_loader("glVertexAttrib4bv");
    glad_glVertexAttrib4bv(index, v);
}
PFNGLVERTEXATTRIB4BVPROC glad_glVertexAttrib4bv = glad_on_demand_impl_glVertexAttrib4bv;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttrib4d(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
    glad_glVertexAttrib4d = (PFNGLVERTEXATTRIB4DPROC) glad_gl_on_demand_loader("glVertexAttrib4d");
    glad_glVertexAttrib4d(index, x, y, z, w);
}
PFNGLVERTEXATTRIB4DPROC glad_glVertexAttrib4d = glad_on_demand_impl_glVertexAttrib4d;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttrib4dv(GLuint index, const GLdouble * v) {
    glad_glVertexAttrib4dv = (PFNGLVERTEXATTRIB4DVPROC) glad_gl_on_demand_loader("glVertexAttrib4dv");
    glad_glVertexAttrib4dv(index, v);
}
PFNGLVERTEXATTRIB4DVPROC glad_glVertexAttrib4dv = glad_on_demand_impl_glVertexAttrib4dv;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttrib4f(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
    glad_glVertexAttrib4f = (PFNGLVERTEXATTRIB4FPROC) glad_gl_on_demand_loader("glVertexAttrib4f");
    glad_glVertexAttrib4f(index, x, y, z, w);
}
PFNGLVERTEXATTRIB4FPROC glad_glVertexAttrib4f = glad_on_demand_impl_glVertexAttrib4f;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttrib4fv(GLuint index, const GLfloat * v) {
    glad_glVertexAttrib4fv = (PFNGLVERTEXATTRIB4FVPROC) glad_gl_on_demand_loader("glVertexAttrib4fv");
    glad_glVertexAttrib4fv(index, v);
}
PFNGLVERTEXATTRIB4FVPROC glad_glVertexAttrib4fv = glad_on_demand_impl_glVertexAttrib4fv;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttrib4iv(GLuint index, const GLint * v) {
    glad_glVertexAttrib4iv = (PFNGLVERTEXATTRIB4IVPROC) glad_gl_on_demand_loader("glVertexAttrib4iv");
    glad_glVertexAttrib4iv(index, v);
}
PFNGLVERTEXATTRIB4IVPROC glad_glVertexAttrib4iv = glad_on_demand_impl_glVertexAttrib4iv;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttrib4s(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w) {
    glad_glVertexAttrib4s = (PFNGLVERTEXATTRIB4SPROC) glad_gl_on_demand_loader("glVertexAttrib4s");
    glad_glVertexAttrib4s(index, x, y, z, w);
}
PFNGLVERTEXATTRIB4SPROC glad_glVertexAttrib4s = glad_on_demand_impl_glVertexAttrib4s;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttrib4sv(GLuint index, const GLshort * v) {
    glad_glVertexAttrib4sv = (PFNGLVERTEXATTRIB4SVPROC) glad_gl_on_demand_loader("glVertexAttrib4sv");
    glad_glVertexAttrib4sv(index, v);
}
PFNGLVERTEXATTRIB4SVPROC glad_glVertexAttrib4sv = glad_on_demand_impl_glVertexAttrib4sv;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttrib4ubv(GLuint index, const GLubyte * v) {
    glad_glVertexAttrib4ubv = (PFNGLVERTEXATTRIB4UBVPROC) glad_gl_on_demand_loader("glVertexAttrib4ubv");
    glad_glVertexAttrib4ubv(index, v);
}
PFNGLVERTEXATTRIB4UBVPROC glad_glVertexAttrib4ubv = glad_on_demand_impl_glVertexAttrib4ubv;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttrib4uiv(GLuint index, const GLuint * v) {
    glad_glVertexAttrib4uiv = (PFNGLVERTEXATTRIB4UIVPROC) glad_gl_on_demand_loader("glVertexAttrib4uiv");
    glad_glVertexAttrib4uiv(index, v);
}
PFNGLVERTEXATTRIB4UIVPROC glad_glVertexAttrib4uiv = glad_on_demand_impl_glVertexAttrib4uiv;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttrib4usv(GLuint index, const GLushort * v) {
    glad_glVertexAttrib4usv = (PFNGLVERTEXATTRIB4USVPROC) glad_gl_on_demand_loader("glVertexAttrib4usv");
    glad_glVertexAttrib4usv(index, v);
}
PFNGLVERTEXATTRIB4USVPROC glad_glVertexAttrib4usv = glad_on_demand_impl_glVertexAttrib4usv;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttribDivisor(GLuint index, GLuint divisor) {
    glad_glVertexAttribDivisor = (PFNGLVERTEXATTRIBDIVISORPROC) glad_gl_on_demand_loader("glVertexAttribDivisor");
    glad_glVertexAttribDivisor(index, divisor);
}
PFNGLVERTEXATTRIBDIVISORPROC glad_glVertexAttribDivisor = glad_on_demand_impl_glVertexAttribDivisor;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttribI1i(GLuint index, GLint x) {
    glad_glVertexAttribI1i = (PFNGLVERTEXATTRIBI1IPROC) glad_gl_on_demand_loader("glVertexAttribI1i");
    glad_glVertexAttribI1i(index, x);
}
PFNGLVERTEXATTRIBI1IPROC glad_glVertexAttribI1i = glad_on_demand_impl_glVertexAttribI1i;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttribI1iv(GLuint index, const GLint * v) {
    glad_glVertexAttribI1iv = (PFNGLVERTEXATTRIBI1IVPROC) glad_gl_on_demand_loader("glVertexAttribI1iv");
    glad_glVertexAttribI1iv(index, v);
}
PFNGLVERTEXATTRIBI1IVPROC glad_glVertexAttribI1iv = glad_on_demand_impl_glVertexAttribI1iv;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttribI1ui(GLuint index, GLuint x) {
    glad_glVertexAttribI1ui = (PFNGLVERTEXATTRIBI1UIPROC) glad_gl_on_demand_loader("glVertexAttribI1ui");
    glad_glVertexAttribI1ui(index, x);
}
PFNGLVERTEXATTRIBI1UIPROC glad_glVertexAttribI1ui = glad_on_demand_impl_glVertexAttribI1ui;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttribI1uiv(GLuint index, const GLuint * v) {
    glad_glVertexAttribI1uiv = (PFNGLVERTEXATTRIBI1UIVPROC) glad_gl_on_demand_loader("glVertexAttribI1uiv");
    glad_glVertexAttribI1uiv(index, v);
}
PFNGLVERTEXATTRIBI1UIVPROC glad_glVertexAttribI1uiv = glad_on_demand_impl_glVertexAttribI1uiv;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttribI2i(GLuint index, GLint x, GLint y) {
    glad_glVertexAttribI2i = (PFNGLVERTEXATTRIBI2IPROC) glad_gl_on_demand_loader("glVertexAttribI2i");
    glad_glVertexAttribI2i(index, x, y);
}
PFNGLVERTEXATTRIBI2IPROC glad_glVertexAttribI2i = glad_on_demand_impl_glVertexAttribI2i;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttribI2iv(GLuint index, const GLint * v) {
    glad_glVertexAttribI2iv = (PFNGLVERTEXATTRIBI2IVPROC) glad_gl_on_demand_loader("glVertexAttribI2iv");
    glad_glVertexAttribI2iv(index, v);
}
PFNGLVERTEXATTRIBI2IVPROC glad_glVertexAttribI2iv = glad_on_demand_impl_glVertexAttribI2iv;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttribI2ui(GLuint index, GLuint x, GLuint y) {
    glad_glVertexAttribI2ui = (PFNGLVERTEXATTRIBI2UIPROC) glad_gl_on_demand_loader("glVertexAttribI2ui");
    glad_glVertexAttribI2ui(index, x, y);
}
PFNGLVERTEXATTRIBI2UIPROC glad_glVertexAttribI2ui = glad_on_demand_impl_glVertexAttribI2ui;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttribI2uiv(GLuint index, const GLuint * v) {
    glad_glVertexAttribI2uiv = (PFNGLVERTEXATTRIBI2UIVPROC) glad_gl_on_demand_loader("glVertexAttribI2uiv");
    glad_glVertexAttribI2uiv(index, v);
}
PFNGLVERTEXATTRIBI2UIVPROC glad_glVertexAttribI2uiv = glad_on_demand_impl_glVertexAttribI2uiv;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttribI3i(GLuint index, GLint x, GLint y, GLint z) {
    glad_glVertexAttribI3i = (PFNGLVERTEXATTRIBI3IPROC) glad_gl_on_demand_loader("glVertexAttribI3i");
    glad_glVertexAttribI3i(index, x, y, z);
}
PFNGLVERTEXATTRIBI3IPROC glad_glVertexAttribI3i = glad_on_demand_impl_glVertexAttribI3i;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttribI3iv(GLuint index, const GLint * v) {
    glad_glVertexAttribI3iv = (PFNGLVERTEXATTRIBI3IVPROC) glad_gl_on_demand_loader("glVertexAttribI3iv");
    glad_glVertexAttribI3iv(index, v);
}
PFNGLVERTEXATTRIBI3IVPROC glad_glVertexAttribI3iv = glad_on_demand_impl_glVertexAttribI3iv;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttribI3ui(GLuint index, GLuint x, GLuint y, GLuint z) {
    glad_glVertexAttribI3ui = (PFNGLVERTEXATTRIBI3UIPROC) glad_gl_on_demand_loader("glVertexAttribI3ui");
    glad_glVertexAttribI3ui(index, x, y, z);
}
PFNGLVERTEXATTRIBI3UIPROC glad_glVertexAttribI3ui = glad_on_demand_impl_glVertexAttribI3ui;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttribI3uiv(GLuint index, const GLuint * v) {
    glad_glVertexAttribI3uiv = (PFNGLVERTEXATTRIBI3UIVPROC) glad_gl_on_demand_loader("glVertexAttribI3uiv");
    glad_glVertexAttribI3uiv(index, v);
}
PFNGLVERTEXATTRIBI3UIVPROC glad_glVertexAttribI3uiv = glad_on_demand_impl_glVertexAttribI3uiv;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttribI4bv(GLuint index, const GLbyte * v) {
    glad_glVertexAttribI4bv = (PFNGLVERTEXATTRIBI4BVPROC) glad_gl_on_demand_loader("glVertexAttribI4bv");
    glad_glVertexAttribI4bv(index, v);
}
PFNGLVERTEXATTRIBI4BVPROC glad_glVertexAttribI4bv = glad_on_demand_impl_glVertexAttribI4bv;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttribI4i(GLuint index, GLint x, GLint y, GLint z, GLint w) {
    glad_glVertexAttribI4i = (PFNGLVERTEXATTRIBI4IPROC) glad_gl_on_demand_loader("glVertexAttribI4i");
    glad_glVertexAttribI4i(index, x, y, z, w);
}
PFNGLVERTEXATTRIBI4IPROC glad_glVertexAttribI4i = glad_on_demand_impl_glVertexAttribI4i;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttribI4iv(GLuint index, const GLint * v) {
    glad_glVertexAttribI4iv = (PFNGLVERTEXATTRIBI4IVPROC) glad_gl_on_demand_loader("glVertexAttribI4iv");
    glad_glVertexAttribI4iv(index, v);
}
PFNGLVERTEXATTRIBI4IVPROC glad_glVertexAttribI4iv = glad_on_demand_impl_glVertexAttribI4iv;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttribI4sv(GLuint index, const GLshort * v) {
    glad_glVertexAttribI4sv = (PFNGLVERTEXATTRIBI4SVPROC) glad_gl_on_demand_loader("glVertexAttribI4sv");
    glad_glVertexAttribI4sv(index, v);
}
PFNGLVERTEXATTRIBI4SVPROC glad_glVertexAttribI4sv = glad_on_demand_impl_glVertexAttribI4sv;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttribI4ubv(GLuint index, const GLubyte * v) {
    glad_glVertexAttribI4ubv = (PFNGLVERTEXATTRIBI4UBVPROC) glad_gl_on_demand_loader("glVertexAttribI4ubv");
    glad_glVertexAttribI4ubv(index, v);
}
PFNGLVERTEXATTRIBI4UBVPROC glad_glVertexAttribI4ubv = glad_on_demand_impl_glVertexAttribI4ubv;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttribI4ui(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w) {
    glad_glVertexAttribI4ui = (PFNGLVERTEXATTRIBI4UIPROC) glad_gl_on_demand_loader("glVertexAttribI4ui");
    glad_glVertexAttribI4ui(index, x, y, z, w);
}
PFNGLVERTEXATTRIBI4UIPROC glad_glVertexAttribI4ui = glad_on_demand_impl_glVertexAttribI4ui;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttribI4uiv(GLuint index, const GLuint * v) {
    glad_glVertexAttribI4uiv = (PFNGLVERTEXATTRIBI4UIVPROC) glad_gl_on_demand_loader("glVertexAttribI4uiv");
    glad_glVertexAttribI4uiv(index, v);
}
PFNGLVERTEXATTRIBI4UIVPROC glad_glVertexAttribI4uiv = glad_on_demand_impl_glVertexAttribI4uiv;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttribI4usv(GLuint index, const GLushort * v) {
    glad_glVertexAttribI4usv = (PFNGLVERTEXATTRIBI4USVPROC) glad_gl_on_demand_loader("glVertexAttribI4usv");
    glad_glVertexAttribI4usv(index, v);
}
PFNGLVERTEXATTRIBI4USVPROC glad_glVertexAttribI4usv = glad_on_demand_impl_glVertexAttribI4usv;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttribIPointer(GLuint index, GLint size, GLenum type, GLsizei stride, const void * pointer) {
    glad_glVertexAttribIPointer = (PFNGLVERTEXATTRIBIPOINTERPROC) glad_gl_on_demand_loader("glVertexAttribIPointer");
    glad_glVertexAttribIPointer(index, size, type, stride, pointer);
}
PFNGLVERTEXATTRIBIPOINTERPROC glad_glVertexAttribIPointer = glad_on_demand_impl_glVertexAttribIPointer;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttribP1ui(GLuint index, GLenum type, GLboolean normalized, GLuint value) {
    glad_glVertexAttribP1ui = (PFNGLVERTEXATTRIBP1UIPROC) glad_gl_on_demand_loader("glVertexAttribP1ui");
    glad_glVertexAttribP1ui(index, type, normalized, value);
}
PFNGLVERTEXATTRIBP1UIPROC glad_glVertexAttribP1ui = glad_on_demand_impl_glVertexAttribP1ui;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttribP1uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint * value) {
    glad_glVertexAttribP1uiv = (PFNGLVERTEXATTRIBP1UIVPROC) glad_gl_on_demand_loader("glVertexAttribP1uiv");
    glad_glVertexAttribP1uiv(index, type, normalized, value);
}
PFNGLVERTEXATTRIBP1UIVPROC glad_glVertexAttribP1uiv = glad_on_demand_impl_glVertexAttribP1uiv;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttribP2ui(GLuint index, GLenum type, GLboolean normalized, GLuint value) {
    glad_glVertexAttribP2ui = (PFNGLVERTEXATTRIBP2UIPROC) glad_gl_on_demand_loader("glVertexAttribP2ui");
    glad_glVertexAttribP2ui(index, type, normalized, value);
}
PFNGLVERTEXATTRIBP2UIPROC glad_glVertexAttribP2ui = glad_on_demand_impl_glVertexAttribP2ui;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttribP2uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint * value) {
    glad_glVertexAttribP2uiv = (PFNGLVERTEXATTRIBP2UIVPROC) glad_gl_on_demand_loader("glVertexAttribP2uiv");
    glad_glVertexAttribP2uiv(index, type, normalized, value);
}
PFNGLVERTEXATTRIBP2UIVPROC glad_glVertexAttribP2uiv = glad_on_demand_impl_glVertexAttribP2uiv;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttribP3ui(GLuint index, GLenum type, GLboolean normalized, GLuint value) {
    glad_glVertexAttribP3ui = (PFNGLVERTEXATTRIBP3UIPROC) glad_gl_on_demand_loader("glVertexAttribP3ui");
    glad_glVertexAttribP3ui(index, type, normalized, value);
}
PFNGLVERTEXATTRIBP3UIPROC glad_glVertexAttribP3ui = glad_on_demand_impl_glVertexAttribP3ui;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttribP3uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint * value) {
    glad_glVertexAttribP3uiv = (PFNGLVERTEXATTRIBP3UIVPROC) glad_gl_on_demand_loader("glVertexAttribP3uiv");
    glad_glVertexAttribP3uiv(index, type, normalized, value);
}
PFNGLVERTEXATTRIBP3UIVPROC glad_glVertexAttribP3uiv = glad_on_demand_impl_glVertexAttribP3uiv;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttribP4ui(GLuint index, GLenum type, GLboolean normalized, GLuint value) {
    glad_glVertexAttribP4ui = (PFNGLVERTEXATTRIBP4UIPROC) glad_gl_on_demand_loader("glVertexAttribP4ui");
    glad_glVertexAttribP4ui(index, type, normalized, value);
}
PFNGLVERTEXATTRIBP4UIPROC glad_glVertexAttribP4ui = glad_on_demand_impl_glVertexAttribP4ui;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttribP4uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint * value) {
    glad_glVertexAttribP4uiv = (PFNGLVERTEXATTRIBP4UIVPROC) glad_gl_on_demand_loader("glVertexAttribP4uiv");
    glad_glVertexAttribP4uiv(index, type, normalized, value);
}
PFNGLVERTEXATTRIBP4UIVPROC glad_glVertexAttribP4uiv = glad_on_demand_impl_glVertexAttribP4uiv;
static void GLAD_API_PTR glad_on_demand_impl_glVertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void * pointer) {
    glad_glVertexAttribPointer = (PFNGLVERTEXATTRIBPOINTERPROC) glad_gl_on_demand_loader("glVertexAttribPointer");
    glad_glVertexAttribPointer(index, size, type, normalized, stride, pointer);
}
PFNGLVERTEXATTRIBPOINTERPROC glad_glVertexAttribPointer = glad_on_demand_impl_glVertexAttribPointer;
static void GLAD_API_PTR glad_on_demand_impl_glViewport(GLint x, GLint y, GLsizei width, GLsizei height) {
    glad_glViewport = (PFNGLVIEWPORTPROC) glad_gl_on_demand_loader("glViewport");
    glad_glViewport(x, y, width, height);
}
PFNGLVIEWPORTPROC glad_glViewport = glad_on_demand_impl_glViewport;
static void GLAD_API_PTR glad_on_demand_impl_glWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout) {
    glad_glWaitSync = (PFNGLWAITSYNCPROC) glad_gl_on_demand_loader("glWaitSync");
    glad_glWaitSync(sync, flags, timeout);
}
PFNGLWAITSYNCPROC glad_glWaitSync = glad_on_demand_impl_glWaitSync;


 


#ifdef __cplusplus
}
#endif
