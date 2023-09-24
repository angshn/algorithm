#include <bits/stdc++.h>
#define ll long long int
#define GETA(buf,size) for(int i=0;i<size;i++) cin>>buf[i];
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define FASTIO                \
    ios ::sync_with_stdio(0); \
    cin.tie(0);               \
    cout.tie(0);
using namespace std;
const int N = 1e2 + 5;
const int INF = 0x3f3f3f3f;
struct Node{
    ll w,depth;
    Node(ll _w,ll _d):w(_w),depth(_d){}
    bool operator <(const Node &a)const{
        return a.w == w?depth>a.depth:w>a.w;
    }
};
priority_queue<Node> q;

void solve(){
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++) {
        ll w;cin>>w;
        q.push(Node(w,1));
    }

    while((q.size()-1)%(k-1)!=0) q.push(Node(0,1));
    ll ans = 0;
    while (q.size()>=k)
    {
        ll d=-1,w=0;//累计权值
        for(int i=1;i<=k;i++){
            w += q.top().w;
            d = max(d, q.top().depth);
            q.pop();
        }
        ans+=w;
        q.push(Node(w,d+1));
    }

    cout<<ans<<"\n"<<q.top().depth-1<<endl;
    

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