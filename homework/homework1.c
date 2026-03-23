#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 1, 2, 3 입력을 문자열로 변환해주는 함수입니다.
const char* get_rsp_str(int choice) {
    if (choice == 1) return "가위";
    if (choice == 2) return "바위";
    if (choice == 3) return "보";
    return "알 수 없음";
}

int main() {
    // 난수 생성을 위한 시드 설정
    srand(time(NULL));

    // 8명의 참가자 배열 선언
    const char* players[8] = {"플레이어", "철수", "영희", "민준", "지아", "현우", "수빈", "태양"};

    // 인터페이스 및 대진표 출력
    printf("가위바위보 토너먼트\n");
    printf("인터페이스\n");
    printf("[대진표 ]\n");
    printf("8강\n");
    printf("[1] %s\nVS\n[2] %s\n", players[0], players[1]);
    printf("[3] %s\nVS\n[4] %s\n", players[2], players[3]);
    printf("[5] %s\nVS\n[6] %s\n", players[4], players[5]);
    printf("[7] %s\nVS\n[8] %s\n", players[6], players[7]);
    printf("당신은 [1] 플레이어입니다.\n\n");

    int rounds = 3; // 8강, 4강, 결승 총 3라운드
    const char* round_names[3] = {"8강", "4강", "결승"};
    
    // 문서의 예시 출력에 맞춰 만나는 상대를 철수(인덱스 1), 민준(인덱스 3), 태양(인덱스 7)으로 고정했습니다. (추측입니다)
    int opponent_indices[3] = {1, 3, 7}; 

    // 토너먼트 라운드 반복
    for (int r = 0; r < rounds; r++) {
        const char* opponent = players[opponent_indices[r]];
        
        if (r == 0) {
            printf("%s\n상대 : %s\n", round_names[r], opponent);
        } else if (r == 1) {
            printf("%s\n상대 : %s\n", round_names[r], opponent);
        } else {
            printf("%s - 상대 : %s\n", round_names[r], opponent);
        }

        int p_choice = 0, c_choice = 0;
        int win = 0;

        // 승부가 날 때까지 반복 (재경기 처리)
        while (1) {
            printf("1: 가위\n2: 바위\n3: 보\n선택 > ");
            
            // 문자 입력 시 무한 루프 방지 및 예외 처리
            if (scanf("%d", &p_choice) != 1) {
                while(getchar() != '\n'); 
                p_choice = 0;
            }

            // 1, 2, 3 이외의 숫자 입력 처리
            if (p_choice < 1 || p_choice > 3) {
                printf("1,2,3 중에서 입력하세요 >");
                continue;
            }

            // 상대방의 선택 (1~3 랜덤)
            c_choice = (rand() % 3) + 1; 

            printf("나: %s\n", get_rsp_str(p_choice));
            printf("%s: %s\n", opponent, get_rsp_str(c_choice));

            // 승패 판별 로직
            if (p_choice == c_choice) {
                printf("=> 비겼습니다! 재경기!\n\n");
            } else if ((p_choice == 1 && c_choice == 3) ||
                       (p_choice == 2 && c_choice == 1) ||
                       (p_choice == 3 && c_choice == 2)) {
                printf("=> 이겼습니다!\n");
                win = 1;
                break; // 승리 시 루프 탈출
            } else {
                printf("=> 졌습니다...\n");
                win = 0;
                break; // 패배 시 루프 탈출
            }
        }

        // 라운드 종료 후 결과 처리
        if (win == 0) {
            printf("아쉽습니다. 다음 기회에!\n");
            return 0; // 패배 시 프로그램 즉시 종료
        } else {
            if (r == 0) {
                printf("=> 준결승 진출!\n\n"); // 예시 문서 5페이지 기반: 4강 생략하고 바로 결승으로 출력되는 부분 반영
            } else if (r == 1) {
                printf("=> 결승 진출!\n\n");
            } else if (r == 2) {
                printf("축하합니다! 우승!\n");
            }
        }
    }

    return 0;
}