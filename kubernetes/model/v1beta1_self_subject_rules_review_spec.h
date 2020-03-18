/*
 * v1beta1_self_subject_rules_review_spec.h
 *
 * 
 */

#ifndef _v1beta1_self_subject_rules_review_spec_H_
#define _v1beta1_self_subject_rules_review_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct v1beta1_self_subject_rules_review_spec_t {
    char *namespace; // string

} v1beta1_self_subject_rules_review_spec_t;

v1beta1_self_subject_rules_review_spec_t *v1beta1_self_subject_rules_review_spec_create(
    char *namespace
);

void v1beta1_self_subject_rules_review_spec_free(v1beta1_self_subject_rules_review_spec_t *v1beta1_self_subject_rules_review_spec);

v1beta1_self_subject_rules_review_spec_t *v1beta1_self_subject_rules_review_spec_parseFromJSON(cJSON *v1beta1_self_subject_rules_review_specJSON);

cJSON *v1beta1_self_subject_rules_review_spec_convertToJSON(v1beta1_self_subject_rules_review_spec_t *v1beta1_self_subject_rules_review_spec);

#endif /* _v1beta1_self_subject_rules_review_spec_H_ */

