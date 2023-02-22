#include <iostream>
using namespace std;

void insertion_sort(int arr[], int n, int& count) {
    for (int i = 1; i < n; i++) {
        ++count;
        int temp = arr[i];
        int j=0;
        while (arr[j]<=arr[i]){ j++;  ++count;}
        ++count;
        for(int k=0; k<i-j; k++){
            //++count;
            arr[i-k]=arr[i-k-1];
        }
        arr[j]=temp;
    }
}

int main() {
    const int n = 8;
    int count = 0;
    int arr[n] = { 7,4,3,8,1,5,4,2 };
    insertion_sort(arr, n, count);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }
    cout<<endl<<count;
    return 0;
}
