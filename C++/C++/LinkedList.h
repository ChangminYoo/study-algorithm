#include <iostream>
using namespace std;

template<typename T>
class Node
{
public:
	T data;
	Node* next;
	Node* prev;

	Node<T>(T data) : data(data){}
};

template<typename T>
class LinkedList
{
private:
	Node<T>* _head;
	Node<T>* _tail;
	int _size;

public:
	LinkedList()
	{
		_head = nullptr;
		_tail = nullptr;
		_size = 0;
	}

	void Insert(T t);
	void Delete(T t);
	int GetSize() const { return _size; }

	void Print()
	{
		Node<T>* current = _head;
		while (current != nullptr)
		{
			cout << current->data << endl;		
			current = current->next;
		}
	}
};

template<typename T>
void LinkedList<T>::Insert(T t)
{
	Node<T>* newData = new Node<T>(t);
	_size++;
	if (_head == nullptr)
	{
		_head = newData;
		_head->next = nullptr;
		_head->prev = nullptr;
	}


	if (_tail == nullptr)
	{
		_tail = newData;
		_tail->next = nullptr;
		_tail->prev = nullptr;
	}
	else
	{
		_tail->next = newData;
		newData->prev = _tail;
		_tail = newData;
	}
}

template<typename T>
void LinkedList<T>::Delete(T t)
{
	if (_head == nullptr) { cout << "Linked List is Empty" << endl; return; }
	_size--;
	Node<T>* deleteData = _head;
	
	if (t == deleteData->data)
	{
		if (_head->next == nullptr)
		{
			delete _head;
			_head = nullptr;
			return;
		}

		_head->next->prev = nullptr;
		_head = _head->next;
		delete deleteData;
		return;
	}

	while (true)
	{
		deleteData = deleteData->next;
		if (deleteData->data == t)
		{
			if (deleteData == _tail)
			{
				_tail = deleteData->prev;
				_tail->next = nullptr;
			}
			else
			{
				deleteData->prev->next = deleteData->next;
				deleteData->next->prev = deleteData->prev;
			}
			delete deleteData;
			break;
		}

		if (deleteData == nullptr)
		{
			cout << "There is No Data" << endl;
			break;
		}
	}

}
