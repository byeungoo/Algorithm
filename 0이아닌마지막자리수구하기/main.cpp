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

		for (int j = 0; j < num; j++) { //2�� 5�� ��� �����ش�
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
		�����÷ο찡 �����ʰ� ���ִ°� ����Ʈ. ������ ���ٶ����� %������ ����
		������ �ڸ��� 1�� �ڸ��� ������ ������
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