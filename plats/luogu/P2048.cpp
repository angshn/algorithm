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
const int N = 5e5 + 5;
const int INF = 0x3f3f3f3f;
int n,k,L,R;
int a[N];
int pre[N];
int LOG2[N];
int dp[N][22];
void init(){
    LOG2[0]=-1;
    for(int i=1;i<=N;i++) LOG2[i] = LOG2[i>>1]+1;
    for(int i=1;i<=n;i++) dp[i][0] = i;
    int p = (int)(log(double(n))/log(2.0));
    for(int k=1;k<=p;k++){
        for(int s=1;s+(1<<k)<=n+1;s++){
            int left = dp[s][k-1];
            int right = dp[s+(1<<(k-1))][k-1];
            dp[s][k] = pre[left]>pre[right]?left:right;//最大值下标
        }
    }
}
int st_query(int l,int r){
    int k = LOG2[r-l+1];
    int left = dp[l][k];
    int right = dp[r-(1<<k)+1][k];
    return pre[left]>pre[right]?left:right;
}

struct Node{
    int s,l,r,t;
    Node(int _s,int _l,int _r):s(_s),l(_l),r(_r),t(st_query(_l,_r)){};

    bool operator < (const Node& x) const {
        return pre[t]-pre[s-1] < pre[x.t] - pre[x.s-1];
    }
    int value(){
        return pre[t]-pre[s-1];
    }
};


void solve(){
    n=read();k=read();L=read();R=read();
    for(int i=1;i<=n;i++) {
        a[i] = read();
        pre[i] = pre[i-1]+a[i];
    }
    priority_queue<Node > q;
    init();

    for(int i=1;i<=n;i++){
        if(i+L-1<=n)
            q.push(Node(i, i + L - 1, min(i + R - 1, n)));
    }

    ll ans = 0;
    while(k--){
        Node top = q.top();q.pop();
        ans += top.value();
        if(top.l!=top.t) q.push(Node(top.s,top.l,top.t-1));
        if(top.t!=top.r) q.push(Node(top.s,top.t+1,top.r));
    }
    printf("%lld\n",ans);
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
    solve();
    return 0;
}