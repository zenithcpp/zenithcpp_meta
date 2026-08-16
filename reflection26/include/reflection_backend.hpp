#pragma once

#include <cstddef>
#include <cstdint>
#include <string_view>

namespace Zenith::Meta
{

struct ReflectionReport
{
    std::size_t declaration_count = 0;

    int reflected_value = 0;

    std::uint32_t threat_level = 0;

    bool allow_extended_payload = false;
    bool allow_branching = false;
    bool allow_match = false;
    bool allow_plugin = false;

    std::string_view reflected_type{};
    std::size_t reflected_members = 0;
};


class ReflectionBackend
{
public:

    virtual ~ReflectionBackend() = default;

    virtual ReflectionReport inspect() const = 0;

    virtual std::string_view name() const = 0;
};

}
