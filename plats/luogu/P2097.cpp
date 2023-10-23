#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios ::sync_with_stdio(0);cin.tie(0);cout.tie(0);
inline int read(){int x=0,f=1;char ch=getchar();while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}return x*f;}

#define ll long long int
const int N = 2e5 + 5;
const int INF = 0x3f3f3f3f;
int s[N];
void init(){
    for(int i=0;i<N;i++) s[i]=i;
}

int Find(int x){
    return s[x]==x?s[x]:s[x]=Find(s[x]);
}
void Merge(int x,int y){
    int fx=Find(x),fy=Find(y);
    if(fx!=fy){
        s[fx]=fy;
    }
}

void solve(){
    int n,m;cin>>n>>m;
    init();
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        Merge(u,v);
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        // if(Find(i)==i) ans++;
        Find(i);
    }
    sort(s+1,s+1+n);
    int cnt = unique(s+1,s+n+1)-(s+1);
    cout<<cnt<<"\n";
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("/Users/syang/career/algorithm/in.txt","r",stdin);
#endif
    FASTIO;solve();return 0;
}