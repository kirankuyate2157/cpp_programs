#include <iostream>
using namespace std;
// implimentation of vectore using arrays
template <typename T> //   taking user defined data type of vectore
class vector          //making vectore class
{
       T *arr;           //initializing array
    int counter = 0;  // counter conting elements
    int cur_size = 0; //array size
public:
 
    vector()
    {
        arr = new T[2]; //array initialize with size 2
        counter = 0;
        cur_size = 2; //now array size is 2
    }



    void push_back(T data) //inserting elements to vectore
    {
        if (counter == cur_size) //when first size array was full then  double the size of the array
        {
            T *temp = new T[2 * cur_size]; //craeting  temporatry array with double size
            for (int i = 0; i < cur_size; i++)
            {
                temp[i] = arr[i]; //copying first array elements to temp array
            }
            T *temp2 = arr; //storing the previous full array adres to temp2 for deleting to them deallocation purpos
            arr = temp;     //arr storeinng double size array addres now array become double
            delete (temp2); //deallocating  temp2 addres
            cur_size *= 2;  //incrasing current array size
        }
        arr[counter] = data; //inserting the element
        counter++;           //inctreasing counter
    }


    int  size(){
        return counter;
    }


    void display() //showing or ptinting the vectore elements
    {
        for (int i = 0; i < counter; i++) //using loop 0 to counter
        {
            cout << arr[i] << " "; //printing elements
        }
        cout << "\n"; //new line
    }


    void pop_back() //deleeting last element
    {
        if (counter == 0) //when vector was empty
        {
            cout << "nothing for deleting ....vectore empty ";
            return;
        }
        if (2 * counter == cur_size) // when  counter of array is going to half of array  cur_size  i mean half array was filled and half was empty
        {

            T *temp = new T[cur_size / 2];       //making half size of current size temp array
            for (int i = 0; i < counter; i++)
            {
                temp[i] = arr[i];      //cpying elements
                cur_size /= 2;         //noew current size is half
            }
            T *temp2 = arr;     //initialize for deallocatingf purpose
            arr = temp;       //copying half temp array addres to arr
            delete (temp2);       //deallocating  full size array
        }
        counter--;        // deleting elemrnts by decreasing  counter 
    }


};

int main()
{
    vector<int,int> v;

    cout << "\n"<< "  ";
    cout << v.size() << "  ";
    return 0;
}