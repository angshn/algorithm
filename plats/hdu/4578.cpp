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
const int N = 1e5 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 10007;
ll a[N];
ll typ,x,y,c;
int n,m;
template<class T>
class SegmentTree{
public:
    T sum[N<<2];
    T sum2[N<<2];
    T sum3[N<<2];

    T add[N<<2];
    T mul[N<<2];
    T cha[N<<2];

    // T ls(T p){return p<<1;}
    // T rs(T p){return p<<1|1;}
    #define ls(p) p<<1
    #define rs(p) p<<1|1
    void push_up(T p){
        sum[p] = (sum[ls(p)] + sum[rs(p)]) % MOD;
        sum2[p] = (sum2[ls(p)] + sum2[rs(p)]) % MOD;
        sum3[p] = (sum3[ls(p)] + sum3[rs(p)]) % MOD;
    }

    void push_down(T p,T pl,T pr){
        T mid = (pr + pl) >> 1;
        T sz1 = mid - pl + 1, sz2 = pr - mid;
        if(cha[p]){
            T d = cha[p];
            sum3[ls(p)] = (sz1 * d * d * d) % MOD;
            sum2[ls(p)] = (sz1 * d * d) % MOD;
            sum[ls(p)] = (sz1 * d) % MOD;

            sum3[rs(p)] = sz2 * d * d * d % MOD;
            sum2[rs(p)] = sz2 * d * d % MOD;
            sum[rs(p)] = sz2 * d % MOD;

            add[ls(p)]=add[rs(p)]=0;
            mul[ls(p)]=mul[rs(p)]=1;
            cha[ls(p)]=cha[rs(p)]=d;
        }
        if(mul[p]!=1){//算乘只算子节点，当前节点已经算过了
            T d = mul[p];
            sum3[ls(p)] = (sum3[ls(p)] * d * d * d) % MOD;
            sum2[ls(p)] = (sum2[ls(p)] * d * d) % MOD;
            sum[ls(p)] = (sum[ls(p)] * d) % MOD;
            add[ls(p)] = (add[ls(p)] * d) % MOD;
            mul[ls(p)] = (mul[ls(p)] * d) % MOD;

            sum3[rs(p)] = (sum3[rs(p)] * d * d * d) % MOD;
            sum2[rs(p)] = (sum2[rs(p)] * d * d) % MOD;
            sum[rs(p)] = (sum[rs(p)] * d) % MOD;
            add[rs(p)] = (add[rs(p)] * d) % MOD;
            mul[rs(p)] = (mul[rs(p)] * d) % MOD;
        }
        if(add[p]){
            T d = add[p];//先加后乘再加,当前节点已经加过了
            sum3[ls(p)] = (sum3[ls(p)] + sz1 * d * d * d + 3 * d * sum2[ls(p)] + 3 * d * d * sum[ls(p)]) % MOD;
            sum2[ls(p)] = (sum2[ls(p)] + 2 * d * sum[ls(p)] + sz1 * d * d) % MOD;
            sum[ls(p)] = (sum[ls(p)] + sz1 * d) % MOD;
            add[ls(p)] = (add[ls(p)] + d) % MOD;
            sum3[rs(p)] = (sum3[rs(p)] + sz2 * d * d * d + 3 * d * sum2[rs(p)] + 3 * d * d * sum[rs(p)]) % MOD;
            sum2[rs(p)] = (sum2[rs(p)] + 2 * sum[rs(p)] * d + sz2 * d * d) % MOD;
            sum[rs(p)] = (sum[rs(p)] + sz2 * d) % MOD;
            add[rs(p)] = (add[rs(p)] + d) % MOD;
        }

        add[p] = 0;
        mul[p] = 1;
        cha[p] = 0;
    }

    void build(T p, T pl, T pr){
        mul[p] = 1;
        sum[p] = sum2[p] = sum3[p] = cha[p] = add[p]= 0;
        if (pl == pr)  return;
        T mid = (pr+pl)>>1;
        build(ls(p),pl,mid);
        build(rs(p),mid+1,pr);
    }

    void update(T L, T R, T p, T pl, T pr, T d){
        T sz = pr - pl + 1;
        if (L <= pl && pr <= R){
            if(typ == 1){
                add[p] = (add[p] + d) % MOD;
                sum3[p] = (sum3[p] + sz * d * d * d + 3 * d * sum2[p] + 3 * d * d * sum[p]) % MOD;
                sum2[p] = (sum2[p] + 2 * d * sum[p] + sz * d * d) % MOD;
                sum[p] = (sum[p] + sz * d) % MOD;
            }
            else if(typ == 2){
                add[p] = (add[p] * d) % MOD;
                mul[p] = (mul[p] * d) % MOD;
                sum3[p] = (d * d * d * sum3[p]) % MOD;
                sum2[p] = (d * d * sum2[p]) % MOD;
                sum[p] = (d * sum[p]) % MOD;
            }
            else{
                cha[p] = d;
                add[p] = 0;
                mul[p] = 1;
                sum3[p] = (d * d * d * sz) % MOD;
                sum2[p] = (d * d * sz) % MOD;
                sum[p] = (d * sz) % MOD;
            }
            return ;
        }

        T mid = (pr+pl)>>1;
        push_down(p, pl, pr);
        if (L <= mid) update(L, R, ls(p), pl, mid, d);
        if (R > mid) update(L, R, rs(p), mid + 1, pr, d);
        push_up(p);
    }

    T query(T L, T R, T p, T pl, T pr, int ty){
        if (L <= pl && pr <= R){
            if(ty==1) return sum[p];
            if(ty==2) return sum2[p];
            if(ty==3) return sum3[p];
        }

        push_down(p,pl,pr);
        T res = 0;
        T mid = (pr+pl)>>1;
        if (L <= mid) res = (res + query(L, R, ls(p), pl,      mid,     ty)) % MOD;
        if (R > mid)  res = (res + query(L, R, rs(p), mid + 1, pr,      ty)) % MOD;
        return res;
    }
};
SegmentTree<ll> t1;
void solve(){
    while (cin >> n >> m)
    {
        if (n == 0 && m == 0) return;
        t1.build(1, 1, n);
        while(m--){
            cin>>typ>>x>>y>>c;
            if(typ==4) cout<<t1.query(x,y,1,1,n,c)<<endl;
            else t1.update(x,y,1,1,n,c);
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