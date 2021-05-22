// 셀프살균케어
// N*N 모눈 종이 영역에 LED 둘레 길이, 살균 대상의 좌표가 주어졌을 때 한 번에 살균할 수 있는 최대 개수를 구하는 문제
// 둘레 길이 L이 10으로 주어진 경우 살균 범위는 1X4, 2X3, 3X2, 4X1과 같은 4가지 형태의 직사각형이 된다.
// L/2 = W + H

// N*N 전체에 대해서 확인하는 방법은 N이 최대 10000의 범위를 가지므로 둘레에 따른 확인까지 하면 시간복잡도 문제가 발생할 수 있다.
// 살균 대상의 좌표를 기준으로 범위를 잡아서 확인해보면 시간복잡도를 줄일 수 있다.
#include<iostream>
#include <stdio.h>
using namespace std;

int y[110]; // 살균 대상의 y 좌표 배열
int x[110]; // 살균 대상의 x 좌표 배열
int N; // 필터 한 변의 크기
int L; // LED의 범위(길이)
int M; // 살균대상의 개수
int sol; // 정답

// Timeout -> getCount로 수정
void checkCnt(int r, int c, int h, int w){
	int cnt = 0;
	for (int i = r; i <= r + h; i++){
		for (int j = c; j <= c + w; j++){
			// 살균 대상
			for (int k = 0; k < M; k++){
				if (y[k] == i && x[k] == j) cnt++;
			}
		}
	}

	if (sol < cnt) sol = cnt;
}

void getCount(int r, int c, int h, int w){
	int cnt = 0;
	for (int k = 0; k < M; k++){
		if (y[k] >= r && y[k] <= r + h && x[k] >= c && x[k] <= c + w) cnt++;
	}
	if (sol < cnt) sol = cnt;
}

void Solve(){
	//살균 범위 기준 검색
	int h = 0;
	for (int w = 1; w < L / 2; w++){
		h = L / 2 - w;

		// 살균대상좌표 기준 검색
		for (int i = 0; i < M; i++){
			for (int j = 0; j < M; j++){
				// 좌표 및 살균 범위 기준으로 몇 개의 살균 대상이 있는지 확인하여 최대 살균 개수를 업데이트
				getCount(y[i], x[j], h, w);
			}
		}
	}
}

int main(){
	int i;
	scanf("%d %d %d", &N, &L, &M);
	for (i = 0; i < M; i++){
		scanf("%d %d", &y[i], &x[i]);
	}

	// ToDo
	Solve();

	printf("%d", sol);

	return 0;
}