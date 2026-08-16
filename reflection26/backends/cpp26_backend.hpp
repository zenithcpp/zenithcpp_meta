#pragma once

#include "../include/reflection_backend.hpp"

#include <string_view>

namespace Zenith::Meta
{

class CPP26Backend final : public ReflectionBackend
{

public:

    std::string_view name() const override
    {
        return "CPP26Backend";
    }


    ReflectionReport inspect() const override
    {
        ReflectionReport report{};


#if defined(__cpp_reflection)

        report.reflected_type =
            "native-cpp26-reflection";


#else

        report.reflected_type =
            "cpp26-reflection-unavailable";


#endif


        return report;
    }

};

}
