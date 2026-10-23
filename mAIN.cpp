#include <iostream>
#include <vector>
#include <memory>
#include "Vector2D.h"

using namespace VectorLib;

/**
 * @brief Точка входа в программу
 * @return 0 при успешном выполнении
 */
int main() {
    std::cout << "=== Демонстрация работы с векторами на плоскости ===" << std::endl;
    std::cout << std::endl;

    std::vector<std::unique_ptr<Vector>> vectors;

    std::cout << "1. Создание вектора через две точки:" << std::endl;
    Point p1(1, 2);
    Point p2(4, 6);
    vectors.push_back(std::make_unique<Vector2D>(p1, p2));
    std::cout << "   Вектор v1: " << *vectors.back() << std::endl;

    std::cout << "\n2. Создание вектора через пары чисел:" << std::endl;
    vectors.push_back(std::make_unique<Vector2D>(0, 0, 3, 4));
    std::cout << "   Вектор v2: " << *vectors.back() << std::endl;

    std::cout << "\n3. Создание вектора (0,0)->(5,5):" << std::endl;
    vectors.push_back(std::make_unique<Vector2D>(0, 0, 5, 5));
    std::cout << "   Вектор v3: " << *vectors.back() << std::endl;

    std::cout << "\n=== Операции с векторами ===" << std::endl;

    Vector2D a(0, 0, 2, 0);
    Vector2D b(0, 0, 0, 2);
    Vector2D c(0, 0, 3, 4);

    std::cout << "\nВектор a: " << a << std::endl;
    std::cout << "Вектор b: " << b << std::endl;
    std::cout << "Вектор c: " << c << std::endl;

    std::cout << "\nУгол между a и b: " << Vector::angleBetween(a, b) 
              << " рад (" << Vector::angleBetween(a, b) * 180 / 3.14159 << "°)" << std::endl;

    std::cout << "Угол между a и c: " << Vector::angleBetween(a, c) 
              << " рад (" << Vector::angleBetween(a, c) * 180 / 3.14159 << "°)" << std::endl;

    Vector2D sum = a + b;
    std::cout << "\na + b = " << sum << std::endl;

    Vector2D diff = b - a;
    std::cout << "b - a = " << diff << std::endl;

    Vector2D scaled = a * 2.5;
    std::cout << "a * 2.5 = " << scaled << std::endl;

    Vector2D d(0, 0, 2, 0);
    std::cout << "\na == d? " << (a == d ? "Да" : "Нет") << std::endl;
    std::cout << "a == b? " << (a == b ? "Да" : "Нет") << std::endl;

    std::cout << "\n=== Коллекция векторов ===" << std::endl;
    for (size_t i = 0; i < vectors.size(); ++i) {
        std::cout << i + 1 << ". " << *vectors[i] << std::endl;
    }

    std::cout << "\n=== Статический метод чтения ===" << std::endl;
    std::cout << "Введите координаты вектора (x1 y1 x2 y2): ";
    Vector2D v = Vector2D::readFromStream(std::cin);
    std::cout << "Вы ввели вектор: " << v << std::endl;

    return 0;
}

/**
 * @brief Выводит ошибку и завершает программу
 * @param text текст ошибки
 */
void error(const std::string& text) {
    std::cerr << "Ошибка: " << text << std::endl;
    exit(1);
}

/**
 * @brief Считывает целое число с клавиатуры
 * @return введенное число
 */
int getChoice() {
    int number = 0;
    std::cin >> number;
    if (std::cin.fail()) {
        error("Неверный ввод числа");
    }
    return number;
}
