// 폭탄돌리기
// 원형이므로 mod 사용
#include<iostream>
using namespace std;

#define MAXN 100

int K; // 처음 폭탄을 가진 사람 번호
int N; // 퀴즈 개수
int T[MAXN + 10]; // 걸린 시간
char Z[MAXN + 10]; // 정답 여부
// 사람 수는 8명으로 정해져 있음

void InputData(){
	cin >> K;
	cin >> N;
	for (int i = 0; i<N; i++){
		cin >> T[i] >> Z[i];
	}
}

#define MAXH 8
int Solve(){
	int s = K - 1; // 0부터 7로 변환
	int stime = 0;

	// 퀴즈 수대로 확인
	for (int i = 0; i<N; i++){
		// 1. 시간 계산
		stime += T[i];
		if (stime >= 210) break; // 210초가 지났는지 확인

		// 퀴즈 정답이면 다음 사람에게 이동, 정답 아니면 그대로
		if (Z[i] == 'T') s = (s + 1) % MAXH;
	}
	return s + 1; // 1 ~ 8로 변환하여 리턴
}

int main(){
	int ans = -1;
	InputData();
	ans = Solve();
	cout << ans << endl;
	return 0;
}