// BFS 문제로 queue에 좌표를 저장하면서 인접한 이동 가능한 좌표를 저장하면서 미로탈출하는 문제
// 거리 갱신에 대해서는 cost를 따로 두어도 되지만 visit map을 이용하여 cost를 저장해두면 따로 queue에 저장할 필요가 없다.
// 조건 확인 시 길이 아닌 경우 skip 하는 것이 정확할 수 있으며, cost 비교 시에도 continue가 아닌 작을 경우 update 하는 것이 실수를 방지할 수 있다.
// visit map을 사용할 경우 처음에는 INF로 모두 초기화가 필요하다!! INF로 되어 있어야 cost가 업데이트될 수 있다.
#include <iostream>
#include<queue>
using namespace std;

#define MAXN (100)
int W, H;//가로, 세로 크기
int sw, sh, ew, eh;//출발 가로세로, 도착 가로세로 좌표
char map[MAXN + 10][MAXN + 10];//지도정보

void InputData(){
	cin >> W >> H;
	cin >> sw >> sh >> ew >> eh;
	for (int i = 1; i <= H; i++){
		cin >> &map[i][1];
	}
}

#define INF 10000000
struct DATA{
	int y;
	int x;
	int cost;

	DATA(){
		y = x = cost = 0;
	}
	DATA(int _y, int _x, int _cost){
		y = _y;
		x = _x;
		cost = _cost;
	}
};
// 주의!! 최단 경로를 찾을 경우는 visit에 INF 값으로 저장 처리 후 확인해야 한다.
int visit[MAXN + 10][MAXN + 10]; // 거리 정보 저장
int mx[] = { -1, 0, 1, 0 };
int my[] = { 0, -1, 0, 1 };
queue<DATA> q;

int BFS(int startX, int startY, int dist){
	// 1. visit map을 INF로 초기화
	for (int i = 0; i < MAXN+10; i++){
		for (int j = 0; j < MAXN + 10; j++){
			visit[i][j] = INF;
		}
	}

	// 2. 길 탐색
	q.push(DATA(startY, startX, dist));
	visit[startY][startX] = dist;

	while (!q.empty()){
		DATA v = q.front();
		q.pop();
		

		// 미로 이동
		for (int i = 0; i < 4; i++){
			int dy = v.y + my[i];
			int dx = v.x + mx[i];

			if (dy < 1 || dy > H || dx < 1 || dx > W) continue; // 벗어난 경우 확인
			if (map[dy][dx] - '0' == 1) continue; // 벽인 경우 skip
			if (visit[dy][dx] < v.cost + 1) continue; // 최단 경로가 아닌 경우
			q.push(DATA(dy, dx, v.cost + 1));
			visit[dy][dx] = v.cost + 1;
		}
	}

	return visit[eh][ew];
}

int main(){
	int ans = 0;
	InputData();//입력

	//여기서부터 작성
	ans = BFS(sw, sh, 0);

	cout << ans << endl;//출력
	return 0;
}