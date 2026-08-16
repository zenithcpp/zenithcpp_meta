#pragma once

#include "capabilities.hpp"

#include <array>
#include <cstddef>
#include <initializer_list>
#include <string_view>

namespace Zenith
{

class Agent
{

public:

    std::string_view name{};

    std::array<Capability, 8> capabilities{};

    std::size_t capability_count = 0;


    Agent() = default;


    Agent(
        std::string_view agent_name,
        std::initializer_list<Capability> caps
    )
        : name(agent_name)
    {
        for (auto cap : caps)
        {
            if (capability_count < capabilities.size())
            {
                capabilities[capability_count++] = cap;
            }
        }
    }

};



template<std::size_t Capacity>
class Registry
{

public:

    std::array<Agent, Capacity> agents{};

    std::size_t count = 0;


    void register_agent(const Agent& agent)
    {
        if (count >= Capacity)
            return;

        agents[count++] = agent;
    }

};

}

