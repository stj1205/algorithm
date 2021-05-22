// 물류 창고
// 공장의 수 N(5<=N<=100)
//  도로 정보 수 5<=M<=N*(N-1)/2
// A 공장에서 B 공장 거리 D(1<=D<=100)
// 최적의 장소에 물류 창고를 지었을 때 가장 먼 공장과의 거리를 출력하시오
// 즉, 해당 문제는 공장에서 공장까지의 최단 거리를 모두 찾고 가장 먼 공장 간의 거리를 찾는 문제
// 그래프 문제로 해당 문제는 다익스트라 알고리즘, 플로이드 와샬, BFS 등의 사용이 가능하다.
// 아래는 BFS로 풀이
// BFS로 그래프를 푸는 경우 주의할 점은 start 노드부터 다른 노드들 까지의 거리를 구하는 방법 
// BFS 및 DFS로 푸는 경우 거리를 구하는 내용은 항상 거리를 저장하는 visited 배열이 필요하며(혹은 방문 저장) 처음에는 모두 INF로 초기화가 필요하다.

#include<iostream>
#include <queue>
using namespace std;
int N, M; // 공장 수, 도로 정보 수
int A[5000], B[5000], D[5000]; // 공장 A, 공장 B, 거리 D

#define INF 1000000000

int map[100 + 10][100 + 10];
int sol[100 + 10][100 + 10];

void InputData(){
	int i;
	scanf("%d %d", &N, &M);
	for (i = 0; i < M; i++){
		scanf("%d %d %d", &A[i], &B[i], &D[i]);
	}
}

void InitMap(){
	// 1. 연결되지 않은 경우는 INF 로 저장
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			map[i][j] = sol[i][j] = INF;
		}
	}

	// 2. 자기 자신은 거리가 0
	for (int i = 0; i < N; i++) map[i][i] = 0;

	// map에 연결 내용 저장
	for (int i = 0; i < M; i++){
		map[A[i] - 1][B[i] - 1] = map[B[i] - 1][A[i] - 1] = D[i]; // 반대로 넣어줘야 함 - 연결이므로
	}
}

void printMap(){
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			//cout << map[i][j] << " ";
			cout << sol[i][j] << " ";
		}
		cout << endl;
	}
}

queue<int> q; 
int BFS(int target){
	int max = 0;
	q.push(target);
	sol[target][target] = 0;
	
	while (!q.empty()){
		int v = q.front();
		q.pop();

		// i는 도착 지점 - target 부터 i까지 vs target - 특정 지점 + 특정 지점 + i 비교
		for (int i = 0; i < N; i++){
			if (sol[target][i] > sol[target][v] + map[v][i]){
				sol[target][i] = sol[target][v] + map[v][i];
				q.push(i);
			}
		}
	}

	// max value의 업데이트는 BFS 끝난 후 확인 필요!!
	for (int i = 0; i < N; i++) {
		if (max < sol[target][i]) max = sol[target][i];
	}

	return max; // 가장 먼 공장의 거리
}

int solve()
{
	int ret = INF;
	for (int i = 0; i < N; i++){
		int max = BFS(i); // 전체 노드를 시작점으로 하여 업데이트
		if (ret > max) ret = max;
	}
	return ret;
}

int main()
{
	int ans = -1;
	InputData();

	// ToDo
	InitMap();
	ans = solve();
	//printMap();

	printf("%d\n", ans);

	return 0;
}