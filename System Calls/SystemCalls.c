#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/utsname.h>
#include <sys/types.h>

void process() {
    int p = fork();
    if (p == 0) {
        printf("Child process id: %d, Parent process id: %d\n", getpid(), getppid());
        // Creating an orphan process when the child is successfully created.
        // sleep(2);
        // exit(0);
    } else if (p > 0) {
        printf("Parent process with PPID: %d\n", getppid());
        int w = wait(NULL);
        // Orphan process
        // exit(0) parent exited without checking the exit status of the child

        // Zombie process creation
        // sleep(2);
        // exit(0);
        printf("Child process with PID: %d\n", getpid());
    } else {
        printf("Fork failed\n");
    }
}

void file() {
    char buffer[100];
    int fd = open("openCallTest.txt", O_CREAT | O_RDWR);
    if (fd == -1) {
        printf("File open error\n");
    } else {
        printf("File created successfully\n");
    }
    int fd1 = open("test2.txt", O_RDONLY | O_WRONLY);
    write(fd1, "Write call test", 13);

    int fd2 = open("test1.txt", O_RDONLY);
    long bytesRead;
    int fd3 = open("test2.txt", O_RDWR);

    // Reading content char by char
    char singleChar;
    while ((bytesRead = read(fd2, &singleChar, 1)) > 0) {
        printf("%c", singleChar);
    }

    link("test1.txt", "test2.txt");
    printf("Link created\n");
    unlink("test2.txt");
    printf("Link destroyed\n");

    struct stat stats;
    if (stat("test2.txt", &stats) == 0) {
        printf("File %lld bytes large\n", (long long)stats.st_size);
        printf("File has permissions %o\n", stats.st_mode);
        printf("File modified at time %ld\n", stats.st_atime);
    }

    // Writing char by char
    int sourceFile = open("test1.txt", O_RDWR);
    int destinationFile = open("test3.txt", O_RDWR | O_CREAT);
    int bytes;
    while ((bytes = read(sourceFile, &singleChar, 1)) > 0) {
        write(destinationFile, &singleChar, 1);
        printf("%c", singleChar);
    }
}

void communication() {
    int fd[2], n;
    char buffer[100];
    pipe(fd);
    int p = fork();
    if (p > 0) {
        printf("Parent passing value to child\n");
        write(fd[1], "Hello\n", 6);
        wait(NULL);
    } else {
        printf("Child printing the received message value\n");
        n = read(fd[0], buffer, 100);
        write(1, buffer, n); // This is used to print the read value;
    }
}

void systemInfo() {
    struct utsname system_info;
    if (uname(&system_info) == 0) {
        printf("System Name: %s\n", system_info.sysname);
        printf("Node Name: %s\n", system_info.nodename);
        printf("Release: %s\n", system_info.release);
        printf("Version: %s\n", system_info.version);
        printf("Machine: %s\n", system_info.machine);
    } else {
        perror("uname");
    }

    int fd = open("sample.txt", O_CREAT);
    struct stat sfile;
    stat("test3.txt", &sfile);
    printf("System time of last access: %ld\n", sfile.st_atime);
    printf("System time of last modification: %ld\n", sfile.st_mtime);
    printf("System mode: %o\n", sfile.st_mode);
    printf("System size: %ld bytes\n", sfile.st_size);
}

int main() {
    int choice;
    do {
        printf("\nChoose an option:\n");
        printf("1. Process\n");
        printf("2. File\n");
        printf("3. Communication\n");
        printf("4. System Info\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                process();
                break;
            case 2:
                file();
                break;
            case 3:
                communication();
                break;
            case 4:
                systemInfo();
                break;
            case 0:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}
