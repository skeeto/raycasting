#include "constants.h"
#include <stdio.h>
#include <math.h>

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

float calculate_distance(float x1, float y1, float x2, float y2){
    return sqr((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}