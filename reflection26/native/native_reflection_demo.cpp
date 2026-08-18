#include "native_reflection.hpp"

#include <zenith_target.hpp>

#include <iostream>


int main()
{
    Zenith::Targets::SecurityPolicy policy
    {
        .threat_level = 264,
        .allow_extended_payload = false,
        .allow_branching = true,
        .allow_match = true,
        .allow_plugin = false
    };


    const auto reflected =
        Zenith::NativeReflection::inspect(policy);


    std::cout
        << "ZENITH NATIVE REFLECTION ENGINE\n\n";


    std::cout
        << "Type: "
        << reflected.type_name
        << "\n";


    std::cout
        << "Size: "
        << reflected.size
        << "\n";


    std::cout
        << "Alignment: "
        << reflected.alignment
        << "\n";


    std::cout
        << "Members: "
        << reflected.members.size()
        << "\n\n";


    for (const auto& member : reflected.members)
    {
        std::cout
            << member.name
            << "\n"
            << "  type: "
            << member.type_name
            << "\n"
            << "  size: "
            << member.size
            << "\n"
            << "  alignment: "
            << member.alignment
            << "\n"
            << "  offset: "
            << member.offset
            << "\n"
            << "  value: "
            << member.value
            << "\n\n";
    }


    return 0;
}
