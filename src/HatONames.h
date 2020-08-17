#ifndef _HAT_O_NAMES_GUARD
#define _HAT_O_NAMES_GUARD

#define HON_MAX_FULL_NAME_LEN 128
#define HON_MAX_NICK_NAME_LEN 128
#define HON_MAX_NAMES 30

typedef struct HON_name {
  char full_name[HON_MAX_FULL_NAME_LEN];
  char nickname[HON_MAX_NICK_NAME_LEN];
} HON_name;

typedef struct HON_hat {
  HON_name Names[HON_MAX_NAMES];
  int name_count;
} HON_hat;

struct hatONames {
  int (*InitializeHat)(HON_hat*, char*);
  int (*RemoveName)(HON_hat*);
  HON_name (*PullName)(HON_hat);
};

extern const struct hatONames HatONames;

#endif
