#include <bits/stdc++.h>
#define NO_MULTICASE
#define ll long long int
#define GETA(buf,size) for(int i=0;i<size;i++) cin>>buf[i];
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define FASTIO                \
    ios ::sync_with_stdio(0); \
    cin.tie(0);               \
    cout.tie(0);
using namespace std;
const int N = 1e5 + 5;
const int INF = 0x3f3f3f3f;
int a[N];
double pre[N];
int s,t;
int n;

bool check(double m){
    deque<int> q;
    for(int i=1;i<=n;i++){
        pre[i] = pre[i - 1] + double(a[i]) - m;
    }
    double ans = 0;
    for(int i=s;i<=n;i++){
        while(!q.empty()&&pre[q.back()]>=pre[i-s]) q.pop_back();//最大单调队列，
        q.push_back(i-s);//i-s是右边的点
        while(!q.empty() && q.front()<=i-t) q.pop_front();//i-t是左边的点，如果当前的点front比i-t还小，那就不在范围里，应该舍弃
        if(!q.empty()&&pre[i]-pre[q.front()]>=1e-5) return true;//如果已经存在这样的序列那就直接返回了，然后枚举更大的平均值
    }
    return false;
}


void solve(){
    scanf("%d",&n);
    scanf("%d %d",&s,&t);
    for(int i=1;i<=n;i++){
        scanf("%d", &a[i]);
    }
    //二分枚举最大得分，然后使用单调队列来查询是否存在这么大的分数
    double l = -10001, r = 10001;
    while((r-l)>1e-5){
        double mid = (l+r)/2;

        if(check(mid)) l=mid;
        else r=mid;
    }
    printf("%.3lf\n", l);

}
int main()
{
#ifndef ONLINE_JUDEGE
    freopen("D:\\devel\\algorithm\\in.txt","r",stdin);
#endif
    solve();
    return 0;
}