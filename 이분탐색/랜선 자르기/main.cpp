#include <iostream>
#include <algorithm>
using namespace std;

int main() {

	int k, n;
	cin >> k >> n;

	long long *lensun = new long long[k];
	long long max = 0;
	for (int i = 0; i < k; i++) {
		cin >> lensun[i];
		if (max < lensun[i])
			max = lensun[i];
	}

	long long left, right, mid, cnt = 0;
	long long sol_cnt;
	left = 1;
	right = max;
	long long result = 0;

	while (left <= right) {
		sol_cnt = 0;
		mid = (left + right) / 2;
		for (int j = 0; j < k; j++) {
			sol_cnt += lensun[j] / mid;
		}
		if (sol_cnt >= n) {
			left = mid + 1;
			if (mid > result) //랜선의 최대값을 구해야 하기 때문에
				result = mid;
		}
		else if (sol_cnt<n) {
			right = mid - 1;
		}
	}
	cout << result << endl;

	return 0;
}