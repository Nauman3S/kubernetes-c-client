#ifndef KUBE_OPERATIONS_H
#define KUBE_OPERATIONS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <apiClient.h>

// Enum for different config map operations
typedef enum {
    CREATE,
    DELETE,
    LIST
} ConfigMapOperation;

// Function to initialize and return a Kubernetes API client
int initialize_kube(apiClient_t **apiClient, char **basePath, sslConfig_t **sslConfig, list_t **apiKeys);

// Function to perform specified operation on config maps
void perform_configmap_operations(apiClient_t *apiClient, ConfigMapOperation op, const char *config_map_name, const char *namespace_);

int free_kube(apiClient_t **apiClient, char **basePath, sslConfig_t **sslConfig, list_t **apiKeys);

#ifdef __cplusplus
}
#endif

#endif // KUBE_OPERATIONS_H
