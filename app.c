#include <furi.h>
#include <gui/gui.h>

int main() {
    Canvas_draw_box(canvas, 0, 0, 127, 63);
    Canvas_set_color(canvas, ColorWhite);

    Canvas_draw_icon(canvas, 0, 0, &I_Background_128x11);

    Canvas_draw_icon(canvas, 0, 52, &I_Background_128x11);

    Canvas_draw_icon(canvas, 117, 45, &I_Alert_9x8);

    Canvas_draw_icon(canvas, 118, 31, &I_Charging - lightning_mask_9x10);

}