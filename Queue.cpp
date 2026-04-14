#include "Queue.h"
#include <string>
#include <stdexcept>

/**
 * @brief Конструктор по умолчанию
 * @post Создается пустая очередь (head = tail = nullptr, count = 0)
 */
Queue::Queue() : head(nullptr), tail(nullptr), count(0) {}

/**
 * @brief Конструктор со списком инициализации
 * @param init Список целых чисел для инициализации очереди
 * @post Очередь содержит элементы из init в том же порядке
 */
Queue::Queue(std::initializer_list<int> init) : head(nullptr), tail(nullptr), count(0)
{
    for (int value : init)
    {
        enqueue(value);
    }
}

/**
 * @brief Конструктор копирования
 * @param other Ссылка на копируемую очередь
 * @post Создается глубокая копия other
 */
Queue::Queue(const Queue& other) : head(nullptr), tail(nullptr), count(0)
{
    Node* current = other.head;
    while (current != nullptr)
    {
        enqueue(current->data);
        current = current->next;
    }
}

/**
 * @brief Конструктор перемещения
 * @param other Ссылка на перемещаемую очередь (rvalue)
 * @post Ресурсы other перемещаются в текущий объект, other становится пустым
 */
Queue::Queue(Queue&& other) noexcept : head(other.head), tail(other.tail), count(other.count)
{
    other.head = nullptr;
    other.tail = nullptr;
    other.count = 0;
}

/**
 * @brief Деструктор
 * @post Все выделенные ресурсы освобождены
 */
Queue::~Queue()
{
    clear();
}

/**
 * @brief Оператор присваивания копированием
 * @param other Ссылка на копируемую очередь
 * @return Ссылка на текущий объект
 * @post Текущая очередь содержит глубокую копию other
 */
Queue& Queue::operator=(const Queue& other)
{
    if (this != &other)
    {
        clear();
        Node* current = other.head;
        while (current != nullptr)
        {
            enqueue(current->data);
            current = current->next;
        }
    }
    return *this;
}

/**
 * @brief Оператор присваивания перемещением
 * @param other Ссылка на перемещаемую очередь (rvalue)
 * @return Ссылка на текущий объект
 * @post Ресурсы other перемещаются в текущий объект, other становится пустым
 */
Queue& Queue::operator=(Queue&& other) noexcept
{
    if (this != &other)
    {
        clear();
        head = other.head;
        tail = other.tail;
        count = other.count;
        other.head = nullptr;
        other.tail = nullptr;
        other.count = 0;
    }
    return *this;
}

/**
 * @brief Добавляет элемент в конец очереди
 * @param value Добавляемое целое число (передается по значению)
 * @post Элемент добавлен в конец очереди, размер увеличен на 1
 */
void Queue::enqueue(int value)
{
    Node* newNode = new Node(value);
    if (isEmpty())
    {
        head = tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
    ++count;
}

/**
 * @brief Удаляет и возвращает первый элемент очереди
 * @return Значение первого элемента очереди
 * @throw std::runtime_error Если очередь пуста
 * @post Первый элемент удален, размер уменьшен на 1
 */
int Queue::dequeue()
{
    if (isEmpty())
    {
        throw std::runtime_error("Ошибка: очередь пуста");
    }
    int value = head->data;
    Node* temp = head;
    head = head->next;
    delete temp;
    --count;
    if (isEmpty())
    {
        tail = nullptr;
    }
    return value;
}

/**
 * @brief Возвращает первый элемент очереди без удаления
 * @return Значение первого элемента очереди
 * @throw std::runtime_error Если очередь пуста
 * @note Очередь остается неизменной
 */
int Queue::peek() const
{
    if (isEmpty())
    {
        throw std::runtime_error("Ошибка: очередь пуста");
    }
    return head->data;
}

/**
 * @brief Проверяет, пуста ли очередь
 * @return true если очередь пуста, false иначе
 */
bool Queue::isEmpty() const
{
    return head == nullptr;
}

/**
 * @brief Возвращает текущий размер очереди
 * @return Количество элементов в очереди (тип size_t)
 */
size_t Queue::size() const
{
    return count;
}

/**
 * @brief Очищает очередь, удаляя все элементы
 * @post Очередь становится пустой (size() == 0)
 */
void Queue::clear()
{
    while (!isEmpty())
    {
        dequeue();
    }
}

/**
 * @brief Преобразует очередь в строковое представление
 * @return Строка вида "[1, 2, 3, 4]"
 * @note Пустая очередь возвращает "[]"
 */
std::string Queue::toString() const
{
    std::string result = "[";
    Node* current = head;
    while (current != nullptr)
    {
        result += std::to_string(current->data);
        if (current->next != nullptr)
        {
            result += ", ";
        }
        current = current->next;
    }
    result += "]";
    return result;
}

/**
 * @brief Оператор добавления элемента в очередь (потоковый)
 * @param value Добавляемое целое число
 * @return Ссылка на текущий объект (для цепочечных вызовов)
 * @example q << 10 << 20 << 30; // добавляет три элемента
 */
Queue& Queue::operator<<(int value)
{
    enqueue(value);
    return *this;
}

/**
 * @brief Оператор извлечения элемента из очереди
 * @param value Ссылка на переменную для сохранения извлеченного значения
 * @return Ссылка на текущий объект (для цепочечных вызовов)
 * @throw std::runtime_error Если очередь пуста
 * @example int x; q >> x; // извлекает первый элемент в x
 */
Queue& Queue::operator>>(int& value)
{
    value = dequeue();
    return *this;
}

/**
 * @brief Проверяет наличие элемента в очереди
 * @param value Искомое значение
 * @return true если элемент найден, false иначе
 * @note Линейный поиск, сложность O(n)
 */
bool Queue::contains(int value) const
{
    Node* current = head;
    while (current != nullptr)
    {
        if (current->data == value)
        {
            return true;
        }
        current = current->next;
    }
    return false;
}
