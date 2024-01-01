#include <furi.h>
#include <gui/gui.h>

int main() {
    canvas_draw_box(canvas, 0, 0, 127, 63);
    canvas_set_color(Canvas, ColorWhite);

    canvas_draw_icon(Canvas, 0, 0, &I_Background_128x11);

    canvas_draw_icon(Canvas, 0, 52, &I_Background_128x11);

    canvas_draw_icon(Canvas, 117, 45, &I_Alert_9x8);

    canvas_draw_icon(Canvas, 118, 31, &I_Charging - lightning_mask_9x10);

}