#define _USE_MATH_DEFINES // for C
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * @brief рассчитывает площадь трапеции
 * @param side1 верхнее основание трапеции
 * @param side2 нижнее основание трапеции
 * @param side3 выстоа трапеции
 * @return возвращает рассчитанную площадь
 */
double getSquare1(const double side1, const double side2, const double side3);

/**
 * @brief рассчитывает площадь круга
 * @param side4 радиус круга
 * @return возвращает рассчитанную площадь
 */
double getSquare2(const double side4);

/**
 * @brief считывает значение, 
 * введенное с клавиатуры с проверкой ввода
 * @return считанное значение
 */
double getValue();

/**
 * @brief проверяет,что переменная положительная
 * @param value значение проверяемой переменной
 */
void checkValue(const double value);

/**
 * @brief Точка входа в программу
 * @return возвращает 0, если программма выполнена корректно
 */
int main(void)
{
    printf("Введите верхнее основание, нижнее основание и высоту трапеции: ");
    double side1 = getValue();
    checkValue(side1);
    double side2 = getValue();
    checkValue(side2);
    double side3 = getValue();
    checkValue(side3);
    printf("Введите радиус круга: ");
    double side4 = getValue();
    checkValue(side4);
    printf("Площадь трапеции равна %.2lf",getSquare1(side1, side2, side3));
    printf("Площадь круга равна %.2lf",getSquare2(side4));

    return 0;
}

double getSquare1(const double side1, const double side2, const double side3)
{
    return ((side1 + side2) * side3) / 2;
}

double getSquare2(const double side4)
{
    return M_PI * (double)pow(side4, 2);
}

double getValue()
{
    double value = 0;
    if (!scanf("%lf",&value))
    {
        printf("Error\n");
        abort();
    }
    return value;
}

void checkValue(const double value)
{
    if (value <= 0 )
    {
        printf("Value have to be positive\n");
        abort();
    }
}
