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
int ls(int p){return p<<1;}
int rs(int p){return p<<1|1;}
int tree[N<<2],pre[N<<2],suf[N<<2];

int history[N];
void pushup(int p,int pl,int pr){
    int len = pr-pl+1;
    pre[p] = pre[ls(p)];
    suf[p] = suf[rs(p)];
    //len>>1为右区间长度
    if(pre[ls(p)]==(len-(len>>1))) pre[p] = pre[ls(p)] + pre[rs(p)];
    if(suf[rs(p)]==(len>>1))       suf[p] = suf[ls(p)] + suf[rs(p)];
}

void build(int p,int pl,int pr){
    if(pl == pr){ tree[p] = pre[p]=suf[p] = 1;return; }
    int mid = pr+pl>>1;
    build(ls(p),pl,mid);
    build(rs(p),mid+1,pr);
    pushup(p,pl,pr);
}

void update(int x,int p,int pl,int pr,int d){
    if(pl==pr){ tree[p]=suf[p]=pre[p] = d;return; }
    int mid = pl+pr>>1;
    if(x<=mid) update(x,ls(p),pl,mid,d);
    if(x>mid) update(x,rs(p),mid+1,pr,d);
    pushup(p,pl,pr);
}

int query(int x,int p,int pl,int pr){//查询第x个位置能两边有多少个1
    if(pl==pr){ return tree[p]; }
    int mid = pr+pl>>1;
    if(x<=mid){
        if(x + suf[ls(p)] > mid) return suf[ls(p)]+pre[rs(p)];//如果x的位置在一些1的范围中，就直接返回
        else                     return query(x,ls(p),pl,mid); 
    }
    else {
        if(mid+pre[rs(p)] >= x)  return pre[rs(p)]+suf[ls(p)];
        else                     return query(x,rs(p),mid+1,pr); 
    }
}


void solve(){
    int n,m,x,tot;
    while(scanf("%d %d",&n,&m) > 0){
        build(1,1,n);
        tot = 0;
        while(m--){
            char op[10];scanf("%s", op);
            if(op[0] == 'Q'){
                scanf("%d", &x);
                printf("%d\n",query(x,1,1,n));
            }
            else if(op[0]=='D'){
                scanf("%d",&x);
                history[++tot]=x;
                update(x,1,1,n,0);
            }
            else {
                x = history[tot--];
                update(x,1,1,n,1);
            }

        }

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