//น้มุ10815น๘

#include <iostream>
#include <algorithm>
using namespace std;

int main() {

	int n, m;
	cin >> n;
	int *sang_arr = new int[n + 1];

	sang_arr[0] = -1999999999;
	for (int i = 1; i <= n; i++) {
		cin >> sang_arr[i];
	}

	cin >> m;
	int *my_arr = new int[m + 1];
	bool *check = new bool[m + 1];
	fill(check, check + m + 1, false);
	for (int i = 1; i <= m; i++) {
		cin >> my_arr[i];
	}

	sort(sang_arr + 1, sang_arr + n + 1);

	for (int i = 1; i <= m; i++) {
		int left = 1;
		int right = n;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (sang_arr[mid]>my_arr[i]) {
				right = mid - 1;
			}
			else if (sang_arr[mid]<my_arr[i]) {
				left = mid + 1;
			}
			else if (sang_arr[mid] == my_arr[i]) {
				check[i] = true;
				break;
			}
		}
	}

	for (int i = 1; i <= m; i++) {
		cout << check[i] << " ";
	}


	return 0;
}