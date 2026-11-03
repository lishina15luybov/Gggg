#include <iostream>
#include <limits>
#include "Task1.h"
#include "Task2.h"
#include "RandomGenerator.h"
#include "IStreamGenerator.h"
#include "ZeroGenerator.h"
#include "ConstantGenerator.h"

using namespace miit::algebra;

/**
 * @brief Класс приложения, инкапсулирующий логику работы.
 */
class Application
{
private:
    static const int CHOICE_RANDOM = 1;
    static const int CHOICE_KEYBOARD = 2;
    static const int CHOICE_ZERO = 3;
    static const int CHOICE_CONST = 4;
    
    static const int DEFAULT_MIN_VAL = -10;
    static const int DEFAULT_MAX_VAL = 10;

public:
    /**
     * @brief Точка входа в логику приложения.
     */
    void run()
    {
        setlocale(LC_ALL, "Russian");

        std::cout << "===== Задание 4.3, вариант 2 =====\n";

        int rows = 0, cols = 0;
        std::cout << "Введите количество строк и столбцов: ";
        std::cin >> rows >> cols;

        std::cout << "Выберите способ заполнения матрицы:\n"
                  << "  " << CHOICE_RANDOM << " - случайными числами\n"
                  << "  " << CHOICE_KEYBOARD << " - с клавиатуры\n"
                  << "  " << CHOICE_ZERO << " - нулями\n"
                  << "  " << CHOICE_CONST << " - константным значением\n"
                  << "Ваш выбор: ";

        int choice = 0;
        std::cin >> choice;

        std::cout << "\n--- Задача 1: заменить минимальный по модулю "
                     "элемент каждого столбца нулем ---\n";

        if (choice == CHOICE_RANDOM)
        {
            int minV = DEFAULT_MIN_VAL, maxV = DEFAULT_MAX_VAL;
            std::cout << "Введите min и max для случайных чисел: ";
            std::cin >> minV >> maxV;
            RandomGenerator gen(minV, maxV);
            Task1 task1(rows, cols, gen);
            std::cout << "Исходная матрица:\n" << task1.toString();
            task1.solve();
            std::cout << "Результат:\n" << task1.toString();
        }
        else if (choice == CHOICE_KEYBOARD)
        {
            IStreamGenerator gen(std::cin);
            Task1 task1(rows, cols, gen);
            std::cout << "Исходная матрица:\n" << task1.toString();
            task1.solve();
            std::cout << "Результат:\n" << task1.toString();
        }
        else if (choice == CHOICE_ZERO)
        {
            ZeroGenerator gen;
            Task1 task1(rows, cols, gen);
            std::cout << "Исходная матрица:\n" << task1.toString();
            task1.solve();
            std::cout << "Результат:\n" << task1.toString();
        }
        else if (choice == CHOICE_CONST)
        {
            int v = 0;
            std::cout << "Введите константу: ";
            std::cin >> v;
            ConstantGenerator gen(v);
            Task1 task1(rows, cols, gen);
            std::cout << "Исходная матрица:\n" << task1.toString();
            task1.solve();
            std::cout << "Результат:\n" << task1.toString();
        }
        else
        {
            std::cout << "Неверный выбор, используется генератор нулей.\n";
            ZeroGenerator gen;
            Task1 task1(rows, cols, gen);
            std::cout << "Исходная матрица:\n" << task1.toString();
            task1.solve();
            std::cout << "Результат:\n" << task1.toString();
        }

        std::cout << "\n--- Задача 2: удалить столбцы, где первый элемент "
                     "больше последнего ---\n";

        Matrix<int> m2(rows, cols);
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                std::cout << "Элемент [" << i << "][" << j << "]: ";
                std::cin >> m2[i][j]; 
            }
        }

        Task2 task2(m2);
        std::cout << "Исходная матрица:\n" << task2.toString();
        task2.solve();
        std::cout << "Результат:\n" << task2.toString();

        std::cout << "\nТест операторов сдвига:\n";
        ZeroGenerator zeroGen;
        Task1 shiftDemo(rows, cols, zeroGen);
        std::cout << "До сдвига:\n" << shiftDemo.toString();
    }
};

int main()
{
    Application app;
    app.run();
    return 0;
}
