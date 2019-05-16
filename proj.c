#include<stdio.h>
#include<conio.h>
#define size 10
struct queue
{
int a[20];
int left,right;
int count;
}*q;
void enqr(struct queue *,int);
int deqr(struct queue *);
void display(struct queue *);
void enqr(struct queue *q,int x)
{
if(size==q->count)
{
printf("overflow");
getch();
return;
}
q->right=(q->right+1);
q->a[q->right]=x;
q->count++;
}
int deqr(struct queue *q)
{
int x;
if(q->count==0)
{
printf("under?ow");
return;
}
x=q->a[q->right] ;
q->right--;
q->count--;
return(x);
}
void display(struct queue *q)
{
int i;
if(q->count==0)
{printf("queue empty");
getch();
return;
}
for(i=q->left;i<=q->right;i++)
printf("%d\t",q->a[i]);
getch();
}
void main()
{
int x,ch;
static int i=0;
int b[10];
q->count=0;
q->right=-1 ;
q->left=0;
do
{ 
printf(" \t\t\t***********MENU************\n \t\t\t* 1.insert *\n\t\t\t* 2 .undo *\n \t\t\t* 3 .redo *\n \t\t\t* 4.exit");
printf("\n\t\t\tenter your option ");
scanf("%d" ,&x);
switch(x)
{
case 1:
printf("enter a number to insert");
scanf("%d" ,&ch);
enqr(q,ch);
display(q);
break;
case 2 : 
ch=deqr(q);
b[i++]=ch;
display(q);
break;
case 3 :
if(i>=1)
enqr(q,b [--i]);
display(q);
break;
}
}while(x!=4);

}

