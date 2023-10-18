#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <cstdio>
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
struct Edge{
    int to,next;
}edge[N<<2];
int cnt,head[N],d[N];
int n;
void add(int u,int v){
    ++cnt;edge[cnt].to=v;edge[cnt].next=head[u];head[u]=cnt;d[v]++;
}
void bfs(){

    queue<int> q;
    for(int i=1;i<=n;i++){
        if(!d[i]){
            q.push(i);
        }
    }
    vector<int> ans;
    while(!q.empty()){
        int u=q.front();q.pop();
        ans.push_back(u);
        for(int i=head[u];i;i=edge[i].next){
            int &to = edge[i].to;

            d[to]--;
            if(!d[to]){
                q.push(to);
            }
        }
    }

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" \n"[i==ans.size()-1];
    }
}

void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        while(cin>>x){
            if(x==0) break;
            add(i,x);
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