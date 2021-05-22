// ������ǰ����
// N���� ��ǰ�� �Ϸķ� ��ġ�Ǿ� �ִµ�, ���� ������ ��ǰ�鵵 ���� �� ��� ������ ��ǰ�� �ּ��� 1�� �̻� �����ϵ� ���� ���̰� ª�� ��� ���
// ��ǰ�� �� N�� 6 �̻� 50,000 ����
// ��ǰ�� ���� ��ǥ X�� 1 �̻� 1,000,000,000 ����
// ��ǰ�� ID�� 1 �̻� 1,000,000,000  ���� <--- ��ǰ�� ���� N�������� ID�� ������ �� ũ��..
// �Էµ� ��� ������ ��ǰ�� �ּ��� 1�� �̻� ���Եǵ��� ������ ���� �� �ּ� ������ ���̸� ���Ͻÿ�
// 1. ��ǰ�� ������ Ȯ���ؾ� �� -> �� ������ � ID�� ���Ǿ����� Ȯ�� �ʿ� -> �迭 ���? -> �ʹ� ŭ -> ID�� �� �Ҵ�
// 2. �ּ����� X ��ǥ�� ���ؾ� �Ѵ�. ��ǰ�� ������ ��� �� ���¿���.. X ��ǥ ���� �ʿ�
#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

int N; // ��ǰ�� ��
struct st{
	int X, ID; // ��ġ, ���̵�
};
struct st A[50010];

void InputData(){
	int i;
	scanf("%d", &N);
	for (i = 0; i<N; i++) scanf("%d %d", &A[i].X, &A[i].ID);
}

#define MAXHASH 50000
int check[50000 + 10] = { 0 };

// X ��ǥ �������� �������� ������ ����
bool compare(st& a, st& b){
	return a.X < b.X;
}

int Solve(){
	int mLen = 1000000000;

	// 1. ��ǰ�� �� �� �� id Ȯ��
	// ������ �ʹ� ũ�Ƿ� HASH�� �̿��Ͽ� ID ���Ҵ�
	int maxCnt = 0;
	for (int i = 0; i<N; i++){
		int nid = A[i].ID % MAXHASH;
		for (int k = 0; k<MAXHASH; k++){
			if (check[nid] == 0){ // �Ҵ� ����
				check[nid] = A[i].ID;
				A[i].ID = nid;
				maxCnt++;
				break;
			}
			else if (check[nid] == A[i].ID){ // ID �ߺ� - �̹� ������ ID�� �Ҵ�Ǿ� �ִ� ���
				A[i].ID = nid;
				break;
			}

			nid = (nid + 1) % MAXHASH;
		}
	}

	// 2. sliding window�� ���� length ���
	// 2.1. X ��ǥ�� �������� sorting
	sort(A, A + N, compare);

	// ���ĵǾ����� Ȯ�� - Debug
	//for(int i=0; i<N; i++){
	//	cout << A[i].X << " " << A[i].ID << endl;
	//}

	// 2.2. ��ǥ Ȯ���ϸ鼭 �̵�
	for (int i = 0; i<50010; i++) check[i] = 0; // check �迭 �ʱ�ȭ

	int i = 0;
	int j = 0;
	int cnt = 0;
	while (true){ // sliding window
		// 1. i �̵�
		while (i<N && cnt < maxCnt){
			if (check[A[i].ID] == 0) cnt++;
			check[A[i].ID]++;
			i++;
		}

		// 2. ���� ���� Ȯ��
		if (cnt < maxCnt) break;

		// 3. j�̵� �ʿ����� Ȯ��
		while (check[A[j].ID] > 1){
			check[A[j].ID]--;
			j++;
		}

		// 4. len Ȯ��
		if (mLen > A[i - 1].X - A[j].X) mLen = A[i - 1].X - A[j].X;

		// 5. j ���� �� slinding window �߰� Ȯ��
		check[A[j].ID]--;
		j++;
		cnt--;
	}

	return mLen;
}

int main(){
	int ans = -1;
	InputData();

	// ToDo
	ans = Solve();

	printf("%d\n", ans);
	return 0;
}
