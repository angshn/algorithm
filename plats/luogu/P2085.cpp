#include <bits/stdc++.h>
#define ll long long int
#define GETA(buf,size) for(int i=0;i<size;i++) cin>>buf[i];
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define FASTIO                \
    ios ::sync_with_stdio(0); \
    cin.tie(0);               \
    cout.tie(0);
using namespace std;
const int N = 1e4 + 5;
const int INF = 0x3f3f3f3f;
int x[N];
struct F{
    int a,b,c;

    ll f(int x){
        return 1LL*a*x*x+b*x+c;
    }
}fs[N];
void solve(){
    priority_queue<pair<ll,ll>, vector<pair<ll,ll> >, greater<pair<ll,ll> > >q;
    fill(x,x+N,1);
    int n,m;cin>>n>>m;
    int sum=0;
    for (int i = 1; i <= n; i++){
        cin>>fs[i].a>>fs[i].b>>fs[i].c;
        q.push(make_pair(fs[i].f(1),i));
    }

    for(int i = 1;i<m;i++){
        pair<ll,ll> top = q.top();q.pop();
        x[top.second]++;
        cout<<top.first<<" ";
        q.push(make_pair(fs[top.second].f(x[top.second]), top.second));
    }
    cout<<q.top().first<<endl;

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