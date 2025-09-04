#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <semaphore.h>
#include <iostream>
#include <chrono>
#include <bits/stdc++.h>
using namespace std;

// malloc memory is not shared

int shmid = shmget(IPC_PRIVATE, sizeof(int), 0644 | IPC_CREAT);
int *x = (int*) shmat(shmid, NULL, 0);

int main() {
    *x = 1;

    int child = fork();

    if (child != 0) {
        usleep(500000);
        cout << *x << endl;
    } else {
        *x = 69;
        cout << *x << endl;
    }

}