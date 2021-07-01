#include <stdio.h>
#include <stdlib.h>

//Objective: Print a menu for the user with some options
//Input: Whole numbers
//Output: Amount of numbers, Amount of negative numbers, Amount of even numbers, Amount of prime numbers, Average, Exit

int main(){
    int i, num, option, amount = 0, negative_amount = 0, even_numbers = 0, rest_prime, prime_amount = 0;
    float average, sum = 0;
    
        printf("-> Enter the numbers: (To go to the menu, enter a multiple number of 150)\n");
    do{
        scanf("%d", &num);
        
        //Discovering the amount of numbers and the average
        if (num % 150 != 0){
            amount++;
            sum += num; //Adding the numbers
            average = sum/amount; //Average structure
        } 

        //Discovering the amount of the negative numbers
        if(num < 0 && num % 150 != 0){
            negative_amount++;
        }  
        
        //Discovering the amount of the even numbers
        if (num % 2 == 0 && num % 150 != 0){
            even_numbers++; 
        }
        
        // Discovering the amount of the prime numbers, I considered that there are negative prime numbers
        rest_prime = 0;
        if(num > 1){
            for (i = 2; i < num; i++){
                if (num % i == 0){
                    rest_prime++;  
                    break;
                }
            }
            if (rest_prime == 0){
                prime_amount++;
            }
        }else if (num < -1){
            num *= -1;
            for (i = 2; i < num; i++){
                if (num % i == 0){
                    rest_prime++;  
                    break;
                }
            }
            if (rest_prime == 0){
                prime_amount++;
            }
        }
    
    } while (num % 150 != 0);
    system("cls||clear");
    
    while(1){
        printf("---------------------MENU---------------------\n");
        printf("1 - Amount of Numbers Entered\n");
        printf("2 - Amount of Negative Numbers\n");
        printf("3 - Amount of Even Numbers\n");
        printf("4 - Amount of Prime Numbers\n");
        printf("5 - Average of Numbers\n");
        printf("6 - Exit\n");
        scanf("%d", &option);
        system("cls||clear");   
        
        switch (option){
        
        case 1:
            printf("--------------AMOUNT OF NUMBERS--------------\n");
            printf("-> The amount of numbers is: %d\n", amount);
            printf("-> Press enter to continue...\n");
            getchar();
            getchar();
            system("cls||clear");
            break;
        
        case 2:
            printf("----------AMOUNT OF NEGATIVE NUMBERS----------\n");
            printf("-> The amount of negative numbers is: %d\n", negative_amount);
            printf("-> Press enter to continue...\n");
            getchar();
            getchar();
            system("cls||clear");
            break;
        
        case 3:
            printf("------------AMOUNT OF EVEN NUMBERS------------\n");
            printf("-> The amount of even numbers is: %d\n", even_numbers);
            printf("-> Press enter to continue...\n");
            getchar();
            getchar();
            system("cls||clear");
            break;
        
        case 4:
            printf("-----------AMOUNT OF PRIME NUMBERS------------\n");
            printf("-> The amount of prime numbers is: %d\n", prime_amount);
            printf("-> Press enter to continue...\n");
            getchar();
            getchar();
            system("cls||clear");
            break;
        
        case 5:
            printf("-------------------AVERAGE-------------------\n");
            printf("-> The average of numbers is: %.2f\n", average);
            printf("-> Press enter to continue...\n");
            getchar();
            getchar();
            system("cls||clear");
            break;
        
        case 6:
            printf("-> Thanks!! See you later!!\n");
            return 0;
            break;
        
        default:
            printf("-> Invalid option!! Please insert a valid option...\n");
            printf("-> Press enter to continue...\n");
            getchar();
            getchar();
            system("cls||clear");
            break;
        }  
    }
    return 0;   
}