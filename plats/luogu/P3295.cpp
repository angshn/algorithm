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
int vis[N];
const int mod = 1e9+7;

int find(int i,int d){
    return dp[i][d]==i?i:dp[i][d]=find(dp[i][d],d);
}

void Union(int x,int y,int d){
    int f1 = find(x,d);
    int f2 = find(y,d);
    if(f1!=f2){
        dp[dp[f1][d]][d] = f2;//确保是根做指向
    }
}

void init(){
    LOG2[0]=-1;
    for(int i=1;i<=N;i++) LOG2[i] = LOG2[i>>1]+1;
    for(int j=21;j>=0;j--) for(int i =1;i+(1<<j)<=n+1;i++) dp[i][j]=i;
}

void solve(){
    cin>>n>>m;
    init();
    for(int i=1;i<=m;i++){
        int l1,r1,l2,r2;cin>>l1>>r1>>l2>>r2;
        //合并子区间
        int k = LOG2[r1-l1+1];
        int f1 = find(l1,k);
        int f2 = find(l2,k);
        dp[f1][k]=f2;
        f1 = find(r1-(1<<k)+1,k);
        f2 = find(r2-(1<<k)+1,k);
        dp[f1][k] = f2;
    }    


    //开始拆解小区间
    for(int k=LOG2[n];k>=1;k--){
        for(int i=1;i+(1<<k)<=n+1;i++){
            int y =find(i,k);
            if(y!=i){
                Union(i,y,k-1);
                Union(i+(1<<(k-1)),y+(1<<(k-1)),k-1);
            }
        }
    }
    ll ans = 0;
    for(int i=1;i<=n;i++){
        int y = find(i,0);
        if(dp[i][0]==i){
            if(ans==0) ans = 9;
            else ans = ans*10%mod;
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