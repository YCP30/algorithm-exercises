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

int ListLength(LinkList L){
    int i = 0;
    LinkList p = L->next;
    while (p){
        i++;
        p = p->next;
    }
    return i;
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

LinkList do_reversal_recursion_tail(LinkList pHead, LinkList pre, LinkList endFlag){
    if(pHead == endFlag){
        return pre;
    }
    LinkList tmp = pHead->next;
    pHead->next = pre;
    return do_reversal_recursion_tail(tmp, pHead, endFlag);
}

void reverse_part(LinkList L, int from, int to){
    if(from < 1 || to < 1 || from == to || from > to){
        return ;
    }

    // ��һ����Ч���
    LinkList head = L->next;
    // tmpCur
    LinkList tmpCur = head;
    // ������ʶfromǰһ���ڵ㣬Ϊnullʱ��fromΪ��һ����Ч�ڵ�NULL
    LinkList f_pre = NULL;
    // ������ʶto��һ���ڵ�
    LinkList t_last = NULL;

    // ��������ȣ���λ f_pre, t_last
    int len = 0;
    while(tmpCur != NULL){
        len ++;

        f_pre = len == from -1 ? tmpCur : f_pre;
        t_last = len == to + 1 ? tmpCur : t_last;

        tmpCur = tmpCur->next;
    }

    // ��תfrom - to ��������
    tmpCur = f_pre == NULL ? head : f_pre->next;
    LinkList newHead = do_reversal_recursion_tail(tmpCur, t_last, t_last);

    // ������������
    if (f_pre == NULL){
        L->next = newHead;
    }else{
        f_pre->next = newHead;
    }
}


int main(){
    LinkList L;
    ElemType e;
    Status i;
    int j,k;
    i=InitList(&L);
    printf("��ʼ��L��ListLength(L)=%d\n",ListLength(L));
    for(j=10;j>=1;j--)
            i=ListInsert(&L,1,j);
    printf("��L�ı�ͷ����10-1��L.data=");
    ListTraverse(L);

    reverse_part(L, 2,5);
    printf("���ַ�תL 2-5��L.data=");
    ListTraverse(L);

     reverse_part(L, 2,5);
    printf("���ַ�תL 2-5��L.data=");
    ListTraverse(L);

    reverse_part(L, 1,9);
    printf("���ַ�תL 1-9��L.data=");
    ListTraverse(L);

     reverse_part(L, 1,10);
    printf("���ַ�תL 1,10��L.data=");
    ListTraverse(L);

      reverse_part(L, 1,2);
    printf("���ַ�תL 1,2��L.data=");
    ListTraverse(L);

    return 0;
}






