#include <bits/stdc++.h>
#define ll long long int
#define GETA(buf,size) for(int i=0;i<size;i++) cin>>buf[i];
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define FASTIO                \
    ios ::sync_with_stdio(0); \
    cin.tie(0);               \
    cout.tie(0);
using namespace std;
const int N = 3e6 + 5;
const int INF = 0x3f3f3f3f;
int a[N];
int ans[N];
void solve(){
    int n;cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    stack<int> st;
    
    for(int i=n;i>=1;i--){
        while(!st.empty()&& a[st.top()] <= a[i]) st.pop();
        if(st.empty()){
            ans[i] = 0;
        }
        else{
            ans[i] = st.top();
        }
        st.push(i);
    }
    for(int i=1;i<=n;i++) cout<<ans[i]<<" \n"[i==n];
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