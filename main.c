#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<stdbool.h>
#define clrscr() printf("\e[1;1H\e[4J")
int length = 20, width = 100, i, j;
int headx, heady, foodx, foody, score = 0, d, life = 3;
bool gameover = false;
char* c = "o";
void setting(){
    headx = length / 2;
    heady = width / 2;
    point1:
    foodx = rand() % length;
    if (foodx == 0){
        goto point1;
    }
    
    point2:
    foody = rand() % width;
    if (foody == 0){
        goto point2;
    }
}

void draw(){
    for (i = 0; i < length; i++){
        for (j = 0; j < width; j++){
            if(i == 0 || i == length - 1)
                printf("!");
            else if(j == 0 || j == width - 1)
                printf("!");
            else{
                if(foodx == i && foody == j)
                    printf("#");
                else if(headx == i && heady == j)
                    printf("%s", c);
                else
                    printf(" ");
            }
        }
        printf("\n");
    }
    
}

void logic(){
    switch (d){
        case 1:
            headx--;
            ///if(headx < 0){
            ///    headx = length;
            ///}
            break;
        case 2:
            heady--;
            ///if(heady < 0){
            ///    heady = width;
            ///}
            break;
        case 3:
            heady++;
            ///heady %= width;
            break;
        case 4:
            headx++;
            ///headx %= length;
            break;
        default:
            break;
    }
}


void input(){
    system("cls");
    ///clrscr();
    if(kbhit()){
        switch (getch()){
        case 'w':
            d = 1;
            break;
        case 'a':
            d = 2;
            break;
        case 'd':
            d = 3;
            break;
        case 's':
            d = 4;
            break;
        case 'o':
            gameover = true;
            break;
        }
    }
    logic();
}

void game(){
    if(foodx == headx && foody == heady){
        score++;
        point1:
        foodx = rand() % length;
        if (foodx == 0){
            goto point1;
        }
    
        point2:
        foody = rand() % width;
        if (foody == 0){
            goto point2;
        }
    }
    if(headx >= length || heady >= width || headx <= 0 || heady <= 0){
        if(life - 1){
            life--;
            headx = length / 2;
            heady = width / 2;
        } else {
            gameover = true;
        }
    }
    //if(score % 2 == 0 && score > 0){
    //    c = "o->";
    //}
}

int main(){
    setting();
    while(!gameover){
        printf("Score:%d                                          Life:%d\n", score, life);
        draw();
        input();
        game();
    }
    printf("\n----------G A M E  O V E R----------\n");
    printf("YOUR SCORE IS: %d\n", score);
    return 0;
}
