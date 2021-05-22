// ����ö-SPJ
// ���������� ���µ� �ɸ��� �ּ� �ð��� �ּ� �ð����� ���� �ִ� ��θ� ����ϴ� ����
// ù �ٿ� N, M�� �Է¹޴´�. N�� ����ö ��, M�� ���ϴ� ������ ��ȣ
// 1������ ���Ұ� �ִ� ���̴�.

#include <iostream>
#include <queue>
using namespace std;

#define MAXN (100)

int N, M;//����ö����, ������
int S[MAXN + 2][MAXN + 2];//[s][e]=�ð�

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
int visit[MAXN + 2][MAXN + 2]; // �ּҰŸ�����
int d[MAXN + 2]; // ��� ������ ���� ���
void BFS(int target){
	q.push(target);
	visit[target][target] = 0;

	while (!q.empty()){
		int x = q.front();
		q.pop();

		for (int i = 1; i <= N; i++){
			if (visit[target][i] > visit[target][x] + S[x][i]){
				visit[target][i] = visit[target][x] + S[x][i]; // �湮 ó��-�Ÿ� ������Ʈ
				q.push(i);
				d[i] = x; // ������ ���� ������ ����
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
	// 1. visit �ʱ�ȭ
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++){
			visit[i][j] = INF;
		}
	}

	// 2. BFS�� ���� �ִ� �Ÿ� Ȯ��
	BFS(1); // target�� �־��� - ���� ��ġ
	cout << visit[1][M] << endl; // ���������� ���� �ּ� �ð� ���
	// Debug
	//for(int i=1; i<=N; i++){
	//	cout << visit[1][i] << " ";
	//}
	//cout << endl;

	// 3. �ּ� �ð����� ���� �ִ� ��� ���
	printPath(M);
}

int main(){
	InputData();//�Է�
	Solve();
	return 0;
}