//
// Created by cyan on 4/23/25.
//

#include <cmath>

#include "utils.h"

double toRadians(const double degrees) {
    return degrees * M_PI / 180;
}

double calcDistance(double lat1, double lon1, double lat2, double lon2) {
    lat1 = toRadians(lat1);
    lon1 = toRadians(lon1);
    lat2 = toRadians(lat2);
    lon2 = toRadians(lon2);

    const double dlat = lat2 - lat1;
    const double dlon = lon2 - lon1;

    // Haversine formula
    const double a = sin(dlat/2) * sin(dlat/2) + cos(lat1) * cos(lat2) * sin(dlon/2) * sin(dlon/2);
    const double c = 2 * atan2(sqrt(a), sqrt(1-a));

    return EARTH_RADIUS * c;
}
