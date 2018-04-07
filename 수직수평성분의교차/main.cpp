#include <iostream>
#include <fstream>

using namespace std;

void case1(int n1,int n2) { 
	if (n1*n2 > 0)
		cout << 0 << endl;
	else if (n1*n2 < 0)
		cout << 1 << endl;
	else if (n1*n2 == 0)
		cout << 2 << endl;
}

void case2(int n1, int n2) {
	if (n1*n2 > 0)
		cout << 0 << endl;
	else if (n1*n2 < 0)
		cout << 2 << endl;
	else if (n1*n2 == 0)
		cout << 2 << endl;
}

int main() {

	ifstream fin;
	fin.open("input.txt");
	int t;
	fin >> t;

	for (int i = 0; i < t;i++) {
		int vertex1[4];
		int vertex2[4];
		int flag;  //0이면 vertex2가 가로 선분, 1이면 vertex1이 가로 선분

		for (int j = 0; j < 4;j++)
			fin >> vertex1[j];
		for (int j = 0; j < 4; j++)
			fin >> vertex2[j];
		if (vertex1[0] == vertex1[2]) 
			flag = 0;
		else 
			flag = 1;

		if (flag == 0) {  //vertex2가 가로선인 경우
			if ((vertex2[1] > vertex1[1] && vertex2[1] < vertex1[3]) || (vertex2[1] < vertex1[1] && vertex2[1] > vertex1[3])) { //가로선y좌표가 세로선 y범위 사이에 있을경우
				int num1 = vertex2[0] - vertex1[0];
				int num2 = vertex2[2] - vertex1[0];
				case1(num1, num2);
			}
			else if (vertex2[1] == vertex1[1] || vertex2[1] == vertex1[3]) { //가로선y좌표가 세로선 꼭짓점의 좌표와 같을 경우
				int num1 = vertex2[0] - vertex1[0];
				int num2 = vertex2[2] - vertex1[0];
				case2(num1, num2);
			}
			else 
				cout << 0 << endl;	
		}
		else if (flag == 1) {//vertex1이 가로선인 경우
			if ((vertex1[1] > vertex2[1] && vertex1[1] < vertex2[3]) || (vertex1[1] < vertex2[1] && vertex1[1] > vertex2[3])) { //가로선y좌표가 세로선 y범위 사이에 있을경우
				int num1 = vertex1[0] - vertex2[0];
				int num2 = vertex1[2] - vertex2[0];
				case1(num1, num2);
			}
			else if (vertex1[1] == vertex2[1] || vertex1[1] == vertex2[3]) { //가로선y좌표가 세로선 꼭짓점의 좌표와 같을 경우
				int num1 = vertex1[0] - vertex2[0];
				int num2 = vertex1[2] - vertex2[0];
				case2(num1, num2);
			}
			else
				cout << 0 << endl;
		}
	}

	return 0;
}