#ifndef v1_se_linux_options_TEST
#define v1_se_linux_options_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_se_linux_options_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_se_linux_options.h"
v1_se_linux_options_t* instantiate_v1_se_linux_options(int include_optional);



v1_se_linux_options_t* instantiate_v1_se_linux_options(int include_optional) {
  v1_se_linux_options_t* v1_se_linux_options = NULL;
  if (include_optional) {
    v1_se_linux_options = v1_se_linux_options_create(
      "0",
      "0",
      "0",
      "0"
    );
  } else {
    v1_se_linux_options = v1_se_linux_options_create(
      "0",
      "0",
      "0",
      "0"
    );
  }

  return v1_se_linux_options;
}


#ifdef v1_se_linux_options_MAIN

void test_v1_se_linux_options(int include_optional) {
    v1_se_linux_options_t* v1_se_linux_options_1 = instantiate_v1_se_linux_options(include_optional);

	cJSON* jsonv1_se_linux_options_1 = v1_se_linux_options_convertToJSON(v1_se_linux_options_1);
	printf("v1_se_linux_options :\n%s\n", cJSON_Print(jsonv1_se_linux_options_1));
	v1_se_linux_options_t* v1_se_linux_options_2 = v1_se_linux_options_parseFromJSON(jsonv1_se_linux_options_1);
	cJSON* jsonv1_se_linux_options_2 = v1_se_linux_options_convertToJSON(v1_se_linux_options_2);
	printf("repeating v1_se_linux_options:\n%s\n", cJSON_Print(jsonv1_se_linux_options_2));
}

int main() {
  test_v1_se_linux_options(1);
  test_v1_se_linux_options(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_se_linux_options_MAIN
#endif // v1_se_linux_options_TEST
