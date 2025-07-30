#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode {
	int val;
	struct ListNode *next;
};

double MyPow(unsigned int num, short pow)
{
	double x = 1;

	while (pow--)
	{
		x *= num;
	}
	return x;
}

double ListToUint(struct ListNode *list)
{
	double num = 0;
	short power = 0;
	while (list)
	{
		num += ((double)list->val * MyPow(10, power));
		printf("%f\n", num);
		power++;
		list = list->next;
	}
	return (num);
}

unsigned int	GetDigNum(double number)
{
	int result = 0;
	if (!number)
		return (1);
	while(number >= 1)
	{
		number /= 10;
		result++;
	}
	return result;
}
			
struct ListNode	*FillList(double number, unsigned int NumDig)
{
	struct ListNode *list;
	if (NumDig)
		list = malloc(sizeof(struct ListNode));
	else
		return (NULL);
	if (!list)
		exit(-1);
	list->val = fmod(number, 10);
	list->next = FillList((number / 10), (NumDig - 1));
	return (list);
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	double first = ListToUint(l1);
	double second = ListToUint(l2);
	double result = (double)first + (double)second;

//	printf("%f\n", first);
//	printf("%f\n", second);
//	printf("voici %f\n", result);
	return (FillList(result, GetDigNum(result)));
}

void TestListVal(struct ListNode *list)
{
	struct ListNode *temp;

	while(list)
	{
		printf("%d", list->val);
		temp = list;
		list = list->next;
		free(temp);
	}
	printf("\n");
}

int main()
{
	double SecondNum = 11111111111;
	double FirstNum = 11111111111;
	struct ListNode *FirstList = FillList(FirstNum, GetDigNum(FirstNum));
	struct ListNode *SecondList = FillList(SecondNum, GetDigNum(SecondNum));
	struct ListNode *result;

	result = addTwoNumbers(FirstList, SecondList);
	printf("first\n");
	TestListVal(FirstList);
	printf("sec\n");
	TestListVal(SecondList);
	printf("\n");
	TestListVal(result);
	return (0);
}


// JE DOIS REFAIRE AVEC UNE AUTRE METHODE QUI NE CONVERTI PAS EN INT LES NOMBRE MAIS FAIT DES OPERATIONS SUR LES LIST DIRECTEMENT

	// tests  GetDigNum //	
//	printf("%d\n",	GetDigNum(765));
//	printf("%d\n",	GetDigNum(0));
//	printf("%d\n",	GetDigNum(99920));


	
