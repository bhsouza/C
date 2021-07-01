#include <stdio.h>
#include <stdlib.h>

void line_column(int line, int column, int student[3][3]);
void view_class(int student[3][3]);
void return_menu();

int main(){
    //Declarations
    int option, line, column, ID, student[3][3] = {0};
    //Instructions
    while(1){
        //Menu
        option = option_menu(option);
        //Choosing a option
        switch (option){
        case 1:
            system("cls || clear");
            line_column(line, column, student); //Function to register a student
            return_menu();
            break;
        
        case 2:
            system("cls || clear");
            view_class(student);// Function to view class
            return_menu();
            break;
        
        case 3:
            //Exit
            system ("cls || clear");
            printf("--------------EXIT--------------\n");
            printf("-> Thanks!! See you later!!\n");
            return 0;
        
        default:
            system ("cls || clear");
            //Validating option
            printf("-> Invalid option!! Please insert a valid option...\n");
            return_menu();
            break;
        }
    }

    return 0;
}
//Function to print Menu and choose a option
int option_menu(int option){

    system ("cls || clear");
    printf("-----------MENU-----------\n");
    printf("1 - Register Student\n");
    printf("2 - View Class\n");
    printf("3 - Exit\n");
    scanf("%d", &option);
    return option;
}
//Function to register a ID
void line_column(int line, int column, int student[3][3]){

    line = 0;
    column = 0;

    while(1){
        system ("cls || clear");
        printf("-------------Register ID-------------\n");
        printf("-> Type the desired line: \n");
        scanf("%d", &line);
        printf("-> Type the desired column: \n");
        scanf("%d", &column);
        
        if(line >= 1 && line <= 3 && column >= 1 && column <= 3){ 

            do{
                system ("cls || clear");
                printf("-------------Register ID-------------\n");
                printf("-> Enter student ID: \n");
                scanf("%d", &student[line - 1][column - 1]);
                
                if (student[line - 1][column - 1] <= 0 || student[line - 1][column - 1] >= 100){
                    system ("cls || clear");
                    printf("-> Invalid ID !! Press enter and enter a value > 0 and < 100 to be accepted ...\n");
                    getchar();
                    getchar();
                }
            
            } while (student[line - 1][column - 1] <= 0 || student[line - 1][column - 1] >= 100);
            return 0;
        
        }else{
            
            system ("cls || clear");
            printf("-> Invalid value, press enter and enter values between 1 and 3 !!\n");
            getchar();
            getchar();
        }
    }
}
//Function to view class
void view_class(int student[3][3]){
    
    system ("cls || clear");
    printf("-------------View Class-------------\n\n");
    
    for (int i = 0; i < 3; i++){         //Cycle with the objective of showing the organization of the IDs
        for (int j = 0; j < 3; j++){
            if(student[i][j] == 0){
                student[i][j] -= 1;
            }
            printf("%d ", student[i][j]);
        }
        printf("\n");
    }
}
//Function to return to menu
void return_menu(){
    
    printf("\n-> Press enter to return to the menu...\n");
    getchar();
    getchar();
}

