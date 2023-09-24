#include <bits/stdc++.h>
#define ll long long int
#define GETA(buf,size) for(int i=0;i<size;i++) cin>>buf[i];
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define FASTIO                \
    ios ::sync_with_stdio(0); \
    cin.tie(0);               \
    cout.tie(0);
using namespace std;
const int N = 30;
const int INF = 0x3f3f3f3f;
int l[N],r[N];
void dfs(int rt){
    printf("%c", rt+'a');

    if(l[rt]!=-1){
        dfs(l[rt]);
    }
    if(r[rt]!=-1){
        dfs(r[rt]);
    }
}

void solve(){
    int n;cin>>n;
    fill(l,l+N,-1);
    fill(r,r+N,-1);

    int root = 0;
    for(int i=0;i<n;i++){
        string s;cin>>s;
        if(i==0){
            root  = s[0]-'a'; 
        }
        if(s[1]!='*'){
            l[s[0]-'a'] = s[1]-'a';
        }
        if(s[2]!='*'){
            r[s[0]-'a'] = s[2]-'a';
        }
    }
    dfs(root);
}
int main()
{
#ifndef ONLINE_JUDGE
  freopen("/Users/syang/career/algo/in.in","r",stdin);
#endif
    FASTIO
    solve();
    return 0;
}
