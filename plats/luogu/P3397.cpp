#include <bits/stdc++.h>
#define ll long long int
#define GETA(buf,size) for(int i=0;i<size;i++) cin>>buf[i];
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define FASTIO                \
    ios ::sync_with_stdio(0); \
    cin.tie(0);               \
    cout.tie(0);
inline int read();
using namespace std;
const int N = 5e3 + 5;
const int INF = 0x3f3f3f3f;

int n,m;
int D[N][N];
void solve(){
    cin>>n>>m;
    while(m--){
        int x1,x2,y1,y2;cin>>x1>>y1>>x2>>y2;
        D[x1][y1]++;
        D[x1][y2+1]--;
        D[x2+1][y1]--;
        D[x2+1][y2+1]++;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){

            D[i][j] = D[i][j] + D[i - 1][j] + D[i][j - 1] - D[i - 1][j - 1];
            cout<<D[i][j]<<" \n"[j==n];
        }
    }
}
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
    return x*f;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("/Users/syang/career/algorithm/in.txt","r",stdin);
#endif
    FASTIO
    solve();
    return 0;
}