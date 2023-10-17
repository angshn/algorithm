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
const int N = 1e3 + 5;
const int INF = 0x3f3f3f3f;
int n;
int c[N],U[N];
int W[N][N];
int head[N];
int d[N],cnt;
struct Edge{
    int to,next,w;
}edge[N<<2];
void addedge(int u,int v,int w){
    cnt++;edge[cnt].to=v;edge[cnt].next=head[u];head[u]=cnt;W[u][v]=w;
}
int sum[N];//累计i节点当前 sum w_ji*cj
int is_head[N];
void bfs(){


    queue<int> q;
    for(int i=1;i<=n;i++){
        if(!d[i]&&c[i]>0){
            is_head[i]=1;
            q.push(i);
        }
    }
    while(!q.empty()){
        int u=q.front();q.pop();
        //当前u的c值不变动
        for(int i=head[u];i;i=edge[i].next){
            d[edge[i].to]--;
            if(c[u]>0){//处于激活态时才能向后传播
                sum[edge[i].to]+=W[u][edge[i].to]*c[u];

            }
            if(d[edge[i].to]==0){
                q.push(edge[i].to);
                // to的所有前缀都处理完了，要更新当前的c
                c[edge[i].to] = sum[edge[i].to] - U[edge[i].to];
            }
        }
        
    }
    vector<int> ans;
    for(int i=1;i<=n;i++){
        if(!head[i]&&c[i]>0){
            ans.push_back(i);
        }

    }
    if(ans.size()==0){
        cout<<"NULL\n";
        
    }
    else {
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " " << c[ans[i]] << "\n";
    }
    return ;
}

void solve(){
    
    int p;
    cin>>n>>p;
    for(int i=1;i<=n;i++) cin>>c[i]>>U[i];
    for(int i=1;i<=p;i++){
        int u,v,w;cin>>u>>v>>w;
        addedge(u,v,w);
        d[v]++;
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