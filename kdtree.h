#ifndef KDTREE_H_
#define KDTREE_H_

#include "mm.h"
#include "platform.h"
#include "types.h"
#include "defs.h"

#define K 2

static KDTree* KDTree_new(Point p)
{
	KDTree *kd_tree = (KDTree*)mm_malloc(sizeof(KDTree));

	kd_tree->point.x = p.x;
	kd_tree->point.y = p.y;
	kd_tree->left = NULL;
	kd_tree->right = NULL;

	return kd_tree;
}

static boolean KDTree_compare_by_axis(Point p1, Point p2, u32 axis)
{
	switch (axis) {
		case 0:
			return p1.x < p2.y;
		case 1:
			return p1.y < p2.y;
	}

	// Crash
	((void (*)(void))0)();
	return  false;
}

static void KDTree_insert(KDTree *kd, Point p, u32 depth) {
	boolean gx = kd->point.x >= p.x;
	boolean gy = kd->point.y >= p.y;

	u32 axis = depth % K;
	if (KDTree_compare_by_axis(kd->point, p, axis)) {
		if(kd->right) {
			KDTree_insert(kd->right, p, depth+1);
		} else {
			kd->right = KDTree_new(p);
		}
	} else {
		if(kd->left) {
			KDTree_insert(kd->left, p, depth+1);
		} else {
			kd->left = KDTree_new(p);
		}
	}
}

#define POINT_SIZE 1
#define POINT_COLOR 0xff0000ff

static void KDTree_display(const KDTree *kd)
{
	if (kd == NULL) return;
	Platform_draw_point(kd->point.x, kd->point.y, POINT_SIZE, POINT_COLOR);

	KDTree_display(kd->left);
	KDTree_display(kd->right);
}

#endif // KDTREE_H_
