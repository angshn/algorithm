#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios ::sync_with_stdio(0);cin.tie(0);cout.tie(0);
inline int read(){int x=0,f=1;char ch=getchar();while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}return x*f;}

#define ll long long int
const int N = 1e7 + 5;
const int INF = 0x3f3f3f3f;
inline int f(int x){
    for(int i=2;i*i<=x;i++){
        if(x%i==0) return i;
    }
    return 0;
}

void solve(){
    int l,r;cin>>l>>r;
    for(int i=l;i<=r;i++){
        int mp=f(i);
        if(mp){
            cout<<mp<<" "<<i-mp<<"\n";
            return;
        }
        else {
        }
    }
    cout << -1 << "\n";
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("/Users/syang/career/algorithm/in.txt","r",stdin);
#endif
    
    FASTIO;int t;cin>>t;while(t--)solve();return 0;
}