// 물류 창고
// 공장의 수 N(5<=N<=100)
//  도로 정보 수 5<=M<=N*(N-1)/2
// A 공장에서 B 공장 거리 D(1<=D<=100)
// 최적의 장소에 물류 창고를 지었을 때 가장 먼 공장과의 거리를 출력하시오
// 즉, 해당 문제는 공장에서 공장까지의 최단 거리를 모두 찾고 가장 먼 공장 간의 거리를 찾는 문제
// 그래프 문제로 해당 문제는 다익스트라 알고리즘, 플로이드 와샬, BFS 등의 사용이 가능하다.
// Floyd-warshall은 모든 정점에 대해서 거쳐가는 정점을 기준으로 최단 거리를 구하는 알고리즘으로 O(N^3)
// map 자체에서 업데이트가 가능하므로 sol이라는 map과 동일한 배열을 생성하여 여기서 업데이트 수행하도록 함


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
	for (int i = 0; i < N; i++) map[i][i] = sol[i][i] = 0;

	// map에 연결 내용 저장
	for (int i = 0; i < M; i++){
		map[A[i] - 1][B[i] - 1] = map[B[i] - 1][A[i] - 1] = D[i]; // 반대로 넣어줘야 함 - 연결이므로
		sol[A[i] - 1][B[i] - 1] = sol[B[i] - 1][A[i] - 1] = D[i];
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

// 거쳐가는 정점을 기준으로 최단 거리를 구하는 방법
void floyd_warshall(){
	// k는 거쳐가는 정점
	for (int k = 0; k < N; k++){
		// i는 start - j는 end
		for (int i = 0; i < N; i++){
			for (int j = 0; j < N; j++){
				if (sol[i][j] > sol[i][k] + sol[k][j]){
					sol[i][j] = sol[i][k] + sol[k][j];
				}
			}
		}
	}
}

// target을 시작으로 다른 정점들의 거리 중 가장 큰 값 리턴
int getMax(int target){
	int max = 0;
	for (int i = 0; i < N; i++){
		if (max < sol[target][i]) max = sol[target][i];
	}
	return max;
}

int solve(){
	//  모든 정점에 대해서 최적의 거리를 구함
	floyd_warshall();
	
	// 최적의 장소에 물류 창고를 지었을 때 가장 먼 공장과의 거리를 구함
	int ret = INF;
	for (int i = 0; i < N; i++){
		int mv = getMax(i);
		if (ret > mv) ret = mv;
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