// 샘플제품사진
// id가 1 이상 1000000000 이하이므로 id 배열을 만드는 경우 4 X 1000000000로 4G 필요 - 불가능
// 제품의 개수는 N이기 때문에 N개만큼의 id 배열을 통한 new id를 부여하는 방법을 사용할 수 있음
// new id를 배열하는 방법에는 정렬을 통한 부여 혹은 HashTable을 통해 부여할 수 있음

#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

int N; // 제품 수
struct st{
	int X, ID; // 위치, 아이디
};
struct st A[50010];

void Input_Data(){
	int i;
	scanf("%d", &N);
	for (i = 0; i < N; i++){
		scanf("%d %d", &A[i].X, &A[i].ID);
	}
}

int check[50010];
//int nid[50010];
int max_id_cnt; // id 총 개수
void new_id(){
	for (int i = 0; i < N; i++){
		int ni = A[i].ID % 50000;
		for (int j = 0; j < 50000; j++){
			if (check[ni] == 0){
				max_id_cnt++;
				check[ni] = A[i].ID;
				A[i].ID = ni;
				break;
			}
			else if (check[ni] == A[i].ID){
				A[i].ID = ni;
				break;
			}
			ni = (ni + 1) % 50000;
		}
	}
}

// 위치 X 기준으로 정렬하기 위한 compare 함수
bool compare(st& a, st& b){
	return a.X < b.X;
}

// sliding window 방식을 통한 해결
int solve(){
	int i, j, cnt = 0;
	int min = 1 << 30;

	/// new id 부여
	new_id();

	// X 좌표 기준으로 sort
	sort(A, A + N, compare);

	// check 배열 초기화 - 50000까지의 nid - check  배열 기준이므로
	for (int i = 0; i < 50000; i++) check[i] = 0;
	 i = j = 0;
	 for (;;){
		 while ((i < N) && (max_id_cnt > cnt)){ // i가 N보다 작고 아직 서로 다른 제품을 모두 찾을 때까지 i를 ++
			 if (check[A[i].ID]++ == 0) cnt++; // cnt는 서로 다른 제품의 개수를 찾는 경우만 ++
			 i++;
		 }
		 if (max_id_cnt != cnt) break; // 종료 조건
		 while (check[A[j].ID] > 1){ // j에서 i까지 제품들 중 j의 제품 개수가 1개 이상인 경우 최소 사진 길이므로 제거
			 check[A[j].ID]--;
			 j++;
		 }
		 if (min > A[i - 1].X - A[j].X) min = A[i - 1].X - A[j].X;
		 cnt--;
		 check[A[j].ID]=0;
		 j++;
	 }
	 return min;
}

int main(){
	int ans = -1;
	Input_Data();

	// ToDo
	ans = solve();

	printf("%d\n", ans);
	return 0;
}