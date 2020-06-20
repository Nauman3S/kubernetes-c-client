#ifndef v1_controller_revision_TEST
#define v1_controller_revision_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_controller_revision_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_controller_revision.h"
v1_controller_revision_t* instantiate_v1_controller_revision(int include_optional);

#include "test_v1_object_meta.c"


v1_controller_revision_t* instantiate_v1_controller_revision(int include_optional) {
  v1_controller_revision_t* v1_controller_revision = NULL;
  if (include_optional) {
    v1_controller_revision = v1_controller_revision_create(
      "0",
      0,
      "0",
       // false, not to have infinite recursion
      instantiate_v1_object_meta(0),
      56
    );
  } else {
    v1_controller_revision = v1_controller_revision_create(
      "0",
      0,
      "0",
      NULL,
      56
    );
  }

  return v1_controller_revision;
}


#ifdef v1_controller_revision_MAIN

void test_v1_controller_revision(int include_optional) {
    v1_controller_revision_t* v1_controller_revision_1 = instantiate_v1_controller_revision(include_optional);

	cJSON* jsonv1_controller_revision_1 = v1_controller_revision_convertToJSON(v1_controller_revision_1);
	printf("v1_controller_revision :\n%s\n", cJSON_Print(jsonv1_controller_revision_1));
	v1_controller_revision_t* v1_controller_revision_2 = v1_controller_revision_parseFromJSON(jsonv1_controller_revision_1);
	cJSON* jsonv1_controller_revision_2 = v1_controller_revision_convertToJSON(v1_controller_revision_2);
	printf("repeating v1_controller_revision:\n%s\n", cJSON_Print(jsonv1_controller_revision_2));
}

int main() {
  test_v1_controller_revision(1);
  test_v1_controller_revision(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_controller_revision_MAIN
#endif // v1_controller_revision_TEST
