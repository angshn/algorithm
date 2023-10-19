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
int a[N],c[N];
struct Edge{
    int to,next;
    int w;
}edge[N<<1];
int head[N],d[N],cnt;
int n;
int vis[N];
int minv = INF;
vector<int> mem(N);
int sz = 0;
void init(){
    for(int i=0;i<N;i++){
        head[i]=d[i]=vis[i]=0;
    }
    sz=0;
    cnt=0;
}

void bfs(){
    queue<int > q;
    for(int i=1;i<=n;i++){
        if(!d[i]){
            q.push(i);
        }
    }


    while(!q.empty()){
        int u = q.front();q.pop();
        vis[u]=1;
        mem[++sz]=u;
        int to = a[u];
        d[to]--;
        if(d[to]==0){
            q.push(to);
        }

    }
}

void solve(){
    init();
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        d[a[i]]++;
    }
    for(int i=1;i<=n;i++) cin>>c[i];
    bfs();
    for(int i=1;i<=n;i++){
        if(d[i]){
            int st,ed;
            int minv=INF;
            int t = i;
            while(!vis[t]){
                vis[t]=1;
                if(c[t]<minv){
                    minv=c[t];
                    st=a[t];
                    ed=t;
                }
                d[a[t]]--;
                t=a[t];
            }

            while(st!=ed){
                mem[++sz]=st;
                st=a[st];
            }
            mem[++sz]=ed;
        }
    }

    for(int i=1;i<=sz;i++){
        cout<<mem[i]<<" \n"[i==sz];
    }

}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("/Users/syang/career/algorithm/in.txt","r",stdin);
#endif
    FASTIO
    int t;cin>>t;while(t--) solve();
    return 0;
}