#include <furi.h>
#include <gui/gui.h>

int main() {
    FuriStatus status = furi_init();
    if (status != FuriStatusOk) {
        printf("Furi initialization failed!\n");
        return -1;
    }

    ViewPort* view_port = view_port_alloc();
    Gui* gui = furi_record_open(RECORD_GUI);
    gui_add_view_port(gui, view_port, GuiLayerFullscreen);

    Canvas* canvas = view_port_get_canvas(view_port);
    canvas_set_font(canvas, FontPrimary);
    canvas_draw_str(canvas, 51, 32, "Hello Application");

    while(1) {
        InputEvent event;
        furi_check(furi_event_get(&event, FuriWaitForever) == FuriStatusOk);

        if (event.key == InputKeyBack) {
            break;
        }
    }

    gui_remove_view_port(gui, view_port);
    view_port_free(view_port);
    furi_record_close(RECORD_GUI);
    furi_deinit();

    return 0;
}
