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
const int N = 2e5 + 5;
const int INF = 0x3f3f3f3f;
const int n = 6;
int a[n];
int z[6] = {1,2,3,5,10,20};
int w[N],v[N],s[N];
int sz = 0;
int dp[1005];

/**
 * dp[j]=max(dp[j],dp[j-w[i]]+c[i])
*/
void solve(){
    for(int i=0;i<n;i++)cin>>a[i];
    sz = 0;
    int sum = 0;
    for(int i=0;i<n;i++){
        sum+=a[i]*z[i];
    }
    for(int i=0;i<n;i++){
        for(int j = 1;j<=a[i];j<<=1){
            a[i] -= j;
            w[++sz] = j*z[i];
        }
        if(a[i]){
            w[++sz] = a[i]*z[i];
        }
    }

    for(int i=1;i<=sz;i++){
        for(int j = sum;j>=w[i];j--){
            dp[j] = max(dp[j],dp[j-w[i]]+w[i]);
        }
    }
    int cnt=0;
    for(int i=1;i<=sum;i++){
        cnt += dp[i] == i;
    }
    cout<<"Total="<<cnt<<'\n';
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