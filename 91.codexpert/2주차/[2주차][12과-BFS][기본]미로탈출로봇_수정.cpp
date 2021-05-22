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

	DATA(){
		y = x = 0;
	}
	DATA(int _y, int _x){
		y = _y;
		x = _x;
	}
};
// 주의!! 최단 경로를 찾을 경우는 visit에 INF 값으로 저장 처리 후 확인해야 한다.
int visit[MAXN + 10][MAXN + 10]; // 거리 정보 저장
int mx[] = { -1, 0, 1, 0 };
int my[] = { 0, -1, 0, 1 };
queue<DATA> q;

int BFS(int startX, int startY){
	// 1. visit map을 INF로 초기화
	for (int i = 0; i < MAXN + 10; i++){
		for (int j = 0; j < MAXN + 10; j++){
			visit[i][j] = INF;
		}
	}

	// 2. 길 탐색
	q.push(DATA(startY, startX));
	visit[startY][startX] = 0; // 출발 지점 거리 0으로 설정

	while (!q.empty()){
		DATA v = q.front();
		q.pop();
		//if (v.y == eh && v.x == ew) break; // BFS 너비우선탐색이므로 거리가 짧은 것이 먼저 도달함

		// 미로 이동
		for (int i = 0; i < 4; i++){
			int dy = v.y + my[i];
			int dx = v.x + mx[i];

			if (dy < 1 || dy > H || dx < 1 || dx > W) continue; // 벗어난 경우 확인
			if (map[dy][dx] != '0') continue; // 길이 아닌 경우는 skip

			// 아래와 같이 설정하는 경우 같아도 계속 push 함 -> 같을 경우는 넣어줄 필요가 없으므로
			//if (visit[dy][dx] < visit[v.y][v.x] + 1) continue; // 최단 경로가 아닌 경우
			//q.push(DATA(dy, dx));
			//visit[dy][dx] = visit[v.y][v.x] + 1;

			// 넣어주는 case를 조건문 안에 넣어서 수행할 수 있도록 확인 필요!!
			if (visit[dy][dx] > visit[v.y][v.x] + 1){
				q.push(DATA(dy, dx));
				visit[dy][dx] = visit[v.y][v.x] + 1;
			}
		}
	}

	return visit[eh][ew];
}

int main(){
	int ans = 0;
	InputData();//입력

	//여기서부터 작성
	ans = BFS(sw, sh);

	cout << ans << endl;//출력
	return 0;
}