#include <stdio.h>
#include <math.h>

// defines a structure for a point
struct Point {
    float x;
    float y;
};

// defines a structure for a line
struct Line {
    struct Point point1;   // First point of the line
    struct Point point2;   // Second point of the line
    float slope;           // Slope of the line
    float midpoint[2];     // Midpoint coordinates of the line
    float distance;        // Distance between the two points
};

// function to calculate the slope of a line
void calculate_slope(struct Line* line) {
    line->slope = (line->point2.y - line->point1.y) / (line->point2.x - line->point1.x);
}

// function to calculate the midpoint of a line
void calculate_midpoint(struct Line* line) {
    line->midpoint[0] = (line->point1.x + line->point2.x) / 2;
    line->midpoint[1] = (line->point1.y + line->point2.y) / 2;
}

// function to calculate the distance between two points
void calculate_distance(struct Line* line) {
    line->distance = sqrt(pow((line->point1.x - line->point2.x), 2) + pow((line->point1.y - line->point2.y), 2));
}

// function to get the slope-intercept form of a line
void get_slope_intercept_form(struct Line line) {
    float b = line.point1.y - (line.slope * line.point1.x);
    printf("y = %.6fx + (%.6f)\n", line.slope, b);
}

int main() {
    struct Line line;

    // gets input for point1
    printf("Enter x and y for point1: ");
    scanf("%f %f", &line.point1.x, &line.point1.y);

    // gets input for point2
    printf("Enter x and y for point2: ");
    scanf("%f %f", &line.point2.x, &line.point2.y);

    // calculates the slope, midpoint, and distance of the line
    calculate_slope(&line);
    calculate_midpoint(&line);
    calculate_distance(&line);

    // prints the calculated values
    printf("\nSlope: %.6f\n", line.slope);
    printf("Midpoint: %.6f %.6f\n", line.midpoint[0], line.midpoint[1]);
    printf("Distance between two points: %.6f\n", line.distance);

    // prints the slope-intercept form of the line
    get_slope_intercept_form(line);

    return 0;
}
