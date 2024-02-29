#include <GL/glut.h> ///18,使用GLUT外掛

void display()
{
    glBegin(GL_POLYGON);///開始畫多邊形
        glVertex2f((34-200)/200.0,-(76-200)/200.0);
        glVertex2f((48-200)/200.0,-(131-200)/200.0);
        glVertex2f((85-200)/200.0,-(59-200)/200.0);
    glEnd();
    glBegin(GL_POLYGON);///開始畫多邊形
        glVertex2f((383-200)/200.0,-(79-200)/200.0);
        glVertex2f((348-200)/200.0,-(146-200)/200.0);
        glVertex2f((312-200)/200.0,-(55-200)/200.0);
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
