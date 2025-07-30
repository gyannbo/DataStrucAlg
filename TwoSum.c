#include <stdlib.h>
#include <stdio.h>
#include <uthash.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
   int	i = 0;
   int	y = 1;

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
				*returnSize = 2;
				return ans;
			}
			y++;
		}
		y = (i + 2);
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



// Leetcode hashmap solution using uthash library
//
//int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
//    struct hashTable {
//        int key;
//        int value;
//        UT_hash_handle hh;
//    } *hashTable = NULL, *item, *tmpItem;
//
//    for (int i = 0; i < numsSize; i++) {
//        HASH_FIND_INT(hashTable, &nums[i], item);
//        if (item) {
//            int* result = malloc(sizeof(int) * 2);
//            result[0] = item->value;
//            result[1] = i;
//            *returnSize = 2;
//            HASH_ITER(hh, hashTable, item, tmpItem) {
//                HASH_DEL(hashTable, item);
//                free(item);
//            }
//            return result;
//        }
//        item = malloc(sizeof(struct hashTable));
//        item->key = target - nums[i];
//        item->value = i;
//        HASH_ADD_INT(hashTable, key, item);
//    }
//    HASH_ITER(hh, hashTable, item, tmpItem) {
//        HASH_DEL(hashTable, item);
//        free(item);
//    }
//    *returnSize = 0;
//    // If no valid pair is found, return an empty array
//    return malloc(sizeof(int) * 0);
//}
