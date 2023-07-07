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
int pre[N];
deque<int>q;
void solve(){
    int n;cin>>n;
    rep(i,1,n+1) {
        cin>>a[i];
        a[i+n] = a[i]; 
    }
    rep(i,1,2*n){
        pre[i] = pre[i-1] + a[i];
    }
    int cnt = 0;
    rep(k,1,2*n){
        //当前位置k到k+n进行单调队列
        while(!q.empty() && pre[q.back()] >= pre[k]) q.pop_back();

        q.push_back(k);
        if(k>=n){
            while(!q.empty() && q.front() <= k - n) q.pop_front();

            if(pre[q.front()] - pre[k - n] >= 0) cnt++;
        }
    }
    cout<<cnt<<endl;

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