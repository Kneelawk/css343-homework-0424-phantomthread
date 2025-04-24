//
// Created by cyan on 4/23/25.
//

#ifndef MIN_SPANNING_TREE_H
#define MIN_SPANNING_TREE_H
#include <ostream>
#include <vector>

#include "city_coords.h"

struct CityLink {
    CityCoords to;
    CityCoords from;
    double distance;

    friend std::ostream &operator<<(std::ostream &os, const CityLink &obj) {
        return os << obj.from << " -- " << obj.distance << " -> " << obj.to;
    }

    friend bool operator==(const CityLink &lhs, const CityLink &rhs) {
        return lhs.to == rhs.to
               && lhs.from == rhs.from
               && lhs.distance == rhs.distance;
    }

    friend bool operator!=(const CityLink &lhs, const CityLink &rhs) {
        return !(lhs == rhs);
    }
};

std::vector<CityLink> minSpanningTree(const std::vector<CityCoords> &cities);

#endif //MIN_SPANNING_TREE_H
