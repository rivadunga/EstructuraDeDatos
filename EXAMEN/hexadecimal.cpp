#include<iostream>
#include<string.h>
using namespace std;

string digitos[] = {"0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"};

string transformar(int n)
{
    if (n > 0)
    {
        int dig = n%16;
        string digStr = digitos[dig];
        n = (n - n%16)/16;
        return digStr + transformar(n);
    }
    return "";


}



int main()
{
    int n;
    cin >> n;
    string hex = transformar(n);
    for (int i = hex.length()-1; i >=  0; i--){
        cout << hex[i];
    }
    return 0;
}
