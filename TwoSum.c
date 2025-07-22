#include <stdlib.h>
#include <stdio.h>



/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
   int	i = 0;
   int	y = 0;

	int *ans = malloc(sizeof(int) * 2);
	if (!ans)
		return NULL;
	while(i < numsSize)
	{
		while(y < numsSize) 
		{
			if (nums[i] + nums[y] == target)
			{
				ans[0] = i;
				ans[1] = y;
				return ans;
			}
			y++;
		}
		y = 0;
		i++;
	}
	return (NULL);
}

int	main()
{
	int nums[4] = { 1, 2, 3, 4};
	int target = 3;
	int	*ans;

	ans = twoSum(nums, 4, target, NULL);
	printf("%d \n%d\n", ans[0], ans[1]);
	free(ans);
	return (0);
}	
		
