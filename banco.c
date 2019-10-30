#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <windows.h>

#define MAXCLIENTES 10000 /* Macro que facilita a alteração do número máximo de clientes */

/* Struct que armazena dados dos clientes */

  struct Dados{

    char nome[40],
         senha[10],
         conta[5],
         saldo[10];

  };

  struct Dados user;

  /* Struct para armazenar dados de transações */

  struct Transacao{

    double valor;

    char data[10];

  } transf;

/* Ponteiros para abrir arquivos */

  FILE *cadastro,
       *tranferencia;

/* Protótipos das funções */

  void menu(int opcao, char pedesenha[7], char senhadeauto[7], char confirmar[10], char nome[40]);
  void cadastrar(int opcao, char senhadeauto[7], char pedesenha[7], char confirmar[10], char nome[40]);
  void pesquisar(char pedesenha[7],char confirmar[10], char senhadeauto[7], int opcao, char nome[40]);
  void transacao();
  void ordenar();
  void listar(int opcao, char pedesenha[7], char senhadeauto[7], char confirmar[10], char nome[40]);

  void pedirsenha();

  void gotoxy(int x, int y);

int main() {


  /* Configurações de tela */

  /* Troca das cores de fundo e de texto */

  system("color f0");

  /* Declaração de variáveis */

    char confirmar[10],
         senhadeauto[7],
         pedesenha[7],
         nome[40];

    int clientes[MAXCLIENTES],
        numdecadastros = 0,
        opcao,
        y;

  /* Atribuições */

  strcpy(senhadeauto, "34159");

  /* Deixar o prompt em tela cheia (COMANDOS SÓ FUNCIONAM PARA WINDOWS) */

  system("MODE con cols=168 lines=60");

  /* Dando título à barra de títulos para substituir endereço do diretório*/

  system("title Cadastro Bancario");

  /* Chamada do menu para iniciar o programa */

  menu(opcao, pedesenha, senhadeauto, confirmar, nome);

  return 0;

}

void menu(int opcao, char pedesenha[7], char senhadeauto[7], char confirmar[10], char nome[40]){

  int i;

  system("cls");

  /* Chamada de função para centralizar teto */

  gotoxy(50,14);

  /* for para imprimir parte do menu */

  printf("%c", 201);

  for(i=0 ; i < 70 ; i++){

    printf("%c", 205);

  }

  printf("%c\n", 187);
  gotoxy(50,15);
  printf("%c                                                                      %c\n", 186, 186);
  gotoxy(50,16);
  printf("%c                            BANCO UPE                                 %c\n", 186, 186);
  gotoxy(50,17);
  printf("%c                                                                      %c\n", 186, 186);
  gotoxy(50,18);
  printf("%c                  ESCOLHA UMA DAS OPCOES ABAIXO                       %c\n", 186, 186);
  gotoxy(50,19);
  printf("%c                                                                      %c\n", 186, 186);
  gotoxy(50,20);
  printf("%c                         1) CADASTRAR                                 %c\n", 186, 186);
  gotoxy(50,21);
  printf("%c                         2) PESQUISAR                                 %c\n", 186, 186);
  gotoxy(50,22);
  printf("%c                       3) TRANSFERENCIA                               %c\n", 186, 186);
  gotoxy(50,23);
  printf("%c                          4) ORDENAR                                  %c\n", 186, 186);
  gotoxy(50,24);
  printf("%c                          5) LISTAR                                   %c\n", 186, 186);
  gotoxy(50,25);
  printf("%c                           6) SAIR                                    %c\n", 186, 186);
  gotoxy(50,26);
  printf("%c                                                                      %c\n", 186, 186);
  gotoxy(50,27);
  printf("%c", 200);

  for(i=0 ; i < 70 ; i++){

    printf("%c", 205);

  }

    printf("%c\n\n", 188);

  scanf("%d", &opcao);

  switch (opcao) {

    case 1:

       cadastrar(opcao, senhadeauto, pedesenha, confirmar, nome);

    break;

    case 2:

      pesquisar(pedesenha, confirmar, senhadeauto, opcao, nome);

    break;

    case 3:

      transacao();

    break;

    case 4:

      ordenar();

    break;

    case 5:

      listar(opcao, pedesenha, senhadeauto, confirmar, nome);

    break;

    case 6:

      exit(0);

    break;
  }

}

/* Função para centralizar textos na tela */

void gotoxy(int x, int y){

  HANDLE mover;
  COORD coordenadas;

  mover = GetStdHandle(STD_OUTPUT_HANDLE);
  coordenadas.X = x;
  coordenadas.Y = y;

  SetConsoleCursorPosition(mover, coordenadas);

}

void cadastrar(int opcao, char senhadeauto[7], char pedesenha[7], char confirmar[10], char nome[40]){

  // Declarações

  int conta,
      comp,
      i;

  // Instruções

  system("cls");

  gotoxy(50,1);

  printf("%c", 201);

  for(i=0 ; i < 70 ; i++){

    printf("%c", 205);

  }

  printf("%c\n", 187);

  gotoxy(50,2);
  printf("%c                                                                      %c\n", 186, 186);
  gotoxy(50,3);
  printf("%c                            BANCO UPE                                 %c\n", 186, 186);
  gotoxy(50,4);
  printf("%c                                                                      %c\n", 186, 186);
  gotoxy(50,5);
  printf("%c                             CADASTRO                                 %c\n", 186, 186);
  gotoxy(50,6);
  printf("%c                                                                      %c\n", 186, 186);
  gotoxy(50,7);
  printf("%c", 200);

  for(i=0 ; i < 70 ; i++){

    printf("%c", 205);

  }

  printf("%c", 188);

  gotoxy(50,10);

  puts(senhadeauto);

  printf("          POR FAVOR, INSIRA A SENHA DE AUTORIZACAO DE ACESSO:           \n");

  scanf("%s", pedesenha);

  puts(pedesenha);

  printf("> %d", strcmp(pedesenha, senhadeauto));

  //comp = strcmp(senhadeauto, pedesenha);

  if (strcmp(senhadeauto, pedesenha) != 0){

  //  system("cls");

    printf("********************************************************************\n");
    printf("*                                                                  *\n");
    printf("*                           ACESSO NEGADO                          *\n");
    printf("*                                                                  *\n");
    printf("********************************************************************\n\n\n");

    system("PAUSE");

    printf("\nDESEJA VOLTAR AO MENU?\n\n\n");
    printf("1) SIM\n");
    printf("2) NAO\n\n");

    scanf("%i", &opcao);

    if(opcao == 1){

      menu(opcao, pedesenha, senhadeauto, confirmar, nome);

    } else {

      exit(0);

    }

  } else {

  printf("\n\nINSIRA O NOME DO CLIENTE:\n");

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

      printf("QUAL EH O SALDO INICIAL DO CLIENTE?\n\nFormato xxx.xx\n\n");
      fflush(stdin);
      gets(user.saldo);

      cadastro = fopen("cadastro.txt", "a");

      /* Sorteio do numero da conta */

      srand(time(NULL));

      conta = rand()%MAXCLIENTES;

      itoa(conta, user.conta, 10);

      printf("O NUMERO DA CONTA DE %s SERA: %s\t \n\n", user.nome, user.conta);

      /* Salvando os dados do cliente em arquivo */

      cadastro = fopen("cadastro.txt", "a");

      fwrite(&user, sizeof(struct Dados), 1, cadastro);

      fclose(cadastro);

      system("PAUSE");
      system("cls");

      printf("CADASTRO REALIZADO COM SUCESSO\n\n");
      printf("DESEJA REALIZAR MAIS ALGUMA ACAO?\n\n");

      printf("1) SIM\n");
      printf("2) NAO\n\n");

      fflush(stdin);
      scanf("%i", &opcao);

      if(opcao == 1){

        menu(opcao, pedesenha, senhadeauto, confirmar, nome);

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

      cadastrar(opcao, senhadeauto, pedesenha, confirmar, nome);

    } else {

      exit(0);

    }

  }

}

}

void pesquisar(char pedesenha[7], char confirmar[10], char senhadeauto[7], int opcao, char nome[40]){

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

      menu(opcao, pedesenha, senhadeauto, confirmar,nome);

    } else {

      exit(0);

    }

  } else {

    system("cls");

    printf("INSIRA O NOME DO CLIENTE\n\n");

    fflush(stdin);
    gets(nome);

    cadastro = fopen("cadastro.txt", "r");

    while (fread(&user, sizeof(struct Dados), 1, cadastro)) {

      if(nome == user.nome){

        printf("\n\nCADASTRO ENCONTRADO\n");

      } else {

        printf("\n\nCADASTRO NAO ENCONTRADO\n");

      }

    }

    fclose(cadastro);

    printf("DESEJA REALIZAR MAIS ALGUMA ACAO?\n\n");

    printf("1) SIM\n");
    printf("2) NAO\n\n");

    fflush(stdin);
    scanf("%i", &opcao);

    if(opcao == 1){

      menu(opcao, pedesenha, senhadeauto, confirmar,nome);

    } else {

      exit(0);

    }

    }

  }


void transacao(){


}

void ordenar(){



}

void listar(int opcao, char pedesenha[7], char senhadeauto[7], char confirmar[10], char nome[40]){

  system("cls");

  printf("********************************************************************\n\n");
  printf("*                          BANCO DO UPE                            *\n\n");
  printf("*                          LISTAR CONTAS                           *\n\n");
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

      menu(opcao, pedesenha, senhadeauto, confirmar, nome);

    } else {

      exit(0);

    }

  } else {

    system("cls");

    cadastro = fopen("cadastro.txt", "r");

    while(fread(&user, sizeof(struct Dados), 1, cadastro)) {

      printf("\n");
      printf("NOME:%s\n", user.nome);
      printf("SENHA: %s\n", user.senha);
      printf("NUMERO DA CONTA:%s\n", user.conta);
      printf("SALDO:%s\n", user.saldo);
      printf("-------------------------\n");

    }

    fclose(cadastro);

}

}
