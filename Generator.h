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
        virtual ~Generator() = 0;

        /**
         * @brief Сгенерировать значение.
         */
        virtual int generate() = 0;
    };
}
