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
const int N = 1e2 + 5;
const int INF = 0x3f3f3f3f;
/**
 * 
 * dp[i][j]表示到i,j位置上的路径数量
 * dp[i][j] = dp[i-1][j]+dp[i][j-1]
*/
ll dp[N][N];
bool vis[N][N];
const int dir[8][2] = {{-2,-1},{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2}};
void solve(){
    int n,m,cx,cy;
    cin>>n>>m>>cx>>cy;
    vis[cx][cy]=1;
    for(int i=0;i<8;i++){
        int nx = dir[i][0] + cx,ny = dir[i][1] + cy;
        if (nx >= 0 && nx <= n && ny >= 0 && ny <= m) vis[nx][ny] = true;
    }

    dp[0][0] = 1;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            //判断当前坐标是否在马范围内
            if(!vis[i][j]) {
                if(i) dp[i][j] += dp[i-1][j];
                if(j) dp[i][j] += dp[i][j-1];

            }
        }
    }
    cout<<dp[n][m]<<endl;
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