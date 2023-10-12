#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#define ll long long int
#define GETA(buf,size) for(int i=0;i<size;i++) cin>>buf[i];
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
inline int read(){int x=0,f=1;char ch=getchar();while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}return x*f;}
#define FASTIO                \
    ios ::sync_with_stdio(0); \
    cin.tie(0);               \
    cout.tie(0);
using namespace std;
const int N = 2e5 + 5;
const int INF = 0x3f3f3f3f;
struct Node{
    int num,val;
}l[N],r[N];
int st[N<<1];
int sz;
map<int,int> hsh;


int tree[N<<2];
int tag[N<<2];

inline int ls(int p) {return p<<1;};
inline int rs(int p) {return p<<1|1;};


void build(int p,int pl,int pr){
    tag[p]=0;
    if(pl == pr){
        tree[pl] = 0; 
        return ;
    }
    int mid = pr+pl >>1;
    build(ls(p),pl,mid);
    build(rs(p),mid+1,pr);
}

void addtag(int p,int pl,int pr,int d){
    tag[p] = d;
    tree[p] = d;
}

void push_down(int p,int pl,int pr ){
    if(tag[p]){
        int mid = pl+pr>>1;
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
    int mid= pr+pl>>1;
    push_down(p,pl,pr);
    if(L<=mid) update(L,R,ls(p),pl,mid,d);
    if(R>mid) update(L,R,rs(p),mid+1,pr,d);
}

int query(int L,int R,int p,int pl,int pr){
    if(L<=pl&&pr<=R){ return tree[p]; }
    int mid= pr+pl>>1;
    int res = 0;
    push_down(p,pl,pr);
    if(L<=mid) res=query(L,R,ls(p),pl,mid);
    if(R>mid) res=query(L,R,rs(p),mid+1,pr);
    return res;
}


void solve(){
    int n =read();
    hsh.clear();
    sz = 0;
    for(int i=1;i<=n;i++){
        int x=read(),y=read();
        l[i].val = x,r[i].val = y;
        l[i].num = r[i].num = i;
        st[sz++] = x;
        st[sz++] = y;
    }
    
    sort(st,st+sz);
    sz = unique(st, st + sz) - st;
    int mx = -1;
    for(int i=0,id=1;i<sz;i++){
        if(i&&st[i]!=st[i-1]+1){ id++; }
        hsh[st[i]] = id; // 旧元素映射为新的id
        mx = max(id,mx); // 维护一个new value的最大值
        id++;
    }
    build(1,1,mx);//从1开始到最大值之间建树
    //hsh原来元素对应的新坐标
    //采用线段树对Post进行操作
    for(int i=1;i<=n;i++){
        l[i].val = hsh[l[i].val];
        r[i].val = hsh[r[i].val];
    }
    for(int i=1;i<=n;i++){
        int _l = l[i].val;
        int _r = r[i].val;
        //l,r之间的值改为第i个post的序号
        update(_l, _r, 1, 1, mx, i); // 离散后的区间更新为i序号
    }

    //叶节点有几种值
    int vis[mx+1]={0};
    for(int i=1;i<=mx;i++){
        int x = query(i,i,1,1,mx);
        vis[x]++;    
    }
    int ans = 0;
    for(int i=1;i<=mx;i++){
        if(vis[i]){
            ans++;
        }
    }
    cout<<ans<<endl;
    
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("D:\\devel\\algorithm\\in.txt","r",stdin);
#endif
    FASTIO
    int t=read();while(t--) solve();
    return 0;
}