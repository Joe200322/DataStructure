#ifndef PROBLEM8_STACK_H
#define PROBLEM8_STACK_H

template <typename t>
class Stack{
private:
    t *arr;
    int Size;
    int Capacity;
    void increaseCapacity();
public:
    Stack();
    Stack(int Size);
    Stack(const Stack<t> &src);
    ~Stack();
    Stack<t> operator=(const Stack<t> &src);
    t pop();
    int size();
    void push(t element);
    bool isEmpty();
    t &top();
    int capacity();
    void clear();
    void reverse();

    t & operator[](int index);
    friend std::ostream & operator<<(std::ostream& out ,const Stack<t> & src){
        out << "[";
        for (int i = src.Size - 1; i >= 0; --i) {
            out << src.arr[i];
        }
        out << "]";
        return out;
    }

    // Exceptions classes
    class StackEmptyException{
    private:
        std::string errorMessage;
    public:
        StackEmptyException(){
            errorMessage = "Stack Empty Exception Happen, as You Try to pop From Empty Stack";
        }
        void pushError(){
            std::cerr << errorMessage << std::endl;
        }
    };
    class InvalidIndex{
    private:
        std::string errorMessage;
    public:
        InvalidIndex(){
            errorMessage = "You enter invalid index";
        }
        void pushError(){
            std::cerr << errorMessage << std::endl;
        }
    };
};

template<typename t>
Stack<t>::Stack() {
    Capacity = 5;
    Size = 0;
    arr = new t[Capacity];
}

template <typename t>
Stack<t>::Stack(int sizeStack) {
    if (sizeStack <= 0){
        throw (InvalidIndex());
    }
    Size = 0;
    Capacity = sizeStack;
    arr = new t[Capacity];
}

template <typename t>
Stack<t>::~Stack() {
    delete[] arr;
}

template<typename t>
Stack<t>::Stack(const Stack<t> &src) {
    Capacity = src.Capacity;
    Size = src.Size;

    this->arr = nullptr;

    if (src.arr != nullptr){
        this->arr = new t[Capacity];
        for (int i = 0; i < Size; ++i) {
            arr[i] = src.arr[i];
        }
    }
}

template<typename t>
Stack<t> Stack<t>::operator=(const Stack<t> &src) {
    if (this != &src) {
        delete[] arr;
        t *newArr = new t[src.Capacity];
        for (int i = 0; i < src.Size; ++i) {
            newArr[i] = src.arr[i];
        }
        arr = newArr;
        newArr = nullptr;
        Size = src.Size;
        Capacity = src.Capacity;
    }
    return *this;
}

template<typename t>
int Stack<t>::size() {
    return Size;
}

template<typename t>
bool Stack<t>::isEmpty() {
    if (Size == 0){
        return true;
    }
    return false;
}

template <typename t>
t Stack<t>::pop() {
    if (Size == 0){
        throw (StackEmptyException());
    }
    t lastElement = arr[Size - 1];
    --Size;
    return lastElement;
}

template<typename t>
void Stack<t>::push(t element) {
    if (Size >= Capacity){
        increaseCapacity();
    }

    arr[Size++] = element;
}

template<typename t>
t& Stack<t>::top() {
    if (Size == 0){
        throw (StackEmptyException());
    }
    return arr[Size - 1];
}

template<typename t>
int Stack<t>::capacity() {
    return Capacity;
}

template<typename t>
void Stack<t>::increaseCapacity() {
    Capacity *= 2;
    t * newArr = new t[Capacity];
    for (int i = 0; i < Size; ++i) {
        newArr[i] = this->arr[i];
    }
    delete[] arr;
    arr = newArr;
    newArr = nullptr;
}

template<typename t>
void Stack<t>::clear() {
    while (Size > 0){
        pop();
    }
}

template<typename t>
t &Stack<t>::operator[](int index) {
    if (index >= Size or index < 0){
        throw (InvalidIndex());
    }
    else{
        return arr[index];
    }
}


template<typename t>
void Stack<t>::reverse() {
    t * newArr = new t[Capacity];
    int counter = 0;
    while (Size >= 0){
        newArr[counter] = pop();
        counter++;
    }
    delete[] arr;
    arr = newArr;
    newArr = nullptr;
}


#endif //PROBLEM8_STACK_H
