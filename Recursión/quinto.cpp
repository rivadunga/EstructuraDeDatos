#include<iostream>
using namespace std;

void voltear(int num){
    if (num > 0)
        cout << num%10;
        voltear((num - (num%10))/10);
}

int main()
{
    int num;
    cin >> num;
    voltear(num);
}
