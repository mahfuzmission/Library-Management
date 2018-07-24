#include<stdio.h>
#include<string.h>

struct book{
char name[100];
char writer[100];
int no_of_pages;
};

struct student{
char name[100];
int id;
};
int borrow();
int add();
int delet();
int librarian();
int admin();
int student();
int display_students();
int display_books();
void search_books();
int delete_book();
int add_book();

int main()
{
    printf("\t\tMain Menu\n\t1. Admin\n\t2. Student\n\t3. Librarian\n\nNOTE: \nPress 1 if you are admin\nPress 2 if you r student\nPress 3 if you are a librarian\nAfter all enter your password.\n ");
    int user;
    scanf("%d",&user);
    int password;
    scanf("%d",&password);
    if(user==1 && password==123)
        admin();
    if(user==2 && password==1234)
        student();
    if(user==3 && password==12345)
        librarian();
}

int admin()
{
    int n;
    printf("To add a student press 1 & to delete a student press 2\nPress 3 to see all student list\n");
    scanf("%d",&n);
    if(n==1)
        add();
    if(n==2)
        delet();
    if(n==3)
        display_students();
}

int student()
{
    printf("\n1. Display book list and info\n2. Search book\n3. Borrow book\n");
    int n;
    scanf("%d",&n);
    if(n==1)
        display_books();
    if(n==2)
        search_books();
    if(n==3)
        borrow();

}

void search_books()
{
    printf("enter book name :\n");
    char search[100];
    scanf("%s",&search);
    int a=strlen(search);

    int n=0,counter=100;
    FILE*fp;
    fp=fopen("book_list.txt","r");
    struct book books[100];
    int i=0;
    while(!feof(fp)){
    fgets(books[i].name,100,fp);
    fgets(books[i].writer,100,fp);
    fscanf(fp,"%d ",&books[i].no_of_pages);
    i++;
    n=i;
    }
    for(i=0;i<n;i++){
        if(strncmp(books[i].name,search,a)==0)
            {
                counter=0;
            }
    }
    if(counter==0)
        printf("found");
    else
        printf("not found");

    fclose(fp);
    return 0;
}

int librarian()
{
    printf("\n1. delete books\n2. Add books\n3. view book\n\n");
    printf("Enter choice");
    int choice;
    scanf("%d",&choice);
    if(choice==1)
        delete_book();
    if(choice==2)
        add_book();
    if(choice==3)
        display_books();
}
int add_book()
{
    int n=0;
    FILE*fp;
    FILE*out;
    fp=fopen("book_list.txt","r");
    struct book books[100];
    int i=0;
    while(!feof(fp)){
    fgets(books[i].name,100,fp);
    fgets(books[i].writer,100,fp);
    fscanf(fp,"%d ",&books[i].no_of_pages);
    i++;
    n=i;
    }
    out=fopen("book_list.txt","w");
    for(i=0;i<n;i++){
        fprintf(out,"%s ",books[i].name);
        fprintf(out,"%s ",books[i].writer);
        fprintf(out,"%d ",books[i].no_of_pages);
    }
    gets(books[n].name);
    gets(books[n].writer);
    scanf("%d ",&books[n].no_of_pages);
    fprintf(out,"%s ",books[n].name);
    fprintf(out,"%s ",books[n].writer);
    fprintf(out,"\n%d \n",books[n].no_of_pages);
    fclose(fp);
    fclose(out);
    return 0;
}

int add(){
    printf("Enter student students name and id then press 'mun' and hit enter : ");
    int n=0;
    FILE*fp;
    FILE *out;
    fp=fopen("student_list.txt","r");
    struct student student_info[n];
    int i=0;
    while(!feof(fp)){
    fgets(student_info[i].name,100,fp);
    fscanf(fp,"%d ",&student_info[i].id);
    i++;
    n=i;
    }
    out=fopen("student_list.txt","w");
    for(i=0;i<n;i++){
        fprintf(out,"%s",student_info[i].name);
        fprintf(out,"%d ",student_info[i].id);
    }
    scanf("%s ",&student_info[n].name);
    scanf("%d ",&student_info[n].id);
    fprintf(out,"%s ",student_info[n].name);
    fprintf(out,"\n%d \n",student_info[n].id);
    fclose(fp);
    fclose(out);
    return 0;
}


int delet()
{
printf("Enter student id to delete: \n");
FILE*fp;
FILE*out;
fp=fopen("student_list.txt","r+");
struct student student_info[1000];
int i=0,n=0,skip_id,skip;
scanf("%d",&skip_id);
while(!feof(fp)){
    fgets(student_info[i].name,100,fp);
    fscanf(fp,"%d ",&student_info[i].id);
    if(skip_id==student_info[i].id)
        skip=i;
    i++;
    n=i;
    }
out=fopen("student_list.txt","w");
    for(i=0;i<n;i++){
        if(skip==i)
            continue;
        fprintf(out,"%s",student_info[i].name);
        fprintf(out,"%d ",student_info[i].id);
    }
    fclose(fp);
}


display_students()
{
    int n=0;
    FILE*fp;
    fp=fopen("student_list.txt","r");
    struct student student_info[n];
    int i=0;
    while(!feof(fp)){
    fgets(student_info[i].name,100,fp);
    fscanf(fp,"%d ",&student_info[i].id);
    i++;
    n=i;
    }
    for(i=0;i<n;i++){
    puts(student_info[i].name);
    printf("\n%d\n\n",student_info[i].id);
    }
    fclose(fp);
}

int display_books()
{
    int n=0;
    FILE*fp;
    fp=fopen("book_list.txt","r");
    struct book books[100];
    int i=0;
    while(!feof(fp)){
    fgets(books[i].name,100,fp);
    fgets(books[i].writer,100,fp);
    fscanf(fp,"%d ",&books[i].no_of_pages);
    i++;
    n=i;
    }
    for(i=0;i<n;i++){
    printf("%d.  \n",i+1);
    puts(books[i].name);
    puts(books[i].writer);
    printf("\n%d\n\n",books[i].no_of_pages);
    }
    fclose(fp);
}

int delete_book()
{
    printf("enter book serial :");
    FILE*fp;
    FILE*out;
    fp=fopen("book_list.txt","r");

    struct book books[1000];
    int i=0,n=0,skip_id;
    scanf("%d",&skip_id);
    while(!feof(fp)){
    fgets(books[i].name,100,fp);
    fgets(books[i].writer,100,fp);
    fscanf(fp,"%d ",&books[i].no_of_pages);
    i++;
    n=i;
    }
    out=fopen("book_list.txt","w");
    for(i=0;i<n;i++){
        if(skip_id-1==i)
            continue;
        fprintf(out,"%s",books[i].name);
        fprintf(out,"%s",books[i].writer);
        fprintf(out,"%d ",books[i].no_of_pages);
    }
    fclose(fp);
}

int borrow()
{
    int n=0,skip;
    int book_code;
    scanf("%d",&book_code);
    FILE *fp;
    FILE *out;
    fp=fopen("book_list.txt","r");
    out=fopen("borrow.txt","w");
    struct book books[100];
    int i=0;
    skip=book_code-1;
    while(!feof(fp)){
    fgets(books[i].name,100,fp);
    fgets(books[i].writer,100,fp);
    fscanf(fp,"%d ",&books[i].no_of_pages);
    i++;
    n=i;
    }

    for(i=0;i<n;i++){
        if(skip==i)
            {
            fprintf(out,"%s",books[skip].name);
            fprintf(out,"%s",books[skip].writer);
            fprintf(out,"%d ",books[skip].no_of_pages);
            continue;
            }
        fprintf(fp,"%s",books[i].name);
        fprintf(fp,"%s",books[i].writer);
        fprintf(fp,"%d ",books[i].no_of_pages);
    }

    fclose(fp);
    fclose(out);
    return 0;
}
