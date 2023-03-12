#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#define ll long long int
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
using namespace std;
const int N = 3e5 + 5;
void solve(){
    int n;ll s;
    cin>>n >> s;
    vector<int> a(n+1);
    rep(i,0,n) cin>> a[i];
    int l = 0;
    int ans = 0;
    ll sum = 0;
    rep(r, 0, n){
        while (a[r] - a[l] >= s){
            l++;
            ans ++;
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