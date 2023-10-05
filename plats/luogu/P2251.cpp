#include <bits/stdc++.h>
#define ll long long int
#define GETA(buf,size) for(int i=0;i<size;i++) cin>>buf[i];
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define FASTIO                \
    ios ::sync_with_stdio(0); \
    cin.tie(0);               \
    cout.tie(0);
inline int read();
using namespace std;
const int N = 1e5 + 5;
const int INF = 0x3f3f3f3f;
int n,m;
int dp[N][22];
int LOG2[N];
void init(){
    LOG2[0]=-1;
    for(int i=1;i<=N;i++) LOG2[i] = LOG2[i>>1]+1;
    int p = (int)(log(double(n))/log(2.0));
    for(int k=1;k<=p;k++){
        for(int s=1;s+(1<<k)<=n+1;s++){
            dp[s][k] = min(dp[s][k - 1], dp[s + (1 << (k - 1))][k - 1]);
        }
    }
}

int st_query(int l,int r){
    int k = LOG2[r - l + 1];
    return min(dp[l][k], dp[r - (1 << k) + 1][k]);
}

void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>dp[i][0];
    init();
    for(int l=1,r=m;r<=n;l++,r++){
        cout<<st_query(l,r)<<"\n";
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