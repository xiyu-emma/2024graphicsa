#include <GL/glut.h> ///18,使用GLUT外掛
#include <stdio.h>
float teapotX = 0, teapotY = 0;
float angle = 0;
void mouse(int button, int state, int x, int y){
    teapotX = (x-150)/150.0;
    teapotY = -(y-150)/150.0;
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        //glTranslatef(teapotX, teapotY, 0);
        glRotatef(angle, 0, 0, 1);
        glutSolidTeapot( 0.3 );
    glPopMatrix();
    glutSwapBuffers();
}

void motion(int x, int y)
{
    angle = x;
    display();
}

int main(int argc, char *argv[]) ///138,main函式
{
    glutInit(&argc, argv); ///140,開啟GLUT功能
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); ///148,設定顯示模式
    glutCreateWindow("week03 mouse"); ///145,開一個GLUT視窗
    glutDisplayFunc(display); ///148,用dusplay()函式畫圖
    glutMouseFunc(mouse);
    glutMotionFunc(motion);

    glutMainLoop();///174,主要迴圈
}
