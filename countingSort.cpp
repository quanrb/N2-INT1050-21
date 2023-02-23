#include "bits/stdc++.h"
using namespace std;

int MAX = 1e5;


void countingSort(int a[], int n) {
    int count[MAX];
    for(int i = 0; i < MAX; i++) {
        count[i] = 0;
    }
    int output[n];
    for(int i  = 0; i < n; i++) {
        count[a[i]]++;
    }

    for(int i = 1; i < MAX; i++) {
        count[i] += count[i-1];
    }

    for(int i = 0; i < n; i++) {
        output[count[a[i]] - 1] = a[i];
        count[a[i]]--;
    }

    for(int i = 0; i < n; i++) {
        a[i] = output[i];
    }
}


int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    countingSort(a, n);
    for(int i  = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}