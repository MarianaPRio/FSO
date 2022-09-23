#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>

typedef struct p_thread{
    int num;
    double raiz;
    int result;
}p_thread;

int ConferePrimo(int num, double raiz){
    
    int atual = 0;
    
    if(num % 2 != 0 && num % 3 != 0 && num % 5 != 0 && num % 7 != 0){
        int i = 11;
        while(1){
            if(num % i == 0){
                atual++;
            }
            if(atual > 10 && atual > num){
                return num;
            }
            i++;
            if(i >= raiz) break;
        }
        ConferePrimo(num+1, raiz);
    }
    else{
        //:)
    }
}

void *CalcPrimo(void *tX){
    p_thread *t = tX;
    t->raiz = sqrt((double)t->num);
    t->result = ConferePrimo(t->num, t->raiz);
    pthread_exit(NULL);
}

int main(){
    int t;
    int numt1, numt2;

    scanf("%d", &t);
    while(1){
        pthread_t tid[2];

        if(scanf("%d", &numt1) == 0) break;
        if(scanf("%d", &numt2) == 0) break;
        
        // Thread 1
        p_thread t1;
        t1.num = numt1;
        pthread_create(&tid[0], NULL, CalcPrimo, &t1);

        // Thread 2
        p_thread t2;
        t2.num = numt2;
        pthread_create(&tid[1], NULL, CalcPrimo, &t2);
        
        //P ir na ordem
        pthread_join(tid[0], NULL);
        pthread_join(tid[1], NULL);
        
        printf("%d\n", t1.result);
        printf("%d\n", t2.result);
    }

    return 0;
}