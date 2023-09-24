#include <bits/stdc++.h>
#define ll long long int
#define GETA(buf,size) for(int i=0;i<size;i++) cin>>buf[i];
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define FASTIO                \
    ios ::sync_with_stdio(0); \
    cin.tie(0);               \
    cout.tie(0);
using namespace std;
const int N = 1e6 + 5;
const int INF = 0x3f3f3f3f;
ll a[N];
ll D[N];
int n,m;
struct Node{
    ll d,s,t;
}nodes[N];
bool check(int mid){
    for(int i=1;i<=n;i++){
        D[i]=a[i]-a[i-1];
    }

    for(int i=1;i<=mid;i++){
        ll s=nodes[i].s;
        ll t=nodes[i].t;
        ll d=-nodes[i].d;
        D[s]+=d;
        D[t+1]-=d;
    }

    ll sum=0;
    for(int i=1;i<=n;i++){
        sum+=D[i];
        if(sum<0) return false;
    }
    return true;
}


void solve(){
    cin>>n>>m;

    rep(i,1,n+1) cin>>a[i];

    rep(i,1,m+1){
        cin>>nodes[i].d>>nodes[i].s>>nodes[i].t;
    }
    if(check(n)){
        cout<<0<<endl;
    }
    else {
        int l = 1,r = n;
        while(l<r){
            int mid = (r+l)>>1;
            if(check(mid)){
                l=mid+1;
            }
            else r=mid;
        }
        cout<<-1<<"\n"<<l<<endl;
    }


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