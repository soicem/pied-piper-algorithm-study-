#include <stdio.h>
#include <math.h>

typedef struct _point
{
   int x;
   int y;
   int z;
}Point;

int square(int num)
{
   return num*num;
}

int distance(int X1, int Y1, int Z1, int X2, int Y2, int Z2, int px, int py, int pz)
{
   int dx = X2 - X1;
   int dy = Y2 - Y1;
   int dz = Z2 - Z1;
   double nearX, nearY, nearZ;

   double result;

   double t = (double)((px - X1) * dx + (py - Y1) * dy + (pz - Z1) * dz) / double(square(dx) + square(dy) + square(dz));

   if (t < 0)
   {
      dx = px - X1;
      dy = py - Y1;
      dz = pz - Z1;

   }
   else if (t > 1)
   {
      dx = px - X2;
      dy = py - Y2;
      dz = pz - Z2;
   }
   else
   {
      nearX = X1 + t * dx;
      nearY = Y1 + t * dy;
      nearZ = Z1 + t * dz;

      dx = px - nearX;
      dy = py - nearY;
      dz = pz - nearZ;
   }

   result = sqrt(double(square(dx) + square(dy) + square(dz)));

   printf("t = %f orignal = %f \n", t, result);

   return ceil(result);
}

int main()
{
   int i;
   Point p[3];

   for (i = 0; i < 3; i++)
   {
      scanf("%d%d%d", &p[i].x, &p[i].y, &p[i].z);
   }

   printf("%d\n", distance(p[0].x, p[0].y, p[0].z, p[1].x, p[1].y, p[1].z, p[2].x, p[2].y, p[2].z));

}