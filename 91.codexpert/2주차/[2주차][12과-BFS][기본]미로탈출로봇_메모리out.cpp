// BFS ������ queue�� ��ǥ�� �����ϸ鼭 ������ �̵� ������ ��ǥ�� �����ϸ鼭 �̷�Ż���ϴ� ����
// �Ÿ� ���ſ� ���ؼ��� cost�� ���� �ξ ������ visit map�� �̿��Ͽ� cost�� �����صθ� ���� queue�� ������ �ʿ䰡 ����.
// ���� Ȯ�� �� ���� �ƴ� ��� skip �ϴ� ���� ��Ȯ�� �� ������, cost �� �ÿ��� continue�� �ƴ� ���� ��� update �ϴ� ���� �Ǽ��� ������ �� �ִ�.
// visit map�� ����� ��� ó������ INF�� ��� �ʱ�ȭ�� �ʿ��ϴ�!! INF�� �Ǿ� �־�� cost�� ������Ʈ�� �� �ִ�.
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
	int cost;

	DATA(){
		y = x = cost = 0;
	}
	DATA(int _y, int _x, int _cost){
		y = _y;
		x = _x;
		cost = _cost;
	}
};
// ����!! �ִ� ��θ� ã�� ���� visit�� INF ������ ���� ó�� �� Ȯ���ؾ� �Ѵ�.
int visit[MAXN + 10][MAXN + 10]; // �Ÿ� ���� ����
int mx[] = { -1, 0, 1, 0 };
int my[] = { 0, -1, 0, 1 };
queue<DATA> q;

int BFS(int startX, int startY, int dist){
	// 1. visit map�� INF�� �ʱ�ȭ
	for (int i = 0; i < MAXN+10; i++){
		for (int j = 0; j < MAXN + 10; j++){
			visit[i][j] = INF;
		}
	}

	// 2. �� Ž��
	q.push(DATA(startY, startX, dist));
	visit[startY][startX] = dist;

	while (!q.empty()){
		DATA v = q.front();
		q.pop();
		

		// �̷� �̵�
		for (int i = 0; i < 4; i++){
			int dy = v.y + my[i];
			int dx = v.x + mx[i];

			if (dy < 1 || dy > H || dx < 1 || dx > W) continue; // ��� ��� Ȯ��
			if (map[dy][dx] - '0' == 1) continue; // ���� ��� skip
			if (visit[dy][dx] < v.cost + 1) continue; // �ִ� ��ΰ� �ƴ� ���
			q.push(DATA(dy, dx, v.cost + 1));
			visit[dy][dx] = v.cost + 1;
		}
	}

	return visit[eh][ew];
}

int main(){
	int ans = 0;
	InputData();//�Է�

	//���⼭���� �ۼ�
	ans = BFS(sw, sh, 0);

	cout << ans << endl;//���
	return 0;
}