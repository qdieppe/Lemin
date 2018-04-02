#ifndef REC_LEMIN_H
#define REC_LEMIN_H

#include <unistd.h>
#include <stdlib.h>
#define constructObject(function_name) self->function_name = &function_name

typedef struct singletonLemin
{
	char **pathtable;

	/* Functions */
}singletonLemin;

typedef struct OneWay
{
	int actual_room;
	int next_room;
	char *rooms;
	size_t rooms_size;
	char **links;

	/* Functions */
	int (*setActualRoom)(struct OneWay *self);
	int (*setNextRoom)(struct OneWay *self, int nb);
	int (*setRoomsTo)(struct OneWay *self, char *room);
	int (*setLinkTableTo)(struct OneWay *self, char **links);
	int (*AddToSingletonLinkTable)(struct OneWay *self, char **links);
	int (*isntUsed)(struct OneWay *self, int nb);
}OneWay;

singletonLemin *singletonLemin_getInstance();
OneWay *OneWayConstructor();
int isntUsed(struct OneWay *self, int nb);

#endif

