
#ifndef __OPEN_RADIO_UI_POINT__
#define __OPEN_RADIO_UI_POINT__

#include <stdint.h>
#include <stdbool.h>

/*!
 * Represents a point.
 */
typedef struct GPoint {
    int16_t x;
    int16_t y;
} GPoint;

/*!
 * Convenience macro to quickly define a point.
 */
#define GPoint(x, y) ((GPoint) {x, y})
/*!
 * Convenience macro for the origin (top left).
 */
#define GPointZero ((n_GPoint) {.x = 0, .y = 0})

/*!
 * Tests whether 2 GPoint are equal.
 */
bool gpoint_equal(const GPoint *point_a, const GPoint *point_b); // implemented in rect.c

/*! @}
 *  @}
 */

#endif