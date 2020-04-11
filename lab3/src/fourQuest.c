#include <stdio.h>

int main() {
	char *options[3] = {"/projects/os_lab_2019/lab3/src/sequential_min_max", "12", "11"}; 
	int pid = fork();

	if (pid == 0) {
		printf("child\n");
		execvp("/projects/os_lab_2019/lab3/src/sequential_min_max", options);
	} else {
		wait(2);
		printf("pid of child process - %d\n", pid);
	}

	return 0;
}
