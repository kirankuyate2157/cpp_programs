#include <bits/stdc++.h>
using namespace std;

template <class K, class V>
class MyUnorderedMap
{
    private:
    vector<pair<K, V>> *arr;
    int size = 3;
    int unique = 0;
    hash<K> Myhashfunction;

public:
    MyUnorderedMap(){
        arr = new vector<pair<K, V>>[size];
    }

    int gethash(K key){
        return Myhashfunction(key);
    }

    bool finddensity(){
        return (size + 0.0f) / (unique + 0.0f) >= 2.0f;
    }

    bool isPresent(K key){
        int index = abs(gethash(key)) % size;
        for (pair<K, V> p : arr[index]){
            if (p.first == key){
                return true;
            }
        }
        return false;
    }

    void reDistribution(int newSize)
    {
        vector<pair<K, V>> *temp = new vector<pair<K, V>>[newSize];
        swap(arr, temp);
        int tempSize = size;
        int size = newSize;
        unique = 0;
        for (int i = 0; i < tempSize; i++){
            for (pair<K, V> p : temp[i]){
                insert(p.first, p.second);
            }
        }
        delete(temp);
    }

    void insert(K key, V value)
    {
        int index = abs(gethash(key)) % size;
        if (isPresent(key)){
            int presentIndx = 0;
            for (int i = 0; i < arr[index].size(); i++){
                if (arr[index][i].first == key){
                    presentIndx = i;
                }
            }
            arr[index][presentIndx].second = value;
            return;
        }
        arr[index].push_back({key, value});
        unique++;

        if (!finddensity()){
            reDistribution(2 * size);
        }
    }

    void remove(K key)
    {
        int index = abs(gethash(key)) % size;
        if (!isPresent()){
            return;
        }
        arr[index].erase(arr[index].find({key, get(key)}));
        unique--;
        if (!finddensity()){
            reDistribution(size / 2);
        }
    }

    V get(K key)
    {
        int index = abs(gethash(key)) % size;
        for (pair<K, V> p : arr[index]){
            if (p.first == key){
                return p.second;
            }
        }
        return -1;
    }

    void display(){
        for (int i = 0; i < size; i++){
            cout << i << " : ";
            for (pair<K, V> p : arr[i]){
                cout <<"("<< p.first << " : " << p.second <<")";
            }
            cout << "\n #-------------------#----------------------#\n";
        }
    }

    vector<int> displayGreaterK(int k)
    {
        vector<int> ans;
        for (int i = 0; i < size; i++){
            for (pair<K, V> p : arr[i]){
                if (p.second >= k){
                    ans.push_back(p.first);
                }
            }
        }
        return ans;
    }

};

int main()
{
    MyUnorderedMap<int,int> mp;
    int n;
    cin>>n;

  while(n!=0){
        int item;
        cin>>item;
        if(mp.isPresent(item)){
            mp.insert(item,mp.get(item)+1);;
        }else{
            mp.insert(item,1);
        }
        mp.display();
        n--;
    }
    
    mp.display();

    return 0;
}