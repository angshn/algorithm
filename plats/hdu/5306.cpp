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
const int N = 1e6 + 5;
const int INF = 0x3f3f3f3f;

ll sum[N<<2],ma[N<<2],se[N<<2],num[N<<2];
ll ls(ll p) {return p<<1;}
ll rs(ll p) {return p<<1|1;}

void pushup(int p){
    sum[p] = sum[ls(p)]+sum[rs(p)];
    ma[p] = max(ma[ls(p)],ma[rs(p)]);
    if(ma[ls(p)]==ma[rs(p)]){//左右最大值一样
        se[p] = max(se[ls(p)],se[rs(p)]);//由于两棵子树的最大值一样，因此父节点的次大值只能是两颗子树中次大值的其中之一
        num[p] = num[ls(p)]+num[rs(p)];
    }
    else {
        se[p] = max(se[ls(p)],se[rs(p)]);
        se[p] = max(se[p],min(ma[ls(p)],ma[rs(p)]));
        //子树中的次大和子树中的最大值
        num[p] = ma[ls(p)] > ma[rs(p)] ? num[ls(p)] : num[rs(p)];
    }
}

void build(int p,int pl,int pr){
    if(pl==pr){
        cin>>sum[p];
        ma[p] = sum[p];se[p] =-1;num[p]=1;return;
    }
    ll mid = pr+pl >>1;
    build(ls(p),pl,mid);
    build(rs(p),mid+1,pr);
    pushup(p);

}

void addtag(int p,int x){
    if(x>=ma[p]) return;
    sum[p] -= num[p] * (ma[p]-x);//原先的最大值要缩减为x，总共的值要少最大值的减少值乘减少的数量
    ma[p]=x;
}

void pushdown(int p){
    addtag(ls(p),ma[p]);
    addtag(rs(p),ma[p]);
}

void update(int L,int R,int p,int pl,int pr,int x){
    if(x>=ma[p]) return;
    if(L<=pl && pr<=R && se[p]<x) { addtag(p,x);return ; }//se[p]<x<ma[p]时，要将最大值进行缩减，只做标记并修改父节点

    pushdown(p);

    ll mid = pr+pl>>1;
    if(L<=mid) update(L,R,ls(p),pl,mid,x);
    if(R>mid) update(L,R,rs(p),mid+1,pr,x);
    pushup(p);
}

int queryMax(int L,int R,int p,int pl,int pr){
    if(L<=pl && pr<=R) return ma[p];

    pushdown(p);
    ll mid = pr+pl>>1;
    int res = 0;
    if(L<=mid) res = queryMax(L,R,ls(p),pl,mid);
    if(R>mid) res = max(res, queryMax(L,R,rs(p),mid+1,pr));
    return res;
}

ll querySum(int L,int R,int p,int pl,int pr){
    if(L<=pl && pr<=R) return sum[p];
    pushdown(p);
    ll res = 0;
    ll mid = pr+pl>>1;
    if(L<=mid) res+=querySum(L,R,ls(p),pl,mid);
    if(R>mid) res+=querySum(L,R,rs(p),mid+1,pr);
    return res;

}
void solve(){
    int t;cin>>t;
    while(t--){
        int n,m;cin>>n>>m;
        build(1,1,n);
        while(m--){
            int q,L,R,x;cin>>q>>L>>R;
            if(q==0){
                cin>>x;
                update(L,R,1,1,n,x);
            }
            if(q==1){
                cout<<queryMax(L,R,1,1,n)<<"\n";
            }
            if(q==2){
                cout<<querySum(L,R,1,1,n)<<"\n";
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