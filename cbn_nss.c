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
                                return NSS_STATUS_NOTFOUND;		\
                        }
static inline enum nss_status one_func(const char *name) 
{
	int rc;
	char str[COMMAND_MAX_LEN];
	fprintf(stderr, "Hello...(%s)\n", name);
	snprintf(str, COMMAND_MAX_LEN, "/tmp/nss_test.sh");
	command(str);
	snprintf(str, COMMAND_MAX_LEN, "echo %s > /tmp/func", name);
	command(str);
	return NSS_STATUS_SUCCESS;
}

enum nss_status _nss_cbn_getpwbynam_r(const char *name, struct passwd *result,
					char *buffer, size_t buflen, int *errnop) 
{
	return one_func(__FUNCTION__);
}

enum nss_status _nss_cbn_getpwbyuid_r(uid_t uid, struct passwd *result,
					char *buffer, size_t buflen, int *errnop) 
{
	return one_func(__FUNCTION__);
}

enum nss_status _nss_oslogin_getpwent_r() { return one_func(__FUNCTION__); }
enum nss_status _nss_oslogin_endpwent() { return one_func(__FUNCTION__); }
enum nss_status _nss_oslogin_setpwent() { return one_func(__FUNCTION__); }
