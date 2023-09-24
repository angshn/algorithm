#include <bits/stdc++.h>
#define ll long long int
#define GETA(buf,size) for(int i=0;i<size;i++) cin>>buf[i];
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
using namespace std;
const int N = 1e2 + 5;
const int INF = 0x3f3f3f3f;
void solve(){
    int n;cin>>n;
    vector<vector<int>> a(n+1);
    int cache[N];
    memset(cache,0,sizeof(cache));
    rep(i,0,n){
        int x;
        rep(j,0,n-1){
            cin>>x;
            a[i].emplace_back(x);
        }
    }
    int cnt[2] = {0, 0};
    rep(i, 0, n)
    {
        cache[a[i][0]]++;
    }
    int mx = max_element(cache,cache+N) - cache;
    rep(i,0,n){
        if(a[i][0]!=mx){
            cout<<mx<<" ";
            rep(j,0,n-1){
                cout<<a[i][j]<<" \n"[j==n-2];
            }
            break;
        }
    }
}
int main()
{
#ifndef ONLINE_JUDGE
  freopen("/root/devel/algorithm/in.in","r",stdin);
 #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}