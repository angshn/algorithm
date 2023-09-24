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
void build_tree(string mid, string post, int lm,int rm,int lp,int rp){
    if(lm>=rm) return;
    char root= post[rp-1];
    cout<<root;
    if(lm+1==rm) return ;
    int i=lm;
    for(;i<rm;i++){
        if(mid[i] == root){
            break;
        }
    }
    //[lm, i)是mid左边,
    //[i+1, rm) 是mid右边
    //[lm, i]是post左边
    //[i, rp-1)是post右边
    build_tree(mid,post, lm,i, lp, lp+i-lm);
    if(i<rm)
        build_tree(mid,post, i+1,rm,lp+i-lm, rp-1);
}

void solve(){

    string mid,post;
    cin>>mid>>post;
    int n = mid.length();
    build_tree(mid,post,0,n,0,n);
    cout<<endl;
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