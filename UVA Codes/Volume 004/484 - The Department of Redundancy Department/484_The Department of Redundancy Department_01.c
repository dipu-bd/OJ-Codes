#include <stdio.h>
#include <stdlib.h>

#define SIZE 10000

typedef struct
{
    int num;
    int freq;
} list;

int indx=0;

int main()
{
    int i, n;
    list *nums = calloc(10000,sizeof(list));

    while(scanf("%d",&n)==1)
    {
        i = search(n,nums);
        if(i<0) i=indx++;
        nums[i].num = n;
        nums[i].freq++;
    }

    for(i=0;i<indx;i++)
        printf("%d %d\n",nums[i].num, nums[i].freq);

    return 0;
}

int search(int n, list *nums)
{
    int i;
    for(i=0;i<indx;i++)
        if(nums[i].num == n) return i;
    return -1;
}
