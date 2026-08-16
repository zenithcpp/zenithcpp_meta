#include <iostream>

#include "../reflection26/engine/reflection_engine.hpp"
#include "../reflection26/engine/reflection_registry.hpp"

#include "../brain/orchestrator/registry.hpp"

#include "runtime/host_runtime.hpp"

#include <zenith_target.hpp>


int main()
{
    std::cout
        << "ZENITH META RUNTIME\n\n";


    Zenith::Registry<8> brain{};


    brain.register_agent(
        Zenith::Agent(
            "ThreatHunt",
            {Zenith::Capability::ThreatDetection}
        )
    );


    brain.register_agent(
        Zenith::Agent(
            "PolicyEnforcer",
            {Zenith::Capability::PolicyEnforcement}
        )
    );


    brain.register_agent(
        Zenith::Agent(
            "ReflectionAgent",
            {
                Zenith::Capability::ReflectionPing,
                Zenith::Capability::ActionExecution
            }
        )
    );


    Zenith::Meta::ReflectionEngine reflection{};

    auto report =
        reflection.inspect();


    Zenith::Meta::ReflectionRegistry<8> registry{};

    registry.register_type<Zenith::Targets::SecurityPolicy>();

    registry.register_type<Zenith::Targets::ReflectionPayload>();


    std::cout
        << "Backend: "
        << reflection.backend_name()
        << "\n";


    std::cout
        << "Agents: "
        << brain.count
        << "\n";


    std::cout
        << "Reflection types: "
        << registry.count
        << "\n";


    for (std::size_t i = 0; i < registry.count; ++i)
    {
        std::cout
            << "  "
            << registry[i].name
            << " members="
            << registry[i].member_count
            << "\n";
    }


    std::cout
        << "\nReflection report\n";


    std::cout
        << "Declarations: "
        << report.declaration_count
        << "\n";


    std::cout
        << "Entity: "
        << report.reflected_type
        << "\n";


    std::cout
        << "Members: "
        << report.reflected_members
        << "\n";


    std::cout
        << "Value: "
        << report.reflected_value
        << "\n";


    std::cout
        << "Threat: "
        << report.threat_level
        << "\n";


    std::cout
        << "\nPayload bytes: ";

    for (auto byte : Zenith::Runtime::HostState::payload)
    {
        std::printf("%02x ", byte);
    }

    std::cout << "\n";


    return 0;
}
