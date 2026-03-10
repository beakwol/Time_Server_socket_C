/*
 * Time Server (TCP, Port 20000)
 * - 클라이언트 접속 기록
 * - 클라이언트 요청 시 현재 시간 전송
 *
 * 컴파일: gcc -o time_server server.c -lws2_32
 */

#include <winsock2.h>
#include <stdio.h>

#pragma comment(lib, "ws2_32.lib")

#define PORT 20000

int main(void)
{
    /* 1. Winsock 초기화 (WSAStartup) */

    /* 2. TCP 소켓 생성 (socket, AF_INET, SOCK_STREAM) */

    /* 3. 서버 주소 설정 후 bind (포트 20000, INADDR_ANY) */

    /* 4. listen */

    /* 5. while(1) accept 루프 */
    /*    - accept 로 클라이언트 연결 수락 */
    /*    - 클라이언트 접속 기록: IP, 포트 출력 */
    /*    - recv 로 클라이언트 요청 수신 */
    /*    - 현재 시간 구해서 (time, ctime 등) send 로 전송 */
    /*    - 클라이언트 소켓 closesocket */

    /* 6. listen 소켓 닫고 WSACleanup */

    return 0;
}
