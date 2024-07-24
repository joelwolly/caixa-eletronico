#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#ifdef _WIN32
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif

#define cabecTexto "################################################################################################"

void comprovante_funcao(char nome[], float renda, float renda_dif, int opcao);

// Função de debug para checar se os dados estão corretos
void debug(char nome[], char nome_usuario[], char senha[], char senha_usuario[], float renda, float renda_dif, int D_ou_S) {
    printf(cabecTexto);
    printf("\n\n# Nome: %s\n", nome);
    printf("# Renda: %.2f\n", renda);
    printf("# Senha: %s\n", senha);
    printf("# Nome de usuário: %s\n", nome_usuario);
    printf("# Senha de usuário: %s\n", senha_usuario);
    printf("# Renda Diferenca: %.2f\n", renda_dif);
    printf("# Deposito ou Saque: %d", D_ou_S);
    
    printf("\n" cabecTexto);
}

// Função de cadastro
float cadastro(char nome[], char senha[], float renda) {
    
    bool senha_correta = false;
    
    printf("# Digite seu nome completo: \n\n");
    printf("--> ");
    scanf(" %[^\n]", nome);  // Leitura do nome completo, incluindo espaços
    system(CLEAR);
    printf("\n# Digite seu salário: \n\n");
    printf("--> ");
    scanf("%f", &renda);  // Leitura da renda
    system(CLEAR);
    while(senha_correta == false){
        printf("\n# Digite a sua senha (até 8 caracteres): \n\n");
        printf("--> ");
        scanf("%8s", senha);  // Leitura da senha com no máximo 8 caracteres
        
        if(strlen(senha) > 8) {
            printf("\n\a• A senha não pode ter mais de 8 caracteres. Tente novamente.\n\n");
        } else {
            senha_correta = true;
        }
    }
    system(CLEAR);
    printf("\n\a• Cadastro realizado com sucesso!\n\n");
   
    return renda;
}

// Função de login
void logar(int comparacao, char nome[], char nome_usuario[], char senha[], char senha_usuario[], int *opcao, float *renda, float *renda_dif) {
    int fechar, fechar2, comprovante = 0;
    fechar = 0;
    int tentativas = 4;

    system(CLEAR);
    printf("\n# Para fazer seu login, digite seu nome: \n\n");
    printf("--> ");
    scanf(" %[^\n]", nome_usuario);
    system(CLEAR);
    comparacao = strcmp(nome_usuario, nome);

    if (comparacao == 0) {
        printf("\a\n• Nome correto.\n\n");
        printf("# Digite a senha: \n");
        while (tentativas > 0 && fechar == 0) {
            printf("\n--> ");
            scanf(" %[^\n]", senha_usuario);
            system(CLEAR);
            comparacao = strcmp(senha_usuario, senha);
            if (comparacao == 0) {
                printf("\a\n» Senha correta!\n\n");
                printf(cabecTexto);
                printf("\n\n• Deseja depositar ou sacar dinheiro?\n\n");
                printf("1. Depositar\n2. Sacar\n");
                printf("\n--> ");
                scanf("%d", &*opcao);
                
                system(CLEAR);

                switch (*opcao) {
                    case 1:
                        printf("\nQuanto deseja depositar?\n");
                        printf("\n--> ");
                        scanf("%f", renda_dif);
                        system(CLEAR);
                        *renda += *renda_dif;
                        printf("\n\a• Depósito concluído com sucesso!\n\n");
                      
                        printf("\nDeseja imprimir o comprovante?\n");
                        printf("\n 1 - sim\n 2 - não\n");
                        printf("\n--> ");
                        scanf("%d", &comprovante);
                        if(comprovante == 1){
                            comprovante_funcao(nome, *renda, *renda_dif, *opcao);
                            
                        }else if(comprovante == 2){
                            printf("\nOk, Obrigado por utilizar nosso Banco!");
                        }else{
                            printf("\nOpção invalida!\n");
                        
                        
                }
                
                        fechar = 1;
                        break;
                    case 2:
                        printf("\n• Quanto deseja sacar?\n");
                        printf("\n--> ");
                        scanf("%f", renda_dif);
                        system(CLEAR);
                        if (*renda < *renda_dif) {
                            printf("Renda insuficiente, digite a senha novamente!\n");
                        } else {
                            *renda -= *renda_dif;
                            printf("\n\a• Saque concluído com sucesso!\n\n");
                            
                            printf("\nDeseja imprimir o comprovante?\n");
                            printf("\n 1 - sim\n 2 - não\n");
                            printf("\n--> ");
                            scanf("%d", &comprovante);
                            if(comprovante == 1){
                              comprovante_funcao(nome, *renda, *renda_dif, *op
