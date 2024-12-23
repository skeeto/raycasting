#include "constants.h"
#include <stdio.h>

/**
 * Normalize the angle such that it is between 0 and 2 PI
 * 
 * @param angle angle to be normalized
 * @return float the normalized angle
 */
float normalize_angle(float angle){
    // Take the remainder
    angle = remainder(angle, TWO_PI);

    // Handle the case when the angle becomes negative
    if (angle < 0){
        angle += TWO_PI;
    }

    return angle; 
}