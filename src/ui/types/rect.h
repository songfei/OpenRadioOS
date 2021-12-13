
#ifndef __OPEN_RADIO_UI_RECT__
#define __OPEN_RADIO_UI_RECT__

#include <stdint.h>
#include <stdbool.h>

#include "point.h"
#include "size.h"

/*! \addtogroup Types
 *  @{
 *  \addtogroup typerect Rect
 *  @{
 */

typedef struct GRect {
    GPoint origin;
    GSize size;
} GRect;

/*!
 * Convenience macro to quickly define a rectangle.
 */
#define GRect(x, y, w, h) ((GRect) {{x, y}, {w, h}})

/*!
 * Convenience macro to standardize a rectangle.
 * \warning Differs from the Pebble OS implementation, which is in-place and
 * takes a pointer.
 */
#define grect_standardize(a) \
    ((a).size.w >= 0 \
        ? (a).size.h >= 0 \
            /* normal */ \
            ? (GRect) { {  (a).origin.x,      (a).origin.y }, \
                          {  (a).size.w,        (a).size.h     }} \
            /* switch vertically */ \
            : (GRect) { {  (a).origin.x,      (a).origin.y + (a).size.h }, \
                          {  (a).size.w,       -(a).size.h }} \
        : (a).size.h >= 0 \
            /* switch horizontally */ \
            ? (GRect) { {  (a).origin.x + (a).size.w, (a).origin.y }, \
                          { -(a).size.w,    (a).size.h     }} \
            /* switch horizontally and vertically */ \
            : (GRect) { {  (a).origin.x + (a).size.w, (a).origin.y + (a).size.h }, \
                          { -(a).size.w,   -(a).size.h }})

/*!
 * Returns the point at the center of a GRect (will prefer top and/or left
 * at even sizes)
 */
GPoint grect_center_point(GRect *rect);

/*!
 * Tests whether 2 GRect are equal
 */
bool grect_equal(const GRect *rect_a, const GRect *rect_b);

/*!
 * Tests whether the size of a GRect is (0, 0)
 */
bool grect_is_empty(const GRect *const rect);

/*!
 * Trim one GRect using the edges of a second GRect
 */
void grect_clip(GRect *rect_to_clip, const GRect *rect_clipper);

/*!
 * Tests whether a GRect contains a point
 */
bool grect_contains_point(const GRect *rect, const GPoint *point);

/*!
 * Reduce the width and height of a GRect and centering it relative to the original
 */
GRect grect_crop(GRect rect, int32_t crop_size_px);

/*! @}
 *  @}
 */

#endif