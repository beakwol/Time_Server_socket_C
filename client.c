/*
 * Time Client (TCP, Port 20000)
 * - 서버에 요청 후 시간 회신 받아 사용자에게 출력
 *
 * 컴파일: gcc -o time_client client.c -lws2_32
 * 사용: time_client [서버IP]  (생략 시 127.0.0.1)
 */

#include <winsock2.h>
#include <stdio.h>

#pragma comment(lib, "ws2_32.lib")

#define PORT 20000

int main(int argc, char *argv[])
{
    /* 서버 IP: argv[1] 있으면 사용, 없으면 "127.0.0.1" */

    /* 1. Winsock 초기화 (WSAStartup) */

    /* 2. TCP 소켓 생성 (socket, AF_INET, SOCK_STREAM) */

    /* 3. 서버 주소 설정 후 connect (서버 IP, 포트 20000) */

    /* 4. 시간 요청 전송 (send, 예: "TIME" 또는 아무 데이터) */

    /* 5. recv 로 시간 수신 후 사용자에게 출력 (printf) */

    /* 6. 소켓 닫고 WSACleanup */

    return 0;
}
