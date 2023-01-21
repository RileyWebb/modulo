#include <stdio.h>

typedef enum resource_type_t
{
    RESOURCE_TYPE_SCRIPT,
    RESOURCE_TYPE_SHADER,
    RESOURCE_TYPE_ASSET,
    RESOURCE_TYPE_OTHER,
} resource_type_t;

typedef struct resource_s
{
    FILE               *file;
    resource_type_t     type;

} resource_t;

typedef struct manifest_s
{

} manifest_t;

manifest_t *load_manifest(const char* name);

/* STEPS
 *
 * open manifest file
 * load all resources
 * compile resources with compile flags
 * execute at entrypoint
 *
 */