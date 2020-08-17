#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "HatONames.h"

int main(int argc, char *argv[])
{
  HON_hat hat;
  HatONames.InitializeHat(&hat, "./data/names");

  HON_name person = HatONames.PullName(hat);
  printf("%s was selected!\n", person.nickname);
  return 0;
}
