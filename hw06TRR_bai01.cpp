#include <bits/stdc++.h>
using namespace std;
string s;
int n;
int ones( int i)
{
    if (i >= n)
    {
        return 0;
    }
    else
    {
        int dem = ones(i+1);
        if (s[i] == '1')
        {
            return dem + 1;
        }
        else
        {
            return dem;
        }
    }
}

int main()
{
    cin >> s;
    n=s.length();
    int dem = ones(0);
    cout << dem << endl;
}