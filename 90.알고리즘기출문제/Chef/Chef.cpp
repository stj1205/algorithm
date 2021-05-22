// Chef
// 예약 확정 시간을 조정하여 얻을 수 있는 최대 수익을 구하는 문제
// 금액이 높은 걸 우선으로 하므로 금액 기준으로 정렬 후 예약 가능한 시간에 예약을 하는 형태로 설정

#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

int N; // 손님 수
int P[10000 + 10]; // 음식 값
int T[10000 + 10]; // 예약 희망 시간

int sIndex[10000 + 10]; // 음식값 내림차순 기준의 정렬 Index
int sol[10000 + 10]; // 예약 확정 시간 별 음식 값

void inputData(){
	int i;
	scanf("%d", &N);
	for (i = 0; i < N; i++){
		scanf("%d %d", &P[i], &T[i]);
	}
}

bool compare(int& a, int& b){
	return P[a] > P[b];
}

int solve(){
	// init sIndex
	for (int i = 0; i < N; i++) sIndex[i] = i;

	// 음식값 내림차순 기준으로 sIndex 정렬
	sort(sIndex, sIndex + N, compare);
	//for (int i = 0; i < N; i++) cout << P[sIndex[i]] << endl;

	for (int i = 0; i < N; i++){
		int rt = T[sIndex[i]]; // 예약 확정 시간
		while (rt != 0){
			if (sol[rt] == 0) { // 비어 있으면 음식값 설정
				sol[rt] = P[sIndex[i]];
				break;
			}
			else{
				rt--; // 비어 있지 않은 경우 예약 시간 조정(-1)
			}
		}
	}

	// 예약 시간 index 기준으로 저장하고 있으므로
	int sum = 0;
	for (int i = 1; i <= 10000; i++){
		sum += sol[i];
	}

	return sum;

}

int main(){
	int ans = -1;
	inputData();

	// ToDo
	ans = solve();
	cout << ans << endl;

	return 0;
}
