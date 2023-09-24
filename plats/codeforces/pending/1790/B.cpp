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
void solve(){
    int n,s,r;cin>>n>>s>>r;   
    int _mx = s - r;
    int mean = r / (n-1);
    int remain = r%(n-1);
    vector<int> ans ;
    ans.emplace_back(_mx);
    rep(i,0,n-1-remain){
        ans.emplace_back(mean);
    }
    rep(i,0,remain){
        ans.emplace_back(mean+1);
    }
    rep(i,0,n){
        cout<<ans[i]<<" \n"[i+1==n];
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