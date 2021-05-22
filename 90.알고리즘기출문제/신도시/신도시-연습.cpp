#include<stdio.h>
#include<iostream>
#include<queue>
using namespace std;

int N; // 정사각형-지도의크기-4이상10이하
int X, Y; // 수돗물, 공급되는 시작 좌표, 가로, 세로
int map[20][20]; // 지도 정보
// 격자 정보는 0 이상 11 이하
// 수돗물이 공급되는 격자의 위치 범위는 0 이상 9 이하임

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

int visit[20][20]; // 방문여부저장
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
	visit[startY][startX] = 1; // 방문 처리

	while (!q.empty()){
		NODE n = q.front();
		q.pop();

		// 지도 탐색
		for (int i = 0; i<4; i++){
			int dx = n.x + mx[i];
			int dy = n.y + my[i];

			if (dx < 0 || dx >= N || dy < 0 || dy >= N) continue; // 영역 체크
			if (visit[dy][dx] == 1) continue; // 이미 방문했으면 skip
			if (pipe[map[n.y][n.x]][i]){ // 이동 가능한지 check
				if (i == 0 && pipe[map[dy][dx]][2] != 1) continue;
				if (i == 1 && pipe[map[dy][dx]][3] != 1) continue;
				if (i == 2 && pipe[map[dy][dx]][0] != 1) continue;
				if (i == 3 && pipe[map[dy][dx]][1] != 1) continue;

				// 이동 가능한 경우
				q.push(NODE(dy, dx));
				visit[dy][dx] = 1;
			}

		}
	}
}

void DFS(int targetY, int targetX){
	visit[targetY][targetX] == 1;

	// 지도 탐색
	for (int i = 0; i<4; i++){
		int dx = n.x + mx[i];
		int dy = n.y + my[i];

		if (dx < 0 || dx >= N || dy < 0 || dy >= N) continue; // 영역 체크
		if (visit[dy][dx] == 1) continue; // 이미 방문했으면 skip
		if (pipe[map[n.y][n.x]][i]){ // 이동 가능한지 check
			if (i == 0 && pipe[map[dy][dx]][2] != 1) continue;
			if (i == 1 && pipe[map[dy][dx]][3] != 1) continue;
			if (i == 2 && pipe[map[dy][dx]][0] != 1) continue;
			if (i == 3 && pipe[map[dy][dx]][1] != 1) continue;

			// 이동 가능한 경우
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

	// 1. BFS를 통한 지도 탐색
	BFS(Y, X);

	// 2. 제거해야 하는 파이프 개수 구함
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