#include <iostream>
using namespace std;

void picnic(int friendRelation[][10], bool checkArr[]);
int result = 0;
int n, m;
int main() {

	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> n >> m;
		int friRelation[10][10] = { 0, };
		bool check[10] = { false, };

		//친구 관계 2차원 배열 초기화
		for (int j = 0; j < m; j++) {
			int friend1, friend2, temp;
			cin >> friend1 >> friend2;
			if (friend1 > friend2) {
				temp = friend1;
				friend1 = friend2;
				friend2 = temp;
			}
			friRelation[friend1][friend2] = 1;
		}
		picnic(friRelation, check);
		cout << result << endl;
		result = 0;
	}

	return 0;
}

void picnic(int friendRelation[][10], bool checkArr[]) { //n은 남은사람
	int first = -1;
	for (int i = 0; i < n; i++) { //모든 사람이 짝을 지었는지 확인
		if (checkArr[i] == false) {
			first = i;
			break;
		}
	}

	if (first == -1) { // 모두 짝을 지었을 경우
		result++;
		return;
	}

	//이 학생과 짝지을 학생을 결정
	for (int pairwith = first + 1; pairwith < n; pairwith++) {
		if (!checkArr[pairwith] && friendRelation[first][pairwith]) {
			checkArr[first] = checkArr[pairwith] = true;
			picnic(friendRelation, checkArr);
			checkArr[first] = checkArr[pairwith] = false;
		}
	}
}