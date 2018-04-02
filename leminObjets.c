#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "my.h"
#include "rec_lemin.h"

int setRoomsTo(struct OneWay *self, char *room)
{

}

int setLinkTableTo(struct OneWay *self, char **links)
{

}

int AddToLinkTable(struct OneWay *self, char **links)
{

}

int setActualRoom(struct OneWay *self)
{

}

int setNextRoom(struct OneWay *self, int nb)
{

}

OneWay *OneWayConstructor()
{
	OneWay *self = (OneWay *) malloc(sizeof(OneWay));
	constructObject(setRoomsTo);
	constructObject(setLinkTableTo);
	constructObject(AddToLinkTable);
	constructObject(setActualRoom);
	constructObject(setNextRoom);
	if (self == NULL)
		return (NULL);
	return (self);
}
