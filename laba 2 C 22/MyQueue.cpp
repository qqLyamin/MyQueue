#include "MyQueue.h"

//template<typename T>
//T MyQueue<T>::pop_back()
//{
//	size_t minimal = 999;
//	T RetObj;
//	for (auto var : arr)
//	{
//		if (var.second < minimal)
//		{
//			minimal = var.second;
//			RetObj = var.first;
//		}
//	}
//	FreeSpace++;
//	return RetObj;
//}
//
//template<typename T>
//void MyQueue<T>::push_back(T & myvalueTopush)
//{
//	auto a = std::make_pair(myvalueTopush, queueNumber);
//	++queueNumber;
//
//	if (FreeSpace > 0)
//	{
//		--FreeSpace;
//		arr[SIZE - FreeSpace - 1] = a;
//	}
//	else
//	{
//		size_t length = strlen(arr);
//		newarr = new T[length + 1 + 1];
//		strcpy(arr, newarr);
//		delete[] arr;
//		arr = newarr;
//		arr[length + 1 + 1] = a;
//	}
//}
//
//template<typename T>
//void MyQueue<T>::push_back(T && myvalueTopush)
//{
//	auto a = std::make_pair(myvalueTopush, queueNumber);
//	++queueNumber;
//
//	if (FreeSpace > 0)
//	{
//		--FreeSpace;
//		arr[SIZE - FreeSpace - 1] = a;
//	}
//	else
//	{
//		size_t length = strlen(arr);
//		newarr = new T[length + 1 + 1];
//		strcpy(arr, newarr);
//		delete[] arr;
//		arr = newarr;
//		arr[length + 1 + 1] = a;
//	}
//
//	delete myvalueTopush;
//}
//
//template<typename T>
//MyQueue<T>::MyQueue()
//{
//	SIZE = 0;
//	arr = nullptr;
//}
//
//template<typename T>
//
//MyQueue<T>::~MyQueue()
//{
//	for (auto var : arr)
//	{
//		delete[] var;
//	}
//
//	arr = nullptr;
//	SIZE = 0;
//}

template<typename T>
T MyQueue<T>::pop_back() //кажется что должно быть еще что-то
{
	if (iPop != SIZE - 1)
	{
		T tmp = arr[iPop];
		delete arr[iPop];
		iPop++;
		return tmp;
	}
	else if (iPop == SIZE - 1)
	{
		T tmp = arr[iPop];
		delete arr[iPop];
		iPop = 0;
		return tmp;
	}
}

