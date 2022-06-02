#include<conio.h>
#include<stdio.h>
struct book
{
 int isbn;
 char bname[50];
 char author[50];
};
typedef struct book blist;
void read();
void display();
void sort();
void search();
blist b[100];
int n=0;
void main()
{
int ch;
clrscr();
for(;;)
{
printf("1.Read Book Details\n2.Display Book Details\n3.Sort Book Details\n4.Search Book by ISBN\n5.Exit\n");
printf("Enter your choice\n");
scanf("%d",&ch);
switch(ch)
{
  case 1:read();
	 break;
  case 2:display();
	 break;
  case 3:sort();
	 break;
  case 5:exit(0);
  default:printf("Invalid choice.Please enter choice between 1-5 only\n");
}
}
void read()
{
 printf("Enter Book Details\n");
 printf("ISBN:");
 scanf("%d",&b[n].isbn);
 printf("\nTitle:");
 scanf("%s",b[n].bname);
 printf("\nAuthor:");
 scanf("%s",b[n].author);
 n++;
}
void display()
{
  int i;
  printf("Book Details\n");
  printf("ISBN\t\tTitle\t\tAuthor\n");
  for(i=0;i<n;i++)
  printf("%d\t\t%s\t\t%s\n",b[i].isbn,b[i].bname,b[i].author);
}
