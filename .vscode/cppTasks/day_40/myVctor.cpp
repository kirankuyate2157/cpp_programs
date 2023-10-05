#include <bits/stdc++.h>
using namespace std;

template <typename T>
class myvector
{
    T *arr;
    int arr_size;
    int counter;

public:
    myvector()
    {
        arr = new T[2];
        counter = 0;
        arr_size = 2;
    }
    void push_back(T x)
    {
        if (counter == arr_size)
        {
            T *temp = new T[arr_size * 2];
            for (int i = 0; i < arr_size; i++)
            {
                temp[i] = arr[i];
            }
            T *temp2 = arr;
            arr = temp;
            delete (temp2);
            arr_size *= 2;
        }
        arr[counter++] = x;
    }

    int size()
    {
        return counter;
    }

    T pop_back()
    {
        if (counter == 0)
            return T(NULL);
        if (counter * 2 == arr_size)
        {
            T *temp = new T[arr_size / 2];
            for (int i = 0; i < arr_size / 2; i++)
            {
                temp[i] = arr[i];
            }
            T *temp2 = arr;
            arr = temp;
            delete (temp2);
            arr_size = arr_size / 2;
        }
        T k = arr[counter - 1];
        counter--;
        return k;
    }
};

int main()
{
    myvector<int> arr;
    arr.push_back(1);
    arr.push_back(3);
    arr.push_back(6);
    arr.push_back(9);
    cout << "size of array " << arr.size() << endl;
    cout << "poped element " << arr.pop_back() << endl;
    cout << "poped element " << arr.pop_back() << endl;
    cout << "poped element " << arr.pop_back() << endl;
    cout << "size of array " << arr.size() << endl;
    cout << "poped element " << arr.pop_back() << endl;
    cout << "poped element " << arr.pop_back() << endl;
    cout << "poped element " << arr.pop_back() << endl;
    cout << "size of array " << arr.size() << endl;
    cout << "size of array " << arr.size() << endl;
    return 0;
}