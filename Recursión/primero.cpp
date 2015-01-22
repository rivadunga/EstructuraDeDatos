#include <iostream>
using namespace std;

int mcd(int m, int n)
{
    if ( !( m == 0 || n == 0))
    {

        if (m > n)
        {
            int mod = m % n;
            if (mod == 0)
                cout << "MCD = " << n << endl;
            else
                return mcd(mod,n);
        }else
        {
            int mod = n % m;
             if (mod == 0)
                cout << "MCD = " << m << endl;
            else
                return mcd(mod,m);

        }
    }
}

int main()
{
    int a, b;
    cin >> a >> b;
    mcd (a,b);
    return 0;
}
