#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve(int __test_case)
{
    int n;
    cin >> n;
    string str;
    cin >> str;
    int dot = 0, p = 0, s = 0;
    for (auto &it : str)
        if (it == '.')
            dot++;
        else if (it == 'p')
            p++;
        else
            s++;
    if (dot == n || p == n || s == n || p == 0 || s == 0)
        cout << "YES";
    else
    {
        vector<int> arr(n, -1);
        set<int> st;
        for (int i = 1; i <= n; ++i)
            st.insert(i);
        for (int i = 0; i < n; ++i)
        {
            if (str[i] == 'p')
            {
                int j = i;
                while (j >= 0)
                {
                    if (arr[j] == -1)
                    {
                        arr[j] = *st.begin();
                        st.erase(st.begin());
                        j--;
                    }
                    else
                        j--;
                }
            }
        }
        for(int i = n-1; i >= 0; --i)
            if(arr[i] == -1)
                arr[i] = *st.begin(), st.erase(st.begin()); 
        // for (auto &it : arr)
        //     cout << it << ' ';
        int j = 0; 
        for (int i = 0; i < n; ++i)
        {
            if (str[i] == 'p')
            {
                vector<int> temp;
                for (int j = 0; j <= i; ++j)
                    temp.push_back(arr[j]);
                sort(temp.begin(), temp.end());
                int len = temp.size();
                vector<int> x(len);
                iota(x.begin(), x.end(), 1);
                if (x != temp)
                {
                    cout << "NO";
                    return;
                }
            }
            else if (str[i] == 's')
            {
                vector<int> temp;
                for (int j = i; j < n; ++j)
                    temp.push_back(arr[j]);
                sort(temp.begin(), temp.end());
                int len = temp.size();
                vector<int> x(len);
                iota(x.begin(), x.end(), 1);
                if (x != temp)
                {
                    cout << "NO";
                    return;
                }
            }
        }
        cout << "YES";
    }
}
int32_t main(void)
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int __test_case = 1;
    cin >> __test_case;
    for (int __t = 1; __t <= __test_case; ++__t)
    {
        solve(__t);
        cout << endl;
    }
    return 0;
}