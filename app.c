#include <furi.h>

int32_t flipper_hello_app(void* p) {
    UNUSED(p);

    FuriMessageQueue* event_queue = furi_message_queue_alloc(8, sizeof(InputEvent));

    while(1) {
        // FuriMessageQueue-Logik zum Warten auf Eingaben oder andere Ereignisse hier einfügen
        // Zum Beispiel: furi_message_queue_get(event_queue, &event, FuriWaitForever);

        // Beispieltext auf dem Flipper-Display anzeigen
        furi_display_clear();
        furi_display_set_cursor(0, 0);
        furi_display_printf("Hello, Flipper Zero!");

        // Logik zum Beenden der Schleife hier einfügen, z.B. wenn eine bestimmte Taste gedrückt wird
        // Zum Beispiel: if (event.key == InputKeyBack) break;
    }

    furi_message_queue_free(event_queue);
    return 0;
}
