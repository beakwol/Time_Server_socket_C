# GitHub에 올리는 방법

1. **GitHub에서 새 저장소 만들기**
   - https://github.com/new 접속
   - Repository name: `Time_Server_socket_C`
   - Public 선택 후 "Create repository" 클릭
   - **"Add a README" 등 추가 파일 생성하지 마세요** (이미 로컬에 있음)

2. **아래 명령어 실행** (YOUR_USERNAME을 본인 GitHub 아이디로 바꾸세요)

```powershell
cd "c:\Users\user\Desktop\codespace"
git remote add origin https://github.com/YOUR_USERNAME/Time_Server_socket_C.git
git branch -M main
git push -u origin main
```

GitHub가 기본 브랜치를 `main`으로 쓰므로 `git branch -M main`으로 이름을 맞춘 뒤 푸시하면 됩니다.
