#include <math.h>
#include <stdio.h>
/**
 * @brief рассчитывает функцию a по заданной формуле 
 * @brief рассчитывает функцию b по заданной формуле
 * @param x - значение параметра x
 * @param y - значение параметра y
 * @return рассчитанное значение
 */
double geta(const double x);
double getb(const double x, const double y);
int main (void) 
{
    const double x = 0.335;
    const double y = 0.025;
    printf("a - %.4f \n", geta(x));
    printf("b - %.4f \n", getb(x, y));
    return 0;
}
double geta(const double x)
{
    return 1 + x + (double)pow(x,2)/2 + (double)pow(x,3)/3 + (double)pow(x,4)/4;
}
double getb(const double x, const double y)
{
    return x*(sin((double)pow(x,3)) + (double)pow(cos(y),2));
}
