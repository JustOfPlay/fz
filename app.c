#include <gtk/gtk.h>

// LED-Farbenauswahl-Callback-Funktion
void on_color_changed(GtkComboBox *widget, gpointer user_data) {
    GtkTreeIter iter;
    GtkTreeModel *model;
    gchar *value;

    // Holen des ausgewählten Werts aus der ComboBox
    if (gtk_combo_box_get_active_iter(widget, &iter)) {
        model = gtk_combo_box_get_model(widget);
        gtk_tree_model_get(model, &iter, 0, &value, -1);

        // Hier kannst du die Logik für die LED-Farbensteuerung implementieren
        // Beispiel: Je nach 'value' die entsprechende LED-Farbe setzen
        // Zum Beispiel: if (strcmp(value, "Rot") == 0) { setze LED auf Rot; }

        g_free(value);
    }
}

int main(int argc, char *argv[]) {
    GtkWidget *window;
    GtkWidget *combo_box;
    GtkListStore *store;

    gtk_init(&argc, &argv);

    // Erstellen des Hauptfensters
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "LED-Farbwähler");
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Erstellen einer ComboBox mit Farboptionen
    combo_box = gtk_combo_box_new_text();
    store = GTK_LIST_STORE(gtk_list_store_new(1, G_TYPE_STRING));
    gtk_combo_box_set_model(GTK_COMBO_BOX(combo_box), GTK_TREE_MODEL(store));

    // Farben hinzufügen
    gtk_list_store_append(store, &iter);
    gtk_list_store_set(store, &iter, 0, "Rot", -1);
    gtk_list_store_append(store, &iter);
    gtk_list_store_set(store, &iter, 0, "Grün", -1);
    gtk_list_store_append(store, &iter);
    gtk_list_store_set(store, &iter, 0, "Blau", -1);

    g_signal_connect(combo_box, "changed", G_CALLBACK(on_color_changed), NULL);

    // Hinzufügen der ComboBox zum Hauptfenster
    gtk_container_add(GTK_CONTAINER(window), combo_box);

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}
