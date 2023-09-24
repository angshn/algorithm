
#include<iostream>
#include<queue>
using namespace std;
const int N = 2e6;
deque<int> q;
int a[N];
int main(){
#ifndef ONLINE_JUDGE
    freopen("/Users/syang/career/algo/in.in", "r",stdin);
#endif
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];

    for(int i=1;i<=n;i++) {
        while(!q.empty() && a[q.back()] < a[i]) q.pop_back();
        q.push_back(i);
        if(i>=k){
            while(!q.empty() && q.front() <= i-k) q.pop_front();
            cout<<a[q.front()]<<"\n";
        }

    }
}