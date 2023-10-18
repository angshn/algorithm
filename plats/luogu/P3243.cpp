#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios ::sync_with_stdio(0);cin.tie(0);cout.tie(0);
inline int read(){int x=0,f=1;char ch=getchar();while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}return x*f;}

#define ll long long int
const int N = 1e5 + 5;
const int INF = 0x3f3f3f3f;
int n,m;
int head[N],cnt;
int d[N];
vector<int> ans;

void init(){
    for(int i=0;i<N;i++) {head[i]=d[i]=0;}
    cnt=0;ans.clear();
}
struct Edge{
    int to,next;
}edge[N<<2];
void add(int u,int v){
    ++cnt;edge[cnt].to=v;edge[cnt].next=head[u];head[u]=cnt;d[v]++;
}

int bfs(){
    priority_queue<int > q;
    for(int i=1;i<=n;i++) if(!d[i]) q.push(i);
    while(!q.empty()){
        int u=q.top();q.pop();
        ans.push_back(u);
        for(int i=head[u];i;i=edge[i].next){
            int to = edge[i].to;
            d[to] --;
            if(d[to]==0){
                q.push(to);
            }
        }
    }

    return 0;

}
void solve(){
    cin>>n>>m;
    init();
    for(int i=1;i<=m;i++){
        int u,v;cin>>u>>v;
        add(v,u);
        
    }
    bfs();
    if(ans.size()!=n){
        cout<<"Impossible!\n";
    }
    else 
    for(int i=ans.size()-1;i>=0;i--){
        cout<<ans[i]<<" \n"[i==0];
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("/Users/syang/career/algorithm/in.txt","r",stdin);
#endif
    FASTIO;int t;cin>>t;while(t--) solve();return 0;
}