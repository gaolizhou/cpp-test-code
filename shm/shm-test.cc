//
// Created by lizgao on 1/28/19.
//

#include <iostream>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <glog/logging.h>

using namespace std;

void shm_writer()
{
  // ftok to generate unique key
  key_t key = ftok("shmfile",65);

  // shmget returns an identifier in shmid
  int shmid = shmget(key,1024,0666|IPC_CREAT);

  // shmat to attach to shared memory
  char *str = (char*) shmat(shmid,(void*)0,0);

  cout<<"Write Data : ";
  cin >> str;

  LOG(INFO) << "Data written in memory: " << str;

  //detach from shared memory
  shmdt(str);
}


void shm_reader()
{
  // ftok to generate unique key
  key_t key = ftok("shmfile",65);

  // shmget returns an identifier in shmid
  int shmid = shmget(key,1024,0666|IPC_CREAT);

  // shmat to attach to shared memory
  char *str = (char*) shmat(shmid,(void*)0,0);

  printf("Data read from memory: %s\n",str);

  //detach from shared memory
  shmdt(str);

  // destroy the shared memory
  shmctl(shmid,IPC_RMID,NULL);
}
