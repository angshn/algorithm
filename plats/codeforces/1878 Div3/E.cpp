#include <bits/stdc++.h>
#define ll long long int
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define FASTIO                \
    ios ::sync_with_stdio(0); \
    cin.tie(0);               \
    cout.tie(0);
inline int read(){int x=0,f=1;char ch=getchar();while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}return x*f;}

using namespace std;
const int N = 2e5 + 5;
const int INF = 0x3f3f3f3f;
int a[N];
int tree[N<<2];
int ls(int p){return p<<1;}
int rs(int p){return p<<1|1;}

void push_up(int p){
    tree[p] = tree[ls(p)]&tree[rs(p)];
}
void build(int p,int pl,int pr){
    if(pl==pr){
        tree[p]=a[pl];return;
    }
    int mid = (pr+pl)>>1;
    build(ls(p),pl,mid);
    build(rs(p),mid+1,pr);
    push_up(p);
}

int query(int L,int R,int p,int pl,int pr){
    if(L<=pl&&pr<=R){
        return tree[p];
    }
    int mid = (pr + pl) >> 1;
    int res = INT_MAX;
    if (L <= mid) res = res & query(L, R, ls(p), pl, mid);
    if (R > mid)  res = res & query(L, R, rs(p), mid + 1, pr);
    return res;
}

void solve(){
    int n = read();
    for(int i=1;i<=n;i++) a[i]=read();
    int q=read();
    build(1,1,n);
    while(q--){
        int _l=read(),k=read();
        if(a[_l]<k){
            printf(q==0?"-1\n":"-1 ");
            continue;
        }
        int l = _l;
        int r = n;
        while (l < r){
            int mid = (l+r+1)>>1;
            if (query(_l, mid, 1, 1, n) >= k){
                l = mid;
            }
            else r = mid-1;
        }
        printf("%d",l);
        q==0?printf("\n"):printf(" ");
    }

}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("/Users/syang/career/algorithm/in.txt","r",stdin);
#endif
    FASTIO
    int t=read();while(t--)solve();
    return 0;
}