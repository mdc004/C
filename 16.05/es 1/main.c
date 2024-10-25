#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void crea_file_random();
int main()
{
    crea_file_random();
    return 0;
}


void crea_file_random()
{ int i;
  FILE *ptr;


  ptr=fopen("random.txt","w");


  if (ptr==NULL)
  {
      printf("\nNon e' stato possibile aprire il file!\n");
      exit(1);
  }

  srand(time(NULL));
  for (i=0;i<20;i++)
  {
    fprintf(ptr,"%d \n",(rand()%31)-11);
  }
fclose(ptr);
}
