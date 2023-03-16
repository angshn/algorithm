#include <bits/stdc++.h>
#define ll long long int
#define GETA(buf,size) for(int i=0;i<size;i++) cin>>buf[i];
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
using namespace std;
const int N = 2e5 + 5;
const int INF = 0x3f3f3f3f;
inline int sum(int x){
    int r = 0;
    while(x){
        r+=x%10;x/=10;
    }
    return r;
}
void solve(){
    int n,q;cin>>n>>q;
    vector<int> a(n+1);
    set<int> ids;
    rep(i,1,n+1) {
        cin>>a[i];
        if(a[i]>9) ids.insert(i);
    }
    rep(i,0,q){
        int op;cin>>op;
        if(op == 1){
            int l,r;cin>>l>>r;
            int pos = 1;
            while(!ids.empty()){
                auto it = ids.lower_bound(pos);
                if(it == ids.end() || *it >r) break;
                int idx = *it;
                a[idx] = sum(a[idx]);
                ids.erase(it);
                if(a[idx] > 9) ids.insert(idx) ;
                pos = (idx) + 1;
            }
        }
        else {
            int x;cin>>x;
            cout<<a[x]<<endl;

        }
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("/root/devel/algorithm/in.in","r",stdin); 
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}