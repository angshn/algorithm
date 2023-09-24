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
    int acc = 0;
    stack<int> st;
    while((x=getchar())!='@'){
        if(isdigit(x)){
            acc = acc * 10 + (x - '0');
        }
        else if(x == '.'){
            st.push(acc);
            acc = 0;
        }
        else if(x == '+'){
            int op2 = st.top();st.pop();
            int op1 = st.top();st.pop();
            st.push(op1+op2);
        }
        else if(x == '-'){
            int op2 = st.top();st.pop();
            int op1 = st.top();st.pop();
            st.push(op1-op2);
        }
        else if(x == '*'){
            int op2 = st.top();st.pop();
            int op1 = st.top();st.pop();
            st.push(op1*op2);
        }
        else if(x == '/'){
            int op2 = st.top();st.pop();
            int op1 = st.top();st.pop();
            st.push(op1/op2);
        }
    }
    if(!st.empty()){
        printf("%d", st.top());
    }
}
int main()
{
#ifndef ONLINE_JUDGE
  freopen("/Users/syang/career/algo/in.in","r",stdin);
#endif
    // FASTIO
    solve();
    return 0;
}