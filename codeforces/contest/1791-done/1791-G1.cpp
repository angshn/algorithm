
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#define INPUT_PATH "in.in"
#define ll long long int
using namespace std;
const int N = 2e5 + 5;

// struct Point
// {
//     int idx;
//     int cost;
// } lines[N];
int buff[N];
typedef struct Point point_t;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen(INPUT_PATH, "r", stdin);
    // freopen("out.out", "w", stdout);
#endif
    int tc;
    cin >> tc;

    while (tc--)
    {
        int n, c;
        cin >> n >> c;
        for (int i = 0; i < n; i++)
        {
            // lines[i].idx = i+1;
            // cin >> lines[i].cost;
            cin >> buff[i];
            buff[i] += (i + 1);
        }
        // auto cmp = [](point_t *a,)
        auto cmp = [](int a, int b)
        { return a < b; };
        sort(buff, buff + n, cmp);
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            (c -= buff[i]) >= 0 && cnt++;
            if (c <= 0)
                break;
        }
        cout << cnt << "\n";
    }
}
