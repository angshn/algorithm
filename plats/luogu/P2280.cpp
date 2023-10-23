#include <bits/stdc++.h>
#define ll long long int
inline int read(){int x=0,f=1;char ch=getchar();while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}return x*f;}
#define FASTIO                \
    ios ::sync_with_stdio(0); \
    cin.tie(0);               \
    cout.tie(0);
using namespace std;
const int N = 5e3 + 5;
const int INF = 0x3f3f3f3f;
int n,m;
int dp[N][N];
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x,y,w;cin>>x>>y>>w;
		dp[x+1][y+1]+=w;
	}
	int mx = -1;
	for(int i=1;i<N;i++){
		for(int j=1;j<N;j++){
			dp[i][j] =dp[i][j]+ dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
			if(i>=m && j>=m){
				mx = max(mx,dp[i][j]-dp[i-m][j]-dp[i][j-m]+dp[i-m][j-m]);
			}
		}
	}
	cout<<mx<<"\n";
}	
int main(){
#ifndef ONLINE_JUDGE
    freopen("D:\\devel\\algorithm\\in.txt","r",stdin);
#endif
    FASTIO
    solve();
    return 0;
}