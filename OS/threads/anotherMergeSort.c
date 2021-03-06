//implementing mergesort
//./a.out 3 7 2 6 1 9
#include <pthread.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
struct node
{
    int *a;
    int begs;
    int ends;
};

void merge(int *a, int beg, int end)
{
    int mid = (beg + end) / 2;
    int i = beg;
    int j = mid + 1;
    int b[100];
    int k = 0;
    while (i <= mid && j <= end)
    {
        if (a[i] < a[j])
        {
            b[k++] = a[i++];
        }
        else
        {
            b[k++] = a[j++];
        }
    }
    while (i <= mid)
    {
        b[k++] = a[i++];
    }
    while (j <= end)
    {
        b[k++] = a[j++];
    }
    int p = 0;
    for (int x = beg; x <= end; ++x)
    {
        a[x] = b[p++];
    }
}

void *mergesortP(void *param)
{
    struct node *nd = param;
    int beg = nd->begs;
    int end = nd->ends;
    int *a = nd->a;
    int mid;
    if (beg >= end)
    {
        return NULL;
    }
    mid = (beg + end) / 2;
    struct node *nd1 = malloc(sizeof(struct node));
    nd1->begs = beg, nd1->ends = mid, nd1->a = a;
    // mergesort(a,beg,mid);
    pthread_t tid1;
    pthread_create(&tid1, NULL, mergesortP, nd1);

    struct node *nd2 = malloc(sizeof(struct node));
    nd2->begs = mid + 1, nd2->ends = end, nd2->a = a;
    // mergesort(a,mid+1,end);
    pthread_t tid2;
    pthread_create(&tid2, NULL, mergesortP, nd2);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    merge(a, beg, end);
    return NULL;
}

int main(int argc, char *argv[])
{
    srand(time(NULL));
    int n = 8;
    int a[8];
    for (int j = 0; j < 8; j++)
    {
        a[j] = rand() % 100;
    }
    // int a[argc];
    // for(int i=0 ; i<argc-1 ; ++i){
    //     a[i]=atoi(argv[i+1]);
    // }

    clock_t t1, t2;

    t1 = clock();

    struct node *nd = malloc(sizeof(struct node));
    nd->begs = 0;
    //nd->ends=argc-2;
    nd->ends = 7;
    nd->a = a;
    // mergesort(a,0,argc-2);
    pthread_t tid;
    pthread_create(&tid, NULL, mergesortP, nd);
    pthread_join(tid, NULL);
    t2 = clock();
    for (int i = 0; i < 8; ++i)
    {
        printf("%d ", a[i]);
    }
    printf("\nClock time: %f\n", (t2 - t1) / (double)CLOCKS_PER_SEC);
}