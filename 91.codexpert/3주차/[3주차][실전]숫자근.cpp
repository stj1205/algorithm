// ���ڱ�
// n���� ������ �ԷµǸ� ���ڱ��� ���� ū ���� ã�� ���α׷��� �ۼ��Ͻÿ�.
#include <iostream>
using namespace std;
#define MAXN ((int)1e3)
int N;//��������
int A[MAXN + 10];//�Է� ����
int sol[MAXN + 10]; // ���ڱ��� ������ �迭
void InputData(){
	cin >> N;
	for (int i = 0; i<N; i++){
		cin >> A[i];
	}
}

int getRoot(int v){
	int num = v;
	int root = 0;
	if (num < 10) root = num;
	else{
		while (true){
			while (num != 0){
				root += num % 10;
				num = num / 10;
			}
			if (root < 10) return root;
			else{
				num = root;
				root = 0;
			}
		}
	}
	return root;
}

int Solve(){
	// 1. ��� ���� ���ڱ��� ����
	for (int i = 0; i<N; i++){
		sol[i] = getRoot(A[i]);
	}

	// 2. ���� ū ���ڱ��� ������ �� ����
	// ��, ���� ū ���ڱ��� ���� ���̸� �� �� ���� ���� ���� ����Ѵ�.
	int maxv = 0;
	int maxIdx = 0;
	for (int i = 0; i<N; i++){
		if (maxv < sol[i]){
			maxv = sol[i];
			maxIdx = i;
		}
		else if (maxv == sol[i]){
			if (A[i] < A[maxIdx]) maxIdx = i;
		}
	}
	return A[maxIdx];
}

int main(){
	int ans = -1;
	InputData();//�Է� �޴� �κ�
	//���⼭���� �ۼ�
	ans = Solve();
	cout << ans << endl;//����ϴ� �κ�
	return 0;
}
