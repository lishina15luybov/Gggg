#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <float.h>
/*
*@brief Рассчитывает значение функции по заданным условиям
*@param x входное значение аргумента
*@return возвращает рассчитанное значение выбранной функции
*/
double func(const double x);
/*
*@brief Считывает значение, введенное с клавиатуру с проверкой ввода
*@return считанное значение
*/
double value();
/*
*@brief Точка входа в программу
*@param x выбранный пользователем значение аргумента
*@return Возвращает 0, если программа выполнена корректно
*/
int main()
{
    printf("Программа для решения функции y:\n");
    printf("y = a * x^(2) + 4, при x < 1.2 \n");
    printf("y = (a + 4*x) * ((x^(2*a))^(1/2)), при x >= 1.2\n");
    printf("Константа a = 2.8\n\n");
    printf("Введите значение:");
    double x = value();
    double result = func(x);
    printf("Результат: y(%.2f) = %.2f\n", x, result);
    return 0;

}

double func(const double x)
{
    const double a = 2.8;
    if (x < 1.2 + DBL_EPSILON)
    {
        return a * pow(x, 2) + 4;
    }
    else 
    {
        return (a + 4 * x) * sqrt(pow(x, (2 * a))) ;
    }
}

double value()
{
    double value = 0;
    if (!scanf("%lf",&value))
    {
        printf("Ошибка! Введено неверное значение!\n");

        abort();
    }
    return value;
}
