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
const int N = 1e5 + 5;
const int INF = 0x3f3f3f3f;
int n,m;
int head[N],cnt,d[N],s[N];

void init(){
    for(int i=0;i<N;i++){
        head[i]=d[i]=0;
        s[i]=i;
    }
    cnt=0;
}
struct Edge{
    int to,next;
}edge[N<<2];

struct Edge2{
    int u,v;
    char op;
}edge2[N<<2];

void addedge(int u,int v){
    ++cnt;edge[cnt].to=v;edge[cnt].next=head[u];head[u]=cnt;d[v]++;
}

int Find(int x){
    return s[x]==x?s[x]:s[x]=Find(s[x]);
}

int num_blocks = 0;
bool Merge(int x,int y){
    int fx=Find(x),fy=Find(y);
    if(fx!=fy){
        s[fx]=fy;
        return true;
    }
    return false;
}
void bfs(){
    queue<int> q;
    for(int i=0;i<n;i++){
        if(i==Find(i)&&!d[i]){
            q.push(i);
        }
    } 
    bool uncertain = false;
    int num_vertex = 0;
    while(!q.empty()){
        if(q.size()>1) uncertain = true;
        int u = q.front();q.pop();
        num_vertex++;
        for(int i=head[u];i;i=edge[i].next){
            int to = edge[i].to;
            d[to]--;
            if(!d[to]){
                q.push(to);
            }
        }
    }
    if(num_vertex<n-num_blocks){
        cout<<"CONFLICT\n";
    }
    else if(uncertain){
        cout<<"UNCERTAIN\n";
    }

    else {
        cout<<"OK\n";
    }

}
void solve(){
    init();
    num_blocks = 0;
    for(int i=1;i<=m;i++){

        int u,v;string op;
        cin>>u>>op>>v;
        edge2[i].u=u;
        edge2[i].v=v;
        edge2[i].op=op[0];
        if(edge2[i].op == '='&&Merge(u,v)){
            num_blocks++;
        }
    }

    for(int i=1;i<=m;i++){
        int u, v;
        char op = edge2[i].op;
        int fu = Find(edge2[i].u);
        int fv = Find(edge2[i].v);
        if(op=='>'){
            addedge(fu,fv);
        }
        else if(op=='<'){
            addedge(fv,fu);
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
    while(cin>>n>>m)
        solve();
    return 0;
}