#include<bits/stdc++.h>
using namespace std;
struct activity{
    char c;
    int s;
    int e;
};

 bool cmp(activity a,activity b){
    return  a.e < b.e;
} 
int main()
{
    int n;
    cin >> n;
    activity arr[n];
    for (int i = 0; i < n;i++)
        {
            cin >> arr[i].c >> arr[i].s >> arr[i].e;
        }
        sort(arr, arr + n, cmp);
        int k=0;
        cout << arr[0].c << " " << arr[0].s << " " << arr[0].e << endl;
        for (int i = 1; i < n;i++){
            if(arr[k].e<=arr[i].s){
                cout << arr[i].c << " " << arr[i].s << " " << arr[i].e << endl;
                k = i;
            }
        }

        
}
