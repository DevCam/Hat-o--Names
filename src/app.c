#include <stdio.h>
#include <stdlib.h>
#include "HatONames.h"

int main(void)
{
  HON_hat hat;
  HatONames.InitializeHat(&hat, "./data/names");
  return 0;
}
