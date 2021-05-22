// ù ��° �ٿ��� ������ ����ũ�� N(N�� ����, 1<=N<=50)�� ���� ũ�� M(M�� ����, 1<=��<=50)�� �������� ���еǾ� �Է�
// �� ��° �ٺ��� N �ٿ� ���� 0�� 1�� ������ ���ڰ� �������� ���еǾ� �Է�
// �� ���� ������ �����Ű�� ���� �ּ����� ���� ����� ������ ���

#include<iostream>
#include<stdio.h>
#include<queue>
using namespace std;

int N; // ���� ũ��
int M; // ���� ũ��
int map[50 + 10][50 + 10]; // map

int visit[50 + 10][50 + 10]; // visit map - �湮 ǥ�ø� ����

// ���� �¿�� �̵���Ű�� ���� ��ǥ
int mx[] = { -1, 0, 1, 0 };
int my[] = { 0, -1, 0, 1 };

typedef struct NODE{
	int x, y;

	NODE(){
		y = 0;
		x = 0;
	}

	// ������ y, x ���� ������ ��!!
	NODE(int _y, int _x){
		y = _y;
		x = _x;
	}

}NODE;

// �Ÿ��� ���ϱ� ���� ��ǥ ����
NODE d[2][50 * 50 + 10]; // ������ 50 x 50�̸�, �� 2���� ���� ��ǥ�� �� ������ �ʿ�
int dSize[2]; // �� �� ����

queue<NODE> q; // BFS ����� ����  q ����

void InputData(){
	int i, j;
	scanf("%d %d", &N, &M);
	for (i = 1; i <= N; i++){
		for (j = 1; j <= M; j++){
			scanf("%d", &map[i][j]);
		}
	}
}

// ��ǥ Ȯ���� ���� �ӽ÷� ����
void OutputData(){
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= M; j++){
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
}

int ABS(int num){
	return (num < 0) ? -num : num;
}

void BFS(int idx, int y, int x){
	q.push(NODE(y, x));
	while (!q.empty()){

		NODE v = q.front();
		q.pop();

		// ����!! q�� �ִ� ��ÿ��� visit ó���� ���� �ʾ����� �� �� ó�� �������� �Ǿ��� ���� �־ �湮 ó�� Ȯ�� �ʿ� - �ƴϸ� �ߺ� ó���� �� ����
		if (visit[v.y][v.x] == 1) continue;

		visit[v.y][v.x] = 1; // �湮 ó��
		map[v.y][v.x] = idx; // group idx�� ������ ����

		// �ش� ���� y, x��ǥ �߰� �� size++
		d[idx - 2][dSize[idx - 2]] = NODE(v.y, v.x);
		dSize[idx - 2]++;

		// ��ǥ �̵��ϸ鼭 �˻�
		for (int i = 0; i < 4; i++){
			int dx = v.x + mx[i];
			int dy = v.y + my[i];

			if (dx < 1 || dx > M || dy < 1 || dy > N) continue;
			if (visit[dy][dx] == 0 && map[dy][dx] == 1){
				q.push(NODE(dy, dx));
			}
		}
	}
}

int getMinRails(){
	int cnt = 1000000;
	int diff = 0;

	for (int i = 0; i < dSize[0]; i++){
		for (int j = 0; j < dSize[1]; j++){
			diff = ABS(d[0][i].x - d[1][j].x) + ABS(d[0][i].y - d[1][j].y) - 1;
			if (diff < cnt) cnt = diff; 
		}
	}

	return cnt;
}

int main()
{
	int ans = -1;
	InputData();

	// ToDo
	int group_idx = 1; // �� �� group_id�� 2->3���� ����
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= M; j++){
			// map���� 1�̰ų� ���� �湮���� �ʴ� �ڸ��� ã���� BFS�� ����
			if (map[i][j] == 1 && visit[i][j] == 0){
				group_idx++;
				BFS(group_idx, i, j); // group_id ���� �� �ش� y, x ��ǥ�� �������� Ȯ���ϸ鼭 �˻� �ʿ�
			}
		}
	}

	ans = getMinRails();

	printf("%d\n", ans);
	return 0;
}