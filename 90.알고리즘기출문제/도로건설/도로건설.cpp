#include<iostream>
#include<stdio.h>
#include<queue>
using namespace std;

#define INF 10000000000

int N; // ���� ũ��
char map[110][110];

int mx[] = { -1, 0, 1, 0 };
int my[] = { 0, -1, 0, 1 };
int visited[110][110]; // �湮 �ּ� �Ÿ��� �����ϴ� �迭

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

	// 1. visit �ʱ�ȭ - �Ÿ��� �����ϸ鼭 �����ؾ� �ϹǷ� INF�� ��� �ʱ�ȭ �ʿ�
	for (int i = 0; i<N; i++){
		for (int j = 0; j<N; j++){
			visited[i][j] = INF;
		}
	}

	// 2. �湮 ó��
	q.push(NODE(y, x)); // 0, 0���� ����
	visited[y][x] = map[y][x] - '0';

	while (!q.empty()){
		NODE n = q.front();
		q.pop();

		for (int i = 0; i<4; i++){
			int dy = n.y + my[i];
			int dx = n.x + mx[i];

			if (dx < 0 || dx >= N || dy < 0 || dy >= N) continue; // �迭�� ũ�⸦ ������� üũ
			if (visited[dy][dx] > visited[n.y][n.x] + map[dy][dx] - '0'){ // ���� ������ �Ÿ��� �ּҰ� �Ǵ� ��츸 queue�� �����Ͽ� ������ �� �ֵ��� ��
				visited[dy][dx] = visited[n.y][n.x] + map[dy][dx] - '0';
				q.push(NODE(dy, dx));
			}
		}
	}

	return visited[N - 1][N - 1];
}

void DFS(int y, int x){
	// Ž��
	for (int i = 0; i < 4; i++){
		int dy = y + my[i];
		int dx = x + mx[i];

		if (dx < 0 || dx >= N || dy < 0 || dy >= N) continue; // �迭�� ũ�⸦ ������� üũ
		if (visited[dy][dx] > visited[y][x] + map[dy][dx] - '0'){ // ���� ������ �Ÿ��� �ּҰ� �Ǵ� ��츸 queue�� �����Ͽ� ������ �� �ֵ��� ��
			visited[dy][dx] = visited[y][x] + map[dy][dx] - '0';
			DFS(dy, dx);
		}
	}
}

int solve_DFS(){
	// 1. visited �ʱ�ȭ
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			visited[i][j] = INF;
		}
	}

	// DFS
	visited[0][0] = 0.; // start ���� �Ÿ� ����
	DFS(0, 0);

	return visited[N - 1][N - 1];
}

int main(){
	int ans = -1;
	Input_Data();

	// BFS - start
	ans = BFS(0, 0);
	// ans = solve_DFS(); // DFS�� ���� �ð� ���⵵ ���� ���鿡�� �� ���� �ð��� �ҿ��

	printf("%d\n", ans);

	return 0;
}