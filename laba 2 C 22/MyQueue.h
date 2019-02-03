#pragma once
template <typename T>
class MyQueue
{
	size_t iPush = 0;
	size_t iPop = 0;

	size_t not_empty = 0;
	size_t capacity = 10;
	T * arr = new T[capacity];

public:

	T pop_back();

	template <typename T2>
	void push_back(T2 &&);

	MyQueue<T> & operator=(const MyQueue<T> & rightQ); //�������� ��������� forwarding

	MyQueue(const MyQueue<T> & rightQ);


	~MyQueue();
	/*void push_back(const T & myvalueTopush);
	void push_back(T && myvalueTopush);*/

};

template<typename T>
inline T MyQueue<T>::pop_back()
{
	if (not_empty != 0)
	{
		T tmp = arr[iPop];
		if (iPop + 1 < capacity)
		{
			iPop++;
		}
		else
		{
			iPop == 0; //�� ������ � ���� �������
		}
		not_empty--;
		return tmp;
	}
}

template<typename T> //�������� ��������� forwarding
inline MyQueue<T> &  MyQueue<T>::operator=(const MyQueue<T> & rightQ)
{
	if (this != rightQ) // ��������� �� ������������ +
	{
		if (this->capacity < rightQ.not_empty)// ��������� ������� �� ����� ������� +
		{
			capacity = rightQ.not_empty;
			T * newarr = new T[capacity];
			delete[] arr;
			arr = newarr;
		}
		for (int i = 0; i < rightQ.not_empty; i++)
		{
			this->arr[i] = rightQ.arr[right.iPop];
			rightQ.iPop++;
			if (rightQ.iPop == rightQ.capacity)
			{
				rightQ.iPop = 0;
			}
		}
		iPop = 0;
		iPush = not_empty;
		not_empty = rightQ.not_empty;
	}
	return *this;
}

//����� � ���������
template<typename T>
inline MyQueue<T>::MyQueue(const MyQueue<T>& rightQ)
{
	if (rightQ.not_empty > this->capacity) //��� � ������ ���� ��� ������� �����
	{
		T * newarr = new T[rightQ.not_empty];
		delete[] this->arr;
		this->arr = newarr;
		this->capacity = rightQ.not_empty;
	}

	for (int i = 0; i < rightQ.not_empty; i++) //��� �� ������ � � ������ ���� ������ ������� � ���� �� �������
	{
		this->arr[i] = rightQ.arr[iPop];
		++iPop;

		if (iPop == rightQ.capacity)
		{
			rightQ.iPop = 0;
		}
	}
	this->iPop = 0;
	this->iPush = rightQ.not_empty - 1;
	this->not_empty = rightQ.not_empty;
	//this->capacity �������� ����� �� � ������ ���� ��� ������ �������
}

template<typename T>
inline MyQueue<T>::~MyQueue()
{
	delete[] arr;
}

template<typename T> //��� ���� ��������� �� ������, � �� ����� ��� ��� ���������
template<typename T2>
inline void MyQueue<T>::push_back(T2 && myvalueTopush)
{

	if (capacity == not_empty)
	{
		T * newarr = new T[capacity + 1];
		for (int i = 0; i < capacity; i++)
		{
			newarr[i] = std::move(arr[iPop]);
			++iPop;
			if (iPop == capacity)
			{
				iPop = 0;
			}
		}
		delete[] arr;
		arr = newarr;

		capacity++;

		iPop = 0; //��������
		iPush = capacity - 1; //���� �������� 
	}


	arr[iPush++] = std::forward<T2>(myvalueTopush);

	not_empty++;
	if (iPush == capacity)
	{
		iPush = 0;
	}
}

