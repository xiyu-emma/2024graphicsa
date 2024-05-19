#include <opencv/highgui.h> ///使用 OpenCV 2.1 比較簡單, 只要用 High GUI 即可
#include <opencv/cv.h>
#include <GL/glut.h>
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCV讀圖
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV轉色彩 (需要cv.h)
    glEnable(GL_TEXTURE_2D); ///1. 開啟貼圖功能
    GLuint id; ///準備一個 unsigned int 整數, 叫 貼圖ID
    glGenTextures(1, &id); /// 產生Generate 貼圖ID
    glBindTexture(GL_TEXTURE_2D, id); ///綁定bind 貼圖ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖T, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖S, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// 貼圖參數, 放大時的內插, 用最近點
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// 貼圖參數, 縮小時的內插, 用最近點
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

void drawBody(void)
{
    if (!body) {
	body = glmReadOBJ("data/body.obj");
	if (!body) exit(0);
	glmUnitize(body);
	glmFacetNormals(body);
	glmVertexNormals(body, 90.0);
    }

    glmDraw(body, GLM_SMOOTH | GLM_MATERIAL);

}
void drawNeckA(void)
{
    if (!neckA) {
	neckA = glmReadOBJ("data/neckA.obj");
	if (!neckA) exit(0);
	glmUnitize(neckA);
	glmFacetNormals(neckA);
	glmVertexNormals(neckA, 90.0);
    }

    glmDraw(neckA, GLM_SMOOTH | GLM_MATERIAL);

}
void drawNeckB(void)
{
    if (!neckB) {
	neckB = glmReadOBJ("data/neckB.obj");
	if (!neckB) exit(0);
	glmUnitize(neckB);
	glmFacetNormals(neckB);
	glmVertexNormals(neckB, 90.0);
    }

    glmDraw(neckB, GLM_SMOOTH | GLM_MATERIAL);

}
void drawHandA(void)
{
    if (!handA) {
	handA = glmReadOBJ("data/handA.obj");
	if (!handA) exit(0);
	glmUnitize(handA);
	glmFacetNormals(handA);
	glmVertexNormals(handA, 90.0);
    }

    glmDraw(handA, GLM_SMOOTH | GLM_MATERIAL);
}
void drawHandB(void)
{
    if (!handB) {
	handB = glmReadOBJ("data/handB.obj");
	if (!handB) exit(0);
	glmUnitize(handB);
	glmFacetNormals(handB);
	glmVertexNormals(handB, 90.0);
    }

    glmDraw(handB, GLM_SMOOTH | GLM_MATERIAL);
}
void drawEyeA(void)
{
    if (!eyeA) {
	eyeA = glmReadOBJ("data/eyeA.obj");
	if (!eyeA) exit(0);
	glmUnitize(eyeA);
	glmFacetNormals(eyeA);
	glmVertexNormals(eyeA, 90.0);
    }

    glmDraw(eyeA, GLM_SMOOTH | GLM_MATERIAL);
}
void drawEyeB(void)
{
    if (!eyeB) {
	eyeB = glmReadOBJ("data/eyeB.obj");
	if (!eyeB) exit(0);
	glmUnitize(eyeB);
	glmFacetNormals(eyeB);
	glmVertexNormals(eyeB, 90.0);
    }

    glmDraw(eyeB, GLM_SMOOTH | GLM_MATERIAL);
}

float angle[20]= {}; ///20個角度,都設成0
int angleID = 0;///可以是角度0、角度1....
int oldX=0, oldY=0;
#include <stdio.h>
FILE * fin = NULL;
FILE * fout = NULL;
void motion(int x, int y){
    angle[angleID] += y - oldY;
    oldX = x;
    oldY = y;
    glutPostRedisplay();///要重畫畫面
    if(fout==NULL) fout = fopen("angle.txt", "w+");
    for(int i=0; i<20; i++){
        printf("%.1f ", angle[i]);
        fprintf(fout, "%.1f ", angle[i]);
    }
    printf("\n");
    fprintf(fout, "\n");
}

void mouse(int button, int state, int x, int y)
{
    oldX = x;
    oldY = y;
}

void keyboard(unsigned char key, int x, int y)
{
    if(key=='r'){
        if(fin==NULL) fin=fopen("angle.txt", "r");
        for(int i=0; i<20; i++){
            fscanf(fin, "%f", & angle[i]);
        }
        glutPostRedisplay();
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
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glDisable(GL_TEXTURE_2D);

    glPushMatrix();
        glTranslatef(0, -0.2, 0);
        glRotatef(angle[0], 0, 1, 0);
        glRotatef(angle[1], 1, 0, 0);
        glScalef(0.7, 0.7, 0.7);
        drawBody();
        glPushMatrix();
            glTranslatef(-0.65, 0.48, -0.2);
            glRotatef(angle[2], 0, 1, 0);
            glRotatef(angle[3], 1, 0, 0);
            glTranslatef(0, 0.01, 0.53);
            glScalef(1.7, 1.7, 1.7);
            drawHandA();
        glPopMatrix();
        glPushMatrix();
            glTranslatef(0.65, 0.48, -0.2);
            glRotatef(angle[4], 0, 1, 0);
            glRotatef(angle[5], 1, 0, 0);
            glTranslatef(0, 0.01, 0.53);
            glScalef(1.7, 1.7, 1.7);
            drawHandB();
        glPopMatrix();
        glTranslatef(0, 0.7, -0.16);
        glRotatef(angle[8], 1, 0, 0);
        glTranslatef(0, 0.1, 0.08);
        glScalef(1.6, 1.6, 1.6);
        drawNeckA();
        glPushMatrix();
            glTranslatef(0, 0.09, 0.086);
            glRotatef(angle[9], 1, 0, 0);
            glTranslatef(0, 0.15, -0.1);
            glScalef(1.6, 1.6, 1.6);
            drawNeckB();
            glPushMatrix();
                glTranslatef(-0.03, 0.08, 0);
                glRotatef(angle[6], 0, 0, 1);
                glTranslatef(-0.07, -0.03, 0);
                glScalef(0.7, 0.7, 0.7);
                drawEyeA();
            glPopMatrix();
            glPushMatrix();
                glTranslatef(0.03, 0.08, 0);
                glRotatef(angle[7], 0, 0, 1);
                glTranslatef(0.07, -0.03, 0);
                glScalef(0.7, 0.7, 0.7);
                drawEyeB();
            glPopMatrix();
        glPopMatrix();

    glPopMatrix();
    glutSwapBuffers();
}

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 2.0f, 2.0f, 2.0f, 2.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, -5.0f, 0.0f };///加這行, 讓它轉動

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

int main(int argc, char*argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("WALL-E");
    glutDisplayFunc(display);
    glutIdleFunc(display); ///加這行, 讓它轉動
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutKeyboardFunc(keyboard);

    myTexture("data/BaseColor.jpg");

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
