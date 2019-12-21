class Node
{
    public:
	int data; //поле данных
	Node* next; //указатель на след элемент

    Node(int data = 0, Node* next = nullptr)
    {
        this -> data = data;
        this -> next = next;
    }
};  

class List
{
    public:
	Node* head;	// head - где лежит первый элемент
    int size;
    List()
    {
        size = 0;
        head = nullptr;
    }

    int len() // размер(длина) списка
    {
        return this -> size;
    }

    void push_front(int data)
    {
        Node* first = new Node(data);
        first -> data = data;
        first -> next = this -> head;
        this -> head = first; 
        this -> size++;
    }

    void pop_front() // удаляет первый элемент
    {
        Node* first = this -> head;
        this -> head = this -> head -> next;
        delete [] first;
        this -> size --;    
    }

    void push_back(int data) // добавляет последний элемент
    {
        if (this -> head == nullptr)
            this -> head = new Node(data);
        else
        {
            Node* current = this -> head;
            while (current -> next != nullptr)
                current = current -> next;
            current -> next = new Node(data);
        }
        this -> size++;
    }

    void pop_back()
    {
        Node* current = this -> head;
        for (int i = 0; i < (this -> size -2); i++)
        {
            current = current -> next;
        }
        Node* last = current -> next;
        current -> next = last -> next;
        delete last;
        this -> size--;
    }

    void clear() //очищает список
    {
        while(this->size > 0)
        {
            this -> pop_front();
        }
    }

    void print()
    {
        Node* current = this -> head;
        while (current != NULL)              
        {
            std::cout << current -> data << " ";           
            current = current -> next;                
        }
    }

    int& operator[](int index) //list[i]
    {
        if((index >= 0) && (index <= this -> len()))
        {
            Node* nd = this -> head;
            int i = 0;
            while((i != index) && (nd))
            {
                i++;
                nd = nd -> next;
            }
            return nd -> data;
        }
        std::cout << "no such index" << std::endl;
    }
};
