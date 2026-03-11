# Time_Server_socket_C

C 소켓 기반 시간 서버/클라이언트 (TCP, 포트 20000).

## 요구사항 정리

| 구분 | 항목 |
|------|------|
| 서버 | 포트 20000, TCP, 접속 기록, 요청 시 현재 시간 전송 |
| 클라이언트 | 시간 회신 받아 사용자에게 출력 |
| 빌드 | gcc |

## 빌드 (Windows, gcc)

```bash
# 서버
gcc -o time_server server.c -lws2_32

# 클라이언트
gcc -o time_client client.c -lws2_32
```

## 실행

```bash
# 1. 서버 실행 (포트 20000에서 대기)
time_server.exe

# 2. 다른 터미널에서 클라이언트 실행 (기본: 127.0.0.1)
time_client.exe
time_client.exe 192.168.0.10   # 원격 서버 IP 지정 시
```

## 코드 흐름

**서버 (`server.c`)**  
소켓 생성 → bind(20000) → listen → accept 루프 → 접속 시 IP/포트 기록 → recv 후 현재 시간을 send → 클라이언트 소켓 종료 후 대기 반복.

**클라이언트 (`client.c`)**  
소켓 생성 → connect(서버:20000) → "TIME" 전송 → recv로 시간 수신 → 화면에 출력 후 종료.
