#include<bits/stdc++.h>
using namespace std;
int main(){
    string s, s1;
    cin >> s >> s1;
    int l = s.length();
    int l1 = s1.length();
      s = " " + s;
      s1 = " " + s1;
    int dp[l+1][l1+1];
    for (int i = 0; i <= l;i++){
        for (int j = 0; j <= l1;j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
            }
            else if(s[i]==s1[j]){
                dp[i][j] = dp[i - 1][j-1] + 1;
            }
            else{
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    int i = l, j = l1;
    string x;
    while(i>0 && j>0){
        if((dp[i][j]-dp[i-1][j-1])==1 && s[i]==s1[j])
        {
            x += s[i];
            i--;
            j--;
        }
       else  if(dp[i][j-1]==dp[i][j]){
            j--;
        }
        else 
        {
            i--;
        }
        
    }
    reverse(x.begin(), x.end());
   
   cout<<x << endl;
}
