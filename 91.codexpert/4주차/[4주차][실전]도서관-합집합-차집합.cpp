// 합집합, 차집합 구하는 문제
// 1. 시작시간을 기준으로 정렬
// 2. 끝나는 시간과 다음 시작 시간을 비교
// 3. 끝나는 시간과 시작 시간이 겹치는 경우 합집합이므로 끝나는 시간을 큰 값으로 갱신
#include <iostream>
#include<algorithm>
using namespace std;

int N;
int S[10000 + 10];
int E[10000 + 10];
int present;
int absent;

typedef struct ST {
	int s;
	int e;
}ST;
ST student[10000 + 10];

bool compare(ST& a, ST& b) {
	return a.s < b.s;
}

void InputData(void) {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> S[i] >> E[i];
	}
}

void solve() {
	// 1. init
	for (int i = 0; i < N; i++) {
		student[i].s = S[i];
		student[i].e = E[i];
	}

	// 2. 시작 시간 기준으로 정렬
	sort(student, student + N, compare);

	// 3. present & absent 구하기
	int s = student[0].s;
	int e = student[0].e;
	for (int i = 1; i < N; i++) {
		if (e >= student[i].s) { // 이어짐
			if (e < student[i].e) e = student[i].e;
			if (present < e - s) present = e - s;
		}
		else { // 이어지지 않음 - 갱신
			if (absent < student[i].s - e) absent = student[i].s - e;
			s = student[i].s;
			e = student[i].e;
		}
	}
}

int main(void) {
	InputData();// 입력받는 부분

	// 여기서부터 작성
	solve();

	cout << present << " " << absent << endl;// 출력하는 부분
	return 0;
}