#include <GL/glut.h> ///18,使用GLUT外掛

void display()
{
    glBegin(GL_POLYGON);///開始畫多邊形
        glColor3f(1,0,0); glVertex2f(0,1);
        glColor3f(0,1,0); glVertex2f(+1,-0.6);
        glColor3f(0,0,1); glVertex2f(-1,-0.6);
    glEnd();
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
