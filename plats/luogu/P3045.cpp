#include <bits/stdc++.h>
#define ll long long int
#define GETA(buf,size) for(int i=0;i<size;i++) cin>>buf[i];
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define FASTIO                \
    ios ::sync_with_stdio(0); \
    cin.tie(0);               \
    cout.tie(0);
#define pll pair<ll, ll>
using namespace std;
const int N = 5e4 + 5;
const int INF = 0x3f3f3f3f;
struct Node{
    int p,c;
}cows[N];
bool cmp1(const Node &x,const Node &y){
    return x.c<y.c;
}
bool vis[N];
void solve(){
    int n,k;
    ll m;
    cin>>n>>k>>m;
    priority_queue<int, vector<int>, greater<int> >q1;
    priority_queue<pll, vector<pll>, greater<pll> >q2,q3;
    for(int i=0;i<n;i++){
        cin>>cows[i].p>>cows[i].c;
        q2.push({cows[i].p,i});
        q3.push({cows[i].c,i});
    }
    for(int i=0;i<k;i++) q1.push(0);

    ll sum = 0;
    int cnt = 0;
    while(!q2.empty()){
        auto tp = q2.top();
        auto tc = q3.top();


        if(vis[tp.second]){
            q2.pop();
            continue;
        }
        if(vis[tc.second]){
            q3.pop();
            continue;
        }

        if(tp.first < tc.first + q1.top()){//选出按照优惠还是原价合适
            if(sum+tp.first>m) {
                break;
            }
            sum+=tp.first;
            q2.pop();
            cnt++;
            vis[tp.second]=1;
        }
        else {//使用优惠券
            if( sum+tc.first+q1.top()>m) break;
            sum+=tc.first+q1.top();
            cnt++;
            vis[tc.second] =1 ;
            q3.pop();
            q1.pop();
            q1.push({cows[tc.second].p - cows[tc.second].c});
        }
    }
   
    cout<<cnt;
   


}
int main()
{
#ifndef ONLINE_JUDGE
  freopen("/Users/syang/Downloads/P3045_17.in","r",stdin);
#endif
    FASTIO
    solve();
    return 0;
}