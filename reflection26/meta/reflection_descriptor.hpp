#pragma once

#include <cstddef>
#include <cstdint>
#include <string_view>

namespace Zenith::Meta
{

using TypeId = std::uint64_t;
using MemberId = std::uint64_t;


struct MemberDescriptor
{
    MemberId id{};

    std::string_view name{};

    TypeId type_id{};

    std::size_t size{};

    std::size_t alignment{};
};


struct ReflectionDescriptor
{
    TypeId id{};

    std::string_view name{};

    std::size_t size{};

    std::size_t alignment{};

    const MemberDescriptor* members{};

    std::size_t member_count{};
};


}
