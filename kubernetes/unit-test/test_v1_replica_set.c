#ifndef v1_replica_set_TEST
#define v1_replica_set_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_replica_set_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_replica_set.h"
v1_replica_set_t* instantiate_v1_replica_set(int include_optional);

#include "test_v1_object_meta.c"
#include "test_v1_replica_set_spec.c"
#include "test_v1_replica_set_status.c"


v1_replica_set_t* instantiate_v1_replica_set(int include_optional) {
  v1_replica_set_t* v1_replica_set = NULL;
  if (include_optional) {
    v1_replica_set = v1_replica_set_create(
      "0",
      "0",
       // false, not to have infinite recursion
      instantiate_v1_object_meta(0),
       // false, not to have infinite recursion
      instantiate_v1_replica_set_spec(0),
       // false, not to have infinite recursion
      instantiate_v1_replica_set_status(0)
    );
  } else {
    v1_replica_set = v1_replica_set_create(
      "0",
      "0",
      NULL,
      NULL,
      NULL
    );
  }

  return v1_replica_set;
}


#ifdef v1_replica_set_MAIN

void test_v1_replica_set(int include_optional) {
    v1_replica_set_t* v1_replica_set_1 = instantiate_v1_replica_set(include_optional);

	cJSON* jsonv1_replica_set_1 = v1_replica_set_convertToJSON(v1_replica_set_1);
	printf("v1_replica_set :\n%s\n", cJSON_Print(jsonv1_replica_set_1));
	v1_replica_set_t* v1_replica_set_2 = v1_replica_set_parseFromJSON(jsonv1_replica_set_1);
	cJSON* jsonv1_replica_set_2 = v1_replica_set_convertToJSON(v1_replica_set_2);
	printf("repeating v1_replica_set:\n%s\n", cJSON_Print(jsonv1_replica_set_2));
}

int main() {
  test_v1_replica_set(1);
  test_v1_replica_set(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_replica_set_MAIN
#endif // v1_replica_set_TEST
