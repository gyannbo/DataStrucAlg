#include <stdlib.h>
#include <stdio.h>

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

unsigned int ListToUint(struct ListNode *list)
{



struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    
}


unsigned int	GetDigNum(unsigned int number)
{
	int result = 0;
	if (!number)
		return (1);
	while(number)
	{
		number /= 10;
		result++;
	}
	return result;
}
			
struct ListNode	*FillList(unsigned int number, unsigned int NumDig)
{
	struct ListNode *list;
	if (NumDig)
		list = malloc(sizeof(struct ListNode));
	else
		return (NULL);
	if (!list)
		exit(-1);
	list->val = number % 10;
	list->next = FillList((number / 10), (NumDig - 1));
	return (list);
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
	unsigned int FirstNum = 765;
	unsigned int SecondNum = 34;
	struct ListNode *FirstList = FillList(FirstNum, GetDigNum(FirstNum));
	struct ListNode *SecondList = FillList(SecondNum, GetDigNum(SecondNum));
	struct ListNode *result;

	TestListVal(FirstList);
	TestListVal(SecondList);
	result = addTwoNumbers(FirstList, SecondList);
	return (0);
}


	// tests  GetDigNum //	
//	printf("%d\n",	GetDigNum(765));
//	printf("%d\n",	GetDigNum(0));
//	printf("%d\n",	GetDigNum(99920));

	

