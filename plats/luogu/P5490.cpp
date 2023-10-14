#include <bits/stdc++.h>
#define ll long long int
#define GETA(buf,size) for(int i=0;i<size;i++) cin>>buf[i];
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define FASTIO                \
    ios ::sync_with_stdio(0); \
    cin.tie(0);               \
    cout.tie(0);
inline int read(){int x=0,f=1;char ch=getchar();while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}return x*f;}

using namespace std;
const int N = 2e5 + 5;
const int INF = 0x3f3f3f3f;
int length[N<<2];
int tag[N<<2];
int xx[N];
struct Line{
    ll y,lx,rx;
    int inout;
    Line(){};
    Line(ll y,ll x2,ll x1,int io):
        y(y),rx(x2),lx(x1),inout(io){}
}line[N];

inline int ls(int p){return p<<1;}
inline int rs(int p){return p<<1|1;}

void pushup(int p,int pl,int pr){
    if(tag[p]) length[p]=xx[pr]-xx[pl];
    else if(pl+1==pr) length[p]=0;
    else length[p] = length[ls(p)]+length[rs(p)];
}

void update(int L,int R,int p,int pl,int pr,int d){
    if(L<=pl&&pr<=R){
        tag[p]+=d;
        pushup(p,pl,pr);
        return;
    }
    if(pl+1==pr) return;
    int mid=(pr+pl)>>1;
    if(L<=mid) update(L,R,ls(p),pl,mid,d);
    if(R>mid) update(L,R,rs(p),mid,pr,d);
    pushup(p,pl,pr);
}
bool cmp1(Line &x,Line &y){
    return x.y<y.y;
}

void solve(){
    int n=read();
    int cnt=0;
    for(int i=1;i<=n;i++){
        double x1=read(),y1=read(),x2=read(),y2=read();
        line[++cnt] = Line(y1,x2,x1,1);
        xx[cnt]=x1;
        line[++cnt] = Line(y2,x2,x1,-1);
        xx[cnt]=x2;
    }

    sort(xx+1,xx+1+cnt);
    sort(line+1,line+1+cnt,cmp1);
    int num = unique(xx + 1, xx + 1 + cnt) - (xx + 1);
    ll ans = 0;
    for(int i=1;i<=cnt;i++){
        ans+= length[1]*(line[i].y-line[i-1].y);
        int L = lower_bound(xx+1,xx+num+1,line[i].lx)-xx;
        int R = lower_bound(xx+1,xx+num+1,line[i].rx)-xx;
        update(L,R,1,1,num,line[i].inout);
    }
    printf("%lld\n",ans);
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