#include<bits/stdc++.h>
using namespace std; 
#define int long long
#define endl "\n"

void solve(int __test_case)
{
    int n; 
    cin >> n; 
    vector<int> arr(n); 
    for(auto &it: arr)
        cin >> it; 
    if(count(arr.begin(), arr.end(), 0) == 0)
        cout << 1; 
    else if(count(arr.begin(), arr.end(), 0) == n)
        cout << 0; 
    else
    {
        int i = 0; 
        while(i < n && arr[i] == 0)
            i++; 
        while(i < n && arr[i] != 0)
            arr[i] = 0, i++; 
        // for(auto &it: arr)
        //     cout <<  it << ' '; 
        if(count(arr.begin(), arr.end(), 0) == n)
            cout << 1; 
        else
            cout << 2; 
    }
}
int32_t main(void)
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int __test_case = 1; 
    cin >> __test_case; 
    for(int __t = 1; __t <= __test_case; ++__t)
    {
        solve(__t); 
        cout << endl; 
    }
    return 0; 
}