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
const int N = 8e4 + 5;
const int INF = 0x3f3f3f3f;
ll d[N];
int n,m,mod,MIN,MAX;
ll pre[N];
void solve(){
    //差分+RMQ
    //ST不行
    cin>>n>>m>>mod>>MIN>>MAX;
    for(int i=1;i<=m;i++){
        string op;int l,r;ll x;cin>>op>>l>>r;
        
        if(op=="A"){
            cin>>x;
            d[l]+=x;d[r+1]-=x;
        }
        else {
            int cnt=0;
            ll y =0;
            for(int i=1;i<=r;i++){
                y = y+d[i];
                if (y * i % mod <= MAX && y * i % mod >= MIN && i >= l){
                    cnt++;
                }
            }
            cout<<cnt<<"\n";
        }
    }
    for(int i=1;i<=n;i++){
        d[i]=d[i]+d[i-1];
        if(d[i]*i%mod<=MAX && d[i]*i%mod>=MIN){
            pre[i]=pre[i-1]+1;
        }
        else {
            pre[i]=pre[i-1];
        }
    }
    int final;cin>>final;
    int l,r;
    for(int i=1;i<=final;i++){
        cin>>l>>r;
        cout<<pre[r]-pre[l-1]<<"\n";
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