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
const int N = 5e4 + 5;
const int INF = 0x3f3f3f3f;

int tree[N<<2],tag[N<<2];
int a[N];
inline int ls(int p){
    return p<<1;
}
inline int rs(int p){
    return p<<1|1;
}
void push_up(int p){
    tree[p] = tree[ls(p)]+tree[rs(p)];
}
void build(int p,int pl,int pr){
    tag[p]=0;
    if(pl == pr){
        tree[p] = a[pl];
        return; 
    }

    int mid = (pl+pr)>>1;
    build(ls(p),pl,mid);
    build(rs(p),mid+1,pr);
    push_up(p);
}
void addtag(int p,int pl,int pr,int d){
    tag[p]+=d;
    tree[p]+=(pr-pl+1)*d;
}
void push_down(int p,int pl,int pr){
    if(tag[p]){
        int mid = (pr+pl)>>1;
        addtag(ls(p),pl,mid,tag[p]);
        addtag(rs(p),mid+1,pr,tag[p]);
        tag[p]=0;
    }
}

void update(int L,int R,int p,int pl,int pr,int d){
    if(L<=pl&&pr<=R){
        addtag(p,pl,pr,d);
        return;
    }

    push_down(p,pl,pr);
    int mid = (pr+pl)>>1;
    if(L<=mid) update(L,R,ls(p),pl,mid,d);
    if(R>mid) update(L,R,rs(p),mid+1,pr,d);

    push_up(p);
}
int query(int L,int R,int p,int pl,int pr){
    if(L<=pl&&pr<=R){
        return tree[p];
    }
    push_down(p,pl,pr);
    int mid = (pr+pl)>>1;
    int res = 0;
    if(L<=mid) res += query(L,R,ls(p),pl,mid);
    if(R>mid) res += query(L,R,rs(p),mid+1,pr);
    return res;
}
void solve(){
    int t;cin>>t;
    int kase = 1;
    while(t--){
        cout<<"Case "<<kase++<<":\n";
        int n;cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];


        build(1,1,n);
        string op;
        int x,y;
        while(cin>>op){
            if(op=="End") break;
            cin>>x>>y;
            if(op=="Add"){
                update(x,x,1,1,n,y);
            }
            if(op == "Sub"){
                update(x,x,1,1,n,-y);
            }
            if(op == "Query"){
                cout<<query(x,y,1,1,n)<<"\n";
            }
        }
    }
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