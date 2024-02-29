#include <GL/glut.h> ///18,使用GLUT外掛

void display()
{
    glColor3f(247/255.0,180/255.0,171/255.0);
    glutSolidTeapot(0.3);
    glColor3f(251/255.0,232/255.0,219/255.0);
    glutSolidTeapot(0.2);
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
