#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void validate_email(char email[], int *valid);
void validate_username(char username[], int *valid);
void validate_password(char password[], int *valid);
int validate_all(int *valid, char email[], char username[], char password[]);
void valid_sinister(char sinister[]);

int main(){
    int valid = 0, ok;
    char email[200], username[200], password[200], sinister[200];
    
    while(1){
        
        printf("----------User Login---------- \n ");
        printf("-> Enter your email: \n");
        scanf("%s", email);
        system("cls || clear");

        printf("----------User Login---------- \n ");
        printf("-> Enter your username: \n");
        scanf("%s", username);
        system("cls || clear");

        printf("----------User Login---------- \n ");
        printf("-> Enter your password: \n");
        scanf("%s", password);
        system("cls || clear");
        
        validate_email(email, &valid);
        validate_username(username, &valid);
        validate_password(password, &valid);
        ok = validate_all(&valid, email, username, password);
        if (ok == 1){
            printf("----------------------------------Last Validation----------------------------------\n");
            printf("-> Okay, now we have the last validation phase, you must insert a sinister phrase! \n");
            valid_sinister(sinister);
            return 0;
        }
    }
    return 0;
}

void validate_email(char email[], int *valid){
        
    int countArroba1 = 0, countPoint1 = 0, countSpecial1 = 0, countCapitalLetter1 = 0, countNumber1 = 0;
    for (int i = 0; i < strlen(email); i++){
        if (email[i] == '@'){
            countArroba1++;
        }
        if (email[i] == '.'){
            countPoint1++;
        }
        if(ispunct(email[i]) && email[i] != '@' && email[i] != '.'){
            countSpecial1++;
        }
        if(isupper(email[i])){
            countCapitalLetter1++;
        }
        if(isdigit(email[i])){
            countNumber1++;
        }
    }
    *valid = 0;
    if(countArroba1 == 1 && countPoint1 > 0 && countSpecial1 == 0 && countCapitalLetter1 == 0 && countNumber1 == 0 ){
        *valid += 1;
    }
}

void validate_username(char username[], int *valid){
        
    int countSpecial2 = 0, countCapitalLetter2 = 0, countNumber2 = 0;
    for (int i = 0; i < strlen(username); i++){
        if (ispunct(username[i])){
            countSpecial2++;
        }
        if (isupper(username[i])){
            countCapitalLetter2++;
        }
        if (isdigit(username[i])){
            countNumber2++;
        }
    }
        
    if (strlen(username) >= 4 && strlen(username) <=10 && countSpecial2 == 0 && countCapitalLetter2 == 0 && countNumber2 == 0){
        *valid += 1;
    }
}

void validate_password(char password[], int *valid){
        
    if (strlen(password) >= 8 && strlen(password) <=40){
        *valid += 1;
    }
}

int validate_all(int *valid, char email[], char username[], char password[]){

    if (*valid == 3){
        printf("---------------------------Login Information--------------------------\n");
        printf("-> Congratulations all your data have been successfully validated!! \n");
        printf("-> Email: %s \n", email);
        printf("-> Username: %s \n", username);
        printf("-> Password: %s \n", password);
        printf("-> Press enter to go to the last validation phase...");
        getchar();
        getchar();
        system("cls || clear");
        return 1;
    }else{
        printf("-> Invalid Login!\n");
        printf("-> Login rules:\n");
        printf("-> Email: Must contain a single '@' and at least one '.', only lowercase letters are accepted.\n");
        printf("-> Username: Only lowercase letters are accepted, special characters and numbers are not accepted. It must have a maximum of 10 characters.\n");
        printf("-> Password: Minimum length of 8 and maximum of 40 characters.\n");
        printf("-> Press enter to rewrite the data correctly ...");
        getchar();
        getchar();
        system("cls || clear");
        return 0;
    }
}

void valid_sinister(char sinister[]){
    
    while(1){ 
        
        scanf(" %[^\n]s", sinister);
        system("cls || clear");
        int  countPoint2 = 0, countSpace = 0, countCapitalLetter3 = 0, size;
        size = strlen(sinister);
        
        for (int i = 0; i < strlen(sinister); i++){
            if (sinister[i] == ' '){
                countSpace++;
            }     
        }
        
        if (isupper(sinister[0])){
            countCapitalLetter3++;
        }

        if (sinister[size - 1] == '.'){
            countPoint2++;
        }
        
        
        if (strlen(sinister) >= 70 && countSpace >= 4 && countCapitalLetter3 == 1 && countPoint2 == 1){
            system("cls || clear");
            printf("--------------------------Login Validated--------------------------\n");
            printf("-> Congratulations, your login has been successfully validated!! \n");
            return 0;
        }else{
            system("cls || clear");
            printf("----------------------------------Last Validation----------------------------------\n");
            printf("-> That phrase was not even sinister! Please enter a sinister phrase:\n");
        }
    }
}