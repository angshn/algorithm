#include <bits/stdc++.h>
#define ll long long int
#define GETA(buf,size) for(int i=0;i<size;i++) cin>>buf[i];
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define FASTIO                \
    ios ::sync_with_stdio(0); \
    cin.tie(0);               \
    cout.tie(0);
using namespace std;
const int N = 2e5 + 5;
const int INF = 0x3f3f3f3f;
int h[N];
int ans[N];
void solve(){
    int n;cin>>n;
    for(int i=1;i<=n;i++) cin>>h[i];

    stack<int> s;

    for(int i=n;i>0;i--){    
        while(!s.empty() && h[s.top()] <= h[i]) s.pop();

        if(s.empty()) ans[i] = 0;
        else ans[i] = s.top();

        s.push(i);

    }
    for(int i = 1;i<=n;i++){
        cout<<ans[i]<< "\n";
    }
}
int main()
{
#ifndef ONLINE_JUDGE
  freopen("/Users/syang/career/algo/in.in","r",stdin);
#endif
    FASTIO
    solve();
    return 0;
}