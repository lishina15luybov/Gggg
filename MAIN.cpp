#include <iostream>
#include <clocale>
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
    /**
     * @brief Пункт меню: заполнение матриц случайными числами.
     */
    static const int CHOICE_RANDOM = 1;

    /**
     * @brief Пункт меню: ввод элементов матриц с клавиатуры.
     */
    static const int CHOICE_KEYBOARD = 2;

    /**
     * @brief Пункт меню: заполнение матриц нулями.
     */
    static const int CHOICE_ZERO = 3;

    /**
     * @brief Пункт меню: заполнение матриц константным значением.
     */
    static const int CHOICE_CONST = 4;

    /**
     * @brief Нижняя граница диапазона случайных чисел по умолчанию.
     */
    static const int DEFAULT_MIN_VAL = -10;

    /**
     * @brief Верхняя граница диапазона случайных чисел по умолчанию.
     */
    static const int DEFAULT_MAX_VAL = 10;

    /**
     * @brief Выполнить задачу 1 (замена минимального по модулю элемента каждого столбца нулём).
     * @param rows Количество строк матрицы.
     * @param cols Количество столбцов матрицы.
     * @param gen Генератор значений для заполнения матрицы.
     */
    void runTask1(const std::size_t rows, const std::size_t cols, const Generator& gen);

    /**
     * @brief Выполнить задачу 2 (удаление столбцов, где первый элемент больше последнего).
     * @param rows Количество строк матрицы.
     * @param cols Количество столбцов матрицы.
     * @param gen Генератор значений для заполнения матрицы.
     */
    void runTask2(const std::size_t rows, const std::size_t cols, const Generator& gen);

    /**
     * @brief Последовательно выполнить обе задачи с использованием одного генератора.
     * @param rows Количество строк матриц.
     * @param cols Количество столбцов матриц.
     * @param gen Генератор значений для заполнения обеих матриц.
     */
    void runTasks(const std::size_t rows, const std::size_t cols, const Generator& gen);

public:
    /**
     * @brief Запустить основной сценарий работы приложения.
     */
    void run();
};

/**
 * @brief Точка входа в программу.
 * @return Код завершения программы (0 при успешном выполнении).
 */
int main()
{
    Application app;
    app.run();
    return 0;
}

void Application::runTask1(const std::size_t rows, const std::size_t cols, const Generator& gen)
{
    std::cout << "\n--- Задача 1: заменить минимальный по модулю "
                 "элемент каждого столбца нулем ---\n";
    Task1 task1(rows, cols, gen);
    std::cout << "Исходная матрица:\n" << task1.toString();

    Exercise& exercise = task1;
    exercise.solve();

    std::cout << "Результат:\n" << task1.toString();
}

void Application::runTask2(const std::size_t rows, const std::size_t cols, const Generator& gen)
{
    std::cout << "\n--- Задача 2: удалить столбцы, где первый элемент "
                 "больше последнего ---\n";
    Task2 task2(rows, cols, gen);
    std::cout << "Исходная матрица:\n" << task2.toString();

    Exercise& exercise = task2;
    exercise.solve();

    std::cout << "Результат:\n" << task2.toString();
}

void Application::runTasks(const std::size_t rows, const std::size_t cols, const Generator& gen)
{
    runTask1(rows, cols, gen);
    runTask2(rows, cols, gen);
}

void Application::run()
{
    setlocale(LC_ALL, "Russian");

    std::cout << "===== Задание 4.3, вариант 2 =====\n";

    std::size_t rows = 0;
    std::size_t cols = 0;
    std::cout << "Введите количество строк и столбцов: ";
    std::cin >> rows >> cols;

    std::cout << "Выберите способ заполнения матриц:\n"
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
        int minV = DEFAULT_MIN_VAL;
        int maxV = DEFAULT_MAX_VAL;
        std::cout << "Введите min и max для случайных чисел: ";
        std::cin >> minV >> maxV;
        RandomGenerator gen(minV, maxV);
        runTasks(rows, cols, gen);
        break;
    }
    case CHOICE_KEYBOARD:
    {
        std::cout << "Введите элементы матриц:\n";
        IStreamGenerator gen(std::cin);
        runTasks(rows, cols, gen);
        break;
    }
    case CHOICE_ZERO:
    {
        ZeroGenerator gen;
        runTasks(rows, cols, gen);
        break;
    }
    case CHOICE_CONST:
    {
        int v = 0;
        std::cout << "Введите константу: ";
        std::cin >> v;
        ConstantGenerator gen(v);
        runTasks(rows, cols, gen);
        break;
    }
    default:
    {
        std::cout << "Неверный выбор, используется генератор нулей.\n";
        ZeroGenerator gen;
        runTasks(rows, cols, gen);
        break;
    }
    }

    std::cout << "\nТест операторов сдвига:\n";
    ZeroGenerator zeroGen;
    Task1 shiftDemo(rows, cols, zeroGen);
    std::cout << "До сдвига:\n" << shiftDemo.toString();
}
