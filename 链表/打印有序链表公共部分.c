#include "stdio.h"
#include "stdlib.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 20

typedef int Status;
typedef int ElemType;
Status visit(ElemType e){
    printf("%d ", e);
    return OK;
}

typedef struct Node {
    ElemType data;
    struct Node *next;
}Node;

typedef struct Node *LinkList;


Status InitList(LinkList *L){
    (*L) = (Node *) malloc(sizeof(Node));
    if(!(*L)){
        return ERROR;
    }
    (*L)->next = NULL;
    return OK;
}
Status ListEmpty(LinkList L){
    if(L->next){
        return FALSE;
    }else{
        return TRUE;
    }
}
Status ClearList(LinkList *L){
    LinkList p = (*L)->next;
    LinkList q;
    while (p){
        q = p->next;
        free(p);
        p = q;
    }
    (*L)->next = NULL;
    return OK;
}
int ListLength(LinkList L){
    int i = 0;
    LinkList p = L->next;
    while (p){
        i++;
        p = p->next;
    }
    return i;
}
Status GetElem(LinkList L, int i, ElemType *e){
    LinkList p = L->next;
    int k = 1;
    while (p  && k <i){
        p = p->next;
        k++;
    }

    if(!p || k >i){
        return ERROR;
    }

    *e = p->data;
    return OK;

}
int LocateElem(LinkList L, ElemType e){
    int k = 1;
    LinkList p = L->next;
    while(p){
        if(p->data == e){
            return k;
        }
        p=p->next;
        k++;
    }
    return 0;
}
Status ListInsert(LinkList *L, int i, ElemType e){
    LinkList p = (*L);
    int k = 0;
    while (p && k < i-1){
        p = p->next;
        k++;
    }

    if(!p || k > i -1 ){
        return ERROR;
    }
    LinkList n = (LinkList) malloc(sizeof(Node));
    n->data = e;
    n->next = p->next;
    p->next = n;

    return OK;
}
Status ListDelete(LinkList *L, int i, ElemType *e){
    LinkList p = (*L);
    int k = 0;
    while (p && k < i-1){
        p = p->next;
        k++;
    }

    if(!(p->next) || k > i-1){
        return ERROR;
    }

    LinkList q = p->next;
    *e = q->data;
    p->next = q->next;

    free(q);
    return OK;

}
Status ListTraverse(LinkList L){
    LinkList p = L->next;
    while(p){
        visit(p->data);
        p = p->next;
    }
    printf("\n");
    return OK;
}
void CreateListHead(LinkList *L, int n){
    srand(time(0));

    *L = (LinkList)malloc(sizeof(Node));
    (*L)->next = NULL;

    LinkList p ;
    for (int i = 1; i <= n; i++){
        p = (LinkList)malloc(sizeof(Node));
        p->data = i;
        p->next = (*L)->next;
        (*L)->next = p;
    }
}
void CreateListTail(LinkList *L, int n){
  srand(time(0));

    *L = (LinkList)malloc(sizeof(Node));
    (*L)->next = NULL;

    LinkList p ;
    LinkList last = (*L);
    for (int i = 1; i <= n; i++){
        p = (LinkList)malloc(sizeof(Node));
        p->data = i;
        last->next = p;
        last = p;
    }
    last->next = NULL;
}

void printCommonPart(LinkList L1, LinkList L2){
    LinkList head1 = L1->next;
    LinkList head2 = L2->next;

    printf("链表公共部分有: ");
    while(head1 != NULL && head2 != NULL){
        if(head1->data > head2->data){
            head1 = head1->next;
        }else if(head1->data < head2->data){
            head2 = head2->next;
        }else {
            printf("%d ", head1->data);
            head1 = head1->next;
            head2 = head2->next;
        }
    }
    printf("\n");
}

int main(){
    LinkList L;
    ElemType e;
    Status i;
    int j,k;
    i=InitList(&L);
    printf("初始化L后：ListLength(L)=%d\n",ListLength(L));
    for(j=1;j<=5;j++)
            i=ListInsert(&L,1,j);
    printf("在L的表头依次插入1～5后：L.data=");
    ListTraverse(L);

    LinkList L2 = (Node *) malloc(sizeof(Node));
    L2->next = NULL;
    for(j=3;j<=9;j++){
            i=ListInsert(&L2,1,j);
    }
    printf("在L2的表头依次插入3～9后：L.data=");
    ListTraverse(L2);

    printCommonPart(L, L2);

    return 0;
}






