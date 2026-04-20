#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define scanf_s scanf

/**
 * @return Ввод данных типа int
 * @return Введенное значение
 */
int Value();

/**
 * @brief Выводит текстовое сообщение о необходимости ввода размера массива, проверяет ввод на правильность, задаёт размер массива
 * @param message текстовое сообщение о необходимости ввода массива
 * @return размер массива (количество его элементов)
 */
size_t getSize(const char* message);

/**
 * @brief Считывает значения элементов массива
 * @param arr массив
 * @param rows количество строк массива
 * @param columns количество столбцов массива
 */
void fillArray(int** arr, const size_t rows, const size_t columns);

/**
 * @brief Выводит массив на экран
 * @param arr массив
 * @param rows количество строк массива
 * @param columns количество столбцов массива
 */
void printArray(int** arr, const size_t rows, const size_t columns);

/**
 * @brief Заполняет массив случайными числами в выбранном пользователем диапазоне
 * @param arr массив
 * @param rows количество строк
 * @param columns количество столбцов
 */
void fillRandom(int** arr, const size_t rows, const size_t columns);

/**
 * @brief Создаёт массив по указанным пользователем вводным данным
 * @param rows количество строк
 * @param columns количество столбцов
 * @return полученный массив
 */
int** createArray(const size_t rows, const size_t columns);

/**
 * @brief Освобождает память, выделенную под массив
 * @param arr массив
 * @param rows количество строк
 */
void freeArray(int** arr, const size_t rows);

/**
 * @brief Заменяет минимальный по модулю элемент каждого столбца на противоположный
 * @param copyArr массив
 * @param rows количество строк массива
 * @param columns количество столбцов массива
 */
void replaceMinOpposite(int** copyArr, const size_t rows, const size_t columns);

/**
 * @brief Удаляет все строки массива с максимальным значением
 * @param copyArr массив
 * @param rows количество строк массива
 * @param columns количество столбцов массива
 * @return 0, если были удалены все строки, иначе 1.
 */
int delRowsWithMax(int** copyArr, const size_t rows, const size_t columns);

/**
 * @brief Проверяет, что минимальное значение меньше максимального
 * @param min минимальное значение
 * @param max максимальное значение
 */
void checkRange(const int min, const int max);

/**
 * @brief Создаёт копию массива для дальнейшей работы с ней
 * @param arr изначальный массив
 * @param rows количество строк
 * @param columns количество столбцов
 * @return копию массива
 */
int** copyArray(int** arr, const size_t rows, const size_t columns);

/**
 * @brief RANDOM - заполнение массива случайными числами в пределах введённого пользователем диапазона
 * @brief MANUAL - заполнение массива вручную
 */
enum {RANDOM = 1, MANUAL};

/**
 * @brief Точка входа в программу
 * @return 0, если программа выполнена корректно, иначе 1
 */
int main()
{
    size_t rows = getSize("Input quantity of rows of an array:\n");
    size_t columns = getSize("Input quantity of columns of an array:\n");
    int** arr = createArray(rows, columns);
    
    printf("Chose the method of filling the array:\n%d - by random\n%d - manually\n", RANDOM, MANUAL);
    int choice = Value();
    switch(choice)
    {
        case RANDOM:
            fillRandom(arr, rows, columns);
            break;
        case MANUAL:
            fillArray(arr, rows, columns);
            break;
        default:
            fprintf(stderr, "Error: invalid choice\n");
            freeArray(arr, rows);
            return 1;
    }
    
    printArray(arr, rows, columns);
    
    int** copyArr = copyArray(arr, rows, columns);
    printf("Replacing min absolute element in every column:\n");
    replaceMinOpposite(copyArr, rows, columns);
    printArray(copyArr, rows, columns);
    
    printf("Deleting rows with max elements:\n");
    delRowsWithMax(copyArr, rows, columns);
    
    freeArray(arr, rows);
    freeArray(copyArr, rows);
    return 0;
}

int Value(void)
{
    int value = 0;
    int result = scanf("%d", &value);
    if (result != 1){
        fprintf(stderr, "Input error");
        exit(1);
    }
    return value;
}

size_t getSize(const char* message)
{
    if (message == NULL)
    {
        fprintf(stderr, "Error: message pointer is NULL\n");
        exit(1);
    }
    
    printf("%s", message);
    int value = Value();
    if (value <= 0)
    {
        fprintf(stderr, "Error: size must be positive\n");
        exit(1);
    }
    return (size_t)value;
}

void fillArray(int** arr, const size_t rows, const size_t columns)
{
    if (arr == NULL)
    {
        fprintf(stderr, "Error: array pointer is NULL\n");
        exit(1);
    }
    
    for (size_t i = 0; i < rows; i++)
    {
        if (arr[i] == NULL)
        {
            fprintf(stderr, "Error: row pointer is NULL\n");
            exit(1);
        }
        
        for (size_t j = 0; j < columns; j++)
        {
            printf("Input a[%zu,%zu] = ", i, j);
            arr[i][j] = Value();
        }
    }
}

void printArray(int** arr, const size_t rows, const size_t columns)
{
    if (arr == NULL)
    {
        fprintf(stderr, "Error: array pointer is NULL\n");
        return;
    }
    
    printf("Your array is:\n");
    for (size_t i = 0; i < rows; i++)
    {
        if (arr[i] == NULL)
        {
            fprintf(stderr, "Error: row pointer is NULL\n");
            return;
        }
        
        for (size_t j = 0; j < columns; j++)
        {
            printf("%5d", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void fillRandom(int** arr, const size_t rows, const size_t columns)
{
    if (arr == NULL)
    {
        fprintf(stderr, "Error: array pointer is NULL\n");
        exit(1);
    }
    
    printf("Input min:\n");
    int min = Value();
    printf("Input max:\n");
    int max = Value();
    checkRange(min, max);
    
    srand((unsigned int)time(NULL));
    for (size_t i = 0; i < rows; i++)
    {
        if (arr[i] == NULL)
        {
            fprintf(stderr, "Error: row pointer is NULL\n");
            exit(1);
        }
        
        for (size_t j = 0; j < columns; j++)
        {
            arr[i][j] = (rand() % (max - min + 1)) + min;
        }
    }
}

int** createArray(const size_t rows, const size_t columns)
{
    int** arr = malloc(rows * sizeof(int*));
    if (arr == NULL)
    {
        fprintf(stderr, "Error: memory allocation failed for rows\n");
        exit(1);
    }
    
    for (size_t i = 0; i < rows; i++)
    {
        arr[i] = malloc(columns * sizeof(int));
        if (arr[i] == NULL)
        {
            fprintf(stderr, "Error: memory allocation failed for row %zu\n", i);
            for (size_t j = 0; j < i; j++)
            {
                free(arr[j]);
            }
            free(arr);
            exit(1);
        }
    }
    return arr;
}

void freeArray(int** arr, const size_t rows)
{
    if (arr == NULL)
    {
        return; 
    }
    
    for (size_t i = 0; i < rows; i++)
    {
        free(arr[i]);
    }
    free(arr);
}

void checkRange(const int min, const int max)
{
    if (min > max)
    {
        fprintf(stderr, "Error: min cannot be greater than max\n");
        exit(1);
    }
}

void replaceMinOpposite(int** copyArr, const size_t rows, const size_t columns)
{
    if (copyArr == NULL)
    {
        fprintf(stderr, "Error: array pointer is NULL\n");
        exit(1);
    }
    
    for (size_t j = 0; j < columns; j++)
    {
        if (rows == 0) continue;
        
        size_t minIndex = 0;
        int minAbs = abs(copyArr[0][j]);
        
        for (size_t i = 1; i < rows; i++)
        {
            if (copyArr[i] == NULL)
            {
                fprintf(stderr, "Error: row pointer is NULL\n");
                exit(1);
            }
            
            if (abs(copyArr[i][j]) < minAbs)
            {
                minAbs = abs(copyArr[i][j]);
                minIndex = i;
            }
        }
        copyArr[minIndex][j] = -copyArr[minIndex][j];
    }
}

int** copyArray(int** arr, const size_t rows, const size_t columns)
{
    if (arr == NULL)
    {
        fprintf(stderr, "Error: source array pointer is NULL\n");
        exit(1);
    }
    
    int** copyArr = createArray(rows, columns);
    
    for (size_t i = 0; i < rows; i++)
    {
        if (arr[i] == NULL)
        {
            fprintf(stderr, "Error: source row pointer is NULL\n");
            freeArray(copyArr, rows);
            exit(1);
        }
        
        for (size_t j = 0; j < columns; j++)
        {
            copyArr[i][j] = arr[i][j];
        }
    }
    return copyArr;
}

int delRowsWithMax(int** copyArr, const size_t rows, const size_t columns)
{
    if (copyArr == NULL)
    {
        fprintf(stderr, "Error: array pointer is NULL\n");
        exit(1);
    }
    
    if (rows == 0 || columns == 0)
    {
        printf("Array is empty\n");
        return 0;
    }
    
    int max = copyArr[0][0];
    for (size_t i = 0; i < rows; i++)
    {
        if (copyArr[i] == NULL)
        {
            fprintf(stderr, "Error: row pointer is NULL\n");
            exit(1);
        }
        
        for (size_t j = 0; j < columns; j++)
        {
            if (copyArr[i][j] > max)
            {
                max = copyArr[i][j];
            }
        }
    }
    
    for (size_t i = 0; i < rows; i++)
    {
        bool containsMax = false;
        for (size_t j = 0; j < columns; j++)
        {
            if (copyArr[i][j] == max)
            {
                containsMax = true;
                break;
            }
        }
        
        if (containsMax)
        {
            for (size_t j = 0; j < columns; j++)
            {
                copyArr[i][j] = 0;
            }
        }
    }
    bool allRowsDeleted = true;
    for (size_t i = 0; i < rows; i++)
    {
        bool rowHasNonZero = false;
        for (size_t j = 0; j < columns; j++)
        {
            if (copyArr[i][j] != 0)
            {
                rowHasNonZero = true;
                break;
            }
        }
        
        if (rowHasNonZero)
        {
            allRowsDeleted = false;
            for (size_t j = 0; j < columns; j++)
            {
                printf("%5d", copyArr[i][j]);
            }
            printf("\n");
        }
    }
    
    if (allRowsDeleted)
    {
        printf("All rows were deleted.\n");
        return 0;
    }
    
    return 1;
}
