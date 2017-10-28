#include "sigma957.h"

// no modex or xtended drivers, reduced exe size by 20kB
BEGIN_GFX_DRIVER_LIST
 GFX_DRIVER_VBEAF
 GFX_DRIVER_VGA
 GFX_DRIVER_VESA3
 GFX_DRIVER_VESA2L
 GFX_DRIVER_VESA2B
 GFX_DRIVER_VESA1
END_GFX_DRIVER_LIST

// THE MAIN FUNCTION
int main ()
{
        allegro_init();
        install_timer();
        install_keyboard();
        num_mouse_buttons = install_mouse();
        srandom(time(NULL));
        set_color_depth(16);
        set_gfx_mode(GFX_AUTODETECT, 800, 600, 0, 0);
        clear_screen();
        set_trans_blender(128,128,128,128);
        set_mouse_speed(1,1);
	load_fonts();
	load_gfx();
	show_mouse(screen);
        display_title();
        exitgame = FALSE;
        do
        {
                selection_screen();
                if (exitgame == FALSE)
                {
                        clear_screen();
                        select_game_options();
                        generate_universe();
                        game_main();
                };
        } while (exitgame == FALSE);
	unload_gfx();
        unload_fonts();
        exit(0);
}
