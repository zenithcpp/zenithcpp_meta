#include "native_reflection.hpp"

#include <meta>

#include <zenith_target.hpp>

#include <iostream>
#include <string>
#include <type_traits>


namespace Zenith::NativeReflection
{

namespace detail
{

template<class T>
std::string value_string(T& value)
{
    if constexpr (std::is_same_v<T, bool>)
    {
        return value ? "true" : "false";
    }
    else if constexpr (std::is_integral_v<T>)
    {
        return std::to_string(value);
    }
    else if constexpr (std::is_floating_point_v<T>)
    {
        return std::to_string(value);
    }
    else
    {
        return "<unsupported>";
    }
}


template<class T>
ReflectedObject inspect_impl(T& object)
{
    ReflectedObject result{};

    constexpr auto type =
        ^^T;


    result.type_name =
        std::meta::display_string_of(type);

    result.size =
        std::meta::size_of(type);

    result.alignment =
        std::meta::alignment_of(type);


    /*
     * GCC 16 requires the reflected range to have
     * stable storage before it can be consumed by
     * `template for`.
     */
    static constexpr auto members =
        std::define_static_array(
            std::meta::nonstatic_data_members_of(
                type,
                std::meta::access_context::unchecked()
            )
        );


    template for (constexpr auto member : members)
    {
        ReflectedMember descriptor{};


        descriptor.name =
            std::meta::identifier_of(member);


        constexpr auto member_type =
            std::meta::type_of(member);


        descriptor.type_name =
            std::meta::display_string_of(
                member_type
            );


        descriptor.size =
            std::meta::size_of(member_type);


        descriptor.alignment =
            std::meta::alignment_of(
                member_type
            );


        descriptor.offset =
            std::meta::offset_of(member).bytes;


        descriptor.value =
            value_string(
                object.[:member:]
            );


        result.members.push_back(
            std::move(descriptor)
        );
    }


    return result;
}


} // namespace detail


template<class T>
ReflectedObject inspect(T& object)
{
    return detail::inspect_impl(object);
}


template ReflectedObject
inspect<Zenith::Targets::SecurityPolicy>(
    Zenith::Targets::SecurityPolicy&
);


} // namespace Zenith::NativeReflection


