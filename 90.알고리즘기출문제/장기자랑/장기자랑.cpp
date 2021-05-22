// Circular queue를 사용하는 문제

// Linear queue를 사용하는 경우 최악의 경우 크기가 N*M이 되므로 10,000 * 10,000 = 100,000,000
// 즉, 400MB 정도가  필요하므로 용량이 부족한 문제가 있습니다.

// Circular Queue
// 사용할 공간 + 1로 큐의 크기를 지정해준다. -> full 과 empty를 비교하기 위함
// WP == RP이면 empty
// WP = (WP + 1) % 큐의 크기
// RP = (RP + 1) % 큐의 크기
// (WP + 1) % 큐의 크기 == RP 이면 full

#include<iostream>
#include<stdio.h>
using namespace std;

int N; // 직원 수
int S; // 시작 직원 번호
int M; 

typedef struct CircularQueue{
	int wp;
	int rp;
	int maxSize; // 큐의 크기

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
			printf("저장공간이 비어 있습니다.");
			return -1;
		}
	}

	void pop(){
		if (!empty()) rp = (rp + 1) % maxSize;
		else{
			printf("저장공간이 비어 있습니다.");
		}
	}

	void push(int v){
		if (!full()){
			arr[wp] = v;
			wp = (wp + 1) % maxSize;
		}
		else{
			printf("저장공간이 가득차 있습니다.");
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

	// 시작 번호 설정
	for (int i = 0; i < S - 1; i++){
		int v = cq.front();
		cq.pop();
		cq.push(v);
	}
	//printf("%d\n", cq.front());

	// M씩 이동 및 장기자랑
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