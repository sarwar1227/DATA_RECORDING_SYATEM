//STUDENT DATA RECORDING SYSTEM


//PASSWORD = sarwar

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<windows.h>
#include<time.h>
typedef struct node
{
    int rollno;
    char name[20];
    int sem;
    struct node *next;
}node;
node *start=NULL;

//FUNCTION DECLARATION

node *create();
node *get_data(int roll);
node *get_data_by_name(char name[]);
node* rev_list();
void in_beg();
void in_end();
void in_after();
void in_before();
int del_beg();
int del_end();
int del_after();
int del_before();
void display();
void disp_time();
void edit();
void password();
int menu();
void first();
void del_record();

//FUNCTION DEFINITION

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
void disp_time()
{
    time_t t;
    time(&t);
    printf("\n\t    Current Date and Time = %s",ctime(&t));
}
node *get_data(int roll)
{
    node *t;
    t=start;
    while(t!=NULL && t->rollno!=roll)
        t=t->next;
    return t;
}
void edit()
{
   int roll; node *temp;
   if(start==NULL){
    printf("Invalid Edition Activity !! No Record Found");
    return;}
   printf("Enter Roll No. Of Student:");
   scanf("%d",&roll);
   temp=get_data(roll);
   if(temp==NULL){
    printf("Oops...No Record Found !!");
    return;}
   printf("\nEnter New Roll No:");
   scanf("%d",&temp->rollno);
   fflush(stdin);
   printf("\nEnter New Name:");
   scanf("%[^\n]s",temp->name);
   fflush(stdin);
   printf("\nEnter New Semester:");
   scanf("%d",&temp->sem);
   fflush(stdin);
   printf("\nData Successfully Edited !!");
}
void password()
{
    char pwd[20];
    system("cls");
    while(1){
            system("cls");
            printf("\n\n\n\n\n\n\n\t\t\t     Password Protected !!\n\n");
            printf("\n\t\t\tEnter Password To Access : ");
            scanf("%[^\n]s",pwd);
            fflush(stdin);
            if(strcmp("sarwar",pwd)==0){
                printf("\n\n\t\t     Correct Password !! You Can Access Now\n");
                getch();
                return;}
            else{
                printf("\n\n\t\t     Wrong Password !! Please Try Again\n");
                getch();}
    }
}
int menu()
{
    int ch;
    system("cls");
    disp_time();
    printf("\n\t\t    STUDENT DATA RECORDING SYSTEM !!");
    printf("\n\n\t\t\t1.Insert At Beginning");
    printf("\n\t\t\t2.Insert At End");
    printf("\n\t\t\t3.Insert After");
    printf("\n\t\t\t4.Insert Before");
    printf("\n\t\t\t5.Delete From Begining");
    printf("\n\t\t\t6.Delete From End");
    printf("\n\t\t\t7.Delete After");
    printf("\n\t\t\t8.Delete Before");
    printf("\n\t\t\t9.Reverse The Record");
    printf("\n\t\t\t10.Edit Data");
    printf("\n\t\t\t11.Get Data");
    printf("\n\t\t\t12.Display The Record");
    printf("\n\t\t\t13.Delete All Records");
    printf("\n\t\t\t14.Exit");
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
    password();
}
void in_after()
{
    int r;
    node *t,*n=create();
    printf("\nEnter The Roll No. After Which Data Should Be Inserted:");
    scanf("%d",&r);
    if(start==NULL){
            printf("\nInvalid Insertion !! list is empty !!");
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
    n->next=t->next;
    t->next=n;
}
void in_before()
{
    int r; node *t1,*t2,*n=create();
    printf("\nEnter The Roll No. Before Which Data Should Be Inserted:");
    scanf("%d",&r);
    if(start==NULL || start->rollno==r){
            printf("\nNo Record Exist Before Provided Roll Number!!");
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
    fflush(stdin);
    t1=start;  t2=t1->next;
    while(t2->rollno!=r){
        t1=t2;
        t2=t2->next;}
    if(t2==NULL)
    {
          printf("\nInvalid Insertion !! Provided Roll No. Not Found !!");
          return;
    }
    n->next=t2;
    t1->next=n;
}
void del_record()
{
    while(start)
        del_beg();
   printf("\nAll Record Deleted!!");
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
int del_before()
{
   node *t1,*t2; int r,item;
   printf("\nEnter The Roll No. Before Which Data Should Be Deleted:");
   scanf("%d",&r);
   if(start==NULL || start->rollno==r){
        printf("\nInvalid Deletion !! Roll no. Not Found");
        return -1;}
    t1=start;
    t2=t1->next->next;
    while(t2->rollno!=r)
    {
        t1=t1->next;
        t2=t2->next;
    }
    t2=t1->next;
    item=t2->rollno;
    t1->next=t2->next;
    return item;
}
/*node *get_data_by_name(char name[])
{
    node *t;
    t=start;
    if(start!=NULL){
    while(strcmp(t->name,name)!=0)
        t=t->next;
    }
    return t;
}*/
int main()
{
    int ans,choice; node *temp_data; char temp_name[20];
    system("color 1f");
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
                    in_before();
                    break;
                case 5:
                    ans=del_beg();
                    if(ans!=-1)
                        printf("\nRecord of Roll No : %d Deleted Successfully !!",ans);
                    break;
                case 6:
                    ans=del_end();
                    if(ans!=-1)
                        printf("\nRecord of Roll No : %d Deleted Successfully !!",ans);
                    break;
                case 7:
                    ans=del_after();
                    if(ans!=-1)
                        printf("\nRecord of Roll No : %d Deleted Successfully !!",ans);
                    break;
                case 8:
                    ans=del_before();
                    if(ans!=-1)
                        printf("\nRecord of Roll No : %d Deleted Successfully !!",ans);
                    break;
                case 9:
                    start=rev_list();
                    if(start!=NULL)
                        printf("List is Reversed !!");
                    break;
                case 10:
                    edit();
                    break;
                case 11:
                    system("cls");
                    printf("\n\n\n\n\n\n\n\t\t\tSearch Record by\n\n\t\t\t1.Roll No\n\n\t\t\t2.Name\n\n\t\t\tEnter Your Choice:");
                    scanf("%d",&choice);
                    switch(choice)
                    {
                        case 1:
                            printf("\n\t\t\tEnter Roll No:");
                            scanf("%d",&ans);
                            temp_data=get_data(ans);
                            if(temp_data!=NULL){
                                    system("cls");
                                    printf("\n\n\n\n\t\t\tRequired Student Data !! \n");
                                    printf("\n\n\t\t\t  Roll No : %d\n\n\t\t\t  Name : %s\n\n\t\t\t  Semester : %d",temp_data->rollno,temp_data->name,temp_data->sem);}
                            else
                               printf("\n\t\t\tNo Record Found !!");
                            break;
                        /*case 2:
                            printf("\nEnter Name:");
                            fflush(stdin);
                            scanf("%[^\n]s",temp_name);
                            fflush(stdin);
                            temp_data=get_data_by_name(temp_name);
                            if(temp_data!=NULL){
                                    system("cls");
                                    printf("\n\n\n\n\t\t\tRequired Student Data !! \n");
                                    printf("\n\n\t\t\t  Roll No : %d\n\n\t\t\t  Name : %s\n\n\t\t\t  Semester : %d",temp_data->rollno,temp_data->name,temp_data->sem);}
                            else
                                printf("\nNo Record Found !!");
                            break;*/
                        default:
                            printf("\n\t\t\tInvalid Choice !!");
                    }
                    break;

                case 12:
                    display();
                    break;
                case 13:
                    del_record();
                    break;
                case 14:
                    system("cls");
                    system("color e0");
                    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t     THANK YOU FOR VISITING !! SEE YOU AGAIN\n\n\t\t\t  HAVE A GOOD DAY !!\n\n\t\t\t   -By Mr. Sarwar Ali\n\n\n\n\n\n\n\n\n\n\n\n");
                    exit(0);
                default:
                    printf("\n\t\t\t  Invalid Choice !!");
            }
        getch();
        }
    return 0;
}
