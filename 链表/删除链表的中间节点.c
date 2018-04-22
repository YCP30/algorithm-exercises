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
题目要求：删除链表的中间节点
1                   长度1，不删除任何节点
1->2                长度2，删除1
1->2->3             长度3，删除2
1->2->3->4          长度4，删除2
1->2->3->4->5       长度5，删除3
1->2->3->4->5->6    长度6，删除3
1->2->3->4->5->6->7 长度7，删除4


规律是：从长度为3开始，长度每增加2，删除节点往后移动一位
思路：
1.仍然是找到要删除节点的前一个节点pre
2.定义一个pCur，初始值为pre+2的节点；
3.循环，让pCur每次向后移动2个节点，而pre每次向后移动一个节点，
        循环结束的条件是：pCur后面的节点数不足两个时，结束循环
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
    printf("在L的表头依次插入1～10后：L.data=");
    ListTraverse(L);

    printf("长度为%2d时，删除中间元素后：L.data=", ListLength(L));
    removeMiddle(L);
    ListTraverse(L);

    printf("长度为%2d时，删除中间元素后：L.data=", ListLength(L));
    removeMiddle(L);
    ListTraverse(L);

    printf("长度为%2d时，删除中间元素后：L.data=", ListLength(L));
    removeMiddle(L);
    ListTraverse(L);

    printf("长度为%2d时，删除中间元素后：L.data=", ListLength(L));
    removeMiddle(L);
    ListTraverse(L);

    printf("长度为%2d时，删除中间元素后：L.data=", ListLength(L));
    removeMiddle(L);
    ListTraverse(L);

    printf("长度为%2d时，删除中间元素后：L.data=", ListLength(L));
    removeMiddle(L);
    ListTraverse(L);

    printf("长度为%2d时，删除中间元素后：L.data=", ListLength(L));
    removeMiddle(L);
    ListTraverse(L);

    printf("长度为%2d时，删除中间元素后：L.data=", ListLength(L));
    removeMiddle(L);
    ListTraverse(L);

    printf("长度为%2d时，删除中间元素后：L.data=", ListLength(L));
    removeMiddle(L);
    ListTraverse(L);



    return 0;
}






