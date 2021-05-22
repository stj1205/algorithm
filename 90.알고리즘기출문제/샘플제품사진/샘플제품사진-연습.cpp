// 샘플제품사진
// N개의 제품이 일렬로 배치되어 있는데, 같은 종류의 제품들도 있을 때 모든 종류의 제품을 최소한 1개 이상 포함하되 사진 길이가 짧게 찍는 방법
// 제품의 수 N은 6 이상 50,000 이하
// 제품의 가로 좌표 X는 1 이상 1,000,000,000 이하
// 제품의 ID는 1 이상 1,000,000,000  이하 <--- 제품의 수는 N개이지만 ID의 범위가 더 크다..
// 입력된 모든 종류의 제품이 최소한 1개 이상 포함되도록 사진을 찍을 때 최소 사진의 길이를 구하시오
// 1. 제품의 종류를 확인해야 함 -> 총 개수와 어떤 ID가 사용되었는지 확인 필요 -> 배열 사용? -> 너무 큼 -> ID를 재 할당
// 2. 최소한의 X 좌표를 구해야 한다. 제품의 종류가 모두 들어간 상태에서.. X 좌표 정렬 필요
#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

int N; // 제품의 수
struct st{
	int X, ID; // 위치, 아이디
};
struct st A[50010];

void InputData(){
	int i;
	scanf("%d", &N);
	for (i = 0; i<N; i++) scanf("%d %d", &A[i].X, &A[i].ID);
}

#define MAXHASH 50000
int check[50000 + 10] = { 0 };

// X 좌표 기준으로 오름차순 정렬을 위해
bool compare(st& a, st& b){
	return a.X < b.X;
}

int Solve(){
	int mLen = 1000000000;

	// 1. 제품의 총 수 및 id 확인
	// 범위가 너무 크므로 HASH를 이용하여 ID 재할당
	int maxCnt = 0;
	for (int i = 0; i<N; i++){
		int nid = A[i].ID % MAXHASH;
		for (int k = 0; k<MAXHASH; k++){
			if (check[nid] == 0){ // 할당 가능
				check[nid] = A[i].ID;
				A[i].ID = nid;
				maxCnt++;
				break;
			}
			else if (check[nid] == A[i].ID){ // ID 중복 - 이미 동일한 ID가 할당되어 있는 경우
				A[i].ID = nid;
				break;
			}

			nid = (nid + 1) % MAXHASH;
		}
	}

	// 2. sliding window를 통한 length 계산
	// 2.1. X 좌표를 기준으로 sorting
	sort(A, A + N, compare);

	// 정렬되었는지 확인 - Debug
	//for(int i=0; i<N; i++){
	//	cout << A[i].X << " " << A[i].ID << endl;
	//}

	// 2.2. 좌표 확인하면서 이동
	for (int i = 0; i<50010; i++) check[i] = 0; // check 배열 초기화

	int i = 0;
	int j = 0;
	int cnt = 0;
	while (true){ // sliding window
		// 1. i 이동
		while (i<N && cnt < maxCnt){
			if (check[A[i].ID] == 0) cnt++;
			check[A[i].ID]++;
			i++;
		}

		// 2. 종료 조건 확인
		if (cnt < maxCnt) break;

		// 3. j이동 필요한지 확인
		while (check[A[j].ID] > 1){
			check[A[j].ID]--;
			j++;
		}

		// 4. len 확인
		if (mLen > A[i - 1].X - A[j].X) mLen = A[i - 1].X - A[j].X;

		// 5. j 조절 및 slinding window 추가 확인
		check[A[j].ID]--;
		j++;
		cnt--;
	}

	return mLen;
}

int main(){
	int ans = -1;
	InputData();

	// ToDo
	ans = Solve();

	printf("%d\n", ans);
	return 0;
}
