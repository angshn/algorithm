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
int pre[N]={0};
deque<int> q;
int kase = 1;
void solve(){
    while(!q.empty())q.pop_back();
    int n;cin >> n;
    pre[0] = 0;
    rep(i,1,n+1) {
        int x;cin>>x; pre[i]=pre[i-1]+x;
    }
    int ans = -INF;
    q.push_back(0);
    int start = 1, end = 1;
    rep(i,1,n+1){
       
        while(!q.empty() && pre[q.back()] > pre[i]) q.pop_back();
        if(q.empty()){
            ans = max(ans,pre[i]);
            if(ans < pre[i]){
                start = end = i;
            }
        }
        if(pre[i] - pre[q.front()] > ans){
            ans = pre[i] - pre[q.front()];
            start = q.front() + 1;
            end = i;
        }
        q.push_back(i);
    }
    cout << "Case " << kase++ <<":\n" << ans << " " << start <<" " << end << "\n";
    

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