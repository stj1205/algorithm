#include <iostream>
#include<vector>
#include<queue>
using namespace std;

int N, M;
int s[200 + 10];
int e[200 + 10];
int sol[100 + 10];

void InputData()
{
	cin >> N >> M;
	for (int i = 1; i <= M; i++)
	{
		cin >> s[i] >> e[i];
	}
}
void OutputData()
{
	cout << sol[0];
	for (int i = 1; i<N; i++)
	{
		cout << " " << sol[i];
	}
}

int visit[100 + 10]; // 방문 등록 배열
vector<int> v[100]; // 인접한 노드를 저장할 배열
queue<int> q;

void updateMap(){
	for (int i = 1; i <= M; i++){
		v[s[i]].push_back(e[i]);
		v[e[i]].push_back(s[i]); // 반대도 넣어줌 - 연결 정보를 가지고 있으므로
	}
}

void BFS(int target){
	int depth = 0;

	// 1. vector 정보를 업데이트
	updateMap();

	// 2. BFS 수행
	q.push(target);
	visit[target] = 1; // 방문 처리
	while (!q.empty()){
		int node = q.front();
		sol[depth++] = node;
		q.pop();

		// 인접한 노드 정보 탐색 및 방문
		for (int i = 0; i < v[node].size(); i++){
			if (visit[v[node][i]] == 1) continue; // 방문되어있으면 방문하지 않음
			q.push(v[node][i]); // 방문
			visit[v[node][i]] = 1; // 방문 처리
		}
	}
}

int main()
{
	InputData();// 입력받는 부분

	// 여기서부터 작성
	BFS(1); // 출발점은 1

	OutputData();// 출력하는 부분
	return 0;
}