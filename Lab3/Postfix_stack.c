#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

#define MAX 100
#define USER_LIMIT 100

int  STACK[MAX];
int top = -1;

void push (int item)
{

    printf("\n Element %d is successfully pushed in the stack", item);
    if (top == MAX-1)
    {
        printf("Overflow stack!!");
        return;
    }
    else
    {
        top ++;
        STACK[top] = item;
    }
}

int pop()
{
    int temp;
    printf( "\n %d is popped from stack", STACK[top]);
    if(top == -1)
    {
        printf("\n Underflow detected");
        return;
    }
    else
    {
        temp = STACK[top];
        top--;
        return temp;
    }
}

void display()
{
    int i;
    printf("\n Elements in the stack are:");
    for(i=top; i>=0;i--)
    {
        printf("%d, ", STACK[i]);
    }
    printf("\n");
}

void stack_postfix(char arr[])
{

    int i, oper_1, oper_2, final_val;

    for (i =0; arr[i ]!= '$' ;i ++)
        {
            if( isdigit( arr[i]) )
            {
                push( arr[i]-'0');
                display() ;
            }
            else if(arr[i]=='+' || arr[i]== '-' || arr[i]== '*' || arr[i]=='/' || arr[i]=='^')
            {
                oper_1 = pop();
                oper_2 = pop();
                switch(arr[i])
                {
                    case '+':  final_val = oper_1 + oper_2;
                                     printf("\n Performing the addition operation of %d and %d", oper_1, oper_2);
                                     printf("\n %d + %d = %d\n ", oper_1, oper_2, final_val);
                                     break;
                    case '-': final_val = oper_2 - oper_1;
                                    printf("\n Performing the subtraction operation by subtracting %d from %d", oper_1, oper_2);
                                    printf("\n %d - %d = %d\n ", oper_2, oper_1, final_val);
                                    break;
                    case '*': final_val = oper_1*oper_2;
                                    printf("\n Performing the multiplication operation of %d and %d", oper_1, oper_2);
                                    printf("\n %d * %d = %d\n", oper_1, oper_2, final_val);
                                    break;
                    case '/': final_val = oper_2/oper_1;
                                    printf("\n Performing the division operation where divisor is %d and dividend is %d", oper_1, oper_2);
                                    printf("\n %d / %d = %d\n", oper_2, oper_1, final_val);
                                    break;
                    case '^': final_val = pow(oper_2,oper_1);
                                    printf("\n %d to the power %d", oper_2, oper_1);
                                    printf("\n %d ^ %d = %d\n", oper_2, oper_1, final_val);
                                    break;
                }
                push(final_val);
                display();
            }
        }
}

int main ()
{
    int i;
    printf ("\t\t POSTFIX EXPRESSION USING STACK \n\n");
    char array[ USER_LIMIT ];
    printf (" Enter the postfix expression ( Use '$' to indicate end of string :)\n");
    for (i =0;i< USER_LIMIT ;i ++)
    {
    scanf ("%c" ,& array[i]);
    if( array[i ]== '$')
    {
        break ;
        }
    }
    printf ("\n");
    stack_postfix( array );
    printf ("\n The evaluated solution for the postfix expression is: %d",pop ());
    return 0;
 }
