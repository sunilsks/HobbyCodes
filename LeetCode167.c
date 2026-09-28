#ifdef Linus

You are given a 1-indexed array of integers numbers that is already sorted in non-decreasing order.
Find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.
Return the indices of the two numbers index1 and index2 as an integer array [index1, index2] of length 2.
The tests are generated such that there is exactly one solution. You may not use the same element twice.
Your solution must use only constant extra space.
Example 1:
Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].

#endif
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) 
{
    int* ReturnArray = (int *) malloc(2 * sizeof(int));
    int left = 0;
    int right = (numbersSize - 1);
    *returnSize = 2;
    if(ReturnArray != NULL)
    {
        while(left < right)
        {
            if((numbers[left]) + (numbers[right]) == target)
            {
                ReturnArray[0] = left+1;
                ReturnArray[1] = right+1;
                return(ReturnArray); 
            }
            else if((numbers[left]) + (numbers[right]) > target)
            {
                right--;
            }
            else if ((numbers[left]) + (numbers[right]) < target)
            {
                left++;
            }
            else
            {
                // dont know
            }
        }


        for(int i=0;i<numbersSize;i++)
        {
            if((numbers[0]) + (numbers[i]) == target)
            {
                ReturnArray[0] = i;
                ReturnArray[1] = numbers[0];
            }
        }
    }

    return ((int*)NULL);
}