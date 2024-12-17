#include<bits/stdc++.h>
using namespace std;
struct activity
{
    char c;
    int s;
    int e;
};

bool cmp(activity a, activity b)
{
    return a.e < b.e;
}
int fractinal()
{
    int n;
    cout << "total activites=";
    cin >> n;
    activity arr[n];
    cout << "start & end:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].c >> arr[i].s >> arr[i].e;
    }
    sort(arr, arr + n, cmp);
    int k = 0;
    cout<< "Maximum number of activities = " << endl;
    cout << arr[0].c << " " << arr[0].s << " " << arr[0].e << endl;
    for (int i = 1; i < n; i++)
    {
        if (arr[k].e <= arr[i].s)
        {
            cout << arr[i].c << " " << arr[i].s << " " << arr[i].e << endl;
            k = i;
        }
    }
}
int knapshack()
{
    int n;
    cout<<"total item : ";
    cin >> n;
    int w[n], v[n];
    cout<<"weight & values : ";
    for (int i = 0; i < n; i++)
    {
        cin >> w[i] >>v[i];
    }
    int capacity;
    cout << "capacity ";
    cin >> capacity;
    int kn[n + 1][capacity + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= capacity; j++)
        {
            if (i == 0 || j == 0)
            {
                kn[i][j] = 0;
            }
            else if (w[i - 1] <= j)
            {
                kn[i][j] = max(kn[i - 1][j], kn[i - 1][j - w[i - 1]] + v[i - 1]);
            }
            else
            {
                kn[i][j] = kn[i - 1][j];
            }
        }
    }
    cout << "max value"<<kn[n][capacity] << endl;

    int mx = kn[n][capacity];
    int ct = capacity;
    for (int i = n; i > 0 && mx > 0; i--)
    {
        if (mx == kn[i - 1][ct])
        {
            continue;
        }
        else
        {
            cout << "Maximum value in Knapsack = " << w[i - 1] << " ";
            mx -= v[i - 1];
            ct -= w[i - 1];
        }
        cout << endl;
    }
}
    int main()
    {
        fractinal();
        knapshack();
    }
