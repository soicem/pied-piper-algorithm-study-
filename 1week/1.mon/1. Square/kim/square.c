#include <stdio.h>
#include <stdlib.h>

#define SWAP(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

void bubble_sort(int list[], int n)
{
   int i, j, temp;

   for (i = n - 1; i > 0; i--)
   {
      for (j = 0; j < i; j++)
      {
         if (list[j]>list[j + 1])
            SWAP(list[j], list[j + 1], temp);
      }

   }
}

int square(int num)
{
   return num*num;
}

int main()
{
   int t_case;
   int * list;
   int result, count = 0;

   scanf("%d", &t_case);

   list = (int *)malloc(sizeof(int)*t_case);

   for (int i = 0; i < t_case; i++)
   {
      scanf("%d", &list[i]);
   }

   bubble_sort(list, t_case);

   for (int i = 0; i < t_case - 2; i++)
   {

      for (int j = i + 1; j < t_case - 1; j++)
      {
         if (list[i]>1000 && list[j]>1000)
            return 0;
         result = square(list[i]) + square(list[j]);
         for (int k = j + 1; k < t_case; k++){
            if (result == list[k])
            {
               printf("%d ", result);
               count++;
            }
         }
      }
   }
   if (count == 0)
      printf("0\n");
   else
      printf("\n");

}