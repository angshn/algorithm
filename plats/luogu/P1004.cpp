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
const int N = 10 + 5;
const int INF = 0x3f3f3f3f;
int dp[N][N][N][N];
int g[N][N];
void solve(){
    int n;cin>>n;
    while(1){
        int x,y,z;
        cin>>x>>y>>z;
        if(x==y&&y==z&&z==0){
            break;
        }
        g[x][y]=z;
    }

    for (int i = 1; i <= n; i++)
    {

        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                for (int l = 1; l <= n; l++)
                {

                    //i j k l当前状态分别可以从四个位置到达，分别取这四个位置的最大值作为来处，然后再加上各自位置上的点值
                    // 两两组合上的最大值
                    dp[i][j][k][l] = max(
                        max(dp[i - 1][j][k - 1][l], dp[i - 1][j][k][l - 1]),
                        max(dp[i][j - 1][k - 1][l], dp[i][j - 1][k][l - 1])) 
                        +g[i][j]+g[k][l];
                    // 同一点两个路径都走了就要减去一份
                    if (k == i && j == l)
                        dp[i][j][k][l] -= g[i][j];
                }
            }
        }
    }

    cout<<dp[n][n][n][n];
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