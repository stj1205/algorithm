// 해커대회 - linked list를 사용하는 문제

#include<stdio.h>
#include<iostream>
using namespace std;

char str[100000 + 10]; // 초기 문자열
char cmd[500000 + 10]; // 명령어 문자열

char result[600000 + 10]; // 결과 저장 배열 - 배열로 옮겨서 출력

typedef struct NODE{
	char ch;
	NODE* prev;
	NODE* next;
};

NODE* head;
NODE* tail;
NODE* cur;

void left(){
	if (cur->prev != head) cur = cur->prev;
}

void right(){
	if (cur != tail) cur = cur->next;
}

void add(char ch){
	NODE* n = new NODE();
	n->ch = ch;
	n->prev = cur->prev;
	n->next = cur;
	cur->prev->next = n;
	cur->prev = n;
}

void del(){
	if (cur->prev != head){
		cur->prev = cur->prev->prev;
		delete cur->prev->next;
		cur->prev->next = cur;
	}
}

void solve(){

	// init
	head = new NODE();
	tail = new NODE();
	cur = tail;
	head->next = cur;
	cur->prev = head; // 꼭 연결까지 init 처리해줘야 함!!

	// 초기 문자열을  linked list로 변환
	for (int i = 0; str[i]; i++){
		add(str[i]);
	}

	// cmd 수행
	for (int i = 0; cmd[i]; i++){
		switch (cmd[i]){
		case 'L':
			left();
			break;
		case 'R':
			right();
			break;
		case 'B':
			del();
			break;
		default:
			add(cmd[i]);
			break;
		}
	}

	// print
	/*
	cur = head->next;
	while (cur != tail){
		cout << cur->ch;
		cur = cur->next;
	}*/
}

void InputData(){
	scanf("%s", str);
	scanf("%s", cmd);
}

void OutputData(){
	cur = head->next;
	for (int i = 0; cur != tail; i++, cur = cur->next){
		result[i] = cur->ch;
	}
	cout << result << endl;
}

int main(){

	InputData();

	// ToDo
	solve();

	OutputData();

	return 0;
}