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
int n;
int ans = 0;
void build(int rt, int d){
    ans = max(ans, d);
    while(rt<=n&&a[rt+1]>a[rt]){
        rt++;
        
    }
    if(rt<=n&&a[rt+1]<a[rt]){
        build(rt+1,d+1);
    }

}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    ans = 1;
    build(1,0);
    cout<<ans<<endl;
}
int main()
{
#ifndef ONLINE_JUDGE
  freopen("/Users/syang/career/algo/in.in","r",stdin);
#endif
    FASTIO
    int t;cin>>t;
    while(t--) solve();
    return 0;
}