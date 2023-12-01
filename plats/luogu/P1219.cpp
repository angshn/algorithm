#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios ::sync_with_stdio(0);cin.tie(0);cout.tie(0);
inline int read(){int x=0,f=1;char ch=getchar();while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}return x*f;}

#define ll long long int
const int N = 2e5 + 5;
const int INF = 0x3f3f3f3f;
int cnt = 0;
int n;
int ans[30];
int vis[3][30];
int sz; 
bool not_conflict(int x,int y){
    return !vis[0][y] and !vis[1][x+y] and !vis[2][y - x + n];
}

void st(int x,int y,int v){
    vis[0][y] = vis[1][x+y] = vis[2][y - x + n] = v;
}

void dfs(int line){
    if(line == n){
        if (cnt < 3)
        {
            for (int i = 0; i < n; i++) cout << ans[i] << " \n"[i == n - 1];
        }
        cnt++;
        return ;
    }
    for(int i=0;i<n;i++){
        if(not_conflict(line,i)){
            st(line, i, 1);
            ans[line] = i + 1;
            dfs(line + 1);
            st(line, i, 0);
        }
    }
}
void solve(){
    cin>>n;
    dfs(0);
    cout<<cnt<<"\n";
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("/Users/syang/career/algorithm/in.txt","r",stdin);
#endif
    FASTIO;solve();return 0;
}