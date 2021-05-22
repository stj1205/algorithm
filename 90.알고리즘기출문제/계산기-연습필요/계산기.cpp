// 계산기 문제
// B진법의 수를 입력 받아 사칙 연산하는 계산기를 개발 중이다. 이 중 곱셈 부분을 구현해야 한다.
// 테스트 케이스는 총 N번으로, 각 테스트 케이스는 100 자리 이하의 B 진법 정수를 두 개 입력 받아, 이를 곱셈함 결과를 구해서 출력해야 한다.
#include<iostream>
using namespace std;

int N; // 테스트 케이스 수
int B; // 진법
char S[110]; // 첫 번째 정수
char D[110]; // 두 번째 정수

// 추가
char DtoC[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
// 문자열을 int 배열로 변환하고 그 길이를 리턴하는 함수
int CtoD(char *src, int* dest){
	int i;
	for (i = 0; src[i]; i++){
		if (src[i] <= '9') dest[i] = src[i] - '0';
		else dest[i] = src[i] - 'A' + 10;
	}
	return i;
}

void InputData(){
	scanf("%d %s %s", &B, S, D);
}

void mul(char* s, char* d){
	int sint[110];
	int dint[110];
	int sol[110 + 110] = { 0, }; // 초기화 필요

	int slen = CtoD(s, sint);
	int dlen = CtoD(d, dint);
	int tlen = slen + dlen;

	// 곱셈 수행
	for (int i = slen-1; i >= 0; i--){
		for (int j = dlen-1; j >= 0; j--){
			sol[i + j + 1] += (sint[i] * dint[j]);
		}
	}

	// 디버그
	//cout << slen << " " << dlen << endl;
	//for (int i = 1; i < tlen; i++){
	//	cout << sol[i] << " ";
	//}
	//cout << endl;

	// 진법 처리
	for (int i = tlen - 1; i > 0; i--){
		sol[i - 1] += sol[i] / B;
		sol[i] = sol[i] % B; 
	}

	// 출력 - 가장 처음 자리가 0인지 아닌지 확인하고 출력
	int i = (sol[0] != 0) ? 0 : 1;
	for (i; i < tlen; i++){
		cout << DtoC[sol[i]];
	}
	cout << endl;
}

void Solve(){
	char *s = S;
	char *d = D;

	// 1. 0이 있는지 확인
	if (s[0] - '0' == 0 || d[0] - '0' == 0){
		cout << "0" << endl;
		return;
	}

	// 2. -  부호 확인
	int sign = 1;
	if (s[0] == '-'){ sign *= -1; s++; }
	if (d[0] == '-'){ sign *= -1; d++; }
	if (sign < 0) cout << "-";

	// 3. 곱셈 수행하여 출력
	mul(s, d);
}

int main(){
	int i;
	scanf("%d", &N);
	for (i = 0; i < N; i++){
		InputData();
		//ToDo
		Solve();
	}

	return 0;
}