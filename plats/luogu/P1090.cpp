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
void solve(){
    int n;cin>>n;
    priority_queue<int,vector<int>, greater<int> > q;
    rep(i,0,n) {
        int x;cin>>x;
        q.push(x);
    }
    ll sum = 0;
    while(q.size()>1){

        int a=q.top();q.pop();
        int b=q.top();q.pop();
        q.push(a+b);
        sum+=a+b;   
    }

    cout<<sum<<endl;


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