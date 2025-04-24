//
// Created by cyan on 4/23/25.
//

#ifndef CITY_COORDS_H
#define CITY_COORDS_H
#include <ostream>
#include <string>
#include "utils.h"

class CityCoords {
    std::string name;
    double lat;
    double lon;

public:
    CityCoords(const std::string &name, const double lat, const double lon)
        : name(name),
          lat(lat),
          lon(lon) {
    }

    double operator -(const CityCoords &other) const {
        return calcDistance(lat, lon, other.lat, other.lon);
    }

    friend std::ostream & operator<<(std::ostream &os, const CityCoords &obj) {
        return os << obj.name;
    }

    friend bool operator==(const CityCoords &lhs, const CityCoords &rhs) {
        return lhs.name == rhs.name
               && lhs.lat == rhs.lat
               && lhs.lon == rhs.lon;
    }

    friend bool operator!=(const CityCoords &lhs, const CityCoords &rhs) {
        return !(lhs == rhs);
    }
};



#endif //CITY_COORDS_H
