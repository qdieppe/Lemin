#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "my.h"
#include "rec_lemin.h"

int is_inbase(char *str, int nb)
{
	int i = 0;

	while (str[i]) {
		if (str[i] == nb)
			return (1);
	}
	return (0);
}

int check_line(char *link, char *rooms, int nb)
{
	unsigned int i = 0;

	while (rooms[i]) {
		if (rooms[i] && is_inbase(link, nb))
			return (1);
		i = i + 1;
	}
	return (0);
}

int isntUsed(struct OneWay *self, int nb)
{
	unsigned int i = 0;
	char **links = self->links;
	char *rooms = self->rooms;

	while (links[i] != NULL) {
		if (check_line(links[i], rooms, nb))
			return (0);
		i = i + 1;
	}
	return (1);
}
