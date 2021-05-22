#include <iostream>
using namespace std;
int N; //빌딩의 층수
void InputData(){
	cin >> N;
}

int isPossible(int num){
	while (num){
		if (num % 10 == 4) return 0; // 4가 있음
		num = num / 10;
	}
	return 1; // 4가 없음
}

// 아래와 같은 방법을 사용하는 경우 시간초과발생
int solve1(){
	int cnt = 0;
	for (int i = 1; i <= N; i++){
		if (isPossible(i)) cnt++; // 4 가 안들어가면 증가
	}
	return cnt;
}

// 4를 고려한 9진법을 이용 -> 4이하면 그대로, 4 이상이면 1 빼서 사용
int solve2(){
	int real = 0;
	int digit = 1;
	while (N){
		int num = N % 10;
		if (num > 4) num -= 1; // 4보다 크면 1씩 빠져야함
		real += num * digit;
		N = N / 10;
		digit *= 9;
	}
	return real;
}

int lookup[] = { 0, 1, 2, 3, 0, 4, 5, 6, 7, 8 };
int solve3(){
	int real = 0;
	int digit = 1;
	while (N){
		real += lookup[ N % 10] * digit;
		N = N / 10;
		digit *= 9;
	}
	return real;
}

int main(){
	int ans = -1;
	InputData();//입력받는 부분

	//여기서부터 작성
	// ans = solve1(); // 시간 초과 발생
	ans = solve3();

	cout << ans << endl;//출력하는 부분
	return 0;
}