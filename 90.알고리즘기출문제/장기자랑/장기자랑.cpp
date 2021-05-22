// Circular queue�� ����ϴ� ����

// Linear queue�� ����ϴ� ��� �־��� ��� ũ�Ⱑ N*M�� �ǹǷ� 10,000 * 10,000 = 100,000,000
// ��, 400MB ������  �ʿ��ϹǷ� �뷮�� ������ ������ �ֽ��ϴ�.

// Circular Queue
// ����� ���� + 1�� ť�� ũ�⸦ �������ش�. -> full �� empty�� ���ϱ� ����
// WP == RP�̸� empty
// WP = (WP + 1) % ť�� ũ��
// RP = (RP + 1) % ť�� ũ��
// (WP + 1) % ť�� ũ�� == RP �̸� full

#include<iostream>
#include<stdio.h>
using namespace std;

int N; // ���� ��
int S; // ���� ���� ��ȣ
int M; 

typedef struct CircularQueue{
	int wp;
	int rp;
	int maxSize; // ť�� ũ��

	int arr[10000 + 10];

	bool empty(){
		if (wp == rp) return true;
		else return false;
	}

	bool full(){
		if ((wp + 1) % maxSize == rp) return true; 
		else return false;
	}

	int front(){
		if (!empty()) return arr[rp];
		else{
			printf("��������� ��� �ֽ��ϴ�.");
			return -1;
		}
	}

	void pop(){
		if (!empty()) rp = (rp + 1) % maxSize;
		else{
			printf("��������� ��� �ֽ��ϴ�.");
		}
	}

	void push(int v){
		if (!full()){
			arr[wp] = v;
			wp = (wp + 1) % maxSize;
		}
		else{
			printf("��������� ������ �ֽ��ϴ�.");
		}
	}
};

CircularQueue cq;

void InputData(){
	scanf("%d %d %d", &N, &S, &M);
}

void solve(){
	// init
	cq.maxSize = N + 1;
	for (int i = 1; i <= N; i++){
		cq.push(i);
	}

	// ���� ��ȣ ����
	for (int i = 0; i < S - 1; i++){
		int v = cq.front();
		cq.pop();
		cq.push(v);
	}
	//printf("%d\n", cq.front());

	// M�� �̵� �� ����ڶ�
	int nod;
	while (!cq.empty()){
		for (int i = 0; i < M - 1; i++){
			nod = cq.front();
			cq.pop();
			cq.push(nod);
		}
		nod = cq.front();
		cq.pop();
		cout << nod << " ";
	}

}

int main(){
	InputData();

	// ToDo
	solve();

	return 0;
}