#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>

#define MAXCLIENTES 10000

  struct dados{

    char nome[40],
         senha[10],
         conta[5],
         saldoconta[5];

  } user;

  char buffer[40],
       confirmar[10],
       numconta[6];

  int clientes[MAXCLIENTES],
      numdecadastros = 0;

  FILE *cadastro;

  char senhadeauto[5] = "34159",
       pedesenha[5],
       nome[40];

  void menu();
  void cadastrar();
  void pesquisar();
  void transacao();
  void ordenar();
  void listar();

  void pedirsenha();

  int opcao;

int main() {

  menu();

  return 0;
}

void menu(){

  system("cls");

  printf("********************************************************************\n");
  printf("\t\tBANCO DO UPE\n");
  printf("\t\tESCOLHA UMA DAS OPCOES ABAIXO\n\n");
  printf("\t\t1) CADASTRAR\n");
  printf("\t\t2) PESQUISAR\n");
  printf("\t\t3) TRANSAÇÃO\n");
  printf("\t\t4) ORDENAR\n");
  printf("\t\t5) LISTAR\n");
  printf("\t\t6) SAIR\n\n");
  printf("********************************************************************\n");

  scanf("%d", &opcao);

  switch (opcao) {

    case 1:

      cadastrar();

    break;

    case 2:

      pesquisar();

    break;

    case 3:

      transacao();

    break;

    case 4:

      ordenar();

    break;

    case 5:

      listar();

    break;

    case 6:

      exit(0);

    break;
  }

}

void cadastrar(){

  // Declarações

  int conta;

  // Instruções

  system("cls");

  printf("********************************************************************\n*\n");
  printf("*                       BANCO DO UPE                               *\n*\n");
  printf("*                         CADASTRO                                 *\n*\n");
  printf("********************************************************************\n\n\n\n");


  printf("\n\nPOR FAVOR, INSIRA O NOME DO CLIENTE:\n");

  fflush(stdin);
  gets(user.nome);

  printf("\n\n");
  printf("DEIXE QUE %s ESCOLHA UMA SENHA DE ATE 10 CARACTERES\n\n", user.nome);

  gets(user.senha);

  printf("\n\n");

  /* Confirmar senha */

  printf("CONFIRME A SENHA, POR FAVOR\n\n");

  gets(confirmar);

  printf("\n\n");

  /* Comparar senhas antes de continuar */

  if(strcmp(confirmar, user.senha) == 0){

    /* Confirmar informações antes de escrever em arquivo */

    system("cls");
    printf("DESEJA CONTINUAR COM AS SEGUINTES INFORMACOES?\n\n");
    printf("NOME: %s\n", user.nome);
    printf("SENHA: %s\n\n", user.senha);
    printf("1) SIM\n");
    printf("2) NAO\n\n");

    scanf("%i", &opcao);

    if(opcao == 1){

      printf("QUAL EH O SALDO INICIAL DO CLIENTE?\n\n");
      gets(user.saldoconta);

      cadastro = fopen("cadastro.txt", "a");

      /* Sorteio do numero da conta */

      srand(time(NULL));

      conta = rand()%MAXCLIENTES;

      itoa(conta, user.conta, 10);

      printf("O NUMERO DA CONTA DE %s SERA: %s\t \n\n", user.nome, user.conta);

      /* Salvando os dados do cliente em arquivo */

      cadastro = fopen("cadastro.txt", "a");

      fwrite(&user, sizeof(struct dados), 1, cadastro);

      fclose(cadastro);

      printf("CADASTRO REALIZADO COM SUCESSO\n\n");
      printf("DESEJA REALIZAR MAIS ALGUMA ACAO?\n\n");

      printf("1) SIM\n");
      printf("2) NAO\n\n");

      fflush(stdin);
      scanf("%i", &opcao);

      if(opcao == 1){

        menu();

      } else {

        exit(0);

      }


    }

  } else {

    printf("AS SENHAS NAO CONFEREM, POR FAVOR, REDEFINA-AS\n");
    printf("DESEJA TENTAR NOVAMENTE?\n\n");

    printf("1) SIM\n");
    printf("2) NAO\n\n");

    scanf("%i", &opcao);

    if(opcao == 1){

      cadastrar();

    } else {

      exit(0);

    }

  }

}

void pesquisar(){

  // Instruções

  system("cls");

  printf("********************************************************************\n\n");
  printf("*                          BANCO DO UPE                            *\n\n");
  printf("*                        PESQUISAR CONTAS                          *\n\n");
  printf("********************************************************************\n\n\n\n");
  printf("POR FAVOR, INSIRA A SENHA DE AUTORIZACAO DE ACESSO:\n");

  fflush(stdin);
  gets(pedesenha);

  if(strcmp(pedesenha, senhadeauto) != 0){

    system("cls");

    printf("********************************************************************\n\n");
    printf("*                           ACESSO NEGADO                          *\n\n\n");
    printf("********************************************************************\n\n\n");
    printf("\nDESEJA VOLTAR AO MENU?\n\n\n");
    printf("1) SIM\n");
    printf("2) NAO\n\n");

    scanf("%i", &opcao);

    if(opcao == 1){

      menu();

    } else {

      exit(0);

    }

  } else {

    printf("INSIRA O NOME DO CLIENTE\n\n");
    fflush(stdin);
    gets(nome);

    cadastro = fopen("cadastro.txt", "a+");

    strcpy(buffer, "");

    while (fread(&user, sizeof(struct dados), 1, cadastro)) {

      if(nome == user.nome){

        printf("\n\nCADASTRO ENCONTRADO\n");

      } else {

        printf("\n\nCADASTRO NAO ENCONTRADO\n");

      }

    }

    fclose(cadastro);

    }

  }


void transacao(){


}

void ordenar(){

}

void listar(){

  system("cls");

  printf("********************************************************************\n\n");
  printf("*                          BANCO DO UPE                            *\n\n");
  printf("*                        PESQUISAR CONTAS                          *\n\n");
  printf("********************************************************************\n\n\n\n");
  printf("POR FAVOR, INSIRA A SENHA DE AUTORIZACAO DE ACESSO:\n");

  fflush(stdin);
  gets(pedesenha);

  if(strcmp(pedesenha, senhadeauto) != 0){

    system("cls");

    printf("********************************************************************\n\n");
    printf("*                           ACESSO NEGADO                          *\n\n\n");
    printf("********************************************************************\n\n\n");
    printf("\nDESEJA VOLTAR AO MENU?\n\n\n");
    printf("1) SIM\n");
    printf("2) NAO\n\n");

    scanf("%i", &opcao);

    if(opcao == 1){

      menu();

    } else {

      exit(0);

    }

  } else {

    cadastro = fopen("cadastro.txt", "r");

    while (fread(&user, sizeof(struct dados), 1, cadastro)) {

      printf("\n\n");
      printf("NOME: %s\n", user.nome);
      printf("SENHA: %s\n", user.senha);
      printf("NUMERO DA CONTA:\n", user.conta);
      printf("-------------------------\n");

    }

    fclose(cadastro);

}

}
