#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios ::sync_with_stdio(0);cin.tie(0);cout.tie(0);
inline int read(){int x=0,f=1;char ch=getchar();while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}return x*f;}

#define ll long long int
const int N = 2e5 + 5;
const int INF = 0x3f3f3f3f;
int n;
int tot;
string shape=" /\\ \n"
void dfs(int lvl){
    if(lvl==1){
        //由n算出空格
        int i1=lvl<<1;
        for(int i=0;i<i1;i++){
            cout<<" ";
        }
    }
}

void solve(){
    cin>>n;
    tot=pow(2,n);
    dfs(n);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("/Users/syang/career/algorithm/in.txt","r",stdin);
#endif
    FASTIO;solve();return 0;
}