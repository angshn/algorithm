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
const int N = 1e4 + 5;
const int INF = 0x3f3f3f3f;
struct Edge{
    int to,next;
}edge[N<<2];
int cnt;
int head[N];
int d[N];
int w[N];
bool cmp(const int &x, const int &y){
    return w[x]>w[y];
}
void addedge(int u,int v){
    ++cnt;
    edge[cnt].to=v;
    edge[cnt].next=head[u];
    head[u] = cnt;
    d[v]++;
}
int mem[N];//记录从某个节点开始到终点的最
int dfs(int u){
    if(mem[u]){
        return mem[u];
    }
    if(head[u]==0){
        return w[u];
    }
    int res = 0;
    for(int i=head[u];i;i=edge[i].next){
        res = max(res,dfs(edge[i].to));//所有子节点中最远的那个
    }
    mem[u] = w[u]+res;
    //子节点中最远的加上当前节点的值就是当前节点最远的
    return mem[u];
}

void solve(){
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        int id,len;cin>>id>>len;
        int x;
        w[id]=len;
        while(cin>>x){
            if(x==0) break;
            addedge(x,id);
        }
    }
    int res = -1;
    for(int i=1;i<=n;i++){
        if(!d[i]){
            
            res = max(res,dfs(i));
        }
    }
    cout<<res<<endl;

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