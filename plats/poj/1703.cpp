#include <iostream>
#include <cstdio>
#define ll long long int
#define GETA(buf,size) for(int i=0;i<size;i++) cin>>buf[i];
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define FASTIO                \
    ios ::sync_with_stdio(0); \
    cin.tie(0);               \
    cout.tie(0);
inline int read(){int x=0,f=1;char ch=getchar();while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}return x*f;}

using namespace std;
const int N = 1e5 + 5;
const int INF = 0x3f3f3f3f;
int s[N];
int d[N];
void Init(){for(int i=0;i<N;i++) s[i]=i,d[i]=0;}
int Find(int x)
{
    if(x!=s[x]){
        int t = s[x];
        s[x] = Find(s[x]);
        d[x]=d[t]^d[x];
    }
    return s[x];
}
void Merge(int x, int y,int v)
{
    int fx = Find(x), fy = Find(y);
    if (fx != fy){
        s[fx] = fy;
        d[fx]=d[x]^d[y]^1;
    }
}
int n,m;
void solve(){
    scanf("%d %d",&n,&m);
    Init();
    char op;int u,v;
    getchar();
    for(int i=1;i<=m;i++){
        scanf("%c %d %d",&op,&u,&v);
        if(op=='D'){
            Merge(u,v,1);
        }
        else {
            if(Find(u)!=Find(v)) printf("Not sure yet.\n");
            else if(d[u]^d[v]) printf("In different gangs.\n");
            else printf("In the same gang.\n");
        } 
        getchar();
    }

}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("/Users/syang/career/algorithm/in.txt","r",stdin);
#endif
    FASTIO
    int t;scanf("%d",&t);
    while (t--)
        solve();
    return 0;
}