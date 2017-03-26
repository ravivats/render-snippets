#include<stdlib.h>
#include<iostream>
#include<math.h>
#include<GL/glut.h>
using namespace std;

int w=500,h=500;
int mode=0;
int flag_first=0;
int temp1,temp2;
int arr[5];
int sub_menu_plot;
int mx=0,my=0;

void init()
{
    glClearColor(1.0,1.0,1.0,1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0,(float)w,0.0,float(h));    
}



void DrawCircle(float cx, float cy, float r, int num_segments) 
{ 
    glBegin(GL_LINE_LOOP); 
    for(int ii = 0; ii < num_segments; ii++) 
    { 
        float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle 

        float x = r * cosf(theta);//calculate the x component 
        float y = r * sinf(theta);//calculate the y component 

        glVertex2f(x + cx, y + cy);//output vertex 

    } 
    glEnd(); 
}

void DrawLineGraph()
{
    cout<<"Enter 5 frequencies in order:"<<endl;
    for(int i=0;i<5;i++)
        cin>>arr[i];
    glColor3f(1.0,0.0,0.0);    
    glBegin (GL_LINE_STRIP);
        for(int i=0;i<5;i++)
        {
            glVertex2i (25+i*50,arr[i]);                        
        }
    glEnd();
}

void DrawBarChart()
{
    cout<<"Enter 5 frequencies in order:"<<endl;
    for(int i=0;i<5;i++)
    cin>>arr[i];
    glColor3f(1.0,0.0,0.0);    
    for(int i=0;i<5;i++)
    {
        glBegin (GL_POLYGON);
            glVertex2i (25+i*50,0);
            glVertex2i (25+i*50,arr[i]);
            glVertex2i (50+i*50,arr[i]);
            glVertex2i (50+i*50,0);
        glEnd();
    }

}

void DrawPieChart()
{
        
    cout<<"Enter 3 frequencies in order:"<<endl;
    for(int i=0;i<3;i++)
        cin>>arr[i];
    int sum=arr[0]+arr[1]+arr[2];
    glBegin (GL_TRIANGLE_FAN);
        int i,n1,n2,n3,n;
        float x=250,y=250;
        float theta;
        glColor3f(1.0,0.0,0.0);    
            n1=360/(sum)*arr[0];
            n2=360/(sum)*arr[1];
            n3=360/(sum)*arr[2];
            n=n1+n2+n3;
            glVertex2f(x,y);
            for(i=0;i<n1;i++)
            {
                
                theta = 2.0f * 3.1415926f * float(i) / float(n);
                glVertex2f (x+25 * cosf(theta),y+    25 * sinf(theta));
                
            }
    glEnd();
    glBegin (GL_TRIANGLE_FAN);
        glColor3f(0.0,1.0,0.0);
            glVertex2f(x,y);
            for(;i<n1+n2;i++)
            {
                
                theta = 2.0f * 3.1415926f * float(i) / float(n);
                glVertex2f (x+25 * cosf(theta),y+    25 * sinf(theta));
            }
        
    glEnd();
    glBegin (GL_TRIANGLE_FAN);
        glColor3f(0.0,0.0,1.0);
            glVertex2f(x,y);
            for(;i<n1+n2+n3;i++)
            {
                theta = 2.0f * 3.1415926f * float(i) / float(n);
                glVertex2f (x+25 * cosf(theta),y+    25 * sinf(theta));
            }
    glEnd();
}

void display()
{    
    glClear(GL_COLOR_BUFFER_BIT);
}

void keyboard(unsigned char key,int x,int y)
{
        switch(key)
        {
            case 'Q':
            case 'q':    exit(0);
                        break;
            case 'C':
            case 'c':    glClearColor(1.0,1.0,1.0,0.0);
                        flag_first=0;
                        glClear(GL_COLOR_BUFFER_BIT);
                        break;
            case '0':    mode=0;
                        break;
            case '1':    mode=1;
                        break;
            case '2':    mode=2;
                        break;
            case '3':   mode=3;
                        DrawLineGraph();
                        break;
            case '4':    mode=4;
                        DrawBarChart();
                        break;
            case '5':    mode=5;
                        cout<<"Enter 5 frequencies in order:"<<endl;
                        for(int i=0;i<5;i++)
                            cin>>arr[i];
                        break;
            case '6':    mode=6;
                        DrawPieChart();
                        break;
            case '9':    mode=9;
                        break;

                        
        }
        glFlush();
}

void mouse(int button, int state, int x, int y)
{
    y=h-y;
    mx=x;
    my=y;
    //cout<<x<<" "<<y<<endl;
    if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN && mode==0)
    {
        glBegin (GL_POLYGON);
            glColor3f(1.0,0.0,0.0);    glVertex2i (x,y);
            glColor3f(0.0,1.0,0.0);    glVertex2i (x+50,y);
            glColor3f(0.0,0.0,1.0);    glVertex2i (x,y+50);
        glEnd();
    }
    else if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN && mode==9)
    {
        glBegin (GL_POLYGON);
            glColor3f(1.0,1.0,0.0);    glVertex2i (x,y);
            glColor3f(0.0,1.0,1.0);    glVertex2i (x+50,y);
            glColor3f(1.0,0.0,1.0);    glVertex2i (x+50,y+50);
            glColor3f(1.0,0.0,1.0);    glVertex2i (x,y+50);
        glEnd();
    }
    else if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN && flag_first==0 && mode==1)
    {
        flag_first=1;
        temp1=x;
        temp2=y;
    }
    else if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN && flag_first==1 && mode==1)
    {
        flag_first=1;
        glBegin(GL_LINES);
            glColor3f(1.0,0.0,0.0);    
            glVertex2i (temp1,temp2);
            glVertex2i (x,y);
        glEnd();
        temp1=x;
        temp2=y;
    }
    else if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN && mode==2)
    {
        
        DrawCircle(x,y,25,10);
        
    }    
        
    
    glFlush();
}
void plot_menu_handler(int x)
{
    //cout<<x<<endl;
    
    switch(x)
    {
        case 2:        DrawLineGraph();
                    break;
        case 3:        DrawBarChart();    
                    break;
    }
    glFlush();
}

void main_menu_handler(int x)
{
    //cout<<x<<endl;
    if(x==1)
        exit(0);
    
    glFlush();
}
void init_menu()
{
    sub_menu_plot=glutCreateMenu(plot_menu_handler);
        glutAddMenuEntry("Line",2);
        glutAddMenuEntry("Bar",3);
    glutCreateMenu(main_menu_handler);
    glutAddSubMenu("Plot",sub_menu_plot);
    glutAddMenuEntry("Quit",1);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

}
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(w,h);
    glutCreateWindow("Exmp");
    init();
    init_menu();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);

    glutMainLoop();            
    return 0;
}
