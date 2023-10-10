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
const int N = 1e6 + 5;
const int INF = 0x3f3f3f3f;
int n,m;
int cates[N];
int a[N];
int tree[N];
#define lowbit(x) (x&(-x))
void update(int x,int d){
    while(x<=n){
        tree[x]+=d;
        x+=lowbit(x);
    }
}
int query(int x){
    int ans = 0;
    while(x){
        ans+=tree[x];
        x-=lowbit(x);
    }
    return ans;
}
int anw[N];
struct Query{
    int l,r;
    int p;
}qs[N];
bool cmp(Query q1,Query q2){
    return q1.r<q2.r;
}
void solve(){
    n = read();
    for(int i=1;i<=n;i++){
        a[i]=read();
    }

    m = read();
    for(int i=1;i<=m;i++){
        qs[i].l=read();
        qs[i].r=read();
        
        qs[i].p=i;
    }
    sort(qs+1,qs+1+m,cmp);
    int nxt = 1;
    for(int i=1;i<=m;i++){
        for (int j = nxt; j <= qs[i].r; j++)
        {
            if (cates[a[j]])
                update(cates[a[j]], -1);
            update(j, 1);
            cates[a[j]] = j;
        }
        nxt = qs[i].r+1;
        anw[qs[i].p] = query(qs[i].r) - query(qs[i].l - 1);
    }
    for(int i=1;i<=m;i++){
        printf("%d\n",anw[i]);
    }
    
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("D:\\devel\\algorithm\\in.txt","r",stdin);
#endif
    solve();
    return 0;
}