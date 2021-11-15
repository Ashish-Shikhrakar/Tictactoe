#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
#include<ctype.h>

// global variables for use in functions

int i,j,piece=0;
int board_grid[3][3];
int storage[9]={50,50,50,50,50,50,50,50,50};
char true_board[10] = { 'o', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
char r = 'O';

//functions used 

void intro(); //landing page
void main_menu(); //options section
void player_1(); //singleplayer
void player_2(); //multiplayer
int coinflip_decision(); //decides who goes first
int playground(int marker,int *p,int turn_counter,int turn); //board for game
int initiate(int *p,int marker,int turn,int turn_counter); //prints board
int wincond(int turn,int turn_counter); //win condition decider
int data_store(int marker,int turn_counter,int turn); // checks if slot is selected or not
void tutorial();

void red () {
  printf("\033[1;31m");
}
void reset () {
  printf("\033[0m");
}
void green () {
  printf("\033[1;32m");
}

//main function

int main()
{
    intro();
    main_menu();
}

// first screen

void intro()
{

    printf("\tWELCOME to TicTacToe v1.0\n");

    printf("\n\tEnter any key to continue.\n%70sCreated by: Ashish Raj Shikhrakar\n"," ");
    getch();
    system("cls");
}

void main_menu()
{
    char ch, user_decision='Y';
    while (user_decision = 'Y')
    {
        mark3:
        red();
        printf("\tMain Menu");
        reset();
        printf("\na.1 Player\nb.2 Player\nc.How to Play\nd.Quit");
        printf("\n\nChoose from the options: \n");
        scanf(" %c",&ch);
        ch = tolower(ch);
        switch (ch)
        {
        case 'a':
            printf("Unavailable");
            break;
        
        case 'b':
            player_2();
            break;
        
        case 'c':
            tutorial();
            break;
        
        case 'd':
            exit(0);
            break;
        
        default:
            printf("Enter a valid option.");
            getch();
            system("cls");
            goto mark3;
            break;
        }
        printf("\n\nPress any key to return to main menu.");
        getch();
        system("cls");
    }
    
    
}
void player_2()
{
    int marker,turn,decider=0,turn_counter=0;
    int counter=1,*p;
    p = &board_grid[0][0];
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            *(p+i*3+j) = counter;
            counter++;
        }
    }
    system("cls");
    turn = coinflip_decision();
    printf("\n\nTo continue press any key.");
    getch();
    system("cls");
    initiate(p,marker,turn,turn_counter);
    while (decider == 0)
    {
        printf("\nChoose the slot number to place your mark:\n");
        printf("\nplayer %d: ",turn);
        scanf("%d",&marker);
        marker = playground(marker,p,turn_counter,turn);
        turn_counter++;
        system("cls");
        initiate(p,marker,turn,turn_counter);
        if (turn_counter>=5)
        {
            decider = wincond(turn,turn_counter);
            if (decider == 1)
            {
                turn_counter == 0;
                turn ==1;
                piece = 0;
                r = 'O';
                for (i = 0; i < 10; i++)
                {
                    storage[i] = 50;
                    true_board[i] = i + '0';
                }
                
            }
            
        }
        if (turn==1)
        {
            turn++;
        }
        else
        {
            turn--;
        }
    }
}
void player_1()
{
    int grid[3][3],i,j,decision;
    char cflip;
    printf("\nPlayer 1 may choose heads(H) or tails(T).\n");
    scanf(" %c",&cflip);
    
    
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            /* code */
        }
        printf("\n");
    }
    getch();
}
int coinflip_decision()
{
    int decision,p1=0,p2=0;
    char cflip;
    printf("\nPlayer 1 may choose heads(H) or tails(T).\n");
    scanf(" %c",&cflip);
    cflip = toupper(cflip);
    srand(time(0));
    decision = (rand() %2);
    if (decision==0)
    {
        if (cflip=='H')
        {
            printf("The coin landed on heads.\n\nPlayer 1 won the toss and gets to go first.\n");
            return 1;
        }
        else
        {
            printf("The coin landed on heads.\n\nPlayer 1 lost the toss and will go second.\n");
            return 2;
        } 
    }
    else
    {
        if (cflip=='T')
        {
            printf("The coin landed on tails.\n\nPlayer 1 won the toss and gets to go first.\n");
            return 1;
        }
        else
        {
            printf("The coin landed on tails.\n\nPlayer 1 lost the toss and will go second.\n");
            return 2;
        }
    }
}
int playground(int marker,int *p,int turn_counter,int turn)
{
    marker = data_store(marker,turn_counter,turn);
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (marker==*(p+i*3+j))
            {
                *(p+i*3+j) = piece;
            }
        }
        printf("\n");
    }
    if (piece == 0)
    {
        piece=1;
    }
    else
    {
        piece=0;
    }
    return marker;
}
int initiate(int *p,int marker,int turn,int turn_counter)
{
    if (turn_counter == 0)
    {
        printf("     |     |     \n");
        printf("  %c  |  %c  |  %c \n", true_board[1], true_board[2], true_board[3]);

        printf("_____|_____|_____\n");
        printf("     |     |     \n");

        printf("  %c  |  %c  |  %c \n", true_board[4], true_board[5], true_board[6]);

        printf("_____|_____|_____\n");
        printf("     |     |     \n");

        printf("  %c  |  %c  |  %c \n", true_board[7], true_board[8], true_board[9]);

        printf("     |     |     \n\n");
    }
    else
    {
        if (r == 'O')
        {
            true_board[marker] = 'O';
            r = 'X';
        }
        else
        {
            true_board[marker] = 'X';
            r = 'O';
        }
        printf("     |     |     \n");
        printf("  %c  |  %c  |  %c \n", true_board[1], true_board[2], true_board[3]);

        printf("_____|_____|_____\n");
        printf("     |     |     \n");

        printf("  %c  |  %c  |  %c \n", true_board[4], true_board[5], true_board[6]);

        printf("_____|_____|_____\n");
        printf("     |     |     \n");

        printf("  %c  |  %c  |  %c \n", true_board[7], true_board[8], true_board[9]);

        printf("     |     |     \n\n");
        
    }
    return 0;
}
int wincond(int turn,int turn_counter)
{
    int round=0,count=0;
    i=0;
    j=0;
    if (turn_counter == 9)
    {
        printf("Draw. Well Played!");
        getch();
        return 1;
        
    }
    else
    {
        while (count!=9)
        {
            mark1:
            if (board_grid[i][j] == board_grid[i][j+1] && board_grid[i][j+1] == board_grid[i][j+2])
            {
                round = 1;
                printf("Player %d is the winner. Congratulations.", turn);
                return 1;
            }
            else
            {
                i++;
                count++;
                if (i!=3)
                {
                    goto mark1;
                }
                
            }
            i=0;j=0;
            mark2:
            if (round == 0)
            {
                if (board_grid[i][j] == board_grid[i+1][j] && board_grid[i+1][j] == board_grid[i+2][j])
                {
                    round = 1;
                    printf("Player %d is the winner. Congratulations.", turn);
                    return 1;
                }
                else
                {
                    j++;
                    count++;
                    if (j!=3)
                    {
                        goto mark2;
                    }
                }
            }
            if (round == 0)
            {
                if ((board_grid[0][0] == board_grid[1][1] && board_grid[1][1] == board_grid[2][2])||(board_grid[0][2] == board_grid[1][1] && board_grid[1][1] == board_grid[2][0]))
                {
                    round = 1;
                    printf("Player %d is the winner. Congratulations.", turn);
                    return 1;
                }
            }
            if (round == 0)
            {
                return 0;
            }
            
        }   
    }
}

int data_store(int marker,int turn_counter,int turn)
{
    int track=0;
    for (i = 0; i < 9; i++)
    {
        if ((marker == storage[i])||((marker<1) || (marker>9)))
        {
            printf("Invalid slot selection. Please choose another slot.\nPlayer %d: ",turn);
            scanf(" %d",&marker);
            track = 1;
            return marker;
        }
    }
    if (track == 0)
    {
        for (i = 0; i <= turn_counter; i++)
        {
            storage[turn_counter] = marker;
            return marker;
        }
    }
    
}

void tutorial()
{
    system("cls");
    printf("Here is how to play the game.\n\nCoin flip decides who goes first.\n\n Try to position pieces such that full row or column or diagnols line up with only your pieces.\n\n If your opponent is close to line up their pieces block with your own.\n\n Have fun!");
}