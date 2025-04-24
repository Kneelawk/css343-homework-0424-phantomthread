//
// Created by cyan on 4/23/25.
//

#include "min_spanning_tree.h"

#include <vector>

#include "city_coords.h"

std::vector<CityLink> minSpanningTree(const std::vector<CityCoords> &cities) {
    const CityCoords first = *cities.rbegin();

    std::vector<CityLink> links;
    for (size_t i = 0; i < cities.size() - 1; i++) {
        CityCoords city = cities[i];
        links.push_back({city, first, first - city});
    }

    std::vector<CityLink> res;

    while (!links.empty()) {
        // find link with smallest distance
        size_t minIndex = 0;
        for (size_t i = 0; i < links.size(); i++) {
            if (links[i].distance < links[minIndex].distance) {
                minIndex = i;
            }
        }

        const CityLink shortest = links[minIndex];
        links.erase(links.begin() + minIndex);
        res.push_back(shortest);

        const CityCoords newFrom = shortest.to;
        // apply min distances with new link in mind
        for (auto &link: links) {
            // only update a link if it is shorter to the new city than any of the old ones
            const double newDistance = newFrom - link.to;
            if (newDistance < link.distance) {
                link.distance = newDistance;
                // keep track of where the shortest links are coming from
                link.from = newFrom;
            }
        }
    }

    return res;
}
