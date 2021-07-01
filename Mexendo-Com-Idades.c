#include <stdio.h>
#include <stdlib.h>

int read_age (int age[], int *count);
int print_menu(int option);
float average_function (int age[], float add, int *count, float average);
void bigger_smaller_function (int *count, int age[], int bigger, int smaller);
void list_age(int age[], int *count);
void above_below_average(int age[], int *count, float average);
int edit_age(int age[], int *count);
int search_position (int age[], int position, int *count);
void yes_no_edit (int age[],int tf, int *count, int position);
void yes_no_delete (int age[], int *count, int position);
void return_menu();

int main(){
    
    // Declarations
    int age[200], count = 0, option, bigger, smaller, position, tf;
    float average = 0, add = 0;
    
    // Instructions
    read_age (age, &count);
    system ("cls || clear");
    
    while(1){
        //Introducing the menu
        option = print_menu(option);
        //Choosing the option
        switch (option){
        case 1:
            system ("cls || clear");
            printf("----------General Information----------\n");
            printf("-> Amount of numbers entered: %d \n", count);
            //Discovering the average
            average = average_function(age, add, &count, average);
            printf("-> Average of ages: %.2f\n", average);
            //Function for discover the bigger and the smaller age
            bigger_smaller_function ( &count, age, bigger, smaller);
            return_menu();
            break;
        case 2:
            system ("cls || clear");
            printf("----------Age List----------\n");
            //Function for list ages
            list_age( age, &count);
            return_menu();
            break;
        case 3:
            system ("cls || clear");
            printf("----------Above and Below Average----------\n");
            //Function to find out which numbers are above or below than the average
            above_below_average(age, &count, average);
            return_menu();
            break;
        case 4:
            system ("cls || clear");
            printf("---------------Edit Age---------------\n");
            //Edit Age
            yes_no_edit(age, tf, &count, position);
            return_menu();
            break;
        case 5:
            system ("cls || clear");
            printf("-------------Delete Age-------------\n");
            //Delete Age
            yes_no_delete (age, &count, position);
            return_menu();
            break;
        case 6:
            system ("cls || clear");
            printf("---------------Searching Age---------------\n");
            //Search Age
            search_position (age, position, &count);
            return_menu();
            break;
        case 7:
            //Exit
            printf("-> Thanks!! See you later!!\n");
            return 1;
        default:
            system ("cls || clear");
            //Validating option
            printf("-> Invalid option!! Please insert a valid option...\n");
            return_menu();
            break;
        }
    }
    printf("hahaha cabo!");
    return 0;
}

// Functions used to do what was said in the main

int read_age (int age[], int *count){
    printf("-> Enter the age of the students, only age between 1 and 149 will be considered valid. To go to the menu enter 150!\n");
    do{
        printf("-> Digite uma idade: ");
        scanf("%d", &age[*count]);
        if (age[*count] < 1 || age[*count] > 150){
            system("cls || clear");
            printf("-> Insira uma idade valida!!!\n");
        }else if (age[*count] > 0 && age[*count] <=149){
            system ("cls || clear");
            *count += 1;
        }
    } while (age[*count] != 150);
    return age[*count];
}


int print_menu(int option){
    printf("---------------------MENU---------------------\n");
    printf("1 - General Information\n");
    printf("2 - List Ages\n");
    printf("3 - Larger / Smaller Than Average List\n");
    printf("4 - Edit Age\n");
    printf("5 - Delete Age\n");
    printf("6 - Search Position\n");
    printf("7 - Exit\n");
    printf("-> Choose an option: (1/7)\n");
    scanf("%d", &option);
    system("cls||clear"); 
    return option;
}

float average_function (int age[], float add, int *count, float average){
    for (int i = 0; i < *count; i++){
        add += age[i];
    }
    average = add / *count;
    return average;
}

void bigger_smaller_function (int *count, int age[], int bigger, int smaller){
    for (int i = 0; i < *count; i++){
        if (i == 0){
            bigger = age[i];
            smaller = age[i];
        }else if (age[i] > bigger){
            bigger = age[i];
        }else if (age [i] < smaller){
            smaller = age[i];
        }
    }
    
    printf("-> Biggest age: %d \n", bigger);
    printf("-> Smaller age: %d \n", smaller);
}

void list_age(int age[], int *count){
    for (int i = 0; i < *count; i++){
        printf("-> %d \n", age[i]);
    }
}

void above_below_average(int age[], int *count, float average){
    for (int i = 0; i < *count; i++){
        if (age[i] > average){
            printf ("-> Above average: %d\n", age[i]);
        }
        if (age[i] < average){
            printf ("-> Below average: %d\n", age[i]);
        }
    }
}

int edit_age(int age[], int *count){
    int newage;
    do{
    printf("-> Digite a nova idade: \n");
        scanf("%d", &newage);
        
        if (newage < 1 || newage >= 150){
            printf("-> Insira uma idade valida!!!\n");
        }
    
    } while (newage < 1 || newage >= 150) ;
    
    return newage;
}

void yes_no_edit (int age[],int tf, int *count, int position){
    position = search_position (age, position, count);
    if (position > 0 && position <= *count){
        printf("-> Are you sure you want to edit the age in this position? (Insert 0 for yes or 1 for no)\n");
        do{
            scanf("%d", &tf);
            if (tf == 0){
                age [position - 1] = edit_age(age, &count);
            }else if (tf == 1){
                printf("-> Okay, press enter to return to the menu\n");
            }else{
                printf("-> Invalid option!! Please insert 0 for yes or 1 for no!!\n ");
            }
        }while (tf < 0 || tf > 1);
    }else{
        printf("-> Return to the menu and try again...\n");
    }
    
}

void yes_no_delete (int age[], int *count, int position){
    int tf;
    position = search_position (age, position, count);
    if(position > 0 && position <= *count){
        printf("-> Are you sure you want to delete the age in this position? (Insert 0 for yes or 1 for no)\n");
        do{
            scanf("%d", &tf);
            if (tf == 0){
                printf ("-> Excluding Age...\n");
                for (int i = position - 1; i <= *count; i++){
                    age[i] = age[i + 1];
                }
                *count -= 1;
            
            }else if (tf == 1){
                printf("-> Okay, press enter to return to the menu\n");
            }else{
                printf("-> Invalid option!! Please insert 0 for yes or 1 for no!!\n ");
            }
        }while (tf < 0 || tf > 1);
    }else{
        printf("-> Return to the menu and try again...\n");
    }
}

int search_position (int age[], int position, int *count){
    printf("-> Enter the desired position: \n");
    scanf("%d", &position);
    if (position > 0 && position <= *count){
        printf("-> The age of this position is: %d\n", age[position - 1]); 
    }else{
        printf("-> Invalid Position!\n");
    }
    return position;
}

void return_menu(){
    printf("-> Press enter to return to the menu...\n");
    getchar();
    getchar();
}