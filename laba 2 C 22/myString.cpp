#include <string>
#include "myString.h"
using namespace std;

// ќпределение конструктора.

MyString::MyString()
{
	m_pStr = nullptr; // записывает ноль default
}

MyString::MyString(const char * S)
{
	int length; // переменна€ длины строки
	length = strlen(S); // в нее записываем данные которые вернула функци€ (число символов в строке без 0)

	m_pStr = new char[length + 1]; // динамически выдел€ем пам€ть под массив символов + 1 дл€ нул€

	strcpy(m_pStr, S); // вызываем функцию котора€ переписывает данные в адрес 1 из адреса 2
}

const char * MyString::GetString() const // const не хватает
{
	return m_pStr;
}

void MyString::SetNewString(const char * const S) 
{
	delete [] m_pStr;            //могу так делать????????

	int length = strlen(S);
	
	m_pStr = new char[length + 1];
	strcpy(m_pStr, S);
}

MyString::MyString(const MyString & other)
{
	if (other.m_pStr != nullptr)
	{
		int size = strlen(other.m_pStr) + 1;

		m_pStr = new char[size];

		strcpy(m_pStr, other.m_pStr);
	}
	else
	{
		m_pStr = nullptr;
	}
}

MyString::MyString(MyString && other)
{
	m_pStr = other.m_pStr;

	other.m_pStr = nullptr;
}
// ќпределение деструктора.

MyString::~MyString()
{
	delete [] m_pStr;
}

std::ostream & operator<<(std::ostream & OUT, const MyString & MYSTRING)
{
	OUT << "contents: \"" << MYSTRING.m_pStr << "\"";


	return OUT;
	// TODO: вставьте здесь оператор return
}

MyString KonFun(const char * a, ...)
{
	const char ** arrCh = &a;
	int counter = 0;

	for (int i = 0; ; i++)
	{
		const char * pChar = *(arrCh + i);

		if (*pChar == '\0')
		{
			break;
		}
		else
		{
			for (int j = 0; ; j++)
			{
				if (*pChar != '\0')
				{
					counter++;
					pChar++;
				}
				else
				{
					break;
				}
			}
		}
	}

	char * arrMyString = new char[counter + 1];

	for (int i = 0; i < counter; )
	{
		for (int j = 0; ; )
		{
			if ((*arrCh)[j] != '\0')
			{
				arrMyString[i] = (*arrCh)[j];
				i++;
				j++;
			}
			else
			{
				arrCh++;
				break;
			}
		}
	}

	arrMyString[counter] = '\0';

	MyString object(arrMyString);

	delete[] arrMyString;

	return object;
}

MyString& MyString::operator=(const MyString & a)
{
	if (this != &a)                //проверил не одини тот же ли объект с двух сторон знака равно
	{
		delete [] m_pStr;             //удал€ю свое, если там ноль то ничего не произойдет

		if (a.m_pStr != nullptr)         // а вдруг там не 0 тогда
		{
			int size = strlen(a.m_pStr) + 1;    // смотрю сколько там лежит

			m_pStr = new char[size];		//выделю столько же пам€ти под мой массив

			strcpy(m_pStr, a.m_pStr);	// и копирую все к себе

			// а delete у мен€ в деструкторе
		}
		else
		{
			m_pStr = nullptr;           //занул€ю свое
		}
	}

	return *this;          //объект по моему адресу полученные разыменованием
}

MyString& MyString::operator=(const char * a)
{
	delete[] m_pStr;

	int size = strlen(a) + 1;

	m_pStr = new char[size];

	strcpy(m_pStr, a);

	return *this;
}

MyString& MyString::operator=(MyString && a)
{
	if (this != &a)
	{
		delete[] m_pStr;

		this->m_pStr = a.m_pStr;

		a.m_pStr = nullptr;
	}

	return *this;
}

MyString & MyString::operator+=(const MyString & incomeString)
{
	int size = 0;
	size = strlen(this->m_pStr) + strlen(incomeString.m_pStr) + 1;

	char * newleftvalue = new char[size];

	for (int i = 0, j = 0, q = 0; i < size; i++)
	{
		if (this->m_pStr[j] != '\0')
		{
			newleftvalue[i] = this->m_pStr[j];
			j++;
		}
		else
		{
			newleftvalue[i] = incomeString.m_pStr[q];
			q++;
		}
	}

	newleftvalue[size] = '\0';

	delete[] this->m_pStr;

	this->m_pStr = newleftvalue;

	return *this; 

}

MyString MyString::operator+(const MyString &) const
{
	//сделать дома 
	return MyString();
}
