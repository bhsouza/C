#include <stdio.h>
#include <stdlib.h>

int main(){
    int option, evenodd;
    float weight, height, BMI, result, num1, num2;
    printf("--------------------MENU--------------------\n");
    printf("1 - Student Information\n");
    printf("2 - Calculate Body Mass Index (BMI)\n");
    printf("3 - Check Whether the Number is Even or Odd\n");
    printf("4 - Calculate Multiplication\n");
    printf("5 - Calculate Division\n");
    printf("6 - Exit\n");
    scanf("%d", &option);
    system("cls");
    
    switch (option){
    case 1:
        printf("Name: Breno Henrique de Souza\n");
        printf("Registration: 202015984\n");
        printf("Semester: 2020/2\n");
        break;
    case 2:
        printf("Enter your weight:");
        scanf("%f", &weight);
        printf("Enter your heght:");
        scanf("%f", &height);
        BMI = weight / (height * height);
        printf("Your BMI is: %f", BMI);
        break;
    case 3:
        printf("Please, enter a number:");
        scanf("%d", &evenodd);
        if (evenodd % 2 ==0){
            printf("This number is even");
        }else{
            printf("This number is odd");    
        }
        break;
    case 4:
        printf("Enter the first number: ");
        scanf("%f", &num1);
        printf("Enter the second number: ");
        scanf("%f", &num2);
        result = num1 * num2;
        printf("The result of the multiplication is: %f", result);
        break;
    case 5:
        printf("Enter the first number: ");
        scanf("%f", &num1);
        if (num1 == 0){
           printf("Invalid number!!");
        }else{
            printf("Enter the second number: ");
            scanf("%f", &num2);
            if (num2 == 0){
                printf("Invalid number!!");
            }else{
                result = num1 / num2;
                printf("The result of the division is: %f", result);
            }
        }
        break;
    case 6:
        printf("Thank you for using the program, always come back !!");
        break;
    default:
        printf("Invalid option!!!");
    }
    return 0;
}