#include <furi.h>
#include <furi_hal.h>
#include <gui/gui.h>
#include <gui/view.h>
#include <gui/view_dispatcher.h>
#include <gui/modules/submenu.h>
#include <gui/modules/text_input.h>
#include <gui/modules/widget.h>
#include <gui/modules/variable_item_list.h>
#include <notification/notification.h>
#include <notification/notification_messages.h>

#define BACKLIGHT_ON 1

const GpioPin* const pin_led = &gpio_ext_pa7;
const GpioPin* const pin_back = &gpio_button_back;

static void delta_gui_app(Canvas* canvas, void* context) {
    UNUSED(context);
    canvas_draw_line(canvas, 0, 13, 127, 13);

    canvas_set_font(canvas, FontSecondary);
    canvas_draw_str(canvas, 52, 10, "12.30");

    canvas_set_font(canvas, FontPrimary);
    canvas_draw_str(canvas, 102, 10, "100%");

    canvas_draw_line(canvas, 100, 0, 126, 0);

    canvas_draw_line(canvas, 127, 1, 127, 10);

    canvas_draw_line(canvas, 126, 11, 100, 11);

    canvas_draw_line(canvas, 99, 1, 99, 10);

    canvas_draw_dot(canvas, 99, 3);

    canvas_draw_line(canvas, 98, 2, 97, 2);

    canvas_draw_line(canvas, 98, 9, 97, 9);

    canvas_draw_line(canvas, 96, 3, 96, 8);

    canvas_set_font(canvas, FontSecondary);
    canvas_draw_str(canvas, 1, 67, "---*-----------------");




}