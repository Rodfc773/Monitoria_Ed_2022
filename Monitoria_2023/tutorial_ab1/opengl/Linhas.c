#include <GL/glut.h>
#include <GL/gl.h>
#include <stdio.h>

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

void display();
void ChangeSize(GLsizei w, GLsizei h);
void setupRC();

int main(int argc, char ** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);   
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT); //tamanho da janela criada
    glutInitWindowPosition(100,100); //posição que vai iniciar a janela
    glutCreateWindow("openGL with glut");

    setupRC();
    glutDisplayFunc(display);
    glutReshapeFunc(ChangeSize);
    glutMainLoop(); //faz com que a janela seja redesenhada o tempo inteiro em um loop;
    return 0; 
}
void ChangeSize(GLsizei w, GLsizei h){

    GLfloat nRange = 100.0f;

    //previne a divisão por 0

    if(h == 0) h = 1;

    //Configura a viewport para a janela de dimensões

    glViewport(0, 0, w, h);

    //Reseta a pilha da matriz de projeções
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    //Separa um parte da  viewport(left, rigth, bottom, top, near, far)

    if(w <= h) glOrtho(-nRange, nRange, -nRange*h/w, nRange*h/w, -nRange, nRange);

    else glOrtho(-nRange*w/h, nRange*w/h, -nRange, nRange, -nRange, nRange);

    //Resetando a pilha de modelo de vizualição

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
void display(){

    float x1, y1, x2, y2;

    scanf("%f %f %f %f", &x1, &y1, &x2, &y2);
    //limpa a janela com a cor atual
    glClear(GL_COLOR_BUFFER_BIT);

    glLineWidth(5.0);

    glBegin(GL_LINE_STRIP);

    glColor3f(0.5f, 0.7f, 0.2f);

    glVertex2f(x1, y1);
    glVertex2f(x2, y2);

    glEnd();
    //Especifica o fim do bloco de instrucao

    glutSwapBuffers();
    

}

void setupRC(){

    //blackground color

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    //Deixando a cor do desenho no verde
    glColor3f(0.0f, 1.0f, 0.0f);
}