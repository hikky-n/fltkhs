#ifndef __FL_BUTTON_C__
#define __FL_BUTTON_C__
// always include the FL/*.H headers before local headers
// Fl_Widget is included transitively and needed for
// the callback mechanism included below to work.
#include "FL/Fl.H"
#include "FL/Fl_Light_Button.H"
#include "Fl_CallbackC.h"
#ifdef __cplusplus
EXPORT {
#endif
  /* Inherited from Fl_Widget */
  FL_EXPORT_C(fl_Group,     Fl_Button_parent)(fl_Button win);
  FL_EXPORT_C(void,         Fl_Button_set_parent)(fl_Button win, fl_Group grp);
  FL_EXPORT_C(uchar,        Fl_Button_type)(fl_Button win);
  FL_EXPORT_C(void,         Fl_Button_set_type)(fl_Button win, uchar t);
  FL_EXPORT_C(int,          Fl_Button_x)(fl_Button win);
  FL_EXPORT_C(int,          Fl_Button_y)(fl_Button win);
  FL_EXPORT_C(int,          Fl_Button_w)(fl_Button win);
  FL_EXPORT_C(int,          Fl_Button_h)(fl_Button win);
  FL_EXPORT_C(Fl_Align,     Fl_Button_align)(fl_Button win);
  FL_EXPORT_C(Fl_Boxtype,   Fl_Button_box)(fl_Button win);
  FL_EXPORT_C(void,         Fl_Button_set_box)(fl_Button win, Fl_Boxtype new_box);
  FL_EXPORT_C(Fl_Color,     Fl_Button_color)(fl_Button win);
  FL_EXPORT_C(void,         Fl_Button_set_color)(fl_Button win, Fl_Color bg);
  FL_EXPORT_C(void,         Fl_Button_set_background_and_selection_color)(fl_Button win,Fl_Color bg, Fl_Color a);
  FL_EXPORT_C(Fl_Color,     Fl_Button_selection_color)(fl_Button win);
  FL_EXPORT_C(void,         Fl_Button_set_selection_color)(fl_Button win, Fl_Color a);
  FL_EXPORT_C(const char*,  Fl_Button_label)(fl_Button win);
  FL_EXPORT_C(void,         Fl_Button_copy_label)(fl_Button win, const char* new_label);
  FL_EXPORT_C(void,         Fl_Button_set_label)(fl_Button win, const char* text);
  FL_EXPORT_C(Fl_Labeltype, Fl_Button_labeltype)(fl_Button win);
  FL_EXPORT_C(void,         Fl_Button_set_labeltype)(fl_Button win, Fl_Labeltype a);
  FL_EXPORT_C(Fl_Color,     Fl_Button_labelcolor)(fl_Button win);
  FL_EXPORT_C(void,         Fl_Button_set_labelcolor)(fl_Button win, Fl_Color c);
  FL_EXPORT_C(Fl_Font,      Fl_Button_labelfont)(fl_Button win);
  FL_EXPORT_C(void,         Fl_Button_set_labelfont)(fl_Button win, Fl_Font c);
  FL_EXPORT_C(Fl_Fontsize,  Fl_Button_labelsize)(fl_Button win);
  FL_EXPORT_C(void,         Fl_Button_set_labelsize)(fl_Button win, Fl_Fontsize pix);
  FL_EXPORT_C(fl_Image,     Fl_Button_image)(fl_Button win);
  FL_EXPORT_C(void,         Fl_Button_set_image)(fl_Button win, fl_Image pix);
  FL_EXPORT_C(fl_Image,     Fl_Button_deimage)(fl_Button win);
  FL_EXPORT_C(void,         Fl_Button_set_deimage)(fl_Button win, fl_Image pix);
  FL_EXPORT_C(const char*,  Fl_Button_tooltip)(fl_Button win);
  FL_EXPORT_C(void,         Fl_Button_copy_tooltip)(fl_Button win, const char* text);
  FL_EXPORT_C(void,         Fl_Button_set_tooltip)(fl_Button win, const char* text);
  FL_EXPORT_C(void,         Fl_Button_set_callback_and_user_data)(fl_Button win, fl_Callback* cb, void* p);
  FL_EXPORT_C(void,         Fl_Button_set_callback)(fl_Button win, fl_Callback* cb);
  FL_EXPORT_C(void*,        Fl_Button_user_data)(fl_Button win);
  FL_EXPORT_C(void,         Fl_Button_set_user_data)(fl_Button win, void* v);
  FL_EXPORT_C(long,         Fl_Button_argument)(fl_Button win);
  FL_EXPORT_C(void,         Fl_Button_set_argument)(fl_Button win, long v);
  FL_EXPORT_C(Fl_When,      Fl_Button_when)(fl_Button win);
  FL_EXPORT_C(void,         Fl_Button_set_when)(fl_Button win, uchar i);
  FL_EXPORT_C(unsigned int, Fl_Button_visible)(fl_Button win);
  FL_EXPORT_C(int,          Fl_Button_visible_r)(fl_Button win);
  FL_EXPORT_C(void,         Fl_Button_set_visible)(fl_Button win);
  FL_EXPORT_C(void,         Fl_Button_clear_visible)(fl_Button win);
  FL_EXPORT_C(unsigned int, Fl_Button_active)(fl_Button win);
  FL_EXPORT_C(int,          Fl_Button_active_r)(fl_Button win);
  FL_EXPORT_C(void,         Fl_Button_activate)(fl_Button win);
  FL_EXPORT_C(void,         Fl_Button_deactivate)(fl_Button win);
  FL_EXPORT_C(unsigned int, Fl_Button_output)(fl_Button win);
  FL_EXPORT_C(void,         Fl_Button_set_output)(fl_Button win);
  FL_EXPORT_C(void,         Fl_Button_clear_output)(fl_Button win);
  FL_EXPORT_C(unsigned int, Fl_Button_takesevents)(fl_Button win);
  FL_EXPORT_C(void,         Fl_Button_set_changed)(fl_Button win);
  FL_EXPORT_C(void,         Fl_Button_clear_changed)(fl_Button win);
  FL_EXPORT_C(int,          Fl_Button_take_focus)(fl_Button win);
  FL_EXPORT_C(void,         Fl_Button_set_visible_focus)(fl_Button win);
  FL_EXPORT_C(void,         Fl_Button_clear_visible_focus)(fl_Button win);
  FL_EXPORT_C(void,         Fl_Button_modify_visible_focus)(fl_Button win, int v);
  FL_EXPORT_C(unsigned int, Fl_Button_visible_focus)(fl_Button win);
  FL_EXPORT_C(void,         Fl_Button_do_callback)(fl_Button win);
  FL_EXPORT_C(void,         Fl_Button_do_callback_with_widget_and_user_data)(fl_Button win, fl_Widget w, long arg);
  FL_EXPORT_C(void,         Fl_Button_do_callback_with_widget_and_default_user_data)(fl_Button win, fl_Widget w);
  FL_EXPORT_C(int,          Fl_Button_contains)(fl_Button win, fl_Widget w);
  FL_EXPORT_C(int,          Fl_Button_inside)(fl_Button win, fl_Widget w);
  FL_EXPORT_C(void,         Fl_Button_redraw)(fl_Button win);
  FL_EXPORT_C(void,         Fl_Button_redraw_label)(fl_Button win);
  FL_EXPORT_C(uchar,        Fl_Button_damage)(fl_Button win);
  FL_EXPORT_C(void,         Fl_Button_clear_damage_with_bitmask)(fl_Button win, uchar c);
  FL_EXPORT_C(void,         Fl_Button_clear_damage)(fl_Button win);
  FL_EXPORT_C(void,         Fl_Button_damage_with_text)(fl_Button win, uchar c);
  FL_EXPORT_C(void,         Fl_Button_damage_inside_widget)(fl_Button win, uchar c, int x , int y , int w, int h);
  FL_EXPORT_C(void,         Fl_Button_draw_label)(fl_Button win, int x , int y , int w, int h, Fl_Align alignment);
  FL_EXPORT_C(void,         Fl_Button_measure_label)(fl_Button win, int& ww , int& hh);

  /* Fl_Button specific functions */
  FL_EXPORT_C(fl_Button,    Fl_Button_New_WithLabel)(int x, int y, int w, int h, const char* label);
  FL_EXPORT_C(fl_Button,    Fl_Button_New)(int x, int y, int w, int h);
  FL_EXPORT_C(int         , Fl_Button_value)(fl_Button b, int v);
  FL_EXPORT_C(int         , Fl_Button_set)(fl_Button b);
  FL_EXPORT_C(int         , Fl_Button_clear)(fl_Button b);
  FL_EXPORT_C(void        , Fl_Button_setonly)(fl_Button b);
  FL_EXPORT_C(int         , Fl_Button_get_shortcut )(fl_Button b);
  FL_EXPORT_C(void        , Fl_Button_set_shortcut )(fl_Button b, int s);
  FL_EXPORT_C(Fl_Boxtype  , Fl_Button_get_down_box)(fl_Button b);
  FL_EXPORT_C(void        , Fl_Button_set_down_box)(fl_Button b,Fl_Boxtype boxtype);
  FL_EXPORT_C(Fl_Color    , Fl_Button_get_down_color )(fl_Button b);
  FL_EXPORT_C(void        , Fl_Button_set_down_color)(fl_Button b, Fl_Color c);
#ifdef __cplusplus
}
#endif
#endif /*#ifndef __FL_BUTTON_C__*/