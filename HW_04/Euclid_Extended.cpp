#include <iostream>
#include <cmath>

using namespace std;

int euclid(int m, int n)
{
    int a = m, b = n;
    if(m < n) swap(m, n);
    int xm = 1, ym = 0;
    int xn = 0, yn = 1;
    while(n != 0){
        int q = m / n;
        int r = m % n;
        int xr = xm - q * xn;
        int yr = ym - q * yn;
        xm = xn;
        ym = yn;
        xn = xr;
        yn = yr;
        m = n;
        n = r;
    }
    if(xm * a + ym * b == 1) return xm;
    else return ym;
}

int main()
{
    int a, b;
    cin >> a >> b;
    int d = euclid(a, b);
    cout << d;
    return 0;
}
