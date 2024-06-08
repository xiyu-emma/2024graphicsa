#include <opencv/highgui.h> ///�ϥ� OpenCV 2.1 ���²��, �u�n�� High GUI �Y�i
#include <opencv/cv.h>
#include <GL/glut.h>
int id1, id2;
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCVŪ��
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV���m (�ݭncv.h)
    cvFlip(img, NULL, 0);///����½��
    glEnable(GL_TEXTURE_2D); ///1. �}�ҶK�ϥ\��
    GLuint id; ///�ǳƤ@�� unsigned int ���, �s �K��ID
    glGenTextures(1, &id); /// ����Generate �K��ID
    glBindTexture(GL_TEXTURE_2D, id); ///�j�wbind �K��ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// �K�ϰѼ�, �W�L�]�˪��d��T, �N���жK��
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// �K�ϰѼ�, �W�L�]�˪��d��S, �N���жK��
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// �K�ϰѼ�, ��j�ɪ�����, �γ̪��I
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// �K�ϰѼ�, �Y�p�ɪ�����, �γ̪��I
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}
#include <GL/glut.h>
#include "glm.h"
GLMmodel * handA = NULL;
GLMmodel * handB = NULL;
GLMmodel * body = NULL;
GLMmodel * eyeA = NULL;
GLMmodel * eyeB = NULL;
GLMmodel * neckA = NULL;
GLMmodel * neckB = NULL;
GLMmodel * wristA = NULL;
GLMmodel * wristB = NULL;
GLMmodel * thumbA = NULL;
GLMmodel * thumbB = NULL;
GLMmodel * fingerA = NULL;
GLMmodel * fingerB = NULL;



void drawBody(void)
{
    if (!body) {
	body = glmReadOBJ("data/body.obj");
	if (!body) exit(0);
	glmScale(body, 1.0/350);
	glmFacetNormals(body);
	glmVertexNormals(body, 90.0);
    }

    glmDraw(body, GLM_SMOOTH | GLM_TEXTURE);

}
void drawNeckA(void)
{
    if (!neckA) {
	neckA = glmReadOBJ("data/neckA.obj");
	if (!neckA) exit(0);
	glmScale(neckA, 1.0/350);
	glmFacetNormals(neckA);
	glmVertexNormals(neckA, 90.0);
    }

    glmDraw(neckA, GLM_SMOOTH | GLM_TEXTURE);

}
void drawNeckB(void)
{
    if (!neckB) {
	neckB = glmReadOBJ("data/neckB.obj");
	if (!neckB) exit(0);
	glmScale(neckB, 1.0/350);
	glmFacetNormals(neckB);
	glmVertexNormals(neckB, 90.0);
    }

    glmDraw(neckB, GLM_SMOOTH | GLM_TEXTURE);

}
void drawHandA(void)
{
    if (!handA) {
	handA = glmReadOBJ("data/handA.obj");
	if (!handA) exit(0);
	glmScale(handA, 1.0/350);
	glmFacetNormals(handA);
	glmVertexNormals(handA, 90.0);
    }

    glmDraw(handA, GLM_SMOOTH | GLM_TEXTURE);
}
void drawHandB(void)
{
    if (!handB) {
	handB = glmReadOBJ("data/handB.obj");
	if (!handB) exit(0);
	glmScale(handB, 1.0/350);
	glmFacetNormals(handB);
	glmVertexNormals(handB, 90.0);
    }

    glmDraw(handB, GLM_SMOOTH | GLM_TEXTURE);
}
void drawEyeA(void)
{
    if (!eyeA) {
	eyeA = glmReadOBJ("data/eyeA.obj");
	if (!eyeA) exit(0);
	glmScale(eyeA, 1.0/350);
	glmFacetNormals(eyeA);
	glmVertexNormals(eyeA, 90.0);
    }

    glmDraw(eyeA, GLM_SMOOTH | GLM_TEXTURE);
}
void drawEyeB(void)
{
    if (!eyeB) {
	eyeB = glmReadOBJ("data/eyeB.obj");
	if (!eyeB) exit(0);
	glmScale(eyeB, 1.0/350);
	glmFacetNormals(eyeB);
	glmVertexNormals(eyeB, 90.0);
    }

    glmDraw(eyeB, GLM_SMOOTH | GLM_TEXTURE);
}
void drawWristA(void)
{
    if (!wristA) {
	wristA = glmReadOBJ("data/wristA.obj");
	if (!wristA) exit(0);
	glmScale(wristA, 1.0/350);
	glmFacetNormals(wristA);
	glmVertexNormals(wristA, 90.0);
    }

    glmDraw(wristA, GLM_SMOOTH | GLM_TEXTURE);
}
void drawWristB(void)
{
    if (!wristB) {
	wristB = glmReadOBJ("data/wristB.obj");
	if (!wristB) exit(0);
	glmScale(wristB, 1.0/350);
	glmFacetNormals(wristB);
	glmVertexNormals(wristB, 90.0);
    }

    glmDraw(wristB, GLM_SMOOTH | GLM_TEXTURE);
}
void drawThumbA(void)
{
    if (!thumbA) {
	thumbA = glmReadOBJ("data/thumbA.obj");
	if (!thumbA) exit(0);
	glmScale(thumbA, 1.0/350);
	glmFacetNormals(thumbA);
	glmVertexNormals(thumbA, 90.0);
    }

    glmDraw(thumbA, GLM_SMOOTH | GLM_TEXTURE);
}
void drawThumbB(void)
{
    if (!thumbB) {
	thumbB = glmReadOBJ("data/thumbB.obj");
	if (!thumbB) exit(0);
	glmScale(thumbB, 1.0/350);
	glmFacetNormals(thumbB);
	glmVertexNormals(thumbB, 90.0);
    }

    glmDraw(thumbB, GLM_SMOOTH | GLM_TEXTURE);
}
void drawFingerA(void)
{
    if (!fingerA) {
	fingerA = glmReadOBJ("data/fingerA.obj");
	if (!fingerA) exit(0);
	glmScale(fingerA, 1.0/350);
	glmFacetNormals(fingerA);
	glmVertexNormals(fingerA, 90.0);
    }

    glmDraw(fingerA, GLM_SMOOTH | GLM_TEXTURE);
}
void drawFingerB(void)
{
    if (!fingerB) {
	fingerB = glmReadOBJ("data/fingerB.obj");
	if (!fingerB) exit(0);
	glmScale(fingerB, 1.0/350);
	glmFacetNormals(fingerB);
	glmVertexNormals(fingerB, 90.0);
    }

    glmDraw(fingerB, GLM_SMOOTH | GLM_TEXTURE);
}

float angleX[15] = {}, angleY[15] = {};
int angleID = 0;
int oldX = 0, oldY = 0;
#include <stdio.h>
FILE * fin = NULL;
FILE * fout = NULL;
void motion(int x, int y){ ///�[�Jmouse motion �������禡
    angleX[angleID] += y - oldY; /// angleX �� y
    angleY[angleID] -= x - oldX; /// angleY �� x
    oldX = x;
    oldY = y;
    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{
    oldX = x;
    oldY = y;
}

float oldAngleX[15] = {}, newAngleX[15] = {};
float oldAngleY[15] = {}, newAngleY[15] = {};
void timer(int t) {
    glutTimerFunc(50, timer, t+1);
    if(t%30==0) {
        if(fin==NULL) fin = fopen("angle.txt", "r");
        for(int i=0; i<15; i++){
            oldAngleX[i] = newAngleX[i];
            oldAngleY[i] = newAngleY[i];
            fscanf(fin, "%f", & newAngleX[i] );
            fscanf(fin, "%f", & newAngleY[i] );
        }
    }
    float alpha = (t%30) / 30.0;
    for(int i=0; i<15; i++){
        angleX[i] = newAngleX[i]*alpha + oldAngleX[i]*(1-alpha);
        angleY[i] = newAngleY[i]*alpha + oldAngleY[i]*(1-alpha);
    }
    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {
    if(key=='p') { ///Play����
        glutTimerFunc(0, timer, 0);
    }
	if(key=='r') { ///Ū1��
		if(fin==NULL) fin = fopen("angle.txt", "r");
		for(int i=0; i<15; i++){
			fscanf(fin, "%f", & angleX[i] );
			fscanf(fin, "%f", & angleY[i] );
		}
		glutPostRedisplay();
	} else if(key=='s') {
        if(fout==NULL) fout = fopen("angle.txt", "w+");
        for(int i=0; i<15; i++){
            printf("%.1f ", angleX[i] );
            printf("%.1f ", angleY[i] );
            fprintf(fout, "%.1f ", angleX[i] );
            fprintf(fout, "%.1f ", angleY[i] );
        }
        printf("\n");
        fprintf(fout, "\n");
	}
    if(key=='0') angleID = 0;
    if(key=='1') angleID = 1;
    if(key=='2') angleID = 2;
    if(key=='3') angleID = 3;
    if(key=='4') angleID = 4;
    if(key=='5') angleID = 5;
    if(key=='6') angleID = 6;
    if(key=='7') angleID = 7;
    if(key=='8') angleID = 8;
    if(key=='9') angleID = 9;
    if(key=='/') angleID = 10;
    if(key=='*') angleID = 11;
    if(key=='-') angleID = 12;
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    ///glutSolidSphere(0.02, 30, 30);�����I
    glBindTexture(GL_TEXTURE_2D, id1);
    glPushMatrix();
        glTranslatef(0, -0.4, 0);
        glRotatef(angleX[0], 1, 0, 0);
        glRotatef(angleY[0], 0, 1, 0);
        glTranslatef(0, -0.35, 0);
        ///glutSolidSphere(0.02, 30, 30);���餤���I
        drawBody();
        glPushMatrix();
            glTranslatef(0.35, 0.68, -0.15);
            glRotatef(angleX[1], 1, 0, 0);
            glRotatef(angleY[1], 0, 1, 0);
            glTranslatef(-0.32, -0.91, 0.1);
            ///glutSolidSphere(0.02, 30, 30);handA�����I
            drawHandA();
            glPushMatrix();
                glTranslatef(0.35, 0.93, 0.42);
                glRotatef(angleX[7], 1, 0, 0);
                glRotatef(angleY[7], 0, 0, 1);
                glTranslatef(0.385, -0.94, -0.42);
                ///glutSolidSphere(0.02, 30, 30);wristA�����I
                drawWristA();
                glPushMatrix();
                    glTranslatef(-0.38, 0.88, 0.48);
                    glRotatef(angleX[9], 1, 0, 0);
                    glTranslatef(0.38, -1.07, -0.45);
                    drawThumbA();
                glPopMatrix();
                glPushMatrix();
                    glTranslatef(-0.4, 0.94, 0.51);
                    glRotatef(angleX[11], 1, 0, 0);
                    glTranslatef(0.4, -1.13, -0.45);
                    drawFingerA();
                glPopMatrix();
            glPopMatrix();
        glPopMatrix();
        glPushMatrix();
            glTranslatef(-0.35, 0.68, -0.15);
            glRotatef(angleX[2], 1, 0, 0);
            glRotatef(angleY[2], 0, 1, 0);
            glTranslatef(0.35, -0.93, 0.1);
            ///glutSolidSphere(0.02, 30, 30);handB�����I
            drawHandB();
            glPushMatrix();
                glTranslatef(-0.38, 0.94, 0.42);
                glRotatef(angleX[8], 1, 0, 0);
                glRotatef(angleY[8], 0, 0, 1);
                glTranslatef(0.385, -0.94, -0.42);
                drawWristB();
                ///glutSolidSphere(0.02, 30, 30);wristB�����I
                glPushMatrix();
                    glTranslatef(-0.38, 0.88, 0.48);
                    glRotatef(angleX[10], 1, 0, 0);
                    glTranslatef(0.38, -1.07, -0.45);
                    drawThumbB();
                glPopMatrix();
                glPushMatrix();
                    glTranslatef(-0.4, 0.94, 0.51);
                    glRotatef(angleX[12], 1, 0, 0);
                    glTranslatef(0.4, -1.13, -0.45);
                    drawFingerB();
                glPopMatrix();
            glPopMatrix();
        glPopMatrix();
        glTranslatef(0, 0.82, -0.14);
        glRotatef(angleX[3], 1, 0, 0);
        glRotatef(angleY[3], 0, 1, 0);
        glTranslatef(0, -0.82, 0.14);
        drawNeckA();
        glPushMatrix();
            glTranslatef(0, 0.95, -0.01);
            glRotatef(angleX[4], 1, 0, 0);
            glRotatef(angleY[4], 0, 0, 1);
            glTranslatef(0, -0.95, 0.01);
            drawNeckB();
            glPushMatrix();
                glTranslatef(-0.02, 1.12, 0);
                glRotatef(angleY[5], 0, 0, 1);
                glTranslatef(0, -1.15, 0);
                drawEyeA();
            glPopMatrix();
            glPushMatrix();
                glTranslatef(0.02, 1.12, 0);
                glRotatef(angleX[6], 0, 0, 1);
                glTranslatef(0, -1.15, 0);
                drawEyeB();
            glPopMatrix();
        glPopMatrix();

    glPopMatrix();

    glBindTexture(GL_TEXTURE_2D, id2);///�I��
    glBegin(GL_POLYGON);
        glTranslatef(0, 0, -2);
        glTexCoord2f(0,0); glVertex3f(-5,+2,+1);
        glTexCoord2f(0,1); glVertex3f(-5,-2,+1);
        glTexCoord2f(1,1); glVertex3f(+5,-2,+1);
        glTexCoord2f(1,0); glVertex3f(+5,+2,+1);
    glEnd();
    glutSwapBuffers();
}

const GLfloat light_ambient[]  = { 0.3f, 0.3f, 0.3f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, -5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };


void reshape(int w, int h)
{
   glViewport(0, 0, w, h); ///�]�w�����|�ݨ쪺�ϰ�
   float ar = w / (float) h; ///���e��
   glMatrixMode(GL_PROJECTION); ///������v�x�}
   glLoadIdentity();
   gluPerspective(60, ar, 0.01, 100); ///�z����v
   glMatrixMode(GL_MODELVIEW); ///��model view�x�}
   glLoadIdentity();
   gluLookAt(0, 0, -2, 0, 0, 0, 0, 1, 0); ///�z����v
}
int main(int argc, char*argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutInitWindowSize(1024, 572);
    glutCreateWindow("WALL-E");
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutIdleFunc(display); ///�[�o��, �������
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutKeyboardFunc(keyboard);

    id1 = myTexture("data/BaseColor.jpg");
    id2 = myTexture("data/background.jpg");
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    glutMainLoop();
}
