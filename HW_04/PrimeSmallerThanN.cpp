#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int n)
{
    if(n < 2) return false;
    for(int i = 2; i <= sqrt(n); i++)
        if(n % i == 0) return false;
    return true;
}

int main()
{
    int n; cin >> n;
    int c = 0;
    for(int i = 2; i < n; i++){
        if(isPrime(i)) c++;
    }
    cout << c;
    return 0;
}
