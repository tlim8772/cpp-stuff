#include <omp.h>
#include <bits/stdc++.h>
#include <semaphore.h>
using namespace std;

sem_t sem;
long long cnt = 0L;

int main() {
    sem_init(&sem, 1, 1);

    #pragma omp parallel for 
    for (int i = 0; i < 1000000; i ++) {
        //sem_wait(&sem);
        cnt += i;
        //sem_post(&sem);
    }
    

    cout << cnt << endl;
}