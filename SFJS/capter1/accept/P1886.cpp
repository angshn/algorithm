#include <bits/stdc++.h>
#define ll long long int
#define GETA(buf,size) for(int i=0;i<size;i++) cin>>buf[i];
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define FASTIO                \
    ios ::sync_with_stdio(0); \
    cin.tie(0);               \
    cout.tie(0);
using namespace std;
const int N = 1e6 + 5;
const int INF = 0x3f3f3f3f;
int a[N];
deque<int> q;
void solve (){
    int n,m; cin>> n>> m;
    for (int i = 1; i <= n; i++)cin >> a[i];
    for (int i = 1; i <= n; i++){
        while (!q.empty() && a[q.back()] > a[i]) q.pop_back();
        q.push_back(i);
        if(i>=m){ //process window
            while(!q.empty()&& q.front() <= i - m) q.pop_front();
            cout<< a[q.front()] <<" ";
        }
    }
    cout<<"\n";
    while(!q.empty()) q.pop_front();
    for(int i=1;i<=n;i++){
        while (!q.empty() && a[q.back()] < a[i]) q.pop_back();
        q.push_back(i);
        if(i>=m){ //process window
            while(!q.empty()&& q.front() <= i - m) q.pop_front();
            cout<< a[q.front()] <<" ";
        }
    }
    cout<<"\n";
}
int main()
{
    FASTIO
#ifndef ONLINE_JUDGE
  freopen("D:/devel/workspace/algorithm/in.in","r",stdin);
#endif
#ifdef MULTI_CASE
    int t;cin>>t;
    while(t--) 
#endif
    solve();
    return 0;
}