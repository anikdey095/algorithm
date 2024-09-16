#include<bits/stdc++.h>
using namespace std;
void heapify(int arr[],int n,int i){
    int left = i * 2 + 1;
    int right = i * 2 + 2;
    if(left<n && arr[left]<arr[i]){
        swap(arr[left], arr[i]);
        heapify(arr, n, left);
    }
    if (right < n && arr[right] < arr[i])
    {
        swap(arr[right], arr[i]);
        heapify(arr, n, right);
    }
    
}
void heapsort(int arr[],int n){
    for (int i = n/2-1; i >=0;i--){
        heapify(arr, n,i);
    }
    for (int i = n - 1; i > 0;i--){
        swap(arr[i], arr[0]);
        heapify(arr, i,0);
    }
}
void printheap(int arr[],int n){
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n;i++){
        cin >> arr[i];
    }
    heapsort(arr, n);
    printheap(arr, n);
}
