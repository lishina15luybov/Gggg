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
        /**
         * @brief Конструктор с константным значением.
         * @param value Значение, которое будет возвращать генератор.
         */
        explicit ConstantGenerator(const int value);

        /**
         * @brief Сгенерировать значение.
         * @return Константное значение.
         */
        int generate() override;
    };
}
