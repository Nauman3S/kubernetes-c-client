#ifndef v1_network_policy_peer_TEST
#define v1_network_policy_peer_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_network_policy_peer_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_network_policy_peer.h"
v1_network_policy_peer_t* instantiate_v1_network_policy_peer(int include_optional);

#include "test_v1_ip_block.c"
#include "test_v1_label_selector.c"
#include "test_v1_label_selector.c"


v1_network_policy_peer_t* instantiate_v1_network_policy_peer(int include_optional) {
  v1_network_policy_peer_t* v1_network_policy_peer = NULL;
  if (include_optional) {
    v1_network_policy_peer = v1_network_policy_peer_create(
       // false, not to have infinite recursion
      instantiate_v1_ip_block(0),
       // false, not to have infinite recursion
      instantiate_v1_label_selector(0),
       // false, not to have infinite recursion
      instantiate_v1_label_selector(0)
    );
  } else {
    v1_network_policy_peer = v1_network_policy_peer_create(
      NULL,
      NULL,
      NULL
    );
  }

  return v1_network_policy_peer;
}


#ifdef v1_network_policy_peer_MAIN

void test_v1_network_policy_peer(int include_optional) {
    v1_network_policy_peer_t* v1_network_policy_peer_1 = instantiate_v1_network_policy_peer(include_optional);

	cJSON* jsonv1_network_policy_peer_1 = v1_network_policy_peer_convertToJSON(v1_network_policy_peer_1);
	printf("v1_network_policy_peer :\n%s\n", cJSON_Print(jsonv1_network_policy_peer_1));
	v1_network_policy_peer_t* v1_network_policy_peer_2 = v1_network_policy_peer_parseFromJSON(jsonv1_network_policy_peer_1);
	cJSON* jsonv1_network_policy_peer_2 = v1_network_policy_peer_convertToJSON(v1_network_policy_peer_2);
	printf("repeating v1_network_policy_peer:\n%s\n", cJSON_Print(jsonv1_network_policy_peer_2));
}

int main() {
  test_v1_network_policy_peer(1);
  test_v1_network_policy_peer(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_network_policy_peer_MAIN
#endif // v1_network_policy_peer_TEST
