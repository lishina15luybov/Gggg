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
        /**
         * @brief Сгенерировать значение.
         * @return Всегда возвращает 0.
         */
        int generate() override;
    };
}
