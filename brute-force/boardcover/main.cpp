#include <iostream>
#include <fstream>
using namespace std;

void solve(char gameBoard[][25], int puzzleNum);
int pointCnt = 0;
int h = 0, w = 0;
int result = 0;
int boardPuzzle = 0;

int main(void)
{
	int t;
	cin >> t;

	for (int k = 0; k < t; k++) {

		pointCnt = 0;
		cin >> h >> w;
		char gameBoard[25][25] = { '#', };
		result = 0;
		//board판 초기화
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				cin >> gameBoard[i][j];
				if (gameBoard[i][j] == '.')
					pointCnt++;
			}
		}
		boardPuzzle = pointCnt / 3;

		if (pointCnt % 3 != 0) { //'.'의 갯수가 3의 배수가 아니면 0출력 후 종료
			cout << 0 << endl;
		}
		else {
			solve(gameBoard, 0);
			cout << result << endl;
			result = 0;
			pointCnt = 0;
		}
	}

	return 0;
}

void solve(char gameBoard[][25], int puzzleNum) {
	int x, y = -1;
	int breakFlag = 0;

	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			if (gameBoard[i][j] == '.') {
				x = i;
				y = j;
				breakFlag = 1;
				break;
			}
		}
		if (breakFlag == 1)
			break;
	}
	if (puzzleNum == boardPuzzle)
		result++;

	if (y == -1)
		return;

	int flag = 0;

	if (gameBoard[x][y + 1] == '.' && gameBoard[x + 1][y] == '.') {
		gameBoard[x][y] = '#';
		gameBoard[x][y + 1] = '#';
		gameBoard[x + 1][y] = '#';
		solve(gameBoard, puzzleNum + 1);
		gameBoard[x][y] = '.';
		gameBoard[x][y + 1] = '.';
		gameBoard[x + 1][y] = '.';
		flag = 1;
	}
	if (gameBoard[x][y + 1] == '.' && gameBoard[x + 1][y + 1] == '.') {
		gameBoard[x][y] = '#';
		gameBoard[x][y + 1] = '#';
		gameBoard[x + 1][y + 1] = '#';
		solve(gameBoard, puzzleNum + 1);
		gameBoard[x][y] = '.';
		gameBoard[x][y + 1] = '.';
		gameBoard[x + 1][y + 1] = '.';
		flag = 1;
	}
	if (gameBoard[x + 1][y] == '.' && gameBoard[x + 1][y + 1] == '.') {
		gameBoard[x][y] = '#';
		gameBoard[x + 1][y] = '#';
		gameBoard[x + 1][y + 1] = '#';
		solve(gameBoard, puzzleNum + 1);
		gameBoard[x][y] = '.';
		gameBoard[x + 1][y] = '.';
		gameBoard[x + 1][y + 1] = '.';
	}
	if (gameBoard[x + 1][y] == '.' && gameBoard[x + 1][y - 1] == '.') {
		gameBoard[x][y] = '#';
		gameBoard[x + 1][y] = '#';
		gameBoard[x + 1][y - 1] = '#';
		solve(gameBoard, puzzleNum + 1);
		gameBoard[x][y] = '.';
		gameBoard[x + 1][y] = '.';
		gameBoard[x + 1][y - 1] = '.';
		flag = 1;
	}
	if (flag == 0)  //어느경우도 만족하지 않으면 현재 recursive 탐색 종료
		return;
}