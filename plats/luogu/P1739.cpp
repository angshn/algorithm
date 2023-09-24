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
    int acc=0;
    stack<char> st;
    while((x=getchar())!='@'){
        if(x=='('){
            st.push(x);
        }
        else if(x == ')'){
            if(!st.empty()){
                st.pop();
            }
            else {
                printf("NO\n");
                return;
            }
        }
    }
    printf("%s", st.empty()?"YES\n":"NO\n");
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