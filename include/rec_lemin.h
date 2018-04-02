#ifndef REC_LEMIN_H
#define REC_LEMIN_H

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
	char **links;

	/* Functions */
	int (*setActualRoom)(struct OneWay *self);
	int (*setNextRoom)(struct OneWay *self, int nb);
	int (*setRoomsTo)(struct OneWay *self, char *room);
	int (*setLinkTableTo)(struct OneWay *self, char **links);
	int (*AddToLinkTable)(struct OneWay *self, char **links);
}OneWay;

singletonLemin *singletonLemin_getInstance();
OneWay *OneWayConstructor();

#endif

