
#ifndef __OPEN_RADIO_UI_SIZE__
#define __OPEN_RADIO_UI_SIZE__

#include <stdint.h>
#include <stdbool.h>

/*! \addtogroup Types
 *  @{
 *  \addtogroup Size
 *  Defines a size, which contains information about something's width and
 *  height.
 *  @{
 */

typedef struct GSize {
    int16_t w;
    int16_t h;
} GSize;

/*!
 * Tests whether 2 GSize are equal
 */
bool gsize_equal(const GSize *size_a, const GSize *size_b); // implemented in rect.c

/*! @}
 *  @}
 */


#endif