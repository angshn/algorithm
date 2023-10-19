#include <bits/stdc++.h>
#define int long long
#define sz(a) ((int)a.size())
using namespace std;
using PII = pair<int, int>;
using i128 = __int128;
const int N = 2e5 + 10;

int n;
int a[N];

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	
	// 先去除两边的1
	int l = 1, r = n;
	while (l + 1 <= n && a[l] == 1) {
		l ++;
	}
	while (r - 1 >= 1 && a[r] == 1) {
		r --;
	}
	
	// 判断元素的累乘是否大于4e14，如果大于，就直接输出[l, r]
	int ji = 1;
	for (int i = l; i <= r; i ++) {
		if (1.0 * ji * a[i] > 4e14) {
			/*
			  由题意知，数组n个元素的和不会超过4e14
			  所以，当[l, r]内元素的累乘达到2e14的时候，
			  我们就可以确定需要对[l, r]段的元素替换为它们的
			  累乘。
			  证明：
			  假设正确的方法是对[ll, rr]段的元素替换为它们的
			  累乘(l <= ll <= rr <= r)，那么增加的大小为：
			  i ∈ [l, ll - 1] ∪ [rr + 1, r]内的元素之和，
			  而减小的大小则至少为：4e14 / 2 >= 2e14，
			  综合来说，则是变小的。
			  证毕。
			 */
			cout << l << ' ' << r << "\n";
			return;
		}
		ji *= a[i];
	}
	
	/*
	  暴力枚举。
	  因为已经确定a数组的累乘不会超过4e14，
	  即使其中 > 1 的数字都是2，数量也一定小于64个，
	  所以这个暴力虽然是O(n^2)的，但实际上消耗的时间很少
	 */
	vector <int> sum(n + 1, 0); // 累加
	vector <int> prod(n + 1, 0); // 累乘
	prod[0] = 1;
	vector <int> one; // 记录元素值为1的下标
	one.push_back(0);
	for (int i = 1; i <= n; i ++) {
		sum[i] = sum[i - 1] + a[i];
		prod[i] = prod[i - 1] * a[i];
		if (a[i] > 1) {
			one.push_back(i);
		}
	}
	
	int L = 1, R = 1, maxn = -1;
    for (int i = 1; i <= sz(one) - 1; i++)
    {
        for (int j = i; j <= sz(one) - 1; j++)
        {
            int pi = one[i], pj = one[j];
            // 把[pi, pj]区间内的所有数字换成一个数：这些数字的乘积
            if (prod[pj] / prod[pi - 1] + sum[n] - sum[pj] + sum[pi - 1] > maxn)
            {
                maxn = prod[pj] / prod[pi - 1] + sum[n] - sum[pj] + sum[pi - 1];
                L = pi;
                R = pj;
            }
        }
    }

    cout << L << ' ' << R << "\n";
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("D:\\devel\\algorithm\\in.txt","r",stdin);
#endif
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T = 1;
	cin >> T; cin.get();
	while (T --) solve();
	return 0;
}
