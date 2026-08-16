#pragma once

#include "../include/reflection_backend.hpp"
#include "../meta/reflection_traits.hpp"

#include "../../src/runtime/host_runtime.hpp"

#include <zenith_target.hpp>


namespace Zenith::Meta
{

class CPP23Backend final : public ReflectionBackend
{

public:

    std::string_view name() const override
    {
        return "CPP23Backend";
    }


    ReflectionReport inspect() const override
    {
        ReflectionReport report{};


        auto descriptor =
            ReflectionTraits<
                Zenith::Targets::SecurityPolicy
            >::descriptor();


        report.reflected_type =
            descriptor.name;


        report.reflected_members =
            descriptor.member_count;


        report.declaration_count =
            Zenith::Runtime::HostState::declarations;


        report.reflected_value =
            Zenith::Runtime::HostState::reflected_value;


        report.threat_level =
            Zenith::Runtime::HostState::threat_level;


        report.allow_extended_payload =
            Zenith::Runtime::HostState::allow_extended_payload;


        report.allow_branching =
            Zenith::Runtime::HostState::allow_branching;


        report.allow_match =
            Zenith::Runtime::HostState::allow_match;


        report.allow_plugin =
            Zenith::Runtime::HostState::allow_plugin;


        return report;
    }

};

}
