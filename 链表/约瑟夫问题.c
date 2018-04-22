
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

Status ListTraverse(LinkList L){
    LinkList p = L->next;
    while(p){
        visit(p->data);
        p = p->next;
    }
    printf("\n");
    return OK;
}

Status ClearList(LinkList *L){
	LinkList p, q;
	p = (*L)->next;
	while (p) {
		q = p->next; /* p ָ���һ���ڵ�*/
		free(p);
		p = q;
	}
	(*L)->next = NULL; /* ͷ���ָ����Ϊ��*/
	return OK;
}

//Լɪ�����⣬����num��kill�� �����������´�1��ʼ��
void josephusKill(LinkList L, int num){
    LinkList head = L->next;
    if(head == NULL || head->next == NULL ||  num < 1){
        return head;
    }

    // �������ɻ�������
    LinkList last = head  ;
    while(last->next != NULL){
        last = last->next;
    }
    last->next = head;

    LinkList killTarget = NULL;
    int count = 0;
    while(last != head){
        if(++count == num){
            killTarget = head;

            last->next = killTarget->next;
            head = killTarget->next;

            free(killTarget);
            count = 0;
        }else{
            last = last->next;
            head = head->next;
        }

    }

    head->next = NULL;
    L->next = head;
}
int main(){
    LinkList L = (LinkList) malloc(sizeof(Node));
    L->next = NULL;
    for(int j=5;j>=1;j--){
        ListInsert(&L,1,j);
    }
    printf("��ʼ������Ϊ��L.data=");
    ListTraverse(L);

    josephusKill(L, 1);
    printf("����1��kill��������������Ľڵ㣺L.data=%d\n", L->next->data);


    ClearList(&L);
    for(int j=5;j>=1;j--){
        ListInsert(&L,1,j);
    }
    printf("��ʼ������Ϊ��L.data=");
    ListTraverse(L);

    josephusKill(L, 3);
    printf("����3��kill��������������Ľڵ㣺L.data=%d\n", L->next->data);



    return 0;
}






