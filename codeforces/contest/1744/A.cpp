#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#define INPUT_PATH "/Users/syang/dev/algorithm/in.in"
using namespace std;
const int N = 1e2 + 5;
short a[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen(INPUT_PATH, "r", stdin);
#endif
    int t, n;
    cin >> t;
    string s;
    while (t--)
    {
        cin >> n;
        set<int> st;
        for (int i = 0; i < n; i++)
        {

            cin >> a[i];
            st.insert(a[i]);
        }
        cin >> s;
        bool error = false;
        for (auto x : st)
        {
            int i = 0;
            char ch;
            while (i < n && a[i] != x)
            {
                i++;
            }
            ch = s[i++];

            while (i < n)
            {
                if (a[i] == x && s[i] != ch)
                {
                    error = true;
                    break;
                }
                i++;
            }
            if (error)
            {
                break;
            }
        }
        if (error)
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
        }
    }
}