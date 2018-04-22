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

int ListLength(LinkList L){
    int count = 0;
    LinkList p = L->next;
    while(p != NULL){
        count ++;
        p = p->next;
    }
    return count;
}


/*
��ĿҪ��ɾ��������м�ڵ�
1                   ����1����ɾ���κνڵ�
1->2                ����2��ɾ��1
1->2->3             ����3��ɾ��2
1->2->3->4          ����4��ɾ��2
1->2->3->4->5       ����5��ɾ��3
1->2->3->4->5->6    ����6��ɾ��3
1->2->3->4->5->6->7 ����7��ɾ��4


�����ǣ��ӳ���Ϊ3��ʼ������ÿ����2��ɾ���ڵ������ƶ�һλ
˼·��
1.��Ȼ���ҵ�Ҫɾ���ڵ��ǰһ���ڵ�pre
2.����һ��pCur����ʼֵΪpre+2�Ľڵ㣻
3.ѭ������pCurÿ������ƶ�2���ڵ㣬��preÿ������ƶ�һ���ڵ㣬
        ѭ�������������ǣ�pCur����Ľڵ�����������ʱ������ѭ��
*/

void removeMiddle(LinkList L){
    LinkList head = L->next;
    if(head == NULL || head->next == NULL){
        return;
    }
    if(head->next->next == NULL){
        L->next = head->next;
        free(head);
        return;
    }

    LinkList pre = head;
    LinkList pCur = head->next->next;
    while(pCur->next != NULL && pCur->next->next){
        pre = pre->next;
        pCur = pCur->next->next;
    }

    LinkList target = pre->next;
    pre->next = target->next;
    free(target);
}

int main(){
    LinkList L = (Node *) malloc(sizeof(Node));
    L->next = NULL;

    for(int j=10;j>=1;j--){
        ListInsert(&L,1,j);
    }
    printf("��L�ı�ͷ���β���1��10��L.data=");
    ListTraverse(L);

    printf("����Ϊ%2dʱ��ɾ���м�Ԫ�غ�L.data=", ListLength(L));
    removeMiddle(L);
    ListTraverse(L);

    printf("����Ϊ%2dʱ��ɾ���м�Ԫ�غ�L.data=", ListLength(L));
    removeMiddle(L);
    ListTraverse(L);

    printf("����Ϊ%2dʱ��ɾ���м�Ԫ�غ�L.data=", ListLength(L));
    removeMiddle(L);
    ListTraverse(L);

    printf("����Ϊ%2dʱ��ɾ���м�Ԫ�غ�L.data=", ListLength(L));
    removeMiddle(L);
    ListTraverse(L);

    printf("����Ϊ%2dʱ��ɾ���м�Ԫ�غ�L.data=", ListLength(L));
    removeMiddle(L);
    ListTraverse(L);

    printf("����Ϊ%2dʱ��ɾ���м�Ԫ�غ�L.data=", ListLength(L));
    removeMiddle(L);
    ListTraverse(L);

    printf("����Ϊ%2dʱ��ɾ���м�Ԫ�غ�L.data=", ListLength(L));
    removeMiddle(L);
    ListTraverse(L);

    printf("����Ϊ%2dʱ��ɾ���м�Ԫ�غ�L.data=", ListLength(L));
    removeMiddle(L);
    ListTraverse(L);

    printf("����Ϊ%2dʱ��ɾ���м�Ԫ�غ�L.data=", ListLength(L));
    removeMiddle(L);
    ListTraverse(L);



    return 0;
}






