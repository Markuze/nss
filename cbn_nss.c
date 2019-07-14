#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <nss.h>
#include <pwd.h>
#include <grp.h>

#define COMMAND_MAX_LEN 1024
#define FILE_NAME "/tmp/test.log"

#define command(x)      rc =  system(str);                              \
                        if (rc) {                                       \
                                fprintf(stderr, "command failed:\n%s\n", str);  \
                                return NSS_STATUS_NOTFOUND;		\
                        } else {					\
                                fprintf(stdout, "command success:\n%s\n", str);  \
			}
static inline enum nss_status one_func(const char *name) 
{
	int rc;
	FILE *fptr;
	char str[COMMAND_MAX_LEN];
	fprintf(stderr, "Hello...(%s)\n", name);

        if (!(fptr = fopen(FILE_NAME, "a"))) {
                fprintf(stderr, "failed to opne %s\n", FILE_NAME);
                exit(1);
        }
        fprintf(fptr, "Hello %s\n", name);
        fclose(fptr);

	snprintf(str, COMMAND_MAX_LEN, "/tmp/nss_test.sh");
	command(str);
	snprintf(str, COMMAND_MAX_LEN, "echo %s > /tmp/func", name);
	command(str);
	return NSS_STATUS_SUCCESS;
}

//int _nss_cbn_getpwbynam_r(const char *name, struct passwd *result,
enum nss_status _nss_cbn_getpwbynam_r(const char *name, struct passwd *result,
					char *buffer, size_t buflen, int *errnop) 
{
	return one_func(__FUNCTION__);
}

enum nss_status _nss_cbn_getpwnam_r(const char *name, struct passwd *result,
					char *buffer, size_t buflen, int *errnop)
{
	return one_func(__FUNCTION__);
}
//int _nss_cbn_getpwbyuid_r(uid_t uid, struct passwd *result,
enum nss_status _nss_cbn_getpwbyuid_r(uid_t uid, struct passwd *result,
					char *buffer, size_t buflen, int *errnop) 
{
	return one_func(__FUNCTION__);
}

enum nss_status _nss_cbn_getpwent_r() { one_func(__FUNCTION__); return NSS_STATUS_NOTFOUND;}
enum nss_status _nss_cbn_endpwent() { return one_func(__FUNCTION__); }
enum nss_status _nss_cbn_setpwent() { return one_func(__FUNCTION__); }
