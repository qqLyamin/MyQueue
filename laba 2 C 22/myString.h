#pragma once
#include <iostream>

class MyString
{
    char * m_pStr;	//строка-член класса

	public:

		MyString();
		MyString(const char * S);
		const char * GetString() const;
		void SetNewString(const char * const S);

		MyString(const MyString & other);
		MyString(MyString && other);

		MyString& operator=(const MyString &);

		MyString& operator=(const char *);

		MyString& operator=(MyString && a);

		MyString& operator+=(const MyString&); 

		MyString operator+(const MyString&) const; //дома

		friend std::ostream&  operator<<(std::ostream&, const MyString&);

		~MyString();

};

MyString KonFun(const char * a, ...);

