# include<iostream>
using namespace std;

template <typename T>
class Node
{
private:
	T object;
	Node* nextNode;
public:
	T get() 
	{ 
		return object; 
	}
	void set(T object) 
	{ 
		this->object = object; 
	}
	Node* getNext() 
	{ 
		return nextNode; 
	}
	void setNext(Node* nextNode) 
	{ 
		this->nextNode = nextNode; 
	}
};

template <typename T>
class stack 
{
private:
	Node<T>* current;
	int size;
public:
	stack()
	{
		current = NULL;
		size = 0;
	}

	void push(const T& data)
	{
		Node<T>* newNode = new Node<T>();
		newNode->set(data);
		newNode->setNext(current);
		current = newNode;
		size++;
	}
	
	T pop()
	{
		T x = current->get();
		Node<T>* p = current;
		current = current->getNext();
		delete p;

		size--;
		return x;
	}
	
	T top()
	{
		return current->get();
	}
	
	bool isEmpty()
	{
		if (size == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void print() const
	{
		Node<T>* p = current;
		while (p != NULL)
		{
			cout << p->get() << " ";
			p = p->getNext();
		}
		cout << endl;
	}
};

int main()
{
	stack<int> s;
	s.push(10);
	s.push(20);
	s.push(30);
	cout << "Stack elements: ";
	s.print();
	for (int i = 0; i < 3; i++)
	{
		cout << "Element popped: " << s.pop() << endl;
	}
	return 0;
}