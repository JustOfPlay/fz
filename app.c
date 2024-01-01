#include <furi.h>
#include <gui/gui.h>
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
#include "assets.h"

#define BACKLIGHT_ON 1

const GpioPin* const pin_led = &gpio_ext_pa7;
const GpioPin* const pin_back = &gpio_button_back;

static void delta_gui_app(Canvas* canvas, void* context) {
    UNUSED(context);
    canvas_draw_icon(canvas, 2, 1, &I_SDcardMounted_11x8);

    canvas_draw_line(canvas, 0, 12, 125, 12);

    canvas_draw_icon(canvas, 2, 22, &I_SDcardFail_11x8);

    canvas_draw_icon(canvas, 16, 1, &I_Bluetooth_Idle_5x8);

    canvas_draw_icon(canvas, 84, -1, &I_Voltage_16x16);

    canvas_draw_icon(canvas, 23, 1, &I_Hidden_window_9x8);

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

    canvas_draw_icon(canvas, 50, 21, &I_Power_25x27);


}

int gpio_blink_app(void* p) {
    UNUSED(p);

    Gui* gui = furi_record_open(RECORD_GUI);
    ViewPort* view_port = view_port_alloc();
    view_port_draw_callback_set(view_port, my_draw_callback, NULL);
    gui_add_view_port(gui, view_port, GuiLayerFullscreen);

    furi_hal_gpio_init_simple(pin_led, GpioModeOutputOpenDrain);
    do {
        furi_hal_gpio_write(pin_led, true);
        furi_delay_ms(500);
        furi_hal_gpio_write(pin_led, false);
        furi_delay_ms(500);

    } while(furi_hal_gpio_read(pin_back));

    furi_hal_gpio_init_simple(pin_led, GpioModeAnalog);

    gui_remove_view_port(gui, view_port);
    return 0;
}