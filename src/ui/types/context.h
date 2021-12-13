


/*-----------------------------------------------------------------------------.
|                                                                              |
|                                  GContext                                    |
|                                                                              |
|   GContexts exist to store information about the graphics environment,       |
|   most importantly a pointer to the framebuffer, information about current   |
|   graphics settings, and information about the currently active graphics     |
|   origin and clipping box.                                                   |
|                                                                              |
`-----------------------------------------------------------------------------*/

/*! \addtogroup context
 *  The graphics context itself.
 *  @{
 */

#include "color.h"
#include "rect.h"

typedef struct GBitmap GBitmap;

//! Values to specify how the source image should be composited onto the destination image.
typedef enum {
    GCompOpAssign,         //<! dst = src
    GCompOpAssignInverted, //<! dst = ~src
    GCompOpOr,             //<! dst = dst | src
    GCompOpAnd,            //<! dst = dst & src
    GCompOpClear,          //<! dst & ~src
    GCompOpSet,            //<! dst | ~src
} GCompOp;

/*!
 * Internal representation of the graphics context itself. Created via
 * n_graphics_context_from_buffer() or
 * n_graphics_context_from_graphics_context().
 */
typedef struct GContext {
    GColor stroke_color;
    GColor fill_color;
    GColor text_color;
    bool antialias;
    bool stroke_caps;
    uint16_t stroke_width;
    GCompOp comp_op;
    GBitmap * bitmap;
    uint8_t * fbuf;
    GRect offset;
} GContext;

/*!
 * Sets the n_GColor used to draw strokes.
 */
void graphics_context_set_stroke_color(GContext * ctx, GColor color);
/*!
 * Sets the n_GColor used to fill primitives.
 */
void graphics_context_set_fill_color(GContext * ctx, GColor color);
/*!
 * Sets the n_GColor used to draw text.
 */
void graphics_context_set_text_color(GContext * ctx, GColor color);
/*!
 * Sets the compositing mode used to draw bitmaps.
 */
void graphics_context_set_compositing_mode(GContext * ctx, GCompOp comp_op);
/*!
 * Sets whether stroke caps should be drawn.
 */
void graphics_context_set_stroke_caps(GContext * ctx, bool caps);
/*!
 * Sets the stroke width.
 */
void graphics_context_set_stroke_width(GContext * ctx, uint16_t width);
/*!
 * Sets whether antialiasing should be used.
 * \note Not implemented yet.
 */
void graphics_context_set_antialiased(GContext * ctx, bool antialias);



/*!
 * In Pebble OS, use this before drawing to the n_GContext for contexts created
 * from a graphics context (via n_graphics_context_from_graphics_context()).
 * Not required on other platforms.
 */
void graphics_context_begin(GContext * ctx);
/*!
 * In Pebble OS, use this before drawing to the n_GContext for contexts created
 * from a graphics context (via n_graphics_context_from_graphics_context()).
 * Not required on other platforms.
 */
void graphics_context_end(GContext * ctx);



/*!
 * In native platforms, freeze the framebuffer and return a GBitmap thereof.
 */
GBitmap * graphics_capture_frame_buffer(GContext * ctx);

/*!
 * In native platforms, unfreeze the framebuffer.
 */
bool graphics_release_frame_buffer(GContext * ctx, GBitmap * bitmap);

///*!
// * Creates a n_GContext based on a framebuffer.
// */
//GContext * graphics_context_from_buffer(uint8_t * buf);
//
//#ifndef NGFX_IS_CORE
///*!
// * Creates a n_GContext based on a GContext (provided by Pebble OS).
// */
//GContext * graphics_context_from_graphics_context(GContext * ctx);
//#endif
//
///*!
// * Destroys a n_GContext.
// */
//void graphics_context_destroy(GContext * ctx);
//
//
//#ifdef NGFX_IS_CORE
///*!
// * Creates a root n_GContext based on the system framebuffer.
// * This should be done exactly once. ** This context cannoy be freed. **
// */
//n_GContext * n_root_graphics_context_from_buffer(uint8_t * buf);
//#endif

/*! @}
 */
