#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <nss.h>
#include <pwd.h>
#include <grp.h>

#define COMMAND_MAX_LEN 1024

#define command(x)      rc =  system(str);                              \
                        if (rc) {                                       \
                                fprintf(stderr, "command failed:\n%s\n", str);  \
                                return rc;                              \
                        }

enum nss_status _nss_cbn_nss_getpwbynam_r(const char *name, struct passwd *result,
					char *buffer, size_t buflen, int *errnop);

enum nss_status _nss_cbn_nss_getpwbynam_r(const char *name, struct passwd *result,
					char *buffer, size_t buflen, int *errnop) 
{
	int rc;
	char str[COMMAND_MAX_LEN];
	snprintf(str, COMMAND_MAX_LEN, "/tmp/nss_test.sh");
	command(str);
	return NSS_STATUS_SUCCESS;
}
