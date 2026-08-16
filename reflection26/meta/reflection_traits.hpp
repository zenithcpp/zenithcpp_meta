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
    static constexpr ReflectionDescriptor descriptor()
    {
        return {
            "SecurityPolicy",
            5
        };
    }
};


template<>
struct ReflectionTraits<Zenith::Targets::ReflectionPayload>
{
    static constexpr ReflectionDescriptor descriptor()
    {
        return {
            "ReflectionPayload",
            1
        };
    }
};

}
