// [2주차][10과-도형기하격자][응용] 창고다각형
// 첫 줄에는 기둥의 개수를 나타내는 정수 N이 주어진다. N은 1이상 1,000 이하 이다. 
// 그 다음 N개의 줄에는 각 줄의 기둥의 왼쪽 면의 위치를 나타내는 정수 L과 높이를 나타내는 정수 H가 한 개의 빈 칸을 사이에 두고 주어진다. L과 H는 둘 다 1 이상 1,000 이하 이다.
// 첫 줄에 창고 다각형의 면적을 나타내는 정수를 출력한다.

#include <iostream>
#include <algorithm>
using namespace std;

int N;//기둥의 개수
struct POLE {
	int L, H;//기둥의 왼쪽 면의 위치, 기둥 높이
};
POLE pole[1000 + 10];

// 높이가 큰 순서대로 정렬
bool compare(POLE& a, POLE& b){
	return a.H > b.H;
}

void InputData(){
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> pole[i].L >> pole[i].H;
	}
}

int solve(){
	int area = 0;
	int min;
	int max;

	// 높이 기준으로 sort
	sort(pole, pole + N, compare);

	min = pole[0].L;
	max = min + 1;
	area = pole[0].H;
	for (int i = 1; i<N; i++){
		if (max <= pole[i].L){ // L max 갱신 조건
			area += pole[i].H * (pole[i].L + 1 - max);
			max = pole[i].L + 1;
		}
		else if (min > pole[i].L){
			area += pole[i].H * (min - pole[i].L);
			min = pole[i].L;
		}
	}

	return area;
}

int main() {
	int ans;
	InputData();//입력

	//여기서부터 작성
	ans = solve();

	cout << ans << endl;//출력
	return 0;
}