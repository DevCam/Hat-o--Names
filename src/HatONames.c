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
  int r = rand() % hat.name_count;

  for(int i = r; i < hat.name_count + r; i++)
    if(hat.Names[i % hat.name_count].full_name[0] != '\0')
      return hat.Names[i % hat.name_count];

  HON_name anon = {
    .full_name = '\0',
    .nickname = '\0'
  };

  return anon;
}

int HON_RemoveName(HON_hat* hat, HON_name toRemove)
{
  for(int i=0; i < hat->name_count; i++)
  {
    if(!strcmp(hat->Names[i].full_name, toRemove.full_name))
    {
      hat->Names[i].full_name[0] = '\0';
      hat->Names[i].nickname[0] = '\0';
      return 1;
    }
  }
  return 0;
}


// Initialize library struct
const struct hatONames HatONames = {
  .InitializeHat = HON_InitializeHat,
  .RemoveName = HON_RemoveName,
  .PullName = HON_PullName
};