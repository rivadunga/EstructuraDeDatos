#include<iostream>
#include"Stack.h"
using namespace std;
using namespace vcn;



void transformar(int n)
{
    Stack<int> res;
    while (n > 0)
    {
        int a = n%2;
        res.push(a);
        n = (n-a)/2;
    }
    cout << res;
}


int main()
{
    int num;
    cin >> num;
    transformar(num);
}
