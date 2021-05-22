#include <iostream>
using namespace std;

typedef struct st
{
	int packet_no;
	int prior_level;
	struct st *next;
}PACKET;

PACKET buffer;
PACKET *last_packet;

void Input_Packet(PACKET& p)
{
	cin >> p.packet_no >> p.prior_level; // packet_no, prior_level 입력
}

#define SUCCESS				(0)
#define ERROR_PUT_PACKET	(-1)
#define ERROR_BUF_EMPTY		(-2)

int Put_Packet_to_Buffer(PACKET& p)
{
	PACKET *pac;

	pac = new PACKET();

	*pac = p;

	// p를 사용하면 loop상 오류 발생!! -> pac을 사용해야 한다.
	if (buffer.next == (PACKET*)0){ // 아무 정보가 없을 때
		last_packet->next = pac;
		last_packet = pac;
	}
	else{ // 비교하면서 값을 삽입
		PACKET* cur = &buffer;
		while (cur->next != NULL){
			if (pac->prior_level < cur->next->prior_level){
				pac->next = cur->next;
				cur->next = pac;
				break;
			}
			cur = cur->next;
		}

		// 가장 마지막에 오는 경우
		if (cur->next == NULL){
			cur->next = pac;
			last_packet = pac;
		}
	}

	return SUCCESS;
}
int Get_Packet_from_Buffer(PACKET& p)
{
	if (buffer.next == (PACKET*)0) return ERROR_BUF_EMPTY;
	p = *buffer.next;
	delete buffer.next;

	buffer.next = p.next;

	return SUCCESS;
}

int main(void)
{
	int N;
	PACKET packet;

	cin >> N;	// 패킷의 수 입력

	last_packet = &buffer;
	packet.next = NULL;
	// 패킷의 수신
	for (int i = 0; i < N; i++)
	{
		Input_Packet(packet);
		Put_Packet_to_Buffer(packet);
	}

	// 패킷 처리순서 출력
	while (Get_Packet_from_Buffer(packet) == SUCCESS)
	{
		cout << packet.packet_no << " ";
	}

	return 0;
}
