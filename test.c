#include <stdio.h>
#include <stdlib.h>

struct Listnode
{
    int a;
    struct Listnode *next;
};

int c=0;

struct Listnode *Listlink();

void compare(struct Listnode *head1,struct Listnode *head2);

int main()
{
    struct Listnode *head1=Listlink();
    int a=c;
    struct Listnode *head2=Listlink();
    int b=c;
    if(a<b)
    {
        printf("ListB is not the sub sequence of ListA.\n");
        return 0;
    }
    compare(head1,head2);
}

struct Listnode *Listlink()
{
    c=0;
    int b = 0;
    struct Listnode *head = NULL, *last = NULL, *current = NULL;
    while (scanf("%d", &b))
    {
        if (b >= 0)
        {
            current = malloc(sizeof(struct Listnode));
            current->a = b;
            if (head == NULL)
            {
                head = current;
                last = current;
            }
            else
            {
                last->next = current;
                last = current;
            }
            c++;
        }
        else
        {
            break;
        }
    }
    last->next = NULL;
    return head;
}

void compare(struct Listnode *headA,struct Listnode *headB)
{
    int temp=0;
    struct Listnode *m;
    m=headB;
    int switch0=0;
    while(headA!=NULL)
    {
        if(headA->a==m->a)
        {
            while(headA->a==m->a)
            {
                temp++;
                if(headA->next==NULL||m->next==NULL)
                {
                    switch0=1;
                    break;
                }
                headA=headA->next;
                m=m->next;
            }
            switch0=1;
        }
        if(temp==c)
        {
            break;
        }
        else if(switch0==1)
        {
            m=headB;
            switch0=0;
            temp=0;
            continue;
        }
        else
            temp=0;
        headA=headA->next;
    }
    if(temp==c)
    {
        printf("ListB is the sub sequence of ListA.");
    }
    else
        printf("ListB is not the sub sequence of ListA.");
}