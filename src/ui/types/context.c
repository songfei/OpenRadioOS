#include "context.h"
#include "color.h"
#include <ui.h>

// TODO optimization: calculate bytefill when color is set.

void graphics_context_set_stroke_color(GContext * ctx, GColor color) {
    ctx->stroke_color = color;
}

void graphics_context_set_fill_color(GContext * ctx, GColor color) {
    ctx->fill_color = color;
}

void graphics_context_set_text_color(GContext * ctx, GColor color) {
    ctx->text_color = color;
}

void graphics_context_set_compositing_mode(GContext * ctx, GCompOp comp_op) {
    ctx->comp_op = comp_op;
}

void graphics_context_set_antialiased(GContext * ctx, bool enable) {
    ctx->antialias = enable;
}

void graphics_context_set_stroke_width(GContext * ctx, uint16_t width) {
    if (width == 0)
        return;
    ctx->stroke_width = ((width + 2) & ~(1)) - 1;
}

void graphics_context_set_stroke_caps(GContext * ctx, bool stroke_caps) {
    ctx->stroke_caps = stroke_caps;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */


//void n_graphics_context_begin(n_GContext * ctx) {
//    if (ctx->underlying_context) {
//        ctx->bitmap = graphics_capture_frame_buffer(ctx->underlying_context);
//        ctx->fbuf = gbitmap_get_data(ctx->bitmap);
//    }
//}
//
//void n_graphics_context_end(n_GContext * ctx) {
//    if (ctx->underlying_context) {
//        graphics_release_frame_buffer(ctx->underlying_context, ctx->bitmap);
//        ctx->bitmap = NULL;
//        ctx->fbuf = NULL;
//    }
//}


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

//GBitmap * graphics_capture_frame_buffer(GContext * ctx) {
//#ifndef NGFX_IS_CORE
//    return graphics_capture_frame_buffer(ctx->underlying_context);
//#else
//    return graphics_capture_frame_buffer(ctx);
//#endif
//}
//
//
//
//bool n_graphics_release_frame_buffer(n_GContext * ctx, GBitmap * bitmap) {
//#ifndef NGFX_IS_CORE
//    return graphics_release_frame_buffer(ctx->underlying_context, bitmap);
//#else
//    return graphics_release_frame_buffer(ctx, bitmap);
//#endif
//}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

static GContext* graphics_context_create() {
    GContext* out = (GContext*)ui_malloc(sizeof(GContext));

//    out->underlying_context = NULL;

    graphics_context_set_stroke_color(out, (GColor) {.rgb = 0b000000000000000});
    graphics_context_set_fill_color(out, (GColor) {.rgb = 0b1111111111111111});
    graphics_context_set_text_color(out, (GColor) {.rgb = 0b111111111111111});
    graphics_context_set_compositing_mode(out, GCompOpAssign);
    graphics_context_set_stroke_caps(out, true);
    graphics_context_set_antialiased(out, true);
    graphics_context_set_stroke_width(out, 1);
    return out;
}

GContext * graphics_context_from_buffer(uint8_t * buf) {
    GContext * out = graphics_context_create();
    out->fbuf = buf;
    return out;
}


GContext * graphics_context_from_graphics_context(GContext * ctx) {
    GContext * out = graphics_context_create();
//    out->underlying_context = ctx;
    return out;
}


void graphics_context_destroy(GContext * ctx) {
    ui_free(ctx);
}

#ifdef NGFX_IS_CORE
static n_GContext * n_root_graphics_context_create() {
    n_GContext * out = malloc(sizeof(n_GContext));
    if (out == NULL)
        printf("NG: COULD NOT CREATE ROOT GRAPHICS CONTEXT!\n");
    n_graphics_context_set_stroke_color(out, (n_GColor) {.argb = 0b11000000});
    n_graphics_context_set_fill_color(out, (n_GColor) {.argb = 0b11111111});
    n_graphics_context_set_text_color(out, (n_GColor) {.argb = 0b11000000});
    n_graphics_context_set_compositing_mode(out, n_GCompOpAssign);
    n_graphics_context_set_stroke_caps(out, true);
    n_graphics_context_set_antialiased(out, true);
    n_graphics_context_set_stroke_width(out, 1);
    return out;
}

n_GContext * n_root_graphics_context_from_buffer(uint8_t * buf) {
    n_GContext * out = n_graphics_context_create();
    out->fbuf = buf;
    return out;
}
#endif
