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
int a[N];
int p[N];
int last = 0;
int cnt = 0;
void init(int x){
    for(int i=2;i*i<=x;i++){
        if(x%i==0){
            a[cnt]=i;
            p[cnt]=1;
            x/=i;
            while(x%i==0){
                x/=i;
                p[cnt]++;
            }
            cnt++;
        }
    }
    if(x!=1){
        a[cnt]=x;
        p[cnt]=1;
        cnt++;
    }
}
int ksm(int a,int b,int mod){
    int ans = 1;
    a%=mod;
    while(b){
        if(b&1) ans=(ans*a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return ans;
}
//求a^b次方的数列的和
int sum(int x,int b,int mod){
    

    int k = 0;

    if(x%mod==1){//不存在逆元的情况,这种情况一定是x是mod的倍数，因为mod是素数
        k = (b+1)%mod;
    }
    else {//计算逆元
         k = (ksm(x,b+1,mod)-1+mod)%mod*ksm(x-1,mod-2,mod)%mod;
    }
    return k;
}

void solve(){
    int z,c;cin>>z>>c; 
    int ans = 1;
    const int mod= 9901;
    init(z);
    for(int i=0;i<cnt;i++){
        int k = p[i];
        ans = ans*sum(a[i],k*c,mod)%mod;
    }
    cout<<ans<<"\n";
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