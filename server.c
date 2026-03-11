#include <winsock2.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

#define PORT 20000

int main(void)
{
    WSADATA wsa;
    SOCKET server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;

    //소켓 초기화
    WSAStartup(MAKEWORD(2, 2), &wsa);
    
    //소켓 생성
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    
    //서버 주소 설정
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
    
    //bind, listen
    bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr));
    listen(server_socket, 1);
    
    //클라 접속 대기 accept
    printf("서버실행, 클라이언트 접속대기\n");
    int addr_len = sizeof(client_addr);
    client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_len);
    
    //클라이언트 접속 기록
    printf("클라이언트 접속 IP: %s\n",inet_ntoa(client_addr.sin_addr));
    fflush(stdout);
    //클라이언트 요청 대기
    char recv_buff[256] = {0};
    recv(client_socket, recv_buff, sizeof(recv_buff), 0);
    
    //시간 부분
    time_t timer = time(NULL);
    char *time_str = ctime(&timer);
    int len = strlen(time_str);

    //시간 전송
    send(client_socket, time_str, len, 0);

    //소켓닫기
    closesocket(client_socket);
    closesocket(server_socket);
    WSACleanup();
    

    return 0;
}
