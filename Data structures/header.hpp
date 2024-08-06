template<class T>
class Node{
    public:
    T val;
    Node<T>* next;

    Node(T val, Node* next){
        this->val = val;
        this->next = next;
    }
    ~Node(){}
};

template<class T>
class Queue{
public:
    Node<T>* front, *back;
    Queue(T val);
    void add(T val);
    T pop();
    ~Queue();

    void print();
};

template<class T>
class Heap{
public:
    Node<T>* top;
    Heap(T val);
    void add(T val);
    T pop();
    ~Heap();

    void print();
};

template<class T>
class List{
public:
    Node<T>* top;
    List(T val);
    void add(T val);
    T pop();
    ~List();
    T get(int i);
    void merge(List<T>* list);

    void print();
};

// bidir cyclic
template<class T>
class Bode{
    public:
    T val;
    Bode<T>* next, * prev;

    Bode(T val, Bode* next, Bode* prev){
        this->val = val;
        this->next = next;
        this->prev = prev;
    }
    ~Bode(){}
};
template<class T>
class Bist{ // Bidirectional List
public:
    Bode<T>* top;
    int size;
    Bist(T val);
    void add(T val);
    T pop();
    ~Bist();
    T get(int i);
    void merge(Bist<T>* list);

    void print();
};

template class Queue<int>;
template class Heap<int>;
template class Node<int>;
template class List<int>;
template class Bist<int>;