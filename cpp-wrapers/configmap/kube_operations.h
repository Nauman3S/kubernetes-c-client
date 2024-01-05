#ifndef KUBE_OPERATIONS_H
#define KUBE_OPERATIONS_H

#include <apiClient.h>

void create_configmap(apiClient_t *apiClient, char *name, char *namespace_);
void list_configmap(apiClient_t *apiClient, char *namespace_);
void delete_configmap(apiClient_t *apiClient, char *name, char *namespace_);

#endif // KUBE_OPERATIONS_H
