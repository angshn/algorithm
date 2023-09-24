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
bool is_op(char x){
    return x == '+' || x == '-' || x == '*' || x == '/' || x=='^';
}
bool is_mt(char x){
    return x=='*' || x == '/';
}
bool is_mp(char x){
    return x=='+' || x=='-';
}
bool is_mm(char x){
    return x=='^';
}

bool higher(char x, char top){
    //是乘除高于其他
    if(is_mt(x) && is_mt(top)){
        return false;
    }
    if((is_mp(x) && is_mt(top)) || (is_mp(x) && is_mp(top))){
        return false;
    }

    if(!is_mm(x) && is_mm(top)){
        return false;
    }
    return true;
}
void solve(){
    vector<char> post;

    string mid;
    cin>>mid;
    stack<char> st;
    for(int i=0;i<mid.length();i++){
        char x = mid[i];

        if(x == '('){
            st.push(x);
        }
        else if(isdigit(x)){
            post.push_back(x);
        }
        else if(x == ')'){
            while(!st.empty() && st.top() !='('){
                x = st.top();st.pop();
                post.push_back(x);
            }
            st.pop();
        }
        else if(is_op(x)){
            if (st.empty() || st.top() == '('){
                st.push(x);
            }
            else {
                while(!st.empty() && !higher(x, st.top()) ){
                    post.push_back(st.top());
                    st.pop();
                }
                st.push(x);

            }
        }
    }
    while(!st.empty()){
        post.push_back(st.top());
        st.pop();
    }
    deque<int> dq;
    vector<bool> flag(post.size());
    for(int i=0;i<post.size();i++){
        flag[i] = is_op(post[i]);
        cout<<post[i]<<" \n"[i==post.size()-1];

    }




    for(int i=0;i<post.size();i++){
        if(is_op(post[i])){
            int op2 = dq.back();dq.pop_back();
            int op1 = dq.back();dq.pop_back();
            int r;
            if(post[i] == '*'){
                r = op1*op2;
            }
            else if(post[i] == '/'){
                r = op1/op2;
            }
            else if(post[i] == '+'){
                r = op1+op2;
            }
            else if(post[i] == '-'){
                r = op1 - op2;

            }else if(post[i] == '^'){
                r = pow(op1,op2);
            }
            dq.push_back(r);
            for(auto x: dq){
                cout<<x;
                if(i!=post.size()-1){
                    cout<<" ";
                }
            }
            for(int j=i+1;j<post.size();j++){
                cout<<post[j]<<" \n"[j==post.size()-1];
            }
        }
        else {
            if(!flag[i]){

                dq.push_back(post[i] - '0');
            }
        }
    }

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