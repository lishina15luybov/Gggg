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
        /**
         * @brief Ссылка на поток ввода.
         */
        std::istream& in;

    public:
        /**
         * @brief Конструктор с потоком ввода.
         * @param in Поток ввода.
         */
        IStreamGenerator(std::istream& in);

        /**
         * @brief Сгенерировать значение из потока.
         * @return Считанное значение.
         */
        int generate() override;
    };
}
