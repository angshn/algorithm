#include <iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#define ll long long int
#define GETA(buf,size) for(int i=0;i<size;i++) cin>>buf[i];
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
inline int read(){int x=0,f=1;char ch=getchar();while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}return x*f;}
#define FASTIO                \
    ios ::sync_with_stdio(0); \
    cin.tie(0);               \
    cout.tie(0);
using namespace std;
const int N = 2e5 + 5;
const int INF = 0x3f3f3f3f;
int d[N];
void solve(){
    int n,i,h,r;cin>>n>>i>>h>>r;
    map<int,bool> Hash;
    for(int j=1;j<=r;j++){
        int A,B;cin>>A>>B;
        if(A>B) swap(A,B);
        int hs = (A+10000)*10000+B;
        if(Hash[hs]) continue;
        Hash[hs]=1;
        if(A+1<B){
            d[A+1]--;d[B]++;
        }
    }
    for(int i=1;i<=n;i++){
        d[i]+=d[i-1];
        cout<<h+d[i]<<"\n";
    }
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