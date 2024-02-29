#include <GL/glut.h> ///18,使用GLUT外掛
#include <math.h>
void myCircle(float x, float y, float r)
{
    glBegin(GL_POLYGON);///開始畫多邊形
        for(float a=0; a<3.1415*2; a+=0.1){
            glVertex2f(r*cos(a)+x, r*sin(a)+y);
        }
    glEnd();
}
void display()
{
    myCircle(0.5, 0.5, 0.3);
    myCircle(-0.5, 0.5, 0.3);
    myCircle(0, -0.1, 0.6);
    glutSwapBuffers();
}

int main(int argc, char *argv[]) ///138,main函式
{
    glutInit(&argc, argv); ///140,開啟GLUT功能
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); ///148,設定顯示模式
    glutCreateWindow("GLUT Shapes"); ///145,開一個GLUT視窗
    glutDisplayFunc(display); ///148,用dusplay()函式畫圖

    glutMainLoop();///174,主要迴圈
}
