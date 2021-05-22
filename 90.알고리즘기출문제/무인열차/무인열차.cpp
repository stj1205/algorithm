// 첫 번째 줄에는 지도의 세로크기 N(N은 정수, 1<=N<=50)과 가로 크기 M(M은 정수, 1<=ㅡ<=50)이 공백으로 구분되어 입력
// 두 번째 줄부터 N 줄에 걸쳐 0과 1로 구성된 숫자가 공백으로 구분되어 입력
// 두 생산 라인을 연결시키기 위한 최소한의 레일 모듈의 개수를 출력

#include<iostream>
#include<stdio.h>
#include<queue>
using namespace std;

int N; // 세로 크기
int M; // 가로 크기
int map[50 + 10][50 + 10]; // map

int visit[50 + 10][50 + 10]; // visit map - 방문 표시를 위해

// 상하 좌우로 이동시키기 위한 좌표
int mx[] = { -1, 0, 1, 0 };
int my[] = { 0, -1, 0, 1 };

typedef struct NODE{
	int x, y;

	NODE(){
		y = 0;
		x = 0;
	}

	// 인자의 y, x 순서 주의할 것!!
	NODE(int _y, int _x){
		y = _y;
		x = _x;
	}

}NODE;

// 거리를 구하기 위한 좌표 저장
NODE d[2][50 * 50 + 10]; // 개수는 50 x 50이며, 총 2동에 대한 좌표의 값 저장이 필요
int dSize[2]; // 동 별 개수

queue<NODE> q; // BFS 사용을 위한  q 정의

void InputData(){
	int i, j;
	scanf("%d %d", &N, &M);
	for (i = 1; i <= N; i++){
		for (j = 1; j <= M; j++){
			scanf("%d", &map[i][j]);
		}
	}
}

// 좌표 확인을 위해 임시로 생성
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

		// 주의!! q에 넣는 당시에는 visit 처리가 되지 않았으나 이 후 처리 과정에서 되었을 수도 있어서 방문 처리 확인 필요 - 아니면 중복 처리될 수 있음
		if (visit[v.y][v.x] == 1) continue;

		visit[v.y][v.x] = 1; // 방문 처리
		map[v.y][v.x] = idx; // group idx의 값으로 수정

		// 해당 동에 y, x좌표 추가 및 size++
		d[idx - 2][dSize[idx - 2]] = NODE(v.y, v.x);
		dSize[idx - 2]++;

		// 좌표 이동하면서 검색
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
	int group_idx = 1; // 동 별 group_id를 2->3으로 저장
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= M; j++){
			// map에서 1이거나 아직 방문하지 않는 자리를 찾으면 BFS를 수행
			if (map[i][j] == 1 && visit[i][j] == 0){
				group_idx++;
				BFS(group_idx, i, j); // group_id 적용 및 해당 y, x 좌표를 기준으로 확장하면서 검색 필요
			}
		}
	}

	ans = getMinRails();

	printf("%d\n", ans);
	return 0;
}