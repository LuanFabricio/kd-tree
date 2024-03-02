#include "kdtree.h"
#include "defs.h"
#include "mm.h"
#include "platform.h"
#include "types.h"

#ifndef PLATFORM_WEB
#include <stdio.h>

void kd_print(const KDTree *kd_root, u32 depth)
{
	if (kd_root == NULL) {
		return;
	}

	printf("Depth: %u | { %.2f, %.2f }\n", depth, kd_root->point.x, kd_root->point.y);

	kd_print(kd_root->left, depth+1);
	kd_print(kd_root->right, depth+1);
}
#endif

static KDTree *kd_root = NULL;

void main_loop()
{
	Platform_begin_draw();
		Platform_clear_background(BACKGROUND_COLOR);
		KDTree_display(kd_root);
	Platform_end_draw();
}

int main()
{
	kd_root = KDTree_new((Point) { (float)CENTER_X, (float)CENTER_Y });

	u32 points = 60;

	for (u32 i = 0; i < points; i++) {
		u32 x = Platform_rand_range(0, SCREEN_WIDTH);
		u32 y = Platform_rand_range(0, SCREEN_HEIGHT);
		KDTree_insert(kd_root, (Point) { x, y}, 0);
	}

#ifndef PLATFORM_WEB
	kd_print(kd_root, 0);
#endif

	mm_log();

	Platform_init_window(SCREEN_WIDTH, SCREEN_HEIGHT, "KD-Tree");

#ifndef PLATFORM_WEB
	while(!Platform_window_should_close()) {
		main_loop();
	}
	Platform_close_Window();
#else
	Platform_set_loop(main_loop);
#endif

	return 0;
}
