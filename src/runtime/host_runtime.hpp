#pragma once

#include <array>
#include <cstddef>
#include <cstdint>

namespace Zenith::Runtime
{

struct HostState
{
    static constexpr std::size_t declarations = 7;

    static constexpr int reflected_value = 264;

    static constexpr std::uint32_t threat_level = 0;

    static constexpr bool allow_extended_payload = false;
    static constexpr bool allow_branching = false;
    static constexpr bool allow_match = false;
    static constexpr bool allow_plugin = false;


    static constexpr std::array<std::uint8_t, 6> payload =
    {
        0xb8,
        0x08,
        0x01,
        0x00,
        0x00,
        0xc3
    };
};

}
