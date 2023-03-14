#include <bits/stdc++.h>
#define ll long long int
#define GETA(buf,size) for(int i=0;i<size;i++) cin>>buf[i];
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
using namespace std;
const int N = 2e5 + 5;
const int INF = 0x3f3f3f3f;
void solve(){
    int n;cin>>n;
    
    vector<int> a(n);
    map<int, int> mp;
    rep(i,0,n) {
        cin>>a[i];
        mp[a[i]]++;
    }
    sort(a.begin(),a.end());
    ll ans = 0;
    rep(i,0,n){
        if(mp[a[i]]){
            int &p=a[i];
            mp[p]--;
            while(1){
                if(mp[p+1]){
                    p++;
                    mp[p]--;
                }
                else break;
            }
            ans ++;
        }
    }
    cout<<ans<<endl;
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