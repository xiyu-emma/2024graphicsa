#include <GL/glut.h> ///18,�ϥ�GLUT�~��

void display()
{
    glBegin(GL_POLYGON);///�}�l�e�h���
        glColor3f(1,0,0); glVertex2f(0,1);
        glColor3f(0,1,0); glVertex2f(+1,-0.6);
        glColor3f(0,0,1); glVertex2f(-1,-0.6);
    glEnd();
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
