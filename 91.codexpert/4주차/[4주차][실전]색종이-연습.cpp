// 창고다각형
// 가로 세로의 크기가 각각 10인 정사각형 모양의 검은색 색종이
// 색종이 수는 100 이하
// 가로, 세로의 크기가 각각 100인 정사각형 모양의 흰색 도화지

#include <iostream>
using namespace std;

int N;
int A[100 + 10];
int B[100 + 10];
void InputData(){
	cin >> N;
	for (int i = 0; i<N; i++){
		cin >> A[i] >> B[i];
	}
}

#define MAXN 100
int map[MAXN + 10][MAXN + 10];
int mx[] = { -1, 0, 1, 0 };
int my[] = { 0, -1, 0, 1 };

void initMap(){
	// 도화지 개수만큼
	for (int k = 0; k<N; k++){
		for (int i = A[k]; i<A[k] + 10; i++){
			for (int j = B[k]; j<B[k] + 10; j++){
				map[i][j] = 1; // 도화지 영역은 1로 표시
			}
		}
	}
}

int Solve(){
	// 1. map에 도화지 그리기
	initMap();

	// 2. map 정보를 기준으로 둘레의 길이 구하기
	int slen = 0;
	for (int y = 0; y<MAXN; y++){
		for (int x = 0; x<MAXN; x++){

			if (map[y][x] == 1){ // 칠해진 영역이면
				// 주변 확인 - 둘레 길이를 구하기 위해
				for (int i = 0; i<4; i++){
					int dx = x + mx[i];
					int dy = y + my[i];

					// 영역이 끝이면 둘레 확인 필요
					if (dx < 0 || dx >= MAXN || dy < 0 || dy >= MAXN){
						slen++;
						continue;
					}

					if (map[dy][dx] != 1) slen++;
				}
			}
		}
	}
	return slen;
}

int main(){
	int ans = -1;
	InputData();// 입력받는 부분
	ans = Solve();
	cout << ans << endl;// 출력하는 부분
	return 0;
}