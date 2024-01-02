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



#define BACKLIGHT_ON 1

static void delta_gui_app(Canvas* canvas, void* context) {
    UNUSED(context);

    canvas_set_font(canvas, FontBigNumbers);
    canvas_draw_str(canvas, 37, 14, "12:50");       //Time

    canvas_draw_line(canvas, 0, 15, 127, 15);       //Split line

    canvas_draw_icon(canvas, 2, 18, &I_SDcardFail_11x8);       //only visable if no sd card

    canvas_draw_icon(canvas, 2, 2, &I_SDcardMounted_11x8);      //only visable if sd card

    canvas_draw_icon(canvas, 15, 18, &I_Bluetooth_Idle_5x8);    //bluetooth on

    canvas_draw_icon(canvas, 108, 2, &I_Charging_lightning_mask_9x10);      //charching

    canvas_draw_box(canvas, 102, 5, 20, 4);            //edit 3. number for % value (max 0 | min 20)

    canvas_draw_icon(canvas, 100, 3, &I_Battery_26x8);      //battery icon

    canvas_draw_icon(canvas, -1, 27, &I_power_19x20);       //placeholder app

    canvas_draw_icon(canvas, 51, 20, &I_power_hover_19x20);       //placeholder app

    canvas_draw_icon(canvas, 116, 54, &I_Pin_back_arrow_10x8);      //back arrow

    canvas_draw_icon(canvas, 15, 2, &I_Bluetooth_Connected_16x8);       //bluetooth on and connected

    canvas_draw_icon(canvas, 25, 27, &'I_voldown_24x21');            //placeholder app

    canvas_draw_icon(canvas, 77, 26, &I_volup_24x21);      //placeholder app

    canvas_draw_icon(canvas, 103, 26, &I_Mute_25x27);       //placeholder app

    canvas_set_font(canvas, FontSecondary);
    canvas_draw_str(canvas, 93, 62, "Hold (    )");         //text for back arrow



}
static void input_callback(InputEvent* input_event, void* context) {
    furi_assert(context);
    FuriMessageQueue* event_queue = context;
    furi_message_queue_put(event_queue, input_event, FuriWaitForever);


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

        if (event.type == InputTypeLong) {
            if(event.key == InputKeyBack) {
                break;
            }
        }

    }

    furi_message_queue_free(event_queue);

    gui_remove_view_port(gui, view_port);

    view_port_free(view_port);
    furi_record_close(RECORD_GUI);
    return 0;
}