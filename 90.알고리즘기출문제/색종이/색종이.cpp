// 색종이
// N * N 크기의 흰색 도화지에 최대 9장의 색종이를 직사각형 모양으로 붙인다.
// 색종이가 가장 많이 겹쳐진 부분을 문서 천공기로 뚫으면 된다.
// 한 번의 천공기로 뚫을 수 있는 색종이의 최대 장수를 구하시오

// 도화지의 크기 N(N은 정수, 4<=N<10)
// 색 정보는 0부터 9까지 있으며 0은 빈공간이므로 실제 색은 1~9

// char로 input을 받았으므로 int로 수정하기 위해서는 A[i][j] - '0'의 연산이 필요함
// min, max를 통해 영역을 구하고 최대 겹치는 영역의 개수를 구하는 문제

#include<iostream>
using namespace std;

int N; // 도화지 크기
char A[10 + 2][10 + 2]; // 도화지 색 정보

int cnt[10 + 2][10 + 2]; // 색칠된 도화지 개수

void InputData(){
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
}

int solve(){
	for (int i = 1; i <= 9; i++){
		// 색 정보에 따른 minX, maxX, minY, maxY를 구한다.
		int minX = 100;
		int maxX = 0;
		int minY = 100;
		int maxY = 0;

		for (int y = 0; y < N; y++){
			for (int x = 0; x < N; x++){
				// 색 정보가 일치하는 경우
				if (A[y][x] - '0' == i){
					// min/max 좌표 업데이트
					if (minX > x) minX = x;
					if (maxX < x) maxX = x;
					if (minY > y) minY = y;
					if (maxY < y) maxY = y;
				}
			}
		}

		// 해당 좌표에 +1씩 색 영역 칠하기
		for (int y = minY; y <= maxY; y++){
			for (int x = minX; x <= maxX; x++){
				cnt[y][x]++;
			}
		}
	}

	int res = 0;
	for (int y = 0; y < N; y++){
		for (int x = 0; x < N; x++){
			if (cnt[y][x] > res) res = cnt[y][x];
		}
	}
	return res;
}

int main(){
	int ans = -1;
	InputData();

	// To Do
	ans = solve();

	cout << ans << endl;
	return 0;
}