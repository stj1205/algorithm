// 가로, 세로의 크기가 각각 100 -> 영역을 모두 확인해도 시간 복잡도는 문제되지 않는다
// 가로, 세로의 크기가 각각 10인 정사각형 모양의 검은색 종이
// 바깥 둘레의 경우 max, min을 통하면 쉽게 구할 수 있으나 가운데 겹치지 않은 곳의 둘레는 구하기 어려움
// 즉, 도화지를 배열로 표현하고 영역은 1로 설정 -> 1 주변 확인하여 범위를 벗어나거나 0인 경우 둘레 길이 업데이트
#include <iostream>
using namespace std;

#define MAXN 100

int N;
int A[100 + 10];
int B[100 + 10];

int D[MAXN + 10][MAXN + 10]; // 도화지
int mx[] = { -1, 0, 1, 0 };
int my[] = { 0, -1, 0, 1 };

void InputData(){
	cin >> N;
	for (int i = 0; i<N; i++){
		cin >> A[i] >> B[i];
	}
}

void printD(){
	for (int y = 0; y < MAXN; y++){
		for (int x = 0; x < MAXN; x++){
			cout << D[y][x];
		}
		cout << endl;
	}
}

int Solve(){
	// 1. 도화지에 색 정보 입히기
	for (int i = 0; i < N; i++){
		// y좌표-x좌표에 대해서 색 정보 삽입
		for (int y = B[i]; y < B[i] + 10 && y < MAXN; y++){
			for (int x = A[i]; x < A[i] + 10 && x < MAXN; x++){
				D[y][x] = 1;
			}
		}
	}

	// 2. 둘레 길이 구하기
	int sum = 0;
	for (int y = 0; y < MAXN; y++){
		for (int x = 0; x < MAXN; x++){
			
			// 색 정보가 있는 경우 상하좌우 확인
			if (D[y][x] == 1){
				for (int i = 0; i < 4; i++){
					int dx = x + mx[i];
					int dy = y + my[i];

					if (dx < 0 || dx >= MAXN || dy < 0 || dy >= MAXN) sum++;
					else if (D[dy][dx] == 0) sum++;
				}
			}

		}
	}

	return sum;
}

int main(){
	int ans = -1;

	InputData();// 입력받는 부분

	// 여기서부터 작성
	ans = Solve();

	cout << ans << endl;// 출력하는 부분
	return 0;
}