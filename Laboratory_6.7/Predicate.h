#pragma once
#include <iostream>
using namespace std;

// інтерфейс, що описує функтори - унарні предикати
template<class T>
class Predicate
{
public:
	virtual bool operator () (T x) = 0;
};

// реалізуємо інтерфейс функтором - перевірка, чи значення дорівнює нулю
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

// реалізуємо інтерфейс функтором - перевірка, чи значення додатне
// працює лише для числових типів
template<class T>
class Positive : public Predicate<T>
{
public:
	virtual bool operator () (T x)
	{
		return x > 0;
	}
};

// реалізуємо інтерфейс функтором - перевірка, чи значення від'ємне
// працює лише для числових типів
template<class T>
class Negative : public Predicate<T>
{
public:
	virtual bool operator () (T x)
	{
		return x < 0;
	}
};

// реалізуємо інтерфейс функтором - перевірка, чи значення парне
// працює лише для цілих типів
template<class T>
class Even : public Predicate<T>
{
public:
	virtual bool operator () (T x)
	{
		return ((int)x % 2) == 0;
	}
};

// реалізуємо інтерфейс функтором - перевірка, чи значення не парне
// працює лише для цілих типів
template<class T>
class Odd : public Predicate<T>
{
public:
	virtual bool operator () (T x)
	{
		return ((int)x % 2) != 0;
	}
};

// begin - ітератор початку вхідного контейнера (вказує на перший елемент)
// end - ітератор кінця вхідного контейнера (вказує на елемент після останнього)
template<class T>
bool search(T* begin, T* end, T* begin2, T* end2)
{
	T* from = begin;
	T* from2 = begin2;
	for (T* from = begin; from < end; from++) // from - ітератор першого контейнера
	{
		if (*from == *from2)
		{
			from2++; // from2 - ітератор другого контейнера
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

	for (T* from = begin; from < end; from++) // from - ітератор першого контейнера
	{
		if (p(*from)) // якщо справджується умова предикату
		{
			if (*from == *from2)
			{
				from2++; // from2 - ітератор другого контейнера
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

