#pragma once

#include <string>
#include <string_view>
#include <vector>
#include <expected>
#include "types.hpp"

struct ParseError {
    std::string message;
};

std::expected<Coordinates, ParseError> parse_geocode(const std::string_view json);

std::expected<std::vector<WeatherSlice>, ParseError> parse_weather(const std::string_view json);

std::expected<std::vector<Place>, ParseError> parse_places(const std::string_view json);
