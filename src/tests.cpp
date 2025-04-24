//
// Created by cyan on 4/21/25.
//

#include "city_coords.h"
#include "ktest.hpp"
#include "min_spanning_tree.h"

KTEST(calc_distance_1) {
    const CityCoords paris("Paris", 48.8566, 2.3522);
    const CityCoords frankfurt("Frankfurt", 50.1109, 8.6821);

    KASSERT_APPROX_EQ(477.862, paris - frankfurt, 0.15);
}

KTEST(calc_distance_2) {
    const CityCoords rome("Rome",41.9028, 12.4964);
    const CityCoords florence("Florence",43.7696, 11.2558);

    KASSERT_APPROX_EQ(231.008, rome - florence, 0.15);
}

KTEST(simple_mst_1) {
    const CityCoords paris("Paris", 48.8566, 2.3522);
    const CityCoords berlin("Berlin",52.52, 13.405);
    const CityCoords frankfurt("Frankfurt", 50.1109, 8.6821);
    const std::vector<CityCoords> cities = {paris, berlin, frankfurt};

    const std::vector<CityLink> expectedLinks = {
        {berlin, frankfurt, berlin - frankfurt},
        {paris, frankfurt, paris - frankfurt}
    };

    const std::vector<CityLink> actualLinks = minSpanningTree(cities);

    KASSERT_EQ(expectedLinks.size(), actualLinks.size());
    KASSERT_EQ(expectedLinks[0], actualLinks[0]);
    KASSERT_EQ(expectedLinks[1], actualLinks[1]);
}

KTEST(simple_mst_2) {
    const CityCoords dublin("Dublin", 53.33306, -6.24889);
    const CityCoords london("London",51.509865, -0.118092);
    const CityCoords paris("Paris", 48.8566, 2.3522);
    const std::vector<CityCoords> cities = {dublin, london, paris};

    const std::vector<CityLink> expectedLinks = {
        {london, paris, london - paris},
        {dublin, london, dublin - london}
    };

    const std::vector<CityLink> actualLinks = minSpanningTree(cities);

    KASSERT_EQ(expectedLinks.size(), actualLinks.size());
    KASSERT_EQ(expectedLinks[0], actualLinks[0]);
    KASSERT_EQ(expectedLinks[1], actualLinks[1]);
}
