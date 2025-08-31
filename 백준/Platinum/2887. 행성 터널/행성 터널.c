#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define min(x, y) (x) < (y) ? (x) : (y)

typedef struct a{
    int x, y, z;
    int index;
}element;

typedef struct b
{
    int index1, index2, dis;
}mat;

int howLong(element *a, element *b);
int static compare(const void * a, const void *b);
int findParent(int *arr, int n);
void unio(int *arr, int a, int b);
int static comparex(const void * a, const void *b);
int static comparey(const void * a, const void *b);
int static comparez(const void * a, const void *b);


int main() {
    int n;
    scanf("%d", &n);
    element **arr = (element **)malloc(sizeof(element *) * n);
   
    for(int i = 0; i < n; i++){
        int a,b,c;
        scanf("%d %d %d", &a, &b, &c);
        element *temp = (element *)malloc(sizeof(element));
        temp->x = a;
        temp->y = b;
        temp->z = c;
        temp->index = i;
        arr[i] = temp; //각각 element 저장
    }

    mat **matt = (mat **)malloc(sizeof(mat *) * (3*(n-1)));
    int count = 0;
    qsort(arr, n, sizeof(element *), comparex);
    for(int i = 0; i < n-1; i++){
        mat *temp = (mat *)malloc(sizeof(mat));
        temp->dis = howLong(arr[i], arr[i+1]);
        temp->index1 = arr[i]->index;
        temp->index2 = arr[i+1]->index;
        matt[count++] = temp;
    }

    qsort(arr, n, sizeof(element *), comparey);
    for(int i = 0; i < n-1; i++){
        mat *temp = (mat *)malloc(sizeof(mat));
        temp->dis = howLong(arr[i], arr[i+1]);
        temp->index1 = arr[i]->index;
        temp->index2 = arr[i+1]->index;
        matt[count++] = temp;
    }

    qsort(arr, n, sizeof(element *), comparez);
    for(int i = 0; i < n-1; i++){
        mat *temp = (mat *)malloc(sizeof(mat));
        temp->dis = howLong(arr[i], arr[i+1]);
        temp->index1 = arr[i]->index;
        temp->index2 = arr[i+1]->index;
        matt[count++] = temp;
    }

    qsort(matt, count, sizeof(mat *), compare);
    
    int* uni = (int *)malloc(sizeof(int) * n);
    for(int i  = 0; i < n; i++){
        uni[i] = -1;
    }

    int c = 0, total = 0;;
    for(int  i = 0 ; i < count; i++){
        if (findParent(uni, matt[i]->index1) == findParent(uni, matt[i]->index2)){
            continue;
        }
        else{
            total += matt[i]->dis;
            c++;
            unio(uni, matt[i]->index1, matt[i]->index2);
        }
        if(c == n-1) break;
    }
    printf("%d", total);
}

int findParent(int *arr, int n){
    if(arr[n] < 0) return n;
    else{
        return arr[n] = findParent(arr, arr[n]);
    }
}

void unio(int *arr, int a, int b){
    int p1 = findParent(arr, a);
    int p2 = findParent(arr, b);
    if(arr[p1] > arr[p2]){
        arr[p1] = p2;
    }
    else{
        arr[p2] = p1;
    }
}

int howLong(element *a, element *b){
    return min(min(abs(a->x - b->x) ,abs(a->y - b->y)) , abs(a->z - b->z));
}

int static compare(const void * a, const void *b){
    return (*(mat **)a)->dis - (*(mat **)b)->dis ;
}

int static comparex(const void * a, const void *b){
    return (*(element **)a)->x - (*(element **)b)->x ;
}

int static comparey(const void * a, const void *b){
    return (*(element **)a)->y - (*(element **)b)->y ;
}

int static comparez(const void * a, const void *b){
    return (*(element **)a)->z - (*(element **)b)->z ;
}