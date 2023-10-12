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
const int INF = 0x3f3f3f3f;
void solve(){
    ll n ,x,k;cin>>n>>k>>x;
    ll _min = k*(k+1)>>1;
    ll _max = (n*(n+1)>>1) - ((n-k)*(n-k+1)>>1);
    if(x>=_min && x<=_max){
        cout<<"Yes\n";
    }
    else {
        cout<<"No\n";
    }
    
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("/Users/syang/career/algorithm/in.txt","r",stdin);
#endif
    FASTIO
    int t;cin>>t;while(t--) solve();
    return 0;
}