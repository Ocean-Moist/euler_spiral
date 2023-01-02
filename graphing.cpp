#include <GL/glut.h>
#include <cmath>
#include <iostream>
using namespace std;


const int NUM_LINES = 4000;   
const float LINE_LENGTH = .015;  
const float LINE_ROTATION = .1;  
const float PI = 3.14;

void drawSpiral() {
  float angle = 0;  
  float x = 0;
  float y = 0;
  for (int i = 0; i < NUM_LINES; i++) {
    angle -= LINE_ROTATION;
    float nx = x + LINE_LENGTH*cos(angle*i * PI / 180);
    float ny = y + LINE_LENGTH*sin(angle*i * PI / 180);
    glBegin(GL_LINES);
    glVertex2f(x, y);
    glVertex2f(nx, ny);
    glEnd();
    x = nx;
    y = ny;
  }
}

void display() {
  glClear(GL_COLOR_BUFFER_BIT);
  drawSpiral();
  glFlush();
}

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
  glutInitWindowSize(1000, 1000);
  glutCreateWindow("Spiral");
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}