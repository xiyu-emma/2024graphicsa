#include <GL/glut.h> ///18,�ϥ�GLUT�~��

void display()
{
    glColor3f(247/255.0,180/255.0,171/255.0);
    glutSolidTeapot(0.3);
    glColor3f(251/255.0,232/255.0,219/255.0);
    glutSolidTeapot(0.2);
    glutSwapBuffers();
}

int main(int argc, char *argv[]) ///138,main�禡
{
    glutInit(&argc, argv); ///140,�}��GLUT�\��
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); ///148,�]�w��ܼҦ�
    glutCreateWindow("GLUT Shapes"); ///145,�}�@��GLUT����
    glutDisplayFunc(display); ///148,��dusplay()�禡�e��

    glutMainLoop();///174,�D�n�j��
}
