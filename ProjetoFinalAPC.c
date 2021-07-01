#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct jogador{
    int id;
    char nome[50];
    char posicao[4];
    int idade;
}Jogador;

typedef struct time{
    Jogador jogadores[5];
    char nome_time[50];
    char nome_MVP[50];
    char nome_LVP[50];
    char nome_tecnico[50];
    char Pos_MVP[4];
    char Pos_LVP[4];
}Time;

typedef struct jogadores_partida{
    int id_jogador;
    int num_assistencias;
    int num_kills;
    int num_deaths;
    int pontuacao_jogador;
    int pontuacao_total_jogador;
}JogadorPartida;

typedef struct partida{
    int total_kills_time;
    int total_kills_adversario;
    char posicao_destaque[4];
    char nome_destaque[50];
    int decisao;
    int total_torres_destruidas_time;
    int total_torres_destruidas_adversario;
    JogadorPartida jogadores_partida[5];
}Partida;

int menu(int opcao);
void distribui_opcoes(int opcao, Time *time, Partida *partidas, int *quant_partidas);
void cadastra_time( Time *time);
void listar_time(Time *time);
void edit_time(Time *time, int *quant_partidas, Partida *partidas);
void cadastrar_partida(Partida *partidas, int *quant_partidas);
void listar_partidas(Time *time, Partida *partidas, int *quant_partidas);
void pesquisa_jogador(Time *time, Partida *partidas, int *quant_partidas);
void soma_kill(Partida *partidas, int *quant_partidas);
void pior_partida(Time *time, Partida *partidas, int *quant_partidas);
void MVP_partida(Time *time, Partida *partidas, int *quant_partidas);
void retorna_menu();

int main(){
    Time time;
    Partida partidas[100];
    int opcao;
    int quant_partidas = 0;
    do{
        opcao = menu(opcao);
        distribui_opcoes(opcao , &time, &partidas, &quant_partidas);
    } while (opcao != 10);

    return 0;
}

int menu(int opcao){
    system ("cls || clear");
    printf("---------MENU---------\n");
    printf("1 - Cadastrar time\n");
    printf("2 - Listar time\n");
    printf("3 - Editar time\n");
    printf("4 - Cadastrar Partida\n");
    printf("5 - Listar partidas\n");
    printf("6 - Pesquisar jogador\n");
    printf("7 - Mostrar o numero total de kills e assistencias\n");
    printf("8 - Mostrar jogador com menor pontuação\n");
    printf("9 - Mostrar jogador com maior pontuacao\n");
    printf("10 - Sair\n");
    scanf("%d", &opcao);
    getchar();
    return opcao;
}

void distribui_opcoes(int opcao, Time *time, Partida *partidas, int *quant_partidas){

    switch (opcao){
    case 1:
        cadastra_time( &*time);
        break;
    case 2:
        listar_time( &*time);
        break;
    case 3:
        edit_time(&*time, &*quant_partidas, &*partidas);
        break;
    case 4:
        cadastrar_partida(&*partidas, &*quant_partidas);
        break;
    case 5:
        listar_partidas(&*time, &*partidas, &*quant_partidas);
        break;
    case 6:
        pesquisa_jogador(&*time, &*partidas, &*quant_partidas);
        break;
    case 7:
        soma_kill(&*partidas, &*quant_partidas);
        break;
    case 8:
        pior_partida(&*time, &*partidas, &*quant_partidas);
        
        break;
    case 9:
        MVP_partida(&*time, &*partidas, &*quant_partidas);
        break;
    case 10:
        system ("cls || clear");
        printf("--------------EXIT--------------\n");
        printf("-> Obrigado, espero te ver novamente!!\n");
        break;
    default:
        printf("-> Opcao invalida!!\n!");
        retorna_menu();
        break;
    }
}

void cadastra_time(Time *time){
    system("cls || clear");
    printf("---------------------------Cadastro do Time--------------------------\n");
    //Nome do time
    printf("-> Digite o nome do time:");
    scanf("%[^\n]s", time->nome_time);
    //Nome do técnico do time
    printf("-> Digite o nome do tecnico:");
    getchar();
    scanf("%[^\n]s", time->nome_tecnico);
    system("cls || clear");
    //Laço para algumas informações
    for (int i = 0; i < 5; i++){
        printf("---------------------------Cadastro do Time--------------------------\n");
        time->jogadores[i].id = i + 1; //ID auto preenchida
        printf("-> ID: %d\n", time->jogadores[i].id); 
        printf("-> Nome: ");
        getchar();
        scanf("%[^\n]s", time->jogadores[i].nome);//Nome dos jogadores
        printf("-> Posicao: ");
        //Laço pra validar uma posição válida
        do{
            getchar();
            scanf("%[^\n]s", time->jogadores[i].posicao);
            if(strcmp(time->jogadores[i].posicao, "TOP") != 0 && strcmp(time->jogadores[i].posicao, "MID") != 0 && strcmp(time->jogadores[i].posicao, "JG") != 0 && strcmp(time->jogadores[i].posicao, "ADC") != 0 && strcmp(time->jogadores[i].posicao, "SUP") != 0){
                printf("-> So sao aceitas as posicoes: TOP, MID, JG, ADC e SUP(So eh aceito uma posicao escrito em caixa alta), digite novamente:\n");
            }
        }while(strcmp(time->jogadores[i].posicao, "TOP") != 0 && strcmp(time->jogadores[i].posicao, "MID") != 0 && strcmp(time->jogadores[i].posicao, "JG") != 0 && strcmp(time->jogadores[i].posicao, "ADC") != 0 && strcmp(time->jogadores[i].posicao, "SUP") != 0);
        printf("-> Idade:");
        //Laço pra validar uma idade válida
        do{
            scanf("%d", &time->jogadores[i].idade);
            if(time->jogadores[i].idade <=0 || time->jogadores[i].idade > 150){
                printf("-> Digite uma idade valida! (So sao aceitos valores entre 1 e 150)\n");
            }
        }while(time->jogadores[i].idade <=0 || time->jogadores[i].idade >150);
        system("cls || clear");
    }
    retorna_menu();
}

//Função feita para listar times
void listar_time(Time *time){
    system("cls || clear");
    printf("-> Nome do Time: %s\n", time->nome_time);
    printf("-> Nome do Tecnico: %s\n", time->nome_tecnico);
    //Laço para listar informações de cada jogador
    for(int i = 0; i < 5; i++){
        printf("--------------------------\n");
        printf("-> ID: %d \n", time->jogadores[i].id);
        printf("-> Nome: %s \n", time->jogadores[i].nome);
        printf("-> Posicao: %s \n", time->jogadores[i].posicao);
    }
    printf("--------------------------\n");
    retorna_menu();
}

//Função feita com intuito de editar um jogador do time
void edit_time(Time *time, int *quant_partidas, Partida *partidas){
    //Declarações
    int ID;
    int pont_total = 0;
    int certeza;
    //Intruções
    system("cls || clear");
    printf("-------------------------Editar Jogador---------------------------\n");
    printf("-> Digite a ID do jogador: ");
    
    do{
        scanf("%d", &ID); //Receber a ID do jogador que deseja editar
        if(ID < 1 || ID > 5){
            printf("-> ID nao encontrada, digite uma ID valida!\n");
        }else{
            for(int i = 0; i < *quant_partidas; i++){ //Laço para descobrir a soma total do jogador solicitado
                pont_total += partidas[i].jogadores_partida[ID - 1].pontuacao_jogador;
            }
            printf("--------------------------\n");
            printf("-> ID: %d \n", time->jogadores[ID - 1].id);
            printf("-> Nome: %s \n", time->jogadores[ID - 1].nome);
            printf("-> Posicao: %s \n", time->jogadores[ID -1].posicao);
            printf("-> Pontuacao: %d \n", pont_total);
            printf("--------------------------\n");
        }
    }while (ID <= 0 || ID >5);
    //Após isso vai solicitar se tem certeza e solicitar as informações e refazer a validação para o novo jogador
    printf("-> Deseja mesmo editar esta posicao? (Digite 1 para sim e 0 para nao)");
    do{
        scanf("%d", &certeza);
        if(certeza != 0 && certeza != 1){
            printf("-> Opcao invalida, digite 1 para sim e 0 para nao!");
        }else if(certeza == 1){
            system("cls || clear");
            printf("-------------------------Editar Jogador---------------------------\n");
            time->jogadores[ID-1].id = ID;
            printf("-> Digite o nome do novo jogador: ");
            getchar();
            scanf("%[^\n]s", time->jogadores[ID - 1].nome);
            printf("-> Digite a posicao do novo jogador:");
            do{
                getchar();
                scanf("%[^\n]s", time->jogadores[ID - 1].posicao);
                if(strcmp(time->jogadores[ID - 1].posicao, "TOP") != 0 && strcmp(time->jogadores[ID - 1].posicao, "MID") != 0 && strcmp(time->jogadores[ID - 1].posicao, "JG") != 0 && strcmp(time->jogadores[ID - 1].posicao, "ADC") != 0 && strcmp(time->jogadores[ID - 1].posicao, "SUP") != 0){
                    printf("-> Opcao invalida\n");
                }
            }while(strcmp(time->jogadores[ID - 1].posicao, "TOP") != 0 && strcmp(time->jogadores[ID - 1].posicao, "MID") != 0 && strcmp(time->jogadores[ID - 1].posicao, "JG") != 0 && strcmp(time->jogadores[ID - 1].posicao, "ADC") != 0 && strcmp(time->jogadores[ID - 1].posicao, "SUP") != 0);
            printf("-> Digite a idade do novo jogador:");
            do{
                getchar();
                scanf("%d", &time->jogadores[ID - 1].idade);
                if(time->jogadores[ID - 1].idade <=0 || time->jogadores[ID - 1].idade > 150){
                    printf("-> Digite uma idade valida!");
                }
            }while(time->jogadores[ID - 1].idade <=0 || time->jogadores[ID -1].idade >150);
        }else if(certeza == 0){
            system("cls || clear");
            printf("-> Okay! \n");
        }
    }while(certeza != 0 && certeza != 1);
    retorna_menu();
}

//Função feita para cadastrar uma partida
void cadastrar_partida(Partida *partidas, int *quant_partidas){
    system("cls || clear");
    printf("--------------------Cadastro de partida---------------------\n");
    for(int i = 0; i < 5; i++){ //Laço feito para receber informação de cada jogador
        partidas[*quant_partidas].jogadores_partida[i].id_jogador = i + 1;
        printf("ID: %d\n", partidas[*quant_partidas].jogadores_partida[i].id_jogador);
        printf("-> Numero de kills: ");
        scanf("%d", &partidas[*quant_partidas].jogadores_partida[i].num_kills);
        printf("-> Numero de assistencias: ");
        scanf("%d", &partidas[*quant_partidas].jogadores_partida[i].num_assistencias);
        printf("-> Numero de deaths: ");
        scanf("%d", &partidas[*quant_partidas].jogadores_partida[i].num_deaths);
        printf("------------------------------\n");
        //Aqui foram feitas algumas operações para facilitar o restante do código
        partidas[*quant_partidas].total_kills_time += partidas[*quant_partidas].jogadores_partida[i].num_kills;
        partidas[*quant_partidas].total_kills_adversario += partidas[*quant_partidas].jogadores_partida[i].num_deaths;
        partidas[*quant_partidas].jogadores_partida[i].pontuacao_jogador = (partidas[*quant_partidas].jogadores_partida[i].num_kills * 3) + partidas[*quant_partidas].jogadores_partida[i].num_assistencias;
        partidas[*quant_partidas].jogadores_partida[i].pontuacao_total_jogador += (partidas[*quant_partidas].jogadores_partida[i].num_kills * 3) + partidas[*quant_partidas].jogadores_partida[i].num_assistencias;
    }
    printf("-> Digite o numero de torres destruidas pelo seu time: ");
    //Algumas validações importantes
    do{
        scanf("%d", &partidas[*quant_partidas].total_torres_destruidas_time);
        if(partidas[*quant_partidas].total_torres_destruidas_time < 0 || partidas[*quant_partidas].total_torres_destruidas_time > 11){
            printf("-> Numero de torres invalido! Digite um numero entre 0 e 11:");
        }
    } while (partidas[*quant_partidas].total_torres_destruidas_time < 0 || partidas[*quant_partidas].total_torres_destruidas_time >11);
    printf("-> Digite o numero de torres destruidas pelo time adversario: ");
    do{
        scanf("%d", &partidas[*quant_partidas].total_torres_destruidas_adversario);
        if(partidas[*quant_partidas].total_torres_destruidas_adversario < 0 || partidas[*quant_partidas].total_torres_destruidas_adversario > 11){
            printf("-> Numero de torres invalido! Digite um numero entre 0 e 11:");
        }
    } while (partidas[*quant_partidas].total_torres_destruidas_adversario < 0 || partidas[*quant_partidas].total_torres_destruidas_adversario >11);
    printf("-> Digite 1 se seu time venceu a partida ou 0 se seu time perdeu:");
    do{
        scanf("%d", &partidas[*quant_partidas].decisao);  
        if(partidas[*quant_partidas].decisao != 1 && partidas[*quant_partidas].decisao != 0){
            printf("-> Digite uma opcao valida!! (1 se seu time venceu e 0 se seu time perdeu\n");
        }
    } while (partidas[*quant_partidas].decisao != 1 && partidas[*quant_partidas].decisao != 0);
        
    (*quant_partidas)++;
        
    retorna_menu();
}

//Função feita para listar as partidas cadastradas
void listar_partidas(Time *time, Partida *partidas, int *quant_partidas){
    system("cls || clear");
    for(int i = 0; i < *quant_partidas; i++){

        printf("--------------------Partida %d------------------ \n", i + 1);
        printf("-> Resultado: \n");
        if (partidas[i].decisao == 1){
            printf("-> %s: Vitoria\n", time->nome_time);
            printf("-> Adversario: Derrota\n");
        }else if(partidas[i].decisao == 0){
            printf("-> %s: Derrota\n", time->nome_time);
            printf("-> Adversario: Vitoria\n");
        }
        
        printf("Numero de kills do time: %d\n", partidas[i].total_kills_time);
        printf("Numero de kills do time adversario: %d\n", partidas[i].total_kills_adversario);
        printf("Numero de torres destruídas pelo time: %d\n", partidas[i].total_torres_destruidas_time);
        printf("Numero de torres destruídas pelo time adversario: %d\n", partidas[i].total_torres_destruidas_adversario);
        int bigger = 0;// Declaração para zerar o valor sempre que chegar aqui
        for(int j = 0; j < 5; j++){//Esse laço serve pare definir o jogador que foi o destaque da partida
            if(partidas[i].jogadores_partida[j].pontuacao_jogador > bigger){
                bigger = partidas[i].jogadores_partida[j].pontuacao_jogador;
                strcpy(partidas[i].posicao_destaque, time->jogadores[j].posicao);
                strcpy(partidas[i].nome_destaque, time->jogadores[j].nome);
            }
        }
        printf("-> Destaque: %s - %s - %d \n", partidas[i].nome_destaque, partidas[i].posicao_destaque, bigger);

    }
    printf("-------------------------------------------------\n");
    retorna_menu();
}

//Funcao para pesquisar jogador
void pesquisa_jogador(Time *time, Partida *partidas, int *quant_partidas){
    
    int pont_total = 0;
    int ID;
    system("cls || clear");
    printf("----------------Pesquisar Jogador-----------------\n");
    printf("-> Digite a ID do jogador: ");
    scanf("%d", &ID);
        if(ID < 1 || ID > 5){    //if usado para saber se o jogador existe ou nao
            printf("-> Jogador nao encontrado\n");
        }else{
            for(int i = 0; i < *quant_partidas; i++){ //Laço para descobrir a soma total do jogador solicitado
                pont_total += partidas[i].jogadores_partida[ID - 1].pontuacao_jogador;
            }
            printf("-> ID: %d\n", time->jogadores[ID - 1].id);
            printf("-> Nome: %s\n", time->jogadores[ID - 1].nome);
            printf("-> Posicao: %s\n", time->jogadores[ID - 1].posicao);
            printf("-> Idade: %d\n", time->jogadores[ID - 1].idade);
            printf("-> Pontuacao total: %d\n", pont_total);
        }
    retorna_menu();
}

//Funcao para somar as kills e assistencias
void soma_kill(Partida *partidas, int *quant_partidas){
    int soma = 0;
    system("cls || clear");
    printf("--Soma de kills e assistencias totais do time--\n");
    for(int i = 0; i < *quant_partidas; i ++){  //For utilizado para realizar a soma de kills e assistencias do time
        for(int j = 0; j < 5; j++){
            soma += partidas[i].jogadores_partida[j].num_kills + partidas[i].jogadores_partida[j].num_assistencias;
        }
    }
    printf("-> A soma total de kill e assistencias eh: %d\n", soma);
    retorna_menu();
}

//Funcao para mostrar o jogador com menor pontuacao da partida
void pior_partida(Time *time, Partida *partidas, int *quant_partidas){
    int LVP, pont_total_LVP[5] = {0}, idade_LVP, ID_LVP;
    system("cls || clear");
    printf("-------Jogador com Pior Pontuacao do Time-------\n");
    
    for (int i = 0; i < *quant_partidas; i++){  //Solucao encontrada para fazer a pontucao total dos jogadores
        pont_total_LVP[0] += partidas[i].jogadores_partida[0].pontuacao_total_jogador;
        pont_total_LVP[1] += partidas[i].jogadores_partida[1].pontuacao_total_jogador;
        pont_total_LVP[2] += partidas[i].jogadores_partida[2].pontuacao_total_jogador;
        pont_total_LVP[3] += partidas[i].jogadores_partida[3].pontuacao_total_jogador;
        pont_total_LVP[4] += partidas[i].jogadores_partida[4].pontuacao_total_jogador;
        LVP = 99999;
        for (int j = 0; j < 5; j++){
            if (pont_total_LVP[j] < LVP){
                LVP = pont_total_LVP[j];
                ID_LVP = time->jogadores[j].id;
                idade_LVP = time->jogadores[j].idade;
                strcpy(time->nome_LVP, time->jogadores[j].nome);
                strcpy(time->Pos_LVP, time->jogadores[j].posicao);
            }
            
        }
    }
    printf("-> ID: %d\n", ID_LVP);
    printf("-> Nome: %s\n", time->nome_LVP);
    printf("-> Idade: %d\n", idade_LVP);
    printf("-> Posicao: %s\n", time->Pos_LVP);
    printf("-> Pontuacao: %d\n", LVP);
    retorna_menu();
}

//Funcao para declarar o melhor jogador
void MVP_partida(Time *time, Partida *partidas, int *quant_partidas){
    int MVP, pont_total_MVP[5] = {0}, idade_MVP, ID_MVP;
    system("cls || clear");
    printf("----------------MVP do Time--------------\n");
    
    for (int i = 0; i < *quant_partidas; i++){  //Solucao encontrada para fazer a pontucao total dos jogadores
        pont_total_MVP[0] += partidas[i].jogadores_partida[0].pontuacao_total_jogador;
        pont_total_MVP[1] += partidas[i].jogadores_partida[1].pontuacao_total_jogador;
        pont_total_MVP[2] += partidas[i].jogadores_partida[2].pontuacao_total_jogador;
        pont_total_MVP[3] += partidas[i].jogadores_partida[3].pontuacao_total_jogador;
        pont_total_MVP[4] += partidas[i].jogadores_partida[4].pontuacao_total_jogador;
        MVP = 0;
        for (int j = 0; j < 5; j++){
            if (pont_total_MVP[j] > MVP){
                MVP = pont_total_MVP[j];
                ID_MVP = time->jogadores[j].id;
                idade_MVP = time->jogadores[j].idade;
                strcpy(time->nome_MVP, time->jogadores[j].nome);
                strcpy(time->Pos_MVP, time->jogadores[j].posicao);
            }
            
        }
    }
    printf("-> ID: %d\n", ID_MVP);
    printf("-> Nome: %s\n", time->nome_MVP);
    printf("-> Idade: %d\n", idade_MVP);
    printf("-> Posicao: %s\n", time->Pos_MVP);
    printf("-> Pontuacao: %d\n", MVP);
    retorna_menu();

}

void retorna_menu(){
    printf("-> Aperte enter para retornar ao menu...");
    getchar();
    getchar();  
}