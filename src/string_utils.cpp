#include "string_utils.hpp"

#include <algorithm>
#include <cctype>
#include <string>

namespace {

// helper: is whitespace for char
bool is_space(char ch) {
    return std::isspace(static_cast<unsigned char>(ch)) != 0;
}

// helper: is alphanumeric
bool is_alnum(char ch) {
    return std::isalnum(static_cast<unsigned char>(ch)) != 0;
}

} // namespace

std::string trim(std::string_view s) {
    std::size_t start = 0;
    std::size_t end = s.size();

    while (start < end && is_space(s[start])) {
        ++start;
    }
    while (end > start && is_space(s[end - 1])) {
        --end;
    }

    return std::string{s.substr(start, end - start)};
}

std::string to_lower(std::string_view s) {
    std::string out;
    out.reserve(s.size());
    for (char ch : s) {
        out.push_back(static_cast<char>(
            std::tolower(static_cast<unsigned char>(ch))
        ));
    }
    return out;
}

std::string collapse_spaces(std::string_view s) {
    std::string out;
    out.reserve(s.size());

    bool in_space = false;
    for (char ch : s) {
        if (is_space(ch)) {
            if (!in_space) {
                out.push_back(' ');
                in_space = true;
            }
        } else {
            out.push_back(ch);
            in_space = false;
        }
    }

    return trim(out);
}

bool icontains(std::string_view haystack, std::string_view needle) {
    if (needle.empty()) return true;
    auto h = to_lower(haystack);
    auto n = to_lower(needle);
    return h.find(n) != std::string::npos;
}

std::string slugify(std::string_view s) {
    // normalize: trim, lowercase, collapse spaces
    std::string cleaned = collapse_spaces(s);
    cleaned = to_lower(cleaned);

    std::string out;
    out.reserve(cleaned.size());

    bool last_was_dash = false;

    for (char ch : cleaned) {
        if (is_alnum(ch)) {
            out.push_back(ch);
            last_was_dash = false;
        } else if (is_space(ch) || ch == '-' || ch == '_' || ch == '/') {
            if (!last_was_dash && !out.empty()) {
                out.push_back('-');
                last_was_dash = true;
            }
        } else {
            // skip other punctuation entirely
        }
    }

    // trim trailing dash if present
    if (!out.empty() && out.back() == '-') {
        out.pop_back();
    }

    return out;
}
