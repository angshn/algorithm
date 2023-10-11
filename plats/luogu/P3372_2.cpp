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
ll a[N];
int n,m;
class SegmentTree{ 
public:
    ll tree[N << 2];
    ll tag[N << 2];
    ll ls(ll p) { return p << 1; }
    ll rs(ll p) { return p << 1 | 1; }
    void push_up(ll p) { tree[p] = tree[ls(p)] + tree[rs(p)]; }
    void build(ll p, ll pl, ll pr)
    {
        tag[p] = 0;
        if (pl == pr) { tree[p] = a[pl]; return; }
        ll mid = (pl + pr) >> 1;
        build(ls(p), pl, mid);
        build(rs(p), mid + 1, pr);
        push_up(p);
    }

    void addtag(ll p, ll pl, ll pr, ll d)
    {
        tag[p] += d;
        tree[p] += d * (pr - pl + 1);
    }

    void push_down(ll p, ll pl, ll pr)
    {
        if (tag[p])
        {
            ll mid = (pl + pr) >> 1;
            addtag(ls(p), pl, mid, tag[p]);
            addtag(rs(p), mid + 1, pr, tag[p]);
            tag[p] = 0;
        }
    }

    void update(ll L, ll R, ll p, ll pl, ll pr, ll d)
    {
        if (L <= pl && pr <= R) { addtag(p, pl, pr, d); return; }//如果全包含就只标记节点
        push_down(p, pl, pr);//不是全部包含时为了防止冲突，将之前的tag下放
        ll mid = (pl + pr) >> 1;
        if (L <= mid) update(L, R, ls(p), pl, mid, d);//左区间有重叠
        if (R > mid) update(L, R, rs(p), mid + 1, pr, d);//右区间存在重叠
        push_up(p);//用左右子区间的结果更新当前节点
    }

    ll query(ll L, ll R, ll p, ll pl, ll pr)
    {
        if (L <= pl && pr <= R) { return tree[p]; }
        push_down(p, pl, pr);
        ll res = 0;
        ll mid = (pl + pr) >> 1;
        if (L <= mid) res += query(L, R, ls(p), pl, mid);
        if (R > mid) res += query(L, R, rs(p), mid + 1, pr);
        return res;
    }
};
SegmentTree t1;
void solve(){
    cin>>n>>m;
    
    for(int i=1;i<=n;i++) cin>>a[i];

    t1.build(1,1,n);
    while(m--){
        ll op,x,y,k;cin>>op>>x>>y;
        if(op==1){
            cin>>k;
            t1.update(x,y,1,1,n,k);
        }
        else {
            cout<<t1.query(x,y,1,1,n)<<"\n";
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