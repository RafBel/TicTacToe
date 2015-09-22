#include <iostream>
#include <gl/Gl.h>
#include <gl/Glu.h>
#include <gl/glut.h>
#include <math.h>
#include "tictactoe_header.h"

//global variables

//defines the screen specs
int screenWidth = 640; int screenHeight = 480;

///TTT Object
tictactoe *tttObj = new tictactoe();

//Mouse coord
float mouseX, mouseY;


void drawO()
{
	float counter;
			

			if (tttObj->getTTTSquare(6) == O)
			{
				glBegin(GL_LINE_LOOP);
				for (counter = 0; counter < PI_TWO; counter += 0.001)
					glVertex2f(167.5 + 25*cos(counter) , 150 + 25*sin(counter));
				glEnd();
				
			}

			if (tttObj->getTTTSquare(3) == O)
			{
				glBegin(GL_LINE_LOOP);
				for (counter = 0; counter < PI_TWO; counter += 0.001)
					glVertex2f(167.5 + 25*cos(counter) , 255 + 25*sin(counter));
				glEnd();
			}

			if (tttObj->getTTTSquare(0) == O)
			{
				glBegin(GL_LINE_LOOP);
				for (counter = 0; counter < PI_TWO; counter += 0.001)
					glVertex2f(167.5 + 25*cos(counter) , 360 + 25*sin(counter));
				glEnd();
			}

			if (tttObj->getTTTSquare(7) == O)
			{
				glBegin(GL_LINE_LOOP);
				for (counter = 0; counter < PI_TWO; counter += 0.001)
					glVertex2f(300 + 25*cos(counter) , 150 + 25*sin(counter));
				glEnd();
			}

			if (tttObj->getTTTSquare(4) == O)
			{
				glBegin(GL_LINE_LOOP);
				for (counter = 0; counter < PI_TWO; counter += 0.001)
					glVertex2f(300 + 25*cos(counter) , 255 + 25*sin(counter));
				glEnd();
			}

			if (tttObj->getTTTSquare(1) == O)
			{
				glBegin(GL_LINE_LOOP);
				for (counter = 0; counter < PI_TWO; counter += 0.001)
					glVertex2f(300 + 25*cos(counter) , 360 + 25*sin(counter));
				glEnd();
			}

			if (tttObj->getTTTSquare(8) == O)
			{
				glBegin(GL_LINE_LOOP);
				for (counter = 0; counter < PI_TWO; counter += 0.001)
					glVertex2f(435.5 + 25*cos(counter) , 150 + 25*sin(counter));
				glEnd();
			}

			if (tttObj->getTTTSquare(5) == O)
			{
				glBegin(GL_LINE_LOOP);
				for (counter = 0; counter < PI_TWO; counter += 0.001)
					glVertex2f(435.5 + 25*cos(counter) , 255 + 25*sin(counter));
				glEnd();
			}

			if (tttObj->getTTTSquare(2) == O)
			{
				glBegin(GL_LINE_LOOP);
				for (counter = 0; counter < PI_TWO; counter += 0.001)
					glVertex2f(435.5 + 25*cos(counter) , 360 + 25*sin(counter));
				glEnd();
			}
		
}

void checkAI()
{
	tttObj->AIBehaviour();

}

void drawX()
{
			if (tttObj->getTTTSquare(6) == X)
			{
				
				glVertex2i( 120, 120); //first line
				glVertex2i( 205 , 180);

				glVertex2i( 120 , 180); //second line
				glVertex2i (205 , 120);

				
			}

			if (tttObj->getTTTSquare(3) == X)
			{

				glVertex2i( 120, 220); //first line
				glVertex2i( 205 , 290);

				glVertex2i( 120 , 290); //second line
				glVertex2i (205 , 220);
			}

			if (tttObj->getTTTSquare(0) == X)
			{
				glVertex2i( 120, 330); //first line
				glVertex2i( 205 , 390);

				glVertex2i( 120 , 390); //second line
				glVertex2i (205 , 330); 	
			}

			if (tttObj->getTTTSquare(7) == X)
			{
				glVertex2i( 245, 120); //first line
				glVertex2i( 355 , 180);

				glVertex2i( 245 , 180); //second line
				glVertex2i (355 , 120); 
			}

			if (tttObj->getTTTSquare(4) == X)
			{

				glVertex2i( 245, 220); //first line
				glVertex2i( 355 , 290);

				glVertex2i( 245 , 290); //second line
				glVertex2i (355 , 220);	
			}

			if (tttObj->getTTTSquare(1) == X)
			{
				glVertex2i( 245, 330); //first line
				glVertex2i( 355 , 390);

				glVertex2i( 245 , 390); //second line
				glVertex2i (355 , 330);	
			}

			if (tttObj->getTTTSquare(8) == X)
			{
				glVertex2i( 395, 120); //first line
				glVertex2i( 480 , 180);

				glVertex2i( 395 , 180); //second line
				glVertex2i (480, 120);	
			}

			if (tttObj->getTTTSquare(5) == X)
			{

				glVertex2i( 395, 220); //first line
				glVertex2i( 480, 290);

				glVertex2i( 395 , 290); //second line
				glVertex2i (480 , 220);	
			}

			if (tttObj->getTTTSquare(2) == X)
			{
				glVertex2i( 395, 330); //first line
				glVertex2i( 480 , 390);

				glVertex2i( 395 , 390); //second line
				glVertex2i (480 , 330);	
			}

}

void myInit(void)
{
	glClearColor(1.0,1.0,1.0,0.0); //sets default background color to white
	glPointSize(4.0); 
}

void reshape(int w, int h) //responsible for keeping the aspect ratio the same
{
	glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    gluOrtho2D (0.0, (GLdouble) w, 0.0, (GLdouble) h);
}

void mouse(int button, int state, int x, int y)
{
	//Draws a X when the player clicks in a TTT that is empty and when it's his turn
	if ( state == GLUT_DOWN && button == GLUT_LEFT_BUTTON && tttObj->getPlayerTurn() == 1)
	{
			mouseX = x;
			mouseY = screenHeight - y;
			if ( (mouseX > 100) && (mouseX < 225))
			{
				if ((mouseY > 100) && ( mouseY < 200)) 
				{
					tttObj->updateGame(6); 
					glutPostRedisplay();
				}

				else if ( mouseY > 200 && mouseY < 310)
				{
					tttObj->updateGame(3);
					glutPostRedisplay();
				}
				
				else if (mouseY > 310 && mouseY < 410)
				{
					tttObj->updateGame(0);
					glutPostRedisplay();
				}
			}

			if (mouseX > 225 && mouseX < 375)
			{
				if ((mouseY > 100) && ( mouseY < 200)) 
				{
					tttObj->updateGame(7); 
					glutPostRedisplay();
				}

				else if ( mouseY > 200 && mouseY < 310)
				{
					tttObj->updateGame(4);
					glutPostRedisplay();
				}
				
				else if (mouseY > 310 && mouseY < 410)
				{
					tttObj->updateGame(1);
					glutPostRedisplay();
				}
			}
			
			if (mouseX > 375 && mouseX < 500)
			{
				if ((mouseY > 100) && ( mouseY < 200)) 
				{
					tttObj->updateGame(8); 
					glutPostRedisplay();
				}

				else if ( mouseY > 200 && mouseY < 310)
				{
					tttObj->updateGame(5);
					glutPostRedisplay();
				}
				
				else if (mouseY > 310 && mouseY < 410)
				{
					tttObj->updateGame(2);
					glutPostRedisplay();
				}
			}
	}

}


void display(void)
{
	glLineWidth(2); 
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0f,0.0f,0.0f);
	glBegin(GL_LINES); //defines tic tac toe lines
		glVertex2i(225,100); //First line
		glVertex2i(225,410);

		glVertex2i(375,100); //Second line
		glVertex2i(375,410);

		glVertex2i(100,200); //Third line
		glVertex2i(500,200);

		glVertex2i(100, 310); //Fourth line
		glVertex2i(500, 310);


		//draws the X
		drawX();

	glEnd();

	drawO();

	glutSwapBuffers();

	if (tttObj->newGame() == true) //empties board
		glutPostRedisplay();

}

int main(int argc, char **argv)
{
	

	//OpenGL and GLUT
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE| GLUT_RGB); //display mode is now set
	glutInitWindowSize(screenWidth,screenHeight); //defines the window size to 600x480
	glutInitWindowPosition(100,100);
	glutCreateWindow("Tic Tac Toe");

	glutDisplayFunc(display);
	glutReshapeFunc(reshape); 

	myInit();
	glutMouseFunc(mouse);
	glutIdleFunc(checkAI);


	tttObj->AIBehaviour();
	glutMainLoop();

	return 0;
}