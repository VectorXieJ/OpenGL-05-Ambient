
#include "../HeadFile/gltools.h"

static GLfloat xRot = 0.0f;
static GLfloat yRot = 0.0f;

// ��Ⱦ����
void RenderScene()
{
	// �����ɫ����������Ȼ�����
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// �������״̬
	glPushMatrix();
	// ��ת��ǰ����
	glRotatef(xRot, 1.0f, 0.0f, 0.0f);
	glRotatef(yRot, 0.0f, 1.0f, 0.0f);
	// ���Ʒɻ�ģ��
	glBegin(GL_TRIANGLES);
		// ��һ����ɫ
		glColor3ub(0, 255, 0);
		glVertex3f(0.0f, 0.0f, 60.0f);
		glVertex3f(-15.0f, 0.0f, 30.0f);
		glVertex3f(15.0f,0.0f,30.0f);

		glVertex3f(15.0f,0.0f,30.0f);
		glVertex3f(0.0f, 15.0f, 30.0f);
		glVertex3f(0.0f, 0.0f, 60.0f);

		glVertex3f(0.0f, 0.0f, 60.0f);
		glVertex3f(0.0f, 15.0f, 30.0f);
		glVertex3f(-15.0f,0.0f,30.0f);

		// �ڶ�����ɫ
		glColor3ub(192,192,192);
		glVertex3f(-15.0f,0.0f,30.0f);
		glVertex3f(0.0f, 15.0f, 30.0f);
		glVertex3f(0.0f, 0.0f, -56.0f);

		glVertex3f(0.0f, 0.0f, -56.0f);
		glVertex3f(0.0f, 15.0f, 30.0f);
		glVertex3f(15.0f,0.0f,30.0f);	

		glVertex3f(15.0f,0.0f,30.0f);
		glVertex3f(-15.0f, 0.0f, 30.0f);
		glVertex3f(0.0f, 0.0f, -56.0f);

		// ��������ɫ
		glColor3ub(64,64,64);
		glVertex3f(0.0f,2.0f,27.0f);
		glVertex3f(-60.0f, 2.0f, -8.0f);
		glVertex3f(60.0f, 2.0f, -8.0f);

		glVertex3f(60.0f, 2.0f, -8.0f);
		glVertex3f(0.0f, 7.0f, -8.0f);
		glVertex3f(0.0f,2.0f,27.0f);

		glVertex3f(60.0f, 2.0f, -8.0f);
		glVertex3f(-60.0f, 2.0f, -8.0f);
		glVertex3f(0.0f,7.0f,-8.0f);

		glVertex3f(0.0f,2.0f,27.0f);
		glVertex3f(0.0f, 7.0f, -8.0f);
		glVertex3f(-60.0f, 2.0f, -8.0f);

		// ��������ɫ
		glColor3ub(255,255,0);
		glVertex3f(-30.0f, -0.50f, -57.0f);
		glVertex3f(30.0f, -0.50f, -57.0f);
		glVertex3f(0.0f,-0.50f,-40.0f);

		glVertex3f(0.0f,-0.5f,-40.0f);
		glVertex3f(30.0f, -0.5f, -57.0f);
		glVertex3f(0.0f, 4.0f, -57.0f);

		glVertex3f(0.0f, 4.0f, -57.0f);
		glVertex3f(-30.0f, -0.5f, -57.0f);
		glVertex3f(0.0f,-0.5f,-40.0f);

		glVertex3f(30.0f,-0.5f,-57.0f);
		glVertex3f(-30.0f, -0.5f, -57.0f);
		glVertex3f(0.0f, 4.0f, -57.0f);

		// ��������ɫ
		glColor3ub(255,0,0);
		glVertex3f(0.0f,0.5f,-40.0f);
		glVertex3f(3.0f, 0.5f, -57.0f);
		glVertex3f(0.0f, 25.0f, -65.0f);

		glVertex3f(0.0f, 25.0f, -65.0f);
		glVertex3f(-3.0f, 0.5f, -57.0f);
		glVertex3f(0.0f,0.5f,-40.0f);

		glVertex3f(3.0f,0.5f,-57.0f);
		glVertex3f(-3.0f, 0.5f, -57.0f);
		glVertex3f(0.0f, 25.0f, -65.0f);

	glEnd();
	// �ָ�����״̬
	glPopMatrix();
	// ��������������ʾ����
	glutSwapBuffers();
}
// ������Ⱦ״̬
void SetupRC()
{
	// ָ��������ǿ��
	GLfloat ambientLight[] = {1.0f, 1.0f, 1.0f, 1.0f};
	// ������ȼ��
	glEnable(GL_DEPTH_TEST);
	// �����ڵ��޳�
	glEnable(GL_CULL_FACE);
	// ������ʱ�뻷��Ϊ����
	glFrontFace(GL_CCW);
	// ���ù���
	glEnable(GL_LIGHTING);
	
	// ���ù���ģʽ����ambientLight��ָ����RGBǿ��ֵӦ�õ�������
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientLight);
	//
	glEnable(GL_COLOR_MATERIAL);
	// ���ö��������Ĳ������ԣ�׷��glColor
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	// ָ�������ɫ
	glClearColor(0.0f, 0.0f, 0.5f, 1.0f);
}

void ChangeSize(int w, int h)
{
	GLfloat nRange = 80.0f;
	// Prevent a divide by zero
	if(h == 0)
		h = 1;

	// Set Viewport to window dimensions
	glViewport(0, 0, w, h);

	// Reset coordinate system
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Establish clipping volume (left, right, bottom, top, near, far)
	if (w <= h) 
		glOrtho (-nRange, nRange, -nRange*h/w, nRange*h/w, -nRange, nRange);
	else 
		glOrtho (-nRange*w/h, nRange*w/h, -nRange, nRange, -nRange, nRange);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void SpecialKeys(int key, int x, int y)
{
	if(key == GLUT_KEY_UP)
		xRot-= 5.0f;

	if(key == GLUT_KEY_DOWN)
		xRot += 5.0f;

	if(key == GLUT_KEY_LEFT)
		yRot -= 5.0f;

	if(key == GLUT_KEY_RIGHT)
		yRot += 5.0f;

	if(key > 356.0f)
		xRot = 0.0f;

	if(key < -1.0f)
		xRot = 355.0f;

	if(key > 356.0f)
		yRot = 0.0f;

	if(key < -1.0f)
		yRot = 355.0f;

	// Refresh the Window
	glutPostRedisplay();
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800,600);
	glutCreateWindow("Ambient Light Jet");
	glutReshapeFunc(ChangeSize);
	glutSpecialFunc(SpecialKeys);
	glutDisplayFunc(RenderScene);
	SetupRC();
	glutMainLoop();

	return 0;
}