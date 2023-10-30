#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios ::sync_with_stdio(0);cin.tie(0);cout.tie(0);
inline int read(){int x=0,f=1;char ch=getchar();while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}return x*f;}

#define ll long long int
const int N = 2e5 + 5;
const int INF = 0x3f3f3f3f;

void solve(){
    int t;cin>>t;
    string s;
    while(t--){
        cin>>s;
        int cur = 1;
        int ans = 0;
        for(int i=1;i<=4;i++){
            int target = s[i-1]-'0';
            if(target==0){
                target = 10;
            }
            int movement = abs(target - cur);
            cur = target;
            ans+=movement+1;
        }
        cout<<ans<<"\n";
    }

}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("/Users/syang/career/algorithm/in.txt","r",stdin);
#endif
    FASTIO;solve();return 0;
}