#include <stdio.h>
#include <conio.h>

int main() {
    int pos = 5;  // 0의 초기 위치

    while (1) {
        system("cls");  // 화면을 지우고

        // 화면 출력
        for (int i = 0; i < 10; i++) {
            if (i == pos)
                putchar('0');  // pos 위치에 '0' 출력
            else
                putchar('-');  // 나머지에는 'ㅡ' 출력
        }       // i가 0부터 9까지 가는데 pos가 i와 같으면 0을 출력 아니면 -를 출력

        // 키 입력
        char key = _getch();
        if (key == 'a' && pos > 0) pos--;  // 왼쪽
        if (key == 'd' && pos < 9) pos++;  // 오른쪽
        if (key == 'q') break;  // 종료
    }

    return 0;
}