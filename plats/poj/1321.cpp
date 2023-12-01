#include  <map>
#include  <set>
#include  <cmath>
#include  <queue>
#include  <cstdio>
#include  <vector>
#include  <climits>
#include  <cstring>
#include  <cstdlib>
#include  <iostream>
#include  <algorithm>
using namespace std;
#define FASTIO ios ::sync_with_stdio(0);cin.tie(0);cout.tie(0);
inline int read(){int x=0,f=1;char ch=getchar();while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}return x*f;}

#define ll long long int
const int N = 2e5 + 5;
const int INF = 0x3f3f3f3f;
int n,k;
int vis[20];
string m[30];
int ans = 0;
void dfs(int p,int cnt){
    if(cnt==k) {
        ans++;
        return ;
    }
    if(p==n){
        return;
    }
    for(int i=0;i<n;i++){
        if(!vis[i] && m[p][i]=='#'){
            vis[i] = 1;
            dfs(p+1,cnt+1);
            vis[i] = 0;
        }
    }
    dfs(p+1,cnt);
}

void solve(){
    while(cin>>n>>k){
        ans=0;
        if(n==-1 && k==-1) return;
        for(int i=0;i<n;i++){
            cin>>m[i];
        }
        dfs(0,0);
        cout<<ans<<endl;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("/Users/syang/career/algorithm/in.txt","r",stdin);
#endif
    FASTIO;solve();return 0;
}