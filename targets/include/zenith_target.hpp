#pragma once

#include <cstdint>

namespace Zenith::Targets
{

struct SecurityPolicy
{
    std::uint32_t threat_level = 0;

    bool allow_extended_payload = false;
    bool allow_branching = false;
    bool allow_match = false;
    bool allow_plugin = false;
};


struct ReflectionPayload
{
    int value = 264;
};

}
