#include <GL/glut.h> ///18,使用GLUT外掛
#include <stdio.h>
void mouse(int button, int state, int x, int y){
    //printf("Hello Mouse!\n");
    //printf("%d %d %d %d\n", button, state, x, y);
    if(state==GLUT_DOWN) printf("glVertex2f((%d-150)/150.0, -(%d-150)/150.0);\n", x, y);
}

void display()
{
    glutSolidTeapot(0.3);
    glutSwapBuffers();
}

int main(int argc, char *argv[]) ///138,main函式
{
    glutInit(&argc, argv); ///140,開啟GLUT功能
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); ///148,設定顯示模式
    glutCreateWindow("week03 mouse"); ///145,開一個GLUT視窗

    glutDisplayFunc(display); ///148,用dusplay()函式畫圖
    glutMouseFunc(mouse);

    glutMainLoop();///174,主要迴圈
}
