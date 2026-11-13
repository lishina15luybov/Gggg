#include "ConstantGenerator.h"

namespace miit::algebra
{
    /**
     * @brief Конструктор с константным значением.
     * @param value Значение, которое будет возвращать генератор.
     */
    ConstantGenerator::ConstantGenerator(const int value) : value{value} {}

    /**
     * @brief Сгенерировать значение.
     * @return Константное значение.
     */
    int ConstantGenerator::generate() { return value; }
}
