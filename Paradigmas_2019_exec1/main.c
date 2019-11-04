#include <stdio.h>
//#include <curses.h> //biblioteca no linux
//#include <conio.h> //biblioteca no windowns
#include <string.h>
#include <stdlib.h>

 typedef struct lista{
     char nome[40];
     int idade[3];
     int telefone[11]
     unsigned long int codigo;
     struct lista* prox;
   }Lista;

   //Declaração de funções.
   Lista* inserir_aluno(Lista* primeiro);
   void listar_aluno(Lista* primeiro);
   Lista* excluir_aluno(Lista* primeiro);
   void alterar_aluno(Lista* primeiro);

main()
{
   //Declaração de variáveis
   Lista *primeiro= NULL;
   char opcao;

   //Artifício para repetir o programa.
   while(opcao!='s')
   {
     //Menu de opcoes
      printf(" %c----------------------------------------------------------------------------%c\n",201,187);
      printf(" | ");printf("\t\t\t     CADASTRO DE ALUNOS");printf("\t\t\t      |\n");
      printf(" %c----------------------------------------------------------------------------%c\n",200,188);
      printf("\t       %c----------%c\t\t\t\t       ",201,187);
      printf("\t\t\t               |   MENU   ");printf("|\t\t\t\t      \n");
      printf("   %c-----------%c----------%c------------%c \n",201,200,188,187);
      printf("   | <A>  Novo cadastro                |\n");
      printf("   |-----------------------------------|\n");
      printf("   | <B>  Listar                       |\n");
      printf("   |-----------------------------------|\n");
      printf("   | <C>  Excluir cadastro             |\n");
      printf("   |-----------------------------------|\n");
      printf("   | <D>  Alterar cadastro             |\n");
      printf("   |-----------------------------------|\n");
      printf("   | <S>  Sair                         |\n");
      printf("   %c-----------------------------------%c",200,188);
      printf("\n\n\n\n");

      //Lendo a opcao do menu
      fflush(stdin);
      opcao= getch();

      //Menu de opcoes
      switch(opcao)
      {
         case 'A':
         case 'a':
              //Inserindo os alunos na lista.
              fflush(stdin);
              system("cls");
              printf(" %c----------------------------------------------------------------------------%c\n",201,187);
              printf(" | ");printf("\t\t\t          NOVO CADASTRO     ");printf("\t\t\t      |\n");
              printf(" %c----------------------------------------------------------------------------%c\n",200,188);
              primeiro= inserir_aluno(primeiro);
         getch();
         system("cls");
         break;

         case 'B':
         case 'b':
              //Listando os restaurantes.
              system ("cls");
              printf(" %c----------------------------------------------------------------------------%c\n",201,187);
              printf(" | ");printf("\t\t\t     ALUNOS CADASTRADOS");printf("\t\t\t      |\n");
              printf(" %c----------------------------------------------------------------------------%c\n",200,188);
              listar_aluno(primeiro);
         getch();
         system("cls");
         break;

         case 'C':
         case 'c':
              //Excluindo restaurantes da lista.
              system ("cls");
              printf(" %c----------------------------------------------------------------------------%c\n",201,187);
              printf(" | ");printf("\t\t\t        EXCLUIR CADASTROS");printf("\t\t\t      |\n");
              printf(" %c----------------------------------------------------------------------------%c\n",200,188);
              primeiro= excluir_aluno(primeiro);
         getch();
         system("cls");
         break;

         case 'D':
         case 'd':
              //Alterando restaurantes da lista.
              system ("cls");
              printf(" %c----------------------------------------------------------------------------%c\n",201,187);
              printf(" | ");printf("\t\t\t       ALTERAR CADASTRADOS");printf("\t\t\t      |\n");
              printf(" %c----------------------------------------------------------------------------%c\n",200,188);
              alterar_aluno(primeiro);
         getch();
         system("cls");
         break;

         case 'S':
         case 's':
              //Artifício para sair do programa.
              opcao='s';
         break;

         default:
              //Artifício que previne a situação de um usuário qualquer, digitar uma opcão inexistente no menu.
              system("cls");
         break;
      }
   }
}

Lista* inserir_aluno(Lista *primeiro){
     Lista aluno;
     Lista *atual= primeiro;
     char identificador= 'F';

     //Lendo as informações do restaurante.
     printf("  Nome: ");
     fflush (stdin); fgets(aluno.nome, 40, stdin); printf ("\n");
     printf("  Idade: ",135);
     fflush (stdin); fgets(aluno.idade, 3, stdin); printf ("\n");
     printf("  Telefone: ",150);
     fflush (stdin); fgets(aluno.telefone, 11, stdin); printf ("\n");
     printf("  C%cdigo: ",162);
     scanf("%u",&aluno.codigo);printf ("\n");

     //Verificando se o cadastro já existe.
     for(atual=primeiro; atual!=NULL; atual=atual->prox){
        if(atual->codigo==aluno.codigo){
            identificador= 'V';
            break;
        }
     }

     if(identificador!='V' && (strlen(aluno.nome)!=1 && strlen(aluno.endereco)!=1)){
         //Alocando os espaços e guardando as informações do restaurante.
         Lista* NovoAluno=(Lista*) malloc (sizeof(Lista));
         strcpy(NovoAluno->nome, aluno.nome);
         strcpy(NovoAluno->endereco, aluno.endereco);
         NovoAluno->codigo= aluno.codigo;
         NovoAluno->prox= primeiro;
         printf("  Cadastro realizado com sucesso.");
         printf("\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
         return NovoAluno;
     }else{
         printf("  Cadastro invalido.",160);
         printf("\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
         return primeiro;
     }
}

void listar_aluno(Lista* primeiro){
     Lista* atual;//Ponteiro para percorrer a lista sem perder a referência do primeiro elemento da lista.

     //Imprimindo os restaurantes da lista, e suas repectivas informações.
     for(atual= primeiro ; atual!= NULL; atual= atual->prox){
        printf("\n  Nome: ");
        printf("%s", atual->nome);
        printf("\n  Idade: ",135);
        printf("%s", atual->idade);
        printf("\n  Telefone: ",150);
        printf("%s", atual->telefone);
        printf("\n  Codigo: ",162 );
        printf("%u", atual->codigo);
        printf("\n\n");
     }
     if(primeiro==NULL)
        printf("  Nenhum aluno cadastrado.");
     printf("\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
}

Lista* excluir_aluno(Lista *primeiro){

     Lista *anterior= NULL;//Ponteiro para saber o elemento anterior ao elemento atual da lista.
     Lista *atual= primeiro;//Ponteiro para percorrer a lista sem perder o primeiro elemento da lista.
     unsigned long int codigo=0;

     //Requisitando e lendo o código do aluno a ser excluído.
     printf("  Codigo do aluno a ser excluido: ", 162,161);
     fflush(stdin);
     scanf("%u",&codigo);

     //Procurando o aluno na lista.
     while(atual!= NULL && atual->codigo!=codigo){
        anterior= atual;
        atual= atual->prox;
     }

     //Mensagem caso o aluno não seja encontrado.
     if(atual==NULL){
        printf("\n  Aluno nao encontrado.", 198);
        printf("\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
        return primeiro;
     }

     //Excluindo o primeiro aluno da lista.
     if(anterior==NULL){
        printf("\n  Aluno excluido com sucesso.", 163,161);
        primeiro= atual->prox;
     //Excluindo um aluno do meio da lista.
     }else{
        printf("\n  Aluno excluido com sucesso.", 163,161);
        anterior->prox= atual->prox;
     }

     //Desalocando o espaço da memória.
     free(atual);
     printf("\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
     return primeiro;
}

//Função para atualizar aluno.
void altualizar_aluno(Lista* primeiro){
     char nome_substituto[40];
     int idade_substituta[3], telefone_substituto[11];
     unsigned long int codigo;
     Lista* atual=primeiro;

     //Requisitando e lendo o código do aluno a ser alterado.
     printf("  Codigo do restaurante a ser alterado: ", 162);
     fflush(stdin);
     scanf("%u",&codigo);

     //Procurando o aluno na lista.
     while(atual!= NULL && atual->codigo!=codigo){
        atual= atual->prox;
     }

     //Alterando os dados do restaurante.
     if(atual!=NULL){
        printf("\n  Novo nome: ");
        fflush (stdin); fgets(nome_substituto, 40, stdin);
        strcpy(atual->nome,nome_substituto);
        printf("\n  Nova idade: ",135);
        fflush (stdin); fgets(idade_substituta, 3, stdin); printf ("\n");
        strcpy(atual->idade,idade_substituta);
        printf("\n  Novo telefone: ",150);
        fflush (stdin); fgets(telefone_substituto, 11, stdin); printf ("\n");
        strcpy(atual->telefone,telefone_substituto);
        printf("  Dados alterados com sucesso.");
     }else{
        printf("\n  Aluno nao encontrado.",198);
     }
     printf("\n\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
}
