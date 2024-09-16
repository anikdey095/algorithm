#include<bits/stdc++.h>
using namespace std;
 struct knapshak{
     int price;
     int weight;
 };
 static bool cmp(struct knapshak x,struct knapshak y)
 {
     double r1 = (double)x.price / (double)x.weight;
     double r2 = (double)y.price / (double)y.weight;
     return r1 > r2;
 }
 double fractional(knapshak arr[], int n, int c)
 {
     double finalvalue = 0.0;
     sort(arr, arr +n, cmp);
     for (int i = 0; i < n;i++){
        if(c>=arr[i].weight){
            c -= arr[i].weight;
            finalvalue += arr[i].price;
           
        }
        else{

            finalvalue += arr[i].price * ((double)c / arr[i].weight);
            break;
        }
     }
     return finalvalue;
 }
int main(){
    int n;
    cin >> n;
    knapshak arr[n];
    for (int i = 0; i < n;i++){
        cin >> arr[i].price >> arr[i].weight;
    }
    int capacity;
    cin >> capacity;
    cout << fixed << setprecision(2) << fractional(arr, n, capacity);
}
