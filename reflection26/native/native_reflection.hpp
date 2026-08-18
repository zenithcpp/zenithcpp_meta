#pragma once

#include <cstddef>
#include <cstdint>
#include <string>
#include <string_view>
#include <vector>

namespace Zenith::NativeReflection
{

struct ReflectedMember
{
    std::string_view name{};
    std::string_view type_name{};

    std::size_t size = 0;
    std::size_t alignment = 0;
    std::ptrdiff_t offset = 0;

    std::string value{};
};


struct ReflectedObject
{
    std::string_view type_name{};

    std::size_t size = 0;
    std::size_t alignment = 0;

    std::vector<ReflectedMember> members{};
};


template<class T>
ReflectedObject inspect(T& object);

}
