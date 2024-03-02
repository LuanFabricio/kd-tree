#ifndef TYPES_H_
#define TYPES_H_

typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned long long u64;

typedef char boolean;
#define true 1
#define false 0

typedef struct {
	float x, y;
} Point;

#define ARRAY_CAPACITY 1024

typedef struct DynamicArray {
	Point *values;
	u32 size;
} DynamicArray;

typedef struct KDTree {
	Point point;
	struct KDTree *left;
	struct KDTree *right;
} KDTree;

#endif // TYPES_H_
