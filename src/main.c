#include <stdio.h>

int main() {

    int score = 0;
    int answer;
    int i;
    char name[50];
    FILE *fp;

    printf("Welcome to the Harry Potter Trivia Quiz!\n");
    printf("Let's see how well you know the Wizarding World!\n\n");

    for(i = 1; i <= 7; i++) {

        if(i == 1) {
            printf("1) What is the name of Harry Potter's pet owl?\n");
            printf("1. Crookshanks\n");
            printf("2. Hedwig\n");
            printf("3. Scabbers\n");
            printf("Enter your choice: ");
            scanf("%d", &answer);

            if(answer == 2) score++;
            printf("\n");
        }

        if(i == 2) {
            printf("2) What house does Harry belong to?\n");
            printf("1. Slytherin\n");
            printf("2. Hufflepuff\n");
            printf("3. Gryffindor\n");
            printf("Enter your choice: ");
            scanf("%d", &answer);

            if(answer == 3) score++;
            printf("\n");
        }

        if(i == 3) {
            printf("3) Who is the headmaster of Hogwarts?\n");
            printf("1. Professor Snape\n");
            printf("2. Dumbledore\n");
            printf("3. McGonagall\n");
            printf("Enter your choice: ");
            scanf("%d", &answer);

            if(answer == 2) score++;
            printf("\n");
        }

        if(i == 4) {
            printf("4) What platform does the Hogwarts Express leave from?\n");
            printf("1. Platform 9 3/4\n");
            printf("2. Platform 10\n");
            printf("3. Platform 7\n");
            printf("Enter your choice: ");
            scanf("%d", &answer);

            if(answer == 1) score++;
            printf("\n");
        }

        if(i == 5) {
            printf("5) What is the name of Harry's best friend?\n");
            printf("1. Ron Weasley\n");
            printf("2. Draco Malfoy\n");
            printf("3. Neville Longbottom\n");
            printf("Enter your choice: ");
            scanf("%d", &answer);

            if(answer == 1) score++;
            printf("\n");
        }

        if(i == 6) {
            printf("6) Who is the main villain in the series?\n");
            printf("1. Voldemort\n");
            printf("2. Hagrid\n");
            printf("3. Sirius Black\n");
            printf("Enter your choice: ");
            scanf("%d", &answer);

            if(answer == 1) score++;
            printf("\n");
        }

        if(i == 7) {
            printf("7) What position does Harry play in Quidditch?\n");
            printf("1. Keeper\n");
            printf("2. Beater\n");
            printf("3. Seeker\n");
            printf("Enter your choice: ");
            scanf("%d", &answer);

            if(answer == 3) score++;
            printf("\n");
        }
    }

    printf("Your final score is: %d out of 7\n", score);

    if(score == 7) {
        printf("You're a true wizard!\n");
    } else if(score >= 4) {
        printf("Not bad! You're on your way to Hogwarts.\n");
    } else {
        printf("Better luck next time, Muggle!\n");
    }

    // --- SCOREBOARD SYSTEM ---
    printf("\nEnter your name to save your score: ");
    scanf(" %[^\n]", name);  // allows full name with spaces

    fp = fopen("scoreboard.txt", "a"); // try to append or create

    if(fp == NULL) {
        fp = fopen("scoreboard.txt", "w"); // second try: create file
    }

    if(fp == NULL) {
        printf("Still couldn't open file. Please check folder permissions.\n");
        return 1;
    }

    fprintf(fp, "%s - %d/7\n", name, score);
    fclose(fp);

    printf("Score saved successfully!\n");

    return 0;
}
