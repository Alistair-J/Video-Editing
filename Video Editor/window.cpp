#include <gtk/gtk.h>
#include <string>

//void callback(GtkWidget* widget, gpointer data);

//gtk_signal_connect is used to define what buttons do

void save()
{
	g_print("Saved");
}


void close(GtkWidget* widget, gpointer data, GtkWidget* window)
{
	GtkWidget* dialog{};
	GtkWidget* button0;
	GtkWidget* button1;

	/*dialog = gtk_dialog_new();
	gtk_dialog_set_default_response(GTK_DIALOG(dialog), GTK_RESPONSE_ACCEPT);

	gtk_dialog_add_button(GTK_DIALOG(dialog), "Save", GTK_RESPONSE_ACCEPT);
	gtk_dialog_add_button(GTK_DIALOG(dialog), "Don't Save", GTK_RESPONSE_CLOSE);
	gtk_dialog_add_button(GTK_DIALOG(dialog), "Cancel", GTK_RESPONSE_CANCEL);
	
	gtk_widget_show_all(dialog);
	gint response = gtk_dialog_get_response_for_widget(GTK_DIALOG(dialog), widget);
		switch (response)
		{
		case(GTK_RESPONSE_ACCEPT) :
			save();
			break;
		case(GTK_RESPONSE_CLOSE) :
			exit;
		case(GTK_RESPONSE_CANCEL) :
			break;
		}
	gtk_dialog_run(GTK_DIALOG(dialog));*/

	dialog = gtk_dialog_new_with_buttons("Dialog", NULL, GTK_DIALOG_MODAL, "Save" , GTK_RESPONSE_OK, "Don't Save" , GTK_RESPONSE_NO, "Cancel", GTK_RESPONSE_CANCEL, NULL);
	gtk_widget_show_all(dialog);
	gint response = gtk_dialog_run(GTK_DIALOG(dialog));
	if (response == GTK_RESPONSE_OK)
	{
		save();
	}
	if (response == GTK_RESPONSE_NO)
	{
		gtk_widget_destroy(window);
		exit(EXIT_SUCCESS);
	}
	gtk_widget_destroy(dialog);
	gtk_widget_show_all(window);
}

void createWindow(int argc, char* argv[], std::string title)
{
	GtkWidget* window;
	GtkWidget* button;

	gtk_init(&argc, &argv);

	//window
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), title.c_str());
	g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(close), NULL);

	//button
	button = gtk_button_new_with_label("Button");
	gtk_container_add(GTK_CONTAINER(window), button);
	g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(close), NULL);

	// set the window as visible
	gtk_widget_show_all(window);

	// run the GTK main loop
	gtk_main();
}

void log(GtkWidget* widget, gpointer data)
{
	g_print("Window Size: ", gtk_window_get_size);
}