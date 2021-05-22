// 모든 직원이 동시에 출발하고 출발 위치는 직원마다 다르며, 산택 속도는 직원 별로 같거나 다를 수 있다.
// 산책은 총 T 분 동안 진행되는데 산책로가 좁기 떄문에 다른 사람을 추월할 수 없어서 그룹이 형성된다.

// 값 범위
// 1. 직원 수 N은 100,000 이하
// 2. 산책 시간 T는 1 이상 1,000,000,000 분 이하
// 3. 직원 i번의 출발 위치 Pi는 0 이상 1,000,000,000 이하
// 4. 직원 i번의 산책 속도 Si는 0 이상 1,000,000,000 이하

// 직원 수 N과 산책 시간 T, 그리고 각 직원의 출발 위치와 속도가 주어졌을 때, T 분 후에 형성되는 그룹의 수를 계산하시오
// 정방향으로 확인하는 경우? 이전 데이터들을 다시 확인해야 하므로 O(N^2)의 시간 복잡도가 소요됨 - 부적합
// 시작 위치가 오름 차순으로 정렬되어 있으므로 역뱡향으로 확인하면 O(N)의 시간 복잡도로 해결 가능하다
// 추가로 정방향으로 확인하고 싶다면? 그룹 개수를 구하는 문제이기 때문에 stack을 이용하면 쉽게 해결 가능하다. -> 작은 값이 오는 경우 pop

// 주의할 점이 최종 위치는 출발위치 + 속도 * 시간이므로  type casting이 필요하다!! int를 넘는 범위가 필요하므로 long long 사용 필요!!
// 혹시라도 printf에서 long long을 출력하고 싶은 경우는 %lld로 사용 가능,  cout은 그냥 사용 가능

#include<iostream>
#include<stdio.h>
using namespace std;

int N; // 직원 수
int T;  // 산책 시간
int P[100000 + 10]; // 직원 출발 위치
int S[100000 + 10]; // 직원 산책 속도(분당)

long long F[100000 + 10]; // 최종 위치

void inputData(){
	int i;
	scanf("%d %d", &N, &T);
	for (i = 0; i < N; i++){
		scanf("%d %d", &P[i], &S[i]);
	}
}

int solve(){
	int group_id = 0;

	F[N - 1] = P[N - 1] + T * (long long)S[N - 1];
	for (int i = N - 2; i >= 0; i--){
		F[i] = P[i] + T * (long long)S[i];
		if (F[i] > F[i + 1]) F[i] = F[i + 1];
	}

	// check group id
	long long num = 0;
	for (int i = N - 1; i >= 0; i--){
		if (num != F[i]){
			num = F[i];
			group_id++;
		}
	}

	return group_id;
}

int main(){
	int ans = -1;
	inputData();

	// ToDo
	ans = solve();

	printf("%d\n", ans);
}