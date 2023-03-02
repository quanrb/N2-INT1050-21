#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//viet n duoi dang nhi phan (nguoc lai)
vector<int> binaryOfn(int n)
{
    vector<int> v;
    while(n > 0){
        int x = n % 2;
        v.push_back(x);
        n /= 2;
    }
    return v;
}

int main()
{
    int a, b, m;
    cin >> a >> b >> m;
    vector<int> bi_b = binaryOfn(b);
    a %= m;
    int x = 1;
    int power = a;
    for(int i = 0; i < bi_b.size(); i++){
        if(bi_b[i] == 1){
            //x = x * (a^2^i)^bi_b[i]
            x = (x * power) % m;
        }
        //power = (a)^2^i
        power = (power * power) % m;
    }
    cout << x;
    return 0;
}
