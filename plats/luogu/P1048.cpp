#include <bits/stdc++.h>
#define ll long long int
#define GETA(buf,size) for(int i=0;i<size;i++) cin>>buf[i];
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
inline int read(){int x=0,f=1;char ch=getchar();while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}return x*f;}
#define FASTIO                \
    ios ::sync_with_stdio(0); \
    cin.tie(0);               \
    cout.tie(0);
using namespace std;
const int N = 2e5 + 5;
const int INF = 0x3f3f3f3f;
int w[N],v[N];
int dp[N];
void solve(){
    int t,m;cin>>t>>m;
    memset(dp,0,sizeof(dp));
    memset(w,0,sizeof(w));
    memset(v,0,sizeof(v));
    
    for(int i=0;i<m;i++) {
        cin>>w[i]>>v[i];
    }
    for(int i=0;i<m;i++)
    {
        for(int j = t;j>=w[i];j--){
            dp[j] = max(dp[j],dp[j-w[i]]+v[i]);
        }
    }
    cout<<dp[t]<<endl;


}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("D:\\devel\\algorithm\\in.txt","r",stdin);
#endif
    FASTIO
    solve();
    return 0;
}