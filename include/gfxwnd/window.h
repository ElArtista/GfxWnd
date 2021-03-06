/*********************************************************************************************************************/
/*                                                  /===-_---~~~~~~~~~------____                                     */
/*                                                 |===-~___                _,-'                                     */
/*                  -==\\                         `//~\\   ~~~~`---.___.-~~                                          */
/*              ______-==|                         | |  \\           _-~`                                            */
/*        __--~~~  ,-/-==\\                        | |   `\        ,'                                                */
/*     _-~       /'    |  \\                      / /      \      /                                                  */
/*   .'        /       |   \\                   /' /        \   /'                                                   */
/*  /  ____  /         |    \`\.__/-~~ ~ \ _ _/'  /          \/'                                                     */
/* /-'~    ~~~~~---__  |     ~-/~         ( )   /'        _--~`                                                      */
/*                   \_|      /        _)   ;  ),   __--~~                                                           */
/*                     '~~--_/      _-~/-  / \   '-~ \                                                               */
/*                    {\__--_/}    / \\_>- )<__\      \                                                              */
/*                    /'   (_/  _-~  | |__>--<__|      |                                                             */
/*                   |0  0 _/) )-~     | |__>--<__|     |                                                            */
/*                   / /~ ,_/       / /__>---<__/      |                                                             */
/*                  o o _//        /-~_>---<__-~      /                                                              */
/*                  (^(~          /~_>---<__-      _-~                                                               */
/*                 ,/|           /__>--<__/     _-~                                                                  */
/*              ,//('(          |__>--<__|     /                  .----_                                             */
/*             ( ( '))          |__>--<__|    |                 /' _---_~\                                           */
/*          `-)) )) (           |__>--<__|    |               /'  /     ~\`\                                         */
/*         ,/,'//( (             \__>--<__\    \            /'  //        ||                                         */
/*       ,( ( ((, ))              ~-__>--<_~-_  ~--____---~' _/'/        /'                                          */
/*     `~/  )` ) ,/|                 ~-_~>--<_/-__       __-~ _/                                                     */
/*   ._-~//( )/ )) `                    ~~-'_/_/ /~~~~~~~__--~                                                       */
/*    ;'( ')/ ,)(                              ~~~~~~~~~~                                                            */
/*   ' ') '( (/                                                                                                      */
/*     '   '  `                                                                                                      */
/*********************************************************************************************************************/
#ifndef _WINDOW_H_
#define _WINDOW_H_

#include "input.h"
#include "context.h"

/* Window datatype */
struct window;

/* Event callback function types */
typedef void(*mouse_button_fn)(struct window*, int, int, int);
typedef void(*cursor_pos_fn)(struct window*, double, double);
typedef void(*cursor_enter_fn)(struct window*, int);
typedef void(*scroll_fn)(struct window*, double, double);
typedef void(*key_fn)(struct window*, int, int, int, int);
typedef void(*char_fn)(struct window*, unsigned int);
typedef void(*char_mods_fn)(struct window*, unsigned int, int);
typedef void(*fb_size_fn)(struct window*, unsigned int, unsigned int);

/* Set of event callbacks */
struct window_callbacks
{
    mouse_button_fn mouse_button_cb;
    cursor_pos_fn cursor_pos_cb;
    cursor_enter_fn cursor_enter_cb;
    scroll_fn scroll_cb;
    key_fn key_cb;
    char_fn char_cb;
    char_mods_fn char_mods_cb;
    fb_size_fn fb_size_cb;
};

/* Creates new window */
struct window* window_create(const char* title, int width, int height, int mode, struct context_params ctx_params);

/* Closes given window */
void window_destroy(struct window*);

/* Registers given callback functions */
void window_set_callbacks(struct window*, struct window_callbacks*);

/* Polls for stored events, calls the registered callbacks and updates cached state */
void window_update(struct window*);

/* Indicates the status of VSync */
int window_vsync_enabled(struct window* wnd);

/* Enables or disables VSync */
void window_vsync_toggle(struct window* wnd, int state);

/* Swaps backbuffer with front buffer */
void window_swap_buffers(struct window* wnd);

/* Sets userdata pointer to be assosiated with given window */
void window_set_userdata(struct window* wnd, void* userdata);

/* Retrieves userdata pointer assisiated with given window */
void* window_get_userdata(struct window* wnd);

/* Returns the current state of the given key */
enum key_action window_key_state(struct window* wnd, enum key k);

/* Returns the current state of the given mouse button */
enum key_action window_mouse_button_state(struct window* wnd, enum mouse_button mb);

/* Returns cursor movement difference between last two frames */
void window_get_cursor_diff(struct window* wnd, float* x, float* y);

/* Sets cursor grub (1: grub, 0: release) */
void window_grub_cursor(struct window* wnd, int mode);

/* Returns 1 when the cursor is being grubbed */
int window_is_cursor_grubbed(struct window* wnd);

/* Sets the window title */
void window_set_title(struct window* wnd, const char* title);

/* Retrieves the current window title */
const char* window_get_title(struct window* wnd);

/* Sets a window title suffix (used for live info) */
void window_set_title_suffix(struct window* wnd, const char* suffix);

#endif /* ! _WINDOW_H_ */
