// ���� â��
// ������ �� N(5<=N<=100)
//  ���� ���� �� 5<=M<=N*(N-1)/2
// A ���忡�� B ���� �Ÿ� D(1<=D<=100)
// ������ ��ҿ� ���� â�� ������ �� ���� �� ������� �Ÿ��� ����Ͻÿ�
// ��, �ش� ������ ���忡�� ��������� �ִ� �Ÿ��� ��� ã�� ���� �� ���� ���� �Ÿ��� ã�� ����
// �׷��� ������ �ش� ������ ���ͽ�Ʈ�� �˰���, �÷��̵� �ͼ�, BFS ���� ����� �����ϴ�.
// Floyd-warshall�� ��� ������ ���ؼ� ���İ��� ������ �������� �ִ� �Ÿ��� ���ϴ� �˰������� O(N^3)
// map ��ü���� ������Ʈ�� �����ϹǷ� sol�̶�� map�� ������ �迭�� �����Ͽ� ���⼭ ������Ʈ �����ϵ��� ��


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
	for (int i = 0; i < N; i++) map[i][i] = sol[i][i] = 0;

	// map�� ���� ���� ����
	for (int i = 0; i < M; i++){
		map[A[i] - 1][B[i] - 1] = map[B[i] - 1][A[i] - 1] = D[i]; // �ݴ�� �־���� �� - �����̹Ƿ�
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

// ���İ��� ������ �������� �ִ� �Ÿ��� ���ϴ� ���
void floyd_warshall(){
	// k�� ���İ��� ����
	for (int k = 0; k < N; k++){
		// i�� start - j�� end
		for (int i = 0; i < N; i++){
			for (int j = 0; j < N; j++){
				if (sol[i][j] > sol[i][k] + sol[k][j]){
					sol[i][j] = sol[i][k] + sol[k][j];
				}
			}
		}
	}
}

// target�� �������� �ٸ� �������� �Ÿ� �� ���� ū �� ����
int getMax(int target){
	int max = 0;
	for (int i = 0; i < N; i++){
		if (max < sol[target][i]) max = sol[target][i];
	}
	return max;
}

int solve(){
	//  ��� ������ ���ؼ� ������ �Ÿ��� ����
	floyd_warshall();
	
	// ������ ��ҿ� ���� â�� ������ �� ���� �� ������� �Ÿ��� ����
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