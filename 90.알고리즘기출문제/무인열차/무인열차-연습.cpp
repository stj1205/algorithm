#include<iostream>
#include<stdio.h>
#include<queue>
using namespace std;

int N; // 세로 크기
int M; // 가로 크기
int map[50 + 10][50 + 10]; // map

int visit[50 + 10][50 + 10]; // visit map
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

NODE pos[3][50 * 50 + 10]; // 각 동별 좌표 저장
int railSize[3]; //각 동별 개수

void InputData(){
	int i, j;
	scanf("%d %d", &N, &M);
	for (i = 1; i <= N; i++){
		for (j = 1; j <= M; j++){
			scanf("%d", &map[i][j]);
		}
	}
}

int ABS(int num){
	return (num < 0) ? -num : num;
}

void BFS(int startY, int startX, int idx){
	q.push(NODE(startY, startX));
	visit[startY][startX] = 1; // 방문 처리
	
	// 좌표 저장 및 Size ++
	pos[idx][railSize[idx]] = NODE(startY, startX);
	railSize[idx]++;

	while (!q.empty()){
		NODE n = q.front();
		q.pop();

		for (int i = 0; i < 4; i++){
			int dx = n.x + mx[i];
			int dy = n.y + my[i];

			if (dx < 1 || dx > M || dy < 1 || dy > N) continue; // 영역을 벗어난 경우 skip
			if (visit[dy][dx] == 0 && map[dy][dx] == 1){ // 방문하지 않았으며, 생산라인인 경우
				q.push(NODE(dy, dx));
				visit[dy][dx] = 1; // 방문 처리

				// 좌표 저장 및 Size++
				pos[idx][railSize[idx]] = NODE(dy, dx);
				railSize[idx]++;
			}
		}
	}
}

int Solve(){
	// 1. BFS를 통한 레인 별 개수 구하기
	int idx = 0;
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= M; j++){
			if (visit[i][j] == 0 && map[i][j] == 1){ // 방문하지 않았으며, 생산라인인 경우
				BFS(i, j, ++idx);
			}
		}
	}

	// 2. 최소 거리 구하기
	int cnt = N + M;
	int tmpCnt;
	for (int i = 0; i < railSize[1]; i++){
		for (int j = 0; j < railSize[2]; j++){
			tmpCnt = ABS(pos[1][i].y - pos[2][j].y) + ABS(pos[1][i].x - pos[2][j].x) - 1;
			if (cnt > tmpCnt) cnt = tmpCnt;
		}
	}

	return cnt;
}

int main(){
	int ans = -1;
	InputData();

	// ToDo
	ans = Solve();

	printf("%d\n", ans);
	return 0;
}