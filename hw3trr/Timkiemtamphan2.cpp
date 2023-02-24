#include<iostream>
using namespace std;

int TimKiemTamPhan(int *a, int n, int x) {
    int L=0;
    int R=n-1;
    while (L<=R) {
        int m1,m2;
        m1=(R-L)/3+L;
        m2=(m1+R)/2;
        if(a[L]<x && x<a[m1]) {
           R=m1-1;}
        else if(a[m1]<x && x<a[m2]) {
            L=m1+1;
            R=m2-1;
        }
        else if(a[m2]<x && x<a[R]) {
            L=m2+1;}
        else if(a[m1]==x) {return m1+1;}
        else if(a[m2]==x) {return m2+1;}
}
    return 0;

    }

int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    int x;
    cin >> x;
    cout << TimKiemTamPhan(a,n,x) << endl;}