// 심리학실험
// 후보자 수 N과 후보자의 기질 값 Ai가 주어질 때, 기질 값 합이 0에 가장 가까운 두 후보자를 찾아서 번호를 출력하시오
// 입력은 기질값 오름차순으로 주어지며, 0에 가장 가까운 조합이 여러 개 나올 경우 먼저 입력된 사람을 선발할 것이다.

// 이중 for문으로 하나씩 전부 확인하는 경우 시간 복잡도 O(N^2)으로 인하여 Timeout발생 -> 시간 복잡도를 O(N)에 가깝게하는 알고리즘 확인 필요
#include<stdio.h>
#include<iostream>
using namespace std;

int N; // 후보자 수
int A[100000 + 10]; // 기질 값
int maxSum = 1000000000;

void InputData(){
	int i;
	scanf("%d", &N);
	for (i = 0; i < N; i++) scanf("%d", &A[i]);
}

int ABS(int num){
	return (num < 0) ? -num : num;
}

void Solve(){
	int num1 = N - 1;
	int num2 = N - 1; // 후보자

	int i = 0;
	int j = N - 1; // index
	int sum = 0;

	while (i < j){
		sum = A[i] + A[j];
		// sum값 갱신
		if (ABS(sum) < maxSum){
			num1 = i;
			num2 = j;
			maxSum = ABS(sum);
		}

		if (sum < 0) i++;
		else if (sum > 0) j--;
		else break; // 0이면 가장 작은 경우이므로
	}

	cout << num1 << " " << num2 << endl;
}

int main()
{
	InputData();

	// ToDo
	Solve();

	return 0;
}