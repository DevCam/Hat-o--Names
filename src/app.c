#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "HatONames.h"

int main(int argc, char *argv[])
{
  HON_hat hat;
  HatONames.InitializeHat(&hat, "./data/names");

  char cmd[10];
  printf("[p]ull name, [pr]Pull And remove, [e]xit \n");

  while(fgets(cmd, 10, stdin))
  {
    if(!strcmp("p\n", cmd))
    {
      HON_name pulled = HatONames.PullName(hat);
      if(pulled.full_name[0] == '\0')
      {
        printf("Hat ran out of names :(\n");
      } else {
        printf("%s was selected!\n", pulled.nickname);
        int wut = HatONames.RemoveName(&hat, pulled);
      }
    }
    else if(!strcmp("pr\n", cmd))
    {
      HON_name pulled = HatONames.PullName(hat);

      if(pulled.full_name[0] == '\0')
      {
        printf("Hat ran out of names :(\n");
      } else {
        printf("%s was selected!\n", pulled.nickname);
        int wut = HatONames.RemoveName(&hat, pulled);
      }
    }
    else if(!strcmp("e\n", cmd))
      break;
    else
    {
      printf("Not implemented :(\n");
    }
  }
  return 0;
}
