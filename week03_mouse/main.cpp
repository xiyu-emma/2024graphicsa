#include <GL/glut.h> ///18,�ϥ�GLUT�~��
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

int main(int argc, char *argv[]) ///138,main�禡
{
    glutInit(&argc, argv); ///140,�}��GLUT�\��
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); ///148,�]�w��ܼҦ�
    glutCreateWindow("week03 mouse"); ///145,�}�@��GLUT����

    glutDisplayFunc(display); ///148,��dusplay()�禡�e��
    glutMouseFunc(mouse);

    glutMainLoop();///174,�D�n�j��
}
