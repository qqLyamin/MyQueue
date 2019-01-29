#pragma once
//template <typename T>
//class MyQueue
//{
//	size_t queueNumber = 1;
//	size_t FreeSpace = 10;
//	size_t SIZE = 10;
//	T * arr = new T[SIZE];
//public:
//
//	T pop_back();
//
//	void push_back(T & myvalueTopush);
//	void push_back(T && myvalueTopush);
//
//	MyQueue();
//	~MyQueue();
//};
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

	void push_back(const T & myvalueTopush);
	void push_back(T && myvalueTopush);

};

template<typename T>
inline void MyQueue<T>::push_back(const T & myvalueTopush)
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

		iPop = 0; //подумать
		iPush = capacity - 1; //тоже подумать
	}
	
	arr[iPush++] = myvalueTopush;
	not_empty++;
	if (iPush == capacity)
	{
		iPush = 0;
	}
}


template<typename T>
inline void MyQueue<T>::push_back(T && myvalueTopush)
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

		iPop = 0; //подумать
		iPush = capacity - 1; //тоже подумать
	}

	arr[iPush++] = std::move(myvalueTopush);
	not_empty++;
	if (iPush == capacity)
	{
		iPush = 0;
	}
}
