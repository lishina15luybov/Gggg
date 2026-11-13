#include <iostream>
#include <limits>
#include <cstddef>
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

    void runTask1(const std::size_t rows, const std::size_t cols, Generator& gen)
    {
        std::cout << "\n--- Задача 1: заменить минимальный по модулю "
                     "элемент каждого столбца нулем ---\n";
        Task1 task1(rows, cols, gen);
        std::cout << "Исходная матрица:\n" << task1.toString();
        
        Exercise* exercise = &task1; 
        exercise->solve();
        
        std::cout << "Результат:\n" << task1.toString();
    }

public:
    void run()
    {
        setlocale(LC_ALL, "Russian");

        std::cout << "===== Задание 4.3, вариант 2 =====\n";

        std::size_t rows = 0;
        std::size_t cols = 0;
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

        switch (choice)
        {
        case CHOICE_RANDOM:
        {
            int minV = DEFAULT_MIN_VAL, maxV = DEFAULT_MAX_VAL;
            std::cout << "Введите min и max для случайных чисел: ";
            std::cin >> minV >> maxV;
            RandomGenerator gen(minV, maxV);
            runTask1(rows, cols, gen);
            break;
        }
        case CHOICE_KEYBOARD:
        {
            IStreamGenerator gen(std::cin);
            runTask1(rows, cols, gen);
            break;
        }
        case CHOICE_ZERO:
        {
            ZeroGenerator gen;
            runTask1(rows, cols, gen);
            break;
        }
        case CHOICE_CONST:
        {
            int v = 0;
            std::cout << "Введите константу: ";
            std::cin >> v;
            ConstantGenerator gen(v);
            runTask1(rows, cols, gen);
            break;
        }
        default:
        {
            std::cout << "Неверный выбор, используется генератор нулей.\n";
            ZeroGenerator gen;
            runTask1(rows, cols, gen);
            break;
        }
        }

        std::cout << "\n--- Задача 2: удалить столбцы, где первый элемент "
                     "больше последнего ---\n";

        Matrix<int> m2;
        m2.fill(rows, cols, 0);

        for (std::size_t i = 0; i < rows; ++i)
        {
            for (std::size_t j = 0; j < cols; ++j)
            {
                std::cout << "Элемент [" << i << "][" << j << "]: ";
                std::cin >> m2[i][j]; 
            }
        }

        Task2 task2(m2);
        std::cout << "Исходная матрица:\n" << task2.toString();
        
        Exercise* exercise2 = &task2;
        exercise2->solve();
        
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
