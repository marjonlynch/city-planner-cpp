#pragma once
#include <string_view>

enum class Category {
    Unknown,
    FoodDrink,
    Culture,
    Nature,
    Book,
    Landmark,
    Weather
};

enum class Priority {
    low,
    medium,
    high
};

enum class Unit {
    metric,
    imperial
};

constexpr std::string_view to_string(Category category) {
    switch (category) {
        case Category::FoodDrink:
            return "Food & Drink";
        case Category::Culture:
            return "Culture";
        case Category::Nature:
            return "Nature";
        case Category::Book:
            return "Book";
        case Category::Landmark:
            return "Landmark";
        case Category::Weather:
            return "Weather";
        default:
            return "Unknown";
    }
}