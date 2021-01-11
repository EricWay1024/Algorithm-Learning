//#include <bits/stdc++.h>
#include<algorithm>
#include<bitset>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<deque>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<utility>
#include<vector>
#include<numeric>
#include<functional>
#include<cstdint>
#include<climits>
using namespace std;

template<class T>
void printArray(T a[], int n){
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

template<class T>
void insertionSort(T a[], int n) {
    int i, j;
    T temp;

    for(int i=1; i<n; i++) {
        int j=i;
        T temp = a[i];
        while (j > 0 && temp < a[j-1]){
            printf("i=%d, j=%d\n", i, j);
            printArray(a, n);
            a[j]=a[j-1];
            j--;
            printArray(a, n);
        }
        a[j]=temp;
        printf("i=%d, j finished\n", i);
        printArray(a, n);
    }
}

int main() {
    int a[] = {5, 4, 2, 3, 7};
    insertionSort(a, 5);

    return 0;
}