#include <bits/stdc++.h>
#define ll long long int
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
using namespace std;
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}
const int N = 3e5 + 5;
void solve(){
    int n;ll s;
    cin>>n >> s;
    vector<int> a(n+1);
    rep(i,0,n) cin>> a[i];
    int l = 0;
    ll ans = 0;
    rep(r, 1, n){
        while(a[r] - a[l] > s){
            l++;
        }
        if(a[r] - a[l-1] > s){
            ans += l;
        }

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