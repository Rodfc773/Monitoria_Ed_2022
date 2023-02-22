#include <iostream>
#include <GL/glut.h>
#include <GL/gl.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
/*  Pra compilar g++ Exemplo.cpp -o Bounce -Ifreeglut/include -Lfreeglut/lib -lGL -lglut 
    Para* Compilar em arquivos do tipo : gcc nome do arquivo -o nome do execuável -Ifreeglut/include -Lfreeglut/lib -lGL -lglut */



// Initial square position and size
GLfloat myx1 = 0.0f;
GLfloat myy1 = 0.0f;
GLfloat rsize = 25;

// Step size in x and y directions
// (number of pixels to move each time)
GLfloat xstep = 1.0f;
GLfloat ystep = 1.0f;
// Keep track of windows changing width and height
GLfloat windowWidth;
GLfloat windowHeight;

void ChangeSize(GLsizei w, GLsizei h);
void setupRC();
void RenderScene();
void TimerFunction(int value);


int main(int argc, char **argv){

    //Funcoes nescessarias para o funcionamento da biblioteca

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(WINDOW_WIDTH,WINDOW_HEIGHT);
    glutCreateWindow("Bounce");
    setupRC();
    glutDisplayFunc(RenderScene);
    glutReshapeFunc(ChangeSize);

    // Funcao que gera a animcao do codigo(nao nescessaria)
    //glutTimerFunc(500,TimerFunction,5);

    glutMainLoop();

    return 0;


}
void TimerFunction(int value){

    // Reverse direction when you reach left or right edge
    if(myx1 > windowWidth-rsize || myx1 < -windowWidth) xstep = -xstep;

    // Reverse direction when you reach top or bottom edge
    if(myy1 > windowHeight || myy1 < -windowHeight + rsize) ystep = -ystep;
    // Actually move the square
    myx1 += xstep;
    myy1 += ystep;
    // Check bounds. This is in case the window is made
    // smaller while the rectangle is bouncing and the
    // rectangle suddenly finds itself outside the new
    // clipping volume
    if(myx1 > (windowWidth-rsize + xstep))
    myx1 = windowWidth-rsize-1;
    else if(myx1 < -(windowWidth + xstep))
    myx1 = - windowWidth -1;
    if(myy1 > (windowHeight + ystep))
    myy1 = windowHeight-1;
    else if(myy1 < -(windowHeight - rsize + ystep))
    myy1 = -windowHeight + rsize -1;
    // Redraw the scene with new coordinates
    glutPostRedisplay();
    glutTimerFunc(500,TimerFunction, 5);
}
void RenderScene(void)
{
// Clear the window with current clearing color
glClear(GL_COLOR_BUFFER_BIT);
// Set current drawing color to red
//RGB
glColor3f(1.0f, 0.0f, 0.0f);
// Draw a filled rectangle with current color
glRectf(myx1, myy1, myx1 + rsize, myy1 - rsize);
// Flush drawing commands and swap
glutSwapBuffers();
}
///////////////////////////////////////////////////////////
// Called by GLUT library when the window has chanaged size
void ChangeSize(GLsizei w, GLsizei h)
{
    GLfloat aspectRatio;
    // Prevent a divide by zero
    if(h == 0)
    h = 1;
    // Set Viewport to window dimensions
    glViewport(0, 0, w, h);
    // Reset coordinate system
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

        //Establish clipping volume (left, right, bottom, top, near, far)
    aspectRatio = (GLfloat)w / (GLfloat)h;
    if (w <= h)
    glOrtho (-100.0, 100.0, -100 / aspectRatio, 100.0 / aspectRatio,
    1.0, -1.0);
    else
    glOrtho (-100.0 * aspectRatio, 100.0 * aspectRatio,
    -100.0, 100.0, 1.0, -1.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
void setupRC(){

    //blackground color

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    //Deixando a cor do desenho no verde
    glColor3f(0.0f, 1.0f, 0.0f);
}