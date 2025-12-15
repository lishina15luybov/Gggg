#include <stdio.h>
#include <stdlib.h> 

/** 
 * @brief Считывает значение, введенное с клавиатуры с проверкой ввода
 * @return считанное значение
 */
double value(void);

/** 
 * @brief Вычисляет квадрат или четвертую степень числа в зависимости от знака
 * @param num число для обработки
 * @return результат вычисления
 */
double process_number(double num);

/** 
 * @brief Точка входа в программу
 * @return возвращает 0, если программа выполнена корректно
 */
int main(void)
{
    double x = 0;
    double y = 0;
    double z = 0;
    printf("Введите три числа:\n");
    printf("Первое число: ");
    x = value();
    
    printf("Второе число: ");
    y = value();
    
    printf("Третье число: ");
    z = value();
    
    printf("\nВведенные значения:\n");
    printf("Первое: %.2lf\n", x);
    printf("Второе: %.2lf\n", y);
    printf("Третье: %.2lf\n", z);
    printf("\n");
    
    double result_x = process_number(x);
    printf("Результат 1: %.2lf\n\n", result_x);
    
    double result_y = process_number(y);
    printf("Результат 2: %.2lf\n\n", result_y);
    
    double result_z = process_number(z);
    printf("Результат 3: %.2lf\n\n", result_z);
    
    return 0;
}

double value(void)
{
    double input_value = 0;
    if (scanf("%lf", &input_value) != 1)
    {
        printf("Ошибка! Введено неверное значение!\n");
        abort();
    }
    return input_value;
}

double process_number(double num)
{
    if (num >= 0)
    {
        return num * num;
    }
    else
    {
        return num * num * num * num;
    }
}
