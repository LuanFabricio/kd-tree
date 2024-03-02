#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#define U32_TO_COLOR(c) *(Color*)(&(c))

extern void Platform_init_window(uint32_t w, uint32_t h, const char* title)
{
	InitWindow(w, h, title);
}

extern void Platform_close_Window()
{
	CloseWindow();
}

extern bool Platform_window_should_close()
{
	return WindowShouldClose();
}

extern void Platform_begin_draw()
{
	BeginDrawing();
}

extern void Platform_end_draw()
{
	EndDrawing();
}

extern void Platform_clear_background(uint32_t color)
{
	ClearBackground(U32_TO_COLOR(color));
}

extern void Platform_draw_point(float x, float y, float radius, uint32_t color)
{
	DrawCircle(x, y, radius, U32_TO_COLOR(color));
}

extern float Platform_rand_float()
{
	return (float)rand() / (float)INT_MAX;
}

extern float Platform_rand_range(float min, float max)
{
	return min + Platform_rand_float() * (max - min);
}

extern void Platform_log_mem(float mem_usage)
{
	printf("Mem usage: %02.2f%%\n", mem_usage * 100);
}
