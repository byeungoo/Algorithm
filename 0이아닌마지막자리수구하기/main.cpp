#include <iostream>
#include <fstream>

using namespace std;

int main() {

	ifstream fin;
	fin.open("input.txt");
	int t;
	fin >> t;

	for (int i = 0; i < t; i++) {
		int num;
		int num_array[101] = { 0, };
		int two_count = 0;
		int five_count = 0;
		fin >> num;

		for (int j = 0; j < num; j++) { //2와 5로 계속 나눠준다
			fin >> num_array[j];
			while (num_array[j] % 2 == 0) {
				num_array[j] /= 2;
				two_count++;
			}

			while (num_array[j] % 5 == 0) {
				num_array[j] /= 5;
				five_count++;
			}
		}
		int sum = 1;
		/*
		오버플로우가 나지않게 해주는게 포인트. 곱셈을 해줄때마다 %연산자 적용
		마지막 자리는 1의 자리의 곱으로 결정됨
		*/
		if (two_count>five_count) { 
			int diff = two_count - five_count; 
			for (int k = 0; k < num; k++) {
				sum *= num_array[k]%10;
				sum %= 10;
			}
			while (diff > 0) {
				sum *= 2;
				sum %= 10;
				--diff;
			}
			cout << sum % 10 << " " << five_count << endl;
		}
		else if (two_count<five_count) {
			int diff = five_count - two_count;
			for (int k = 0; k < num; k++) {
				sum *= num_array[k]%10;
				sum %= 10;
			}
			while (diff > 0) {
				sum *= 5;
				sum %= 10;
				--diff;
			}
			cout << sum % 10 << " " << two_count << endl;
		}
		else if (two_count == five_count) {
			for (int k = 0; k < num; k++) {
				sum *= num_array[k]%10;
				sum %= 10;
			}
			cout << sum % 10 << " " << five_count << endl;
		}
	}

	return 0;
}