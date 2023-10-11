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
int n,m;
ll a[N];
template <class T>
class SegmentTree{
public:
    T tree[N<<2];
    T tag[N<<2];
    
    T ls(T p){ return p<<1; }
    T rs(T p){ return p<<1|1; }
    void push_up(T p){ tree[p] = tree[ls(p)]+tree[rs(p)]; }

    void build(T p,T pl,T pr){
        tag[p]=0;
        if(pl == pr){ tree[p] = a[pl];return; }
        T mid = (pl+pr)>>1;
        build(ls(p),pl,mid);
        build(rs(p),mid+1,pr);
        push_up(p);
    }

    void addtag(T p, T pl, T pr, T d)
    {
        tag[p] += d;
        tree[p] += d * (pr - pl + 1);
    }
    void push_down(T p, T pl, T pr)
    {
        if (tag[p])
        {
            T mid = (pr + pl) >> 1;
            addtag(ls(p), pl, mid, tag[p]);
            addtag(rs(p), mid + 1, pr, tag[p]);
            tag[p] = 0;
        }
    }
    void update(T L, T R, T p, T pl, T pr, T d)
    {
        if (tree[p] == (pr - pl + 1)) return;
        if (pl == pr)
        {
            tree[p] = (ll)(sqrt(tree[p]));
            return;
        }
        T mid = (pr + pl) >> 1;
        if (L <= mid) update(L, R, ls(p), pl, mid, d);
        if (R > mid) update(L, R, rs(p), mid + 1, pr, d);
        push_up(p);
    }
    T query(T L, T R, T p, T pl, T pr)
    {
        if (L <= pl && pr <= R)
        {
            return tree[p];
        }
        // push_down(p, pl, pr);
        T mid = (pr + pl) >> 1;
        T res = 0;
        if (L <= mid) res += query(L, R, ls(p), pl, mid);
        if (R > mid) res += query(L, R, rs(p), mid + 1, pr);
        return res;
    }
};
SegmentTree<ll> t1;

void Swap(ll &x, ll &y){ ll t=x; x = y; y = t; }
void solve(){
    int cnt = 1;
    while(cin>>n){
        
        for (int i = 1; i <= n; i++) cin >> a[i];
        t1.build(1, 1, n);
        cin >> m;
        
        cout<<"Case #" << cnt++ << ":\n";
        for (int i = 1; i <= m; i++)
        {

            ll t, x, y;
            cin >> t >> x >> y;
            if(x>y) Swap(x,y);
            if (t) cout<< t1.query(x, y, 1, 1, n) << "\n";
            else t1.update(x, y, 1, 1, n, 0);
            
        }
        cout<<"\n";
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
