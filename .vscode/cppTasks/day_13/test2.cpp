#include<bits/stdc++.h>
using namespace std;

int reversenumber(int n){
	int rev=0;
	while(n>0){
		int digit=n%10;
		rev=rev*10+digit;
		n=n/10;
	}
	return rev;
}
int main() 
{
int n=12345;
cout<<reversenumber(n);
return 0;
}