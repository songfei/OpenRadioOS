
#ifndef __OPEN_RADIO_UI_CORNER_MASK__
#define __OPEN_RADIO_UI_CORNER_MASK__

/*! \addtogroup Types
 *  @{
 *  \addtogroup CornerMask
 *  @{
 */

/*!
 * Describes what corners should be rounded when drawing a shape.
 */
typedef enum GCornerMask {
    GCornersNone       = 0, // support all grammatical preferences
    GCornerNone        = 0,
    GCornerTopLeft     = 0b0001,
    GCornerTopRight    = 0b0010,
    GCornerBottomLeft  = 0b0100,
    GCornerBottomRight = 0b1000,
    GCornersTop        = 0b0011,
    GCornersBottom     = 0b1100,
    GCornersLeft       = 0b0101,
    GCornersRight      = 0b1010,
    GCornersAll        = 0b1111,
} GCornerMask;

/*! @}
 *  @}
 */

#endif