#ifndef _GETLINE_H_
#define _GETLINE_H_

#include <stdlib.h>
#include <unistd.h>

#include "string.h"

#define GETLINE_BUFFER_SIZE 4096

/**
 * struct buf_s - func inputs buffer
 * @buffer: the buffer
 * @next: pointer to the next value
 * @remaining: returns number of values remaining
 */
typedef struct buf_s
{
	char buffer[GETLINE_BUFFER_SIZE];
	char *next;
	size_t remaining;
} buf_t;

#define GETLINE_TABLE_SIZE 127

/**
 * struct buf_table_node_s - func inputs buffer hash table
 * @fd: file descriptor
 * @buf: associated buffer
 * @next: Returns the next buffer in the chain
 */
typedef struct buf_table_node_s
{
	int fd;
	struct buf_s buf;
	struct buf_table_node_s *next;
} buf_table_node_t;

typedef buf_table_node_t *buf_table_t[GETLINE_TABLE_SIZE];

char *_getline(const int fd);

#endif /* _GETLINE_H_ */
