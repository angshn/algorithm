#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#define INPUT_PATH "in.in"
#define TCASE \
    int tc;   \
    cin >> tc;
#define forf(i, n) for (int i = 0; i < n; i++)
#define ll long long int
using namespace std;
const int N = 2e3 + 5;
char buffer[N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen(INPUT_PATH, "r", stdin);
#endif
    TCASE
    while (tc--)
    {
        int n;
        cin >> n;
        cin >> buffer;
        int st = 0, end = n - 1;
        for (; st < end; st++, end--)
        {
            if(buffer[st]==buffer[end]){
                break;
            }
        }
        cout<<end-st+1<<"\n";
    }
}