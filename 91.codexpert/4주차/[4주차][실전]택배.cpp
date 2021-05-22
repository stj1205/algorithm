#include <iostream>
#include<algorithm>
using namespace std;

int N, C, M;
int S[10000 + 10];
int E[10000 + 10];
int NUM[10000 + 10];

typedef struct DATA{
	int s;
	int e;
	int cnt;
}DATA;
DATA A[10000 + 10];

bool compare(DATA& a, DATA& b){
	return a.e < b.e;
}

void InputData(){
	cin >> N >> C;
	cin >> M;
	for (int i = 0; i<M; i++){
		cin >> S[i] >> E[i] >> NUM[i];
	}
}

int truck[2000 + 10]; // 트럭에서 각 마을 별 가지고 있을 BOX 수 저장
int Solve(){
	// 1. struct에 정리
	for (int i = 0; i < M; i++){
		A[i].s = S[i];
		A[i].e = E[i];
		A[i].cnt = NUM[i];
	}

	// 2. 받는 마을 기준으로 오름차순
	sort(A, A + M, compare);

	// 3. 계산
	int sum = 0;
	// 3-1. 박스 정보의 개수 기준으로 확인
	for (int i = 0; i < M; i++){
		int maxv = 0;
		for (int k = A[i].s; k < A[i].e; k++){
			if (maxv < truck[k]) maxv = truck[k];
		}
		
		// 3-2. 옮길 수 있는 최대 수로 수정
		if (maxv + A[i].cnt <= C) maxv = A[i].cnt;
		else maxv = C - maxv;

		sum += maxv; // 총 옮길 수 있는 수 update
		// truck 배열 저장
		for (int k = A[i].s; k < A[i].e; k++){
			truck[k] += maxv;
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