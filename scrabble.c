#include "util/print_board.h"
#include "util/scrabble.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 15
#define M 100

void declare_matrix(char m[N][N]) {
    for (int i = 0; i < 15; i++) {
        for( int j = 0; j < 15; j++) {
            m[i][j] = 46;
        }
    }
}


int len_int(int n) {
    if(n == 0)
        return 1;
    int j = 0;
    while(n != 0) {
        j++;
        n = n/10;
    }
    return j;
}
int len_before_word(int n, int m, int a) {
    
    return n + m + a + 3;
}

void task1_matrix(char m[N][N], int n, char word[NUM_WORDS][NUM_WORDS]) {
    for (int i = 0; i < n; i++) {
        char str[M];
        
        fgets(str, M, stdin);
        int len = strlen(str);
        int yi = atoi(str); 
        int xi = atoi(strchr(str,' '));
        char Di =str[len_int(xi)+len_int(yi)+2];
        int len_w = len_before_word(len_int(xi),len_int(yi), 1);
        if(Di == '0') {
            for(int j = 0; j < len - len_w -1; j++) {
                m[yi][j + xi] = str[j+ len_w];
                word[i][j] = str[j + len_w];
            }
        }
        else {
            for(int j = 0; j < len - len_w - 1 ; j++) {
                m[j+ yi][xi] =  str[j + len_w];
                word[i][j] = str[j + len_w];
            }
        }
    }

}

void calculate_points( int n, int a[M]) {
    int v[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    int player1 = 0, player2 = 0;
    for(int i = 0; i < n; i++) {
        char str[M];
        fgets(str, M, stdin);
        int len = strlen(str);
        int yi = atoi(str); 
        int xi = atoi(strchr(str,' '));
        int len_w = len_before_word(len_int(xi),len_int(yi), 1);
        for(int j = 0; j < len - len_w - 1;j++) {
            if(i % 2 == 0) {
                player1 = player1 + v[str[len_w + j] - 'A'];
            }
            else player2 = player2 + v[str[len_w + j] - 'A'];
        }
    }
    a[0] = player1;
    a[1] = player2;
}

int check_for_bonus1(char s[M], char XX[M]) {
    int len = strlen(s);
    for(int i = 0; i < len - 1; i++) {
        int j = 0;
        if(s[i] == XX[j]) {
            j++;
            if(s[i + 1] == XX[j]) {
                return 1;
            }
        }
    }
    return 0;
}

int check_for_bonus2( char s[M], char YY[M]) {
    if(strstr(s, YY) != NULL) {
        return 1;
    }
    return 0;
}

  int calculate_player_points(char str[M], int len_w) {
    int v[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    int player = 0;
    int len  = strlen(str);
        for(int j = 0; j < len - len_w - 1; j++) {    
              player = player + v[str[len_w + j] - 'A'];
            }
    return player;
}

int power (int n, int a) {
    if ( a == 1)
    return n;
    int x = n;
    for( int i = 1; i < a; i++) {
        x = x*n;
    }
    return x;
}


void calculate_bonus( int n, char XX[M], char YY[M],int a[M], char m[N][N],char word[NUM_WORDS][NUM_WORDS] ) {
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; i++) {
        char str[M];
        fgets(str, M, stdin);
        int board_bonus1 = 0, board_bonus2 = 0;
        int bonus1 = check_for_bonus1(str, XX);
        int bonus2 = check_for_bonus2(str, YY);
        int len = strlen(str);
        int yi = atoi(str); 
        int xi = atoi(strchr(str,' '));
        char Di =str[len_int(xi)+len_int(yi)+2];
        int len_w = len_before_word(len_int(xi),len_int(yi), 1);
        int k = 0, p = 0;
        if(Di == '0') {  
            for(int j = 0; j < len - len_w -1; j++) {
                if(bonus_board[yi][j + xi] == 1) {
                    board_bonus1 = 1;
                    k++;
                } 
                if(bonus_board[yi][j + xi] == 2 ) {
                    board_bonus2 = 1;
                   p++;
                }
                m[yi][j + xi] = str[j+ len_w];
                word[i][j] = str[j + len_w];
            }
        }
        else {
            for(int j = 0; j < len - len_w - 1 ; j++) {
                if(bonus_board[j+ yi][xi] == 1 ) {
                    board_bonus1 = 1;
                    k++;
                }
                if(bonus_board[j+ yi][xi] == 2 ) {
                    board_bonus2 = 1; 
                    p++;
            }
                m[j+ yi][xi] =  str[j + len_w];
                word[i][j] = str[j + len_w];
            }
        }
            if(i % 2 == 0) {
                if (board_bonus1 == 1 && board_bonus2 == 1 && bonus1 == 1 && bonus2 == 1)
                    sum1 = sum1 + power(3,p)*power(2,k)*calculate_player_points(str, len_w);
                else if(board_bonus1 == 1 && bonus1 == 1){
                        sum1 = sum1 + power(2,k)*calculate_player_points(str, len_w);
                }
                else if(board_bonus2 == 1 && bonus2 == 1) { 
                    sum1 = sum1 + power(3,p)*calculate_player_points(str, len_w);
                }
                else
                    sum1 = sum1 + calculate_player_points(str, len_w);
            
            }
            else {
                if(board_bonus1 == 1 && board_bonus2 == 1 && bonus1 == 1 && bonus2 == 1)
                    sum2 = sum2 + power(3,p)*power(2,k)*calculate_player_points(str, len_w);
                else if(board_bonus1 == 1 && bonus1 == 1) {
                    sum2 = sum2 + power(2,k)*calculate_player_points(str, len_w);
                }
                else if(board_bonus2 == 1 && bonus2 == 1) {
                    sum2 = sum2 + power(3,p)*calculate_player_points(str, len_w);
                }
                else
                    sum2 = sum2 + calculate_player_points(str, len_w);
            
                }
    

    }
    a[0] = sum1;
    a[1] = sum2;   
}


int look_for_bonuses1( int xi, int yi, char word[NUM_WORDS], char XX[M], char YY[M]) {
    int bonus1 = check_for_bonus1(word, XX);
    int bonus2 = check_for_bonus2(word, YY);
    int len = strlen(word);
    int sum = 0;
    int k = 0, p = 0, board_bonus1 = 0, board_bonus2 = 0;
    for(int j = yi; j < yi + len -1; j++) {
                if(bonus_board[xi][j] == 1) {
                    board_bonus1 = 1;
                    k++;
                } 
                if(bonus_board[xi][j] == 2 ) {
                    board_bonus2 = 1;
                   p++;
                }
            }
     if (board_bonus1 == 1 && board_bonus2 == 1 && bonus1 == 1 && bonus2 == 1)
                    sum = sum + power(3,p)*power(2,k)*calculate_player_points(word, 0);
                else if(board_bonus1 == 1 && bonus1 == 1){
                        sum = sum + power(2,k)*calculate_player_points(word, 0);
                }
                else if(board_bonus2 == 1 && bonus2 == 1) { 
                    sum = sum + power(3,p)*calculate_player_points(word, 0);
                }
                else
                    sum = sum + calculate_player_points(word, 0);
    return sum;
}


int look_for_bonuses2( int xi, int yi, char word[NUM_WORDS], char XX[M], char YY[M]) {
    int bonus1 = check_for_bonus1(word, XX);
    int bonus2 = check_for_bonus2(word, YY);
    int len = strlen(word);
    int sum = 0;
    int k = 0, p = 0, board_bonus1 = 0, board_bonus2 = 0;
    for(int j = xi; j < xi + len - 1; j++) {
                if(bonus_board[j][yi] == 1) {
                    board_bonus1 = 1;
                    k++;
                } 
                if(bonus_board[j][yi] == 2 ) {
                    board_bonus2 = 1;
                   p++;
                }
            }
     if (board_bonus1 == 1 && board_bonus2 == 1 && bonus1 == 1 && bonus2 == 1)
                    sum = sum + power(3,p)*power(2,k)*calculate_player_points(word, 0);
                else if(board_bonus1 == 1 && bonus1 == 1){
                        sum = sum + power(2,k)*calculate_player_points(word, 0);
                }
                else if(board_bonus2 == 1 && bonus2 == 1) { 
                    sum = sum + power(3,p)*calculate_player_points(word, 0);
                }
                else
                    sum = sum + calculate_player_points(word, 0);
    return sum;
}


void task4 (char game_board[N][N], int n, char board_words[NUM_WORDS][NUM_WORDS]) {
    task1_matrix(game_board, n, board_words);
    int p = 0;
    for( int i = 0; i < NUM_WORDS; i++) {
        for( int j = 0; j < N ; j++) {
                for (int k = 0; k < N; k++) {
                    int x = 0;
	                if(game_board[j][k] == words[i][0] && p == 0) {
                        for (int l = 0; l < n; l++) {
                            if(strcmp(words[i] , board_words[l]) == 0) {
                                x = 1;
                                break;
                            }     
                        }
                        if( x == 0) {
                            int len = strlen(words[i]);
                            int a = 0, b = 0;
                            if((k + len - 1) < N) {
                                for(int l = 1; l < len; l++) {
                                    if(game_board[j][k+l] == 46) 
                                        a = 1;
                                    else {
                                        a = 0;
                                        break;
                                    }
                                }
                            }
                            if(( j + len - 1) < N) {
                                for( int  l = 1; l < len; l++) {    
                                    if(game_board[j + l][k] == 46) 
                                        b = 1;
                                    else {
                                        b = 0;
                                        break;
                                    }
                                }
                            }        
                            

                                if (a == 1) {
                                    for( int l = 0; l < len; l++) {
                                        game_board[j][k + l] = words[i][l];
                                    }
                                    p = 1;
                                    break;
                                }
                                if( b == 1) {
                                    for( int l = 0; l < len; l++) {
                                        game_board[j + l][k] = words[i][l];
                                    }
                                    p = 1;
                                    break;
                                }
                            
                        
                        }
                    }
            
	            }

            }
        }
}

void task5 (int n, char XX[M], char YY[M],int a[M], char m[N][N],char word[NUM_WORDS][NUM_WORDS]) {
    int p = 0;
    a[2] = 0;
    a[3] = 0;
     for( int i = 0; i < NUM_WORDS; i++) {
        for( int j = 0; j < N ; j++) {
                for (int k = 0; k < N; k++) {
                    int x = 0;
	                if(m[j][k] == words[i][0] && p == 0) {
                        for (int l = 0; l < n; l++) {
                            if(strcmp(words[i] , word[l]) == 0) {
                                x = 1;
                                break;
                            }     
                        }
                        if( x == 0) {
                            int len = strlen(words[i]);
                            int c = 0, b = 0;
                            if((k + len - 1) < N) {
                                for(int l = 1; l < len; l++) {
                                    if(m[j][k+l] == 46) 
                                        c = 1;
                                    else {
                                        c = 0;
                                        break;
                                    }
                                }
                            }
                            if(( j + len - 1) < N) {
                                for( int  l = 1; l < len; l++) {    
                                    if(m[j + l][k] == 46) 
                                        b = 1;
                                    else {
                                        b = 0;
                                        break;
                                    }
                                }
                            }        
                                if (c == 1 && (a[1] + look_for_bonuses1(j,k,words[i],XX,YY)) >= a[0]) {
                                   
                                    if((a[1] + look_for_bonuses1(j,k,words[i],XX,YY)) > a[2]) {
                                        a[2] = a[1] + look_for_bonuses1(j,k,words[i],XX,YY);
                                        a[3] = i;
                                        a[4] = j;
                                        a[5] = k;
                                    }
                                }
                                if( b == 1 && (a[1] + look_for_bonuses2(j,k,words[i],XX,YY)) >= a[0]) {
                                    if((a[1] + look_for_bonuses2(j,k,words[i],XX,YY)) > a[2]) {
                                        a[2] = a[1] + look_for_bonuses2(j,k,words[i],XX,YY);
                                        a[3] = i;
                                        a[4] = j;
                                        a[5] = k;
                                    }
                                }
                        }
                    }
            
	            }

            }
        }
        int len = strlen(words[a[3]]);
        if( a[3] != 0) {
        if(look_for_bonuses1(a[4],a[5],words[a[3]],XX,YY) > look_for_bonuses2(a[4],a[5],words[a[3]],XX,YY)) {
            for (int i = 0; i < len; i++) {
                m[a[4]][a[5] + i] = words[a[3]][i];
            }
        }
        else {
            for (int i = 0; i < len; i++) {
                m[a[4] + i][a[5]] = words[a[3]][i];
            }
        }
        }
}


int main() {
    char n[M], XX[M], YY[M];
    int x;
    int k; 
    char task[M]; // index nr task
    char game_board[N][N];
    int a[M];
    char board_words[NUM_WORDS][NUM_WORDS];
    fgets(task, M, stdin);
    x = atoi(task);
    declare_matrix(game_board);
        if(x == 0){   // task 0
            print_board(game_board);
        }
        else if( x == 1) { // task 1
            fgets(n, M, stdin);
             k = atoi(n);
            task1_matrix(game_board, k, board_words);
            print_board(game_board);
        }
        else if( x == 2) { //task 2
            fgets(n, M, stdin);
             k = atoi(n);
            calculate_points(k, a);
            printf("Player 1: %d Points\n", a[0]);
            printf("Player 2: %d Points\n", a[1]);
        }
        else if( x == 3) { //task 3
            fgets(XX, M, stdin);
            fgets(YY, M, stdin);
            fgets(n, M, stdin);
            k = atoi(n);
            calculate_bonus(k, XX, YY, a, game_board, board_words);
            printf("Player 1: %d Points\n", a[0]);
            printf("Player 2: %d Points\n", a[1]);
        }
        else if (x == 4) {
            fgets(XX, M, stdin);
            fgets(YY, M, stdin);
            fgets(n, M, stdin);
            k = atoi(n);
            task4(game_board,k, board_words);
            print_board(game_board);
        }
        else if ( x == 5) {
            fgets(XX, M, stdin);
            fgets(YY, M, stdin);
            fgets(n, M, stdin);
            k =atoi(n);
            calculate_bonus(k, XX, YY, a, game_board,board_words);
            task5(k,XX,YY,a,game_board,board_words);
            if(a[3] != 0)
            print_board(game_board);
            else 
                printf("Fail!");
        }

    return 0;
}