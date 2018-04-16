#include <iostream>
#include <fstream>
#include <algorithm>
#include <stack>

using namespace std;

int main() {

	ifstream fin;
	fin.open("input.txt");
	int t;
	fin >> t;

	for (int i = 0; i < t; i++) {

		int n;
		fin >> n;
		int* arr = new int[n + 1];

		//입력 숫자 초기화
		for (int j = 0; j < n; j++) {
			fin >> arr[j];
		}
		arr[n] = 2100000000;

		//배열 정렬
		sort(arr, arr + n);

		int cnt = 1;
		int num;
		int max;

		//초기화
		num = arr[0];
		max = 0;

		stack<int> max_stack;
		max_stack.push(num);


		for (int j = 0; j < n; j++) {
			if (arr[j] == arr[j + 1]) {
				cnt++;
			}
			else {
				cnt = 1;
			}

			if (cnt == max) {
				max_stack.push(arr[j]);
			}
			else if (cnt > max) {
				max = cnt;
				while (max_stack.empty() != 1) {
					max_stack.pop();
				}
				max_stack.push(arr[j]);
			}
		}

		int k = max_stack.size();
		int *sort_max_num = new int[k];

		int j = 0;
		while (max_stack.empty() != 1) {
			sort_max_num[j] = max_stack.top();
			max_stack.pop();
			j++;
		}
		sort(sort_max_num, sort_max_num + k);

		cout << k << " " << max << " ";
		for (int p = 0; p < k; p++) {
			cout << sort_max_num[p] << " ";
		}
		cout << endl;
	}

	return 0;
}