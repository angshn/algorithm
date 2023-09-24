#include <iostream>
using namespace std;
#define TCASE \
    int t;    \
    cin >> t;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    int cache[30] = {0};
    TCASE
    char strs[11] = "codeforces";
    char chr;
    for (int i = 0; i < 10; i++)
    {
        chr = strs[i];
        cache[chr - 'a'] = 1;
    }
    while (t--)
    {
        char ch;
        cin >> ch;
        cache[ch - 'a']==1 ? cout << "YES\n" : cout << "NO\n";
    };
}