// ���� ��ȣ�� ���� ��, �������� ����ϰ�, �� ������ ���ϴ� ���� ���� ������������ �����Ͽ� ����ϴ� ���α׷� �ۼ�
// Flood-Fill ����̹Ƿ� BFS �ʿ�
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
int visit[MAXN + 10][MAXN + 10]; // �湮ó�� Ȯ�� - �湮 ���θ� Ȯ��
queue<NODE> q;
int mx[] = { -1, 0, 1, 0 };
int my[] = { 0, -1, 0, 1 };

int idCnt[MAXN * MAXN]; // ���� id�� �� ���� �����ϴ� �迭

void BFS(int startY, int startX, int id){
	q.push(NODE(startY, startX));
	visit[startY][startX] = 1; // �湮 ó��
	idCnt[id]++; // ���� �� update

	while (!q.empty()){
		NODE n = q.front();
		q.pop();

		// ������ map �̵�
		for (int i = 0; i < 4; i++){
			int dy = n.y + my[i];
			int dx = n.x + mx[i];

			if (dx < 1 || dx > N || dy < 1 || dy > N) continue;
			if (visit[dy][dx] == 0 && map[dy][dx] == '1'){ // �湮�� �̷��� ������, ���� ���
				visit[dy][dx] = 1; // �湮 ó��
				q.push(NODE(dy, dx));
				idCnt[id]++; // ���� �� update
			}
		}
	}
}

void Solve(){
	// ������ id �ο�
	int id = 0;
	for (int y = 1; y <= N; y++){
		for (int x = 1; x <= N; x++){
			if (visit[y][x] == 0 && map[y][x] == '1'){ // �湮���� �ʰ� ������ �ִ� ��츸 ó��
				BFS(y, x, ++id);
			}
		}
	}
	cout << id << endl;

	// �ο��� id ������ �������� �������� ����
	sort(idCnt + 1, idCnt + id + 1); // 1���� id �̹Ƿ�
	for (int i = 1; i <= id; i++){
		cout << idCnt[i] << endl;
	}
}

int main(){
	InputData();//�Է�

	//���⼭���� �ۼ�
	Solve();

	return 0;
}