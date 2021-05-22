// 단지 번호를 붙인 후, 단지수를 출력하고, 각 단지에 속하는 집의 수를 오름차순으로 정렬하여 출력하는 프로그램 작성
// Flood-Fill 기법이므로 BFS 필요
#include <iostream>
#include<queue>
#include<algorithm>
using namespace std;

#define MAXN (25)
int N;
char map[MAXN + 10][MAXN + 10];

void InputData(){
	cin >> N;
	for (int i = 1; i <= N; i++){
		cin >> &map[i][1];
	}
}

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
int visit[MAXN + 10][MAXN + 10]; // 방문처리 확인 - 방문 여부만 확인
queue<NODE> q;
int mx[] = { -1, 0, 1, 0 };
int my[] = { 0, -1, 0, 1 };

int idCnt[MAXN * MAXN]; // 단지 id별 집 수를 저장하는 배열

void BFS(int startY, int startX, int id){
	q.push(NODE(startY, startX));
	visit[startY][startX] = 1; // 방문 처리
	idCnt[id]++; // 집의 수 update

	while (!q.empty()){
		NODE n = q.front();
		q.pop();

		// 근접한 map 이동
		for (int i = 0; i < 4; i++){
			int dy = n.y + my[i];
			int dx = n.x + mx[i];

			if (dx < 1 || dx > N || dy < 1 || dy > N) continue;
			if (visit[dy][dx] == 0 && map[dy][dx] == '1'){ // 방문된 이력이 없으며, 집인 경우
				visit[dy][dx] = 1; // 방문 처리
				q.push(NODE(dy, dx));
				idCnt[id]++; // 집의 수 update
			}
		}
	}
}

void Solve(){
	// 단지별 id 부여
	int id = 0;
	for (int y = 1; y <= N; y++){
		for (int x = 1; x <= N; x++){
			if (visit[y][x] == 0 && map[y][x] == '1'){ // 방문하지 않고 단지가 있는 경우만 처리
				BFS(y, x, ++id);
			}
		}
	}
	cout << id << endl;

	// 부여된 id 개수를 바탕으로 오름차순 수행
	sort(idCnt + 1, idCnt + id + 1); // 1부터 id 이므로
	for (int i = 1; i <= id; i++){
		cout << idCnt[i] << endl;
	}
}

int main(){
	InputData();//입력

	//여기서부터 작성
	Solve();

	return 0;
}