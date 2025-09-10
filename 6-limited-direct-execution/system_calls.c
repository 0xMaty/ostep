#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>

int main() {
  struct timeval start_time, end_time;
  int loops = 1000000;
  int fd = open("file.txt", O_RDONLY);
  if (fd == -1) {
    perror("Failed to open file.");
    return 1;
  }

  gettimeofday(&start_time, NULL);
  for (int i = 0; i < loops; i++) {
    read(fd, NULL, 0);
  }
  gettimeofday(&end_time, NULL);

  close(fd);

  long total_usec = (end_time.tv_sec - start_time.tv_sec) * 1000000 +
                    (end_time.tv_usec - start_time.tv_usec);

  printf("average time of system call: %ld microseconds\n", total_usec / loops);
  return 0;
}