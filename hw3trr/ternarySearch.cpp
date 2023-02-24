/* Cau 2
Ternary Search (Thuat toan tim kiem tam phan)

ternarySearch(x, a1,a2,a3,...an) {
// x: so nguyen can tim. a1.a2.a3,...an: cac so nguyen tang dan
    left = 1 (left la diem mut trai cua khoang tim kiem)
    right = n (right la diem mut phai cua khoang tim kiem)
    loca = 0;
while (left < right)
{
    p = (right - left)/3;
    mid1 = left + p; (mid1, mid2 la diem mut chia day lam 3 phan bang nhau)
    mid2 = right - p;

    if x = a[mid1] then loca = mid1; break;
    else if x = a[mid2] then loca = mid2; break;
    else if x < mid1 then right = mid1-1;
    else if x > mid2 then left = mid2+1;
    else left = mid1 and right = mid2;
}
return loca ( loca la chi so duoi so hang bang key hoac bang 0 neu khong tim thay key)
}

Cau 3
Cach hoat dong cua thuat toan tren voi ket qua tim x = 19 trong day 1,2,3,5,6,7,8,10,12,13,15,16,19,19,20,23

left	right	left < right	p	mid1	mid2	a[mid1]	a[mid2]	x(19)<,>,=mid1,mid2?	loca
1	    16	        T	        5	6	    11	    7	    15	    x > mid2	            0
12	    16	        T	        1	13	    15	    19	    20	    x = mid1	            13 (end)
Ket qua = 13

Cau 4
Lan lap thu nhat, pham vi tim kiem la n phan tu.
Lan lap thu 2, pham vi tim kiem la n/3
...
Truong hop xau nhat, vong lap ket thuc khi pham vi tìm kiem n/(3^i) = 1 hay i = log3(n)
Coi moi lan lap thoi gian la O(1) thi thoi gian ham thuc hien la O(log3(n))
=> Vay do phuc tap thoi gian O(log3(n)) voi n la so phan tu cua day
*/


#include <iostream>

using namespace std;

int ternarySearch(int key, int A[], int left, int right)
{
    //left = 0; right = n-1 voi n la so phan tu cua day do mang trong C++ danh so tu 0
    if (left > right) return 0;

    int p = (right - left)/3;
    int mid1 = p +left;
    int mid2 = right - p;

    if (A[mid1] == key) return mid1+1;
    else if (A[mid2] == key) return mid2+1;
    else if(key < A[mid1]) {
        return ternarySearch(key, A, left, mid1-1);
    }
    else if (key> A[mid2]) {
        return ternarySearch(key, A, mid2+1, right) ;
    }
    else return ternarySearch(key, A, mid1, mid2);

}

int main ()
{
    int key = 19;
    int A[16] = {1,2,3,5,6,7,8,10,12,13,15,16,19,19,20,23};
    int x = ternarySearch(key, A, 0, 15);
    cout << x;
    return 0;
}
