#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int solution(int arr[]) {
	int maxSum = arr[0];
	int currentSum = arr[0];

	/*
	동적 배열의 사이즈를 알 수 있습니다.단, byte의 크기가 나오므로
	아래와 같이 sizeof()로 나누어주면 되겠습니다.
	_msize() / sizeof()
	_msize(array)/sizeof(*array);  -> 예시'

	일반 배열의 사이즈
	int len = sizeof(arr)/sizeof(int);
	*/

	int len = _msize(arr)/sizeof(*arr);
	for (int i = 1; i<len ; i++) {
		currentSum = max(currentSum + arr[i], arr[i]);   // max, min 함수 algorithm에 있는 함수
		maxSum = max(currentSum, maxSum);
	}
	return maxSum;
}

int main() {

	ifstream fin;
	fin.open("input.txt");
	
	int t;
	fin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		fin >> n;
		int *array = new int[n];
		
		for (int j = 0; j < n; j++) {
			int num;
			fin >> num;
			array[j] = num;
		}

		cout << solution(array) << endl; //동적할당한 배열도 인자로 이름 넘기면 됨
	}

	return 0;
}