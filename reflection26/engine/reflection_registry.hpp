#pragma once

#include "../meta/reflection_descriptor.hpp"
#include "../meta/reflection_traits.hpp"

#include <array>
#include <cstddef>

namespace Zenith::Meta
{

template<std::size_t Capacity>
class ReflectionRegistry
{

private:

    std::array<ReflectionDescriptor, Capacity> entries{};


public:

    std::size_t count = 0;


    template<typename T>
    void register_type()
    {

        if (count >= Capacity)
            return;


        entries[count++] =
            ReflectionTraits<T>::descriptor();

    }


    const ReflectionDescriptor& operator[](std::size_t index) const
    {
        return entries[index];
    }

};

}
