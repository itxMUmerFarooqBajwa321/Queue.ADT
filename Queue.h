#ifndef QUEUE_H
#define QUEUE_H
#include<iostream>
#include<cstdarg>
using namespace std;
template<typename T>
void mySwap(T & a, T & b);
template<typename T>
class Queue
{
	T* queue;
	int sizeOfQueue;
	int frnt;
	int rear;
	void reSize(const int newSize);
	bool full() const;
public:
	Queue(const int cnt =0, ...);
	Queue(const Queue& ref);
	Queue(Queue&& ref);
	T& front();
	T& back();
	//void emplace(const T& ele);
	void push(const T& ele);
	void pop();
	int size()const;
	bool empty() const;
	void swap(Queue<T>& other);
	void displayQueue()const;
	~Queue();
};
template<typename T>
Queue<T>::Queue(const int cnt, ...) : queue(nullptr), sizeOfQueue(0), frnt(-1), rear(-1)
{
	if (cnt <= 0)
		return;
	sizeOfQueue = cnt;
	queue = new T[sizeOfQueue];
	va_list myList;
	va_start(myList, cnt);
	int i = 0;
	while (i < cnt)
	{
		queue[i] = va_arg(myList, T);
		i++;
	}
	va_end (myList);
	frnt = 0;
	rear = cnt - 1;
}
template<typename T>
T& Queue<T>::front()
{
	if (empty())
		exit(0);	
	return queue[frnt];
}
template<typename T>
T& Queue<T>::back()
{
	if (empty())
	{
		exit(0);
	}
	return queue[rear];
}
template<typename T>
void Queue<T>::push(const T& ele)
{
	if (full())
	{
		reSize(sizeOfQueue + 1);
	}
	rear++;
	queue[rear] = ele;
	if (frnt == -1)
		frnt = 0;
}
template<typename T>
void Queue<T>::pop()
{
	if (empty())
		return;
	frnt++;
	if (frnt == rear + 1)
	{
		frnt = -1;
		rear = -1;
	}
}
template<typename T>
int Queue<T>::size()const
{
	return sizeOfQueue;
}
template<typename T>
bool Queue<T>::empty() const
{
	return (frnt == rear == -1);
}
template<typename T>
bool Queue<T>::full() const
{
	return rear == (sizeOfQueue-1);
}
template<typename T>
void Queue<T>::reSize(const int newSize)
{
	if (newSize == sizeOfQueue)
	{
		return;
	}
	if (newSize <= 0)
	{
		this->~Queue();
	}
	int smallerSize = (sizeOfQueue < newSize) ? sizeOfQueue : newSize;
	T* temp=new T[smallerSize];
	int i = 0;
	while(i<smallerSize)
	{
		temp[i] = queue[i];
		i++;
	}
	delete[] queue;
	queue = temp;
	if (rear >= smallerSize)
		rear = smallerSize - 1;
	sizeOfQueue = newSize;
}
template<typename T>
Queue<T>::Queue(const Queue & ref):Queue()
{
	if (!ref)
		return;
	sizeOfQueue = ref.sizeOfQueue;
	frnt = ref.frnt;
	rear = ref.rear;
	queue = new T[sizeOfQueue];
	int i = frnt;
	while (i < rear)
	{
		queue[i] = ref.queue[i];
		i++;
	}
}
template<typename T>
Queue<T>::Queue(Queue&& ref)
{
	if (!ref)
		return;
	frnt = ref.frnt;
	rear = ref.rear;
	sizeOfQueue = ref.sizeOfQueue;
	queue = ref.queue;
	ref.queue = nullptr;
	ref.frnt = ref.rear = -1;
	ref.sizeOfQueue = 0;
}
template<typename T>
void Queue<T>::swap(Queue<T>& other)
{
	mySwap<int>(frnt, other.frnt);
	mySwap<int>(rear, other.rear);
	mySwap<int>(sizeOfQueue, other.sizeOfQueue);
	mySwap<int*>(queue, other.queue);
}
template<typename T>
Queue<T>::~Queue()
{
	if (!this)
		return;
	sizeOfQueue = 0;
	frnt = rear = -1;
	if (queue) 
	{
		delete[] queue;
		queue = nullptr;
	}
}
template<typename T>
void Queue<T>::displayQueue()const
{
	for (int i = frnt; i <= rear; i++)
		cout << queue[i] << ' ';
}
template<typename T>
void mySwap(T & a , T & b)
{
	T temp = move(a);
	a = move(b);
	b = move(temp);
}
#endif