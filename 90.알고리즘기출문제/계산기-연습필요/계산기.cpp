// ���� ����
// B������ ���� �Է� �޾� ��Ģ �����ϴ� ���⸦ ���� ���̴�. �� �� ���� �κ��� �����ؾ� �Ѵ�.
// �׽�Ʈ ���̽��� �� N������, �� �׽�Ʈ ���̽��� 100 �ڸ� ������ B ���� ������ �� �� �Է� �޾�, �̸� ������ ����� ���ؼ� ����ؾ� �Ѵ�.
#include<iostream>
using namespace std;

int N; // �׽�Ʈ ���̽� ��
int B; // ����
char S[110]; // ù ��° ����
char D[110]; // �� ��° ����

// �߰�
char DtoC[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
// ���ڿ��� int �迭�� ��ȯ�ϰ� �� ���̸� �����ϴ� �Լ�
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
	int sol[110 + 110] = { 0, }; // �ʱ�ȭ �ʿ�

	int slen = CtoD(s, sint);
	int dlen = CtoD(d, dint);
	int tlen = slen + dlen;

	// ���� ����
	for (int i = slen-1; i >= 0; i--){
		for (int j = dlen-1; j >= 0; j--){
			sol[i + j + 1] += (sint[i] * dint[j]);
		}
	}

	// �����
	//cout << slen << " " << dlen << endl;
	//for (int i = 1; i < tlen; i++){
	//	cout << sol[i] << " ";
	//}
	//cout << endl;

	// ���� ó��
	for (int i = tlen - 1; i > 0; i--){
		sol[i - 1] += sol[i] / B;
		sol[i] = sol[i] % B; 
	}

	// ��� - ���� ó�� �ڸ��� 0���� �ƴ��� Ȯ���ϰ� ���
	int i = (sol[0] != 0) ? 0 : 1;
	for (i; i < tlen; i++){
		cout << DtoC[sol[i]];
	}
	cout << endl;
}

void Solve(){
	char *s = S;
	char *d = D;

	// 1. 0�� �ִ��� Ȯ��
	if (s[0] - '0' == 0 || d[0] - '0' == 0){
		cout << "0" << endl;
		return;
	}

	// 2. -  ��ȣ Ȯ��
	int sign = 1;
	if (s[0] == '-'){ sign *= -1; s++; }
	if (d[0] == '-'){ sign *= -1; d++; }
	if (sign < 0) cout << "-";

	// 3. ���� �����Ͽ� ���
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