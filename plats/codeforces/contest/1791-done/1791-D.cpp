#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <cstring>
#define INPUT_PATH "in.in"

#define TCASE \
    int tc;   \
    cin >> tc;
#define ll long long int
using namespace std;
const int N = 2e5 + 5;
char buffer[N];
int cache[26],cache2[26];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen(INPUT_PATH, "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    TCASE
    while (tc--)
    {
        memset(cache,0,sizeof(cache));
        memset(cache2,0,sizeof(cache2));
        int n;
        cin >> n;
        cin >> buffer;
        #define lseq(chr) chr - 'a'
        for(int i=0;i<n;i++){
            ++cache[lseq(buffer[i])];
        }
        int _max = -1;
        for(int i=0;i<n;i++){
            cache2[lseq(buffer[i])]++;
            cache[lseq(buffer[i])]--;
            int sigma = 0;
            for(int i=0;i<26;i++){
                sigma += min(1,cache[i])+min(1,cache2[i]);
            }
            _max = max(_max,sigma);
        }
        cout<<_max<<"\n";

    }
}