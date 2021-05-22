// DFS - ���ϱ� ����
// ���� �˰����� Ȱ��
// ���� �� ã���� return�ϵ��� ����
// depth�� �̿����� ���� ������ idx�� N�� �Ѿ�� ������ ����
// check�� �κп��� sum�� ���� ���� Ȯ���Ͽ� return�ϸ�, DFS�� ���� ������ ������ �ٽ� �����ϴ� ���·� ����
#include <iostream>
using namespace std;

#define MAXN (20)
int N, K;//�ڿ��� ����, �����
int A[MAXN + 10];//�ڿ��� ��

char *msg[] = { "NO", "YES" };

void InputData(){
	cin >> N >> K;
	for (int i = 1; i <= N; i++){
		cin >> A[i];
	}
}

// depth ���� Ȯ��
int DFS(int idx, int sum){
	// check
	if (sum == K){ // sum�� K�� ������
		return 1;
	}
	
	// ���պ� Ȯ��
	for (int i = idx; i <= N; i++){
		int ret = DFS(i + 1, sum + A[i]);
		if (ret == 1) return 1;
	}

	return 0;
}

// debug�� ���� depth �߰��Ͽ�  � ���� ����ߴ��� ���� �� Ȯ��
int dpArr[MAXN + 10];
void printdpArr(int depth){
	for (int i = 1; i < depth; i++){
		cout << dpArr[i] << " ";
	}
	cout << endl;
}
int DFS2(int depth, int idx, int sum){
	// check
	if (sum == K){ // sum�� K�� ������
		printdpArr(depth);
		return 1;
	}

	// ���պ� Ȯ��
	for (int i = idx; i <= N; i++){
		dpArr[depth] = A[i];
		int ret = DFS2(depth+1, i + 1, sum + A[i]);
		if (ret == 1) return 1;
	}

	return 0;
}

int main(){
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++){
		InputData();//�Է�

		//���⼭���� �ۼ�
		//int ans = DFS(1, 0);
		int ans = DFS2(1, 1, 0);

		cout << msg[ans] << endl;//���
	}
	return 0;
}