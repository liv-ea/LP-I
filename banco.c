#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>

#define MAXCLIENTES 10000

struct dados{

  char senha[10],
       confirmar[10],
       nome[40],
       numconta[6];

  float saldo;

  int conta,
      endereco;

} user;

int clientes[MAXCLIENTES],
    numdecadastros = 0;

FILE *cadastro;

char senhadeauto[5] = "34159",
     pedesenha[5],
     nome[40];;

void menu();
void cadastrar();
void pesquisar();
void transacao();
void ordenar();
void listar();

void sortearconta();
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

  int i;

  system("cls");

  printf("********************************************************************\n\n");
  printf("\t\tBANCO DO UPE\n\n");
  printf("\t\tCADASTRO\n\n");
  printf("********************************************************************\n\n\n\n");
  printf("POR FAVOR, INSIRA O NOME DO CLIENTE:\n");
  fflush(stdin);
  gets(user.nome);
  printf("\n\n");

  printf("OK, %s. DEIXE QUE ELX ESCOLHA UMA SENHA DE ATE 10 CARACTERES\n\n", user.nome);
  gets(user.senha);
  printf("\n\n");

  /* Confirmar senha */

  printf("CONFIRME A SENHA, POR FAVOR\n\n");
  gets(user.confirmar);
  printf("\n\n");

  /* Comparar senhas antes de continuar */

  if(strcmp(user.confirmar, user.senha) == 0){

    /* Confirmar informações antes de escrever em arquivo */

    system("cls");
    printf("DESEJA CONTINUAR COM AS SEGUINTES INFORMACOES?\n\n");
    printf("NOME: %s\n", user.nome);
    printf("SENHA: %s\n\n", user.senha);
    printf("1) SIM\n");
    printf("2) NAO\n\n");

    scanf("%i", &opcao);

    if(opcao == 1){

      /* Escreve o nome e a senha do cliente em arquivo */

      cadastro = fopen("cadastro.txt", "a");

      fprintf(cadastro, "%s\n", user.nome);

      fprintf(cadastro, "%s\n", user.senha);

      fclose(cadastro);

      sortearconta();

      printf("%s O NUMERO DA SUA CONTA SERA: %d\t \n\n", user.nome, user.conta);

      /* Número da conta em arquivo */

      cadastro = fopen("cadastro.txt", "a");

      fprintf(cadastro, "%d\n", user.conta);

      fclose(cadastro);

      printf("CADASTRO REALIZADO COM SUCESSO\n\n");
      printf("DESEJA REALIZAR MAIS ALGUMA ACAO?\n\n");

      printf("1) SIM\n");
      printf("2) NAO\n\n");

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

  system("cls");

  printf("********************************************************************\n\n");
  printf("\t\tBANCO DO UPE\n\n");
  printf("\t\tPESQUISAR CONTAS\n\n");
  printf("********************************************************************\n\n\n\n");
  printf("POR FAVOR, INSIRA A SENHA DE AUTORIZACAO DE ACESSO:\n");

  fflush(stdin);
  gets(pedesenha);

  if(strcmp(pedesenha, senhadeauto) != 0){

    system("cls");

    printf("********************************************************************\n\n");
    printf("ACESSO NEGADO\n\n\n");
    printf("********************************************************************\n\n\n");
    printf("\nDESEJA VOLTAR AO MENU?\n\n");
    printf("1) SIM\n");
    printf("2) NAO\n\n");

    scanf("%i", &opcao);

    if(opcao == 1){

      menu();

    } else {

      exit(0);

    }

  } else {

    printf("INSIRA O NOME DO CLIENTE\n");
    fflush(stdin);
    gets(nome);

    cadastro = fopen("cadastro.txt", "a+");

    while (!feof(cadastro)) {

      fgets(nome, sizeof(nome), cadastro);
      nome[strlen(nome)-1]='\0';

    }

    if(strcmp(nome, user.nome) == 0){

      printf("CLIENTE %s ENCONTRADO\n", nome);

    } else {

      printf("O CLIENTE %s NÃO ESTÁ CADASTRADO\n", nome);

    }

    fclose(cadastro);

    }

  }


void transacao(){

  // Declarações

}

void ordenar(){

}

void listar(){

  system("cls");

  printf("********************************************************************\n\n");
  printf("\t\tBANCO DO UPE\n\n");
  printf("\t\tLISTAR CONTAS\n\n");
  printf("********************************************************************\n\n\n\n");
  printf("POR FAVOR, INSIRA A SENHA DE AUTORIZACAO DE ACESSO:\n");

  fflush(stdin);
  gets(pedesenha);

  if(strcmp(pedesenha, senhadeauto) != 0){

    system("cls");

    printf("********************************************************************\n\n");
    printf("ACESSO NEGADO\n\n\n");
    printf("********************************************************************\n\n\n");
    printf("\nDESEJA VOLTAR AO MENU?\n\n");
    printf("1) SIM\n");
    printf("2) NAO\n\n");

    scanf("%i", &opcao);

    if(opcao == 1){

      menu();

    } else {

      exit(0);

    }

  } else {



      while (fread(&user, sizeof(struct dados), 1, cadastro)) {
        printf("NOME %s\n", );
      }

  }

}

void sortearconta(){


  char comparar[11];

  /* Usando tempo como semente para que os números das contas não se repitam */

  srand(time(NULL));

  /* Sorteio do número da conta */

  user.conta = rand()%MAXCLIENTES;

  /* Transformando a senha em uma string */

  itoa(user.conta, user.numconta, 10);

  /* Percorrer o arquivo de números de contas para verificar se ele já existe */

  cadastro = fopen("cadastro.txt", "r");

  while (!feof(cadastro)) {

    fgets(comparar, sizeof(comparar), cadastro);
    comparar[strlen(comparar)-1]='\0';

    if(strcmp(user.numconta, comparar) == 0){

      sortearconta();

    }

  }

  fclose(cadastro);

}
