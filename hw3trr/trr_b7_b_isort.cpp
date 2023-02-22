#include <iostream>
using namespace std;

int b_search(int arr[], int i, int temp,int &count){
    int l=0;
    int r=i-1;
    int m=(l+r)/2;

    while(l<r){
        ++count;
        if(temp == arr[m]){
            return m+1;
            ++count;
        }
        if(temp>arr[m]){
            l=m+1;
            ++count;
        }
        else if(temp<arr[m]){
            r=m-1;
            ++count;
        }
        m=(l+r)/2;
        if(l>=r) ++count;
    }
    ++count;
    if(temp > arr[m]) ++m;
    return m; //m là index của phần tử đầu tiên sao cho arr[m]>temp
}

void b_insertion_sort(int arr[],int n, int & count){
    for(int i=1; i<n; i++){
        ++count;
        int temp = arr[i];
        int m = b_search(arr,i,temp,count);
        for(int k=0; k<i-m; k++){
            ++count;
            arr[i-k]=arr[i-k-1];
        }
        arr[m]=temp;
    }
}

int main(){
    int n=6;
    int count =0;   // đếm số phép so sánh
    int arr[n] = {7,4,3,8,1,5,4,2};
    b_insertion_sort(arr,n,count);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<' ';
    }
    cout<<endl;
    cout<<count;
    return 0;
}

