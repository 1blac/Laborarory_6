#include <iostream>
#include <string>

using namespace std;

template <typename T>
T Sort( T arr[], const int size, int i);

template <typename T>
void Print(const T arr[], const int size, int i);

int main()
{
    int i = 0;
    int arr[12] = { 1488, 228, 1337, 69, 13, 666, -1, 9, 777, 96, -100, 3 };
    Print(arr, size(arr), i);
    Sort(arr, size(arr), i) ;
    cout << "Sort = ";
    Print(arr, size(arr), i);
    return 0;
}

template <typename T>
T Sort( T arr[], const int size, int i) // ����� ����� (���������)
{
    T tmp = arr[0];
    for (int j = 0; j < size - i; j++) // ����� ��������� ��������
        if (arr[j - 1] > arr[j]) // ���� �������� ����� �������������
        { // - ���� �������� ������
            tmp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = tmp;
        }
    if (i < size - 1) // i - �������� ��������
        Sort(arr, size, i + 1);
    return tmp;
}

template <typename T>
void Print(const T arr[], const int size, int i)
{
    cout << arr[i] << "  ";
    if (i < size - 1)
        Print(arr, size, i + 1);
    else
        cout << endl;
}