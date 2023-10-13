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
const int N = 1e5 + 5;
const int INF = 0x3f3f3f3f;
int tree[N<<2][2],pre[N<<2][2],suf[N<<2][2];
int tag[N<<2][3];
int a[N];
int Sum[N<<2][2];

inline int ls(int p) {return p<<1;}
inline int rs(int p) {return p<<1|1;}

#define cmid (pr+pl)>>1
void addtag(int p,int pl,int pr,int d){
    //当前区间全部改为0
    if (d == 0)
    {
        tag[p][0] = 1;
        tag[p][1] = tag[p][2] = 0;
        Sum[p][0] = tree[p][0] = pre[p][0] = suf[p][0] = pr - pl + 1; // 前缀0，全为0
        Sum[p][1] = tree[p][1] = pre[p][1] = suf[p][1] = 0;//前缀1清空
    }
    if (d == 1)
    {
        tag[p][1] = 1;
        tag[p][0] = tag[p][2] = 0;
        Sum[p][0] = tree[p][0] = pre[p][0] = suf[p][0] = 0;
        Sum[p][1] = tree[p][1] = pre[p][1] = suf[p][1] = pr - pl + 1;
    }
    if (d == 2) {
        //当前区间全部取0，现在要全部取反，
        if (tag[p][0])
        {
            tag[p][0] = 0;
            tag[p][1] = 1;//全为1
            Sum[p][0] = tree[p][0] = pre[p][0] = suf[p][0] = 0;
            Sum[p][1] = tree[p][1] = pre[p][1] = suf[p][1] = pr - pl + 1;
        }
        else if (tag[p][1])
        {
            tag[p][0] = 1;
            tag[p][1] = 0;
            Sum[p][0] = tree[p][0] = pre[p][0] = suf[p][0] = pr - pl + 1; // 前缀0，全为0
            Sum[p][1] = tree[p][1] = pre[p][1] = suf[p][1] = 0;           // 前缀1清空
        }
        else 
        {
            tag[p][2] ^= 1;
            swap(Sum[p][0], Sum[p][1]);
            swap(tree[p][0], tree[p][1]);
            swap(pre[p][0], pre[p][1]);
            swap(suf[p][0], suf[p][1]);
        }

    }
}
void pushdown(int p,int pl,int pr){
    int mid=cmid;
    if (tag[p][0])
    {
        addtag(ls(p), pl, mid, 0);
        addtag(rs(p), mid + 1, pr, 0);
        tag[p][0] = 0;
    }
    // 一个区间上只能有一个操作，因此可以同时if
    if (tag[p][1])
    {
        addtag(ls(p), pl, mid, 1);
        addtag(rs(p), mid + 1, pr, 1);
        tag[p][1] = 0;
    }
    if (tag[p][2])
    {
        addtag(ls(p), pl, mid, 2);
        addtag(rs(p), mid + 1, pr, 2);
        tag[p][2] = 0;
    }
}
void pushup(int p,int pl,int pr){
    int len=pr-pl+1;
    {
        pre[p][0] = pre[ls(p)][0];
        suf[p][0] = suf[rs(p)][0];
        if (pre[ls(p)][0] == len - (len >> 1))
            pre[p][0] = pre[ls(p)][0] + pre[rs(p)][0];
        if (suf[rs(p)][0] == (len >> 1))
            suf[p][0] = suf[ls(p)][0] + suf[rs(p)][0];
        tree[p][0] = max(suf[ls(p)][0] + pre[rs(p)][0], max(tree[ls(p)][0], tree[rs(p)][0]));
        Sum[p][0] = Sum[ls(p)][0] + Sum[rs(p)][0];
    }

    {
        pre[p][1] = pre[ls(p)][1];
        suf[p][1] = suf[rs(p)][1];
        if (pre[ls(p)][1] == len - (len >> 1))
            pre[p][1] = pre[ls(p)][1] + pre[rs(p)][1];
        if (suf[rs(p)][1] == (len >> 1))
            suf[p][1] = suf[ls(p)][1] + suf[rs(p)][1];

        tree[p][1] = max(suf[ls(p)][1] + pre[rs(p)][1], max(tree[ls(p)][1], tree[rs(p)][1]));
        Sum[p][1] = Sum[ls(p)][1] + Sum[rs(p)][1];
    }
}


void build(int p,int pl,int pr){
    tag[p][0]=tag[p][1]=tag[p][2]=0;
    if(pl==pr){
        Sum[p][0]=tree[p][0]=pre[p][0]=suf[p][0]=a[pl]^1;
        Sum[p][1]=tree[p][1]=pre[p][1]=suf[p][1]=a[pl];
        return ;
    }
    int mid = cmid;
    build(ls(p),pl,mid);
    build(rs(p),mid+1,pr);
    pushup(p,pl,pr);
}

void update(int L,int R,int p,int pl,int pr,int d){
    if(L<=pl&&pr<=R){

        addtag(p,pl,pr,d);

        return;
    }
    pushdown(p,pl,pr);
    int mid=cmid;
    if(L<=mid) update(L,R,ls(p),pl,mid,d);
    if(R>mid) update(L,R,rs(p),mid+1,pr,d);
    pushup(p,pl,pr);
}

int querySum(int L,int R,int p,int pl,int pr){
    if(L<=pl and pr<=R){
        return Sum[p][1];
    }
    pushdown(p,pl,pr);
    int mid=cmid;
    int res=0;
    if(L<=mid) res = querySum(L,R,ls(p),pl,mid);
    if(R>mid) res+=querySum(L,R,rs(p),mid+1,pr);
    return res;
}
//连续的个数
int queryCnt(int L,int R,int p,int pl,int pr){
    if(L<=pl and pr<=R){
        return tree[p][1];
    }
    pushdown(p,pl,pr);
    int mid=cmid;
    if(R<=mid) return queryCnt(L,R,ls(p),pl,mid);
    if(L>mid) return queryCnt(L,R,rs(p),mid+1,pr);
    int res=0;
    res = max(queryCnt(L,R,ls(p),pl,mid),queryCnt(L,R,rs(p),mid+1,pr));//左右子区间的最大值
    int ans = min(pre[rs(p)][1],R-mid)+min(suf[ls(p)][1],mid+1-L);//左孩子后缀+有孩子前缀
    return max(res,ans);
}



void solve(){
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    build(1,1,n);
    while(m--){
        int d,L,R;cin>>d>>L>>R;
        L++;R++;
        if(d==0||d==1||d==2){
            update(L,R,1,1,n,d);
        }
        else if(d==3) {
            cout<<querySum(L,R,1,1,n)<<"\n";
        }
        else{
            cout<<queryCnt(L,R,1,1,n)<<"\n";
        }
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("D:\\devel\\algorithm\\in.txt","r",stdin);
#endif
    FASTIO
    int t;cin>>t;while(t--) solve();
    return 0;
}