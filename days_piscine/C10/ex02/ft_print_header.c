#include <unistd.h>
#include "ft_tail.h"

void	ft_print_header(char *filename, int file_index, int start_index)
{
	if (file_index > start_index)
		write(1, "\n", 1);
	ft_putstr("==> ");
	ft_putstr(filename);
	ft_putstr(" <==\n");
}
