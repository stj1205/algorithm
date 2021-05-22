#include <iostream>
using namespace std;

int R, C;//지도 크기 세로, 가로
char map[50 + 5][50 + 5];//지도 정보

void InputData(){
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		cin >> map[i];
	}
}

int dx[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[] = { 0, -1, -1, -1, 0, 1, 1, 1 };
int Solve(){
	int cnt = 0;
	// 1. 기존 악수 최대 수
	for (int y = 0; y<R; y++){
		for (int x = 0; x<C; x++){
			if (map[y][x] == 'o'){
				for (int i = 0; i<8; i++){
					int r = y + dy[i];
					int c = x + dx[i];
					if (r < 0 || r >= R || c < 0 || c >= C) continue;
					if (map[r][c] == 'o') cnt++;
				}
			}
		}
	}
	cnt = cnt / 2;

	// 2. 민혁이가 들어가는 경우의 최대 cnt 개수
	int mcnt = 0;
	for (int y = 0; y<R; y++){
		for (int x = 0; x<C; x++){
			if (map[y][x] != 'o'){ // 사람없는 곳에서 사람 검색
				// 주변 탐색
				int num = 0;
				for (int i = 0; i<8; i++){
					int r = y + dy[i];
					int c = x + dx[i];
					if (r < 0 || r >= R || c < 0 || c >= C) continue;
					if (map[r][c] == 'o') num++;
				}

				// max 갱신
				if (mcnt < num) mcnt = num;
			}
		}
	}
	cnt += mcnt;
	return cnt;
}

int main() {
	int ans;
	InputData();//입력
	ans = Solve();
	cout << ans << endl;//출력
	return 0;
}
