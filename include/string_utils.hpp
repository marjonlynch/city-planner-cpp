#pragma once

#include <string>
#include <string_view>

// Trim whitespace from both ends
std::string trim(std::string_view s);

// Lowercase a string (ASCII for now)
std::string to_lower(std::string_view s);

// Collapse runs of whitespace into a single space
std::string collapse_spaces(std::string_view s);

// Case-insensitive "haystack contains needle"
bool icontains(std::string_view haystack, std::string_view needle);

// Turn "Boulder, CO" -> "boulder-co", safe for IDs/URLs
std::string slugify(std::string_view s);
