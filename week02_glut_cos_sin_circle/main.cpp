#include <GL/glut.h> ///18,�ϥ�GLUT�~��
#include <math.h>
void myCircle(float x, float y, float r)
{
    glBegin(GL_POLYGON);///�}�l�e�h���
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

int main(int argc, char *argv[]) ///138,main�禡
{
    glutInit(&argc, argv); ///140,�}��GLUT�\��
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); ///148,�]�w��ܼҦ�
    glutCreateWindow("GLUT Shapes"); ///145,�}�@��GLUT����
    glutDisplayFunc(display); ///148,��dusplay()�禡�e��

    glutMainLoop();///174,�D�n�j��
}
