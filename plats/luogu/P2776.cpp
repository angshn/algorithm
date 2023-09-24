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
int g[N];
void solve(){
    int m,n;
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>g[i];
    vector<queue<int> > ques(m);
    int t;cin>>t;
    set<int> pool;
    queue<int> q;
    for(int i=0;i<t;i++){
        string op;
        int idx;
        cin>>op;
        if(op == "push"){
            cin>>idx;
            ques[g[idx]].push(idx);
            bool not_found = pool.find(g[idx])== pool.end();
            if(not_found){
                pool.insert(g[idx]);
                q.push(g[idx]);
            }
        }
        else{
            int g_first = q.front();

            int ele = ques[g_first].front();
            cout<<ele<<'\n';
            ques[g_first].pop();
            if(ques[g_first].size()==0){
                q.pop();
                pool.erase(pool.find(g_first));
            }   
        }
    }
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