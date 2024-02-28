#include <stdio.h>
#include <stdlib.h>

struct point {
    int x, y;
};

int orientation(struct point p, struct point q, struct point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;  // Collinear
    return (val > 0) ? 1 : 2; // Clockwise or Counterclockwise
}

void convexhull(struct point points[], int n) {
    if (n < 3) return; // Convex hull not possible

    int hull[n];
    int hullsize = 0;
    int leftmost = 0;
    for (int i = 1; i < n; i++) {
        if (points[i].x < points[leftmost].x)
            leftmost = i;
    }

    int p = leftmost, q;
    do {
        hull[hullsize++] = p;

        q = (p + 1) % n;
        for (int i = 0; i < n; i++) {
            if (orientation(points[p], points[i], points[q]) == 2) {
                q = i;
            }
        }
        p = q;
    } while (p != leftmost);

    for (int i = 0; i < hullsize; i++) {
        printf("(%d, %d)\n", points[hull[i]].x, points[hull[i]].y);
    }
}

int main() {
    int n;
    printf("Enter the number of points: ");
    scanf("%d", &n);

    struct point *points = (struct point *)malloc(n * sizeof(struct point));
    if (points == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter the points:\n");
    for (int i = 0; i < n; i++) {
        printf("Point %d (x y): ", i+1);
        scanf("%d %d", &points[i].x, &points[i].y);
    }
    printf("Points of convex polygon\n ");
    convexhull(points, n);

    free(points);
    return 0;
}


/*
Enter the number of points: 7
Enter the points:
Point 1 (x y): 0 3
Point 2 (x y): 2 2
Point 3 (x y): 1 1
Point 4 (x y): 2 1
Point 5 (x y): 3 0
Point 6 (x y): 0 0
Point 7 (x y): 3 3
Points of convex polygon
(0, 3)
(0, 0)
(3, 0)
(3, 3)
*/
