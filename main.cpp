#include"Header.h"
#include"Model.h"


#define WIDTH 1280
#define HEIGHT 720

#define INTERVAL 15
#include "../Library/MicrosoftTeams-image (30).png"
#include "../Library/MicrosoftTeams-image (32).png"
#include "../Library/MicrosoftTeams-image (28).png"




using namespace std;






Model CCrji;

void display();
void reshape(int,int);
void timer(int);

void init(){



    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    GLfloat light_pos[]={-1,10,100,1};
    glLightfv(GL_LIGHT0,GL_POSITION,light_pos);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_LINE_SMOOTH);
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

    glEnable(GL_TEXTURE_2D);

    glEnable(GL_DEPTH_TEST);

    //board.load("../../Models/board.obj");
    //player1.load("../../Models/player1.obj");
    //player2.load("../../Models/player2.obj");
    //player3.load("../../Models/player3.obj");
    //player4.load("../../Models/player4.obj");
    //snakeAll.load("../../Models/snakeAll.obj");
    //ladderUp.load("../../Models/ladderUpMode.obj");
    CCrji.load("../../Models/RACmodel1.obj");

}

int main(int argc,char**argv){


    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH |GLUT_MULTISAMPLE);

    glEnable(GL_MULTISAMPLE);
    glHint(GL_MULTISAMPLE_FILTER_HINT_NV,GL_NICEST);
    //glutSetOption(GLUT_MULTISAMPLE,8);
    int POS_X=(glutGet(GLUT_SCREEN_WIDTH)-WIDTH)>>1;
    int POS_Y=(glutGet(GLUT_SCREEN_HEIGHT)-HEIGHT)>>1;


    glutInitWindowPosition(POS_X,POS_Y);
    glutInitWindowSize(WIDTH,HEIGHT);
    glutCreateWindow("Animation");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(0,timer,0);
    init();

    glutMainLoop();

}

void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    //glTranslatef(-5,-5.5,-5);
    glTranslatef(-5,0,-75);
    glRotatef(30,1,0,0);
    CCrji.draw();



    glutSwapBuffers();
}


void reshape(int w,int h){

    const float ar = (float) w / (float) h;
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //gluPerspective()
    glFrustum(-ar, ar, -1,1, 2, 150.0);

    glMatrixMode(GL_MODELVIEW);

}

void timer(int){
    glutPostRedisplay();
    glutTimerFunc(5000,timer,0);




}






