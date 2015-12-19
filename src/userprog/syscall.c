#include "userprog/syscall.h"
#include <stdio.h>
#include <syscall-nr.h>
#include "threads/interrupt.h"
#include "threads/thread.h"

static void syscall_handler (struct intr_frame *);

void
syscall_init (void) 
{
  intr_register_int (0x30, 3, INTR_ON, syscall_handler, "syscall");
}

static void
syscall_handler (struct intr_frame *f UNUSED) 
{
	//~ int *p = (int *)(f->esp);
	//~ int i;
	//~ for(i=0; i<4; i++){
		//~ printf("------------%d\n",*p);
		//~ p+=1;
	//~ }
  printf ("system call!\n");
  thread_exit ();
}
