//STUDENT DATA RECORDING SYSTEM
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
struct node
{
    int rollno;
    char name[20];
    int sem;
    struct node *next;
};
typedef struct node node;
node *start=NULL;
node *create()
{
    node *n=(node *)malloc(sizeof(node));
    n->next=NULL;
}
void in_beg()
{
    node *t,*n=create();
    printf("\nEnter Roll No:");
    scanf("%d",&n->rollno);
    fflush(stdin);
    printf("\nEnter Name:");
    scanf("%[^\n]s",n->name);
    fflush(stdin);
    printf("\nEnter Semester:");
    scanf("%d",&n->sem);
    if(start==NULL)
        start=n;
    else
    {
        t=start;
        start=n;
        n->next=t;
    }
}
void in_end()
{
    node *t,*n=create();
    printf("\nEnter Roll No:");
    scanf("%d",&n->rollno);
    fflush(stdin);
    printf("\nEnter Name:");
    scanf("%[^\n]s",n->name);
    fflush(stdin);
    printf("\nEnter Semester:");
    scanf("%d",&n->sem);
    if(start==NULL)
        start=n;
    else
    {
        t=start;
        while(t->next!=NULL)
            t=t->next;
        t->next=n;

    }
}
void in_after()
{
    int r;
    node *t,*n=create();
    printf("\nEnter The Roll No. After Which Data Should Be Inserted:");
    scanf("%d",&r);
    if(start==NULL){
            printf("\nInvalid Insertion !!.......Provided Roll No. Not Found !!");
            return;}
    fflush(stdin);
    printf("\nEnter Roll No:");
    scanf("%d",&n->rollno);
    fflush(stdin);
    printf("\nEnter Name:");
    gets(n->name);
    fflush(stdin);
    printf("\nEnter Semester:");
    scanf("%d",&n->sem);
    t=start;
    while(t->rollno!=r)
        t=t->next;
    if(t==NULL)
    {
          printf("\nInvalid Insertion... Provided Roll No. Not Found !!");
          return;
    }
    if(t->rollno==r)
    {
        n->next=t->next;
        t->next=n;
    }
    else{
        printf("\nInvalid Insertion... Provided Roll No. Not Found !!");
        return;}
}
int del_end()
{
    node *t; int item;
    if(start==NULL){
        printf("\nList is Empty !!");
        return -1;}
    if(start->next==NULL){
            item=start->rollno;
            start=NULL;
            return item;}
    else
    {
        t=start;
        while(t->next->next!=NULL)
            t=t->next;
        item=t->next->rollno;
        free(t->next);
        t->next=NULL;
        return item;
    }
}
int del_beg()
{
   node *t; int item;
    if(start==NULL){
        printf("\nList is Empty !!");
        return -1;}
    else
    {
        t=start;
        item=start->rollno;
        start=start->next;
        free(t);
        return item;
    }
}
int del_after()
{
   int r,item; node *t,*temp;
   if(start==NULL){
        printf("\nList is Empty !!");
        return -1;}
   printf("\nEnter The Roll No. After Which Data Should Be Deleted:");
   scanf("%d",&r);
   t=start;
   while(t->rollno!=r)
    t=t->next;
   if(t->next==NULL){
    printf("\nRecord Not Exist !!");
    return -1;}
   if(t->next->next==NULL)
   {
       temp=t;
       temp=temp->next;
       t->next=temp->next;
       item=temp->rollno;
       free(temp);
       return item;
   }
   temp=t;
   temp=temp->next;
   t->next=temp->next;
   item=temp->rollno;
   if(temp==NULL){
    printf("\nSorry record can't be deleted !!!");
    return -1;}
   free(temp);
   return item;
}
node* rev_list()
{
   node *t1=NULL,*t2=NULL;
   if(start==NULL){
    printf("List is Empty !!");
    return start;}
   else{
   while(start!=NULL)
   {
       t2=start->next;
       start->next=t1;
       t1=start;
       start=t2;
   }}
return t1;
}
void display()
{
    node *t;
    if(start==NULL){
        printf("\nList Is Empty !!");
        return;}
    else
    {
        system("cls");
        printf("\n\n\t\t\tSTUDENT EXISTING RECORDS");
        printf("\n\n\n\n\t\tS.NO\tROLL NUMBER\tNAME\tSEMESTER\n");

        t=start;
        int i=1;
        while(t!=NULL)
        {
            printf("\t\t %d         %d          %s        %d    ",i,t->rollno,t->name,t->sem);
            printf("\n");
            t=t->next;
            i++;
        }
    }
free(t);
printf("\n\nEnter any key to go back...!!");
}
int menu()
{
    int ch;
    system("cls");
    printf("\n\n\t\t    STUDENT DATA RECORDING SYSTEM !!");
    printf("\n\n\t\t\t1.Insert At Beginning");
    printf("\n\t\t\t2.Insert At End");
    printf("\n\t\t\t3.Insert After");
    printf("\n\t\t\t4.Delete From Begining");
    printf("\n\t\t\t5.Delete From End");
    printf("\n\t\t\t6.Delete After");
    printf("\n\t\t\t7.Reverse The Record");
    printf("\n\t\t\t8.Display The Record");
    printf("\n\t\t\t9.Exit");
    printf("\n\n\t\t\tEnter Your Choice:");
    scanf("%d",&ch);
    return ch;
}
void first()
{

   system("cls");
   printf("\n\n\n\n\n\n");
   printf("\t\t   STUDENT DATA RECORDING SYSTEM !!\n");
   printf("\n\t\t\t ->Coded By - SARWAR ALI<-\n");
   printf("\n\t\t\t     Github - sarwar1227\n");
   printf("\n\tSource Code available at : https://github.com/sarwar1227/DATA_RECORDING_SYSTEM");
   printf("\n\n\t\t\tPress Any Key to Continue.....!!!!\n\n");
   getch();
   system("cls");
   printf("\n\n\n\n\n\n\n\n\t\t\t\tLOADING...\n\n\t\t\t");
   for(int i=0;i<25;i++)
        {
            printf("%c",219);
            Sleep(25);
        }
    system("cls");
}
int main()
{
    int ans;
    first();
    while(1)
        {
            switch(menu())
            {
                case 1:
                    in_beg();
                    break;
                case 2:
                    in_end();
                    break;
                case 3:
                    in_after();
                    break;
                case 4:
                    ans=del_beg();
                    if(ans!=-1)
                        printf("\nRecord of Roll No : %d Deleted Successfully !!",ans);
                    break;
                case 5:
                    ans=del_end();
                    if(ans!=-1)
                        printf("\nRecord of Roll No : %d Deleted Successfully !!",ans);
                    break;
                case 6:
                    ans=del_after();
                    if(ans!=-1)
                        printf("\nRecord of Roll No : %d Deleted Successfully !!",ans);
                    break;
                case 7:
                    start=rev_list();
                    if(start!=NULL)
                        printf("List is Reversed !!");
                    break;
                case 8:
                    display();
                    break;
                case 9:
                    exit(0);
                default:
                    printf("\nInvalid Choice !!");
            }
        getch();
        }
    return 0;
}

