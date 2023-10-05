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
const int N = 2e5 + 5;
const int INF = 0x3f3f3f3f;
int n,m;
int cnt;
int s[N];
struct Node{
    int x,y,t;
    bool operator < (const Node &a)const {
        return t<a.t;
    }
}q[N];
void Init(){
    for(int i=0;i<=n;i++) s[i] = i;
}
int Find(int x){
    if (x != s[x])
    {
        s[x] = Find(s[x]);
    }
    return s[x];
}
void Merge(int x,int y){
    int rx = Find(x),ry = Find(y);
    if(rx != ry){
        s[rx] = ry;
        cnt--;
    }
}
void solve(){
    cin>>n>>m;
    cnt = n;
    for(int i=1;i<=m;i++)cin>>q[i].x>>q[i].y>>q[i].t;
    Init();
    sort(q+1,q+1+m);
    int ans = -1;
    for(int i=1;i<=m;i++){
        Merge(q[i].x,q[i].y);
        if(cnt==1){
            ans = q[i].t;
            break;
        }
    }
    cout<<ans<<"\n";

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
    solve();
    return 0;
}