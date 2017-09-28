#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main (int argc, char* argv[]) {

	char* file = argv[1];
	int fd;
	struct flock lock;
	printf ("opening the file %s\n", file);
	
	/* Open a file descriptor to the file. */
	fd = open (file, O_WRONLY);
	printf ("locking file. Write\n");
	
	/* Initialize the flock structure. */
	memset (&lock, 0, sizeof(lock));
	lock.l_type = F_WRLCK;
	
	/* Place a write lock on the file. */
	fcntl (fd, F_SETLKW, &lock);
	printf ("Locked the file. Able to unlock ");
	
	/* Wait for the user to hit Enter. */
	getchar ();
	printf ("unlocking the file\n");
	
	/* Release the lock. */
	lock.l_type = F_UNLCK;
	fcntl (fd, F_SETLKW, &lock);
	close (fd);
	return 0;
}