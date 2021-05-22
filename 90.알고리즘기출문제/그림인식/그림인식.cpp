// N*N 도화지에 여러 가지 색을 임의의 순서로 직사각형 모양으로 칠한다.
// 색칠된 도화지를 그림 인식을 통해 덧칠하지 않은 색의 개수를 찾으려고 한다.
// 도화지의 크기 N은 4 <=N<=10
// 색정보는 0<=색정보<=9, 0이면 색칠이 되어있지 않음을 의미
// 도화지에 보이는 색 중에 덧칠하지 않은 색의 개수를 출력하는 문제

// 도화지의 크기가 최대 10이므로 10(색정보)*10(도화지크기)*10(도화지크기)로 검색해도 시간복잡도는 충분하다
#include<iostream>
using namespace std;

int N; // 도화지 크기
char A[10 + 2][10 + 2]; // 도화지 색정보
int check[10]; // 덧칠정보를 저장하는 배열

void InputData(){
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
}

int solve(){
	int minX, minY, maxX, maxY;

	// 색 정보를 기준으로 검색
	// 색 정보가 있으면 min, max 영역을 구해서 그 안에 다른 색 정보가 있으면 check 배열에 표시
	for (int i = 1; i <= 9; i++){
		// 도화지 좌표 탐색
		minX = minY = 10; // 가질 수 없는 최대 수로 초기화
		maxX = maxY = 0;
		for (int y = 0; y < N; y++){
			for (int x = 0; x < N; x++){
				if (A[y][x] - '0' == i){ // 색이 있으면
					// 영역을 구함
					if (minX > x) minX = x;
					if (minY > y) minY = y;
					if (maxX < x) maxX = x;
					if (maxY < y) maxY = y;
				}
			}
		}
		// 색이 있는지 확인
		if (minX == 10) continue; // 가질 수 없는 좌표의 값(초기화 값)이면 다음 색  정보 확인을 위해 이동

		// 구한 영역을 통해 값 확인
		// 덧칠되지 않은 색의 정보와 사용되지 않은 색의 정보 구별이 필요함에 따라 사용되는 색의 정보는 1로 모두 표기
		// 1이면 사용되나 덧칠되지 않은 색의 정보, 1 이상의 값은 덧칠된 색의 정보로 구분
		check[i]++;
		for (int y = minY; y <= maxY; y++){
			for (int x = minX; x <= maxX; x++){
				if (A[y][x] - '0' != i) check[A[y][x] - '0']++;
			}
		}
	}

	// 덧칠되지 않은 색의 개수를 리턴
	int cnt = 0;
	for (int i = 1; i <= 9; i++){
		if (check[i] == 1) cnt++;
	}

	return cnt;
}

int main(){
	int ans = -1;
	InputData();

	// ToDo
	ans = solve();

	cout << ans << endl;
	return 0;
}