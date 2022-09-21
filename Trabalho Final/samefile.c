/*
A tarefa é determinar se os arquivos passados como argumento para o seu programa são iguais ou diferentes.
Para determinar se arquivos são iguais ou diferentes você deve comparar todos os bytes dos dois arquivos. 
E, claro, se os tamanhos forem diferentes você já pode considerar que os arquivos são diferentes.
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void compare(char **argv){

    size_t aux; //Armazena o tamanho em bytes
    char **arqv1, **arqv2;
    
    //ponteiros para os arquivos comparados
    arqv1 = argv;
    arqv2 = argv++;

    //Leitura do arqv
    FILE *file1;
    file1 = fopen(*arqv1, "r");
    fseek(file1, 0L, SEEK_END);//acha o final do arqv1
    long tam1 = ftell(file1);//valor atual da posicao do arqv1
    fseek(file1, 0, SEEK_SET);//return ponteiro no inicio do arqv1

    //conteudo do arqv1 p comparar
    char *buffer1;
    aux = (char*)malloc(sizeof(char)*tam1);
    fseek(file1, 0, SEEK_SET); //manda o arqv1 p inicio
    aux = fread(buffer1, 1, tam1, file1);// arqv1 p buffer apartir do inicio
    //fread (void *buffer, int numero_de_bytes, int count   , FILE *fp);
    //       vai p ca   , tamanho a ser lido , quantos bytes , arqv alvo
    
    while(0){
        //Leitura do arqv2
        FILE *file2;
        file2 = fopen(*arqv2, "r");
        fseek(file2, 0L, SEEK_END);//acha o final do arqv2
        long tam2 = ftell(file2);//valor atual da posicao do arqv2
        fseek(file2, 0, SEEK_SET);//volta ao comeco do arqv
        
        //Comparar tam dos arqvs
        if(tam1 != tam2){
            printf("%s %s diferentes\n", *arqv1, *arqv2);
        }else{
            //Comparacao dos conteudos  
            //memcmp(arqv1, arqv2, aux);
            //int memcmp(const void *str1, const void *str2, size_t n)
        }
        
        fclose(file2);
        arqv2++;
        if(arqv2 == NULL) break;
    }

    //libera memoria
    free(buffer1);
    fclose(file1);

    //proxima comparacao
    arqv1++;
    if(*arqv1 == NULL){
        return;
    }
    compare(arqv1);
}

int main(int argc,char **argv){

    compare(argv);
    
    return 0;
}