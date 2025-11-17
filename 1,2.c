#define _USE_MATH_DEFINES // for C
#include <stdio.h>
#include <math.h>
/**
 * @brief рассчитывает объем шара
 * @param side радиус шара
 * @return возвращает рассчитанный объем
 */
double getVolume (const double side);
/**
 * @brief рассчитывает площадь поверхности шара
 * @param side радиус шара
 * @return возвращает рассчитанную площадь поверхности
 */
double getSquare (const double side);
/**
 * @brief точка входа в программу
 * @return возвращает 0, если программма выполнена корректно
 */
int main(void)
{
    double side;
    scanf("%lf",&side);
    printf("радиус равен %.2lf\n", side);
    printf("объем равен %.2lf",getVolume(side));
    printf("площадь поверхности равна %.2lf",getSquare(side));

    return 0;
}
double getVolume (const double side)
{
    return 4/3 * M_PI * (double)pow(side, 3);
}
double getSquare (const double side)
{
    return 4 * M_PI * (double)pow(side, 2);
}
