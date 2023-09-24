#include <bits/stdc++.h>
#define ll long long int
#define GETA(buf,size) for(int i=0;i<size;i++) cin>>buf[i];
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define FASTIO                \
    ios ::sync_with_stdio(0); \
    cin.tie(0);               \
    cout.tie(0);
using namespace std;
const int N = 2e5 + 5;
const int INF = 0x3f3f3f3f;
string outp="BIF";
int build_tree(string s,int l,int r){
    if(l==r-1){
        if(s[l]=='0'){
            cout<<outp[0];
            return 0;
        }
        else {
            cout<<outp[1];
            return 1;
        }
    }
    else {
        int lf = build_tree(s,l,(l+r)/2);
        int rf = build_tree(s,(l+r)/2,r);
        if (lf == 2 || rf == 2){
            cout<<outp[2];
            return 2;
        }
        else if((lf^rf) == 0){
            cout<<outp[lf];
            return lf;
        }
        else {
            cout<<outp[2];
            return 2;
        }
    }
}

void solve(){
    int n;cin>>n;
    int len = 1<<n;
    string s;cin>>s;
    build_tree(s, 0,len);
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