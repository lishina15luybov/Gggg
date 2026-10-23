#pragma once
#include "Generator.h"
#include <istream>

namespace miit::algebra
{
    /**
     * @brief Генератор, читающий значения из потока ввода.
     */
    class IStreamGenerator : public Generator
    {
    private:
        std::istream& in;

    public:
        IStreamGenerator(std::istream& in);
        int generate() override;
    };
}
