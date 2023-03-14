#include <bits/stdc++.h>
#define ll long long int
#define GETA(buf,size) for(int i=0;i<size;i++) cin>>buf[i];
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
using namespace std;
const int N = 2e5 + 5;
const int INF = 0x3f3f3f3f;

void solve(){
    ll x;cin>>x;
    ll a=x ,b = 0;

    rep(i,32,0){
        if(x & (1<<i)) continue;
        if (2LL* x - a - b >= (2LL<<i)){
            a+=1LL<<i;
            b+=1LL<<i;
        }
    }
    if(2*x == a+b && (a^b) == x){
        cout<<a<<" "<<b<<endl;
    }
    else {
        cout<<-1<<endl;
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