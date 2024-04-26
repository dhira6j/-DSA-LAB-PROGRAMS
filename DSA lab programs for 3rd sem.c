#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define MAX 10
char str[50],pat[50],rep[50],ans[50],q[MAX],item;
int count=0,w[10],n,elem,i,pos,j,c,m,k,flag=0,ch,top=-1,status=0,front=0,rear=-1,a[10][10],source,s[10],b[10];int visited[10],stack[MAX];

void ct() //creating an array
{
printf("\nEnter the size of the array elements:\n");
scanf("%d",&n);
printf("\nEnter the elements for the array:\n");
for(i=0;i<n;i++)
scanf("%d",&w[i]);
} //end of create()
void dis() //displaying an array elements
{
int i;
printf("\nThe array elements are:\n");
for(i=0;i<n;i++)
{
printf("%d\t",w[i]);
}
} //end of display()
void ins() //inserting an element in to an array
{
printf("\nEnter the position for the new element:\n ");
scanf("%d",&pos);
printf("\nEnter the element to be inserted:\n ");
scanf("%d",&elem);
for(i=n-1;i>=pos;i--)
{
w[i+1]=w[i];
}
w[pos]=elem;
n=n+1;
} //end of insert()
void de() //deleting an array element
{
printf("\nEnter the position of the element to be deleted: \n");
scanf("%d",&pos);
elem=w[pos];
for(i=pos; i<n-1;i++)
{
w[i]=w[i+1];
}
n=n-1;
printf("\nThe deleted element is=%d\n", elem);
}//end of delete()
void array()

{
	int ch;

clrscr();

do{

printf("\n\n--------Menu-----------\n");

printf("1.Create\n 2.Display\n 3.Insert\n 4.Delete\n 5.Exit\n");

printf("-------------------------------");

printf("\nEnter your choice:\n ");

scanf("%d", &ch);

switch(ch)

{

case 1:ct();

break;

case 2:dis();

break;

case 3:ins();

break;

case 4:de();

break;

case 5:array();break;

default: printf("\nInvalid choice:\n");

break;

}

}while(ch!=5);

getch();

}// end of main

// end of Array program @@@@@@@@ 1


void stringmatch()
{
i = m = c = j = 0;
while(str[c]!='\0')
{
if(str[m] == pat[i]) // ...... matching
{
i++; m++;
if(pat[i] == '\0') //.....found occurrences.
{
flag = 1;
//.... copy replace string in ans string.
for(k = 0; rep[k] != '\0'; k++, j++)
ans[j] = rep[k];
i = 0;
c = m;
}
} // if ends.
else //... mismatch
{
ans[j] = str[c];
j++;
c++;
m = c;
i = 0;
}//else ends
} //end of while
ans[j] = '\0';
} //end stringmatch()
void string()
{
clrscr();
printf("\nEnter a main string\n ");
fflush(stdin);
gets(str);
printf("\nEnter a pattern string \n");
fflush(stdin);
gets(pat);
printf("\nEnter a replace string \n");
fflush(stdin);
gets(rep);
stringmatch();
if(flag == 1)
printf("\nThe resultant string is\n %s\n" , ans);
else
printf("\nPattern string NOT found\n");
getch();
} 
// end of strings program 2

void push(int stack[], int item)
{
if(top == (MAX-1))
printf("\n\nStack is Overflow\n");
else
{
stack[++top]=item;
status++;
}
}
/*POP FUNCTION*/
int pop(int stack[])
{
int ret;
if(top == -1)
printf("\n\nStack is Underflow\n");
else
{
ret = stack[top--];
status--;
printf("\nPopped element is %d\n",ret);
}
return ret;
}
/* FUNCTION TO CHECK STACK IS PALINDROME OR NOT */
void palindrome(int stack[])
{
int i, temp;
temp=status;
for(i=0;i<temp; i++)
{
if(stack[i]==pop(stack))
count++;
}
if(temp==count)
printf("\nStack contents are Palindrome\n");
else
printf("\nStack contents are not palindrome\n");
}
/*FUNCTION TO DISPLAY STACK*/
void displayy(int stack[])
{
int i;
printf("\nThe stack contents are:\n");
if(top == -1)
printf("\nStack is Empty\n");
else{
for(i=top; i>=0; i--)
printf("\n ------\n| %d |",stack[i]);
printf("\n");
}
}
/*MAIN PROGRAM*/
void sk()
{
clrscr();
do{
printf("\n\n----MAIN MENU----\n");
printf("\n1. PUSH (Insert) in the Stack\n");
printf("\n2. POP (Delete) from the Stack\n");
printf("\n3. PALINDROME check using Stack\n");
printf("\n4. Exit (End the Execution)\n");
printf("\nEnter Your Choice: \n");
scanf("%d", &ch);
switch(ch){
case 1: printf("\nEnter a element to be pushed: \n");
scanf("%d", &item);
 push(stack,item);
displayy(stack);
break;
case 2: item=pop(stack);
displayy(stack);
break;
case 3:
palindrome(stack);
break;
case 4: sk();break;
default:
printf("\nEND OF EXECUTION\n");
};//end switch
}while (ch !=4);
getch();
}

//End of Stack program 3

int F(char symbol)
{
switch(symbol)
{
case '+':
case '-':
return 2;
case '*':
case  '/':
return 4;
case  '^':
case  '$' : return 5;
case  '(' : return 0;
case  '#' : return -1;
default : return 8;
}
}
int G(char symbol)
{
switch(symbol)
{
case  '+'
:
case  '-':
return 1;
case  '*':
case  '/':
return 3;
case '^':
case '$':return 6;
case  '(': return 9;
case  ')': return 0;
default: return 7;
}
}
void infix_postfix(char infix[], char postfix[])
{
int top, j, i;
char s[30], symbol;
top = -1;
s[++top] = '#';
j = 0;
for(i=0; i < strlen(infix); i++)
{
symbol = infix[i];
while(F(s[top]) > G(symbol))
{
postfix[j] = s[top--];
j++;
}
if(F(s[top]) != G(symbol))
s[++top] = symbol;
else
top--;
}
while(s[top] != '#')
{
postfix[j++] = s[top--];
}
postfix[j] = '\0';
}
void expr()
{
char infix[20], postfix[20];
clrscr();
printf("\nEnter a valid infix expression\n");
fflush(stdin);
gets(infix);
infix_postfix(infix,postfix);
printf("\nThe infix expression is:\n");
printf ("%s\n",infix);
printf("\nThe postfix expression is:\n");
printf ("%s\n",postfix);
getch();
}
//End of infix to postfix program 4

double compute(char symbol, double op1, double op2)

{

switch(symbol)

{

case '+': return op1 + op2;

case '-': return op1 - op2;

case '*': return op1 * op2;

case '/': return op1 / op2;

case '$':

case '^': return pow(op1,op2);

default: return 0;

}

}

void suff()

{

double s[20], res, op1, op2;

int top, i;

char postfix[20], symbol;

clrscr();

printf("\nEnter the postfix expression:\n");

fflush(stdin);

gets(postfix);

top=-1;

for(i=0; i<strlen(postfix); i++)

{

symbol = postfix[i];

if(isdigit(symbol))

s[++top] = symbol - '0';

else

{

op2 = s[top--];

op1 = s[top--];
res = compute(symbol, op1, op2);

s[++top] = res;

}

}

res = s[top--];

printf("\nThe result is : %f\n", res);

getch();

}

//End of suffix program 5.a

void tower(int n, int source, int temp,int destination)

{

if(n == 0)

return;

tower(n-1, source, destination, temp);

printf("\nMove disc %d from %c to %c\n", n, source, destination);

tower(n-1, temp, source, destination);

}

void hanoi()

{

int n;

clrscr();

printf("\nEnter the number of discs: \n");

scanf("%d", &n);

tower(n, 'A', 'B', 'C');
printf("\n\nTotal Number of moves are: %d\n", (int)pow(2,n)-1);

getch();

}

// End of Tower of hanoi program 5.b

void insert()
{
if(count == MAX)
printf("\nQueue is Full\n");
else {
rear = (rear + 1) % MAX;
q[rear]=item;
count++;
}
}
void del()
{
if(count == 0)
printf("\nQueue is Empty\n");
else
{
if(front > rear && rear==MAX-1)
{
front=0; rear=-1; count=0;
}
else
{
item=q[front];
printf("\nDeleted item is: %c\n",item);
front = (front + 1) % MAX;
count--;
}
}
}
void display()
{
int i,f=front, r=rear;
if(count == 0)
printf("\nQueue is Empty\n");
else
{
printf("\nContents of Queue is:\n");
for(i=f; i<=r; i++)
{
printf("%c\t", q[i]);
f = (f + 1) % MAX;
}
}
}
void que()
{
clrscr();
do
{
printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
printf("\nEnter the choice:\n ");
scanf("%d", &ch);
fflush(stdin);
switch(ch)
{
case 1: printf("\nEnter the character / item to be inserted: \n");
scanf("%c", &item);
insert();
break;
case 2: del();
break;
case 3: display();
break;
case 4: que();break;
}
}while(ch!=4);
getch();
}

// End of Circular Queue Program 6


struct student
{
char usn[10];
char name[30];
char branch[5];
int sem;
char phno[10];
struct student *next; //Self referential pointer.
};
typedef struct student NODE;
int countnodes(NODE *head)
{
NODE *p;
count=0;
p=head;
while(p!=NULL)
{
p=p->next;
count++;
}
return count;
}
NODE* getnode(NODE *head)
{
NODE *newnode;
newnode=(NODE*)malloc(sizeof(NODE)); //Create first NODE
printf("\nEnter USN, Name, Branch, Sem, Ph.No\n");
fflush(stdin);
gets(newnode->usn);
fflush(stdin);
gets(newnode->name);
fflush(stdin);
gets(newnode->branch);
scanf("%d",&(newnode->sem));
fflush(stdin);
gets(newnode->phno);
newnode->next=NULL; //Set next to NULL...
head=newnode;
return head;
}
NODE* display1(NODE *head)
{
NODE *p;
if(head == NULL)
printf("\nNo student data\n");
else
{
p=head;
printf("\n----STUDENT DATA----\n");
printf("\nUSN\tNAME\t\tBRANCH\tSEM\tPh.NO.\n");
while(p!=NULL)
{
printf("\n%s\t%s\t\t%s\t%d\t%s\n", p->usn, p->name, p->branch, p->sem, p->phno);
p = p->next; //Go to next node...
}
printf("\nThe no. of nodes in list is: %d\n",countnodes(head));
}
return head;
}
NODE* create1(NODE *head)
{
NODE *newnode;
if(head==NULL)
{
newnode=getnode(head);
head=newnode;
}
else
{
newnode=getnode(head);
newnode->next=head;
head=newnode;
}
return head;
}
NODE* insert_front(NODE *head)
{
if(countnodes(head)==MAX)
printf("\nList is Full / Overflow!!\n");
else
head=create1(head); //create()insert nodes at front.
return head;
}
NODE* insert_rear(NODE *head)
{
NODE *p, *newnode;
p=head;
if(countnodes(head) == MAX)
printf("\nList is Full(QUEUE)!!\n");
else
{
if(head == NULL)
{
newnode=getnode(head);
head=newnode; //set first node to be head
}
else
{
	newnode=getnode(head);
while(p->next!=NULL)
{
p=p->next;
}
p->next=newnode;
}
}
return head;
}
NODE* insert1(NODE *head)
{
int ch;
do
{
printf("\n1.Insert at Front(First)\t2.Insert at End(Rear/Last)\t3.Exit\n");
printf("\nEnter your choice: \n");
scanf("%d", &ch);
switch(ch)
{
case 1: head=insert_front(head); break;
case 2: head=insert_rear(head); break;
case 3: break;
}
head=display1(head);
}while(ch!=3);
return head;
}
NODE* delete_front(NODE *head)
{
NODE *p;
if(head==NULL)
printf("\nList is Empty/Underflow (STACK/QUEUE)\n");
else
{
p=head;
head=head->next; //Set 2nd NODE as head
free(p);
printf("\nFront(first)node is deleted\n");
}
return head;
}
NODE* delete_rear(NODE *head)
{
NODE *p, *q;
p=head;
while(p->next->next!=NULL)
{
p=p->next; //Go upto -1 NODE which you want to delete
}
q=p->next;
free(q);//Delete last NODE...
p->next=NULL;
printf("\nLast(end) entry is deleted\n");
return head;
}
NODE* del1(NODE *head)
{
int ch;
do{
printf("\n1.Delete from Front(First)\t2. Delete from End(Rear/Last))\t3.Exit\n");
printf("\nEnter your choice: \n");
scanf("%d",&ch);
switch(ch)
{
case 1: head=delete_front(head);
break;
case 2: head=delete_rear(head);
break;
case 3: break;
}
head=display1(head);
}while(ch!=3);
return head;
}
NODE* stack1(NODE *head)
{
int ch;
do
{
printf("\nSSL used as Stack...\n");
printf("\n 1.Insert at Front(PUSH) \t 2.Delete from Front(POP))\t3.Exit\n");
printf("\nEnter your choice:\n ");
scanf("%d", &ch);
switch(ch)
{
	case 1: head=insert_front(head); break;
case 2: head=delete_front(head); break;
case 3: break;
}
head=display1(head);
}while(ch!=3);
return head;
}
NODE* queue(NODE *head)
{
int ch;
do
{
printf("\nSSL used as Queue...\n");
printf("\n 1.Insert at Rear(INSERT) \t 2.Delete from Front(DELETE))\t3.Exit\n");
printf("\nEnter your choice: \n");
scanf("%d", &ch);
switch(ch)
{
case 1: head=insert_rear(head); break;
case 2: head=delete_front(head); break;
case 3: break;
}
head=display1(head);
}while(ch!=3);
return head;
}
void sll()
{
int ch, i, n;
NODE *head;
head=NULL;
clrscr();
printf("\n*----------Studednt Database-----------*\n");
do
{
printf("\n 1.Create\n 2.Display\n 3.Insert\n 4.Delete\n 5.Stack\n 6.Queue\n 7.Exit\n");
printf("\nEnter your choice: \n");
scanf("%d", &ch);
switch(ch)
{
case 1: printf("\nHow many student data you want to create: \n");
scanf("%d", &n);
for(i=0;i<n;i++)
head=create1(head);//Call to Create NODE...
break;
case 2: head=display1(head); //Call to Display...
break;
case 3: head=insert1(head); //Call to Insert...
break;
case 4: head=del1(head); //Call to delete
break;
case 5: head=stack1(head);
break;
case 6: head=queue(head);
break;
case 7: sll();break;//Exit...
}
}while(ch!=7);
}


// End of Singly Linked List Program 7



struct emp
{
int ssn;
char name[20];
char dept[10];
char desig[15];
int sal;
char phno[10];
struct emp *left;
struct emp *right;
};
typedef struct emp NODE;
int countnodess(NODE *head)
{
NODE *p;
count=0;
p=head;
while(p!=NULL)
{
p=p->right;
count++;
}
return count;
}
NODE* getnodee(NODE *head)
{
NODE *newnode;
newnode=(NODE*)malloc(sizeof(NODE));
newnode->right=newnode->left=NULL;
printf("\nEnter SSN, Name, Dept, Designation, Sal, Ph.No\n");
scanf("%d",&newnode->ssn);
fflush(stdin);
gets(newnode->name);
fflush(stdin);
gets(newnode->dept);
fflush(stdin);
gets(newnode->desig);
scanf("%d",&newnode->sal);
fflush(stdin);
gets(newnode->phno);
head=newnode;
return head;
}
NODE* dispay(NODE *head)
{
NODE *p;
if(head==NULL)
printf("\nNo Employee data\n");
else
{
p=head;
printf("\n----EMPLOYEE DATA----\n");
printf("\nSSN\tNAME\tDEPT\tDESINGATION\tSAL\t\tPh.NO.\n");
while(p!=NULL)
{
printf("\n%d\t%s\t%s\t%s\t\t%d\t\t%s\n", p->ssn, p->name, p->dept, p->desig,
p->sal, p->phno);
p = p->right; //Go to next node...
}
printf("\nThe no. of nodes in list is: %d\n",countnodess(head));
}
return head;
}
NODE* crea(NODE *head)// creating & inserting at end.
{
NODE *p,*newnode;
p=head;
if(head==NULL)
{
newnode=getnodee(head);
head=newnode;
}
else
{
newnode=getnodee(head);
while(p->right!=NULL)
{
	p=p->right;
}
p->right=newnode;
newnode->left=p;
}
return head;
}
NODE* insert_end(NODE *head)
{
if(countnodess(head)==MAX)
printf("\nList is Full!!\n");
else
head=crea(head);
return head;
}
NODE* insert_frontt(NODE *head)
{
NODE *p,*newnode;
if(countnodess(head)==MAX)
printf("\nList is Full!!\n");
else
{
if(head==NULL)
{
newnode=getnodee(head);
head=newnode; //set first node to be head
}
else
{
newnode=getnodee(head);
newnode->right=head;
head->left=newnode;
head=newnode;
}
}
return head;
}
NODE* insertt(NODE *head)
{
int ch;
do
{
printf("\n 1.Insert at Front(First) \t 2.Insert at End(Rear/Last)\t3.Exit\n");
printf("\nEnter your choice:\n ");
scanf("%d", &ch);
switch(ch)
{
case 1: head=insert_frontt(head); break;
case 2: head=insert_end(head); break;
case 3: break;
}
head=dispay(head);
}while(ch!=3);
return head;
}
NODE* delete_frontt(NODE *head)
{
NODE *p;
if(head==NULL)
printf("\nList is Empty (QUEUE)\n");
else
{
p=head;
head=head->right;

free(p);
printf("\nFront(first)node is deleted\n");
}
return head;
}
NODE* delete_end(NODE *head)
{
NODE *p,*q;
p=head;
while(p->right!=NULL)
{
p=p->right; //Go upto -1 node which you want to delete
}
q=p->left;
q->right=NULL;
p->left=NULL;
free(p);//Delete last node...
printf("\nLast(end) entry is deleted\n");
return head;
}
NODE* dell(NODE *head)
{
int ch;
do {
printf("\n1.Delete from Front(First)\t2. Delete from End(Rear/Last))\t3.Exit\n");
printf("\nEnter your choice:\n ");
scanf("%d", &ch);
switch(ch)
{
case 1: head=delete_frontt(head);
break;
case 2: head=delete_end(head);
break;
case 3: break;
}
head=dispay(head);
}while(ch!=3);
return head;
}
NODE* queuee(NODE *head)
{
int ch, ch1, ch2;
do
{
printf("\nDLL used as Double Ended Queue\n");
printf("\n1.QUEUE- Insert at Rear & Delete from Front\n");
printf("\n2.QUEUE- Insert at Front & Delete from Rear\n");
printf("\n3.Exit\n");
printf("\nEnter your choice:\n ");
scanf("%d", &ch);
switch(ch)
{
case 1: do{
printf("\n1.Insert at Rear\t2.Delete from From Front\t3.Exit\n");
printf("\nEnter your choice:\n ");
scanf("%d", &ch1);
switch(ch1)
{
case 1: head=insert_end(head); break;
case 2: head=delete_frontt(head); break;
case 3: break;
}
}while(ch1!=3);
break;
case 2: do{
printf("\n1.Insert at Front\t2.Delete from Rear\t3.Exit\n");
printf("\nEnter your choice: \n");
scanf("%d", &ch2);
switch(ch2)
{
case 1: head=insert_frontt(head); break;
case 2: head=delete_end(head); break;
case 3: break;
}
}while(ch2!=3);
break;
case 3: break;
}
}while(ch!=3);
head=dispay(head);
return head;
}
void dll()
{
int ch, i, n;
clrscr();
NODE *head;
head=NULL;
clrscr();
printf("\n----------Employee Database-----------\n");
do
{
printf("\n1.Create\n2.Display\n3.Insert\n4.Delete\n  5.Queue\n6.Exit\n");
printf("\nEnter your choice: \n");
scanf("%d", &ch);
switch(ch)
{
case 1: printf("\nHow many employees data you want to create: \n");
scanf("%d", &n);
for(i=0;i<n;i++)
head=crea(head);//Call to Create node...
break;
case 2: head=dispay(head); //Call to Display...
break;
case 3: head=insertt(head); //Call to Insert...
break;
case 4: head=dell(head); //Call to delete
break;
case 5: head=queuee(head);
break;
case 6: dll();break;//Exit...
}
}while(ch!=6);
getch();
}


//END OF DOUBLY LINKED LIST PROGRAM 8





typedef struct polynomial
{
    float coeff;
    int x,y,z;
    struct polynomial *next;
}poly;
poly *p1,*p2,*p3;
poly* readpoly()
{
    poly *temp=(poly*)malloc(sizeof(poly));
    printf("\nEnter coeff:\n");
    scanf("%f",&temp->coeff);
    printf("Enter x expon:\n");
    scanf("%d",&temp->x);
    printf("Enter y expon:\n");
    scanf("%d",&temp->y);
    printf("Enter z expon:\n");
    scanf("%d",&temp->z);
    return temp;
}
poly* ceate()
{
    int n,i;
    printf("\nEnter no. of terms:\n");
    scanf("%d",&n);
    poly *temp=(poly*)malloc(sizeof(poly)),*t1=temp;
    for(i=0;i<n;i++,t1=t1->next)
      t1->next=readpoly();
    t1->next=temp;
    return temp;
}
void evaluate()
{
    float sum=0;
    int x,y,z;
    poly *t=p1->next;
    printf("\nEnter x,y&z:\n");
    scanf("%d",&x);
    scanf("%d",&y);
    scanf("%d",&z);
    while(t!=p1)
    {
      sum+=t->coeff*pow(x,t->x)*pow(y,t->y)*pow(z,t->z);
      t=t->next;
    }
    printf("\nSum=%f\n",sum);
}
void dsplay(poly *p)
{
    poly *t=p->next;
    while(t!=p)
    {
      if(t!=p->next&&t->coeff>0)
        putchar('+');
      printf("%.1fx^%dy^%dz^%d\n",t->coeff,t->x,t->y,t->z);
      t=t->next;
    }
}
poly* attach(float coeff,int x,int y,int z,poly *p)
{
    poly *t=(poly*)malloc(sizeof(poly));
    t->coeff=coeff;
    t->x=x;
    t->y=y;
    t->z=z;
    p->next=t;
    return t;
}
poly* add()
{
    printf("\nPolynomial1:\n");
    p1=ceate();
    printf("\nPolynomial2:\n");
    p2=ceate();
    int flag;
    poly *t1=p1->next,*t2=p2->next,*t3;
    p3=(poly*)malloc(sizeof(poly));
    t3=p3;
    while(t1!=p1&&t2!=p2)
    {
        if(t1->x>t2->x)
          flag=1;
        else if(t1->y<t2->y)
          flag=-1;
        else if(t1->z==t2->z)
          flag=0;
        switch(flag)
        {
            case 0:t3=attach(t1->coeff+t2->coeff,t1->x,t1->y,t1->z,t3);
                   t1=t1->next;
                   t2=t2->next;
                   break;
            case 1:t3=attach(t1->coeff,t1->x,t1->y,t1->z,t3);
                   t1=t1->next;
                   break;
            case -1:t3=attach(t2->coeff,t2->x,t2->y,t2->z,t3);
                    t2=t2->next;
                    break;
        }
    }
    for(;t1!=p1;t1=t1->next)
        t3=attach(t1->coeff,t1->x,t1->y,t1->z,t3);
    for(;t2!=p2;t2=t2->next)
        t3=attach(t2->coeff,t2->x,t2->y,t2->z,t3);
    t3->next=p3;
    return p3;
}
void pol()
{
   int ch;
   clrscr();
   printf("\n1.Represent and evaluate polynomial\n2.Add 2 polynomials\n3.Exit\nEnter choice:\n");
   scanf("%d",&ch);
   switch(ch)
   {
       case 1:p1=ceate();
              dsplay(p1);
              evaluate();
              break;
       case 2:p3=add();
              printf("\nPolynomial1:\n");
              dsplay(p1);
              printf("\nPolynomial2:\n");
              dsplay(p2);
              printf("\nP1+P2:\n");
              dsplay(p3);
              break;
       case 3: pol();break;
       default:printf("\nInvalid choice...!\n");
   }
    getch();
}


// End of POLYNOMIAL PROGRAM 9



struct BST

{

int data;

struct BST *left;

struct BST *right;

};

typedef struct BST NODE;

NODE *node;

NODE* createtree(NODE *node, int data)

{

if (node == NULL)

{

NODE *temp;

temp= (NODE*)malloc(sizeof(NODE));

temp->data = data;

temp->left = temp->right = NULL;

return temp;

}

if (data < (node->data))

{
	node->left = createtree(node->left, data);

}

else if (data > node->data)

{

node -> right = createtree(node->right, data);

}

return node;

}

NODE* search(NODE *node, int data)

{

if(node == NULL)

printf("\nElement not found\n");

else if(data < node->data)

{

node->left=search(node->left, data);

}

else if(data > node->data)

{

node->right=search(node->right, data);

}

else

printf("\nElement found is: %d\n", node->data);

return node;

}

void inorder(NODE *node)

{

if(node != NULL)

{

inorder(node->left);

printf("%d\t", node->data);

inorder(node->right);

}

}

void preorder(NODE *node)

{

if(node != NULL)

{

printf("%d\t", node->data);

preorder(node->left);

preorder(node->right);

}

}
void postorder(NODE *node)

{

if(node != NULL)

{

postorder(node->left);

postorder(node->right);

printf("%d\t", node->data);

}

}

NODE* findMin(NODE *node)

{

if(node==NULL)

{

return NULL;

}

if(node->left)

return findMin(node->left);

else

return node;

}

NODE* del3(NODE *node, int data)

{

NODE *temp;

if(node == NULL)

{

printf("\nElement not found\n");

}

else if(data < node->data)

{

node->left = del3(node->left, data);

}

else if(data > node->data)

{

node->right = del3(node->right, data);

}

else

{ /* Now We can delete this node and replace with either minimum element in the right sub tree or maximum element in the left subtree */

if(node->right && node->left)

{ /* Here we will replace with minimum element in the right sub tree */

temp = findMin(node->right);

node -> data = temp->data;

/* As we replaced it with some other node, we have to delete that node */

node -> right = del3(node->right,temp->data);
 }

else

{

/* If there is only one or zero children then we can directly remove it from the tree and connect its parent to its child */

temp = node;

if(node->left == NULL)

node = node->right;

else if(node->right == NULL)

node = node->left;

free(temp); /* temp is longer required */

}

}

return node;

}

void bst()

{

int data, ch, i, n;

NODE *root=NULL;

clrscr();

while (1)

{

printf("\n1.Insertion in Binary Search Tree");

printf("\n2.Search Element in Binary Search Tree");

printf("\n3.Delete Element in Binary Search Tree");

printf("\n4.Inorder\n5.Preorder\n6.Postorder\n7.Exit");

printf("\nEnter your choice:\n ");

scanf("%d", &ch);

switch (ch)

{

case 1: printf("\nEnter N value: \n" );

scanf("%d", &n);

printf("\nEnter the values to create BST like(6,9,5,2,8,15,24,14,7,8,5,2)\n");

for(i=0; i<n; i++)

{

scanf("%d", &data);

root=createtree(root, data);

}

break;

case 2: printf("\nEnter the element to search:\n ");

scanf("%d", &data);

root=search(root, data);

break;

case 3: printf("\nEnter the element to delete:\n ");

scanf("%d", &data);

root=del3(root, data);

break;
case 4: printf("\nInorder Traversal: \n");

inorder(root);

break;

case 5: printf("\nPreorder Traversal: \n");

preorder(root);

break;

case 6: printf("\nPostorder Traversal: \n");

postorder(root);

break;

case 7: bst();break;

default:printf("\nWrong option\n");

break;

}

}

getch();

}



// End of BINARY SEARCH TREE PROGRAM 10



void Crte()

{

printf("\nEnter the number of vertices of the digraph: \n");

scanf("%d", &n);

printf("\nEnter the adjacency matrix of the graph:\n");

for(i=1; i<=n; i++)

for(j=1; j<=n; j++)

scanf("%d", &a[i][j]);

}

void bfs()

{

int q[10], u, front=0, rear=-1;

printf("\nEnter the source vertex to find other nodes reachable or not: \n");

scanf("%d", &source);

q[++rear] = source;

visited[source] = 1;

printf("\nThe reachable vertices are:\n ");

while(front<=rear)

{

u = q[front++];

for(i=1; i<=n; i++)

{

if(a[u][i] == 1 && visited[i] == 0)

{

q[++rear] = i;

visited[i] = 1;

printf("\n%d\n", i);

}

}
}

}

void dfs(int source)

{

int v, top = -1;

s[++top] = 1;

b[source] = 1;

for(v=1; v<=n; v++)

{

if(a[source][v] == 1 && b[v] == 0)

{

printf("\n%d -> %d\n", source, v);

dfs(v);

}

}

}

void gra()

{

int ch;

clrscr();

while(1)

{

printf("\n1.Create Graph\n2.BFS\n3.Check graph connected or not(DFS)\n4.Exit\n");

printf("\nEnter your choice:\n ");

scanf("%d", &ch);

switch(ch)

{

case 1: Crte(); break;

case 2: bfs();

for(i=1;i<=n;i++)

if(visited[i]==0)

printf("\nThe vertex that is not rechable %d\n" ,i);

break;

case 3: printf("\nEnter the source vertex to find the connectivity:\n ");

scanf("%d",&source);

m=1;

dfs(source);

for(i=1;i<=n;i++) {

if(b[i]==0)

m=0;

}

if(m==1)

printf("\nGraph is Connected\n");

else
printf("\nGraph is not Connected\n");

case 4: gra();break;
default: exit(0);

}

}

}

// End of Graph DFS & DFS Program 11



struct employee {
int id;
char name[15]; };
typedef struct employee EMP;
EMP emp[MAX];
int a1[MAX];
int creat(int num) {
int key;
key = num % 100;
return key;
}
int getemp(EMP emp[],int key)
{
printf("\nEnter emp id: \n");
scanf("%d",&emp[key].id);
printf("\nEnter emp name: \n");
fflush(stdin);
gets(emp[key].name);
return key;
}
void displa() {
int i, ch;
printf("\n1.Display ALL\n2.Filtered Display\n");
printf("\nEnter the choice:\n ");
scanf("%d",&ch);
if(ch == 1)
{
printf("\nThe hash table is:\n");
printf("\nHTKey\tEmpID\tEmpName\n");
for(i=0; i<MAX; i++)
printf("\n%d\t%d\t%s\n", i, emp[i].id, emp[i].name);
}
else
{
printf("\nThe hash table is:\n");
printf("\nHTKey\tEmpID\tEmpName\n");
for(i=0; i<MAX; i++)
if(a1[i]!=-1)
{
printf("\n%d\t%d\t%s\n", i, emp[i].id, emp[i].name);
continue;
}
}
}
void linear_prob(int key, int num)
{
int flag, i, count = 0; flag = 0;
if(a1[key]== -1)
{
a1[key]=getemp(emp, key);
}
else
{
printf("\nCollision Detected...!!!\n");
i = 0;
while(i < MAX)
{
if (a1[i] != -1)
count++;
else
i++;
}
printf("\nCollision avoided successfully using LINEAR PROBING\n");
if(count == MAX)
{
printf("\n Hash table is full\n");
displa(emp);
exit(1);
}
for(i=key; i<MAX; i++)
if(a1[i] == -1)
{
	a1[i] = num;
flag = 1;
break;
}
i = 0;
while((i < key) && (flag == 0))
{
if(a1[i] == -1)
{
a1[i] = num;
flag=1; break;
}
i++;
} // end while
} // end else
} // end linear_prob()
void tab()
{
int num, key, i;
int ans = 1;
clrscr();
printf("\nCollision handling by linear probing:\n ");
for (i=0; i < MAX; i++)
{
a1[i] = -1;
}
do
{
printf("\nEnter the data: \n");
scanf("%d", &num);
key=creat(num);
linear_prob(key,num);
printf("\nDo you wish to continue? (1/0): \n");
scanf("%d",&ans);
}while(ans);
displa(emp);
getch();
}

// End of HASH Program 12



void main()
{
	int r,p,s;
	clrscr();
printf("                PROUDHADEVARAYA INSTITUTE OF TECHNOLOGY"); 
printf("                                          VIJAYANAGARA\n ");
	printf("\n ●◆●◆●◆●◆●◆●◆●◆●◆ CREATED BY 3PG20CS BATCH ◆●◆●◆●◆●◆●◆●◆●◆●◆●\n");
	printf("\n ~~~~~~~~~~~~~~~~~ 3rd Sem D$A All LAB PROGRAMS ~~~~~~~~~~~~~~~~~\n");
	printf("\n1.Array \n2.String \n3.Stack \n4.Infix to Postfix Expression's \n5.Suffix Expression & Tower of Hanoi \n6.Circular Queue \n7.Singly Linked List [SLL] \n8.Doubly Linked List [DLL] \n9.Polynomial function \n10.Binary Search Tree [BST] \n11.Graph [BFS & DFS] \n12.Hash table [linear Probing] \n\n *NOTE : ℅ = Percentage and ñ = BackSlash n in Source code");
	printf("\n\nChoose The Program :\n");
	scanf("%d",&r);
	switch(r)
	{
		case 1: printf("\n1.View Code \n 2.Algorithm \n 3.Output \n 4.Exit\n");
		printf("\n Enter your Choice :\n");
		scanf("%d",&p);
		switch(p)
		{
			case 1: printf("#include<stdio.h>
#include<conio.h>
/* Global variables declaration */
int a[4], n, elem, i, pos;
/*Function Prototype and Definitions*/
void create() //creating an array
{
printf(''\ñ Enter the size of the array elements: '');
scanf(''℅d'', &n);
printf(''Enter the elements for the array:\ñ'');
for(i=0; i<n; i++)
scanf(''℅d'', &a[i]);
} //end of create()
void display() //displaying an array elements
{
int i;
printf(''\ñ The array elements are:\ñ'');
for(i=0; i<n; i++)
{
printf(''℅d\ T'', a[i]);
}
} //end of display()
void insert() //inserting an element in to an array
{
printf(''\ñ Enter the position for the new element: '');
scanf(''℅d'', &pos);
printf(''\ñ Enter the element to be inserted: '');
scanf(''℅d'', &elem);
for(i=n-1; i>=pos; i--)
{
a[i+1] = a[i];
}
a[pos] = elem;
n = n+1;
} //end of insert()
void del() //deleting an array element
{
printf(''\ñ Enter the position of the element to be deleted: '');
scanf(''℅d'', &pos);
elem = a[pos];
for(i=pos; i<n-1; i++)
{
a[i] = a[i+1];
}
n = n-1;
printf(''\ñ The deleted element is = ℅d'', elem);
}//end of delete()
void main()
{
	int ch;
clrscr();
do
{
printf(''\ñ\ñ--------Menu-----------\ñ'');
printf(''1.Create\ñ 2.Display\ñ 3.Insert\ñ 4.Delete\ñ 5.Exit\ñ'');
printf(''-------------------------------'');
printf(''\ñ Enter your choice: '');
scanf(''℅d'', &ch);
switch(ch)
{
case 1: create();
break;
case 2: display();
break;
case 3: insert();
break;
case 4: del();
break;
case 5: exit(0);
break;
default: printf(''\ñ Invalid choice:\ñ'');
break;
}
}
while(ch!=5);
getch();
} ") ;
			
			break;
			case 2 :printf(" Step 1: Start.
Step 2: Read N value.
Step 3: Read Array of N integer elements
Step 4: Print array of N integer elements.
Step 5: Insert an element at given valid position in an array.
Step 6: Delete an element at given  valid position from an array.
Step 7: Stop.
") ;break;
			case 3: array();break;
			case 4: return main();break;
			default : printf("\n Wrong choice\n");break;
		}
		            break;
		case 2:  printf("\n1.View Code \n2.Algorithm \n3.Output \n4.Exit\n");
		printf("\n Enter your Choice :\n");
		scanf("%d",&p);
		switch(p)
		{
			case 1: printf("#include<stdio.h>
#include<conio.h>
//Declarations
char str[100], pat[50], rep[50], ans[100];
int i, j, c, m, k, flag=0;
void stringmatch()
{
i = m = c = j = 0;
while(str[c]!='NULL')
{
if(str[m] == pat[i]) // ...... matching
{
i++; m++;
if(pat[i] == 'NULL') //.....found occurrences.
{
flag = 1;
//.... copy replace string in ans string.
for(k = 0; rep[k] != 'NULL'; k++, j++)
ans[j] = rep[k];
i = 0;
c = m;
}
} // if ends.
else //... mismatch
{
ans[j] = str[c];
j++;
c++;
m = c;
i = 0;
}//else ends
} //end of while
ans[j] = 'NULL';
} //end stringmatch()
void main()
{
clrscr();
printf(''\ñ Enter a main string \ñ'');
gets(str);
printf(''\ñ Enter a pattern string \ñ'');
fflush(stdin);
gets(pat);
printf(''\ñ Enter a replace string \ñ'');
flushall();
gets(rep);
stringmatch();
if(flag == 1)
printf(''\ñ The resultant string is\ñ ℅s'' , ans);
else
printf(''\ñ Pattern string NOT found\ñ'');
getch();
}") ;
			 
			 break;
			 case 2: printf("Step 1: Start.
Step 2: Read main string STR, pattern string PAT and replace string REP.
Step 3: Search / find the pattern string PAT in the main string STR.
Step 4: if PAT is found then replace all occurrences of PAT in main string STR with REP string.
Step 5: if PAT is not found give a suitable error message.
Step 6: Stop.
") ; break;
			case 3: string();break;
			case 4: return main();break;
			default : printf("\n Wrong choice\n");break;
		}
		             break;
		case 3:  printf("\n1.View Code \n2.Algorithm \n3.Output \n4.Exit\n");
		printf("\n Enter your Choice :\n");
		scanf("%d",&p);
		switch(p)
		{
			case 1: printf("#include<stdio.h>
#include<conio.h>
#define MAX 4
int stack[MAX], item;
int ch, top = -1, count = 0, status = 0;
/*PUSH FUNCTION*/
void push(int stack[], int item)
{
if (top == (MAX-1))
printf(''Stack is Overflow'');
else
{
stack[++top] = item;
status++;
}
}
/*POP FUNCTION*/
int pop(int stack[])
{
int ret;
if(top == -1)
printf(''Stack is Underflow'');
else
{
ret = stack[top--];
status--;
printf(''Popped element is ℅d'', ret);
}
return ret;
}
/* FUNCTION TO CHECK STACK IS PALINDROME OR NOT */
void palindrome(int stack[])
{
int i, temp;
temp = status;
for(i=0; i<temp; i++)
{
if(stack[i] == pop(stack))
count++;
}
if(temp==count)
printf(''Stack contents are Palindrome'');
else
printf(''Stack contents are not palindrome'');
}
/*FUNCTION TO DISPLAY STACK*/
void display(int stack[])
{
int i;
printf(''The stack contents are:'');
if(top == -1)
printf(''Stack is Empty'');
else{
for(i=top; i>=0; i--)
printf(''\ñ ------\ñ| ℅d |'', stack[i]);
printf(''\ñ'');
}
}
/*MAIN PROGRAM*/
void main()
{
clrscr();
do{
printf(''\ñ\ñ----MAIN MENU----\ñ'');
printf(''\ñ1. PUSH (Insert) in the Stack'');
printf(''\ñ2. POP (Delete) from the Stack'');
printf(''\ñ3. PALINDROME check using Stack'');
printf(''\ñ4. Exit (End the Execution)'');
printf(''\ñEnter Your Choice: '');
scanf(''℅d'', &ch);
switch(ch)
{
case 1: printf(''\ñEnter a element to be pushed: '');
scanf(''℅d'', &item);
push(stack, item);
display(stack);
break;
case 2 : item=pop(stack);
           display(stack);
           break;

case 3 : palindrome(stack);
           break;
case 4:exit(0); break;
default:printf(''\ñEND OF EXECUTION'');
}//end switch
}while (ch != 4);
getch();
 }") ;
			
			break;
			case 2 : printf("Step 1: Start.
Step 2: Initialize stack size MAX and top of stack -1.
Step 3: Push integer element on to stack and display the contents of the stack.
if stack is full give a message as ‘Stack is Overflow’.
Step 3: Pop element from stack along with display the stack contents.
if stack is empty give a message as ‘Stack is Underflow’.
Step 4: Check whether the stack contents are Palindrome or not.
Step 5: Stop.
") ; break;
			case 3: sk();break;
			case 4: return main();break;
			default : printf("\n Wrong choice\n");break;
		}
		             break;
		 case 4:  printf("\n1.View Code \n 2.Algorithm \n3.Output \n4.Exit\n");
		printf("\n Enter your Choice :\n");
		scanf("%d",&p);
		switch(p)
		{
			case 1: printf("#include<stdio.h>
#include<string.h>
#include<conio.h>
int F(char symbol)
{
switch(symbol)
{
case '+':
case '-':
return 2;
case '*':
case  '/':
return 4;
case  '^':
case  '$' : return 5;
case  '(' : return 0;
case  '#' : return -1;
default : return 8;
}
}
int G(char symbol)
{
switch(symbol)
{
case  '+'
:
case  '-':
return 1;
case  '*':
case  '/':
return 3;
case '^':
case '$':return 6;
case  '(': return 9;
case  ')': return 0;
default: return 7;
}
}
void infix_postfix(char infix[], char postfix[])
{
int top, j, i;
char s[30], symbol;
top = -1;
s[++top] = '#';
j = 0;
for(i=0; i < strlen(infix); i++)
{
symbol = infix[i];
while(F(s[top]) > G(symbol))
{
postfix[j] = s[top--];
j++;
}
if(F(s[top]) != G(symbol))
s[++top] = symbol;
else
top--;
}
while(s[top] != '#')
{
postfix[j++] = s[top--];
}
postfix[j] = 'NULL';
}
void main()
{
char infix[20], postfix[20];
clrscr();
printf(''\ñEnter a valid infix expression\ñ'');
flushall();
gets(infix);
infix_postfix(infix,postfix);
printf(''\nThe infix expression is:\ñ'');
printf (''℅s'',infix);
printf(''\ñThe postfix expression is:\ñ'');
printf (''℅s'',postfix);
getch();
}") ;
			
			 break;
			 case 2: printf("Step 1: Start.
Step 2: Read an infix expression with parenthesis and without parenthesis.
Step 3: convert the infix expression to postfix expression.
Step 4: Stop") ;break;
			case 3: expr();break;
			case 4: return main();break;
			default : printf("\n Wrong choice\n");break;
		}
		             break;
		 case 5:  printf("\n1.Suffix expression \n2.Tower of Hanoi \n3.Exit\n");
		printf("\n Enter your Choice :\n");
		scanf("%d",&s);
		switch(s)
		{
			case 1:  printf("\n1.View Code \n2.Algorithm\n3.Output \n3.Exit\n");
		printf("\n Enter your Choice :\n");
		scanf("%d",&p);
		switch(p)
		{
			case 1: printf("#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
double compute(char symbol, double op1, double op2)
{
switch(symbol)
{
case '+': return op1 + op2;
case '-': return op1 - op2;
case '*': return op1 * op2;
case '/': return op1 / op2;
case '$':
case '^': return pow(op1,op2);
default: return 0;
}
}
void main()
{
double s[20], res, op1, op2;
int top, i;
char postfix[20], symbol;
clrscr();
printf(''\ñ Enter the postfix expression:\ñ'');
flushall();
gets(postfix);
top=-1;
for(i=0; i<strlen(postfix); i++)
{
symbol = postfix[i];
if(isdigit(symbol))
s[++top] = symbol - '0';
else
{
op2 = s[top--];
op1 = s[top--];
res = compute(symbol, op1, op2);
s[++top] = res;
}
}
res = s[top--];
printf(''\ñ The result is : ℅f\ñ'', res);
getch();
}");
			break;
			case 2:printf("Step 1: Start.
Step 2: Read the postfix/suffix expression.
Step 3: Evaluate the postfix expression based on the precedence of the operator.
Step 4: Stop.
") ; break;
			case 3: suff(); break;
			case 4: return main();break;
			default : printf("\n Wrong choice\n");break;
		}
			break;
			case 2:  printf("\n1.View Code \n2.Algorithm \n3.Output \n4.Exit\n");
		printf("\n Enter your Choice :\n");
		scanf("%d",&s);
		switch(s)
		{
			case 1: printf("#include<stdio.h>
#include<conio.h>
#include<math.h>
void tower(int n, int source, int temp,int destination)
{
if(n == 0)
return;
tower(n-1, source, destination, temp);
printf(''\ñ Move disc ℅d from ℅c to ℅c\ñ'', n, source, destination);
tower(n-1, temp, source, destination);
}
void main()
{
int n;
clrscr();
printf(''\ñ Enter the number of discs: \ñ'');
scanf(''℅d'', &n);
tower(n, 'A', 'B', 'C');
printf(''\ñ\ñTotal Number of moves are: ℅d\n'', (int)pow(2,n)-1);
getch();
}");
			
			
			break;
			case 2 : printf("Step 1: Start.
Step 2: Read N number of discs.
Step 3: Move all the discs from source to destination by using temp rod.
Step 4: Stop.") ; break;
			case 3: hanoi();break;
			case 4: return main();break;
			default : printf("\n Wrong choice\n");break;
		}
			break;
			case 3: return main();break;
			default : printf("\n Wrong choice\n");break;
		}
		             break;
		 case 6: printf("\n1.View Code \n2.Algorithm \n 3.Output \n4.Exit\n");
		printf("\n Enter your Choice :\n");
		scanf("%d",&p);
		switch(p)
		{
			case 1: printf("#include<stdio.h>
#include<conio.h>
#define MAX 4
int ch, front = 0, rear = -1, count=0;
char q[MAX], item;
void insert()
{
if(count == MAX)
printf(''\ñ Queue is Full'');
else 
{
rear = (rear + 1) ℅ MAX;
q[rear]=item;
count++;
}
}
void del()
{
if(count == 0)
printf(''\ñ Queue is Empty'');
else
{
if(front > rear && rear==MAX-1)
{
front=0; rear=-1; count=0;
}
else
{
item=q[front];
printf(''\ñ Deleted item is: ℅c'',item);
front = (front + 1) ℅ MAX;
count--;
}
}
}
void display()
{
int i, f=front, r=rear;
if(count == 0)
printf(''\ñ Queue is Empty'');
else
{
printf(''\ñ Contents of Queue is:\ñ'');
for(i=f; i<=r; i++)
{
printf(''℅c\T'', q[i]);
f = (f + 1) ℅ MAX;
}
}
}
void main()
{
clrscr();
do
{
printf(''\ñ 1. Insert\ñ 2. Delete\ñ 3. Display\ñ 4. Exit'');
printf(''\ñ Enter the choice: '');
scanf(''℅d'', &ch);
fflush(stdin);
switch(ch)
{
case 1: printf(''\ñ Enter the character / item to be inserted: '');
scanf(''℅c'', &item);
insert();
break;
case 2: del();
break;
case 3: display();
break;
case 4: exit(0);
break;
}
}while(ch!=4);
getch();
 ") ;

			break;
			case 2: printf("Step 1: Start.
Step 2: Initialize queue size to MAX.
Step 3: Insert the elements into circular queue. If queue is full give a message as ‘queue is overflow”
Step 4: Delete an element from the circular queue. If queue is empty give a message as ‘queue is
underflow’.
Step 5: Display the contents of the queue.
Step 6: Stop") ; break;
			case 3: que();break;
			case 4: return main();break;
			default : printf("\n Wrong choice\n");break;
		}
		             break;
		 case 7: printf("\n1.View Code \n2.Algorithm \n3.Output \n4.Exit\n");
		printf("\n Enter your Choice :\n");
		scanf("%d",&p);
		switch(p)
		{
			case 1: printf("#include<stdio.h>
#include<conio.h>
int MAX=4, count;
struct student
{
char usn[10];
char name[30];
char branch[5];
int sem;
char phno[10];
struct student *next; //Self referential pointer.
};
typedef struct student NODE;
int countnodes(NODE *head)
{
NODE *p;
count=0;
p=head;
while(p!=NULL)
{
p=p->next;
count++;
}
return count;
}
NODE* getnode(NODE *head)
{
NODE *newnode;
newnode=(NODE*)malloc(sizeof(NODE)); //Create first NODE
printf(''\ñEnter USN, Name, Branch, Sem, Ph.No\ñ'');
flushall();
gets(newnode->usn);
flushall();
gets(newnode->name);
flushall();
gets(newnode->branch);
scanf(''℅d'',&(newnode->sem));
flushall();
gets(newnode->phno);
newnode->next=NULL; //Set next to NULL...
head=newnode;
return head;
}
NODE* display(NODE *head)
{
NODE *p;
if(head == NULL)
printf(''\ñNo student data\ñ'');
else
{
p=head;
printf(''\ñ----STUDENT DATA----\ñ'');
printf(''\ñUSN\TNAME\T\TBRANCH\TSEM\TPh.NO.'');
while(p!=NULL)
{
printf(''\n℅s\T℅s\T\T℅s\T℅d\T℅s'', p->usn, p->name, p->branch, p->sem, p->phno);
p = p->next; //Go to next node...
}
printf(''\ñThe no. of nodes in list is:℅d'',countnodes(head));
}
return head;
}
NODE* create(NODE *head)
{
NODE *newnode;
if(head==NULL)
{
newnode=getnode(head);
head=newnode;
}
else
{
newnode=getnode(head);
newnode->next=head;
head=newnode;
}
return head;
}
NODE* insert_front(NODE *head)
{
if(countnodes(head)==MAX)
printf(''\ñ List is Full / Overflow!!'');
else
head=create(head); //create()insert nodes at front.
return head;
}
NODE* insert_rear(NODE *head)
{
NODE *p, *newnode;
p=head;
if(countnodes(head) == MAX)
printf(''\ñ List is Full(QUEUE)!!'');
else
{
if(head == NULL)
{
newnode=getnode(head);
head=newnode; //set first node to be head
}
else
{
newnode=getnode(head);
while(p->next!=NULL)
{
p=p->next;
}
p->next=newnode;
}
}
return head;
}
NODE* insert(NODE *head)
{
int ch;
do
{
printf(''\ñ1.Insert at Front(First)\T 2.Insert at End(Rear/Last)\T 3.Exit'');
printf(''\ñ Enter your choice: '');
scanf(''℅d'', &ch);
switch(ch)
{
case 1: head=insert_front(head); break;
case 2: head=insert_rear(head); break;
case 3: break;
}
head=display(head);
}while(ch!=3);
return head;
}
NODE* delete_front(NODE *head)
{
NODE *p;
if(head==NULL)
printf(''\ñ List is Empty/Underflow (STACK/QUEUE)'');
else
{
p=head;
head=head->next; //Set 2nd NODE as head
free(p);
printf(''\ñ Front(first)node is deleted'');
}
return head;
}
NODE* delete_rear(NODE *head)
{
NODE *p, *q;
p=head;
while(p->next!=NULL)
{
p=p->next; //Go upto -1 NODE which you want to delete
}
q=p->next;
free(q);//Delete last NODE...
p->next=NULL;
printf(''\ñ Last(end) entry is deleted'');
return head;
}
NODE* del(NODE *head)
{
int ch;
do{
printf(''\ñ 1.Delete from Front(First)\T 2. Delete from End(Rear/Last))\T 3.Exit'');
printf(''\ñ Enter your choice: '');
scanf(''℅d'',&ch);
switch(ch)
{
case 1: head=delete_front(head);
break;
case 2: head=delete_rear(head);
break;
case 3: break;
}
head=display(head);
}while(ch!=3);
return head;
}
NODE* stack(NODE *head)
{
int ch;
do
{
printf(''\ñ SSL used as Stack...'');
printf(''\ñ 1.Insert at Front(PUSH) \T 2.Delete from Front(POP))\T 3.Exit'');
printf(''\ñEnter your choice: '');
scanf(''℅d'', &ch);
switch(ch)
{
case 1: head=insert_front(head); break;
case 2: head=delete_front(head); break;
case 3: break;
}
head=display(head);
}while(ch!=3);
return head;
}
NODE* queue(NODE *head)
{
int ch;
do
{
printf(''\ñ SSL used as Queue...'');
printf(''\n 1.Insert at Rear(INSERT) \T 2.Delete from Front(DELETE))\T 3.Exit'');
printf(''\ñ Enter your choice: '');
scanf(''℅d'', &ch);
switch(ch)
{
case 1: head=insert_rear(head); break;
case 2: head=delete_front(head); break;
case 3: break;
}
head=display(head);
}while(ch!=3);
return head;
}
void main()
{
int ch, i, n;
NODE *head;
head=NULL;
clrscr();
printf(''\ñ*----------Studednt Database-----------*'');
do
{
printf(''\ñ 1.Create\T 2.Display\T 3.Insert\T 4.Delete\T 5.Stack\T 6.Queue\T 7.Exit'');
printf(''\ñ Enter your choice: '');
scanf(''℅d'', &ch);
switch(ch)
{
case 1: printf(''\ñ How many student data you want to create: '');
scanf(''℅d'', &n);
for(i=0;i<n;i++)
head=create(head);//Call to Create NODE...
break;
case 2: head=display(head); //Call to Display...
break;
case 3: head=insert(head); //Call to Insert...
break;
case 4: head=del(head); //Call to delete
break;
case 5: head=stack(head);
break;
case 6: head=queue(head);
break;
case 7: exit(); //Exit...
}
}while(ch!=7);
 "); 
			break;
			case 2: printf("Step 1: Start.
Step 2: Read the value of N. (N student’s information)
Step 2: Create a singly linked list. (SLL)
Step 3: Display the status of SLL.
Step 4: Count the number of nodes.
Step 5: Perform insertion at front of list.
Step 6: Perform deletion at the front of the list.
Step 7: Perform insertion at end of the list.
Step 8: Perform deletion at the end of the list.
Step 9: Demonstrate how singly linked list can be used as stack.
Step 10: Demonstrate how singly linked list can be used as queue.
Step 11: Stop") ; break;
			case 3: sll();break;
			case 4: return main();break;
			default : printf("\n Wrong choice\n");break;
		}
		             break;
		  case 8: printf("\n1.View Code \n2. Algorithm \n3.Output \n4.Exit\n");
		printf("\n Enter your Choice :\n");
		scanf("%d",&p);
		switch(p)
		{
			case 1: printf("#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int MAX=4, count;
struct emp
{
int ssn;
char name[20];
char dept[10];
char desig[15];
int sal;
char phno[10];
struct emp *left;
struct emp *right;
};
typedef struct emp NODE;
int countnodes(NODE *head)
{
NODE *p;
count=0;
p=head;
while(p!=NULL)
{
p=p->right;
count++;
}
return count;
}
NODE* getnode(NODE *head)
{
NODE *newnode;
newnode=(NODE*)malloc(sizeof(NODE));
newnode->right=newnode->left=NULL;
printf(''\ñ Enter SSN, Name, Dept, Designation, Sal, Ph.No\n'');
scanf(''℅d'',&newnode->ssn);
flushall();
gets(newnode->name);
flushall();
gets(newnode->dept);
flushall();
gets(newnode->desig);
scanf(''℅d'',&newnode->sal);
flushall();
gets(newnode->phno);
head=newnode;
return head;
}
NODE* display(NODE *head)
{
NODE *p;
if(head==NULL)
printf(''\ñNo Employee data\ñ'');
else
{
p=head;
printf(''\ñ----EMPLOYEE DATA----\ñ'');
printf(''\ñSSN\TNAME\TDEPT\TDESINGATION\TSAL\T\TPh.NO.\ñ'');
while(p!=NULL)
{
printf(''\n℅d\T℅s\T℅s\T℅s\T\T℅d\T\T℅s\ñ'', p->ssn, p->name, p->dept, p->desig,
p->sal, p->phno);
p = p->right; //Go to next node...
}
printf(''\ñ The no. of nodes in list is: ℅d\ñ'',countnodes(head));
}
return head;
}
NODE* create(NODE *head)// creating & inserting at end.
{
NODE *p, *newnode;
p=head;
if(head==NULL)
{
newnode=getnode(head);
head=newnode;
}
else
{
newnode=getnode(head);
while(p->right!=NULL)
{
	p=p->right;
}
p->right=newnode;
newnode->left=p;
}
return head;
}
NODE* insert_end(NODE *head)
{
if(countnodes(head)==MAX)
printf(''\ñ List is Full!!\ñ'');
else
head=create(head);
return head;
}
NODE* insert_front(NODE *head)
{
NODE *p,*newnode;
if(countnodes(head)==MAX)
printf(''\ñList is Full!!\ñ'');
else
{
if(head==NULL)
{
newnode=getnode(head);
head=newnode; //set first node to be head
}
else
{
newnode=getnode(head);
newnode->right=head;
head->left=newnode;
head=newnode;
}
}
return head;
}
NODE* insert(NODE *head)
{
int ch;
do
{
printf(''\ñ 1.Insert at Front(First) \T 2.Insert at End(Rear/Last)\T 3.Exit\ñ'');
printf(''\ñ Enter your choice:\ñ'');
scanf(''℅d'', &ch);
switch(ch)
{
case 1: head=insert_front(head); break;
case 2: head=insert_end(head); break;
case 3: break;
}
head=display(head);
}while(ch!=3);
return head;
}
NODE* delete_front(NODE *head)
{
NODE *p;
if(head==NULL)
printf(''\ñ List is Empty (QUEUE)\ñ'');
else
{
p=head;
head=head->right;

free(p);
printf(''\ñ Front(first)node is deleted\ñ'');
}
return head;
}
NODE* delete_end(NODE *head)
{
NODE *p,*q;
p=head;
while(p->right!=NULL)
{
p=p->right; //Go upto -1 node which you want to delete
}
q=p->left;
q->right=NULL;
p->left=NULL;
free(p);//Delete last node...
printf(''\ñLast(end) entry is deleted\ñ'');
return head;
}
NODE* del(NODE *head)
{
int ch;
do {
printf(''\ñ1.Delete from Front(First)\T 2. Delete from End(Rear/Last))\T 3.Exit\ñ'');
printf(''\ñEnter your choice:\ñ'');
scanf(''℅d'', &ch);
switch(ch)
{
case 1: head=delete_front(head);
break;
case 2: head=delete_end(head);
break;
case 3: break;
}
head=display(head);
}while(ch!=3);
return head;
}
NODE* queue(NODE *head)
{
int ch, ch1, ch2;
do
{
printf(''\ñDLL used as Double Ended Queue\ñ'');
printf(''\ñ1.QUEUE- Insert at Rear & Delete from Front\ñ'');
printf(''\ñ2.QUEUE- Insert at Front & Delete from Rear\ñ'');
printf(''\ñ3.Exit\ñ'');
printf(''\ñEnter your choice:\ñ'');
scanf(''℅d'', &ch);
switch(ch)
{
case 1: do{
printf(''\ñ1.Insert at Rear\T 2.Delete from From Front\T 3.Exit\ñ'');
printf(''\ñEnter your choice:\ñ'');
scanf(''℅d'', &ch1);
switch(ch1)
{
case 1: head=insert_end(head); break;
case 2: head=delete_front(head); break;
case 3: break;
}
}while(ch1!=3);
break;
case 2: do{
printf(''\ñ1.Insert at Front\T 2.Delete from Rear\T 3.Exit\ñ'');
printf(''\ñEnter your choice: \ñ'');
scanf(''℅d'', &ch2);
switch(ch2)
{
case 1: head=insert_front(head); break;
case 2: head=delete_end(head); break;
case 3: break;
}
}while(ch2!=3);
break;
case 3: break;
}
}while(ch!=3);
head=display(head);
return head;
}
void main()
{
int ch, i, n;
clrscr();
NODE *head;
head=NULL;
clrscr();
printf(''\ñ----------Employee Database-----------\ñ'');
do
{
printf(''\ñ1.Create\T 2.Display\T 3.Insert\T 4.Delete\T 5.Queue\T 6.Exit\ñ'');
printf(''\ñ Enter your choice: \ñ'');
scanf(''℅d'', &ch);
switch(ch)
{
case 1: printf(''\ñHow many employees data you want to create: \ñ'');
scanf(''℅d', &n);
for(i=0;i<n;i++)
head=create(head);//Call to Create node...
break;
case 2: head=display(head); //Call to Display...
break;
case 3: head=insert(head); //Call to Insert...
break;
case 4: head=del(head); //Call to delete
break;
case 5: head=queue(head);
break;
case 6: exit(0); break;//Exit...
}
}while(ch!=6);
getch();
");
			
			
		    break;
		    case 2: printf("Step 1: Start.
Step 2: Read the value of N. (N student’s information)
Step 3: Create a doubly linked list. (DLL)
Step 4: Display the status of DLL.
Step 5: Count the number of nodes.
Step 6: Perform insertion at front of list.
Step 7: Perform deletion at the front of the list.
Step 8: Perform insertion at end of the list.
Step 9: Perform deletion at the end of the list. 
Step 10: Demonstrate how doubly linked list can be used as double ended queue.
Step 11: Stop.") ; break;
			case 3: dll(); break;
			case 4:return main();break;
			default : printf("\n Wrong choice\n");break;
		}
		              break;
		   case 9: printf("\n1.View Code \n2.Algorithm \n3.Output \n4.Exit\n");
		printf("\n Enter your Choice :\n");
		scanf("%d",&p);
		switch(p)
		{
			case 1: printf("#include <stdio.h>
#include <stdlib.h>
#include<math.h>
typedef struct polynomial
{
    float coeff;
    int x,y,z;
    struct polynomial *next;
}poly;
poly *p1,*p2,*p3;
poly* readpoly()
{
    poly *temp=(poly*)malloc(sizeof(poly));
    printf(''\ñ Enter coeff:'');
    scanf(''℅f'',&temp->coeff);
    printf(''Enter x expon:'');
    scanf(''℅d'',&temp->x);
    printf(''Enter y expon:'');
    scanf(''℅d'',&temp->y);
    printf(''Enter z expon:'');
    scanf(''℅d'',&temp->z);
    return temp;
}
poly* create()
{
    int n,i;
    printf(''\ñEnter no. of terms:'');
    scanf(''d'',&n);
    poly *temp=(poly*)malloc(sizeof(poly)),*t1=temp;
    for(i=0;i<n;i++,t1=t1->next)
      t1->next=readpoly();
    t1->next=temp;
    return temp;
}
void evaluate()
{
    float sum=0;
    int x,y,z;
    poly *t=p1->next;
    printf(''\ñ Enter x,y&z:\ñ'');
    scanf(''℅d'',&x);
    scanf(''℅d'',&y);
    scanf(''℅d'',&z);
    while(t!=p1)
    {
      sum+=t->coeff*pow(x,t->x)*pow(y,t->y)*pow(z,t->z);
      t=t->next;
    }
    printf(''\ñ Sum=℅f'',sum);
}
void display(poly *p)
{
    poly *t=p->next;
    while(t!=p)
    {
      if(t!=p->next&&t->coeff>0)
        putchar('+');
      printf(''℅.1fx^%dy^%dz^%d'',t->coeff,t->x,t->y,t->z);
      t=t->next;
    }
}
poly* attach(float coeff,int x,int y,int z,poly *p)
{
    poly *t=(poly*)malloc(sizeof(poly));
    t->coeff=coeff;
    t->x=x;
    t->y=y;
    t->z=z;
    p->next=t;
    return t;
}
poly* add()
{
    printf(''\ñ Polynomial1:\ñ'');
    p1=create();
    printf(''\ñ Polynomial2:\ñ'');
    p2=create();
    int flag;
    poly *t1=p1->next,*t2=p2->next,*t3;
    p3=(poly*)malloc(sizeof(poly));
    t3=p3;
    while(t1!=p1&&t2!=p2)
    {
        if(t1->x>t2->x)
          flag=1;
        else if(t1->y<t2->y)
          flag=-1;
        else if(t1->z==t2->z)
          flag=0;
        switch(flag)
        {
            case 0:t3=attach(t1->coeff+t2-                     >coeff,t1->x,t1->y,t1->z,                     t3);
                    t1=t1->next;
                    t2=t2->next;
                    break;
            case 1:t3=attach(t1->coeff,t1-                      >x,t1->y,t1->z,t3);
                    t1=t1->next;
                   break;
            case -1:t3=attach(t2->coeff,                        t2->x,t2->y,t2->z,t3);
                    t2=t2->next;
                    break;
        }
    }
    for(;t1!=p1;t1=t1->next)
        t3=attach(t1->coeff,t1->x,t1->y,t1->z,t3);
    for(;t2!=p2;t2=t2->next)
        t3=attach(t2->coeff,t2->x,t2->y,t2->z,t3);
    t3->next=p3;
    return p3;
}
int main()
{
   int ch;
   printf(''\ñ1.Represent and evaluate polynomial\ñ 2.Add 2 polynomials\nñ 3.Exit\ñ Enter choice:'');
   scanf(''℅d'',&ch);
   switch(ch)
   {
       case 1:p1=create();
              display(p1);
              evaluate();
              break;
       case 2:p3=add();
              printf(''\ñPolynomial1:\ñ'');
              display(p1);
              printf(''\ñ Polynomial2:\ñ'');
              display(p2);
              printf(''\ñP1+P2:\ñ'');
              display(p3);
              break;
       case 3:exit(0);
       default:printf(''\ñInvalid choice...!'');
   }
    return 0;
}
") ;
			break;
			case 2: printf("Step 1: Start.
Step 2: Read a polynomial.
Step 3: Represent the polynomial using singly circular linked list.
Step 3: Evaluate the given polynomial
Step 4: Read two polynomials and find the sum of the polynomials.
Step 5: Stop
") ; break;
			case 3: pol( ); break;
			case 4: return main();break;
			default : printf("\n Wrong choice\n");break;				
					}
		            break;
    case 10 : printf("\n1.View Code \n2.Algorithm \n3.Output \n4.Exit\n");
		printf("\n Enter your Choice :\n");
		scanf("%d",&p);
		switch(p)
		{
			case 1: printf("#include <stdio.h>
#include<conio.h>
#include <stdlib.h>

struct BST
{
int data;
struct BST *left;
struct BST *right;
};
typedef struct BST NODE;
NODE *node;
NODE* createtree(NODE *node, int data)
{
if (node == NULL)
{
NODE *temp;
temp= (NODE*)malloc(sizeof(NODE));
temp->data = data;
temp->left = temp->right = NULL;
return temp;
}
if (data < (node->data))
{
	node->left = createtree(node->left, data);
}
else if (data > node->data)
{
node -> right = createtree(node->right, data);
}
return node;
}
NODE* search(NODE *node, int data)
{
if(node == NULL)
printf(''\ñ Element not found\ñ'');
else if(data < node->data)
{
node->left=search(node->left, data);
}
else if(data > node->data)
{
node->right=search(node->right, data);
}
else
printf(''\ñElement found is: ℅d\ñ'', node->data);
return node;
}

void inorder(NODE *node)
{
if(node != NULL)
{
inorder(node->left);
printf(''℅d\t'', node->data);
inorder(node->right);
}
}
void preorder(NODE *node)
{
if(node != NULL)
{
printf(''℅d\t'', node->data);
preorder(node->left);
preorder(node->right);
}
}
void postorder(NODE *node)
{
if(node != NULL)
{
postorder(node->left);
postorder(node->right);
printf(''℅d\t'', node->data);
}
}
NODE* findMin(NODE *node)
{
if(node==NULL)
{
return NULL;
}
if(node->left)
return findMin(node->left);
else
return node;
}
NODE* del(NODE *node, int data)
{
NODE *temp;
if(node == NULL)
{
printf(''\ñ Element not found\ñ'');
}
else if(data < node->data)
{
node->left = del(node->left, data);
}
else if(data > node->data)
{
node->right = del(node->right, data);
}
else
{ /* Now We can delete this node and replace with either minimum element in the right sub tree or maximum element in the left subtree */
if(node->right && node->left)
{ /* Here we will replace with minimum element in the right sub tree */
temp = findMin(node->right);
node -> data = temp->data;
/* As we replaced it with some other node, we have to delete that node */
node -> right = del(node->right,temp->data);
 }
else
{
/* If there is only one or zero children then we can directly remove it from the tree and connect its parent to its child */
temp = node;
if(node->left == NULL)
node = node->right;
else if(node->right == NULL)
node = node->left;
free(temp); /* temp is longer required */
}
}
return node;
}
void main()
{
int data, ch, i, n;
NODE *root=NULL;
clrscr();
while (1)
{
printf(''\ñ 1.Insertion in Binary Search Tree'');
printf(''\ñ 2.Search Element in Binary Search Tree'');
printf(''\ñ 3.Delete Element in Binary Search Tree'');
printf(''\ñ 4.Inorder\ñ 5.Preorder\ñ 6.Postorder\ñ 7.Exit'');
printf(''\ñ Enter your choice:\ñ'');
scanf(''℅d'', &ch);
switch (ch)
{
case 1: printf(''\ñ Enter N value: \ñ'' );
scanf(''℅d'', &n);
printf(''\ñ Enter the values to create BST like(6,9,5,2,8,15,24,14,7,8,5,2)\ñ'');
for(i=0; i<n; i++)
{
scanf(''℅d'', &data);
root=createtree(root, data);
}
break;
case 2: printf(''\ñ Enter the element to search:\ñ'');
scanf(''℅d'', &data);
root=search(root, data);
break;
case 3: printf(''\ñEnter the element to delete:\ñ'');
scanf(''℅d'', &data);
root=del(root, data);
break;
case 4: printf(''\ñ Inorder Traversal: \ñ'');
inorder(root);
break;
case 5: printf(''\ñ Preorder Traversal: \ñ'');
preorder(root);
break;
case 6: printf(''\ñ Postorder Traversal: \ñ'');
postorder(root);
break;
case 7: exit(0);
default:printf(''\ñ Wrong option\ñ'');
break;
}
}
getch();
}");
			 
			 break;
			 case 2: printf("Step 1: Start.
Step 2: Create a Binary Search Tree for N elements.
Step 3: Traverse the tree in inorder.
Step 4: Traverse the tree in preorder
Step 6: Traverse the tree in postorder.
Step 7: Search the given key element in the BST.
Step 8: Delete an element from BST.
Step 9: Stop") ; break;
			case 3: bst();break;
			case 4:return main();break;
			default : printf("\n Wrong choice\n");break;
		}
		                 break;
		    case 11: printf("\n1.View Code \n2.Algorithm \n3.Output \n4.Exit\n");
		printf("\n Enter your Choice :\n");
		scanf("%d",&p);
		switch(p)
		{
			case 1: printf("#include<stdio.h>
#include<conio.h>
int a[10][10], n, m, i, j, source, s[10], b[10];
int visited[10];
void create()
{
printf(''\ñEnter the number of vertices of the digraph: '');
scanf(''℅d'', &n);
printf(''\ñ Enter the adjacency matrix of the graph:\ñ'');
for(i=1; i<=n; i++)
for(j=1; j<=n; j++)
scanf(''℅d'', &a[i][j]);
}
void bfs()
{
int q[10], u, front=0, rear=-1;
printf(''\ñ Enter the source vertex to find other nodes reachable or not:'');
scanf(''℅d'', &source);
q[++rear] = source;
visited[source] = 1;
printf(''\ñ The reachable vertices are: '');
while(front<=rear)
{
u = q[front++];
for(i=1; i<=n; i++)
{
if(a[u][i] == 1 && visited[i] == 0)
{
q[++rear] = i;
visited[i] = 1;
printf(''\ñ℅d'', i);
}
}
}
}
void dfs(int source)
{
int v, top = -1;
s[++top] = 1;
b[source] = 1;
for(v=1; v<=n; v++)
{
if(a[source][v] == 1 && b[v] == 0)
{
printf(''\ñ℅d -> ℅d'', source, v);
dfs(v);
}
}
}
void main()
{
int ch;
clrscr();
while(1)
{
printf(''\ñ1.Create Graph\ñ 2.BFS\ñ 3.Check graph connected or not(DFS)\ñ 4.Exit'');
printf(''\ñ Enter your choice:'');
scanf(''℅d'', &ch);
switch(ch)
{
case 1: create(); break;
case 2: bfs();
for(i=1;i<=n;i++)
if(visited[i]==0)
printf(''\ñ The vertex that is not rechable ℅d'',i);
break;
case 3: printf(''\ñ Enter the source vertex to find the connectivity: '');
scanf(''℅d'',&source);
m=1;
dfs(source);
for(i=1;i<=n;i++) {
if(b[i]==0)
m=0;
}
if(m==1)
printf(''\ñ Graph is Connected'');
else
printf(''\ñ Graph is not Connected'');
break;
default: exit(0);
}
}
}");
			
			
			
			break;
			case 2 : printf("Step 1: Start.
Step 2: Input the value of N nodes of the graph
Step 3: Create a graph of N nodes using adjacency matrix representation.
Step 3: Print the nodes reachable from the starting node using BFS.
Step 4: Check whether graph is connected or not using DFS.
Step 5: Stop.
") ; break;
			case 3: gra();break;
			case 4: return main();break;
			default : printf("\n Wrong choice\n");break;
		}
		                  break;
		     case 12:  printf("\n1.View Code \n2.Algorithm \n3.Output \n4.Exit\n");
		printf("\n Enter your Choice :\n");
		scanf("%d",&p);
		switch(p)
		{
			case 1: printf("#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct employee
 {
int id;
char name[15];
 };
typedef struct employee EMP;
EMP emp[MAX];
int a[MAX];
int create(int num)
 {
int key;
key = num ℅ 100;
return key;
}
int getemp(EMP emp[],int key)
{
printf(''\ñ Enter emp id: \ñ'');
scanf(''℅d'',&emp[key].id);
printf(''\ñEnter emp name: \ñ'');
flushall();
gets(emp[key].name);
return key;
}
void display() 
{
int i, ch;
printf(''\ñ1.Display ALL\ñ 2.Filtered Display\ñ'');
printf(''\ñ Enter the choice:\ñ'');
scanf(''℅d'',&ch);
if(ch == 1)
{
printf(''\ñ The hash table is:\ñ'');
printf(''\ñ HTKey\tEmpID\tEmpName\ñ'');
for(i=0; i<MAX; i++)
printf(''\n℅d\t℅d\t℅s\n'', i, emp[i].id, emp[i].name);
}
else
{
printf(''\ñ The hash table is:\ñ'');
printf(''\ñ HTKey\tEmpID\tEmpName\ñ'');
for(i=0; i<MAX; i++)
if(a[i] != -1)
{
printf(''\ñ℅d\t℅d\t℅s\ñ'', i, emp[i].id, emp[i].name);
continue;
}
}
}
void linear_prob(int key, int num)
{
int flag, i, count = 0; flag = 0;
if(a[key] == -1)
{
a[key]=getemp(emp, key);
}
else
{
printf(''\ñ Collision Detected...!!!\ñ'');
i = 0;
while(i < MAX)
{
if (a[i] != -1)
count++;
else
i++;
}
printf(''\ñCollision avoided successfully using LINEAR PROBING\ñ'');
if(count == MAX)
{
printf(''\ñ Hash table is full\ñ'');
display(emp);
exit(1);
}
for(i=key; i<MAX; i++)
if(a[i] == -1)
{
	a[i] = num;
flag = 1;
break;
}
i = 0;
while((i < key) && (flag == 0))
{
if(a[i] == -1)
{
a[i] = num;
flag=1; break;
}
i++;
} // end while
} // end else
} // end linear_prob()
void main()
{
int num, key, i;
int ans = 1;
clrscr();
printf(''\ñCollision handling by linear probing:\ñ'');
for (i=0; i < MAX; i++)
{
a[i] = -1;
}
do
{
printf(''\ñ Enter the data: \ñ'');
scanf(''℅d'', &num);
key=create(num);
linear_prob(key,num);
printf(''\ñDo you wish to continue? (1/0): \ñ'');
scanf(''℅d'',&ans);
}while(ans);
display(emp);
getch();
 }"); 
 	break;
 	case 2 : printf("Step 1: Start.
Step 2: Given a File of N employee records with a set K of Keys (4-digit) which uniquely determine
the records in file F.
Step 3: Assume that file F is maintained in memory by a Hash Table(HT) of m memory locations
with L as the set of memory addresses (2-digit) of locations in HT.
Step 3: Let the keys in K and addresses in L are Integers
Step 4: Hash function H: K ®L as H(K)=K mod m (remainder method)
Step 5: Hashing as to map a given key K to the address space L, Resolve the collision (if any) is
using linear probing.
Step6: Stop") ; break;
			case 3: tab(); break;
			case 4: return main(); break; 
		
		} 
		                   break;
		      default : printf(" Invalid Choice\n");
		                   break;
	}
	getch();
}