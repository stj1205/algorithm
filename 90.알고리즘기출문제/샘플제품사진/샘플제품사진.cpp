#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

#define MAXHASH 50000

int N; // 제품 수 - 6이상 50000 이하
struct st{
	int X, ID; // 좌표 위치, 제품 ID
};
st A[50010];

// X 좌표 기준으로 정렬
bool compare(st& a, st& b){
	return a.X < b.X;
}

void InputData(){
	int i;
	scanf("%d", &N);
	for (i = 0; i < N; i++){
		scanf("%d %d", &A[i].X, &A[i].ID);
	}
}

// 모든 종류의 제품이 최소한 1개 이상 포함되도록 사진을 찍을 때 최소 사진 길이를 출력
// ID의 크기가 너무 크므로 용량 제한에 따라 ID size의 배열을 만들 수 없음
// 제품의 수가 50000 이하이므로 제품의 수에 맞게 ID 재할당 필요
// hash를 통해  확인 시 이전 id 와 new id 간의 저장 배열로 필요하다. -> check 배열 생성
int check[50010];
int maxCnt = 0;
int solve(){
	
	// 1. id 재 할당 - hash 사용
	for (int i = 0; i < N; i++){
		int nid = A[i].ID % MAXHASH;
		for (int j = 0; j < MAXHASH; j++){
			if (check[nid] == 0){ // 할당 가능한 경우
				maxCnt++;
				check[nid] = A[i].ID;
				A[i].ID = nid;
				break;
			}
			else if (check[nid] == A[i].ID){ // 이미 할당된 경우
				A[i].ID = nid;
				break;
			}

			nid = (nid + 1) % MAXHASH;
		}
	}

	// 2. 최소 사진 길이
	for (int i = 0; i < MAXHASH; i++) check[i] = 0; // check   배열 초기화
	// 2-1. X 좌표 기준으로 정렬
	sort(A, A + N, compare);
	// 2-2. 최소 사진 길이 구하기
	int cnt = 0;
	int i = 0, j = 0;
	int m_cost = 1000000000;
	while (true){
		// 1) i의 좌표 조절
		while (i < N && cnt != maxCnt){
			if (check[A[i].ID] == 0) cnt++;
			check[A[i].ID]++;
			i++;
		}

		// 2) 종료 조건 체크
		if (cnt != maxCnt) break;

		// 3) j 좌표 확인 - 시작 지점 체크
		while (check[A[j].ID] != 1){
			check[A[j].ID]--;
			j++;
		}

		// 4) min값 계산
		if (m_cost > A[i - 1].X - A[j].X) m_cost = A[i - 1].X - A[j].X;

		// 5. sliding window를 위한 j값 조절
		check[A[j].ID]--;
		j++;
		cnt--;
	}

	return m_cost;
}

int main(){
	int ans = -1;
	InputData();

	ans = solve();
	printf("%d\n", ans);
	return 0;
}