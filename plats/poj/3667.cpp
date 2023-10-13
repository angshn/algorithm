#include <iostream>
#include <cstring>
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
const int N = 5e4 + 5;
const int INF = 0x3f3f3f3f;
inline int ls(int p){return p<<1;}
inline int rs(int p){return p<<1|1;}

int tree[N<<2],pre[N<<2],suf[N<<2];
int tag[N<<2];
void addtag(int p,int pl,int pr,int d){
    tag[p]=d;
    if(d){
        pre[p]=suf[p]=0;
        tree[p]=0;
    }
    else{
        tree[p]=pr-pl+1;
        pre[p]=suf[p]=pr-pl+1;
    }
}
void pushdown(int p,int pl,int pr){
    if(tag[p]!=-1){
        int mid = pl+pr>>1;
        addtag(ls(p),pl,mid,tag[p]);
        addtag(rs(p),mid+1,pr,tag[p]);
        tag[p]=-1;
    }
}

int pushup(int p,int pl,int pr){
    int len = pr-pl+1;
    pre[p]=pre[ls(p)];
    suf[p]=suf[rs(p)];
    if (pre[ls(p)] == len - (len >> 1))  pre[p] = pre[ls(p)] + pre[rs(p)]; 
    if (suf[rs(p)] == len >> 1)          suf[p] = suf[ls(p)] + suf[rs(p)]; 
    tree[p] = max(tree[ls(p)], max(tree[rs(p)], suf[ls(p)] + pre[rs(p)]));
}
void build(int p,int pl,int pr){
    tag[p]=-1;
    tree[p] = pre[p] = suf[p] = pr-pl+1;
    if(pl==pr){ return; }
    int mid = pr+pl>>1;
    build(ls(p),pl,mid);
    build(rs(p),mid+1,pr);
    pushup(p,pl,pr);
}

void update(int L,int R,int p,int pl,int pr,int d){
    //将l,r区间全部修改为d
    if(L<=pl&&pr<=R){
        addtag(p,pl,pr,d);
        return ;
    }
    pushdown(p,pl,pr);
    int mid=pl+pr>>1;
    if(L<=mid) update(L,R,ls(p),pl,mid,d);
    if(R>mid) update(L,R,rs(p),mid+1,pr,d);
    pushup(p,pl,pr);
}


int query(int p,int pl,int pr,int d){
    //查询是否存在一个tree[p]>=d的最左区间
    if(pl==pr) return pl;
    pushdown(p,pl,pr);
    int mid=pl+pr>>1;
    //如果当前区间的左区间满足d
    if(tree[ls(p)]>=d) return query(ls(p),pl,mid,d);
    else if(pre[rs(p)]+suf[ls(p)]>=d) return mid - suf[ls(p)]+1;
    else return query(rs(p),mid+1,pr,d);
}


void solve(){
    int n,m;cin>>n>>m;
    build(1,1,n);
    while(m--){
        int op;cin>>op;
        if(op==1){
            int x;cin>>x;
            if (x > tree[1]) { cout << 0 << endl; continue; }
            int lft = query(1,1,n,x);//find x length room.
            update(lft,lft+x-1,1,1,n,1);
            cout<<lft<<endl;
        }
        else {
            int l,r;cin>>l>>r;
            update(l,l+r-1,1,1,n,0);
        }
    }
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