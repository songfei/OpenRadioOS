#ifndef __OPEN_RADIO_UI_COLOR__
#define __OPEN_RADIO_UI_COLOR__

#include <stdint.h>
#include <stdbool.h>
#include "colors.h"


/*! \addtogroup Types
 *  @{
 *  \addtogroup Color
 *  Color-handling code.
 *  @{
 */

/*!
 * Internal representation of colors: now with revolutionary 2-bit-per-channel
 * technology!
 */
typedef union GColor {
    struct {
        uint8_t r:5;
        uint8_t g:6;
        uint8_t b:5;
    };
    uint16_t rgb;
} GColor;


/*!
 * Check for the equality of two GColor(s).
 */
static inline bool gcolor_equal(GColor a, GColor b) {
   return a.rgb == b.rgb;
}

/*!
 * Get the ideal text GColor over a given background.
 */
static inline GColor gcolor_legible_over(GColor color) {
   return (color.r + color.g + color.b > 48) ? n_GColorWhite : n_GColorBlack;
}

/*!
 * Blends a GColor over another.
 */
static inline GColor gcolor_blend(GColor dst, GColor src) {
    dst.r = (src.r * dst.r ) >> 5;
    dst.g = (src.g * dst.g ) >> 6;
    dst.b = (src.b * dst.b ) >> 5;
    return dst;
}

/*!
 * Convenience macro to create the closest GColor.
 */
#define GColorFromRGB(_r, _g, _b) \
    ((GColor) {{.r = (_r >> 3) & 0b11111,\
                   .g = (_g >> 2) & 0b111111, .b = (_b >> 3) & 0b11111}})

/*!
 * Convenience macro to create the closest GColor to a hex value (eg 0xFF7700).
 */
#define GColorFromHEX(_h) GColorFromRGB(((_h) >> 16) & 0b11111111, \
                                            ((_h) >>  8) & 0b11111111, \
                                             (_h)        & 0b11111111)

/*! @}
 *  @}
 */

#endif