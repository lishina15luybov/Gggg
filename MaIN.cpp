#include <iostream>
#include <memory>
#include <limits>
#include "Task1.h"
#include "Task2.h"
#include "RandomGenerator.h"
#include "IStreamGenerator.h"
#include "ZeroGenerator.h"
#include "ConstantGenerator.h"

using namespace miit::algebra;

/**
 * @brief Выбор генератора пользователем.
 */
std::unique_ptr<Generator> chooseGenerator()
{
    std::cout << "Выберите способ заполнения матрицы:\n"
              << "  1 - случайными числами\n"
              << "  2 - с клавиатуры\n"
              << "  3 - нулями\n"
              << "  4 - константным значением\n"
              << "Ваш выбор: ";

    int choice = 0;
    std::cin >> choice;

    switch (choice)
    {
    case 1:
    {
        int minV = -10, maxV = 10;
        std::cout << "Введите min и max для случайных чисел: ";
        std::cin >> minV >> maxV;
        return std::make_unique<RandomGenerator>(minV, maxV);
    }
    case 2:
        return std::make_unique<IStreamGenerator>(std::cin);
    case 3:
        return std::make_unique<ZeroGenerator>();
    case 4:
    {
        int v = 0;
        std::cout << "Введите константу: ";
        std::cin >> v;
        return std::make_unique<ConstantGenerator>(v);
    }
    default:
        std::cout << "Неверный выбор, используется генератор нулей.\n";
        return std::make_unique<ZeroGenerator>();
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");

    std::cout << "===== Задание 4.3, вариант 2 =====\n";

    int rows = 0, cols = 0;
    std::cout << "Введите количество строк и столбцов: ";
    std::cin >> rows >> cols;

    auto generator = chooseGenerator();

    std::cout << "\n--- Задача 1: заменить минимальный по модулю "
                 "элемент каждого столбца нулем ---\n";
    Task1 task1(rows, cols, *generator);
    std::cout << "Исходная матрица:\n" << task1.toString();
    task1.solve();
    std::cout << "Результат:\n" << task1.toString();
    std::cout << "\n--- Задача 2: удалить столбцы, где первый элемент "
                 "больше последнего ---\n";

    Matrix<int> m2(rows, cols);
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
        {
            std::cout << "Элемент [" << i << "][" << j << "]: ";
            std::cin >> m2(i, j);
        }

    Task2 task2(m2);
    std::cout << "Исходная матрица:\n" << task2.toString();
    task2.solve();
    std::cout << "Результат:\n" << task2.toString();

    std::cout << "\nТест операторов сдвига:\n";
    Task1 shiftDemo(rows, cols, *std::make_unique<ZeroGenerator>());
    std::cout << "До сдвига:\n" << shiftDemo.toString();

    return 0;
}
