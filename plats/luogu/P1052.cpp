#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios ::sync_with_stdio(0);cin.tie(0);cout.tie(0);
inline int read(){int x=0,f=1;char ch=getchar();while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}return x*f;}

#define ll long long int
const int N = 2e5 + 5;
const int INF = 0x3f3f3f3f;
int l;
int s,t,m;
int dp[N];
int a[N];
int st[N];
int b[N];
int gcd(int x,int y)
{
    return y ? gcd(y, x % y) : x;
}
int lcm(int a,int b){
    return a/gcd(a,b)*b;
}

void solve(){
    cin>>l>>s>>t>>m;
    int pre=0;
    int idx=0;
    int dis = lcm(s,t);
    int ans= 0;
    if(s==t){
        for(int i=1;i<=m;i++){
            int pos;cin>>pos;
            if(pos%s==0){
                ans++;
            }
        }
    }
    else {
        for(int i=1;i<=m;i++)cin>>st[i];
        sort(st+1,st+m+1);
        for(int i=1;i<=m;i++){
            int d=st[i]-st[i-1];
            if(d>=dis) d= dis;
            b[i]=b[i-1]+d;
            a[b[i]]=1;
        }
        l=b[m]+dis;
        memset(dp,0x7f,sizeof(dp));
        dp[0]=0;
        for(int i=1;i<=l;i++){
            for(int j=s;j<=t;j++){

                if(i-j>=0) dp[i]=min(dp[i],dp[i-j]+a[i]);
            }
        }
        ans=0x3fffffff;
        for(int i=b[m];i<=l;i++){
            ans = min(dp[i],ans);
        }
    }
    cout<<ans<<'\n';
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("/Users/syang/career/algorithm/in.txt","r",stdin);
#endif
    FASTIO;solve();return 0;
}