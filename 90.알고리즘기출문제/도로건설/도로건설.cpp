#include<iostream>
#include<stdio.h>
#include<queue>
using namespace std;

#define INF 10000000000

int N; // 지도 크기
char map[110][110];

int mx[] = { -1, 0, 1, 0 };
int my[] = { 0, -1, 0, 1 };
int visited[110][110]; // 방문 최소 거리를 저장하는 배열

typedef struct NODE{
	int y, x;
	NODE(){
		y = x  = 0;
	}
	NODE(int _y, int _x){
		y = _y;
		x = _x;
	}
}NODE;
queue<NODE> q;

void Input_Data(){
	int i;
	scanf("%d", &N);
	for (i = 0; i < N; i++){
		scanf("%s", map[i]);
	}
}

int BFS(int y, int x){

	// 1. visit 초기화 - 거리를 갱신하면서 저장해야 하므로 INF로 모두 초기화 필요
	for (int i = 0; i<N; i++){
		for (int j = 0; j<N; j++){
			visited[i][j] = INF;
		}
	}

	// 2. 방문 처리
	q.push(NODE(y, x)); // 0, 0에서 시작
	visited[y][x] = map[y][x] - '0';

	while (!q.empty()){
		NODE n = q.front();
		q.pop();

		for (int i = 0; i<4; i++){
			int dy = n.y + my[i];
			int dx = n.x + mx[i];

			if (dx < 0 || dx >= N || dy < 0 || dy >= N) continue; // 배열의 크기를 벗어나는지 체크
			if (visited[dy][dx] > visited[n.y][n.x] + map[dy][dx] - '0'){ // 갱신 조건은 거리가 최소가 되는 경우만 queue에 삽입하여 갱신할 수 있도록 함
				visited[dy][dx] = visited[n.y][n.x] + map[dy][dx] - '0';
				q.push(NODE(dy, dx));
			}
		}
	}

	return visited[N - 1][N - 1];
}

void DFS(int y, int x){
	// 탐색
	for (int i = 0; i < 4; i++){
		int dy = y + my[i];
		int dx = x + mx[i];

		if (dx < 0 || dx >= N || dy < 0 || dy >= N) continue; // 배열의 크기를 벗어나는지 체크
		if (visited[dy][dx] > visited[y][x] + map[dy][dx] - '0'){ // 갱신 조건은 거리가 최소가 되는 경우만 queue에 삽입하여 갱신할 수 있도록 함
			visited[dy][dx] = visited[y][x] + map[dy][dx] - '0';
			DFS(dy, dx);
		}
	}
}

int solve_DFS(){
	// 1. visited 초기화
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			visited[i][j] = INF;
		}
	}

	// DFS
	visited[0][0] = 0.; // start 지점 거리 설정
	DFS(0, 0);

	return visited[N - 1][N - 1];
}

int main(){
	int ans = -1;
	Input_Data();

	// BFS - start
	ans = BFS(0, 0);
	// ans = solve_DFS(); // DFS의 경우는 시간 복잡도 적인 측면에서 더 많은 시간이 소요됨

	printf("%d\n", ans);

	return 0;
}