#pragma once
#include "Generator.h"

namespace miit::algebra
{
    /**
     * @brief Генератор нулей.
     */
    class ZeroGenerator : public Generator
    {
    public:
        int generate() override;
    };
}
