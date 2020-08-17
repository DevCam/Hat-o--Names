#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "HatONames.h"

void NotImplementedErr(void** args){fprintf(stderr, "FUNCTION_NOT_IMPLEMENTED");}

int HON_InitializeHat(HON_hat* hat, char* dataPath)
{
  FILE* data = fopen(dataPath, "r");
  srand(time(NULL));

  if(hat == NULL || dataPath == NULL)
    return 1;

  const int nameBufferSize = HON_MAX_FULL_NAME_LEN + HON_MAX_NICK_NAME_LEN;
  char nameBuffer[nameBufferSize];

  int nameCount = 0;
  while(fgets(nameBuffer, nameBufferSize, data) != NULL)
  {
    char* fullName = strtok(nameBuffer, ",");
    char* nickName = strtok(NULL, ",");

    if(strchr(nickName, '\n') != NULL)
      nickName[strlen(nickName)-1] = '\0';

    strcpy(hat->Names[nameCount].full_name, fullName);
    strcpy(hat->Names[nameCount].nickname, nickName);
    nameCount++;
  }
  hat->name_count = nameCount;
  return 0;
}

HON_name HON_PullName(HON_hat hat)
{
  // Get random name
}

// Initialize library struct
const struct hatONames HatONames = {
  .InitializeHat = HON_InitializeHat,
  .RemoveName = NotImplementedErr,
  .PullName = HON_PullName
};