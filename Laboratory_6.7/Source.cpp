#include "Array.h"
#include "Predicate.h"
#include <iostream>
#include <time.h>
#include <stdexcept>
#include <exception>
#include <cmath>

using namespace std;

typedef Array::value_type* TArray;

Array func(double arr[], const int size)
{
	//First Array
	Array res = Array(size);

	//Fill array with random values (-50..50)
	srand((unsigned)time(NULL));
	Array::value_type A = -50;
	Array::value_type B = 50;
	for (int i = 0; i < size; i++)
	{
		res[i] = A + rand() % int(B - A + 1);
		//res[i] = i - 5;
	}
	cout << "Array with random values : { " << res << " }" << endl;

	//Add Sum & Mean to result array
	res.commonPart();
	cout << "Array plus two additional elements : { " << res << " }" << endl;

	res.individualPart();
	//cout << res;	

	return res;
}

int main()
{
	const int size = 10;
	double arr[size];

	Array taskArray = func(arr, size);
	cout << "Result array : { " << taskArray << " }" << endl;

	Array searchArray = Array(3);
	searchArray[0] = -1;
	searchArray[1] = 0;
	searchArray[2] = 1;
	cout << "SearchArray : { " << searchArray << " }" << endl;

	Array searchZero = Array(1);
	searchZero[0] = 0.0;
	cout << "searchZero : { " << searchZero << " }" << endl;

	Array searchPositive = Array(2);
	searchPositive[0] = 1;
	searchPositive[1] = 2;
	cout << "searchPositive : { " << searchPositive << " }" << endl;

	Array searchNegative = Array(2);
	searchNegative[0] = -2;
	searchNegative[1] = -1;
	cout << "searchNegative : { " << searchNegative << " }" << endl;

	Array searchEven = Array(2);
	searchEven[0] = 2;
	searchEven[1] = 4;
	cout << "searchEven : { " << searchEven << " }" << endl;

	Array searchOdd = Array(2);
	searchOdd[0] = 1;
	searchOdd[1] = 3;
	cout << "searchOdd : { " << searchOdd << " }" << endl;


	cout << endl;


	cout << "searchArray sequence exists in Result array : " << (search(taskArray.begin(), taskArray.end(), searchArray.begin(), searchArray.end()) ? "true" : "false") << endl;

	Predicate<double>* zero = new Zero<double>(); //functor: "zero elements"
	cout << "searchArray sequence exists in Result array with Zero func : " << (search_if(taskArray.begin(), taskArray.end(), searchArray.begin(), searchArray.end(), *zero) ? "true" : "false") << endl;
	cout << "searchZero sequence exists in Result array with Zero func : " << (search_if(taskArray.begin(), taskArray.end(), searchZero.begin(), searchZero.end(), *zero) ? "true" : "false") << endl;

	Predicate<double>* positive = new Positive<double>(); //functor: "positive elements" 
	cout << "searchArray sequence exists in Result array with Positive func : " << (search_if(taskArray.begin(), taskArray.end(), searchArray.begin(), searchArray.end(), *positive) ? "true" : "false") << endl;
	cout << "searchPositive sequence exists in Result array with Positive func : " << (search_if(taskArray.begin(), taskArray.end(), searchPositive.begin(), searchPositive.end(), *positive) ? "true" : "false") << endl;

	Predicate<double>* negative = new Negative<double>(); //functor: "Negative elements" 
	cout << "searchArray sequence exists in Result array with Negative func : " << (search_if(taskArray.begin(), taskArray.end(), searchArray.begin(), searchArray.end(), *negative) ? "true" : "false") << endl;
	cout << "searchNegative sequence exists in Result array with Negative func : " << (search_if(taskArray.begin(), taskArray.end(), searchNegative.begin(), searchNegative.end(), *negative) ? "true" : "false") << endl;

	Predicate<double>* even = new Even<double>(); //functor: "Even elements" 
	cout << "searchArray sequence exists in Result array with Even func : " << (search_if(taskArray.begin(), taskArray.end(), searchArray.begin(), searchArray.end(), *even) ? "true" : "false") << endl;
	cout << "searchEven sequence exists in Result array with Even func : " << (search_if(taskArray.begin(), taskArray.end(), searchEven.begin(), searchEven.end(), *even) ? "true" : "false") << endl;

	Predicate<double>* odd = new Odd<double>(); //functor: "Odd elements" 
	cout << "searchArray sequence exists in Result array with Odd func : " << (search_if(taskArray.begin(), taskArray.end(), searchArray.begin(), searchArray.end(), *odd) ? "true" : "false") << endl;
	cout << "searchOdd sequence exists in Result array with Odd func : " << (search_if(taskArray.begin(), taskArray.end(), searchOdd.begin(), searchOdd.end(), *odd) ? "true" : "false") << endl;

	return 0;
}