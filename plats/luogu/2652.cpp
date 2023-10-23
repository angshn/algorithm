#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios ::sync_with_stdio(0);cin.tie(0);cout.tie(0);
inline int read(){int x=0,f=1;char ch=getchar();while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}return x*f;}

#define ll long long int
const int N = 2e5 + 5;
const int INF = 0x3f3f3f3f;
#define pii pair<int,int > 
int n;
pii a[N];
#define f(x) x.first
#define s(x) x.second

void clear(queue<int> &q){
    while(!q.empty()) q.pop();
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>f(a[i])>>s(a[i]);
    }
    sort(a+1,a+1+n);

    int cnt = unique(a+1,a+1+n)-(a+1);
    int ans = 0;


    queue<int> q;
    for(int i=1;i<=cnt;i++){
        if(f(a[i]) !=f(a[i-1])) clear(q);

        while(!q.empty() && s(a[i])-q.front()>=n) q.pop();

        q.push(s(a[i]));
        ans = max(ans, (int)q.size());
    }
    ans = (n-ans);
    cout<<ans<<"\n";
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("/Users/syang/career/algorithm/in.txt","r",stdin);
#endif
    FASTIO;solve();return 0;
}