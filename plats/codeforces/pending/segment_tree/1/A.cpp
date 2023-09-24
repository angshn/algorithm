#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#define ll long long int
#define GETA(buf,size) for(int i=0;i<size;i++) cin>>buf[i];
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
using namespace std;
const int N = 2e5 + 5;
const int INF = 0x3f3f3f3f;
struct SegTree{
    vector<ll> sums;
    int size;
    void init(int n){
        size = 1;
        while(size < n) size*=2;
        sums.assign(size<<1,0LL);
    }
    void build(vector<int> &a,int x,int lx,int rx){
        if(rx - lx == 1){
            if(lx < a.size()){
                sums[x] = a[lx];
            }
            return ;
        }
        int m = (rx+lx)/2;
        build(a,2*x+1,lx,m);
        build(a,2*x+2,m,rx);
        sums[x] = sums[2*x+1]+sums[2*x+2];
    }

    void build(vector<int> &a){
        build(a ,0 ,0 ,size);
    }

    void set(int i,int v,int x,int lx,int rx){
        if(rx - lx == 1){
            sums[x] = v;
            return ;
        }
        int m = (rx + lx)/2;
        if(i<m){
            set(i,v,2*x+1,lx,m);
        }
        else {
            set(i,v,2*x+2,m,rx);
        }
        sums[x] = sums[2*x+1]+sums[2*x+2];
    }
    void set(int idx,int v){
        set(idx,v,0,0,size);
    }

    ll sum(int l, int r,int x,int lx,int rx){
        if( lx>=r || rx <= l)return 0;
        if(lx>=l && rx<=r) return sums[x];
        int m = (rx+lx)/2;
        ll s1 = sum(l,r,x*2+1,lx,m);
        ll s2 = sum(l,r,2*x+2,m,rx);
        return s1+s2;
    }

    ll sum(int l,int r){
       return sum(l,r,0,0,size);
    }
} st;

void solve(){
    int n,m;cin>>n>>m;
    vector<int> a(n);
    rep(i,0,n) cin>> a[i];
    st.init(n);
    st.build(a);

    rep(i,0,m){
        int op;cin>>op;
        if(op==1){
            int idx,v;
            cin>>idx>>v;
            st.set(idx,v);
        }
        else{
            int l,r;cin>>l>>r;
            cout<<st.sum(l,r)<<endl;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}