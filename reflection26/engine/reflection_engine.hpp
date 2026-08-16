#pragma once

#include "../include/reflection_backend.hpp"
#include "../backends/cpp23_backend.hpp"
#include "../backends/cpp26_backend.hpp"

#include <memory>
#include <string_view>

namespace Zenith::Meta
{

class ReflectionEngine
{

private:

    std::unique_ptr<ReflectionBackend> backend;


public:

    ReflectionEngine()
    {

#if defined(__cpp_reflection)

        backend =
            std::make_unique<CPP26Backend>();

#else

        backend =
            std::make_unique<CPP23Backend>();

#endif

    }


    ReflectionReport inspect() const
    {
        return backend->inspect();
    }


    std::string_view backend_name() const
    {
        return backend->name();
    }

};

}
