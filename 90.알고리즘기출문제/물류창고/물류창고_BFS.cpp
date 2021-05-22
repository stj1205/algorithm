// ���� â��
// ������ �� N(5<=N<=100)
//  ���� ���� �� 5<=M<=N*(N-1)/2
// A ���忡�� B ���� �Ÿ� D(1<=D<=100)
// ������ ��ҿ� ���� â�� ������ �� ���� �� ������� �Ÿ��� ����Ͻÿ�
// ��, �ش� ������ ���忡�� ��������� �ִ� �Ÿ��� ��� ã�� ���� �� ���� ���� �Ÿ��� ã�� ����
// �׷��� ������ �ش� ������ ���ͽ�Ʈ�� �˰���, �÷��̵� �ͼ�, BFS ���� ����� �����ϴ�.
// �Ʒ��� BFS�� Ǯ��
// BFS�� �׷����� Ǫ�� ��� ������ ���� start ������ �ٸ� ���� ������ �Ÿ��� ���ϴ� ��� 
// BFS �� DFS�� Ǫ�� ��� �Ÿ��� ���ϴ� ������ �׻� �Ÿ��� �����ϴ� visited �迭�� �ʿ��ϸ�(Ȥ�� �湮 ����) ó������ ��� INF�� �ʱ�ȭ�� �ʿ��ϴ�.

#include<iostream>
#include <queue>
using namespace std;
int N, M; // ���� ��, ���� ���� ��
int A[5000], B[5000], D[5000]; // ���� A, ���� B, �Ÿ� D

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
	// 1. ������� ���� ���� INF �� ����
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			map[i][j] = sol[i][j] = INF;
		}
	}

	// 2. �ڱ� �ڽ��� �Ÿ��� 0
	for (int i = 0; i < N; i++) map[i][i] = 0;

	// map�� ���� ���� ����
	for (int i = 0; i < M; i++){
		map[A[i] - 1][B[i] - 1] = map[B[i] - 1][A[i] - 1] = D[i]; // �ݴ�� �־���� �� - �����̹Ƿ�
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

		// i�� ���� ���� - target ���� i���� vs target - Ư�� ���� + Ư�� ���� + i ��
		for (int i = 0; i < N; i++){
			if (sol[target][i] > sol[target][v] + map[v][i]){
				sol[target][i] = sol[target][v] + map[v][i];
				q.push(i);
			}
		}
	}

	// max value�� ������Ʈ�� BFS ���� �� Ȯ�� �ʿ�!!
	for (int i = 0; i < N; i++) {
		if (max < sol[target][i]) max = sol[target][i];
	}

	return max; // ���� �� ������ �Ÿ�
}

int solve()
{
	int ret = INF;
	for (int i = 0; i < N; i++){
		int max = BFS(i); // ��ü ��带 ���������� �Ͽ� ������Ʈ
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