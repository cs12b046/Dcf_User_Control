#include <gtk/gtk.h>
#include<stdio.h>
#include<string.h>
#define MAX1 10000
static void pass_change_by_admin(GtkWidget* change_pass_of_user , gpointer data);
static void print_user_name_and_pass(GtkWidget* user_name_and_pass , gpointer data);
static void mech_of_remove_user_from_com(GtkWidget* delete , gpointer data);
void gtk_after_login_by_user(GtkWidget* windows_after_login);
void calculate_no_of_user(GtkWidget* no_of_user, gpointer data);
void gtk_after_login_by_admin(GtkWidget* windows_after_login);
static void mech_for_change_pass(GtkWidget* ok , gpointer data);
static void show_com_to_all(GtkWidget* show_com, gpointer data);
static void mech_of_add_user(GtkWidget* create , gpointer data);
static void free_any_user(GtkWidget* free_slot , gpointer data);
static void mech_of_delete_user(GtkWidget* delete , gpointer data);
static void add_user_by_admin(GtkWidget* add_user , gpointer data);
static void delete_user_by_admin(GtkWidget* delete_user , gpointer data);
static void book_com_window(GtkWidget* register_com , gpointer data);
static void login_for_admin(GtkWidget* button1,gpointer data);
static void mech_for_book_com(GtkWidget* book ,gpointer data);
static void change_user_password(GtkWidget* change_pass , gpointer data);
static GtkWidget *user_name=0;    // user name(fill)
static GtkWidget *user_pass=0;   //user password(fill)
static GtkWidget *admin_name=0;   // for admin(fill)
static GtkWidget *admin_pass=0;   // for password of admin(fill)
static GtkWidget* entry_begin=0;
static GtkWidget *entry_end=0;
static GtkWidget *entry_date=0;
static GtkWidget *entry_day=0;
static GtkWidget *entry_com=0;
static void button_on_pre(GtkWidget* button , gpointer data)
{
	const gchar *entry_text1;
	const gchar *entry_text2;
	int i=0;
	int j=0;
	GtkWidget* window_after_login;
	GtkWidget* not_label;
	GtkWidget* ok;
	GtkWidget* table;
	//char* pch;
	//char* pch2;
	char *user;
	char *pass;
	char combine_string[MAX1];
	FILE* fip;
	entry_text1 = gtk_entry_get_text(GTK_ENTRY(user_name));
	entry_text2 = gtk_entry_get_text(GTK_ENTRY(user_pass));
	
	fip = fopen("user_and_pass.txt","r");
	
	fgets (combine_string , MAX1 , fip);
	user = strtok(combine_string, " ,\n");
	pass = strtok(NULL, " ,\n");
	while(pass != NULL)
	{
	
		if(strcmp(user,entry_text1) == 0 && strcmp(pass, entry_text2)==0)
		{
			window_after_login = gtk_window_new (GTK_WINDOW_TOPLEVEL);
			gtk_window_set_title (GTK_WINDOW (window_after_login), "HII USER");
			gtk_container_set_border_width (GTK_CONTAINER (window_after_login), 20);
	                g_signal_connect (window_after_login, "delete-event",G_CALLBACK (gtk_main_quit), NULL);
	                gtk_after_login_by_user( window_after_login);
	                gtk_widget_show (window_after_login);
	                fclose(fip) ;
	                return;
		}
		user = strtok(NULL, " ,\n");
		pass = strtok(NULL, " ,\n");
	}
	if(pass == NULL)
	{
		window_after_login = gtk_window_new (GTK_WINDOW_TOPLEVEL);
		gtk_window_set_title (GTK_WINDOW (window_after_login), "User Not Present");
		gtk_container_set_border_width (GTK_CONTAINER (window_after_login), 20);
	        g_signal_connect (window_after_login, "delete-event",G_CALLBACK (gtk_main_quit), NULL);
	        table = gtk_table_new (1, 2, TRUE);
		gtk_container_add (GTK_CONTAINER (window_after_login), table);
		not_label = gtk_label_new ("User is not present");
        	gtk_table_attach_defaults (GTK_TABLE (table),not_label, 0, 1, 0, 1);
        	ok = gtk_button_new_with_label ("OK");
		gtk_table_attach_defaults (GTK_TABLE (table), ok, 0, 1, 1, 2);
		g_signal_connect (ok, "clicked",G_CALLBACK (gtk_main_quit), NULL);
		gtk_widget_show(not_label);
		gtk_widget_show(ok);
		gtk_widget_show(table);
		 gtk_widget_show (window_after_login);
		 fclose(fip);
	}
}
void main(int argc , char* argv[])
{
	GtkWidget* window;   //for first time opening the windows
	GtkWidget* table;    // for admin login and students login
	GtkWidget* button;   // for login student
	GtkWidget* label1;   //User name of student(text)
	GtkWidget* label2;   // user password(text)
	
	GtkWidget* label3;   // to type For students.
	GtkWidget* button1;  // For admin login
	GtkWidget* label4;   // For Admin(type)
	GtkWidget* label5;   // for admin(type)
	
	GtkWidget* label6;   // for password
	GtkWidget* button_exit; //button for exit
	gtk_init (&argc, &argv);
	/* Create a new window */
	window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	/* Set the window title */
	gtk_window_set_title (GTK_WINDOW (window), "DCF USER CONTROL");
	/* Sets the border width of the window. */
	gtk_container_set_border_width (GTK_CONTAINER (window), 20);
	g_signal_connect (window, "delete-event",G_CALLBACK (gtk_main_quit), NULL);
	
	/* Create a 5x1 table */
	table = gtk_table_new (5, 5, TRUE);
	/* Put the table in the main window */
	gtk_container_add (GTK_CONTAINER (window), table);
	
	/* Create the Login button */
	
	label1 = gtk_label_new ("User Name");
        gtk_table_attach_defaults (GTK_TABLE (table),label1, 0, 1, 1, 2);
        label2 = gtk_label_new ("Password");
        gtk_table_attach_defaults (GTK_TABLE (table),label2, 2, 3, 1, 2);
        label3 = gtk_label_new ("For Students :");
        gtk_table_attach_defaults (GTK_TABLE (table),label3, 0, 1, 0, 1);
        gtk_widget_show (label3);
        gtk_widget_show (label1);
        gtk_widget_show (label2);
        user_name = gtk_entry_new ();
        gtk_table_attach_defaults (GTK_TABLE (table),user_name, 1, 2, 1, 2);
        gtk_widget_show (user_name); 
        user_pass = gtk_entry_new ();
        gtk_table_attach_defaults (GTK_TABLE (table),user_pass, 3, 4, 1, 2);
        button = gtk_button_new_with_label ("Login");
	g_signal_connect (button, "clicked",G_CALLBACK (button_on_pre), (gpointer) "button");
	gtk_table_attach_defaults (GTK_TABLE (table), button, 4, 5, 1, 2);
	gtk_widget_show (button);
        //gtk_entry_set_invisible_char(user_pass,'*');
       
        /*****
         for admin
         *****/
         /* Create the Login button */
	
	label5 = gtk_label_new ("Admin");
        gtk_table_attach_defaults (GTK_TABLE (table),label5, 0, 1, 3, 4);
        label6 = gtk_label_new ("Password");
        gtk_table_attach_defaults (GTK_TABLE (table),label6, 2, 3, 3, 4);
        label4 = gtk_label_new ("For Admin :");
        gtk_table_attach_defaults (GTK_TABLE (table),label4, 0, 1, 2, 3);
        gtk_widget_show (label4);
        gtk_widget_show (label5);
        gtk_widget_show (label6);
        admin_name = gtk_entry_new ();
        gtk_table_attach_defaults (GTK_TABLE (table),admin_name, 1, 2, 3, 4);
       
        gtk_widget_show (admin_name); 
        admin_pass = gtk_entry_new ();
        gtk_entry_set_invisible_char(GTK_ENTRY(admin_pass),'*');
        gtk_table_attach_defaults (GTK_TABLE (table),admin_pass, 3, 4, 3, 4);
        button1 = gtk_button_new_with_label ("Login");
	gtk_table_attach_defaults (GTK_TABLE (table), button1, 4, 5, 3, 4);
	g_signal_connect (button1, "clicked",G_CALLBACK (login_for_admin), (gpointer) "button1");
	gtk_widget_show (button1);
        button_exit = gtk_button_new_with_label ("Exit");
	gtk_table_attach_defaults (GTK_TABLE (table), button_exit, 2, 3, 4, 5);
	gtk_widget_show (button_exit);
	g_signal_connect (button_exit, "clicked",G_CALLBACK (gtk_main_quit), NULL);
        
        /*************/
        gtk_widget_show (user_pass);
        gtk_widget_show (admin_pass);  
	gtk_widget_show (table);
        gtk_widget_show (window);
	gtk_main();
}   
void gtk_after_login_by_user(GtkWidget* window_after_login)
{
	GtkWidget* welcome_label;
	GtkWidget* change_pass;
	GtkWidget* logout;
	GtkWidget* table;
	GtkWidget* show_com;
	GtkWidget* register_com;
	GtkWidget* free_yourself;
	table = gtk_table_new (6,1, TRUE);
	gtk_container_add (GTK_CONTAINER (window_after_login), table);
	welcome_label = gtk_label_new ("HII USER");
        gtk_table_attach_defaults (GTK_TABLE (table),welcome_label, 0, 1, 0, 1);
        gtk_widget_show (welcome_label);
        logout = gtk_button_new_with_label ("Logout");
	gtk_table_attach_defaults (GTK_TABLE (table), logout, 0, 1, 5, 6);
	gtk_widget_show (logout);
	g_signal_connect (logout, "clicked",G_CALLBACK (main), NULL);
	change_pass=gtk_button_new_with_label("Change Password");
	gtk_table_attach_defaults(GTK_TABLE(table),change_pass,0,1,3,4);
	gtk_widget_show(change_pass);
	g_signal_connect (change_pass, "clicked",G_CALLBACK (change_user_password), NULL);
	show_com = gtk_button_new_with_label ("Com Status");
	gtk_table_attach_defaults (GTK_TABLE (table), show_com, 0, 1, 2, 3);
	gtk_widget_show (show_com);
	g_signal_connect (show_com, "clicked",G_CALLBACK (show_com_to_all), NULL);
	register_com = gtk_button_new_with_label ("Register Com");
	gtk_table_attach_defaults (GTK_TABLE (table), register_com, 0, 1, 1, 2);
	gtk_widget_show (register_com);
	g_signal_connect (register_com, "clicked",G_CALLBACK (book_com_window), NULL);
	free_yourself=gtk_button_new_with_label("Free Registered Slot");
	gtk_table_attach_defaults(GTK_TABLE(table),free_yourself,0,1,4,5);
	gtk_widget_show(free_yourself);
	g_signal_connect (free_yourself, "clicked",G_CALLBACK (mech_of_remove_user_from_com), NULL);
        gtk_widget_show (table);
}
static void change_user_password(GtkWidget* change_pass , gpointer data)
{
	//FILE*  fp;
	//fp = fopen("user_and_pass.txt","w+");
	GtkWidget* window_for_change_pass;
	GtkWidget* ok;
	GtkWidget* cencel;
	GtkWidget* table;
	//GtkWidget* new_pass;
	window_for_change_pass = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title (GTK_WINDOW (window_for_change_pass), "Change Password");
	gtk_window_set_default_size(GTK_WINDOW(window_for_change_pass), 100, 100);
	gtk_container_set_border_width (GTK_CONTAINER (window_for_change_pass), 20);
	g_signal_connect (window_for_change_pass, "delete-event",G_CALLBACK (gtk_main_quit), NULL);
	table = gtk_table_new (4,1, TRUE);
	gtk_container_add (GTK_CONTAINER (window_for_change_pass), table);
	/*user_name = gtk_entry_new ();
        gtk_table_attach_defaults (GTK_TABLE (table),user_name, 0, 1, 0, 1);
        gtk_entry_set_text(GTK_ENTRY(user_name),"User Name");
        gtk_widget_show (user_name); */
	user_pass = gtk_entry_new ();
        gtk_table_attach_defaults (GTK_TABLE (table),user_pass, 0, 1, 1, 2);
        gtk_entry_set_text(GTK_ENTRY(user_pass),"New Password");
        gtk_widget_show (user_pass); 
        ok = gtk_button_new_with_label ("Change Password");
	gtk_table_attach_defaults (GTK_TABLE (table), ok, 0, 1, 2, 3);
	g_signal_connect (ok, "clicked",G_CALLBACK (mech_for_change_pass), NULL);
	gtk_widget_show (ok);
	cencel = gtk_button_new_with_label ("Cencel");
	gtk_table_attach_defaults (GTK_TABLE (table), cencel, 0, 1, 3, 4);
	g_signal_connect (cencel, "clicked",G_CALLBACK (gtk_main_quit), NULL) ;
	gtk_widget_show (cencel);
        gtk_widget_show(table);
        gtk_widget_show(window_for_change_pass);
}
static void mech_for_change_pass(GtkWidget* ok , gpointer data)
{
	GtkWidget* window_after_login;
	GtkWidget* not_label;
	GtkWidget* done;
	GtkWidget* table;
	const gchar *entry_text1;
	const gchar *entry_text2;
	char* user;
	char* pass;
	char combine_string[MAX1];
	int i,j;
	FILE *fp;
	entry_text1 = gtk_entry_get_text(GTK_ENTRY(user_name));
	entry_text2 = gtk_entry_get_text(GTK_ENTRY(user_pass));
	fp=fopen("user_and_pass.txt","r");
	fgets (combine_string , MAX1 , fp);
	fclose(fp);
	fp=fopen("user_and_pass.txt","wt");
	user = strtok(combine_string, " ,\n");
	while(!feof(fp))
	{
		i=0;j=0;
		if(user == NULL)	
		{
			window_after_login = gtk_window_new (GTK_WINDOW_TOPLEVEL);
			gtk_window_set_title (GTK_WINDOW (window_after_login), "Password Changed");
			gtk_container_set_border_width (GTK_CONTAINER (window_after_login), 20);
			g_signal_connect (window_after_login, "delete-event",G_CALLBACK (gtk_main_quit), NULL);
			table = gtk_table_new (1, 2, TRUE);
			gtk_container_add (GTK_CONTAINER (window_after_login), table);
			not_label = gtk_label_new ("Password has been changed");
        		gtk_table_attach_defaults (GTK_TABLE (table),not_label, 0, 1, 0, 1);
        		done = gtk_button_new_with_label ("OK");
			gtk_table_attach_defaults (GTK_TABLE (table), done, 0, 1, 1, 2);
			g_signal_connect (done, "clicked",G_CALLBACK (gtk_main_quit), NULL);
			gtk_widget_show(not_label);
			gtk_widget_show(done);
			gtk_widget_show(table);
			 gtk_widget_show (window_after_login);
			fclose(fp);
			return;
		}
		if(strcmp(user,entry_text1) == 0)
		{
			pass = strtok(NULL, " ,\n");
			fprintf(fp,"%s",user);
			fprintf(fp,"%c",' ');
			fflush(fp);
			fprintf(fp,"%s",entry_text2);
			fprintf(fp,"%c",' ');
			fflush(fp);
			
		}
		else
		{
			pass = strtok(NULL, " ,\n");
			fprintf(fp,"%s",user);
			fprintf(fp,"%c",' ');
			fflush(fp);
			fprintf(fp,"%s",pass);
			fprintf(fp,"%c",' ');
			fflush(fp);
		}
		user = strtok(NULL, " ,\n");
	}
	
}
static void login_for_admin(GtkWidget* button1,gpointer data)
{
	const gchar *entry_text1;
	const gchar *entry_text2;
	int i=0;
	int j=0;
	GtkWidget* window_after_login;
	GtkWidget* table;
	GtkWidget* not_label;
	GtkWidget* ok;
	//char* pch;
	//char* pch2;
	char *admin;
	char *pass;
	char combine_string[MAX1];
	FILE* fip;
	entry_text1 = gtk_entry_get_text(GTK_ENTRY(admin_name));
	entry_text2 = gtk_entry_get_text(GTK_ENTRY(admin_pass));
	
	fip = fopen("admin_and_pass.txt","r");
	fseek( fip, 0L, 0 );
	
	fgets (combine_string , MAX1 , fip);
	admin = strtok(combine_string, " ,\n");
	
	while(!feof(fip))
	{
		
		//
		pass = strtok(NULL, " ,\n");
		if(admin==NULL) 
		{
			fclose(fip);
			break;
		} 
		if(strcmp(admin,entry_text1) == 0 && strcmp(pass, entry_text2)==0)
		{
			window_after_login = gtk_window_new (GTK_WINDOW_TOPLEVEL);
			gtk_window_set_title (GTK_WINDOW (window_after_login), "Welcome to Admin Page");
			gtk_window_set_default_size(GTK_WINDOW(window_after_login), 300, 500);
			gtk_container_set_border_width (GTK_CONTAINER (window_after_login), 20);
	                g_signal_connect (window_after_login, "delete-event",G_CALLBACK (gtk_main_quit), NULL);
	                gtk_after_login_by_admin( window_after_login);
	                gtk_widget_show (window_after_login);
	                fclose(fip) ;
	                return;
		}
		admin = strtok(NULL, " ,\n");
	}
	if(pass == NULL)
	{
		window_after_login = gtk_window_new (GTK_WINDOW_TOPLEVEL);
		gtk_window_set_title (GTK_WINDOW (window_after_login), "Admin Not Present");
		gtk_container_set_border_width (GTK_CONTAINER (window_after_login), 20);
	        g_signal_connect (window_after_login, "delete-event",G_CALLBACK (gtk_main_quit), NULL);
	        table = gtk_table_new (1, 2, TRUE);
		gtk_container_add (GTK_CONTAINER (window_after_login), table);
		not_label = gtk_label_new ("You are not admin check user name and password and try again");
        	gtk_table_attach_defaults (GTK_TABLE (table),not_label, 0, 1, 0, 1);
        	ok = gtk_button_new_with_label ("OK");
		gtk_table_attach_defaults (GTK_TABLE (table), ok, 0, 1, 1, 2);
		g_signal_connect (ok, "clicked",G_CALLBACK (gtk_main_quit), NULL);
		gtk_widget_show(not_label);
		gtk_widget_show(ok);
		gtk_widget_show(table);
		 gtk_widget_show (window_after_login);
	}
	
}
void gtk_after_login_by_admin(GtkWidget* windows_after_login)
{
	GtkWidget* table;
	GtkWidget* welcome_note;
	GtkWidget* no_of_user;
	GtkWidget* user_name_and_pass;
	GtkWidget* change_pass_of_user;
	GtkWidget* add_user;
	GtkWidget* delete_user;
	GtkWidget* logout;
	GtkWidget* com_status;
	GtkWidget* free_slot;
	table = gtk_table_new (1,9 , TRUE);
	gtk_container_add (GTK_CONTAINER (windows_after_login), table);
	welcome_note = gtk_label_new ("HII Admin");
        gtk_table_attach_defaults (GTK_TABLE (table),welcome_note, 0, 1, 0, 1);
        gtk_widget_show (welcome_note);
        no_of_user = gtk_button_new_with_label ("No Of User");
	gtk_table_attach_defaults (GTK_TABLE (table), no_of_user, 0, 1, 1, 2);
	g_signal_connect (no_of_user, "clicked",G_CALLBACK (calculate_no_of_user), NULL);
	gtk_widget_show (no_of_user);
	user_name_and_pass = gtk_button_new_with_label ("Username and Password");
	gtk_table_attach_defaults (GTK_TABLE (table), user_name_and_pass, 0, 1, 2, 3);
	g_signal_connect (user_name_and_pass, "clicked",G_CALLBACK (print_user_name_and_pass), NULL);
	gtk_widget_show (user_name_and_pass);
	change_pass_of_user = gtk_button_new_with_label ("Change Password Of User");
	gtk_table_attach_defaults (GTK_TABLE (table), change_pass_of_user, 0, 1, 3, 4);
	g_signal_connect (change_pass_of_user, "clicked",G_CALLBACK (pass_change_by_admin), NULL);
	gtk_widget_show (change_pass_of_user);
	add_user = gtk_button_new_with_label ("Add User");
	gtk_table_attach_defaults (GTK_TABLE (table), add_user, 0, 1, 4, 5);
	g_signal_connect (add_user, "clicked",G_CALLBACK (add_user_by_admin), NULL);
	gtk_widget_show (add_user);
	delete_user = gtk_button_new_with_label ("Delete User");
	gtk_table_attach_defaults (GTK_TABLE (table), delete_user, 0, 1, 5, 6);
	g_signal_connect (delete_user, "clicked",G_CALLBACK (delete_user_by_admin), NULL);
	gtk_widget_show (delete_user);
	com_status = gtk_button_new_with_label ("Com Status");
	gtk_table_attach_defaults (GTK_TABLE (table), com_status, 0, 1, 6, 7);
	g_signal_connect (com_status, "clicked",G_CALLBACK (show_com_to_all), NULL);
	gtk_widget_show (com_status);
	free_slot = gtk_button_new_with_label ("Free Slot");
	gtk_table_attach_defaults (GTK_TABLE (table), free_slot, 0, 1, 7, 8);
	g_signal_connect (free_slot, "clicked",G_CALLBACK (free_any_user), NULL);
	gtk_widget_show (free_slot);
	logout = gtk_button_new_with_label ("Logout");
	gtk_table_attach_defaults (GTK_TABLE (table), logout, 0, 1, 8, 9);
	g_signal_connect (logout, "clicked",G_CALLBACK (gtk_main_quit), NULL);
	gtk_widget_show (logout);
	gtk_widget_show (table);
}
void calculate_no_of_user(GtkWidget* no_of_user, gpointer data)
{
	GtkWidget* window;
	GtkWidget* table;
	GtkWidget* no_of_user_label;
	GtkWidget* ok;
	char buff[2];
	FILE *fp;
	char combine_string[MAX1];
	char* user;
	char* pass;
	int i=0;
	fp=fopen("user_and_pass.txt","r");
	fgets(combine_string,MAX1,fp);
	user=strtok(combine_string," ");
	pass=strtok(NULL," ");
	while(user != NULL && pass!=NULL)
	{
		i++;
		user=strtok(NULL," ");
		pass=strtok(NULL," ");
	}
	window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title (GTK_WINDOW (window), "No Of User");
	gtk_container_set_border_width (GTK_CONTAINER (window), 20);
	g_signal_connect (window, "delete-event",G_CALLBACK (gtk_main_quit), NULL);
	table = gtk_table_new (1, 2, TRUE);
	
	gtk_container_add (GTK_CONTAINER (window), table);
	no_of_user_label = gtk_label_new("0");
	sprintf(buff, "%d", i);
	gtk_label_set_text(GTK_LABEL(no_of_user_label), buff);
        gtk_table_attach_defaults (GTK_TABLE (table),no_of_user_label, 0, 1, 0, 1);
        gtk_widget_show (no_of_user_label);
        ok = gtk_button_new_with_label ("OK");
	gtk_table_attach_defaults (GTK_TABLE (table), ok, 0, 1, 1, 2);
	g_signal_connect (ok, "clicked",G_CALLBACK (gtk_main_quit), NULL);
	//g_signal_connect (ok, "clicked",G_CALLBACK (gtk_after_login_by_admin), NULL);
	gtk_widget_show (ok);
	gtk_widget_show (table);
	gtk_widget_show (window);
}
static void print_user_name_and_pass(GtkWidget* change_pass_of_user , gpointer data)
{
	GtkWidget* window;
	GtkWidget* username_label;
	GtkWidget* password_label;
	GtkWidget* table;
	GtkWidget*button_exit;
	int i=0;
	int j=0,k=0;
	char buff[10];
	char *user;
	char *pass;
	char combine_string[MAX1];
	FILE* fip;
	fip = fopen("user_and_pass.txt","r");
	//fseek( fip, 0L, 0 );
	
	fgets (combine_string , MAX1 , fip);
	user = strtok(combine_string, " ,\n");
	pass = strtok(NULL, " ,\n");
	while(pass!=NULL)
	{
		i++;
		user = strtok(NULL, " ,\n");
		pass = strtok(NULL, " ,\n");
	}
	fclose(fip);
	j=i;
	
	window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title (GTK_WINDOW (window), "Username And Password");
	gtk_window_set_default_size(GTK_WINDOW(window), 300, 500);
	gtk_container_set_border_width (GTK_CONTAINER (window), 20);
	g_signal_connect (window, "delete-event",G_CALLBACK (gtk_main_quit), NULL);
	table = gtk_table_new (3,i+2, TRUE);
	gtk_container_add (GTK_CONTAINER (window), table);
	GtkWidget* labels[2*i];
	username_label = gtk_label_new ("User Name");
        gtk_table_attach_defaults (GTK_TABLE (table),username_label, 0, 1, 0, 1);
        gtk_widget_show (username_label);
        password_label = gtk_label_new ("Password");
        gtk_table_attach_defaults (GTK_TABLE (table),password_label, 2, 3, 0, 1);
        gtk_widget_show (password_label);
	fip = fopen("user_and_pass.txt","r");
	fgets (combine_string , MAX1 , fip);
	user = strtok(combine_string, " ,\n");
	pass = strtok(NULL, " ,\n");
	i=0;
	while(pass!=NULL)
	{
		labels[i] = gtk_label_new("0");
		sprintf(buff, "%s", user);
		gtk_label_set_text(GTK_LABEL(labels[i]), buff);
        	gtk_table_attach_defaults (GTK_TABLE (table),labels[i], 0, 1, i+1, i+2);
        	//g_print("%d",i);
        	gtk_widget_show (labels[i]);
        	labels[i+1] = gtk_label_new("0");
        	sprintf(buff, "%s", pass);
        	gtk_label_set_text(GTK_LABEL(labels[i+1]), buff);
        	gtk_table_attach_defaults (GTK_TABLE (table),labels[i+1], 2, 3, i+1,i+2);
        	gtk_widget_show (labels[i+1]);
        	i=i+2;
		user = strtok(NULL, " ,\n");
		pass = strtok(NULL, " ,\n");
	}
	fclose(fip);
	 button_exit = gtk_button_new_with_label ("Exit");
	printf("%d",j);
	gtk_table_attach_defaults (GTK_TABLE (table),button_exit, 2, 3, j+1, j+2);
	// gtk_widget_show (button_exit);
	 //g_signal_connect (button_exit, "clicked",G_CALLBACK (gtk_main_quit), NULL);
	 gtk_widget_show(table);
	 gtk_widget_show(window);
}
static void pass_change_by_admin(GtkWidget* change_pass_of_user , gpointer data)
{
	//FILE*  fp;
	//fp = fopen("user_and_pass.txt","w+");
	GtkWidget* window_for_change_pass;
	GtkWidget* ok;
	GtkWidget* cencel;
	GtkWidget* table;
	//GtkWidget* new_pass;
	window_for_change_pass = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title (GTK_WINDOW (window_for_change_pass), "Change Password");
	gtk_window_set_default_size(GTK_WINDOW(window_for_change_pass), 100, 100);
	gtk_container_set_border_width (GTK_CONTAINER (window_for_change_pass), 20);
	g_signal_connect (window_for_change_pass, "delete-event",G_CALLBACK (gtk_main_quit), NULL);
	table = gtk_table_new (4,1, TRUE);
	gtk_container_add (GTK_CONTAINER (window_for_change_pass), table);
	user_name = gtk_entry_new ();
        gtk_table_attach_defaults (GTK_TABLE (table),user_name, 0, 1, 0, 1);
        gtk_entry_set_text(GTK_ENTRY(user_name),"User Name");
        gtk_widget_show (user_name); 
	user_pass = gtk_entry_new ();
        gtk_table_attach_defaults (GTK_TABLE (table),user_pass, 0, 1, 1, 2);
        gtk_entry_set_text(GTK_ENTRY(user_pass),"New Password");
        gtk_widget_show (user_pass); 
        ok = gtk_button_new_with_label ("Change Password");
	gtk_table_attach_defaults (GTK_TABLE (table), ok, 0, 1, 2, 3);
	g_signal_connect (ok, "clicked",G_CALLBACK (mech_for_change_pass), NULL);
	gtk_widget_show (ok);
	cencel = gtk_button_new_with_label ("cencel");
	gtk_table_attach_defaults (GTK_TABLE (table), cencel, 0, 1, 3, 4);
	g_signal_connect (cencel, "clicked",G_CALLBACK (gtk_main_quit), NULL) ;
	gtk_widget_show (cencel);
        gtk_widget_show(table);
        gtk_widget_show(window_for_change_pass);
}
static void add_user_by_admin(GtkWidget* add_user , gpointer data)
{
	GtkWidget* window;
	GtkWidget* create;
	GtkWidget* cencel;
	GtkWidget* table;
	window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title (GTK_WINDOW (window), "Create New User");
	gtk_window_set_default_size(GTK_WINDOW(window), 100, 100);
	gtk_container_set_border_width (GTK_CONTAINER (window), 20);
	g_signal_connect (window, "delete-event",G_CALLBACK (gtk_main_quit), NULL);
	table = gtk_table_new (4,1, TRUE);
	gtk_container_add (GTK_CONTAINER (window), table);
	user_name = gtk_entry_new ();
        gtk_table_attach_defaults (GTK_TABLE (table),user_name, 0, 1, 0, 1);
        gtk_entry_set_text(GTK_ENTRY(user_name),"User Name");
        gtk_widget_show (user_name); 
	user_pass = gtk_entry_new ();
        gtk_table_attach_defaults (GTK_TABLE (table),user_pass, 0, 1, 1, 2);
        gtk_entry_set_text(GTK_ENTRY(user_pass),"Password");
        gtk_widget_show (user_pass); 
        create = gtk_button_new_with_label ("Create");
	gtk_table_attach_defaults (GTK_TABLE (table), create, 0, 1, 2, 3);
	g_signal_connect (create, "clicked",G_CALLBACK (mech_of_add_user), NULL);
	gtk_widget_show (create);
	cencel = gtk_button_new_with_label ("Cencel");
	gtk_table_attach_defaults (GTK_TABLE (table), cencel, 0, 1, 3, 4);
	g_signal_connect (cencel, "clicked",G_CALLBACK (gtk_main_quit), NULL) ;
	gtk_widget_show (cencel);
        gtk_widget_show(table);
        gtk_widget_show(window);
	
}
static void delete_user_by_admin(GtkWidget* delete_user , gpointer data)
{
	GtkWidget* window;
	GtkWidget* delete;
	GtkWidget* cencel;
	GtkWidget* table;
	window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title (GTK_WINDOW (window), "Delete User");
	gtk_window_set_default_size(GTK_WINDOW(window), 100, 100);
	gtk_container_set_border_width (GTK_CONTAINER (window), 20);
	g_signal_connect (window, "delete-event",G_CALLBACK (gtk_main_quit), NULL);
	table = gtk_table_new (4,1, TRUE);
	gtk_container_add (GTK_CONTAINER (window), table);
	user_name = gtk_entry_new ();
        gtk_table_attach_defaults (GTK_TABLE (table),user_name, 0, 1, 0, 1);
        gtk_entry_set_text(GTK_ENTRY(user_name),"User Name");
        gtk_widget_show (user_name); 
	/*user_pass = gtk_entry_new ();
        gtk_table_attach_defaults (GTK_TABLE (table),user_pass, 0, 1, 1, 2);
        gtk_entry_set_text(GTK_ENTRY(user_pass),"Password");
        gtk_widget_show (user_pass); */
        delete = gtk_button_new_with_label ("Delete");
	gtk_table_attach_defaults (GTK_TABLE (table), delete, 0, 1, 2, 3);
	g_signal_connect (delete, "clicked",G_CALLBACK (mech_of_delete_user), NULL);
	gtk_widget_show (delete);
	cencel = gtk_button_new_with_label ("Cencel");
	gtk_table_attach_defaults (GTK_TABLE (table), cencel, 0, 1, 3, 4);
	g_signal_connect (cencel, "clicked",G_CALLBACK (gtk_main_quit), NULL) ;
	gtk_widget_show (cencel);
        gtk_widget_show(table);
        gtk_widget_show(window);
}
static void mech_of_add_user(GtkWidget* create , gpointer data)
{
	int i=0;
	GtkWidget* window;
	GtkWidget* table;
	GtkWidget* already_present_label;
	GtkWidget* ok;
	const gchar *entry_text1;
	const gchar *entry_text2;
	entry_text1 = gtk_entry_get_text(GTK_ENTRY(user_name));
	entry_text2 = gtk_entry_get_text(GTK_ENTRY(user_pass));
	FILE *fp;
	//fp=fopen("user_and_pass.txt","a");
	char combine_string[MAX1];
	char* user;
	char* pass;
	fp=fopen("user_and_pass.txt","r");
	fgets(combine_string,MAX1,fp);
	fclose(fp);
	fp=fopen("user_and_pass.txt","wt");
	user=strtok(combine_string," ");
	pass=strtok(NULL," ");
	while(user != NULL && pass != NULL)
	{
		if(strcmp(user,entry_text1) == 0)
		{
			i=1;
			window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
			gtk_window_set_title (GTK_WINDOW (window), "Status");
			gtk_container_set_border_width (GTK_CONTAINER (window), 20);
			g_signal_connect (window, "delete-event",G_CALLBACK (gtk_main_quit), NULL);
			table = gtk_table_new (1, 2, TRUE);
			gtk_container_add (GTK_CONTAINER (window), table);
			already_present_label = gtk_label_new ("User is already present");
        		gtk_table_attach_defaults (GTK_TABLE (table),already_present_label, 0, 1, 0, 1);
        		ok = gtk_button_new_with_label ("OK");
			gtk_table_attach_defaults (GTK_TABLE (table), ok, 0, 1, 1, 2);
			g_signal_connect (ok, "clicked",G_CALLBACK (gtk_main_quit), NULL);
			gtk_widget_show(already_present_label);
			gtk_widget_show(ok);
			gtk_widget_show(table);
			gtk_widget_show(window);
		}
		
		fprintf(fp,"%s",user);
		fprintf(fp," ");
		fprintf(fp,"%s",pass);
		fprintf(fp," ");
		user=strtok(NULL," ");
		pass=strtok(NULL," ");
	} 
	//fseek(fp,-2, SEEK_END);
	if(pass ==NULL && i==0)
	{
		fprintf(fp," ");
		fprintf(fp,"%s",entry_text1);
		fprintf(fp," ");
		fprintf(fp,"%s",entry_text2);
		window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
		gtk_window_set_title (GTK_WINDOW (window), "Status");
		gtk_container_set_border_width (GTK_CONTAINER (window), 20);
		g_signal_connect (window, "delete-event",G_CALLBACK (gtk_main_quit), NULL);
		table = gtk_table_new (1, 2, TRUE);
		gtk_container_add (GTK_CONTAINER (window), table);
		already_present_label = gtk_label_new ("User has been added successfully");
        	gtk_table_attach_defaults (GTK_TABLE (table),already_present_label, 0, 1, 0, 1);
        	ok = gtk_button_new_with_label ("OK");
		gtk_table_attach_defaults (GTK_TABLE (table), ok, 0, 1, 1, 2);
		g_signal_connect (ok, "clicked",G_CALLBACK (gtk_main_quit), NULL);
		gtk_widget_show(already_present_label);
		gtk_widget_show(ok);
		gtk_widget_show(table);
		gtk_widget_show(window);
	}
	fclose(fp);
}
static void mech_of_delete_user(GtkWidget* delete , gpointer data)
{
	int i=0;
	GtkWidget* window;
	GtkWidget* table;
	GtkWidget* already_present_label;
	GtkWidget* ok;
	const gchar *entry_text1;
	entry_text1 = gtk_entry_get_text(GTK_ENTRY(user_name));
	FILE *fp;
	//fp=fopen("user_and_pass.txt","a");
	char combine_string[MAX1];
	char* user;
	char* pass;
	fp=fopen("user_and_pass.txt","r");
	fgets(combine_string,MAX1,fp);
	fclose(fp);
	fp=fopen("user_and_pass.txt","wt");
	user=strtok(combine_string," ");
	pass=strtok(NULL," ");
	while(user != NULL && pass!= NULL)
	{
		if(strcmp(user,entry_text1) == 0)
		{
		 	i=1;
			
			user=strtok(NULL," ");
			pass=strtok(NULL," ");
			window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
			gtk_window_set_title (GTK_WINDOW (window), "Status");
			gtk_container_set_border_width (GTK_CONTAINER (window), 20);
			g_signal_connect (window, "delete-event",G_CALLBACK (gtk_main_quit), NULL);
			table = gtk_table_new (1, 2, TRUE);
			gtk_container_add (GTK_CONTAINER (window), table);
			already_present_label = gtk_label_new ("User has been delected");
        		gtk_table_attach_defaults (GTK_TABLE (table),already_present_label, 0, 1, 0, 1);
        		ok = gtk_button_new_with_label ("OK");
			gtk_table_attach_defaults (GTK_TABLE (table), ok, 0, 1, 1, 2);
			g_signal_connect (ok, "clicked",G_CALLBACK (gtk_main_quit), NULL);
			gtk_widget_show(already_present_label);
			gtk_widget_show(ok);
			gtk_widget_show(table);
			gtk_widget_show(window);
		}
	if(pass != NULL){
		fprintf(fp,"%s",user);
		fprintf(fp," ");
		fprintf(fp,"%s",pass);
		fprintf(fp," ");
		user=strtok(NULL," ");
		pass=strtok(NULL," ");}
	}
	if(pass==NULL && i==0)
	{
		window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
		gtk_window_set_title (GTK_WINDOW (window), "Status");
		gtk_container_set_border_width (GTK_CONTAINER (window), 20);
		g_signal_connect (window, "delete-event",G_CALLBACK (gtk_main_quit), NULL);
		table = gtk_table_new (1, 2, TRUE);
		gtk_container_add (GTK_CONTAINER (window), table);
		already_present_label = gtk_label_new ("User is not present");
        	gtk_table_attach_defaults (GTK_TABLE (table),already_present_label, 0, 1, 0, 1);
        	ok = gtk_button_new_with_label ("OK");
		gtk_table_attach_defaults (GTK_TABLE (table), ok, 0, 1, 1, 2);
		g_signal_connect (ok, "clicked",G_CALLBACK (gtk_main_quit), NULL);
		gtk_widget_show(already_present_label);
		gtk_widget_show(ok);
		gtk_widget_show(table);
		gtk_widget_show(window);
	}
	fclose(fp);
}
static void book_com_window(GtkWidget* register_com , gpointer data)
{
	GtkWidget* window;
	GtkWidget* book;
	GtkWidget* table;
	window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title (GTK_WINDOW (window), "Book Com");
	gtk_container_set_border_width (GTK_CONTAINER (window), 20);
	g_signal_connect (window, "delete-event",G_CALLBACK (gtk_main_quit), NULL);
	table = gtk_table_new (1,6, TRUE);
	gtk_container_add (GTK_CONTAINER (window), table);
	entry_day = gtk_entry_new ();
        gtk_table_attach_defaults (GTK_TABLE (table),entry_day, 0, 1, 0, 1);
        gtk_entry_set_text(GTK_ENTRY(entry_day),"Enter Week Day( in Caps)");
        gtk_widget_show (entry_day); 
        entry_begin = gtk_entry_new ();
        gtk_table_attach_defaults (GTK_TABLE (table),entry_begin, 0, 1, 1, 2);
        gtk_entry_set_text(GTK_ENTRY(entry_begin),"Time from (in 24)");
        gtk_widget_show (entry_begin); 
        entry_end = gtk_entry_new ();
        gtk_table_attach_defaults (GTK_TABLE (table),entry_end, 0, 1, 2, 3);
        gtk_entry_set_text(GTK_ENTRY(entry_end),"Time upto(in 24)");
        gtk_widget_show (entry_end); 
        entry_date = gtk_entry_new ();
        gtk_table_attach_defaults (GTK_TABLE (table),entry_date, 0, 1, 3, 4);
        gtk_entry_set_text(GTK_ENTRY(entry_date),"dd/mm/yy");
        gtk_widget_show (entry_date); 
        entry_com = gtk_entry_new ();
        gtk_table_attach_defaults (GTK_TABLE (table),entry_com, 0, 1, 4, 5);
        gtk_entry_set_text(GTK_ENTRY(entry_com),"com1");
        gtk_widget_show (entry_com); 
        book = gtk_button_new_with_label ("BOOK");
	gtk_table_attach_defaults (GTK_TABLE (table), book, 0, 1, 5, 6);
	g_signal_connect (book, "clicked",G_CALLBACK (mech_for_book_com), NULL);
	gtk_widget_show(book);
	gtk_widget_show(table);
	gtk_widget_show(window);
}
static void mech_for_book_com(GtkWidget* book ,gpointer data)
{
	int i=0;
	GtkWidget* window;
	GtkWidget* table;
	GtkWidget* already_present_label;
	GtkWidget* ok;
	const gchar *entry_text1;
	const gchar *day;
	const gchar *begin;
	const gchar *end;
	const gchar *date;
	const gchar *com;
	char *first;
	char *second;
	char *third;
	char *fourth;
	char *fifth;
	char* sixth;
	FILE *fp;
	char combine_string[MAX1];
	entry_text1 = gtk_entry_get_text(GTK_ENTRY(user_name));
	day = gtk_entry_get_text(GTK_ENTRY(entry_day));
	begin = gtk_entry_get_text(GTK_ENTRY(entry_begin));
	end = gtk_entry_get_text(GTK_ENTRY(entry_end));
	date = gtk_entry_get_text(GTK_ENTRY(entry_date));
	com=gtk_entry_get_text(GTK_ENTRY(entry_com));
	fp=fopen("register_com.txt","r");
	fgets(combine_string,MAX1,fp);
	fclose(fp);
	fp=fopen("register_com.txt","wt");
	first=strtok(combine_string," \n");
	second=strtok(NULL," \n");
	while(first != NULL && second!= NULL)
	{
		
		third=strtok(NULL," \n");
		fourth=strtok(NULL," \n");
		fifth=strtok(NULL," \n");
		sixth=strtok(NULL," \n");
		if(strcmp(first,entry_text1)==0 ||(strcmp(second,day)==0 && ((begin<=third || end>=third) ||(begin<=fourth &&end>=fourth)) && strcmp(fifth,date)==0 && strcmp                  (sixth,com)==0))
		{
			i=1;
			window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
			gtk_window_set_title (GTK_WINDOW (window), "Already Allocated");
			gtk_container_set_border_width (GTK_CONTAINER (window), 20);
			g_signal_connect (window, "delete-event",G_CALLBACK (gtk_main_quit), NULL);
			table = gtk_table_new (1, 2, TRUE);
			gtk_container_add (GTK_CONTAINER (window), table);
			already_present_label = gtk_label_new ("Com is not free.");
        		gtk_table_attach_defaults (GTK_TABLE (table),already_present_label, 0, 1, 0, 1);
        		ok = gtk_button_new_with_label ("OK");
			gtk_table_attach_defaults (GTK_TABLE (table), ok, 0, 1, 1, 2);
			g_signal_connect (ok, "clicked",G_CALLBACK (gtk_main_quit), NULL);
			gtk_widget_show(already_present_label);
			gtk_widget_show(ok);
			gtk_widget_show(table);
			gtk_widget_show(window);
			
		}
		fprintf(fp,"%s",first);
		fprintf(fp," ");
		fprintf(fp,"%s",second);
		fprintf(fp," ");
		fprintf(fp,"%s",third);
		fprintf(fp," ");
		fprintf(fp,"%s",fourth);
		fprintf(fp," ");
		fprintf(fp,"%s",fifth);
		fprintf(fp," ");
		fprintf(fp,"%s",sixth);
		fprintf(fp," ");
		first=strtok(NULL," \n");
		second=strtok(NULL," \n");
	}
	if(second == NULL && i==0)
	{
		fprintf(fp,"%s",entry_text1);
		fprintf(fp," ");
		fprintf(fp,"%s",day);
		fprintf(fp," ");
		fprintf(fp,"%s",begin);
		fprintf(fp," ");
		fprintf(fp,"%s",end);
		fprintf(fp," ");
		fprintf(fp,"%s",date);
		fprintf(fp," ");
		fprintf(fp,"%s",com);
		fprintf(fp," ");
		window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
		gtk_window_set_title (GTK_WINDOW (window), "DONE");
		gtk_container_set_border_width (GTK_CONTAINER (window), 20);
		g_signal_connect (window, "delete-event",G_CALLBACK (gtk_main_quit), NULL);
		table = gtk_table_new (1, 2, TRUE);
		gtk_container_add (GTK_CONTAINER (window), table);
		already_present_label = gtk_label_new ("Com has been allocated to you");
        	gtk_table_attach_defaults (GTK_TABLE (table),already_present_label, 0, 1, 0, 1);
        	ok = gtk_button_new_with_label ("OK");
		gtk_table_attach_defaults (GTK_TABLE (table), ok, 0, 1, 1, 2);
		g_signal_connect (ok, "clicked",G_CALLBACK (gtk_main_quit), NULL);
		gtk_widget_show(already_present_label);
		gtk_widget_show(ok);
		gtk_widget_show(table);
		gtk_widget_show(window);
	}
	fclose(fp);
}
static void show_com_to_all(GtkWidget* show_com, gpointer data)
{
	char combine_string[MAX1];
	int i=0;
	char buff[10];
	char* first;
	//const gchar* entry_text1;
	char* second;
	char* third;
	char* fourth;
	char* fifth;
	char* sixth;
	int temp;
	GtkWidget* table;
	GtkWidget* window;
	GtkWidget* button_exit;
	FILE* fp;
	//entry_text1 = gtk_entry_get_text(GTK_ENTRY(user_name));
	fp=fopen("register_com.txt","r");
	fgets(combine_string,MAX1,fp);
	fclose(fp);
	fp=fopen("register_com.txt","wt");
	first=strtok(combine_string," ");
	second=strtok(NULL," ");
	while(first != NULL && second !=NULL)
	{
		if(first==NULL)
		{
			fclose(fp);
			break;
		}
		
		third=strtok(NULL," ");
		fourth=strtok(NULL," ");
		fifth=strtok(NULL," ");
		sixth=strtok(NULL," ");
		i++;
		fprintf(fp,"%s",first);
		fprintf(fp," ");
		fprintf(fp,"%s",second);
		fprintf(fp," ");
		fprintf(fp,"%s",third);
		fprintf(fp," ");
		fprintf(fp,"%s",fourth);
		fprintf(fp," ");
		fprintf(fp,"%s",fifth);
		fprintf(fp," ");
		fprintf(fp,"%s",sixth);
		fprintf(fp," ");
		first=strtok(NULL," ");
		second=strtok(NULL," ");
	}
	temp=i;
	GtkWidget* label[6+6*i];
	window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title (GTK_WINDOW (window), "Registered Coms");
	gtk_container_set_border_width (GTK_CONTAINER (window), 20);
	g_signal_connect (window, "delete-event",G_CALLBACK (gtk_main_quit), NULL);
	table = gtk_table_new (6, i+2, TRUE);
	gtk_container_add (GTK_CONTAINER (window), table);
	label[0] = gtk_label_new ("User Name");
        gtk_table_attach_defaults (GTK_TABLE (table),label[0], 0, 1, 0, 1);
        gtk_widget_show (label[0]);
        label[1] = gtk_label_new ("Day");
        gtk_table_attach_defaults (GTK_TABLE (table),label[1], 1, 2, 0, 1);
        gtk_widget_show (label[1]);
        label[2] = gtk_label_new ("From");
        gtk_table_attach_defaults (GTK_TABLE (table),label[2], 2, 3, 0, 1);
        gtk_widget_show (label[2]);
        label[3] = gtk_label_new ("To");
        gtk_table_attach_defaults (GTK_TABLE (table),label[3], 3, 4, 0, 1);
        gtk_widget_show (label[3]);
        label[4] = gtk_label_new ("Date");
        gtk_table_attach_defaults (GTK_TABLE (table),label[4], 4, 5, 0, 1);
        gtk_widget_show (label[4]);
        label[5] = gtk_label_new ("Com No");
        gtk_table_attach_defaults (GTK_TABLE (table),label[5], 5, 6, 0, 1);
        gtk_widget_show (label[5]);
        fclose(fp);
	fp = fopen("register_com.txt","r");
	fgets (combine_string , MAX1 , fp);
	first = strtok(combine_string, " ,\n");
	second = strtok(NULL, " ,\n");
	i=6;
	while(first !=NULL && second != NULL)
	{
		
		third=strtok(NULL, " ,\n");
		fourth=strtok(NULL, " ,\n");
		fifth=strtok(NULL, " ,\n");
		sixth=strtok(NULL, " ,\n");
		label[i] = gtk_label_new("0");
		sprintf(buff, "%s", first);
		gtk_label_set_text(GTK_LABEL(label[i]), buff);
        	gtk_table_attach_defaults (GTK_TABLE (table),label[i], 0, 1, i-5, i-4);
        	//g_print("%d",i);
        	gtk_widget_show (label[i]);
        	label[i+1] = gtk_label_new("0");
        	sprintf(buff, "%s", second);
        	gtk_label_set_text(GTK_LABEL(label[i+1]), buff);
        	gtk_table_attach_defaults (GTK_TABLE (table),label[i+1], 1, 2, i-5,i-4);
        	gtk_widget_show (label[i+1]);
        	label[i+2] = gtk_label_new("0");
		sprintf(buff, "%s", third);
		gtk_label_set_text(GTK_LABEL(label[i+2]), buff);
        	gtk_table_attach_defaults (GTK_TABLE (table),label[i+2], 2, 3, i-5, i-4);
        	gtk_widget_show (label[i+2]);
        	label[i+3] = gtk_label_new("0");
		sprintf(buff, "%s", fourth);
		gtk_label_set_text(GTK_LABEL(label[i+3]), buff);
        	gtk_table_attach_defaults (GTK_TABLE (table),label[i+3], 3, 4, i-5, i-4);
        	gtk_widget_show (label[i+3]);
        	label[i+4] = gtk_label_new("0");
		sprintf(buff, "%s", fifth);
		gtk_label_set_text(GTK_LABEL(label[i+4]), buff);
        	gtk_table_attach_defaults (GTK_TABLE (table),label[i+4], 4, 5, i-5, i-4);
        	gtk_widget_show (label[i+4]);
        	label[i+5] = gtk_label_new("0");
		sprintf(buff, "%s", sixth);
		gtk_label_set_text(GTK_LABEL(label[i+5]), buff);
        	gtk_table_attach_defaults (GTK_TABLE (table),label[i+5], 5, 6, i-5, i-4);
        	gtk_widget_show (label[i+5]);
        	i=i+1;
		first = strtok(NULL, " ,\n");
		second = strtok(NULL, " ,\n");
	}
	fclose(fp);
	button_exit = gtk_button_new_with_label ("Exit");
	gtk_table_attach_defaults (GTK_TABLE (table),button_exit, 5, 6, temp+1, temp+2);
	 gtk_widget_show (button_exit);
	 g_signal_connect (button_exit, "clicked",G_CALLBACK (gtk_main_quit), NULL);
	 gtk_widget_show(button_exit);
	gtk_widget_show(table);
	gtk_widget_show(window);
}
static void free_any_user(GtkWidget* free_slot , gpointer data)
{
	GtkWidget* window;
	GtkWidget* delete;
	GtkWidget* cencel;
	GtkWidget* table;
	window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title (GTK_WINDOW (window), "Delete User From Com List");
	gtk_window_set_default_size(GTK_WINDOW(window), 100, 100);
	gtk_container_set_border_width (GTK_CONTAINER (window), 20);
	g_signal_connect (window, "delete-event",G_CALLBACK (gtk_main_quit), NULL);
	table = gtk_table_new (4,1, TRUE);
	gtk_container_add (GTK_CONTAINER (window), table);
	user_name = gtk_entry_new ();
        gtk_table_attach_defaults (GTK_TABLE (table),user_name, 0, 1, 0, 1);
        gtk_entry_set_text(GTK_ENTRY(user_name),"User Name");
        gtk_widget_show (user_name); 
	delete = gtk_button_new_with_label ("Remove");
	gtk_table_attach_defaults (GTK_TABLE (table), delete, 0, 1, 2, 3);
	g_signal_connect (delete, "clicked",G_CALLBACK (mech_of_remove_user_from_com), NULL);
	gtk_widget_show (delete);
	cencel = gtk_button_new_with_label ("Cencel");
	gtk_table_attach_defaults (GTK_TABLE (table), cencel, 0, 1, 3, 4);
	g_signal_connect (cencel, "clicked",G_CALLBACK (gtk_main_quit), NULL) ;
	gtk_widget_show (cencel);
        gtk_widget_show(table);
        gtk_widget_show(window);
}
static void mech_of_remove_user_from_com(GtkWidget* delete , gpointer data)
{
	char combine_string[MAX1];
	int i=0;
	char buff[10];
	char* first;
	const gchar* entry_text1;
	char* second;
	char* third;
	char* fourth;
	char* fifth;
	char* sixth;
	int temp;
	GtkWidget* table;
	GtkWidget* window;
	GtkWidget* ok;
	GtkWidget* already_present_label;
	FILE* fp;
	entry_text1 = gtk_entry_get_text(GTK_ENTRY(user_name));
	fp=fopen("register_com.txt","r");
	fgets(combine_string,MAX1,fp);
	fclose(fp);
	fp=fopen("register_com.txt","wt");
	first=strtok(combine_string," ");
	second=strtok(NULL," ");
	while(first != NULL && second !=NULL)
	{
		
		if(strcmp(first,entry_text1)==0)
		{
			i=1;
			third=strtok(NULL," ");
			fourth=strtok(NULL," ");
			fifth=strtok(NULL," ");
			sixth=strtok(NULL," ");
			first=strtok(NULL," ");
			second=strtok(NULL," ");
			window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
			gtk_window_set_title (GTK_WINDOW (window), "DONE");
			gtk_container_set_border_width (GTK_CONTAINER (window), 20);
			g_signal_connect (window, "delete-event",G_CALLBACK (gtk_main_quit), NULL);
			table = gtk_table_new (1, 2, TRUE);
			gtk_container_add (GTK_CONTAINER (window), table);
			already_present_label = gtk_label_new ("User is removed from the com list");
        		gtk_table_attach_defaults (GTK_TABLE (table),already_present_label, 0, 1, 0, 1);
        		ok = gtk_button_new_with_label ("OK");
			gtk_table_attach_defaults (GTK_TABLE (table), ok, 0, 1, 1, 2);
			g_signal_connect (ok, "clicked",G_CALLBACK (gtk_main_quit), NULL);
			gtk_widget_show(already_present_label);
			gtk_widget_show(ok);
			gtk_widget_show(table);
			gtk_widget_show(window);
		}
		if(first==NULL)
		{
			fclose(fp);
			return;
		}
		third=strtok(NULL," ");
		fourth=strtok(NULL," ");
		fifth=strtok(NULL," ");
		sixth=strtok(NULL," ");
		fprintf(fp,"%s",first);
		fprintf(fp," ");
		fprintf(fp,"%s",second);
		fprintf(fp," ");
		fprintf(fp,"%s",third);
		fprintf(fp," ");
		fprintf(fp,"%s",fourth);
		fprintf(fp," ");
		fprintf(fp,"%s",fifth);
		fprintf(fp," ");
		fprintf(fp,"%s",sixth);
		fprintf(fp," ");
		first=strtok(NULL," ");
		second=strtok(NULL," ");
	}
	fclose(fp);
	if(second==NULL && i==0)
	{
		window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
		gtk_window_set_title (GTK_WINDOW (window), "DONE");
		gtk_container_set_border_width (GTK_CONTAINER (window), 20);
		g_signal_connect (window, "delete-event",G_CALLBACK (gtk_main_quit), NULL);
		table = gtk_table_new (1, 2, TRUE);
		gtk_container_add (GTK_CONTAINER (window), table);
		already_present_label = gtk_label_new ("User is not present in the com list");
        	gtk_table_attach_defaults (GTK_TABLE (table),already_present_label, 0, 1, 0, 1);
        	ok = gtk_button_new_with_label ("OK");
		gtk_table_attach_defaults (GTK_TABLE (table), ok, 0, 1, 1, 2);
		g_signal_connect (ok, "clicked",G_CALLBACK (gtk_main_quit), NULL);
		gtk_widget_show(already_present_label);
		gtk_widget_show(ok);
		gtk_widget_show(table);
		gtk_widget_show(window);
	}
}























