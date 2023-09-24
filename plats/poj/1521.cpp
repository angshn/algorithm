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
    string line;
    while(getline(cin,line) && line!="END"){
        int ans = 0;
        sort(line.begin(), line.end());
        int num = 1;
        priority_queue<int, vector<int> ,greater<int> > q;
        for(int i = 1;i<=line.length();i++){
            if(line[i] != line[i-1]) {
                q.push(num);
                num = 1;
            }
            else {
                num++;
            }
        }

        if(q.size()==1){
            ans = line.length();
        }

        while(q.size()>1){
            int op1 = q.top();q.pop();
            int op2 = q.top();q.pop();

            int res = op1+op2;
            q.push(res);
            ans += res;
        }
        printf("%d %d %.1f\n", line.length()*8, ans, (double)line.length()*8/(double)ans);
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