#include <bits/stdc++.h>
#define ll long long int
#define GETA(buf,size) for(int i=0;i<size;i++) cin>>buf[i];
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define FASTIO                \
    ios ::sync_with_stdio(0); \
    cin.tie(0);               \
    cout.tie(0);
using namespace std;
const int N = 2e5 + 5;
const int INF = 0x3f3f3f3f;
int a[N];
void solve(){
    int n,c;cin>>n>>c;
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    ll ans = 0;
    for(int i=0,j=0,k=0;i<n;i++){
        while (j < n && a[j] - a[i] < c)
            j++;
        while (k < n && a[k] - a[i] <= c)
            k++;

        if (a[j] - a[i] == c && a[k - 1] - a[i] == c && k - 1 >= 0)
        {
            ans+=k-j;
        }
    }
    cout<<ans<<endl;
}
int main()
{
#ifndef ONLINE_JUDGE
  freopen("/Users/syang/career/algo/in.in","r",stdin);
#endif
    FASTIO
    solve();
    return 0;
}