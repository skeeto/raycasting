#ifndef HELPERS_H
#define HELPERS_H

/**
 * Normalize the angle such that it is between 0 and 2 PI
 * 
 * @param angle angle to be normalized
 * @return float the normalized angle
 */
float normalize_angle(float angle);

/**
 * Calculates the distance between two points using euclidean distance
 * 
 * @param x1 
 * @param y1 
 * @param x2 
 * @param y2 
 * @return float distance in float 
 */
float calculate_distance(float x1, float y1, float x2, float y2); 

#endif