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
    while(p != NULL){
        visit(p->data);
        p = p->next;
    }
    printf("\n");
    return OK;
}
void removeLastKthNode2(LinkList L, int lastKth){
    if(L->next == NULL || lastKth < 0){
        return;
    }

    LinkList k1 = L->next, k2 = k1, pre=NULL;

    int num = 1;
    while (k1->next != NULL &&  num < lastKth){
        num++;
        k1 = k1->next;
    }

    if(num < lastKth){

    }else{
        while (k1->next != NULL){
            k1 = k1->next;
            pre = k2;
            k2 = k2->next;
        }
        if(pre == NULL){
            L->next = k2->next;
        }else{
            pre->next = k2->next;
        }
        free(k2);
    }
}
void removeLastKthNode(LinkList L, int lastKth){
    if(L->next == NULL || lastKth < 0){
        return;
    }

    //��ּ��ɾ��ĳ���ڵ㣬�Ǿ��ҵ�����ǰһ���ڵ�
    //��������ĳ���ΪN��Ҫɾ��������N���ڵ㣬 ������ǰһ���ڵ㼴ΪN-K
    //���������һ��ѭ����ÿ�ζ�K-1��ѭ������ʱ��K=K-N��
    //����ʱ��K==0��˵��K==N�� ��ɾ�����ǵ�һ��Ԫ��, ��ʱ��head�ڵ���Ҫ����;
    //����ʱ��K>0, ˵��N<K,��˵�����Ԫ�ز����ڣ�����ɾ��
    //����ʱ��K<0; �����´�ͷ��������K+1�� ��K=0ʱ����ΪN-K ;

    LinkList cur = L->next;
    while(cur != NULL){
        lastKth--;
        cur = cur->next;
    }

    if(lastKth == 0){
        LinkList head = L->next;
        L->next = head->next;
        free(head);
    }else if(lastKth > 0){
        //donothing
    }else{
        cur = L->next;
        while(++lastKth != 0){
            cur = cur->next;
        }
        LinkList deleteTarget = cur->next;
        cur->next = deleteTarget->next;
        free(deleteTarget);
    }
}


int main(){
    LinkList L = (Node *) malloc(sizeof(Node));
    L->next = NULL;

    for(int j=1;j<=5;j++){
        ListInsert(&L,1,j);
    }
    printf("��L�ı�ͷ����1��5��L.data=");
    ListTraverse(L);

    removeLastKthNode2(L,9);
    printf("ɾ��������9��Ԫ�غ�L.data=");
    ListTraverse(L);

    removeLastKthNode2(L,2);
    printf("ɾ��������2��Ԫ�غ�L.data=");
    ListTraverse(L);

    removeLastKthNode2(L,2);
    printf("ɾ��������2��Ԫ�غ�L.data=");
    ListTraverse(L);

    removeLastKthNode2(L,2);
    printf("ɾ��������2��Ԫ�غ�L.data=");
    ListTraverse(L);

    removeLastKthNode2(L,2);
    printf("ɾ��������2��Ԫ�غ�L.data=");
    ListTraverse(L);

    removeLastKthNode2(L,1);
    printf("ɾ��������1��Ԫ�غ�L.data=");
    ListTraverse(L);


    L = (Node *) malloc(sizeof(Node));
    L->next = NULL;

    for(int j=1;j<=5;j++){
        ListInsert(&L,1,j);
    }
    printf("��L�ı�ͷ����1��5��L.data=");
    ListTraverse(L);

    removeLastKthNode(L,2);
    printf("ɾ��������2��Ԫ�غ�L.data=");
    ListTraverse(L);

    removeLastKthNode(L,2);
    printf("ɾ��������2��Ԫ�غ�L.data=");
    ListTraverse(L);

    removeLastKthNode(L,2);
    printf("ɾ��������2��Ԫ�غ�L.data=");
    ListTraverse(L);

    removeLastKthNode(L,2);
    printf("ɾ��������2��Ԫ�غ�L.data=");
    ListTraverse(L);

    removeLastKthNode(L,1);
    printf("ɾ��������2��Ԫ�غ�L.data=");
    ListTraverse(L);


    return 0;
}






