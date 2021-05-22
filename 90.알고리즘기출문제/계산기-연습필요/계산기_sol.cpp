// 계산기
// B 진법(2<=B<=36)의 수를 입력 받아 사칙 연산하는 계산기를 구현하는 문제
// 테스트 케이스는 총 N(N=자연수, 5<=N<=100), 이를 곱셈한 결과를 구해서 출력
// 인력 정수가 음수인 경우 '-' 기호가 정수 맨 앞에 붙는다. 연산 결과가 음수인 경우 '-'기호를 맨 앞에 붙여서 출력한다.
// 입력 정수가 B진법이면 연산 결과도 B 진법으로 출력한다.

#include<iostream>
using namespace std;

int N; // 테스트 케이스 수
int B; // 진법
char S[110]; // 첫 번째 정수
char D[110]; // 두 번째 정수

void InputData(){
	cin >> B >> S >> D;
}

char d2c[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
// char -> decimal로 변환하는 함수
int c2d(char ch){
	if (ch <= '9') return ch - '0';
	return ch - 'A' + 10;
}
int conv(int *dst, char *src){
	int i;
	for (i = 0; src[i]; i++) dst[i] = c2d(src[i]);
	return i;
}

void mulEx(char *s, char *d){
	int S[110], D[110], sol[210] = { 0 };
	int slen = conv(S, s);
	int dlen = conv(D, d);
	int len = slen + dlen;
	
	int i, j, k, kstart;
	for (i = dlen - 1, kstart = len - 1; i >= 0; i--, kstart--){
		for (j = slen - 1, k = kstart; j >= 0; j--, k--){
			sol[k] += S[j] * D[i];
		}
	}
	// 올림처리 -> 10진법일 경우 합이 10보다 크거나 같으면 올림 발생, 16진법일 경우는 합이 16보다 크거나 같으면 올림 발생!!
	for (i = len - 1; i > 0; i--){
		if (sol[i] >= 0){
			sol[i - 1] += sol[i] / B;
			sol[i] %= B;
		}
	}
	// 출력 처리 => 최대 길이 - 최소길이 = 1
	// {0} 요소 값이 0 일 수 있다
	// 불필요한 0은 출력하면 안되니 {0} 요소가 0이면 {1} 요소부터 출력한다
	for (i = sol[0] == 0; i < len; i++){
		printf("%c", d2c[sol[i]]);
	}
	printf("\n");
}

// 곱셈 처리 방식 수정
void mul(char *s, char *d){
	int S[110], D[110], sol[210] = { 0 };
	int slen = conv(S, s); // char -> int로 변환
	int dlen = conv(D, d); 
	int len = slen + dlen;

	// 곱셈 처리
	for (int i = 0; i < slen; i++){
		for (int j = 0; j < dlen; j++){
			sol[i + j + 1] += S[i] * D[j];
		}
	}

	for (int i = len - 1; i>0; i--){
		if (sol[i] >= 0){
			sol[i - 1] += sol[i] / B;
			sol[i] = sol[i] % B;
		}
	}

	// {0} 요소 값이 0 일 수 있다
	// 불필요한 0은 출력하면 안되니 {0} 요소가 0이면 {1} 요소부터 출력한다
	for (int i = sol[0] == 0; i < len; i++){
		printf("%c", d2c[sol[i]]);
	}
	printf("\n");
}

void solve(){
	// 0이 있는지 확인 및 처리 - 0이 있으면 결과는 항상 0이므로
	if ((S[0] == '0') || (D[0] == '0')){
		printf("0\n");
		return;
	}

	int sign = 1;
	char *s = S; // 검색을 위해 포인터 변수 사용
	char *d = D;

	// 음수가 있는지 확인하여 부호 결정
	if (S[0] == '-'){
		sign *= -1;
		s++;
	}
	if (D[0] == '-'){
		sign *= -1;
		d++;
	}
	if (sign < 0) printf("-");

	mul(s, d); // 곱셈 수행
}

int main(){
	int i;
	scanf("%d", &N);
	for (i = 0; i < N; i++){
		InputData();
		
		// ToDo
		solve();
	}
	return 0;
}