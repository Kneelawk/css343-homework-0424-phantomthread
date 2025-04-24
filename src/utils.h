//
// Created by cyan on 4/23/25.
//

#ifndef UTILS_H
#define UTILS_H

constexpr double EARTH_RADIUS = 6371.0;

double toRadians(double degrees);

double calcDistance(double lat1, double lon1, double lat2, double lon2);

#endif //UTILS_H
