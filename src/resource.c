#include "resource.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include <yaml.h>
#include <zlib.h>

manifest_t *load_manifest(const char *name)
{
    struct stat path;
    if (stat(name, &path) != 0)
        return 0; //ERROR: directory or file does not exist

    if (!S_ISREG(path.st_mode)) //Is Directory
    {
        struct stat manifest_info;

        char *manifest_location = (char *)malloc(strlen(name) + 1);
        strcpy(manifest_location,name);
        strcat(manifest_location,"/manifest.yaml\0");

        if (stat(manifest_location, &manifest_info) == NULL) //Locate Manifest
        {
            FILE *manifest_file;
            if ((manifest_file = fopen(manifest_location, "r")) == NULL)
            {
                printf("baaaa"); //ERROR: unable to locate application manifest
                return NULL;
            }
            //Load File
        } else
        {
            printf("baaaa");

            //ERROR: unable to locate application manifest
            return NULL;
        }
    } else //Unzip With zlib
    {

    }
}
