#include <bits/stdc++.h>
#define ll long long int
#define GETA(buf,size) for(int i=0;i<size;i++) cin>>buf[i];
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define FASTIO                \
    ios ::sync_with_stdio(0); \
    cin.tie(0);               \
    cout.tie(0);
using namespace std;
inline int read();
const int N = 2e5 + 5;
const int INF = 0x3f3f3f3f;
int n,m;
int a[N];
int l2[N];

int dp[N][22];
void init(){
    l2[0]=-1;
    for(int i=1;i<=N;i++) l2[i]=l2[i>>1]+1;
    for(int i=1;i<=n;i++) dp[i][0] = a[i];

    int p = (int)(log(double(n))/log(2.0));
    for(int k=1;k<=p;k++){
        for(int s=1;s+(1<<k)<=n+1;s++){
            dp[s][k] = max(dp[s][k-1], dp[s+(1<<(k-1))][k-1]);

        }
    }
}

int st_query(int l,int r){
    int k = l2[r-l+1];
    return max(dp[l][k],dp[r-(1<<k)+1][k]);
}

void solve(){
    n=read();
    for(int i=1;i<=n;i++) a[i]=read();
    init();
    m=read();
    for(int i=1;i<=m;i++){
        int l=read(),r=read();
        printf("%d\n",st_query(l,r));
    }
}
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
    return x*f;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("/Users/syang/career/algorithm/in.txt","r",stdin);
#endif
    FASTIO
     int t;cin>>t;while(t--)  solve();
    return 0;
}