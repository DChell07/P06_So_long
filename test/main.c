#include "so_long.h"

int animate_image(void *param)
{
    t_data *data = (t_data *)param;
    static int frame_count = 0;
    mlx_clear_window(data->mlx_ptr, data->win_ptr);
    if (frame_count % 20 == 0) // 10 est la valeur qui ralentit l'animation
    {
        // Déplace l'image verticalement
        data->y += data->dy * 64;

        // Si l'image atteint le bord supérieur ou inférieur, on inverse la direction
        if (data->y <= 0 || data->y + 64 >= 1000)
            data->dy *= -1;
    }
    frame_count++;
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, data->x, data->y);

    return 0;
}

int main(void)
{
    t_data data;
    int w = 64;
    int h = 64;

    // Initialisation de MinilibX
    data.mlx_ptr = mlx_init();
    
    // Chargement de l'image XPM
    data.img = mlx_xpm_file_to_image(data.mlx_ptr, "item.xpm", &w, &h);
    
    // Création de la fenêtre
    data.win_ptr = mlx_new_window(data.mlx_ptr, 1000, 1000, "TEST");

    // Position initiale de l'image
    data.x = 500;  // Position horizontale fixe
    data.y = 500;  // Position verticale initiale
    data.dy = 1;   // Vitesse de déplacement vertical (descendre)

    // Attache la fonction d'animation à la boucle
    mlx_loop_hook(data.mlx_ptr, animate_image, &data);

    // Lance la boucle principale
    mlx_loop(data.mlx_ptr);

    return 0;
}
