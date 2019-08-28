#include <gtk/gtk.h>
#include <string>

//void callback(GtkWidget* widget, gpointer data);

//gtk_signal_connect is used to define what buttons do


void createWindow(int argc, char* argv[], std::string title)
{
	GtkWidget* window;
	GtkWidget* button;

	gtk_init(&argc, &argv);

	//window
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), title.c_str());
	g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

	//button
	button = gtk_button_new_with_label("Button");
	gtk_container_add(GTK_CONTAINER(window), button);
	g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(gtk_main_quit), NULL);

	/* set the window as visible */
	gtk_widget_show_all(window);

	/* run the GTK+ main loop */
	gtk_main();
}

void close(GtkWidget* widget, gpointer data) //May need to add a save/don't save/cancel
{
	gtk_main_quit();
}

void log(GtkWidget* widget, gpointer data)
{
	g_print("Window Size: ", gtk_window_get_size);
}