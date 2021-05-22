// 지하철-SPJ
// 목적역까지 가는데 걸리는 최소 시간과 최소 시간으로 가는 최단 경로를 출력하는 문제
// 첫 줄에 N, M을 입력받는다. N은 지하철 수, M은 원하는 목적역 번호
// 1번역이 숙소가 있는 역이다.

#include <iostream>
#include <queue>
using namespace std;

#define MAXN (100)

int N, M;//지하철역수, 목적역
int S[MAXN + 2][MAXN + 2];//[s][e]=시간

void InputData(){
	cin >> N >> M;
	for (int s = 1; s <= N; s++){
		for (int e = 1; e <= N; e++){
			cin >> S[s][e];
		}
	}
}

#define INF 100000
queue<int> q;
int visit[MAXN + 2][MAXN + 2]; // 최소거리저장
int d[MAXN + 2]; // 경로 저장을 위해 사용
void BFS(int target){
	q.push(target);
	visit[target][target] = 0;

	while (!q.empty()){
		int x = q.front();
		q.pop();

		for (int i = 1; i <= N; i++){
			if (visit[target][i] > visit[target][x] + S[x][i]){
				visit[target][i] = visit[target][x] + S[x][i]; // 방문 처리-거리 업데이트
				q.push(i);
				d[i] = x; // 지나간 역의 정보를 저장
			}
		}
	}

}

void printPath(int x){
	if (x == 1){
		cout << x << " ";
		return;
	}

	printPath(d[x]);
	cout << x << " ";
}

void Solve(){
	// 1. visit 초기화
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++){
			visit[i][j] = INF;
		}
	}

	// 2. BFS를 통한 최단 거리 확인
	BFS(1); // target을 넣어줌 - 시작 위치
	cout << visit[1][M] << endl; // 목적역까지 가는 최소 시간 출력
	// Debug
	//for(int i=1; i<=N; i++){
	//	cout << visit[1][i] << " ";
	//}
	//cout << endl;

	// 3. 최소 시간으로 가는 최단 경로 출력
	printPath(M);
}

int main(){
	InputData();//입력
	Solve();
	return 0;
}