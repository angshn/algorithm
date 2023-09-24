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
int a[N];
void solve(){
    int n,m,q,u,v,t;
    cin>>n>>m>>q>>u>>v>>t;
    queue<int> pq[4];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    sort(a,a+n,greater<int>() );
    for(int i=0;i<n;i++){
        pq[1].push(a[i]);
    }
    for(int i=1;i<=m;i++){
        pair<int,int> pii = max({
            make_pair(pq[1].empty()?-INF:pq[1].front(),1),
            make_pair(pq[2].empty()?-INF:pq[2].front(),2),
            make_pair(pq[3].empty()?-INF:pq[3].front(),3)});
        int sc = pii.first+q*(i-1);
        pq[pii.second].pop();

        int l = 1LL*sc*u/v,r=sc-l;

        pq[2].push(l-q-q*(i-1));
        pq[3].push(r-q-q*(i-1));


        if(i%t==0){
            cout<<sc<<" ";
        }
    }
    cout<<endl;

    for(int i=1;i<=n+m;i++){
        pair<int,int> pii = max({
            make_pair(pq[1].empty()?-INF:pq[1].front(),1),
            make_pair(pq[2].empty()?-INF:pq[2].front(),2),
            make_pair(pq[3].empty()?-INF:pq[3].front(),3)});
        int sc = pii.first;
        pq[pii.second].pop();

        if(i%t==0){
            cout<<sc+q*m<<" ";
        }
    }
    cout<<"\n";


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
