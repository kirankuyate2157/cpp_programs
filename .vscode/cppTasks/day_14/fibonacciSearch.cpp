#include <bits/stdc++.h>
using namespace std;

int fibSearch(int arr[], int n, int x)
{
    int FbMn2 = 0;
    int FbMn1 = 1;
    int FbMn = FbMn1 + FbMn2;
    while (FbMn < n)
    {
        FbMn2 = FbMn1;
        FbMn1 = FbMn;
        FbMn = FbMn1 + FbMn2; // making fibonacci series
    }
    int offset = -1; // offsert initialized by  -1
    while (FbMn > 1) // fibenocci    FbMn is grater greter than   0,1,1
    {

        int i = min((offset + FbMn2), n - 1); // fining possible arr index number which is equal to  X.
        if (arr[i] < x)
        {
            if (arr[i] < x) // if arr[i] value is less  move FbMn to one step down
            {
                FbMn = FbMn1;
                FbMn1 = FbMn2;
                FbMn2 = FbMn - FbMn1;
                offset = i;
            }
        }

        else if (arr[i] > x) // if arr[i] value is greater then  move FbMn two step down
        {
            FbMn = FbMn2;
            FbMn1 = FbMn1 - FbMn2;
            FbMn2 = FbMn - FbMn1;
        }
        else
        {
            return i; // when arr[i] nor be greater and less than X then ti will  return i either it will equal to x or not equal to x/
        }
    }

    if (FbMn1 && arr[offset + 1] == x) // FbMn is true while it was greater than 1 &&  arr values 0 base index so we increasing offset by one  so then  Fibonacci is greater than 1 as well as arr[offset +1] is matching with x then it will return index of unsirted array where the x is maching with unsorted array with  i th index value
        return offset + 1;

    return -1; // when offset + 1 index not maching with  X  then return false value (-1);
}

int main()
{
    int arr[] = {3, 6, 1, 6, 13, 88, 17, 20, 27, 990, 1, 60, 55, 250}; // given a unsorted array
    int n = sizeof(arr) / sizeof(int);                                 // size of given  array
    int x = 250;                                                       // which element we should to search
    cout << fibSearch(arr, n, x);                                      // calling Fibbonacci search array which returning values  index of unsorted array;

    return 0;
}
