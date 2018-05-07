#include <iostream>
using namespace std;

void solve(char gameBoard[][21], int curPoint, int x, int y);
int pointCnt = 0;
int h = 0, w = 0;
int result = 0;

int main(void)
{
	int t;
	cin >> t;

	for (int k = 0; k < t; k++) {

		pointCnt = 0;
		cin >> h >> w;
		char gameBoard[21][21] = { '#', };
		result = 0;
		//board판 초기화
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				cin >> gameBoard[i][j];
				if (gameBoard[i][j] == '.')
					pointCnt++;
			}
		}

		if (pointCnt % 3 != 0) { //'.'의 갯수가 3의 배수가 아니면 0출력 후 종료
			cout << 0 << endl;
		}
		else {
			solve(gameBoard, 0, 1, 1);
			cout << result << endl;
		}

	}

	return 0;
}

void printBoard(char gameBoard[][21]) {
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			cout << gameBoard[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void solve(char gameBoard[][21], int curPoint, int x, int y) {

	//printBoard(gameBoard);

	if (curPoint == pointCnt) {
		result++;
		return;
	}
	else if (x == w + 1) {
		return;
	}

	int nextX, nextY;
	if (y < w) {
		nextX = x;
		nextY = y + 1;
	}
	else if (y == w) {
		nextX = x + 1;
		nextY = 1;
	}

	if (gameBoard[x][y] == '.') {
		if (gameBoard[x][y + 1] == '.' && gameBoard[x + 1][y] == '.') {
			gameBoard[x][y] = '#';
			gameBoard[x][y + 1] = '#';
			gameBoard[x + 1][y] = '#';
			solve(gameBoard, curPoint + 3, nextX, nextY);
			gameBoard[x][y] = '.';
			gameBoard[x][y + 1] = '.';
			gameBoard[x + 1][y] = '.';
		}
		if (gameBoard[x][y + 1] == '.' && gameBoard[x + 1][y + 1] == '.') {
			gameBoard[x][y] = '#';
			gameBoard[x][y + 1] = '#';
			gameBoard[x + 1][y + 1] = '#';
			solve(gameBoard, curPoint + 3, nextX, nextY);
			gameBoard[x][y] = '.';
			gameBoard[x][y + 1] = '.';
			gameBoard[x + 1][y + 1] = '.';
		}
		if (gameBoard[x + 1][y] == '.' && gameBoard[x + 1][y + 1] == '.') {
			gameBoard[x][y] = '#';
			gameBoard[x + 1][y] = '#';
			gameBoard[x + 1][y + 1] = '#';
			solve(gameBoard, curPoint + 3, nextX, nextY);
			gameBoard[x][y] = '.';
			gameBoard[x + 1][y] = '.';
			gameBoard[x + 1][y + 1] = '.';
		}
		if (gameBoard[x + 1][y] == '.' && gameBoard[x + 1][y - 1] == '.') {
			gameBoard[x][y] = '#';
			gameBoard[x + 1][y] = '#';
			gameBoard[x + 1][y - 1] = '#';
			solve(gameBoard, curPoint + 3, nextX, nextY);
			gameBoard[x][y] = '.';
			gameBoard[x + 1][y] = '.';
			gameBoard[x + 1][y - 1] = '.';
		}
	}
	solve(gameBoard, curPoint, nextX, nextY);
}