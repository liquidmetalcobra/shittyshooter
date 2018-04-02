
#include <iostream>
#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_native_dialog.h"
#include "globals.h"
#include "keyboardmanager.hpp"
extern "C" {
# include "lua.h"
# include "lauxlib.h"
# include "lualib.h"
}
#include <unistd.h>
#include "LuaBridge/LuaBridge.h"

#include "LevelLoader.hpp"



using namespace std;
int main(int argc, char **argv)
{
    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_EVENT_QUEUE *event_queue = NULL;
    ALLEGRO_TIMER *timer = NULL;
    
    
    bool redraw = true;
    bool doexit = false;
    
    //_GLOBALCONFIG = *GlobalConfig::instance();
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL)
        fprintf(stdout, "Current working dir: %s\n", cwd);
    cout << ALLEGRO_RESOURCES_PATH;
    
    
    cout << "main: global_ptr is " << G_FPS << '\n';
    
    
    if(!al_init()) {
        fprintf(stderr, "failed to initialize allegro!\n");
        return -1;
    }
    
    
    al_init_font_addon(); // initialize the font addon
    al_init_ttf_addon();// initialize the ttf (True Type Font) addon
    
    if(!al_init_image_addon()) {
        al_show_native_message_box(display, "Error", "Error", "Failed to initialize al_init_image_addon!",
                                   NULL, ALLEGRO_MESSAGEBOX_ERROR);
        return -1;
    }
    
    if(!al_install_keyboard()) {
        fprintf(stderr, "failed to initialize the keyboard!\n");
        return -1;
    }
    
    if(!al_install_mouse()) {
        fprintf(stderr, "failed to initialize the mouse!\n");
        return -1;
    }
    
    timer = al_create_timer(1.0 / G_FPS);
    if(!timer) {
        fprintf(stderr, "failed to create timer!\n");
        return -1;
    }
    
    display = al_create_display(G_SCREEN_W, G_SCREEN_H);
    if(!display) {
        fprintf(stderr, "failed to create display!\n");
        al_destroy_timer(timer);
        return -1;
    }
    //Level1 lev = Level1();
    LevelLoader lev = LevelLoader();
    al_set_target_bitmap(al_get_backbuffer(display));
    
    event_queue = al_create_event_queue();
    if(!event_queue) {
        fprintf(stderr, "failed to create event_queue!\n");
        
        al_destroy_display(display);
        al_destroy_timer(timer);
        return -1;
    }
 
 
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_mouse_event_source());
    
    al_clear_to_color(al_map_rgb(0,0,0));
    
    al_flip_display();
    
    al_start_timer(timer);
    
    
    
    
    while(!doexit)
    {
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);
        
        if(ev.type == ALLEGRO_EVENT_TIMER) {
            lev.update();
            redraw = true;
        }
        else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            break;
        }
        else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
        {
            lev.handleMouseEvent(ev);
        }
        else if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {
       
            
            updateKeyboardKeyState(ev.keyboard.keycode, true);
        }
        else if(ev.type == ALLEGRO_EVENT_KEY_UP) {
            if (key[KEY_ESCAPE] && ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
                doexit = true;
            
            lev.handleKeyboardEvent(ev);
            updateKeyboardKeyState(ev.keyboard.keycode, false);
        }
        
        if(redraw && al_is_event_queue_empty(event_queue)) {
            redraw = false;
            al_set_target_bitmap(al_get_backbuffer(display));
            al_clear_to_color(al_map_rgb(0,0,0));
            lev.draw();
            //al_draw_bitmap(bouncer, bouncer_x, bouncer_y, 0);
            
            al_flip_display();
        }
    }
   
    
    
    al_destroy_timer(timer);
    al_destroy_display(display);
    al_destroy_event_queue(event_queue);
    
    return 0;
}