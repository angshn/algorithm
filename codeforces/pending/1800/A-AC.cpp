#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#define ll long long int
using namespace std;
const int N = 1e2 + 5;
char buff[N];
int main()
{
    // freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cin >> buff;
        // clog<<buff<<'\n';
        int i = 0;
        int flags[4] = {
            0,
        };
        while (i < n && buff[i] == 'm' || buff[i] == 'M')
        {
            i++;
            flags[0]++;
        }
        while (i < n && buff[i] == 'e' || buff[i] == 'E')
        {
            i++;
            flags[1]++;
        }
        while (i < n && buff[i] == 'o' || buff[i] == 'O')
        {
            i++;
            flags[2]++;
        }
        while (i < n && buff[i] == 'w' || buff[i] == 'W')
        {
            i++;
            flags[3]++;
        }
        int f = 0;
        for (int i = 0; i < 4; i++)
        {
            if (!flags[i])
            {
                f = 1;
                break;
            }
        }
        // clog<<i<<'\n';
        if (!f && i == n)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}