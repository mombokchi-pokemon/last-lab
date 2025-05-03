#include <stdio.h>
#include <windows.h>
#include <string.h>

typedef struct {
    int x, y;            // 위치
    int w, h;            // 너비, 높이
    char* title;         // 제목
    char* msg;           // 메시지
} Box;

// 커서 이동 함수
void gotoxy(int x, int y) {
    COORD pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

// 박스 출력 함수 (모서리를 |로 표시)
void drawBox(Box b) {
    // 윗줄
    gotoxy(b.x, b.y);
    printf("|");
    for (int i = 0; i < b.w; i++) printf("-");
    printf("|");

    // 제목줄
    gotoxy(b.x, b.y + 1);
    printf("|");
    int pad = (b.w - strlen(b.title)) / 2;
    for (int i = 0; i < pad; i++) printf(" ");
    printf("%s", b.title);
    for (int i = 0; i < b.w - pad - strlen(b.title); i++) printf(" ");
    printf("|");

    // 구분선
    gotoxy(b.x, b.y + 2);
    printf("|");
    for (int i = 0; i < b.w; i++) printf("-");
    printf("|");

    // 안쪽 공간
    for (int i = 0; i < b.h; i++) {
        gotoxy(b.x, b.y + 3 + i);
        printf("|");
        if (i == b.h / 2) {
            int msg_pad = (b.w - strlen(b.msg)) / 2;
            for (int j = 0; j < msg_pad; j++) printf(" ");
            printf("%s", b.msg);
            for (int j = 0; j < b.w - msg_pad - strlen(b.msg); j++) printf(" ");
        }
        else {
            for (int j = 0; j < b.w; j++) printf(" ");
        }
        printf("|");
    }

    // 아랫줄
    gotoxy(b.x, b.y + 3 + b.h);
    printf("|");
    for (int i = 0; i < b.w; i++) printf("-");
    printf("|");
}

void fill_console_background(int color_code) {
    printf("\033[%dm", color_code); // ANSI 배경색 설정

    for (int i = 0; i < 60; i++) {
        for (int j = 0; j < 200; j++) {
            printf(" ");
        }
        printf("\n");
    }

    printf("\033[0m"); // 색 초기화
}

int main() {
    system("cls");  // 화면 지우기

    fill_console_background(42);

    printf("\033[41m");
    Box box1 = { 10, 3, 20, 7, "안녕하십니까", "교수님" };
    drawBox(box1);

    gotoxy(0, 20);
    printf("\033[43m");
    Box box2 = { 15, 5, 20, 7, "배고프다", "뭐먹지" };
    drawBox(box2);

    gotoxy(0, 20);
    printf("\033[0m"); // 색 초기화
    return 0;
}