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
const int N = 2e5 + 5;
const int INF = 0x3f3f3f3f;
int D[N];
int n;
void solve(){
    cin>>n;
    ll now = 0;
    ll pos=0,neg = 0;
    for(int i=1;i<=n;i++){
        ll x;cin>>x;
        D[i] = x-now;
        now = x;
        if(i==1) continue;
        D[i]>=0?pos+=D[i]:neg-=D[i];
    }
    cout<<max(pos,neg)<<"\n"<<abs(pos-neg)+1<<endl;
    



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