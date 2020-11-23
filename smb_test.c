#include <stdio.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#pragma comment(lib, "ws2_32.lib")

int main(void) {

	SOCKET SMB_CONNECTION = INVALID_SOCKET;
	SMB_CONNECTION = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	struct sockaddr_in SMB_DEETS;

	SMB_DEETS.sin_family = AF_INET;
	SMB_DEETS.sin_addr.s_addr = inet_addr("127.0.0.1");
	SMB_DEETS.sin_port = htons(135);

	int result = connect(SMB_CONNECTION, (SOCKADDR *) &SMB_DEETS, sizeof(SMB_DEETS));
	if(result == SOCKET_ERROR) {
		printf("socket error");
		closesocket(SMB_CONNECTION);
	}

	closesocket(SMB_CONNECTION);

}