#include <print>
#include <expected>
#include <string>
#include <expected>
#include "types.hpp"
#include <iostream>
#include "string_utils.hpp"
#include <nlohmann/json.hpp>
#include <cpr/cpr.h>
#include <spdlog/spdlog.h>

struct Entry {
    std::string name;
    int value;
};

Entry read_entry(std::istream& is) {
    std::string s;
    int i;
    is >> s >> i;
    return {s, i};
}

int main() {

    CityProfile profile {
        .city_input = "New York",
        .city_normalized = "new-york",
        .coords = {40.7128, -74.0060},
        .wiki_summary = "The city that never sleeps."
    };

    profile.city_normalized = slugify(profile.city_input);

    spdlog::info("Profile created for city: {}", profile.city_input);

    std::println("City: {}", profile.city_input);
    std::println("Normalized City: {}", profile.city_normalized);
    std::println("Latitude: {}", profile.coords.latitude);
    std::println("Longitude: {}", profile.coords.longitude);


    auto e = read_entry(std::cin);
    std::println("Entry Name: {}, Value: {}", e.name, e.value);

    auto response = cpr::Get(cpr::Url("https://api.github.com"));
    if (response.status_code == 200) {
        spdlog::info("Successfully fetched data from GitHub API");
        nlohmann::json json_response = nlohmann::json::parse(response.text);
        std::println("github json response: {}", json_response.dump(4));
    } else {
        spdlog::error("Failed to fetch data from GitHub API: {}", response.error.message);
    }

    return 0;
}