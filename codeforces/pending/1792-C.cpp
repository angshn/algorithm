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
    int n;cin>>n;
    vector<int> a(n);
    vector<int> pos(n+1);
    int x;
    rep(i,0,n) {
        cin>>x;pos[x] = i;
    }


    int k = (n)>>1;
    while(k && pos[k+1]>pos[k] && pos[n-k+1]>pos[n-k]) --k;
    cout<<k<<endl;

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