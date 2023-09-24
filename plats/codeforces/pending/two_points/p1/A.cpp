#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#define ll long long int
const int INF = 0x3f3f3f3f;
using namespace std;
const int N = 1e5 + 5;
int a[N], b[N];
int c[N << 1];
void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    a[n] = INF;
    b[m] = INF;

    int i = 0, j = 0;
    while (i < n || j < m)
    {
        if (a[i] < b[j])
        {
            c[i + j] = a[i];
            i++;
        }
        else
        {
            c[i + j] = b[j];
            j++;
        }
    }
    for(int i=0;i<n+m;i++){
        cout << c[i] << " \n"[i == n + m -1 ];
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}