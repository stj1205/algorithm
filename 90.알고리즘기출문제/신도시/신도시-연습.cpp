#include<stdio.h>
#include<iostream>
#include<queue>
using namespace std;

int N; // ���簢��-������ũ��-4�̻�10����
int X, Y; // ������, ���޵Ǵ� ���� ��ǥ, ����, ����
int map[20][20]; // ���� ����
// ���� ������ 0 �̻� 11 ����
// �������� ���޵Ǵ� ������ ��ġ ������ 0 �̻� 9 ������

void InputData(){
	int i, j;
	scanf("%d", &N);
	scanf("%d %d", &X, &Y);
	for (i = 0; i<N; i++){
		for (j = 0; j<N; j++){
			scanf("%1x", &map[i][j]);
		}
	}
}

int visit[20][20]; // �湮��������
typedef struct NODE{
	int y;
	int x;
	NODE(){
		y = x = 0;
	}
	NODE(int ny, int nx){
		y = ny;
		x = nx;
	}
}NODE;
queue<NODE> q;
int mx[] = { -1, 0, 1, 0 };
int my[] = { 0, -1, 0, 1 };
int pipe[12][4] = {
	{ 0, 0, 0, 0 }, // 0
	{ 1, 0, 1, 0 }, // 1
	{ 0, 1, 0, 1 }, // 2
	{ 0, 0, 1, 1 }, // 3
	{ 1, 0, 0, 1 }, // 4
	{ 1, 1, 0, 0 }, // 5
	{ 0, 1, 1, 0 }, // 6
	{ 0, 1, 1, 1 }, // 7
	{ 1, 0, 1, 1 }, // 8
	{ 1, 1, 0, 1 }, // 9
	{ 1, 1, 1, 0 }, // A
	{ 1, 1, 1, 1 }, // B
};

void BFS(int startY, int startX){
	q.push(NODE(startY, startX));
	visit[startY][startX] = 1; // �湮 ó��

	while (!q.empty()){
		NODE n = q.front();
		q.pop();

		// ���� Ž��
		for (int i = 0; i<4; i++){
			int dx = n.x + mx[i];
			int dy = n.y + my[i];

			if (dx < 0 || dx >= N || dy < 0 || dy >= N) continue; // ���� üũ
			if (visit[dy][dx] == 1) continue; // �̹� �湮������ skip
			if (pipe[map[n.y][n.x]][i]){ // �̵� �������� check
				if (i == 0 && pipe[map[dy][dx]][2] != 1) continue;
				if (i == 1 && pipe[map[dy][dx]][3] != 1) continue;
				if (i == 2 && pipe[map[dy][dx]][0] != 1) continue;
				if (i == 3 && pipe[map[dy][dx]][1] != 1) continue;

				// �̵� ������ ���
				q.push(NODE(dy, dx));
				visit[dy][dx] = 1;
			}

		}
	}
}

void DFS(int targetY, int targetX){
	visit[targetY][targetX] == 1;

	// ���� Ž��
	for (int i = 0; i<4; i++){
		int dx = n.x + mx[i];
		int dy = n.y + my[i];

		if (dx < 0 || dx >= N || dy < 0 || dy >= N) continue; // ���� üũ
		if (visit[dy][dx] == 1) continue; // �̹� �湮������ skip
		if (pipe[map[n.y][n.x]][i]){ // �̵� �������� check
			if (i == 0 && pipe[map[dy][dx]][2] != 1) continue;
			if (i == 1 && pipe[map[dy][dx]][3] != 1) continue;
			if (i == 2 && pipe[map[dy][dx]][0] != 1) continue;
			if (i == 3 && pipe[map[dy][dx]][1] != 1) continue;

			// �̵� ������ ���
			DFS(dy, dx);
		}

	}
}

void printMap(){
	for (int i = 0; i<N; i++){
		for (int j = 0; j<N; j++){
			cout << visit[i][j] << " ";
		}
		cout << endl;
	}
}

int Solve(){
	int cnt = 0;

	// 1. BFS�� ���� ���� Ž��
	BFS(Y, X);

	// 2. �����ؾ� �ϴ� ������ ���� ����
	for (int i = 0; i<N; i++){
		for (int j = 0; j<N; j++){
			if (map[i][j] != 0 && visit[i][j] == 0) cnt++;
		}
	}

	return cnt;
}

int main(){
	int ans = -1;
	InputData();

	ans = Solve();
	printf("%d\n", ans);
	return 0;
}