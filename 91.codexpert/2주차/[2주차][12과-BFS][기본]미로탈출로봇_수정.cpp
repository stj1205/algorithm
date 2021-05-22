#include <iostream>
#include<queue>
using namespace std;

#define MAXN (100)
int W, H;//����, ���� ũ��
int sw, sh, ew, eh;//��� ���μ���, ���� ���μ��� ��ǥ
char map[MAXN + 10][MAXN + 10];//��������

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
// ����!! �ִ� ��θ� ã�� ���� visit�� INF ������ ���� ó�� �� Ȯ���ؾ� �Ѵ�.
int visit[MAXN + 10][MAXN + 10]; // �Ÿ� ���� ����
int mx[] = { -1, 0, 1, 0 };
int my[] = { 0, -1, 0, 1 };
queue<DATA> q;

int BFS(int startX, int startY){
	// 1. visit map�� INF�� �ʱ�ȭ
	for (int i = 0; i < MAXN + 10; i++){
		for (int j = 0; j < MAXN + 10; j++){
			visit[i][j] = INF;
		}
	}

	// 2. �� Ž��
	q.push(DATA(startY, startX));
	visit[startY][startX] = 0; // ��� ���� �Ÿ� 0���� ����

	while (!q.empty()){
		DATA v = q.front();
		q.pop();
		//if (v.y == eh && v.x == ew) break; // BFS �ʺ�켱Ž���̹Ƿ� �Ÿ��� ª�� ���� ���� ������

		// �̷� �̵�
		for (int i = 0; i < 4; i++){
			int dy = v.y + my[i];
			int dx = v.x + mx[i];

			if (dy < 1 || dy > H || dx < 1 || dx > W) continue; // ��� ��� Ȯ��
			if (map[dy][dx] != '0') continue; // ���� �ƴ� ���� skip

			// �Ʒ��� ���� �����ϴ� ��� ���Ƶ� ��� push �� -> ���� ���� �־��� �ʿ䰡 �����Ƿ�
			//if (visit[dy][dx] < visit[v.y][v.x] + 1) continue; // �ִ� ��ΰ� �ƴ� ���
			//q.push(DATA(dy, dx));
			//visit[dy][dx] = visit[v.y][v.x] + 1;

			// �־��ִ� case�� ���ǹ� �ȿ� �־ ������ �� �ֵ��� Ȯ�� �ʿ�!!
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
	InputData();//�Է�

	//���⼭���� �ۼ�
	ans = BFS(sw, sh);

	cout << ans << endl;//���
	return 0;
}