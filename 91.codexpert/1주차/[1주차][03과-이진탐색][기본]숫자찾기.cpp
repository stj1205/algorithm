// ����Ž������
#include <iostream>
using namespace std;

int N;
int A[50000 + 10];
int T;
int B[10000 + 10];

void InputData(){
	cin >> N;
	for (int i = 0; i<N; i++){
		cin >> A[i];
	}
	cin >> T;
	for (int i = 0; i<T; i++){
		cin >> B[i];
	}
}
void OutputData(){
	for (int i = 0; i<T; i++){
		cout << B[i] << endl;
	}
}

int binearySearch(int target){
	int s = 0;
	int e = N - 1;
	while (s <= e){
		int mid = (s + e) / 2;
		if (target < A[mid]) e = mid - 1;
		else if (target > A[mid]) s = mid + 1;
		else{
			return mid;
		}
	}
	return -1;
}

// binearySearch �Լ�
// ���� ���� �ߺ��Ǵ� ��� ���� ó�� ������ ���� index�� ����
int bslow(int target){
	int s = 0;
	int e = N - 1;
	int sol = -1;
	while (s <= e){
		int mid = (s + e) / 2;
		if (target < A[mid]) e = mid - 1;
		else if (target > A[mid]) s = mid + 1;
		else{
			sol = mid;
			e = sol - 1;
		}
	}
	return sol;
}

int main(){
	InputData();// �Է¹޴� �κ�

	// ���⼭���� �ۼ�
	for (int i = 0; i < T; i++){
		int idx = binearySearch(B[i]);
		if (idx == -1) B[i] = 0; // ��ã���� 0
		else B[i] = idx + 1; // ã���� ã�� idx + 1
	}

	OutputData();// ����ϴ� �κ�
	return 0;
}