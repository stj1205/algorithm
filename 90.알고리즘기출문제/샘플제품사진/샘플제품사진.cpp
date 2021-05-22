#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

#define MAXHASH 50000

int N; // ��ǰ �� - 6�̻� 50000 ����
struct st{
	int X, ID; // ��ǥ ��ġ, ��ǰ ID
};
st A[50010];

// X ��ǥ �������� ����
bool compare(st& a, st& b){
	return a.X < b.X;
}

void InputData(){
	int i;
	scanf("%d", &N);
	for (i = 0; i < N; i++){
		scanf("%d %d", &A[i].X, &A[i].ID);
	}
}

// ��� ������ ��ǰ�� �ּ��� 1�� �̻� ���Եǵ��� ������ ���� �� �ּ� ���� ���̸� ���
// ID�� ũ�Ⱑ �ʹ� ũ�Ƿ� �뷮 ���ѿ� ���� ID size�� �迭�� ���� �� ����
// ��ǰ�� ���� 50000 �����̹Ƿ� ��ǰ�� ���� �°� ID ���Ҵ� �ʿ�
// hash�� ����  Ȯ�� �� ���� id �� new id ���� ���� �迭�� �ʿ��ϴ�. -> check �迭 ����
int check[50010];
int maxCnt = 0;
int solve(){
	
	// 1. id �� �Ҵ� - hash ���
	for (int i = 0; i < N; i++){
		int nid = A[i].ID % MAXHASH;
		for (int j = 0; j < MAXHASH; j++){
			if (check[nid] == 0){ // �Ҵ� ������ ���
				maxCnt++;
				check[nid] = A[i].ID;
				A[i].ID = nid;
				break;
			}
			else if (check[nid] == A[i].ID){ // �̹� �Ҵ�� ���
				A[i].ID = nid;
				break;
			}

			nid = (nid + 1) % MAXHASH;
		}
	}

	// 2. �ּ� ���� ����
	for (int i = 0; i < MAXHASH; i++) check[i] = 0; // check   �迭 �ʱ�ȭ
	// 2-1. X ��ǥ �������� ����
	sort(A, A + N, compare);
	// 2-2. �ּ� ���� ���� ���ϱ�
	int cnt = 0;
	int i = 0, j = 0;
	int m_cost = 1000000000;
	while (true){
		// 1) i�� ��ǥ ����
		while (i < N && cnt != maxCnt){
			if (check[A[i].ID] == 0) cnt++;
			check[A[i].ID]++;
			i++;
		}

		// 2) ���� ���� üũ
		if (cnt != maxCnt) break;

		// 3) j ��ǥ Ȯ�� - ���� ���� üũ
		while (check[A[j].ID] != 1){
			check[A[j].ID]--;
			j++;
		}

		// 4) min�� ���
		if (m_cost > A[i - 1].X - A[j].X) m_cost = A[i - 1].X - A[j].X;

		// 5. sliding window�� ���� j�� ����
		check[A[j].ID]--;
		j++;
		cnt--;
	}

	return m_cost;
}

int main(){
	int ans = -1;
	InputData();

	ans = solve();
	printf("%d\n", ans);
	return 0;
}