#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <stack>
#define ll long long int
#define GETA(buf,size) for(int i=0;i<size;i++) cin>>buf[i];
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
using namespace std;
const int N = 2e5 + 5;
const int INF = 0x3f3f3f3f;
ll a[N];
ll gcd(ll x,ll y){
    return y ? gcd(y, x % y) : x;
}

struct Stack{
    vector<ll> st,val={0};
    void push_back(ll x){
        st.emplace_back(x);
        val.emplace_back(gcd(val.back(), x));
    }

    ll top(){
        return val.back();
    }
    ll pop(){
        ll x = st.back();
        st.pop_back();
        val.pop_back();
        return x;
    }
    bool empty(){
        return st.empty();
    }
}s1,s2;

void remove(){
    if(s1.empty()){
        while(!s2.empty()){
            s1.push_back(s2.pop());
        }
    }
    s1.pop();
}
void solve(){
    int n;cin>>n;
    GETA(a,n);
    int l = 0;
    ll _gcd = 0;
    ll ans = INF;
    rep(r, 0, n){
        s2.push_back(a[r]);
        while(gcd(s1.top(),s2.top())==1){
            remove();
            ans = min(ans,r - l + 1LL);
            l++;
        }
    }
    if(ans == INF){
        ans = -1;
    }
    cout<<ans<<endl;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("/Users/syang/career/algorithm/codeforces/in.in","r",stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}