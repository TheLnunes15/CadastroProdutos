/* Lucas dos Santos Nunes - Projeto Final (PI) */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE* AbreArquivo(char modo, char destino[50]){ //Função para abrir o arquivo
    FILE *arquivo;
    switch(modo){
        case 'l': // l = leitura
          arquivo = fopen(destino , "r");
          break;
        case 'a': // a = ler e gravar no fim do arquivo
          arquivo = fopen(destino , "a");
          break;
    }
      if(arquivo != NULL){
        getc(arquivo);
         if (feof(arquivo)){
          printf("\nNenhum produto cadastrado!\n");
          exit(0);
         }
     }
       else if(arquivo == NULL){
         printf("\nErro no arquivo!\n");
         exit(0);
    }
      return arquivo;
}

void FechaArquivo(FILE *arquivo){ //Função para fechar o arquivo
    fclose(arquivo);
}

struct cadastro{
    int codigo;
    char nome[50];
    float valor;
};


int main(void){
  FILE *arquivo;
  struct cadastro produto;
  int opcao;
   do{
    system("cls");
    printf("\nMENU PRINCIPAL\n");
    printf("1 - Cadastrar produto\n");
    printf("2 - Listar todos produtos\n");
    printf("3 - Sair\n");
    printf("\nDigite a opcao:\n");
    scanf("%d", &opcao);
    system("cls");
      switch(opcao){
          case 1:
             printf("\nDigite o codigo:\n");
             scanf("%d", &produto.codigo);
             fflush(stdin);
             printf("\nDigite o nome do produto:\n");
             scanf("%s", &produto.nome);
             fflush(stdin);
             printf("\nDigite o valor:\n");
             scanf("%f", &produto.valor);
             fflush(stdin);
             arquivo = AbreArquivo('a', "produtos.txt");
             fwrite(&produto, sizeof(produto), 1, arquivo);
             printf("\nCadastro salvo com sucesso!");
             printf("\n");
             printf("\n");
             FechaArquivo(arquivo);
             system("pause");
             break;
          case 2:
              arquivo = AbreArquivo('l', "produtos.txt");
              rewind(arquivo);
                while(!feof(arquivo)){
                  fread(&produto, sizeof(produto), 1, arquivo);
                    if (ferror(arquivo)){
                       printf("\nErro ao ler registro!");
                      }
                       else {
                          if(!feof(arquivo)){
                            printf("\t*** Registro do produto ***");
                            printf("\nCodigo: %d", produto.codigo);
                            printf("\nNome: %s", produto.nome);
                            printf("\nValor: %f", produto.valor);
                            printf("\n");
                            printf("\n");
                        }
                      }
                  }
                    FechaArquivo(arquivo);
                    system("pause");
                    break;
        }
    } while(opcao != 3);
}
