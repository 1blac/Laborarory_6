#pragma once
#include <iostream>
using namespace std;

// ���������, �� ����� �������� - ����� ���������
template<class T>
class Predicate
{
public:
	virtual bool operator () (T x) = 0;
};

// �������� ��������� ��������� - ��������, �� �������� ������� ����
template<class T>
class Zero : public Predicate<T>
{
public:
	virtual bool operator () (T x)
	{
		T zero = T();
		return x == zero;
	}
};

// �������� ��������� ��������� - ��������, �� �������� �������
// ������ ���� ��� �������� ����
template<class T>
class Positive : public Predicate<T>
{
public:
	virtual bool operator () (T x)
	{
		return x > 0;
	}
};

// �������� ��������� ��������� - ��������, �� �������� ��'����
// ������ ���� ��� �������� ����
template<class T>
class Negative : public Predicate<T>
{
public:
	virtual bool operator () (T x)
	{
		return x < 0;
	}
};

// �������� ��������� ��������� - ��������, �� �������� �����
// ������ ���� ��� ����� ����
template<class T>
class Even : public Predicate<T>
{
public:
	virtual bool operator () (T x)
	{
		return ((int)x % 2) == 0;
	}
};

// �������� ��������� ��������� - ��������, �� �������� �� �����
// ������ ���� ��� ����� ����
template<class T>
class Odd : public Predicate<T>
{
public:
	virtual bool operator () (T x)
	{
		return ((int)x % 2) != 0;
	}
};

// begin - �������� ������� �������� ���������� (����� �� ������ �������)
// end - �������� ���� �������� ���������� (����� �� ������� ���� ����������)
template<class T>
bool search(T* begin, T* end, T* begin2, T* end2)
{
	T* from = begin;
	T* from2 = begin2;
	for (T* from = begin; from < end; from++) // from - �������� ������� ����������
	{
		if (*from == *from2)
		{
			from2++; // from2 - �������� ������� ����������
		}
		else
		{
			from2 = begin2;
		}

		if (*from2 == *end2)
			return 1;

	}
	return 0;
}

template<class T>
bool search_if(T* begin, T* end, T* begin2, T* end2, Predicate<T>& p)
{
	T* from = begin;
	T* from2 = begin2;

	for (T* from = begin; from < end; from++) // from - �������� ������� ����������
	{
		if (p(*from)) // ���� ������������ ����� ���������
		{
			if (*from == *from2)
			{
				from2++; // from2 - �������� ������� ����������
			}
			else
			{
				from2 = begin2;
			}

			if (*from2 == *end2)
				return 1;
		}
	}
	return 0;
}

