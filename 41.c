#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define scanf_s scanf

/**
 * @brief Проверяет указатель на NULL
 * @param ptr указатель для проверки
 * @param func_name имя функции, в которой выполняется проверка
 */
void check_null_pointer(const void* ptr, const char* func_name);

/**
 * @brief Считывает введённое с клавиатуры целое значение и проверяет на правильность ввода
 * @return введённое значение
 */
int Value(void);

/**
 * @brief Выводит текстовое сообщение о необходимости ввода размера массива, проверяет ввод на правильность, задаёт размер массива
 * @param message текстовое сообщение о необходимости ввода массива
 * @return размер массива (количество его элементов)
 */
size_t getSize(const char* message);

/**
 * @brief Считывает значения элементов массива
 * @param arr массив
 * @param size размер массива
 */
void fillArray(int* arr, const size_t size);

/**
 * @brief Выводит массив (его элементы)
 * @param arr массив
 * @param size размер массива
 */
void printArray(const int* arr, const size_t size);

/**
 * @brief Вычисляет сумму чётных элементов массива
 * @param arr массив
 * @param size размер массива
 */
void sumEven(const int* arr, const size_t size);

/**
 * @brief Заполняет массив случайными числами в пределах введённого пользователем диапазона
 * @param arr массив
 * @param size размер массива
 */
void fillRandom(int* arr, const size_t size);

/**
 * @brief Создаёт копию массива
 * @param arr массив
 * @param size размер массива
 * @return полученный массив
 */
int* copyArray(const int* arr, const size_t size);

/**
 * @brief Заменяет крайний отрицательный элемент массива на модуль первого элемента
 * @param copyArr копия массива
 * @param size размер массива
 * @return Возвращает 1, если функция выполнена корректно, 0 - если в массиве отсутствуют отрицательные элементы
 */
int replaceFirstAbsLastNegative(int* copyArr, const size_t size);

/**
 * @brief Считает количество двузначных элементов массива
 * @param arr массив
 * @param size размер массива
 */
void countTwoDigitNumbers(const int* arr, const size_t size);

/**
 * @brief RANDOM - заполнение массива случайными числами в пределах введённого пользователем диапазона
 * @brief MANUAL - заполнение массива вручную
 */
enum {RANDOM = 1, MANUAL};

/**
 * @brief выделяет память для массива целых чисел
 * @param size размер массива
 */
int* allocate_int_array_with_check(const size_t size);

/**
 * @brief Точка входа в программу
 * @return 0, если программа выполнена корректно, иначе 1.
 */
int main(void)
{
    size_t size = getSize("Input size of an array:\n");
    int* my_array = allocate_int_array_with_check(size);
    printf("Chose the method of filling the array:\n%d - by random\n%d - manually\n", RANDOM, MANUAL);
    int choice = Value();
    switch(choice)
        {
            case RANDOM:
                fillRandom(my_array, size);
                break;
            case MANUAL:
                fillArray(my_array, size);
                break;
            default:
                fprintf(stderr,"Error.");
                free(my_array);
                exit(1);
        }
    printArray(my_array, size);
    printf("\n");
    sumEven(my_array, size);
    printf("\n");
    countTwoDigitNumbers(my_array, size);
    printf("\n");
    int* copyArr = copyArray(my_array, size);
    replaceFirstAbsLastNegative(copyArr, size);
    free(copyArr);
    free(my_array);
    return 0;
}

void check_null_pointer(const void* ptr, const char* func_name)
{
    if (ptr == NULL)
    {
        fprintf(stderr, "Error: NULL pointer passed to %s\n", func_name);
        exit(1);
    }
}

int* allocate_int_array_with_check(size_t size) 
{
    int* arr = malloc(size * sizeof(int));
    if (arr == NULL) 
    {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        exit(1);
    }
    return arr;
}

int Value(void)
{
    int value = 0;
    int result = scanf("%d", &value);
    if (result != 1)
    {
        fprintf(stderr, "Input error\n");
        exit(1);
    }
    return value;
}

size_t getSize(const char* message)
{
    check_null_pointer(message, "getSize");
    printf("%s", message);
    int value = Value();
    if (value <= 0)
    {
        fprintf(stderr,"Input error: size must be positive\n");
        exit(1);
    }
    return (size_t)value;
}

void fillArray(int* arr, const size_t size)
{
    check_null_pointer(arr, "fillArray");
    for (size_t i = 0; i < size; i++)
    {
        printf("Input %zu element of array:", i);
        arr[i] = Value();
    }
}

void printArray(const int* arr, const size_t size)
{
    check_null_pointer(arr, "printArray");
    printf("Your array is:\n");
    for (size_t i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void sumEven(const int* arr, const size_t size)
{
    check_null_pointer(arr, "sumEven");
    int result = 0;
    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] % 2 == 0)
            {
                result += arr[i];
            }
    }
    printf("Sum of even numbers is %d.\n", result);
}

void fillRandom(int* arr, const size_t size)
{
    check_null_pointer(arr, "fillRandom");
    printf("diapozon start:\n");
    int start = Value();
    printf("diapozon end:\n");
    int end = Value();
    if (start >= end) 
    {
        fprintf(stderr, "Error: end must be more than start\n");
        exit(1);
    }
    srand(time(NULL)); // Initialize random seed
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = rand() % (end - start + 1) + start;
    }
}

int* copyArray(const int* arr, const size_t size)
{
    check_null_pointer(arr, "copyArray");
    int* copyArr = malloc(sizeof(int)*size);
    if (copyArr == NULL) 
    {
        fprintf(stderr, "Error: Memory allocation failed in copyArray\n");
        exit(1);
    }
    for (size_t i = 0; i<size; i++)
    {
        copyArr[i] = arr[i];
    }
    return copyArr;
}

void countTwoDigitNumbers(const int* arr, const size_t size) 
{
    check_null_pointer(arr, "countTwoDigitNumbers");
    int count = 0;

    for (size_t i = 0; i < size; i++) 
    {
        if ((arr[i] >= 10 && arr[i] <= 99) || (arr[i] <= -10 && arr[i] >= -99)) {
            count++;
        }
    }
    printf("Amount of 2-digit elements is %d.\n", count);
}

int replaceFirstAbsLastNegative(int* copyArr, const size_t size) 
{
    check_null_pointer(copyArr, "replaceFirstAbsLastNegative");
    int firstAbs = abs(copyArr[0]);
    for (size_t i = size; i > 0; i--) 
    {
        if (copyArr[i-1] < 0) 
        {
            copyArr[i-1] = firstAbs;
            printf("Your new array is:\n");
            for (size_t j = 0; j < size; j++) 
            {
                printf("%d ", copyArr[j]);
            }
            printf("\n");
            return 1;
        }
    }
    printf("Your array has not negative elements.\n");
    return 0;
}
