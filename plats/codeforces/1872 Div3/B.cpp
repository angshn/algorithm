#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios ::sync_with_stdio(0);cin.tie(0);cout.tie(0);
inline int read(){int x=0,f=1;char ch=getchar();while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}return x*f;}

#define ll long long int
const int N = 2e3 + 5;
const int INF = 0x3f3f3f3f;
int d[N],s[N];
int room[N];
int Min[N];
void solve(){
    
    int n;cin>>n;
    for(int i=0;i<N;i++) {
        Min[i]=INF;room[i]=0;
    }
    for(int i=1;i<=n;i++) {
        int x,y;cin>>d[i]>>s[i];
        room[d[i]]++;
        Min[d[i]] = min(Min[d[i]],s[i]);//每个房间记录最小的炸弹触发事件
    }
    int ans=0;
    int limit=INF;
    for(int i=1;i<=limit;i++)
    {
        if(room[i]){
            limit = min(limit, ((Min[i] + 1) / 2 - 1)+i);
        }
        ans++;
    }
    cout<<ans<<endl;

}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("/Users/syang/career/algorithm/in.txt","r",stdin);
#endif
    FASTIO;
    int t;cin>>t;while(t--) solve();return 0;
}