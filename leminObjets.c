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

int AddToSingletonLinkTable(struct OneWay *self, char **links)
{
	char ***pathtable = &(singletonLemin_getInstance()->pathtable);

}

int setActualRoom(struct OneWay *self)
{

}

int setNextRoom(struct OneWay *self, int nb)
{
	if (nb != -1) {
		return (1);
	}
}

OneWay *OneWayConstructor()
{
	OneWay *self = (OneWay *) malloc(sizeof(OneWay));
	constructObject(setRoomsTo);
	constructObject(setLinkTableTo);
	constructObject(AddToSingletonLinkTable);
	constructObject(setActualRoom);
	constructObject(setNextRoom);
	constructObject(isntUsed);
	if (self == NULL)
		return (NULL);
	return (self);
}
