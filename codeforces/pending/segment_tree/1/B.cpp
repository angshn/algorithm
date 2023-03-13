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
inline int Min(int x,int y){
    return x>y?y:x;
}
struct SegTree{
    int size = 0;
    vector<int> mins;
#define left(x) 2 * x + 1
#define right(x) 2 * x + 2

    void init(int n){
        size=1;
        while(size < n) size <<=1;
        mins.assign(size << 1, INF);
    }
    void build(vector<int> &a,int x,int lx, int rx){
        if(rx - lx == 1){
            if(lx < a.size()){
                mins[x] = a[lx];
            }
            return;
        }
        int m = (rx + lx) >> 1;
        build(a,left(x),lx,m);
        build(a,right(x),m,rx);
        mins[x] = Min(mins[left(x)],mins[right(x)]);
    }
    void build(vector<int> &a){
        build(a, 0, 0, size);
    }
    void set(int idx,int v,int x,int lx,int rx){
        if(rx - lx == 1){
            mins[x] = v;
            return;
        }
        int m = (rx + lx) >> 1;
        if(m > idx){
            set(idx,v,left(x),lx,m);
        }
        else {
            set(idx,v,right(x),m,rx);
        }
        mins[x] = Min(mins[left(x)],mins[right(x)]);
    }
    void set(int idx,int v){
        set(idx, v, 0, 0, size);
    }
    int minv(int l,int r,int x,int lx,int rx){
        if(lx >= r || rx <= l){
            return INF;
        }
        if(lx>=l && rx <=r){
            return mins[x];
        }
        int m = (rx+lx)/2;
        int m1 = minv(l,r,left(x),lx,m);
        int m2 = minv(l,r,right(x),m,rx);
        return Min(m1,m2);
    }
    int minv(int l,int r){
        return minv(l,r,0,0,size);
    }
};


void solve(){
    int n,m;cin>>n>>m;
    vector<int> a(n);
    rep(i,0,n) cin>>a[i];
    SegTree st;
    st.init(n);
    st.build(a);
    rep(i,0,m){
        int op;cin >> op;
        if(op==1){
            int idx,v;
            cin>>idx>>v;
            st.set(idx,v);
        }
        else{
            int l,r;cin>>l>>r;
            cout<<st.minv(l,r)<<endl;
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