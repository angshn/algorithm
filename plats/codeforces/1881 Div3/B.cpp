#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios ::sync_with_stdio(0);cin.tie(0);cout.tie(0);
inline int read(){int x=0,f=1;char ch=getchar();while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}return x*f;}

#define ll long long int
const int N = 2e5 + 5;
const int INF = 0x3f3f3f3f;
int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}
int v[3];
void solve(){
    cin>>v[0]>>v[1]>>v[2];
    if(v[0]==v[1]&&v[1]==v[2]){
        cout<<"Yes\n";
        return;
    }
    sort(v,v+3);
    if(v[1]%v[0]!=0 || v[2]%v[0]!=0){
        cout<<"No\n";
    }
    else if(v[1]/v[0]-1+v[2]/v[0]-1<=3){
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
    FASTIO;int t;cin>>t;while(t--)solve();return 0;
}