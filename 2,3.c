#include <stdio.h>
#include <stdlib.h> 
/** 
*@brief Считывает значение, введенное с клавиатуру с проверкой ввода
*@return считанное значение
*/
double value();

/** 
*@brief Точка входа в программу
*@param x введенное значение пользователем
*@param y введенное значение пользователем
*@param z введенное значение пользователем
*@return вовзвращает 0, если программа выполнена корректно
*/
int main()
{
    double x = 0;
    scanf("%lf",&x);
    double y = 0;
    scanf("%lf",&y);
    double z = 0;
    scanf("%lf",&z);
    printf("значение первое %.2lf\n", x);
    printf("значение второе %.2lf\n", y);
    printf("значение третье %.2lf\n", z);
    if (x >= 0)
    {
        double result = x * x;
        printf("Число %.2lf (неотрицательное)\n", x);
        printf("Результат: %.2lf^2 = %.2lf\n\n", x, result);
    }
    else
    {
        double result = x * x * x * x;
        printf("Число %.2lf (отрицательное)\n", x);
        printf("Результат: (%.2lf)^4 = %.2lf\n\n", x, result);
    }
    if (y >= 0)
    {
        double result = y * y;
        printf("Число %.2lf (неотрицательное)\n", y);
        printf("Результат: %.2lf^2 = %.2lf\n\n", y, result);
    }
    else
    {
        double result = y * y * y * y;
        printf("Число %.2lf (отрицательное)\n", y);
        printf("Результат: (%.2lf)^4 = %.2lf\n\n", y, result);
    }
    if (z >= 0)
    {
        double result = z * z;
        printf("Число %.2lf (неотрицательное)\n", z);
        printf("Результат: %.2lf^2 = %.2lf\n\n", z, result);
    }
    else
    {
        double result = z * z * z * z;
        printf("Число %.2lf (отрицательное)\n", z);
        printf("Результат: (%.2lf)^4 = %.2lf\n\n", z, result);
    }
    
    return 0;
    

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
