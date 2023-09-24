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
void solve(){
    char x;
    ll acc=0;
    ll sum = 0;
    scanf("%lld", &acc);
    ll acu = 1;
    while(scanf("%c",&x) && x!='\n'){
        ll acc2;
        scanf("%lld",&acc2);
        if(x == '+'){
            sum = (sum+acc) %10000;
            acc = acc2;
        }
        else if(x=='*'){
            acc = (acc2*acc) % 10000;

        }
    }
    printf("%lld\n",(sum+acc) %10000);
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