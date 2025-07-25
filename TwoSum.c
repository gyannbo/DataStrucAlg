// given an array, return the indices of two number that add to a given sum
// example :
// array[] = {1, 2, 3, 4}
// target = 5
// answer[2] ={0, 3}

#include <stdlib.h>
#include <stdio.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
	int	indexFirstNum = 0;
	int	indexSecNum = 1;

	int *answer = malloc(sizeof(int) * 2);
	if (!answer)
		return NULL;
	while(indexFirstNum < numsSize)
	{
		while(indexSecNum < numsSize) 
		{
			if (nums[indexFirstNum] + nums[indexSecNum] == target)
			{
				answer[0] = indexFirstNum;
				answer[1] = indexSecNum;
				*returnSize = 2;
				return answer;
			}
			indexSecNum++;
		}
		indexSecNum = (indexFirstNum + 2);
		indexFirstNum++;
	}
	return (NULL);
}

int	main()
{
	int nums[4] = {1, 2, 3, 4};
	int target = 5;
	int	*ans = NULL;
	int returnSize = 0;

	ans = twoSum(nums, 4, target, &returnSize);
	printf("%d \n%d\n", ans[0], ans[1]);
	free(ans);
	return (0);
}	


// check the hash tables to do the solution that is more performant, and understand why		
