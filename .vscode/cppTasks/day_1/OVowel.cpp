#include <iostream>
using namespace std;
void check(char c){
    int LoweVowel, upperVowel;
    LoweVowel = (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    upperVowel = (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');

    if (LoweVowel || upperVowel)
        cout << c << " is Vowel \n";
    else
        cout << c << "  is a consonant\n";

}

int main()
{
char a='j';
char b='a';
char c='z';
check(a);
check(b);
check(c);
    

    return 0;
}


/*

Output  ---->


PS F:\Cpp_programes\.vscode\cppTasks\day_1> cd "f:\Cpp_programes\.vscode\cppTasks\day_1\" ; if ($?) { g++ OVowel.cpp -o OVowel } ; if ($?) { .\OVowel }
j  is a consonant
a is Vowel 
z  is a consonant


*/
