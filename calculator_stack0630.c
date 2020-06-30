/*******************************/
/* NAME : Stack Calculator     */
/* 1자리수만 가능              */
/* 간단한 계산만 가능          */
/* ()안에서 계산 정확하지 않음 */
/* DATE : 2020.06.30           */
/*******************************/

#include<stdio.h>
#include<string.h>

#define MAX   100
#define TRUE  1
#define FALSE 0

char Operator_Stack[100];
char Operand_Stack [100];
int  Operator_Top;
int  Operand_Top;

void Create_Stack(void);
void Operator_Push(char);
void Operand_Push(int);
char Operator_Pop(void);
int Operand_Pop(void);
int Empty_Operator_Stack(void);
int Empty_Operand_Stack(void);
int CreaterOpr(char, char);
int calculate(int, int, char);


void main(void)
{
	char buf[80];
	int len, i;
	int opn1, opn2;
	char opr, c;
	char tmpopr;

	Create_Stack();
	memset(buf, 0x00, sizeof(buf));
	memset(&Operator_Stack, 0x00, sizeof(Operator_Stack));
	memset(&Operand_Stack, 0x00, sizeof(Operand_Stack));
	memcpy(buf, "1-2*(3*1+4*2)", strlen("1-2*(3*1+4*2)"));
	len = strlen(buf);

	i = 0;
	while (i < len)
	{
		c = buf[i++];
		if (c == ' ')
			continue;
		else if (c <= '9' && c >= '0')
			Operand_Push((int)(c - '0'));
		else if (c == '+' || c == '-' || c == '*' || c == '/')
		{
			if (Empty_Operator_Stack())
				Operator_Push(c);
			else
			{
				opr = Operator_Pop();
				if (CreaterOpr(opr, c))
				{
					opn2 = Operand_Pop();
					opn1 = Operand_Pop();
					opn1 = calculate(opn1, opn2, opr);
					Operand_Push(opn1);
					Operator_Push(c);
				}
				else
				{
					Operator_Push(opr);
					Operator_Push(c);
				}
			}
		}
		else if (c == '(')
		{
			Operator_Push(c);
		}
		else if (c == ')')
		{
			do {
				tmpopr = Operator_Pop();
				if (tmpopr != '(')
				{
					opn2 = Operand_Pop();
					opn1 = Operand_Pop();
					opn1 = calculate(opn1, opn2, tmpopr);
					Operand_Push(opn1);
				}
			} while (tmpopr != '(');
		}
	}
	while (!Empty_Operator_Stack()) {
		opn2 = Operand_Pop();
		printf("opn2 = [%d]\n", opn2);
		opn1 = Operand_Pop();
		printf("opn1 = [%d]\n", opn1);
		opr = Operator_Pop();
		if(opr != NULL)
		    opn2 = calculate(opn1, opn2, opr);
		Operand_Push(opn2);
		printf("result = %d\n", opn2);
	}
	printf("%s = %d \n", buf, Operand_Pop());
}


void Create_Stack(void)
{
	Operator_Top = 0;
	Operand_Top = 0;
}

void Operator_Push(char opr)
{

	Operator_Stack[Operator_Top++] = opr;
}

void Operand_Push(int opn)
{
	Operand_Stack[Operand_Top++] = opn;
}

char Operator_Pop(void)
{
	return Operator_Stack[--Operator_Top];
}

int Operand_Pop(void)
{
	return Operand_Stack[--Operand_Top];
}

int Empty_Operator_Stack(void)
{
	if (Operand_Top == 0)
		return TRUE;
	else
		return FALSE;
}

int Empty_Operand_Stack(void)
{
	if (Operand_Top == 0)
		return TRUE;
	else
		return FALSE;
}

int CreaterOpr(char opr1, char opr2)
{
	if (opr1 == '*' || opr2 == '/')
	{
		if (opr2 == '+' || opr2 == '-')
			return TRUE;
		else
			return FALSE;
	}
	else
		return FALSE;
}

int calculate(int opn1, int opn2, char opr)
{
	switch (opr) {
	case '+': opn1 = opn1 + opn2;
		break;
	case '-': opn1 = opn1 - opn2;
		break;
	case '*': opn1 = opn1 * opn2;
		break;
	case '/': opn1 = opn1 / opn2;
		break;
	}
	return opn1;
}