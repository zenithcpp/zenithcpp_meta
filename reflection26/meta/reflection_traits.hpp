#pragma once

#include "reflection_descriptor.hpp"

#include <zenith_target.hpp>

namespace Zenith::Meta
{

template<typename T>
struct ReflectionTraits
{
    static constexpr ReflectionDescriptor descriptor()
    {
        return {};
    }
};


template<>
struct ReflectionTraits<Zenith::Targets::SecurityPolicy>
{
private:

    inline static constexpr MemberDescriptor members[] =
    {
        {
            1,
            "threat_level",
            1,
            sizeof(std::uint32_t),
            alignof(std::uint32_t)
        },
        {
            2,
            "allow_extended_payload",
            2,
            sizeof(bool),
            alignof(bool)
        },
        {
            3,
            "allow_branching",
            2,
            sizeof(bool),
            alignof(bool)
        },
        {
            4,
            "allow_match",
            2,
            sizeof(bool),
            alignof(bool)
        },
        {
            5,
            "allow_plugin",
            2,
            sizeof(bool),
            alignof(bool)
        }
    };


public:

    static constexpr ReflectionDescriptor descriptor()
    {
        return {
            1,
            "SecurityPolicy",
            sizeof(Zenith::Targets::SecurityPolicy),
            alignof(Zenith::Targets::SecurityPolicy),
            members,
            5
        };
    }
};


template<>
struct ReflectionTraits<Zenith::Targets::ReflectionPayload>
{
private:

    inline static constexpr MemberDescriptor members[] =
    {
        {
            1,
            "value",
            3,
            sizeof(int),
            alignof(int)
        }
    };


public:

    static constexpr ReflectionDescriptor descriptor()
    {
        return {
            2,
            "ReflectionPayload",
            sizeof(Zenith::Targets::ReflectionPayload),
            alignof(Zenith::Targets::ReflectionPayload),
            members,
            1
        };
    }
};


}
