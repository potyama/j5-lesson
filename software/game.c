#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int school_grade;
    int count_repeat_year;
    int turn;
} board;

typedef struct {
    int sum_dices;
    int diff_fail;
} dice;

int main(){
    board player = {1, 0, 1};
    printf("Your grade is %d,\nThe number of years of retention is %d,\nYour turn is %d.\n", player.school_grade, player.count_repeat_year, player.turn);
    printf("\n\n");

    dice first = {61, 1};
    //関数の判定で学年があがったとする。
    printf("Your test score was %d. Difference is %d points.\nCongratulations. You've been promoted.\n", first.sum_dices, first.diff_fail);

    printf("\n\n");
    player.school_grade++;
    player.turn++;
    printf("Your grade is %d,\nThe number of years of retention is %d,\nYour turn is %d.\n", player.school_grade, player.count_repeat_year, player.turn);
    printf("\n\n");

    first.sum_dices = 40;
    first.diff_fail = -20;
    //関数の判定で学年があがったとする。
    printf("Your test score was %d. Difference is %d points.\nOops. You repeated a school year...   Cheer up! Work harder next time.\n", first.sum_dices, first.diff_fail);
    printf("\n\n");

    player.count_repeat_year++;
    player.turn++;
    printf("Your grade is %d,\nThe number of years of retention is %d,\nYour turn is %d.\n", player.school_grade, player.count_repeat_year, player.turn);
}