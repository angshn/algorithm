#include <bits/stdc++.h>
#define ll long long int
#define GETA(buf,size) for(int i=0;i<size;i++) cin>>buf[i];
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define FASTIO                \
    ios ::sync_with_stdio(0); \
    cin.tie(0);               \
    cout.tie(0);
using namespace std;
const int N = 1e5 + 5;
const int INF = 0x3f3f3f3f;
int dp[N];
int kase = 1;
void solve(){
    int n;cin>>n;

    for(int i = 1;i<=n;i++) cin>>dp[i];
    int start = 1,end = 1,p = 1;
    int maxsum = dp[1];

    rep(i,2,n+1){
        if(dp[i-1] + dp[i] >= dp[i]) dp[i] = dp[i-1]+dp[i];
        else p = i;
        if(dp[i]>maxsum){
            maxsum = dp[i];
            start = p;
            end = i;
        }
    }


    cout << "Case " << kase++ <<":\n" << maxsum << " " << start <<" " << end << "\n";
    
}
int main()
{
    #ifndef ONLINE_JUDGE
      freopen("D:/devel/workspace/algorithm/in.in","r",stdin);
     #endif
    FASTIO
#ifndef NO_MULTICASE
    int t;cin>>t;
    while(t--) 
#endif
    solve();
    return 0;
}