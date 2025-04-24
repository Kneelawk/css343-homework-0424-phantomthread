#include <iostream>

#include "city_coords.h"
#include "ktest.hpp"
#include "min_spanning_tree.h"

int main() {
    ktest::runAllTests();

    const std::vector<CityCoords> cityCoords = {
        CityCoords("Frankfurt", 50.1109, 8.6821),
        CityCoords("Copenhagen", 55.6761, 12.5683),
        CityCoords("Prague", 50.0755, 14.4378),
        CityCoords("Rome", 41.9028, 12.4964),
        CityCoords("Vienna", 48.2082, 16.3738),
        CityCoords("Budapest", 47.4979, 19.0402),
        CityCoords("Barcelona", 41.3784, 2.1915),
        CityCoords("Florence", 43.7696, 11.2558),
        CityCoords("Berlin", 52.52, 13.405),
        CityCoords("Amsterdam", 52.3676, 4.9041),
        CityCoords("Paris", 48.8566, 2.3522)
    };

    const std::vector<CityLink> mst = minSpanningTree(cityCoords);

    std::cout << "Links:" << std::endl;
    double sum = 0;
    for (const CityLink &link : mst) {
        std::cout << "  " << link << std::endl;
        sum += link.distance;
    }
    std::cout << "Total distance: " << sum << std::endl;

    return 0;
}
