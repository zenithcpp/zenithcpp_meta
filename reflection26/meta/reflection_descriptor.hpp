#pragma once

#include <cstddef>
#include <string_view>

namespace Zenith::Meta
{

struct ReflectionDescriptor
{
    std::string_view name{};

    std::size_t member_count = 0;
};

}
