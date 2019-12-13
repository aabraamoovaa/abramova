#include <fstream>
#include <iostream>

class Node
{
public:
	int data; //поле данных
	Node* next; //указатель на след элемент
}  

class List
{
    public:
	Node* head;	// head - где лежит первый элемент
    int len();
    void push_front(int data);
    void pop_front();
    void push_back(int data);
    void pop_back();
    void clear();
    void remove();
    void print();

}

int List::len() //длина списка
{
    int count = 0;
    Node * current = head;
    if (!current)
        return count;
    while(current)
    {
            count ++;
            current = current -> next;
    }
    return count;
}

void List::push_front(int data) // добавляет первый элемент
{
    Node* first = new Node;
    first -> data = data;
    first -> next = head;
    head = first;
}

void List::pop_front() // удаляет первый элемент
{
    Node* first = head;
    if(first)
    {
        head = head -> next;
    }
}

void List::push_back(int val) // добавляет последний элемент
{
    Node* last = new Node;
    last -> data = data;
    last -> next = nullptr;
    if (head)
    {
        Node* current = head;
        while(current -> next)
        {
            current = current -> next;
        }
        current -> next = last;
    }
    else
    {
        head = last;
    }
}
    
void List::pop_back() // удаляет последний элемент
{
    Node* current = head;
    if (current){
        if (current -> next){
            while(current -> next -> next)
            {
                current = current -> next;
            }
        Node* last = current->next;
        current -> next = nullptr;
        }
        else
        {
            head = nullptr;
        }
    }
}

void List::clear() //очищает список(ну очевидно...)
{
    while(head){
        this -> pop_front();
    }
}

void List::remove(int value) //удаляет элементы с опредененным значением 
{
Node* current = head;
    if (head -> value == value)
    {
        this -> popFront();
        return;
    }
} 

void List::print()
{
    Node* element = head;
    do 
    {
        std::cout << element -> data << " ";
        element = element -> next;
    } 
    while (element != NULL);
    std::cout << std::endl;
}
