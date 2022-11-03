#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define F 10
#define C 15

int matrix(int m[F][C]){
   int i, j;
   for(i=0, j=0;i<F&&m[i][j]>=0;) {
       for (j = 0; j < C && m[i][j] >= 0; j++);
       if(j==C) {
           i++;
           j=0;
       }

   }
    return (i==F);
}