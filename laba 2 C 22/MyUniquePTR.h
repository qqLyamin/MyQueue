#pragma once
template <class C>
class MyUniquePTR
{
	C * myobject = nullptr;

public:

	MyUniquePTR(const MyUniquePTR &) = delete; //нельзя пользоваться не move 

	MyUniquePTR(C * target);

	MyUniquePTR & operator=(const C & target) = delete;
	MyUniquePTR<C> & operator=(C && target); //не понимаююоткуда вылезло MyUniquePTR<C> и MyUniquePTR &

	~MyUniquePTR();
};

template<class C>
inline MyUniquePTR<C>::MyUniquePTR(C * target)
{
	if (myobject != target)
	{
		myobject = target;
		target = nullptr;
	}
}


template<class C>
inline MyUniquePTR<C> & MyUniquePTR<C>::operator=(C && target)
{
	if (myobject != target) //по идее такого и не может быть
	{
		myobject = std::move(target);
	}
}

template<class C>
inline MyUniquePTR<C>::~MyUniquePTR()
{
	delete myobject;
	myobject = nullptr;
}
