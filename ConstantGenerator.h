#pragma once
#include "Generator.h"

namespace miit::algebra
{
    /**
     * @brief Генератор константного значения.
     */
    class ConstantGenerator : public Generator
    {
    private:
        int value;

    public:
        explicit ConstantGenerator(const int value);
        int generate() override;
    };
}
