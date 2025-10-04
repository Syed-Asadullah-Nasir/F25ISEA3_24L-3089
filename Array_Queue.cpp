//#include <iostream>
//#include <stdexcept>
//using namespace std;
//
//template <typename T>
//class Stack
//{
//private:
//    T* A;
//    int size;      // number of elements in queue
//    int capacity;  // total capacity (with +1 dummy slot)
//    int front, rear;
//
//    int next(int i) const
//    { 
//        return (i + 1) % capacity; 
//    }
//
//public:
//    Stack(int cap = 0) 
//    {
//        if (cap > 0) 
//        {
//            A = new T[cap + 1];
//            capacity = cap + 1;
//        }
//        else 
//        {
//            A = NULL;
//            capacity = 0;
//        }
//        size = 0;
//        front = rear = 0;
//    }
//
//    ~Stack() 
//    { 
//        delete[] A; 
//    }
//
//    void push(const T& data)
//    {
//        if (capacity == size + 1)  // queue full ? resize
//        {
//            T* temp = new T[capacity * 2];
//            int i = next(front);
//
//            for (int j = 1; j <= size; j++)
//            {
//                temp[j] = A[i];
//                i = next(i);
//            }
//            delete[] A;
//            A = temp;
//
//            front = 0;
//            rear = size;
//            capacity *= 2;
//
//            rear = next(rear);
//            A[rear] = data;
//        }
//        else if (capacity == 0) // first insertion
//        { 
//            A = new T[2];
//            capacity = 2;
//            front = 0;
//            rear = 1;
//            A[rear] = data;
//        }
//        else 
//        {
//            rear = next(rear);
//            A[rear] = data;
//        }
//        size++;
//    }
//
//    T pop() 
//    {
//        if (size == 0)
//        {
//            throw runtime_error("Queue underflow!");
//        }
//
//        if ((size + 1) == capacity / 2)  // shrink
//        {
//            T* temp = new T[(capacity / 2) + 1];
//            int i = next(front);
//
//            for (int j = 1; j <= size; j++) 
//            {
//                temp[j] = A[i];
//                i = next(i);
//            }
//            delete[] A;
//            A = temp;
//
//            front = 0;
//            rear = size;
//            capacity /= 2;
//
//            front = next(front);
//            T x = A[front];
//            size--;
//            return x;
//        }
//        else 
//        {
//            front = next(front);
//            T x = A[front];
//            size--;
//            return x;
//        }
//    }
//
//    bool isEmpty()
//    { 
//        return size == 0; 
//    }
//
//    const T& top() 
//    {
//        if (size == 0) 
//        {
//            throw runtime_error("Queue is empty!");
//        }
//        return A[next(front)];
//    }
//
//    int getSize() const 
//    { 
//        return size; 
//    }
//    
//    void print() const
//    {
//        if (size == 0) 
//        {
//            cout << "Queue is empty!" << endl;
//            return;
//        }
//        int i = next(front);
//        for (int j = 1; j <= size; j++) 
//        {
//            cout << A[i] << " ";
//            i = next(i);
//        }
//        cout << endl;
//	}
//};
//
//int main() 
//{
//    Stack<int> q;
//    q.push(10);
//    q.push(20);
//    q.push(30);
//	cout << "Queue elements: ";
//	q.print();
//
//
//    while (!q.isEmpty()) 
//    {
//        cout << "Front element: " << q.top() << endl;
//        cout << "element Poped: " << q.pop() << endl << endl;
//    }
//
//    q.print();
//    return 0;
//}