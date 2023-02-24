#include "bits/stdc++.h"
using namespace std;

void countingSort(int arr[100], int n)
  {
    int count[100];  //khởi tạo mảng mà mỗi phần tử là số lần xuất hiện của giá trị chỉ số
    //cho tất cả các phần tử của mảng count = 0, nghĩa là ban đầu chưa có số nào xuất hiện trong mảng
    for (int i = 0; i <= 100; i++) {
        count[i] = 0;
    }
    //chạy mảng arr và đếm dần số lần xuất hiện của các số trong mảng, của số arr[i] thì sẽ có count[arr[i]] lần xuất hiện
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }
    // chạy mảng count, count[arr[i]] > 0 thì đưa ra arr[i] luôn vì chắc chắn arr[i] đó là bé hơn do i chạy từ min đến max
    for (int i = 0; i <= 100; i++) {
        while (count[i] > 0) {
            cout << i << " ";
            count[i]--;
        }
    }
}

int main(){
    int a[100];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    countingSort(a,n);
    return 0;

}
