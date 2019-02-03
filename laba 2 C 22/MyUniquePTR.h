#pragma once
template <class C>
class MyUniquePTR
{
	C * myobject = nullptr;

public:

	MyUniquePTR(const MyUniquePTR &) = delete; //������ ������������ �� move 

	MyUniquePTR(C * target);

	MyUniquePTR & operator=(const C & target) = delete;
	MyUniquePTR<C> & operator=(C && target); //�� �������������� ������� MyUniquePTR<C> � MyUniquePTR &

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
	if (myobject != target) //�� ���� ������ � �� ����� ����
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
