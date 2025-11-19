#pragma once

#include <string_view>
#include <vector>
#include "enums.hpp"

struct Coordinates {
    double latitude;
    double longitude;
};

struct Place {
    std::string name;
    std::string id;
    Category category {Category::Unknown};
    std::string address;
    Coordinates coords;
    std::vector <std::string> tags;
};

struct WeatherSlice {
    long timestamp;
    double tempCelsius;
    double humidity;
    double wind_speed;
    std::string summary;
};

struct CityProfile {
    std::string city_input;
    std::string city_normalized;
    Coordinates coords;
    std::string wiki_summary;
    std::vector<Place> places;
    std::vector<WeatherSlice> forecast;
};
