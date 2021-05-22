// ����
// B ����(2<=B<=36)�� ���� �Է� �޾� ��Ģ �����ϴ� ���⸦ �����ϴ� ����
// �׽�Ʈ ���̽��� �� N(N=�ڿ���, 5<=N<=100), �̸� ������ ����� ���ؼ� ���
// �η� ������ ������ ��� '-' ��ȣ�� ���� �� �տ� �ٴ´�. ���� ����� ������ ��� '-'��ȣ�� �� �տ� �ٿ��� ����Ѵ�.
// �Է� ������ B�����̸� ���� ����� B �������� ����Ѵ�.

#include<iostream>
using namespace std;

int N; // �׽�Ʈ ���̽� ��
int B; // ����
char S[110]; // ù ��° ����
char D[110]; // �� ��° ����

void InputData(){
	cin >> B >> S >> D;
}

char d2c[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
// char -> decimal�� ��ȯ�ϴ� �Լ�
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
	// �ø�ó�� -> 10������ ��� ���� 10���� ũ�ų� ������ �ø� �߻�, 16������ ���� ���� 16���� ũ�ų� ������ �ø� �߻�!!
	for (i = len - 1; i > 0; i--){
		if (sol[i] >= 0){
			sol[i - 1] += sol[i] / B;
			sol[i] %= B;
		}
	}
	// ��� ó�� => �ִ� ���� - �ּұ��� = 1
	// {0} ��� ���� 0 �� �� �ִ�
	// ���ʿ��� 0�� ����ϸ� �ȵǴ� {0} ��Ұ� 0�̸� {1} ��Һ��� ����Ѵ�
	for (i = sol[0] == 0; i < len; i++){
		printf("%c", d2c[sol[i]]);
	}
	printf("\n");
}

// ���� ó�� ��� ����
void mul(char *s, char *d){
	int S[110], D[110], sol[210] = { 0 };
	int slen = conv(S, s); // char -> int�� ��ȯ
	int dlen = conv(D, d); 
	int len = slen + dlen;

	// ���� ó��
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

	// {0} ��� ���� 0 �� �� �ִ�
	// ���ʿ��� 0�� ����ϸ� �ȵǴ� {0} ��Ұ� 0�̸� {1} ��Һ��� ����Ѵ�
	for (int i = sol[0] == 0; i < len; i++){
		printf("%c", d2c[sol[i]]);
	}
	printf("\n");
}

void solve(){
	// 0�� �ִ��� Ȯ�� �� ó�� - 0�� ������ ����� �׻� 0�̹Ƿ�
	if ((S[0] == '0') || (D[0] == '0')){
		printf("0\n");
		return;
	}

	int sign = 1;
	char *s = S; // �˻��� ���� ������ ���� ���
	char *d = D;

	// ������ �ִ��� Ȯ���Ͽ� ��ȣ ����
	if (S[0] == '-'){
		sign *= -1;
		s++;
	}
	if (D[0] == '-'){
		sign *= -1;
		d++;
	}
	if (sign < 0) printf("-");

	mul(s, d); // ���� ����
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