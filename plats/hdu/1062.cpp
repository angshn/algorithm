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
    stack<char> s;
    char x;
    getchar();
    while((x = getchar() )!= -1){
        if(x!='\n' && x !=' '){
            s.push(x);
        }
        else if(x==' ' || x == '\n'){
            while(!s.empty()){
                printf("%c", s.top());
                s.pop();
            }
        }

        if(x == '\n' || x ==' '){
            printf("%c", x);
        }
    }

            
}
int main()
{
#ifndef ONLINE_JUDGE
  freopen("/Users/syang/career/algo/in.in","r",stdin);
#endif
    FASTIO
    int t;scanf("%d", &t);
    while(t--) solve();
    return 0;
}