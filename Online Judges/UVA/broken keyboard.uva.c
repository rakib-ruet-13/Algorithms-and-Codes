#include<stdio.h>
#include<stdlib.h>
struct list
{
    char cdata;
    struct list *nxtadd;
};

   int  making_list();
   void print_list(struct list *ptr);

 int main()
{
    int i;
    struct list *list1;
    printf("This_is_a_[Beiju]_text\n");
    list1=making_list();
    printf("This_is_a_[Beiju]_text\n");
    print_list(list1);


    return 0;
}
int making_list()
{
    struct list *tnb,*nb,*head;
    tnb=(struct list*)malloc(sizeof(struct list));
    head=tnb;

    tnb->cdata=getchar();
    while(tnb->cdata=='[' || tnb->cdata==']')
        tnb->cdata=getchar();
    while(tnb->cdata!='\n')
    {
         nb=tnb;
         tnb=(struct list*)malloc(sizeof(struct list));
         tnb->cdata=getchar();
         while(tnb->cdata=='[' || tnb->cdata==']')
        tnb->cdata=getchar();
         if(tnb->cdata=='\n')
         {
             nb->nxtadd='\0';
             break;
         }
         nb->nxtadd=tnb;

    }
    return head;
}
void print_list(struct list *pnb)
{
    while(pnb!='\0')
    {
        printf("%c",pnb->cdata);
        pnb=pnb->nxtadd;

    }
    printf("\n");

}

