#pragma once
#include "Generator.h"
#include <random>

namespace miit::algebra
{
    /**
     * @brief Генератор случайных чисел.
     */
    class RandomGenerator : public Generator
    {
    private:
        std::uniform_int_distribution<int> distribution;
        std::mt19937 generator;

    public:
        /**
         * @brief Конструктор с диапазоном случайных чисел.
         * @param min Минимальное значение.
         * @param max Максимальное значение.
         */
        RandomGenerator(const int min, const int max);

        /**
         * @brief Сгенерировать случайное значение.
         * @return Случайное число.
         */
        int generate() override;
    };
}
