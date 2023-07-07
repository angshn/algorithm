#include <bits/stdc++.h>
#define ll long long int
#define GETA(buf,size) for(int i=0;i<size;i++) cin>>buf[i];
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define FASTIO                \
    ios ::sync_with_stdio(0); \
    cin.tie(0);               \
    cout.tie(0);
using namespace std;
const int N = 2e6 + 5;
const int INF = 0x3f3f3f3f;
int a[N];
deque<int> q;
void solve(){
    int n,k;cin>>n>>k;    
    rep(i,1,n+1)cin>>a[i];
    rep(i,1,n+1){
        while(!q.empty() && a[q.back()] < a[i]) q.pop_back();

        q.push_back(i);
        if(i>=k){
            while(!q.empty() && q.front() <= i - k) q.pop_front();
            cout<<a[q.front()]<<"\n";
        }
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
#endif
    FASTIO
#ifndef NO_MULTICASE
    int t=1;
    while(t--) 
#endif
    solve();
    return 0;
}