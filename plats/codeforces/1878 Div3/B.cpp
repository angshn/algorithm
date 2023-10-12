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
const int N = 2e5 + 5;
const int INF = 0x3f3f3f3f;
int a[N];
void solve(){
    int n = 2e5;
    int x=2,y=3;
    a[1]=x,a[2]=3;
    for(int i=3;i<=n;i++){
        int c = y+1;
        while((c+y)%3==0) c++;
        x = y;
        y = c;
        a[i]=c;
    }
    int t;cin>>t;
    while(t--){
        int x;cin>>x;
        for(int i=1;i<=x;i++){
            cout<<a[i]<<" \n"[i==x];
        }
    }
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