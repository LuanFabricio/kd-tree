#include "kdtree.h"
#include "defs.h"
#include "mm.h"
#include "platform.h"
#include "types.h"
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

int main()
{
	KDTree *kd_root = KDTree_new((Point) { (float)CENTER_X, (float)CENTER_Y });

	u32 points = 32;

	for (u32 i = 0; i < points; i++) {
		u32 x = Platform_rand_range(0, SCREEN_WIDTH);
		u32 y = Platform_rand_range(0, SCREEN_HEIGHT);
		KDTree_insert(kd_root, (Point) { x, y}, 0);
	}

	kd_print(kd_root, 0);

	mm_log();

	Platform_init_window(SCREEN_WIDTH, SCREEN_HEIGHT, "KD-Tree");

	while(!Platform_window_should_close()) {
		Platform_begin_draw();
			Platform_clear_background(BACKGROUND_COLOR);
			KDTree_display(kd_root);
		Platform_end_draw();
	}

	Platform_close_Window();

	return 0;
}
