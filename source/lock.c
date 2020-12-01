/**
 *  Implementation of lock.h
 */
#include "lock.h"

#include <stdio.h>
#include <string.h>
#include <new>

/**
 * Initialise a read/write lock.
 */
int rwlock_init(rwlock_t* lock)
{
    if(lock == NULL)
    {
        printf("rwlock_init: lock == NULL!\n");
        return -1;
    }

    new(lock) RWLock;
    return 0;
}

/**
 * Acquire the rwlock as a write lock
 * 
 * This code blocks if:
 *  - There is already a writer that has the lock
 *  - There are readers that have the lock
 */
int rwlock_wrlock(rwlock_t* lock)
{
    lock->lock_write();
    return 0;
}

int rwlock_rdlock(rwlock_t* lock)
{
    lock->lock_read();
    return 0;
}

int rwlock_rdunlock(rwlock_t* lock)
{
    lock->unlock_read();
    return 0;
}

int rwlock_wrunlock(rwlock_t* lock)
{
    lock->unlock_write();
    return 0;
}
