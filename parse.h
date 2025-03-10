#ifndef PARSE_H
# define PARSE_H

//EXTERNAL LIBS
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <math.h>

//LOCAL LIBS
# include "includes/eugenelibft/libft.h"
# include "includes/MLX42/include/MLX42/MLX42.h"

//TYPES



//PROTOTYPES

int		parse(int argc, char **argv);
char	**get_map_array(char *arg1);

#endif