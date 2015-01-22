#include <iostream>
using namespace std;


int suma(int num){
    if (num > 0){
        return (num % 10) + suma( (num - (num%10))/10);
    }
    else
        return 0;
}

int main()
{
   int num;
   cin >> num;
   cout << suma(num) << endl;

}

