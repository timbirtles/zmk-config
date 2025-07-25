#include <lvgl.h>

extern const lv_img_dsc_t img1;
extern const lv_img_dsc_t img2;

static const lv_img_dsc_t *frames[] = { &img1, &img2 };
static lv_obj_t *img;
static int frame_idx = 0;

static void update_frame(struct k_work *work) {
    lv_img_set_src(img, frames[frame_idx]);
    frame_idx = (frame_idx + 1) % 2;
}
K_WORK_DEFINE(frame_work, update_frame);

static void timer_cb(struct k_timer *timer) {
    k_work_submit(&frame_work);
}
K_TIMER_DEFINE(animation_timer, timer_cb, NULL);

int animation_widget_init(lv_obj_t *parent) {
    img = lv_img_create(parent);
    lv_img_set_src(img, frames[0]);
    k_timer_start(&animation_timer, K_MSEC(1000), K_MSEC(1000));
    return 0;
}
