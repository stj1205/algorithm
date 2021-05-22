// 그림인식문제
// N*N 도화지에 직사각형 모양으로 색칠을 함 -> N의 size는 4부터 10
// 색의 정보는 0부터 9(0은 색칠이 안됨)
// 도화지에 보이는 색 중에 덧칠하지 않은 색의 개수를 출력하는 문제
// 덧칠된 색의 개수를 저장하는 배열을 이용하여 확인 필요 -> 덧칠되지 않은 색과 색칠되지 않은 색의 구분 필요
#include<iostream>
#include<stdio.h>
using namespace std;

int N; // 도화지의 크기
char A[10 + 2][10 + 2];

void InputData(){
	int i;
	scanf("%d", &N);
	for (i = 0; i<N; i++) scanf("%s", A[i]);
}

#define MAXN 10
int check[MAXN];
int Solve(){
	int cnt = 0;
	int minX, minY, maxX, maxY;

	// 색의 정보 기준으로 검색
	for (int i = 1; i<10; i++){
		minX = minY = MAXN;
		maxX = maxY = 0;
		// 영역 구하기(직사각형이므로)
		for (int y = 0; y<N; y++){
			for (int x = 0; x<N; x++){
				// 색의 정보가 일치하는 경우 영역 업데이트
				if (A[y][x] - '0' == i){
					if (minX > x) minX = x;
					if (minY > y) minY = y;
					if (maxX < x) maxX = x;
					if (maxY < y) maxY = y;
				}
			}
		}

		// cout << i << minX << " " << maxX << " " << minY << " " << maxY << endl;

		// 색칠된 정보가 있는지 확인
		if (minX == MAXN) continue; // MAXN은 영역 이외의 정보이므로 색이 없음을 의미
		else check[i]++; // 색이 있으면 1 추가 업데이트 - 색칠되지 않은 색과의 분리를 위해
		// 중간에 1로 바꾸면 이전 색의 영역을 확인하면서 덧칠한 색의 정보를 지울 수 있다.(주의 필요!)
		// 혹은 0개이면 -1로 설정하여 분리를 해도 될 것 같다. 

		// 색 정보 영역에 다른 색이 덧칠되어 있으면 덧칠되어 있는 색의 count를 증가
		for (int y = minY; y <= maxY; y++){ // min 부터 max까지 검색
			for (int x = minX; x <= maxX; x++){
				int col = A[y][x] - '0';
				if (col != i) check[col]++; // 덧칠되어 있는 색의 count를 증가
			}
		}
	}

	// check 배열을 통해 덧칠되지 않은 색의 개수를 출력
	for (int i = 1; i<10; i++){
		if (check[i] == 1) cnt++;
	}
	return cnt;
}

int main(){
	int ans = -1;
	InputData();

	// ToDo
	ans = Solve();

	printf("%d\n", ans);
	return 0;
}
