/// week11-1_TRT_again
/// �K�W week10-1_glutWireCube_myBody_myArm ���{��
#include <GL/glut.h>
void myBody() { ///�ڪ�����
	glPushMatrix(); ///�ƥ��x�}
        glColor3f(1, 0, 0);///���⪺
        glutWireCube(0.6);///myBody();
	glPopMatrix(); ///�٭�x�}
}
void myArm() { ///�ڪ����u
	glPushMatrix();
        glColor3f(0, 1, 0); ///��⪺
        glScalef(1, 0.4, 0.4);///myArm();
        glutWireCube(0.3);
	glPopMatrix();
}
float angle=0;
void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    myBody(); ///�ڪ�����
    glPushMatrix();
        glTranslatef(+0.3, 0.3, 0); ///(3)���b�ӤW
        glRotatef(angle++, 0, 0, 1);///(2)����
        glTranslatef(0.15, 0, 0); ///(1) ����त��,��쥿����
        myArm(); ///�ڪ����u
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-0.3, 0.3, 0);///(3)���b�ӤW
        glRotatef(angle++, 0, 0, 1);///(2)����
        glTranslatef(0.15, 0, 0); ///(1) ����त��,��쥿����
        myArm(); ///�ڪ����u
    glPopMatrix();

    glutSwapBuffers();
}
int main(int argc, char*argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("week11-1");
	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutMainLoop();
}
