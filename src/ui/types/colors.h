

#ifndef __OPEN_RADIO_UI_COLORS__
#define __OPEN_RADIO_UI_COLORS__


#include <stdint.h>
#include "color.h"

/*! \addtogroup Types
 *  @{
 *  \addtogroup Color
 *  @{
 *  \addtogroup Definitions
 *  All the color definitions.
 *  @{
 */

#define GColorWhiteRGB565                ((uint16_t) 0b111111111111111)
#define GColorWhite                      ((GColor) { .rgb = (GColorWhiteRGB565) })

#define GColorBlackRGB565                ((uint16_t) 0b0000000000000000)
#define GColorBlack                      ((GColor) { .rgb = (GColorBlackRGB565) })


/*! @}
 */

#endif