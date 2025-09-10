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

// we can get the ptr in each individual process, or simply get it here
// the address return is the same for both process, regardless of whether
// it is called here or in each individual process
int *x = (int*) shmat(shmid, NULL, 0);

int *x2 = new int(1);

int f(int x) {
    return 2 * x;
}

int y = f(10);

int main() {

    int child = fork();

    if (child != 0) {
        sleep(1);
        
        cout << "parent" << " " << x << " " << x2 << endl;
        cout << *x << " " << *x2 << endl;
    } else {
        *x = 69;
        *x2 = 69;
        cout << "child" << " " << x << " " << x2 << endl;
        //cout << y << endl;
    }

}