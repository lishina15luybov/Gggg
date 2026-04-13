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
        Node(int value) : data(value), next(nullptr) {}
    };

    Node* head;   
    Node* tail;   
    size_t count; 
public:
    Queue();
    explicit Queue(std::initializer_list<int> init);
    Queue(const Queue& other);
    Queue(Queue&& other) noexcept;

    ~Queue();


    Queue& operator=(const Queue& other);
    Queue& operator=(Queue&& other) noexcept;


    void enqueue(int value);   
    int dequeue();              
    int peek() const;        


    bool isEmpty() const;       
    size_t size() const;         
    void clear();                
    std::string toString() const;

   
    Queue& operator<<(int value);  
    Queue& operator>>(int& value); 

    
    bool contains(int value) const;
};
