#pragma once

namespace miit::algebra
{
    /**
     * @brief Абстрактный класс генератора значений.
     */
    class Generator
    {
    public:
        /**
         * @brief Виртуальный деструктор.
         */
        virtual ~Generator() = default;

        /**
         * @brief Сгенерировать значение.
         * @return Сгенерированное значение.
         */
        virtual int generate() = 0;
    };
}
