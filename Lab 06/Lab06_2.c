#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <locale.h>
#include <langinfo.h>
#include <stdint.h>




#define FOUND 0
#define NOT_FOUND 1
#define OPEN_ERROR 2
#define READ_ERROR 4

int main() {
	struct stat statbuf;
	DIR *dirp = opendir(".");
	struct dirent* dp;
	char name[256];
	struct tm *tm;
	char datestring[256];

	while (dirp) {
		errno = 0;
		if ((dp = readdir(dirp)) != NULL) {

			/* Get entry's information. */
			if (stat(dp->d_name, &statbuf) == -1)
				continue;

			strftime(datestring, sizeof(datestring), nl_langinfo(D_T_FMT)

			printf("filename: %s\n | Size of the file: %9jd\n |Date: %s\n\n" ,dp->d_name, (intmax_t)statbuf.st_size, datestring);
			if (strcmp(dp->d_name, name) == 0) {
				closedir(dirp);
				return FOUND;
			}
		} else {
		if (errno == 0) {
				closedir(dirp);
				return NOT_FOUND;
			}
			closedir(dirp);
			return READ_ERROR;
		}
	}
	return OPEN_ERROR;
}