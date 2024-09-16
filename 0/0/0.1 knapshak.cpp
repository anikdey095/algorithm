#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int w[n], v[n];
    for (int i = 0; i < n;i++){
        cin >> w[i] >> v[i];
    }
    int capacity;
    cin >> capacity;
    int kn[n+1][capacity+1];
    for (int i = 0; i <= n;i++){
        for (int j = 0; j <= capacity;j++){
    if(i==0 || j==0){
        kn[i][j] = 0;
    }
    else if(w[i-1]<=j){
        kn[i][j] = max(kn[i - 1][j], kn[i - 1][j - w[i - 1]] + v[i - 1]);
    }
    else{
        kn[i][j] = kn[i - 1][j];
    }
        }
    }
    cout << kn[n][capacity] << endl;//find max

    int mx = kn[n][capacity];
    int ct = capacity;
    for (int i = n; i > 0 && mx > 0;i--){
        if(mx==kn[i-1][ct]){
            continue;
        }
        else{
            cout << w[i - 1] << " ";
            mx -= v[i - 1];
            ct -= w[i - 1];
        }
        cout << endl;
    }
}
