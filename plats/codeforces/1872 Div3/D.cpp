#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios ::sync_with_stdio(0);cin.tie(0);cout.tie(0);
inline int read(){int x=0,f=1;char ch=getchar();while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}return x*f;}

#define ll long long int
const int N = 2e5 + 5;
const int INF = 0x3f3f3f3f;

ll gcd(ll a,ll b){
    if(b){
        return gcd(b,a%b);
    }
    return a;
}

void solve(){
    ll n,x,y;cin>>n>>x>>y;
    ll lcm = x/gcd(x,y)*y;
    ll lengthx=n/x-n/lcm;
    ll lengthy=n/y-n/lcm;
    ll sumleft = lengthx*(n+n-lengthx+1)>>1;
    ll sumright = lengthy*(1+lengthy)>>1;
    cout<<sumleft-sumright<<"\n";
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("/Users/syang/career/algorithm/in.txt","r",stdin);
#endif
    FASTIO;int t;cin>>t;while(t--) solve();return 0;
}