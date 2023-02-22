#include <iostream>
using namespace std;

int b_search(int arr[], int i, int temp) {    //j là số phần tử mảng cần xét, temp là biến để so sánh
    int l = 0;
    int r = i - 1;
    int m = (l + r) / 2;
    while (l < r) {
        if (temp == arr[m]) {
            return m + 1;
        }
        if (temp > arr[m]) {
            l = m + 1;
        }
        else if (temp < arr[m]) {
            r = m - 1;
        }
        m = (l + r) / 2;

    }

    if (temp > arr[m]) ++m;
    return m; //m là index của phần tử nhỏ nhất mảng đang xét sao cho arr[m]>temp
}

void b_insertion_sort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int temp = arr[i];

        // --insertion_sort--
        //    int j=0;
        //    while (arr[j]<=arr[i]) j++;
        //    for(int k=0; k<i-j; k++){
        //    arr[i-k]=arr[i-k-1];
        //    }
        //    arr[j]=temp;

        int m = b_search(arr, i, temp);
        for (int k = 0; k < i - m; k++) {
            arr[i - k] = arr[i - k - 1];
        }
        arr[m] = temp;
    }
}

int main() {
    const int n = 6;
    int arr[n] = { 3,2,4,5,1,6 };
    b_insertion_sort(arr, n);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }
    return 0;
}

