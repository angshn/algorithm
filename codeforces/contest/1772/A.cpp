#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include<set>
#define INPUT_PATH "/Users/syang/dev/algorithm/codeforces/in.in"
#define ll long long int
using namespace std;
const int N = 1e5 + 5;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen(INPUT_PATH, "r", stdin);
#endif
    //A+B?
    int t;
    scanf("%d",&t);
    while(t--){
        int x,y;
        scanf("%d+%d",&x,&y);
        printf("%d\n",x+y);
    }
}