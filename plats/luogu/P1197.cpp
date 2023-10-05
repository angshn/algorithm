#include <bits/stdc++.h>
#define ll long long int
#define GETA(buf,size) for(int i=0;i<size;i++) cin>>buf[i];
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define FASTIO                \
    ios ::sync_with_stdio(0); \
    cin.tie(0);               \
    cout.tie(0);
inline int read(){int x=0,f=1;char ch=getchar();while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}return x*f;}

using namespace std;
const int N = 4e5 + 5;
const int M = 2e5+5;
const int INF = 0x3f3f3f3f;
int n,m;
int s[N];
int blocks = 0;
void Init(){for(int i=0;i<N;i++) s[i]=i;}
int Find(int x){return x==s[x]?x:s[x]=Find(s[x]);}
void Merge(int x,int y){
    int fx = Find(x),fy=Find(y);
    if(fx!=fy){
         s[fx] = fy;
         blocks--;
    }
}
int head[N],cnt=0;
struct {
    int to,next,w;
}edge[N];
int del[N];
void addedge(int u,int v,int w){
    cnt++;
    edge[cnt].to = v;
    edge[cnt].w = w;
    edge[cnt].next = head[u];//类似于链表的前插
    head[u] = cnt;//指向最新的边
}


void solve(){
    n=read(),m=read();
    for(int i=1;i<=m;i++){
        int u=read(),v=read();
        addedge(u,v,0);addedge(v,u,0);
    }
    vector<int> ans;
    Init();
    int k=read();
    blocks = n-k;
    vector<int> d(k+1);
    for(int i=k;i>0;i--){
        d[i]=read();
        del[d[i]]=1;
    }
    for(int i=1;i<=n;i++){
        if(head[i]&&!del[i]){
            for(int j=head[i];j;j=edge[j].next){
                if(!del[edge[j].to]){
                    Merge(i,edge[j].to);
                }
            }
        }
    }
    ans.push_back(blocks);
    for(int i=1;i<=k;i++){
        int cur = d[i];
        del[cur]=0;
        blocks++;//修复当前点
        //将从cur出发的所有边加回
        for(int j=head[cur];j;j=edge[j].next){
            if(!del[edge[j].to]){
                Merge(cur,edge[j].to);
            }
        }
        ans.push_back(blocks);
    }
    for(int i=ans.size()-1;i>=0;i--)printf("%d\n",ans[i]);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("/Users/syang/career/algorithm/in.txt","r",stdin);
#endif
    solve();
    return 0;
}