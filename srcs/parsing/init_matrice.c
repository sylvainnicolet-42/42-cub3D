
#include "cub3d.h"

/**
 * Initialize the matrice.
 *
 * @param ac
 * @param av
 *
 * @return t_matrice*
 */
t_matrice	*ft_init_matrice(int ac, char **av)
{
	t_matrice	*matrice;

	ft_check_arguments(ac, av);
	matrice = malloc(sizeof(t_matrice));
	if (!matrice)
		ft_print_error(MSG_MALLOC_ERR);
	*matrice = (t_matrice){};
	return (matrice);
}
