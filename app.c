#include <furi.h>
#include <gui/gui.h>
#include <furi.h>
#include <furi_hal.h>
#include <gui/gui.h>
#include <gui/view.h>
#include <gui/icon_i.h>
#include <gui/view_dispatcher.h>
#include <gui/modules/submenu.h>
#include <gui/modules/text_input.h>
#include <gui/modules/widget.h>
#include <gui/modules/variable_item_list.h>
#include <notification/notification.h>
#include <notification/notification_messages.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include <assets_icons.h>

char LeftPressed == "False";

#define BACKLIGHT_ON 1

static void delta_gui_app(Canvas* canvas, void* context {
    UNUSED(context);

    canvas_set_font(canvas, FontBigNumbers);
    canvas_draw_str(canvas, 37, 14, "12:50");

    canvas_draw_line(canvas, 0, 15, 127, 15);
    
    canvas_draw_icon(canvas, 51, 50, &I_FaceCharging_29x14);

    while (LeftPressed == "True") {
        canvas_set_font(canvas, FontPrimary);
        canvas_draw_str(canvas, -1, 29, "Button Pressed (OK)");
    }

}
static void input_callback(InputEvent* input_event, void* context) {
    furi_assert(context);
    FuriMessageQueue* event_queue = context;
    furi_message_queue_put(event_queue, input_event, FuriWaitForever);

    if (event->key == InputKeyLeft) {
        char LeftPressed == "True";
    }
    if (!event->key == InputKeyLeft) {
        char LeftPressed == "False";
    }
}


int main() {
    InputEvent event;

    FuriMessageQueue* event_queue = furi_message_queue_alloc(8, sizeof(InputEvent));

    ViewPort* view_port = view_port_alloc();


    view_port_draw_callback_set(view_port, delta_gui_app, NULL);


    view_port_input_callback_set(view_port, input_callback, event_queue);


    Gui* gui = furi_record_open(RECORD_GUI);
    gui_add_view_port(gui, view_port, GuiLayerFullscreen);

    while(true) {
        furi_check(furi_message_queue_get(event_queue, &event, FuriWaitForever) == FuriStatusOk);

        if(event.key == InputKeyBack) {
            break;
        }
    }

    furi_message_queue_free(event_queue);

    gui_remove_view_port(gui, view_port);

    view_port_free(view_port);
    furi_record_close(RECORD_GUI);
    return 0;
}