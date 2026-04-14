#pragma once
#include <initializer_list>
#include <string>

/**
 * @brief Класс Очередь (Queue)
 * Реализует коллекцию целых чисел с операциями:
 * enqueue - добавление элемента в конец очереди
 * dequeue - извлечение элемента из начала очереди
 * peek - чтение головного элемента
 */
class Queue
{
private:
    struct Node
    {
        int data;
        Node* next;
        explicit Node(const int value) : data(value), next(nullptr) {}
    };
   
    size_t count; 
public:
    Queue();
    explicit Queue(const std::initializer_list<int> init);
    Queue(const Queue& other);
    Queue(Queue&& other) noexcept;

    ~Queue();


    Queue& operator=(const Queue& other);
    Queue& operator=(Queue&& other) noexcept;


    void enqueue(const int value);   
    int dequeue();              
    int peek() const;        


    bool isEmpty() const;       
    size_t size() const;         
    void clear();                
    std::string toString() const;

   
    Queue& operator<<(const int value);  
    Queue& operator>>(int& value); 

    
    bool contains(const int value) const;
};
