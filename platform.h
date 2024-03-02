#ifndef PLATFORM_H_
#define PLATFORM_H_

#include "types.h"

extern void Platform_init_window(u32 w, u32 h, const char* title);
extern void Platform_close_Window();
extern boolean Platform_window_should_close();

extern void Platform_begin_draw();
extern void Platform_end_draw();

extern void Platform_clear_background(u32 color);
extern void Platform_draw_point(float x, float y, float radius, u32 color);

extern float Platform_rand_range(float min, float max);

extern void Platform_log_mem(float mem_usage);

extern void Platform_set_loop(void* loop_fn);

#endif // PLATFORM_H_
