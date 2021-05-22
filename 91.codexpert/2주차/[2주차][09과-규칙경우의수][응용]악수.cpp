#include <iostream>
using namespace std;

int R, C;//���� ũ�� ����, ����
char map[50 + 5][50 + 5];//���� ����

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
	// 1. ���� �Ǽ� �ִ� ��
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

	// 2. �����̰� ���� ����� �ִ� cnt ����
	int mcnt = 0;
	for (int y = 0; y<R; y++){
		for (int x = 0; x<C; x++){
			if (map[y][x] != 'o'){ // ������� ������ ��� �˻�
				// �ֺ� Ž��
				int num = 0;
				for (int i = 0; i<8; i++){
					int r = y + dy[i];
					int c = x + dx[i];
					if (r < 0 || r >= R || c < 0 || c >= C) continue;
					if (map[r][c] == 'o') num++;
				}

				// max ����
				if (mcnt < num) mcnt = num;
			}
		}
	}
	cnt += mcnt;
	return cnt;
}

int main() {
	int ans;
	InputData();//�Է�
	ans = Solve();
	cout << ans << endl;//���
	return 0;
}
