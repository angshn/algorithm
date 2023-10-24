#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios ::sync_with_stdio(0);cin.tie(0);cout.tie(0);
inline int read(){int x=0,f=1;char ch=getchar();while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}return x*f;}

#define ll long long int
const int N = 2e5 + 5;
const int INF = 0x3f3f3f3f;
int n;
void f(int x){
    int hs=0;
    for(int i=15;i>=0;i--){
        if(x&(1<<i)){
            if(i==0){
                if(hs) cout<<"+";
                cout<<"2(0)";
            }
            else if(i==1){
                if(hs) cout<<"+";
                cout<<2;
            }
            else {
                if(hs) cout<<"+";
                cout<<"2(";
                f(i);
                cout<<")";
            }
            hs=1;
        }
    }
}
void solve(){
    cin>>n;
    f(n);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("/Users/syang/career/algorithm/in.txt","r",stdin);
#endif
    FASTIO;solve();return 0;
}