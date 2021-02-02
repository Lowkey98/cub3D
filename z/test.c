# include "includes/libft.h"
# include <mlx.h>
# include <stdio.h>
typedef struct s_vars{
	void *mlx;
	void *win;
}	t_vars;
int	key_hook(int keycode, t_vars *vars)
{
	printf("%d",keycode);
}

int main()
{
	t_vars vars;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx.640,500,"hi");
	mlx_key_hook(vars.win,key_hook,&vars);
	mlx_loop(vars.mlx);
}
