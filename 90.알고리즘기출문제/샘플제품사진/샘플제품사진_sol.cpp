// ������ǰ����
// id�� 1 �̻� 1000000000 �����̹Ƿ� id �迭�� ����� ��� 4 X 1000000000�� 4G �ʿ� - �Ұ���
// ��ǰ�� ������ N�̱� ������ N����ŭ�� id �迭�� ���� new id�� �ο��ϴ� ����� ����� �� ����
// new id�� �迭�ϴ� ������� ������ ���� �ο� Ȥ�� HashTable�� ���� �ο��� �� ����

#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

int N; // ��ǰ ��
struct st{
	int X, ID; // ��ġ, ���̵�
};
struct st A[50010];

void Input_Data(){
	int i;
	scanf("%d", &N);
	for (i = 0; i < N; i++){
		scanf("%d %d", &A[i].X, &A[i].ID);
	}
}

int check[50010];
//int nid[50010];
int max_id_cnt; // id �� ����
void new_id(){
	for (int i = 0; i < N; i++){
		int ni = A[i].ID % 50000;
		for (int j = 0; j < 50000; j++){
			if (check[ni] == 0){
				max_id_cnt++;
				check[ni] = A[i].ID;
				A[i].ID = ni;
				break;
			}
			else if (check[ni] == A[i].ID){
				A[i].ID = ni;
				break;
			}
			ni = (ni + 1) % 50000;
		}
	}
}

// ��ġ X �������� �����ϱ� ���� compare �Լ�
bool compare(st& a, st& b){
	return a.X < b.X;
}

// sliding window ����� ���� �ذ�
int solve(){
	int i, j, cnt = 0;
	int min = 1 << 30;

	/// new id �ο�
	new_id();

	// X ��ǥ �������� sort
	sort(A, A + N, compare);

	// check �迭 �ʱ�ȭ - 50000������ nid - check  �迭 �����̹Ƿ�
	for (int i = 0; i < 50000; i++) check[i] = 0;
	 i = j = 0;
	 for (;;){
		 while ((i < N) && (max_id_cnt > cnt)){ // i�� N���� �۰� ���� ���� �ٸ� ��ǰ�� ��� ã�� ������ i�� ++
			 if (check[A[i].ID]++ == 0) cnt++; // cnt�� ���� �ٸ� ��ǰ�� ������ ã�� ��츸 ++
			 i++;
		 }
		 if (max_id_cnt != cnt) break; // ���� ����
		 while (check[A[j].ID] > 1){ // j���� i���� ��ǰ�� �� j�� ��ǰ ������ 1�� �̻��� ��� �ּ� ���� ���̹Ƿ� ����
			 check[A[j].ID]--;
			 j++;
		 }
		 if (min > A[i - 1].X - A[j].X) min = A[i - 1].X - A[j].X;
		 cnt--;
		 check[A[j].ID]=0;
		 j++;
	 }
	 return min;
}

int main(){
	int ans = -1;
	Input_Data();

	// ToDo
	ans = solve();

	printf("%d\n", ans);
	return 0;
}