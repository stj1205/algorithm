// 모두 보관하기 위해 필요한 최소의 냉장고를 구하는 문제 -> 교집합
#include <iostream>
#include<algorithm>
using namespace std;

int N;
int X[100 + 10];
int Y[100 + 10];

struct DATA{
	int x;
	int y;
};
DATA D[100 + 10];
bool compare(DATA& a, DATA& b){
	return a.y < b.y;
}

void InputData(){
	cin >> N;
	for (int i = 0; i<N; i++){
		cin >> X[i] >> Y[i];
	}
}

int Solve(){
	int cnt = 0;

	// 1. DATA 구조체에 값 넣기
	for (int i = 0; i < N; i++){
		D[i].x = X[i];
		D[i].y = Y[i];
	}

	// 2. y 기준으로 정렬
	sort(D, D + N, compare);

	// 3. 최소의 냉장고 구하기 - 교집합 구하기
	int s = -280;
	int e = -280;
	for (int i = 0; i < N; i++){
		if (e >= D[i].x){ // 겹치는 구간 발생
			// s와 e 갱신
			if (e > D[i].y) e = D[i].y;
			if (s < D[i].x) s = D[i].x;
		}
		else{ // 겹치는 구간 발생하지 않음
			cnt++;
			s = D[i].x;
			e = D[i].y;
		}
	}

	return cnt;
}

int main(){
	int ans = -1;

	InputData();// 입력받는 부분

	// 여기서부터 작성
	ans = Solve();

	cout << ans << endl;// 출력하는 부분
	return 0;
}