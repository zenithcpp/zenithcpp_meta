#pragma once

#include "reflection_descriptor.hpp"

#include <string_view>

namespace Zenith::Meta
{

constexpr TypeId type_id(std::string_view name)
{
    TypeId hash = 14695981039346656037ull;

    for (const char character : name)
    {
        hash ^= static_cast<unsigned char>(character);
        hash *= 1099511628211ull;
    }

    return hash;
}


constexpr MemberId member_id(
    std::string_view owner,
    std::string_view name
)
{
    TypeId hash = 14695981039346656037ull;

    for (const char character : owner)
    {
        hash ^= static_cast<unsigned char>(character);
        hash *= 1099511628211ull;
    }

    hash ^= static_cast<unsigned char>(':');
    hash *= 1099511628211ull;

    hash ^= static_cast<unsigned char>(':');
    hash *= 1099511628211ull;

    for (const char character : name)
    {
        hash ^= static_cast<unsigned char>(character);
        hash *= 1099511628211ull;
    }

    return hash;
}

}
