#include <bits/stdc++.h>
#define ll long long int
#define GETA(buf,size) for(int i=0;i<size;i++) cin>>buf[i];
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
inline int read(){int x=0,f=1;char ch=getchar();while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}return x*f;}
#define FASTIO                \
    ios ::sync_with_stdio(0); \
    cin.tie(0);               \
    cout.tie(0);
using namespace std;
const int N = 2e3 + 5;
const int INF = 0x3f3f3f3f;
int s[N];

vector<int> G[N];


int d[N];//统计入度
int tp[N][N];
int n,m;
int vis[N];
void bfs(){
    queue<pair<int,int> >q;
    for(int i=1;i<=n;i++){
        if(d[i]==0){
            q.push({i,1});
        }
    }
    int ans = 1;
    while(!q.empty()){
        int u=q.front().first,dep=q.front().second;q.pop();
        for(int i=0;i<G[u].size();i++){
            int to = G[u][i];
            d[to]--;
            if(d[to]==0){
                q.push({to,dep+1});
                ans = max(ans, dep+1);
            }
        }
        
    }
    cout<<ans<<"\n";
}
int is_stop[N];
void solve(){
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int k;cin>>k;
        memset(s,0,sizeof(s));
        memset(is_stop,0,sizeof(is_stop));
        for(int j=1;j<=k;j++){
            cin>>s[j];
            is_stop[s[j]]=1;
        }

        for(int l=s[1];l<=s[k];l++){//未停靠站
            if(!is_stop[l]){
                for(int j=1;j<=k;j++){//停靠站
                    if(!tp[l][s[j]]){
                        tp[l][s[j]] = 1;
                        d[s[j]]++;
                        // addedge(l,s[j]);
                        G[l].push_back(s[j]);
                    }                    
                }
            }
        }
    }

    bfs();

}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("D:\\devel\\algorithm\\in.txt","r",stdin);
#endif
    FASTIO
    solve();
    return 0;
}