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



////#################  �ݹ�ʵ�ַ�ת����
LinkList do_reversal_recursion(LinkList head){
    if(head->next == NULL){
        return head;
    }
    LinkList tmp = head->next;
    LinkList newHead = do_reversal_recursion(tmp);
    tmp->next = head;

    head->next = NULL;
    return newHead;
}
void reversal_recursion(LinkList L){
    LinkList head = L->next;
    L->next = do_reversal_recursion(head);
}

////################## β�ݹ�ʵ��
LinkList do_reversal_recursion_tail(LinkList head, LinkList preHead){
    while(head == NULL){
        return preHead;
    }
    LinkList tmp = head->next ;
    head->next = preHead;

    return do_reversal_recursion_tail(tmp, head);
}
//
void reversal_recursion_tail(LinkList L){
    LinkList head = L->next;
    L->next = do_reversal_recursion_tail(head, NULL);
}

//################### ����ʵ��
void reversal_iterate(LinkList L){
    LinkList head = L->next;
    if(head != NULL && head->next != NULL){
        LinkList pre = NULL;
        LinkList tmp = NULL;
        while (head){
            tmp = head->next;
            head->next = pre;
            pre = head;
            head = tmp;
        }
        L->next = pre;
    }


}

int main(){
    LinkList L = (LinkList) malloc(sizeof(Node));
    L->next = NULL;
    for(int j=1;j<=5;j++){
        ListInsert(&L,1,j);
    }
    printf("��L�ı�ͷ���β���1��5��L.data=");
    ListTraverse(L);

    reversal_iterate(L);
    printf("������תL��L.data=");
    ListTraverse(L);

    reversal_recursion(L);
    printf("�ݹ鷴תL��L.data=");
    ListTraverse(L);

    reversal_recursion_tail(L);
    printf("β�ݹ鷴תL��L.data=");
    ListTraverse(L);

    return 0;
}






