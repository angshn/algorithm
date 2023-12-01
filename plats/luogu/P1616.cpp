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
const int N = 1e4 + 5;
const int INF = 0x3f3f3f3f;
const int M = 1e7+5;
int m,n;
int w[N],v[N];
ll dp[M];
void solve(){
    cin>>m>>n;
    for(int i=0;i<n;i++)
    {
        cin>>w[i]>>v[i];
    }

    for(int i=0;i<n;i++){
        for(int j=w[i];j<=m;j++){
            dp[j] = max(dp[j],dp[j-w[i]]+v[i]);
        }
    }

    cout<<dp[m]<<"\n";


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