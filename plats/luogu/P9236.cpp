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
const int N = 1e5 + 5;
const int INF = 0x3f3f3f3f;
ll a[N];
ll pre[N];
ll cnt1[N];

ll cnt0[N];
void solve(){
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    ll ans = 0;
    // 当前异或前缀的第i为是否是1，如果是1表示和前面为0的
    // 所有点都可以有贡献
    // 碰到0了，那就是将其余前面是1的所有位置都做乘法，贡献就是
    // cnt[i][1]*num[1]
    // 碰到1，就是将前面所有0的个数做乘法，贡献就是]

    // cnt[0,i][0] * num[0]

    for(int i=0;i<=30;i++) cnt0[i] = 1;
    for(int i=1;i<=n;i++){
        pre[i] = pre[i - 1] ^ a[i];
        for (int j = 30; j >= 0; j--){
            // 如果当前前缀异或是1
            if (pre[i] &(1<<j))
            {
                ans += cnt0[j] * (1 << j), cnt1[j]++;
            }
            else
            {
                ans += cnt1[j] * (1 << j), cnt0[j]++;
            }
        }
    }

    cout<<ans<<endl;    
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