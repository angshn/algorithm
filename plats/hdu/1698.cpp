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
const int N = 1e5 + 5;
const int INF = 0x3f3f3f3f;
int tree[N<<2],tag[N<<2];
int ls(int p){return p<<1;}
int rs(int p){return p<<1|1;}
#define cmid pr+pl>>1
void pushup(int p){
    tree[p] = tree[ls(p)]+tree[rs(p)];
}

void addtag(int p,int pl,int pr,int d){
    tag[p] = d;
    tree[p] = d*(pr-pl+1);
}
void pushdown(int p,int pl,int pr){
    if(tag[p]){
        int mid =cmid;
        addtag(ls(p),pl,mid,tag[p]);
        addtag(rs(p),mid+1,pr,tag[p]);
        tag[p]=0;
    }
}


void build(int p,int pl,int pr){
    tag[p]=0;
    if(pl==pr){
        tree[p]=1;
        return;
    }
    int mid=cmid;
    build(ls(p),pl,mid);
    build(rs(p),mid+1,pr);
    pushup(p);
}
void update(int L,int R,int p,int pl,int pr,int d){
    if(L<=pl&&pr<=R){
        addtag(p,pl,pr,d);return;
    }
    pushdown(p,pl,pr);
    int mid = cmid;
    if(L<=mid) update(L,R,ls(p),pl,mid,d);
    if(R>mid) update(L,R,rs(p),mid+1,pr,d);
    pushup(p);
}

int query(int L,int R,int p,int pl,int pr){
    if(L<=pl&&pr<=R){
        return tree[p];
    }
    pushdown(p,pl,pr);
    int mid=cmid;
    int res=0;
    if(L<=mid) res = query(L,R,ls(p),pl,mid);
    if(R>mid) res+=query(L,R,rs(p),mid+1,pr);
    return res;
}

void solve(int t){
    int n,q;cin>>n>>q;
    build(1,1,n);
    while(q--){
        int x,y,z;cin>>x>>y>>z;
        update(x,y,1,1,n,z);
    }
    cout<<"Case "<<t<<": The total value of the hook is "<<query(1,n,1,1,n)<<".\n";
    
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("/Users/syang/career/algorithm/in.txt","r",stdin);
#endif
    FASTIO
    int t;cin>>t;for(int i=1;i<=t;i++) solve(i);
    return 0;
}