// ���÷��� ����
// ������ �� N, �ݻ� ���� R, ���� ���� P
// ���÷��̿� �ݵ�� �ϳ� �̻��� ���ʹ� �����Ǿ� �Ѵ�.
// ������ ���ü��� �β��� ���� �����ؾ� �� ������ �ִ� ������ ���ϴ� ���� -> �� ���� �����ؾ� �ϴ����� ������ �� �ִ�. -> ���չ���
// �ݻ� ������ ���� ������ ���� 0�� ���� ����� �� �ְ��� ������ ����.
#include<iostream>
using namespace std;

int N; // ������ ��
int R[11]; // �ݻ��� ����
int P[11]; // ������ ����

long long sum = 1000000000;
int minCnt = 100;

long long ABS(long long num){
	return (num < 0) ? -num : num;
}

void InputData(){
	cin >> N;
	for (int i = 1; i <= N; i++){
		cin >> R[i] >> P[i];
	}
}

// print depth
int dpArr[11] = { 0 };
void printDepth(int* arr, int len){
	for (int i = 0; i < len; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}

void DFS(int cnt, long long r, long long p, int idx){
	// check - ������ ���� �ݻ� ������ ���� ������ ���� Ȯ��
	if (cnt != 0){ 
		if (sum > ABS(r - p)){ 
			sum = ABS(r - p);
			minCnt = cnt;
		}
		else if (sum == ABS(r - p)){ // ���� ���� cnt�� ���� ���� �����Ѵ�
			if (cnt < minCnt) minCnt = cnt;
		}
	}

	// printDepth
	// if (idx == N+1) printDepth(dpArr, cnt);

	// DFS ����
	for (int i = idx; i <= N; i++){
		// dpArr[cnt] = i;
		DFS(cnt + 1, r * R[i], p + P[i], i + 1);
	}

}

// ����Ʈ�� �������� �ذ�
void DFS_BT(int cnt, long long r, long long p, int idx){
	// check - ������ ���� �ݻ� ������ ���� ������ ���� Ȯ��
	if (cnt != 0){
		if (sum > ABS(r - p)){
			sum = ABS(r - p);
			minCnt = cnt;
		}
		else if (sum == ABS(r - p)){ // ���� ���� cnt�� ���� ���� �����Ѵ�
			if (cnt < minCnt) minCnt = cnt;
		}
	}

	// DFS ���� - ����Ʈ������
	if (idx <= N){
		DFS(cnt + 1, r * R[idx], p + P[idx], idx + 1);
		DFS(cnt, r, p, idx + 1);
	}
}

int main(){

	int ans = -1;
	InputData(); // �Է�

	// ToDo
	//DFS(0, 1, 0, 1);
	DFS_BT(0, 1, 0, 1);
	ans = N - minCnt;

	printf("%d\n", ans); // ���
	return 0;
}