// 건물옥상정원
// 동쪽의 자기 건물 높이보다 낮은 건물의 옥상만 볼 수 있음
// 건물 높이가 같거나 높은 건물이 있으면 그 건물 옥상 뿐 아니라 그 뒤에 위치한 모든 건물 옥상은 볼 수 없음
// 건물 개수 N과 각 건물의 높이가 주어졌을 때, 각 건물에서 볼 수 있는 옥상의 총 합을 구하는 문제
// 인접한 노드의 확인이 중요하다는 점에서 stack 사용 필요
// 건물의 총 합이므로 long long을 사용
#include<iostream>
#include<stdio.h>
#include<stack>
using namespace std;

int N;	// 건물 수 - 80000 이하
int H[80010]; // 건물 높이

void InputData(){
	int i;
	scanf("%d", &N);
	for (i = 0; i < N; i++){
		scanf("%d", &H[i]);
	}
}

stack<int> s;
long long solve(){
	long long cnt = 0;

	// 건물 수만큼 확인
	for (int i = 0; i < N; i++){
		while (!s.empty()){
			int v = s.top();
			if (H[i] < v){ // 작으면
				cnt += s.size();
				break;
			}
			else{ // 크거나 같으면
				s.pop();
			}
		}
		s.push(H[i]);
	}

	return cnt;
}

int main(){
	long long ans = -1;
	InputData();

	ans = solve();
	printf("%lld", ans);
	return 0;
}