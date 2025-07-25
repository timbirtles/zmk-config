#include <zmk/display.h>
#include <lvgl.h>
#include "display/animation_widget.h"

void zmk_display_app_init(lv_obj_t *parent) {
    animation_widget_init(parent);
}
