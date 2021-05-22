// 관람할 수 있는 최대 영화의 수를 구하는 문제
#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN ((int)1e5)
int N;//영화수
struct DATA{
	int s, e;//시작시간, 종료시간
};
DATA A[MAXN + 10];


void InputData(){
	cin >> N;
	for (int i = 0; i<N; i++){
		cin >> A[i].s >> A[i].e;
	}
}
bool compare(DATA& a, DATA& b){
	return a.e < b.e;
}
int Solve(){
	// 1. 끝나는 점을 기준으로 정렬
	sort(A, A + N, compare);

	// 2. 최대 영화 수 확인
	int cnt = 0;
	int e = 0; // 시작 시간보다 더 빠른 값으로 설정
	for (int i = 0; i<N; i++){
		if (e < A[i].s){
			cnt++;
			e = A[i].e;
		}
	}
	return cnt;
}

int main(){
	int ans;
	InputData();//입력
	ans = Solve();
	cout << ans << endl;//출력
	return 0;
}