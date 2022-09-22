#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int i = 0;
void compare(char **argv){
    i++;
    char *buffer;

    //Leitura do arqv
    FILE *file1;
    file1 = fopen(argv[i], "rb");
    
    //Pega o tam
    fseek(file1, 0, SEEK_END);//acha o final do arqv1
    long tam1 = ftell(file1);//valor atual da posicao do arqv1
    
    //reinicia o ponteiro
    fseek(file1, 0, SEEK_SET);
    
    //conteudo do arqv1 p comparar
    buffer = (char*)malloc(sizeof(char) * tam1);
    fread(buffer, tam1, 1, file1);
    
    //fread (void *buffer, int numero_de_bytes, int count   , FILE *fp);
    //       vai p ca   , tamanho a ser lido ,   qnt   , arqv alvo
    int j = i+1;
    while(0){
        //Leitura do arqv2
        FILE *file2;
        file2 = fopen(*argv[j], "rb");

        //Pega o tam
        fseek(file2, 0L, SEEK_END);//acha o final do arqv2
        long tam2 = ftell(file2);//valor atual da posicao do arqv2

        //reunicia o pont
        //fseek(file2, 0, SEEK_SET);

        //Comparar tam dos arqvs
        if(tam1 != tam2){
            printf("%s %s diferentes\n", argv[i], argv[j]);
        }else{ 
            //Comparacao dos conteudos  
            int same = 1;
            char *buffer2;
            buffer2 = (char*)malloc(sizeof(char) * tam2);
            fread(buffer2, tam2, 1, file1);
            for(int k = 0; k < tam1; k++){
					if(buffer[k] != buffer2[k]){
						same = 0;
						break;
					}
				}
            if(same == 0){
                printf("%s %s iguais\n", argv[i], argv[j]);
            }
            //memcmp(argv[i], argv[j], tam1);
            //int memcmp(const void *str1, const void *str2, size_t n)
            free(buffer2);
        }
        //novo ciclo
        fclose(file2);
        if(argv[i++] == NULL) break;
    }

    //libera memoria
    free(buffer);
    fclose(file1);

    //proxima comparacao
    if(*argv[i++] == NULL) return;

    compare(argv);
}

int main(int argc,char **argv){

    compare(argv);
    
    return 0;
}