#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#define ll long long int
#define GETA(buf,size) for(int i=0;i<size;i++) cin>>buf[i];
using namespace std;
const int N = 1e5 + 5;
const int INF = 0x3f3f3f3f;
int a[N];
void solve(){
    int n;
    ll m;cin>>n>>m;
    GETA(a,n);
    ll sum = 0;
    int l = 0;
    int r = 0;
    int res = 0;
    while(r < n){
        sum+=a[r];
        while(sum>m){
            sum -= a[l];
            l++;
        }
        res = max(res, r-l+1);
        r++;
    }
    cout << res << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}