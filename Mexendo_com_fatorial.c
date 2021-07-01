#include <stdio.h>
#include <stdlib.h>


int validate_x(int x);
int validate_y(int y);
int validate_z(int z);
int print_menu(int option);
double factorial (int n);
int check_equilateral(int x, int y, int z);
int check_isosceles(int x, int y, int z);

int main(){
    int x, y, z, option;
    double result;
    
    printf("Enter de values of x, y and z: (Remember that values must be between 0 and 6 and prime numbers will not be accepted!)\n");
    
    x = validate_x(x);
    y = validate_x(y);
    z = validate_x(z);

    while(1){
        option = print_menu(option);   
        
        switch (option){
        
        case 1:
            result = factorial(x) + factorial(y) + factorial(z);
            printf("-> The result is: %.lf\n", result);
            printf("-> Press enter to continue...\n");
            getchar();
            getchar();
            system("cls||clear");
            break;
        
        case 2:
            result = (factorial(x + y + z));
            printf("-> The result is: %.lf\n", result);
            printf("-> Press enter to continue...\n");
            getchar();
            getchar();
            system("cls||clear");
            break;
        
        case 3:
            result = (factorial(x + y)) + (factorial(x - z));
            printf("-> The result is: %.lf\n", result);
            printf("-> Press enter to continue...\n");
            getchar();
            getchar();
            system("cls||clear");
            break;
        
        case 4:
            result = (factorial(x)) - (factorial(z + y));
            printf("-> The result is: %.lf", result);
            printf("-> Press enter to continue...\n");
            getchar();
            getchar();
            system("cls||clear");
            break;
        
        case 5:
            check_equilateral(x, y, z);
            printf("-> Press enter to continue...\n");
            getchar();
            getchar();
            system("cls||clear");
            break;
        
        case 6:
            check_isosceles(x, y, z);
            printf("-> Press enter to continue...\n");
            getchar();
            getchar();
            system("cls||clear");
            break;
        case 7:
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

int validate_x(int x){
    int rest_prime = 0;
    do{
        printf("Enter the value of X: \n");
        scanf("%d", &x);
        
        if (x < 0 || x >= 7){
            printf("-> Please enter a valid number!!\n");
            printf("-> Press enter to continue...\n");
            getchar();
            getchar();
            system("cls||clear");
        }
        
        rest_prime = 0; 
        for (int i = 1; i <= x; i++){
            if(x % i == 0){
                rest_prime++;
            }
        }
        if (rest_prime == 2){
            printf("-> Enter a non-prime number!\n");
            printf("-> Press enter to continue...\n");
            getchar();
            getchar();
            system("cls||clear");
        }
    } while (x <0 || x >= 7 || rest_prime == 2);
    return x;
}

int validate_y(int y){
    int rest_prime = 0;
    do{
        system("cls || clear");
        printf("Enter the value of Y: \n");
        scanf("%d", &y);
        
        if (y < 0 || y >= 7){
            printf("Please enter a valid number!!\n");
            getchar();
            getchar();
            system("cls || clear");
        }
        
        rest_prime = 0; 
        for (int i = 1; i <= y; i++){
            if(y % i == 0){
                rest_prime++;
            }
        }
        if (rest_prime == 2){
            printf("Enter a non-prime number!\n");
            printf("-> Press enter to continue...\n");
            getchar();
            getchar();
            system("cls||clear");
        }
    } while (y <0 || y >= 7 || rest_prime == 2);
    return y;
}

int validate_z(int z){
    int rest_prime = 0;
    do{
        printf("-> Enter the value of Z: \n");
        scanf("%d", &z);
        
        if (z < 0 || z >= 7){
            system("cls||clear");
            printf("-> Please enter a valid number!!\n");
            printf("-> Press enter to continue...\n");
            getchar();
            getchar();
            system("cls||clear");
        }
        
        rest_prime = 0; 
        for (int i = 1; i <= z; i++){
            if(z % i == 0){
                rest_prime++;
            }
        }
        if (rest_prime == 2){
            printf("-> Enter a non-prime number!\n");
            printf("-> Press enter to continue...\n");
            getchar();
            getchar();
            system("cls||clear");
        }
    } while (z <0 || z >= 7 || rest_prime == 2);
    return z;
}

int print_menu(int option){
    printf("---------------------MENU---------------------\n");
    printf("1 - x! + y! + z!\n");
    printf("2 - (x + y + z)!\n");
    printf("3 - (x + y)! + (x-z)!\n");
    printf("4 - x! - (z + y)!\n");
    printf("5 - If they were sides, would the 3 numbers form an equilateral triangle?\n");
    printf("6 - If they were sides, would the 3 numbers form an isosceles triangle?\n");
    printf("7 - Exit\n");
    scanf("%d", &option);
    system("cls||clear"); 
    return option;
}

double factorial (int n) {
    int f = 1;
    for (int i = 2; i <= n; i++){
        f = f * i;
    }
    return f;
}

int check_equilateral(int x, int y, int z){

    if (x + y > z && x + z > y && y + z > x){
        if (x == y && x == z){
            printf("-> The points form an equilateral triangle!\n");
        }else{
            printf("-> The dots do not form an equilateral triangle!\n");
        }
    }else{
        printf("-> The three points do not form a triangle!\n");
    }
    return 0;
}

int check_isosceles(int x, int y, int z){

    if (x + y > z && x + z > y && y + z > x){
        if (x == y || x == z || y == z){
            printf("-> The points form an isosceles triangle!\n");
            printf("-> Press enter to continue...\n");
            getchar();
            getchar();
            system("cls||clear");
        }else{
            printf("-> The points do not form an isosceles triangle!\n");
            printf("-> Press enter to continue...\n");
            getchar();
            getchar();
            system("cls||clear");
        }
    }else{
        printf("-> The three points do not form a triangle!\n");
        printf("-> Press enter to continue...\n");
        getchar();
        getchar();
        system("cls||clear");
    }
    return 0;
}