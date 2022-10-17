#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Table.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Button.H>

#include <stdio.h>



enum screen_size {
    scr_w = 1920,
    scr_h = 1080
};

enum window_size {
    win_w = 400,
    win_h = 250
};

enum { spacing = 30 };

static int get_pos(int s, int w)
{
    return s/2 - w;
}

static void menu_cb(Fl_Widget *w, void *data)
{
    if(data)
        puts((const char*)data);
}


static struct Fl_Menu_Item items[] = {
    { "File", 0, 0, 0, FL_SUBMENU },
        { "New",         FL_CTRL + 'n', 0, 0, 0 },
        { "Open",        FL_CTRL + 'N', 0, 0, 0 },
        { "Save",        FL_CTRL + 's', 0, 0, 0 },
        { "Save as\t\t", FL_CTRL + 'S', 0, 0, FL_MENU_DIVIDER },
        { "Exit",        0, 0, 0, 0 },
        { 0 },
    { "Edit", 0, 0, 0, FL_MENU_INACTIVE | FL_SUBMENU },
        { "Add record",      0, 0, 0, 0 },
        { "Edit record",     0, 0, 0, 0 },
        { "Remove record\t", 0, 0, 0, 0 },
        { 0 },
    { "Help", 0, 0, 0, FL_SUBMENU },
        { "Help",      FL_CTRL + 'h', 0, 0, FL_MENU_DIVIDER },
        { "About\t\t", FL_CTRL + 'p', 0, 0, 0 },
        { 0 },
    { 0 }
};

int main()
{

    int pos_x = get_pos(scr_w, win_w), pos_y = get_pos(scr_h, win_h);
    Fl_Window *win =
        new Fl_Window(pos_x, pos_y, win_w, win_h, "Main window");

    Fl_Menu_Bar *menu = new Fl_Menu_Bar(0, 0, win_w, spacing);
    menu->menu(items);

    Fl_Table *table = new Fl_Table(spacing, 2*spacing,
                win_w-2*spacing, win_h-3*spacing);

    win->resizable(table);
    win->size_range(win_w, win_h);
    win->end();
    win->show();
    return Fl::run();
}
