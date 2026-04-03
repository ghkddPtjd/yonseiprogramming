#include <stdio.h>
#include <stdlib.h> //난수 생성
#include <time.h>

const char* get_rsp_str(int choice) {
    if (choice == 1) return "가위";
    else if (choice == 2) return "바위";
    else if (choice == 3) return "보";
    return "알 수 없음";
} // 숫자를 문자열로 변환 

int main() {
    srand((unsigned int)time(NULL));

    const char* names[8] = {"플레이어", "태헌", "청민", "우현", "준홍", "규은", "서연", "진성"};
    int bracket[8] = {0, 1, 2, 3, 4, 5, 6, 7};

    for (int i = 0; i < 8; i++) {
        int random_idx = rand() % 8;
        int temp = bracket[i];
        bracket[i] = bracket[random_idx];
        bracket[random_idx] = temp;
    } // 대진표 매번 랜덤으로 섞기
    printf("========================================\n");
    printf("가위바위보 토너먼트\n");
    printf("비길 경우 재경기\n");
    printf("========================================\n");
    printf("[대진표 ]\n");
    printf("8강\n");
    for (int i = 0; i < 8; i += 2) {
        printf("[%d] %s\nVS\n[%d] %s\n", i + 1, names[bracket[i]], i + 2, names[bracket[i+1]]);
    } //화면에 출력
    
    int player_pos = 0;
    for (int i = 0; i < 8; i++) {
        if (bracket[i] == 0) player_pos = i + 1;
    }
    printf("========================================\n");
    printf("당신은 [%d] %s입니다.\n\n", player_pos, names[0]);

    const char* round_names[3] = {"8강", "4강", "결승"}; //라운드 이름 지정
    int num_players = 8;

    for (int r = 0; r < 3; r++) { //각 라운드 반복문으로 진행
        int next_bracket[4]; 
        int next_idx = 0;

        for (int i = 0; i < num_players; i += 2) {
            int p1 = bracket[i];
            int p2 = bracket[i+1];

            //유저가 진행하는 경우
            if (p1 == 0 || p2 == 0) {
                int opponent = (p1 == 0) ? p2 : p1; 
                
                if (r < 2) printf("%s\n상대 : %s\n", round_names[r], names[opponent]);
                else printf("%s - 상대 : %s\n", round_names[r], names[opponent]);

                int win = 0;
                while (1) {
                    printf("1: 가위\n2: 바위\n3: 보\n선택 > ");
                    int p_choice = 0;
                    
                    if (scanf("%d", &p_choice) != 1) {
                        while(getchar() != '\n'); 
                        p_choice = 0;
                    }

                    if (p_choice < 1 || p_choice > 3) {
                        printf("1,2,3 중에서 입력하세요 >\n");
                        continue;
                    }

                    int c_choice = (rand() % 3) + 1;

                    printf("나: %s\n", get_rsp_str(p_choice));
                    printf("%s: %s\n", names[opponent], get_rsp_str(c_choice));

                    if (p_choice == c_choice) {
                        printf("=> 비겼습니다! 재경기!\n\n");
                    } else if ((p_choice == 1 && c_choice == 3) ||
                               (p_choice == 2 && c_choice == 1) ||
                               (p_choice == 3 && c_choice == 2)) {
                        printf("=> 이겼습니다!\n");
                        win = 1;
                        break;
                    } else {
                        printf("=> 졌습니다...\n");
                        win = 0;
                        break;
                    }
                }

                if (win == 1) {
                    next_bracket[next_idx++] = 0;
                    if (r == 0) printf("=> 4강 진출!\n\n");         // 8강 승리 시
                    else if (r == 1) printf("=> 결승 진출!\n\n");   // 4강 승리 시
                    else printf("축하합니다! 우승!\n");             // 결승 승리 시
                } else {
                    printf("아쉽습니다. 다음 기회에!\n");
                    return 0;
                }
            } 
            //npc? 컴퓨터들이 진행하는 경기
            else {
                int winner = -1;
                while (1) {
                    int npc1_choice = (rand() % 3) + 1;
                    int npc2_choice = (rand() % 3) + 1;
                    
                    if (npc1_choice == npc2_choice) continue; 
                    
                    if ((npc1_choice == 1 && npc2_choice == 3) ||
                        (npc1_choice == 2 && npc2_choice == 1) ||
                        (npc1_choice == 3 && npc2_choice == 2)) {
                        winner = p1; 
                        break;
                    } else {
                        winner = p2; 
                        break;
                    }
                }
                //다음 라운드 갱신
                next_bracket[next_idx++] = winner;
            }
        }

        for (int i = 0; i < next_idx; i++) {
            bracket[i] = next_bracket[i];
        }
        num_players /= 2; 
    }

    return 0;
}