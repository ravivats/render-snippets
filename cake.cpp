#include <GL/glut.h> // (or others, depending on the system in use)
void init (void)  {
	glClearColor (1.0, 1.0, 1.0, 0.0);       // Set display-window color to white.
	glMatrixMode (GL_PROJECTION); // Set projection parameters.
	gluOrtho2D (0.0, 200.0, 0.0, 150.0);
}
void lineSegment (void)  {
	glClear (GL_COLOR_BUFFER_BIT); // Clear display window.
	glColor3f (1.0, 0.0, 0.0);                   // Set line segment color to red.
	glBegin (GL_LINES);
		glVertex2i (15, 40);	// Specify line-segment geometry.
		glVertex2i (145, 40);
		glVertex2i (15, 20);
		glVertex2i (145, 20);
		glVertex2i (15, 40);
		glVertex2i (15, 20);// Specify line-segment geometry.
		glVertex2i (145, 40);
		glVertex2i (145, 20);
		//seperate rectangle with new color
		glColor3f (0.0, 1.0, 0.0); 
		glVertex2i (30, 40);
		glVertex2i (30, 60);
		glVertex2i (130, 60);
		glVertex2i (130, 40);
		glVertex2i (30, 60);
		glVertex2i (130, 60);
		//seperate rectangle with new color
		glColor3f (0.0, 1.0, 1.0); 
		glVertex2i (45, 80);
		glVertex2i (115, 80);
		glVertex2i (45, 80);
		glVertex2i (45, 60);
		glVertex2i (115, 80);
		glVertex2i (115, 60);
		//seperate rectangle with new color
		glColor3f (1.0, 0.0, 1.0); 
		glVertex2i (60, 80);
		glVertex2i (60, 100);
		glVertex2i (100, 80);
		glVertex2i (100, 100);
		glVertex2i (60, 100);
		glVertex2i (100, 100);
		//seperate rectangle with new color
		glColor3f (0.0, 0.0, 1.0); 
		glVertex2i (75, 100);
		glVertex2i (75, 140);
		glVertex2i (85, 100);
		glVertex2i (85, 140);
		glVertex2i (75, 140);
		glVertex2i (85, 140);

		//seperate rectangle with new color
		glColor3f (0.0, 1.0, 1.0); 
		glVertex2i (25, 80);
		glVertex2i (45, 60);
		glVertex2i (115, 60);
		glVertex2i (135, 80);
		
		//seperate rectangle with new color
		glColor3f (1.0, 0.0, 1.0); 
		glVertex2i (60, 80);
		glVertex2i (40, 100);
		glVertex2i (100, 80);
		glVertex2i (120, 100);
	glEnd ( );
	//drawing triangles after this
	glColor3f (0.0, 0.0, 0.0);
	glBegin(GL_TRIANGLES);
	 glVertex3i(120,110,0);//triangle one first vertex
     glVertex3i(120,90,0);//triangle one second vertex
     glVertex3i(140,100,0);
	glEnd ();
	glBegin(GL_TRIANGLES);
	 glVertex3i(135,90,0);//triangle one first vertex
     glVertex3i(135,70,0);//triangle one second vertex
     glVertex3i(155,80,0);
	glEnd ();
	glBegin(GL_TRIANGLES);
	 glVertex3i(40,110,0);//triangle one first vertex
     glVertex3i(40,90,0);//triangle one second vertex
     glVertex3i(20,100,0);
	glEnd ();
	glBegin(GL_TRIANGLES);
	 glVertex3i(25,90,0);//triangle one first vertex
     glVertex3i(25,70,0);//triangle one second vertex
     glVertex3i(5,80,0);
	glEnd ();



	glFlush ( ); 	// Process all OpenGL routines as quickly as possible.
}
void main (int argc, char** argv)   {
	glutInit (&argc, argv); 				// Initialize GLUT.
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB); 	// Set display mode.
	glutInitWindowPosition (50, 100); 	// Set top-left display-window position.
	glutInitWindowSize (400, 300); 	// Set display-window width and height.
	glutCreateWindow ("An Example OpenGL Program"); // Create display window.
	init(); 			// Execute initialization procedure.
	glutDisplayFunc (lineSegment); 	// Send graphics to display window.
	glutMainLoop ( ); 		// Display everything and wait.
}
