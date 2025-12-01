#define _USE_MATH_DEFINES // for C
#include <stdio.h>
#include <math.h>
/
 * @brief рассчитывает сопротивление соединения
 * @param r1 сопротивление резистора 1
 * @param r2 сопротивление резистора 2
 * @param r3 сопротивление резистора 3
 * @return возвращает рассчитанное значение сопртивления
 */
double getR(const double r1, const double r2, const double r3);
/
 * @brief точка входа в программу
 * @return возвращает 0, если программма выполнена корректно
 */
int main(void)
{
    double r1 = 0;
    scanf("%lf",&r1);
    double r2 = 0;
    scanf("%lf",&r2);
    double r3 = 0;
    scanf("%lf",&r3);
    printf("сопротивление первого резистора равно %.2lf\n", r1);
    printf("сопротивление второго резистора равно %.2lf\n", r2);
    printf("сопротивление третьего резистора равно %.2lf\n", r3);
    printf("сопротивление равно %.2lf", getR(r1, r2, r3));

    return 0;
}
double getR(const double r1, const double r2, const double r3)
{
    return (r1 * r2 * r3)/((r1 * r2)+(r2 * r3)+(r1 * r3));
}
