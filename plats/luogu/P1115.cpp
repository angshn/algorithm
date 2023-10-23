#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios ::sync_with_stdio(0);cin.tie(0);cout.tie(0);
inline int read(){int x=0,f=1;char ch=getchar();while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}return x*f;}

#define ll long long int
const int N = 2e5 + 5;
const int INF = 0x3f3f3f3f;
int n;
int a[N];

int f(int l,int r){
    if(l==r) return a[l];

    int mid = (l+r)>>1;

    int ret1=-INF,ret2=-INF;
    int sum=0;
    for(int i=mid;i>=l;i--){
        sum+=a[i];
        ret1=max(ret1,sum);
    }
    sum=0;
    for(int i=mid+1;i<=r;i++){
        sum+=a[i];
        ret2=max(ret2,sum);
    }

    return max(max(f(l,mid),f(mid+1,r)),ret1+ret2);

}

void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    cout<<f(1,n)<<"\n";

}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("/Users/syang/career/algorithm/in.txt","r",stdin);
#endif
    FASTIO;solve();return 0;
}