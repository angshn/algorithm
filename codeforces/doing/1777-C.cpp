#include <bits/stdc++.h>
#define ll long long int
#define GETA(buf,size) for(int i=0;i<size;i++) cin>>buf[i];
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
using namespace std;
const int N = 1e5 + 5;
const int M = 1e5 + 5;
const int INF = 0x3f3f3f3f;
vector<vector<int>> factors(N);
void init(){
    int maxn = N;
    int maxm = M;
    rep(i,1,maxn){
        for(int j = 1;j<maxm;j+=i){
            factors[j].push_back(i);
        }
    }
}


void solve(){
    int n,m;cin>>n>>m;
    vector<int> a(n+1);
    rep(i,0,n)cin>>a[i];

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