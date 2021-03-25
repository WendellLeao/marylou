#include <gl/glut.h>
#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


//Declara os milhos
int milho1= 4, milho2= 6, milho3= 9, milho4= 5, milho5= 8, milho6= 12, milho7= 30, milho8= 23, milho9= 26, milho10= 18,
    milho11= 10, milho12= 13, milho13= 16, milho14= 18, milho15= 20, milho16= 31, milho17= 26, milho18= 33, milho19= 35, milho20= 35,
    totalbolas = 0, movimentoCoiote3 = -1, movimentoCoiote4 = 0;

float galinhax1=2, galinhay1=2, galinhax2 = galinhax1+2, galinhay2=galinhay1-2, 
	  coiotex1=40, coiotey1=10, coiotex2 = 0, coiotey2 = 20, coiotex3 = 10, coiotey3 = 40, coiotex4=30, coiotey4=-15,
	  angle = 0;
	  
	  
	  
bool vertical = true, horizontal = true, viva = true;


void desenhar(){
	glClearColor(0, 0.9, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 40, 0, 30);

	glBegin(GL_QUADS);
	//Vitória
	
	
	//Cercas
	
	glColor3ub(255,255,255);
	glVertex2f(2, 27); //Cerca norte.
	glVertex2f(2, 28);
	glVertex2f(38, 28);
	glVertex2f(38, 27);
	
	
	glVertex2f(2, 2); //Cerca sul
	glVertex2f(2, 3);
	glVertex2f(38, 3);
	glVertex2f(38, 2);
	
	
	glVertex2f(2, 2); //Cerca oeste
	glVertex2f(3, 2);
	glVertex2f(3, 28);
	glVertex2f(2, 28);
	
	
	glVertex2f(37, 2); //Cerca leste
	glVertex2f(38, 2);
	glVertex2f(38, 28);
	glVertex2f(37, 28);
	
	
	glEnd();

	
	//Desenha os milhos 
     
	glColor3f(1,1,0);         
	glPointSize(8.0);
	glBegin(GL_POINTS);        
	
	glVertex2f (milho1,8); 
	glVertex2f (milho2,15); 
	glVertex2f (milho3,5); 
	glVertex2f (milho4,17); 
	glVertex2f (milho5,22); 
	glVertex2f (milho6,9); 
	glVertex2f (milho7,16); 
	glVertex2f (milho8,13); 
	glVertex2f (milho9,14); 
	glVertex2f (milho10,26);
	 
	glVertex2f (milho11,10); 
	glVertex2f (milho12,13); 
	glVertex2f (milho13,9); 
	glVertex2f (milho14,11); 
	glVertex2f (milho15,18); 
	glVertex2f (milho16,20); 
	glVertex2f (milho17,14); 
	glVertex2f (milho18,12); 
	glVertex2f (milho19,7); 
	glVertex2f (milho20,22); 


	glEnd(); 
	
	glColor3f(0, 1, 1);
	
	glBegin(GL_TRIANGLES); // Bico e asas
	glColor3f(0.9, 0.9, 0);
	glVertex2f(galinhax1+1, galinhay1+0.5); 
	glVertex2f(galinhax1+1.5, galinhay1);
	glVertex2f(galinhax1+0.5, galinhay1);
	
	glColor3ub(210,105,30);
	glVertex2f(galinhax1+2, galinhay1-0.5); 
	glVertex2f(galinhax1+2.5, galinhay1-1.5);
	glVertex2f(galinhax1+2, galinhay1-1.5);
	
	glVertex2f(galinhax1, galinhay1-0.5); 
	glVertex2f(galinhax1-0.5, galinhay1-1.5);
	glVertex2f(galinhax1, galinhay1-1.5);
	glEnd();
	
	
	glBegin(GL_QUADS); // Corpo
	glColor3ub(210,105,30);
	glVertex2f(galinhax1, galinhay1); //Ponto superior esquerdo
	glVertex2f(galinhax1+2, galinhay1);
	glVertex2f(galinhax2, galinhay2); // Ponto inferior direito.
	glVertex2f(galinhax1, galinhay1-2); 
	glEnd();
	
	glPushMatrix();
	glBegin(GL_QUADS); 
	glColor3ub(140, 70, 20);
	// Coiote 1
	glVertex2f(coiotex1, coiotey1);	glVertex2f(coiotex1+1, coiotey1); glVertex2f(coiotex1+1, coiotey1-1); glVertex2f(coiotex1, coiotey1-1); 
	glVertex2f(coiotex1+1, coiotey1+0.5); glVertex2f(coiotex1+4, coiotey1+0.5); glVertex2f(coiotex1+4, coiotey1-1.5); glVertex2f(coiotex1+1, coiotey1-1.5);
	glVertex2f(coiotex1+4, coiotey1-0.3); glVertex2f(coiotex1+6.5, coiotey1-0.3); glVertex2f(coiotex1+6.5, coiotey1-0.7); glVertex2f(coiotex1+4, coiotey1-0.7);
	// Coiote 2
	glVertex2f(coiotex2, coiotey2); glVertex2f(coiotex2-1, coiotey2); glVertex2f(coiotex2-1, coiotey2-1); glVertex2f(coiotex2, coiotey2-1);
	glVertex2f(coiotex2-1, coiotey2+0.5); glVertex2f(coiotex2-4, coiotey2+0.5); glVertex2f(coiotex2-4, coiotey2-1.5); glVertex2f(coiotex2-1, coiotey2-1.5);
	glVertex2f(coiotex2-4, coiotey2-0.3); glVertex2f(coiotex2-6.5, coiotey2-0.3); glVertex2f(coiotex2-6.5, coiotey2-0.7); glVertex2f(coiotex2-4, coiotey2-0.7);
	
	// Coiote 3
	
//	glRotatef (angle, coiotex3, coiotey3, 1);
	glVertex2f(coiotex3, coiotey3);	glVertex2f(coiotex3-1, coiotey3); glVertex2f(coiotex3-1, coiotey3+1); glVertex2f(coiotex3, coiotey3+1);
	glVertex2f(coiotex3+0.5, coiotey3+1); glVertex2f(coiotex3+0.5, coiotey3+4); glVertex2f(coiotex3-1.5, coiotey3+4); glVertex2f(coiotex3-1.5, coiotey3+1);
	glVertex2f(coiotex3-0.3, coiotey3+4); glVertex2f(coiotex3-0.3, coiotey3+6.5); glVertex2f(coiotex3-0.7, coiotey3+6.5); glVertex2f(coiotex3-0.7, coiotey3+4);
	
	glVertex2f(coiotex4, coiotey4);	glVertex2f(coiotex4-1, coiotey4); glVertex2f(coiotex4-1, coiotey4-1); 	glVertex2f(coiotex4, coiotey4-1);
	glVertex2f(coiotex4+0.5, coiotey4-1); glVertex2f(coiotex4+0.5, coiotey4-4); glVertex2f(coiotex4-1.5, coiotey4-4); glVertex2f(coiotex4-1.5, coiotey4-1);
	glVertex2f(coiotex4-0.3, coiotey4-4); glVertex2f(coiotex4-0.3, coiotey4-6.5); glVertex2f(coiotex4-0.7, coiotey4-6.5); glVertex2f(coiotex4-0.7, coiotey4-4);

	glEnd();
	
		
	//Vitória
	if (totalbolas>=20 || !viva){
	glBegin(GL_QUADS);
	glColor3ub(0,0,0);
	
	glVertex2f(0, 0);
	glVertex2f(40, 0);
	glVertex2f(40, 30);
	glVertex2f(0, 30);
	glEnd();	
	}
	
	

	
	
	glEnd();

	glPopMatrix();
	
	if (viva)
		{
		//Colisao com as bolas
		glPushMatrix();
		if ((galinhax1+1 == milho1) && (galinhay1 == 8)) {milho1=-14, totalbolas += 1;}
		if ((galinhax1+1 == milho2) && (galinhay1 == 15)) {milho2=-14, totalbolas += 1;}
		if ((galinhax1+1 == milho3) && (galinhay1 == 5)) {milho3=-14, totalbolas += 1;}
		if ((galinhax1+1 == milho4) && (galinhay1 == 17)) {milho4=-14, totalbolas += 1;}
		if ((galinhax1+1 == milho5) && (galinhay1 == 22)) {milho5=-14, totalbolas += 1;}
		if ((galinhax1+1 == milho6) && (galinhay1 == 9)) {milho6=-14, totalbolas += 1;}
		if ((galinhax1+1 == milho7) && (galinhay1 == 16)) {milho7=-14, totalbolas += 1;}
		if ((galinhax1+1 == milho8) && (galinhay1 == 13)) {milho8=-14, totalbolas += 1;}
		if ((galinhax1+1 == milho9) && (galinhay1 == 14)) {milho9=-14, totalbolas += 1;}
		if ((galinhax1+1 == milho10) && (galinhay1 == 26)) {milho10=-14, totalbolas += 1;}
		if ((galinhax1+1 == milho11) && (galinhay1 == 10)) {milho11=-14, totalbolas += 1;}
		if ((galinhax1+1 == milho12) && (galinhay1 == 13)) {milho12=-14, totalbolas += 1;}
		if ((galinhax1+1 == milho13) && (galinhay1 == 9))	{milho13=-14, totalbolas += 1;}
		if ((galinhax1+1 == milho14) && (galinhay1 == 11)) {milho14=-14, totalbolas += 1;}
		if ((galinhax1+1 == milho15) && (galinhay1 == 18)) {milho15=-14, totalbolas += 1;}
		if ((galinhax1+1 == milho16) && (galinhay1 == 20)) {milho16=-14, totalbolas += 1;}
		if ((galinhax1+1 == milho17) && (galinhay1 == 14)) {milho17=-14, totalbolas += 1;}
		if ((galinhax1+1 == milho18) && (galinhay1 == 12)) {milho18=-14, totalbolas += 1;}
		if ((galinhax1+1 == milho19) && (galinhay1 == 7)) {milho19=-14, totalbolas += 1;}
		if ((galinhax1+1 == milho20) && (galinhay1 == 22)) {milho20=-14, totalbolas += 1;}
		glPopMatrix();
		if(totalbolas >= 20){
		

			glColor3ub(255, 255, 255);
			glRasterPos2f(10, 15.0);
			char* p = (char*) "A galinha ta de buxin chei";
			while (*p !='\0')
			{
				glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *p++);
			}

		}		
		
		
	}
	else
	{
		glColor3ub(255, 255, 255);
			glRasterPos2f(14, 15.0);
			char* p = (char*) "Virou nugget!";
			while (*p !='\0')
			{
				glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *p++);
			}
	}
	
	glutSwapBuffers();
	glutPostRedisplay();
}

/*void coiote(){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glBegin(GL_QUADS);
	glRotatef (angle, coiotex3, coiotey3, 1);
	glVertex2f(coiotex3, coiotey3);	glVertex2f(coiotex3-1, coiotey3); glVertex2f(coiotex3-1, coiotey3+1); glVertex2f(coiotex3, coiotey3+1);
	glVertex2f(coiotex3+0.5, coiotey3+1); glVertex2f(coiotex3+0.5, coiotey3+4); glVertex2f(coiotex3-1.5, coiotey3+4); glVertex2f(coiotex3-1.5, coiotey3+1);
	glVertex2f(coiotex3-0.3, coiotey3+4); glVertex2f(coiotex3-0.3, coiotey3+6.5); glVertex2f(coiotex3-0.7, coiotey3+6.5); glVertex2f(coiotex3-0.7, coiotey3+4);
	glEnd();
	
}*/



void GameLoop()
{
	

	glutSwapBuffers();
	glutPostRedisplay();
}



void controle (unsigned char tecla, int x, int y)
{
	if(viva && totalbolas<20){
	
		if(tecla == 'w' || tecla == 'W')
		{
		 	galinhay1+=1;
		 	galinhay2+=1;
		}
		if(tecla == 's' || tecla == 'S')
		{
			galinhay1-=1;
			galinhay2-=1;
		}
	
	
		if(tecla == 'a' || tecla == 'A')
		{
			galinhax1-=1;
			galinhax2-=1;
		}
		if(tecla == 'd' || tecla == 'D')
		{
			galinhax1+=1;
			galinhax2+=1;
		}
		
		// Colisão com a cerca
		if(galinhax1<3)
		{
			galinhax1 = 3;
			galinhax2 = galinhax1+2;
		}
		if(galinhax2>37)
		{
			galinhax1 = 35;
			galinhax2 = galinhax1+2;
		}
		if(galinhay1>27)
		{
			galinhay1 = 27;
			galinhay2 = galinhay1-2;
		}
		if(galinhay2 < 3)
		{
			galinhay1 = 5;
			galinhay2 = galinhay1-2;
		}
	}
	
	
	glutPostRedisplay();
}

void setas (int tecla, int x, int y){
	if(tecla == GLUT_KEY_UP)
	{
		galinhay1+=1;
		galinhay2+=1;	
	}
	if(tecla == GLUT_KEY_DOWN)
	{
		galinhay1-=1;
		galinhay2-=1;
	}
	if(tecla == GLUT_KEY_LEFT)
	{
		galinhax1-=1;
		galinhax2-=1;
	}
	if(tecla == GLUT_KEY_RIGHT)
	{
		galinhax1+=1;
		galinhax2+=1;
	}
		if(galinhax1<3)
		{
			galinhax1 = 3;
			galinhax2 = galinhax1+2;
		}
		if(galinhax2>37)
		{
			galinhax1 = 35;
			galinhax2 = galinhax1+2;
		}
		if(galinhay1>27)
		{
			galinhay1 = 27;
			galinhay2 = galinhay1-2;
		}
		if(galinhay2 < 3)
		{
			galinhay1 = 5;
			galinhay2 = galinhay1-2;
		}
		glutPostRedisplay();
}

void AnimaCoiote(int value){
	
	coiotex1-=1;
	if(coiotex1<-30){
		coiotex1 = 40;
	}
	coiotex2+=1;
	if(coiotex2>60){
		coiotex2 = 0;
	}
	coiotey3+=movimentoCoiote3;
	if(coiotey3<=-10){
		coiotey3 = 30;
		
	//	angle = 180;
		movimentoCoiote3=0;
		movimentoCoiote4=1;
		
	}
	coiotey4+=movimentoCoiote4;
	if(coiotey4>=40){
		coiotey4 = -10;
		
	//	angle=0;
		movimentoCoiote3=-1;
		movimentoCoiote4=0;
		
	}
	
	// Colisão com o coiote 1.
	if( (galinhax1-1>=coiotex1) && (galinhay1-1<coiotey1+0.5) && (galinhax1-1<=coiotex1+4) && (galinhay1-1>=coiotey1-1.5) 
		
	)
	{		
		viva = false;		
	}
	// Colisão com o coiote 2.
	if( (galinhax1-1<=coiotex2) && (galinhay1-1<coiotey2+0.5) && (galinhax1-1>=coiotex2-4) && (galinhay1-1>=coiotey2-1.5)
		
	)
	{		
		viva = false;			
	}
	// Colisão com o coiote 3.
	if( (galinhax1-1<=coiotex3+0.5) && (galinhay1-1>=coiotey3) && (galinhax1-1>=coiotex3-4) && (galinhay1-1<=coiotey3+1.5)
		
	)
	{		
		viva = false;			
	}
	if( (galinhax1-1<=coiotex4+0.5) && (galinhay1-1<=coiotey4) && (galinhax1-1>=coiotex4-4) && (galinhay1-1>=coiotey4-1.5)
		
	)
	{		
		viva = false;			
	}
	
	
	
	glutPostRedisplay();
	glutTimerFunc(40, AnimaCoiote, 1);
}



int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(500, 400);
	glutCreateWindow("Marylou");
	glutKeyboardFunc(controle);
	glutSpecialFunc(setas);
	glutDisplayFunc(desenhar);
	glutTimerFunc(40, AnimaCoiote, 1);
	
	glutMainLoop();
	return 0;
}
