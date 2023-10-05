#include <bits/stdc++.h>
#define ll long long int
#define GETA(buf,size) for(int i=0;i<size;i++) cin>>buf[i];
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define FASTIO                \
    ios ::sync_with_stdio(0); \
    cin.tie(0);               \
    cout.tie(0);
using namespace std;
const int N = 5e5 + 5;
const int INF = 0x3f3f3f3f;
int a[N];
int t,n,m;
bool check(int mid){

    int cur = 0;
    int cnt = 0;
    for (int i = 1; i <= n + 1; i++){
        if(a[i]-a[cur]<mid){
            cnt++;
        }
        else {
            cur = i;
        }
    }
    return cnt<=m;
}

void solve(){
    cin>>t>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    a[n+1]=t;
    int l=1,r=t;
    int ans = 0;
    while(l<=r){
        int mid = (r+l)>>1;
        if(check(mid)){//符合就调高标准
            ans = mid;
            l = mid+1;
        }
        else {
            r= mid-1;
        }
    }
    cout<<ans<<endl;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("/Users/syang/career/algorithm/in.txt","r",stdin);
#endif
    FASTIO
    solve();
    return 0;
}