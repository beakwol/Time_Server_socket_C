#include <winsock2.h>
#include <stdio.h>
#include <string.h>

#define SERVER_IP "127.0.0.1" // 내 컴퓨터 안에서 테스트할 때 쓰는 주소 (루프백)
#define PORT 20000

int main(void)
{
    WSADATA wsa;
    SOCKET client_socket;
    struct sockaddr_in server_addr;

    //소켓 초기화
    WSAStartup(MAKEWORD(2, 2), &wsa);

    //소켓 생성
    client_socket = socket(AF_INET, SOCK_STREAM, 0);

    //접속할 서버 주소 설정
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP); // 문자열 IP를 네트워크용으로 변환
    server_addr.sin_port = htons(PORT);

    //서버에 연결 요청
    if (connect(client_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == SOCKET_ERROR) {
        printf("서버 연결 실패!\n");
        return 1;
    }
    printf("서버에 성공적으로 연결되었습니다.\n");

    char request_msg[] = "시간";

    send(client_socket, request_msg, strlen(request_msg), 0);

    char recv_time[256] = {0}; 

    recv(client_socket,recv_time,sizeof(recv_time),0);
    printf("현재시간: %s",recv_time);

    // 5. 소켓 닫고 마무리 (서버와 동일)
    closesocket(client_socket);
    WSACleanup();

    return 0;
}