

#include <iostream>
#include <glad/glad.h>		// find my OpenGL definitions and fetch their functional pointers to let me use OpenGL.
#include <GLFW/glfw3.h>		// setting OpenGL context and Window Rendering for my device and OS. Alternate: GLUT
#include <vector>			// STL Vector for storing vertices and edges of a polygon.
#include "Shader.h"         // Our shader functions are in this! Modularized for ease of use.
#include "VAO.h"            // VAO Management implemented here to keep main code clean.
#include "VBO.h"            // VBO Management implemented here to keep main code clean.
#include "Polygon.h"		// Helpful for defining a polygon with vertices and edges by using PolygonElements.
#include "PolygonElement.h" // Helpful for defining parts that make up an entire polygon... using curves, lines.
#include "Renderer.h"		// Rendering functions are implemented here to keep main code clean.

// JG, NS, MUKUL VERMA

// Function Declaration can be found below code...

Renderer** loadBuriBuri(Shader** shaderArray, int size);

int main()
{
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(800, 800, "BuriBuriZaeMon", NULL, NULL);

	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	// Enable anti-aliasing
	glfwWindowHint(GLFW_SAMPLES, 16); // Adjust the number for higher quality

	gladLoadGL();

	std::cout << "Window Initialized!\n";

	// GLAD OVER WORK

	glViewport(0, 0, 1000, 1000);


	Shader* s1 = new Shader("vertexShader.vert", "fragmentBlack.frag");
	Shader* s2 = new Shader("vertexShader.vert", "fragmentGlove.frag");
	Shader* s3 = new Shader("vertexShader.vert", "fragmentHandleRed.frag");
	Shader* s4 = new Shader("vertexShader.vert", "fragmentLower.frag");
	Shader* s5 = new Shader("vertexShader.vert", "fragmentNose.frag");
	Shader* s6 = new Shader("vertexShader.vert", "fragmentSkin.frag");
	Shader* s7 = new Shader("vertexShader.vert", "fragmentSword.frag");
	Shader* s8 = new Shader("vertexShader.vert", "fragmentSwordHandle.frag");
	Shader* s9 = new Shader("vertexShader.vert", "fragmentWhite.frag");
	Shader* s10 = new Shader("vertexShader.vert", "fragmentYellow.frag");

	Shader* shaderArray[10] = { s1, s2, s3, s4, s5, s6, s7, s8, s9, s10 };

	std::cout << "Shaders Compiled and Linked!\n";
	glEnable(GL_LINE_SMOOTH);

	Renderer** bodyPartRenderers = loadBuriBuri(shaderArray, 10);
	int numRenderers = 20;

	std::cout << "Renderer Created!\n";

	while (!glfwWindowShouldClose(window))
	{

		glClearColor(1.00f, 1.00f, 1.00f, 1.0f);

		glClear(GL_COLOR_BUFFER_BIT);

		glLineWidth(2.0f);

		
		// Render in correct order!
		bodyPartRenderers[0]->renderPolygon();
		 bodyPartRenderers[0]->renderBorder();
		bodyPartRenderers[1]->renderPolygon();
		 bodyPartRenderers[1]->renderBorder();
		bodyPartRenderers[2]->renderPolygon();
		 bodyPartRenderers[2]->renderBorder();
		bodyPartRenderers[3]->renderPolygon();
		 bodyPartRenderers[3]->renderBorder();
		bodyPartRenderers[4]->renderPolygon();
		 bodyPartRenderers[4]->renderBorder();
		 bodyPartRenderers[5]->renderPolygon();
		 bodyPartRenderers[5]->renderBorder();
		bodyPartRenderers[6]->renderPolygon();
		 bodyPartRenderers[6]->renderBorder();
		bodyPartRenderers[7]->renderPolygon();
		 bodyPartRenderers[7]->renderBorder();
		bodyPartRenderers[8]->renderPolygon();
		 bodyPartRenderers[8]->renderBorder();
		bodyPartRenderers[9]->renderPolygon();
		 bodyPartRenderers[9]->renderBorder();
		bodyPartRenderers[10]->renderPolygon();
		 bodyPartRenderers[10]->renderBorder();
		bodyPartRenderers[11]->renderPolygon();
		 bodyPartRenderers[11]->renderBorder();
		bodyPartRenderers[12]->renderPolygon();
		 bodyPartRenderers[12]->renderBorder();
		bodyPartRenderers[13]->renderPolygon();
		 bodyPartRenderers[13]->renderBorder();
		bodyPartRenderers[14]->renderPolygon();
		 bodyPartRenderers[14]->renderBorder();
		bodyPartRenderers[15]->renderPolygon();
		 bodyPartRenderers[15]->renderBorder();
		bodyPartRenderers[16]->renderPolygon();
		 bodyPartRenderers[16]->renderBorder();
		bodyPartRenderers[17]->renderPolygon();
		 bodyPartRenderers[17]->renderBorder();
		bodyPartRenderers[18]->renderPolygon();
		 bodyPartRenderers[18]->renderBorder();
		 bodyPartRenderers[19]->renderPolygon();
		 bodyPartRenderers[19]->renderBorder();
		 bodyPartRenderers[20]->renderPolygon();
		 bodyPartRenderers[20]->renderBorder();
		 bodyPartRenderers[21]->renderPolygon();
		 bodyPartRenderers[21]->renderBorder();
		 bodyPartRenderers[22]->renderPolygon();
		 bodyPartRenderers[22]->renderBorder();
		 bodyPartRenderers[23]->renderPolygon();
		 bodyPartRenderers[23]->renderBorder();
		 bodyPartRenderers[25]->renderPolygon();
		 bodyPartRenderers[25]->renderBorder();
		 bodyPartRenderers[26]->renderBorder();
		 bodyPartRenderers[27]->renderBorder();
		 bodyPartRenderers[28]->renderBorder();
		 bodyPartRenderers[29]->renderBorder();
		 bodyPartRenderers[24]->renderPolygon();
		 bodyPartRenderers[24]->renderBorder();
		 bodyPartRenderers[30]->renderPolygon();
		 bodyPartRenderers[30]->renderBorder();

		glfwSwapBuffers(window);

		glfwPollEvents();
	}

	for (int i = 0; i < numRenderers; i++)
	{
		bodyPartRenderers[i]->Delete();
	}


	for (int i = 0; i < 7; i++)
	{
		shaderArray[i]->Delete();
	}

	glfwDestroyWindow(window);

	glfwTerminate();
	return 0;
}



// Hardcoded from Desmos Modelling.
Renderer** loadBuriBuri(Shader** shaderArray, int size)
{
	// Render Up Hand Part 1:

	Renderer** bodyPartRenderers = new Renderer * [150]; // 0-19
	Polygon** POLYGONS = new Polygon * [150];
	float maxX = 50.0, maxY = 50.0, minX = -50.0, minY = -50.0;
	int i = 1;

	//[Hand – Left]
//    [GLOVE] – 
	std::vector<std::vector<float>> ST1A = { { -6.288, -14.932 ,0.0}, { -5.52, -16.87,0.0} };
	std::vector<std::vector<float>> ST1B = { { -5.52, -16.87, 0.0}, { -5.61, -18.15,0.0} };
	std::vector<std::vector<float>> ST1C = { { -5.61, -18.15, 0.0}, {-6.01, -18.16, 0.0} };
	std::vector<std::vector<float>> ST1D = { {-6.01, -18.16, 0.0}, { -5.67, -19.027, 0.0} };
	float CTRL1[4][2] = { { -5.67, -19.027}, { -6.12, -18.95}, {-7.64, -17.72}, { -8.28, -17.05} };
	std::vector<std::vector<float>> ST1E = { { -8.28, -17.05, 0.0}, { -6.288, -14.932, 0.0} };
	PolygonElement* p1[5] = { new StraightLine(ST1A[0], ST1A[1]), new StraightLine(ST1B[0], ST1B[1]), new StraightLine(ST1C[0], ST1C[1]), new StraightLine(ST1D[0], ST1D[1]), new CubicBezierCurve(CTRL1) };
	POLYGONS[0] = new IrregularPolygon(p1, 5);
	POLYGONS[0]->normalizeControlPoints(maxX, maxY, minX, minY);
	bodyPartRenderers[5] = new Renderer(POLYGONS[0], *shaderArray[1], *shaderArray[0]);

	std::cout << i++ << "\n";

	//[Remaining Part]
	std::vector<std::vector<float>> ST2A = { { -8.28, -17.05, 0.0}, { -6.288, -14.932, 0.0} };
	std::vector<std::vector<float>> ST2B = { { -6.288, -14.932, 0.0}, {-7.16, -12.66, 0.0} };
	std::vector<std::vector<float>> ST2C = { {-7.16, -12.66, 0.0},  { -4.75, -11.66, 0.0 } };
	std::vector<std::vector<float>> ST2D = { { -4.75, -11.66, 0.0 }, {-2.36, 0.06, 0.0} };            //Just Pink Colour
	std::vector<std::vector<float>> ST2E = { {-2.36, 0.06, 0.0}, {-4.06, 0.42, 0.0} };
	float CTRL2A[4][2] = { {-4.06, 0.42}, { -6.8, -2.6}, { -8, -4.16}, { -13.4, -11.1} };
	float CTRL2B[4][2] = { { -13.4, -11.1}, {-11.6, -13.97}, {-10.86, -14.88}, {-8.28, -17.05} };
	PolygonElement* p2[7] = { new StraightLine(ST2A[0], ST2A[1]), new StraightLine(ST2B[0], ST2B[1]), new StraightLine(ST2C[0], ST2C[1]), new StraightLine(ST2D[0], ST2D[1]),new StraightLine(ST2E[0], ST2E[1]),new CubicBezierCurve(CTRL2A), new CubicBezierCurve(CTRL2B) };
	POLYGONS[1] = new IrregularPolygon(p2, 7);
	POLYGONS[1]->normalizeControlPoints(maxX, maxY, minX, minY);
	bodyPartRenderers[4] = new Renderer(POLYGONS[1], *shaderArray[5], *shaderArray[0]);


	std::cout << i++ << "\n";


	//[Right Hand] 
	float CTRL3A[4][2] = { {20.905, 0.775}, { 25.3, -0.8}, { 26.75, -6.9}, {28.1, -11.9} };
	float CTRL3B[4][2] = { {28.1, -11.9}, { 27.37, -13.09}, { 25.5, -14.58}, { 24.112, -15.094} };
	std::vector<std::vector<float>> ST3A = { { 24.112, -15.094, 0.0}, {22.13, -13.373, 0.0} };
	std::vector<std::vector<float>> ST3B = { {22.13, -13.373, 0.0}, { 23.36, -11, 0.0} };
	float CTRL3C[4][2] = { { 23.36, -11}, { 22.2, -6.75}, { 20.65, -10.23}, { 20.42, -9.657} };
	std::vector<std::vector<float>> ST3C = { { 20.42, -9.657, 0.0}, {18.76, 0.06, 0.0} };
	std::vector<std::vector<float>> ST3D = { {18.76, 0.06, 0.0}, {20.905, 0.775, 0.0} };
	PolygonElement* p3[7] = { new CubicBezierCurve(CTRL3A) ,new CubicBezierCurve(CTRL3B) , new StraightLine(ST3A[0], ST3A[1]), new StraightLine(ST3B[0], ST3B[1]), new CubicBezierCurve(CTRL3C), new StraightLine(ST3C[0], ST3C[1]), new StraightLine(ST3D[0], ST3D[1]) };
	POLYGONS[2] = new IrregularPolygon(p3, 7);
	POLYGONS[2]->normalizeControlPoints(maxX, maxY, minX, minY);
	bodyPartRenderers[7] = new Renderer(POLYGONS[2], *shaderArray[5], *shaderArray[0]);

	std::cout << i++ << "\n";

	//[GLOVE] – 
	std::vector<std::vector<float>> ST4A = { {22.13, -13.373, 0.0}, { 24.112, -15.094, 0.0} };
	std::vector<std::vector<float>> ST4B = { { 24.112, -15.094, 0.0}, { 22.97, -15.62, 0.0} };
	std::vector<std::vector<float>> ST4C = { { 22.97, -15.62, 0.0} ,  { 21.75, -14.08, 0.0} };
	std::vector<std::vector<float>> ST4D = { { 21.75, -14.08, 0.0}, {22.13, -13.373, 0.0} };

	PolygonElement* p4[4] = { new StraightLine(ST4A[0], ST4A[1]), new StraightLine(ST4B[0], ST4B[1]), new StraightLine(ST4C[0], ST4C[1]),
	new StraightLine(ST4D[0], ST4D[1]) };

	POLYGONS[3] = new IrregularPolygon(p4, 4);

	POLYGONS[3]->normalizeControlPoints(maxX, maxY, minX, minY);

	bodyPartRenderers[30] = new Renderer(POLYGONS[3], *shaderArray[1], *shaderArray[0]);

	std::cout << i++ << "\n";


	// arm border transparent 8, 9

	std::vector<std::vector<float>> ST1000 = { { -4.75, -11.66, 0.0 }, {-2.36, 0.06, 0.0} };
	PolygonElement* p1000[1] = { new StraightLine(ST1000[0], ST1000[1])};
	POLYGONS[113] = new IrregularPolygon(p1000, 1);
	POLYGONS[113]->normalizeControlPoints(maxX, maxY, minX, minY);
	bodyPartRenderers[8] = new Renderer(POLYGONS[113], *shaderArray[5], *shaderArray[5]);

	std::vector<std::vector<float>> ST1001 = { { 20.42, -9.657, 0.0}, {18.76, 0.06, 0.0} };
	PolygonElement* p1001[1] = { new StraightLine(ST1001[0], ST1001[1]) };
	POLYGONS[114] = new IrregularPolygon(p1001, 1);
	POLYGONS[114]->normalizeControlPoints(maxX, maxY, minX, minY);
	bodyPartRenderers[9] = new Renderer(POLYGONS[114], *shaderArray[5], *shaderArray[5]);


	//Ear 1
	std::vector<std::vector<float>> ST5A = { {21.6, 24.21,0.0}, {16.0, 17.3, 0.0} };
	std::vector<std::vector<float>> ST5B = { {16.0, 17.3, 0.0}, {20.9, 15.5, 0.0} };
	std::vector<std::vector<float>> ST5C = { {20.9, 15.5, 0.0}, {21.6, 24.21,0.0} };

	PolygonElement* p5[3] = { new StraightLine(ST5A[0], ST5A[1]), new StraightLine(ST5B[0], ST5B[1]),
	new StraightLine(ST5C[0], ST5C[1]) };

	POLYGONS[4] = new IrregularPolygon(p5, 3);
	POLYGONS[4]->normalizeControlPoints(maxX, maxY, minX, minY);
	bodyPartRenderers[0] = new Renderer(POLYGONS[4], *shaderArray[5], *shaderArray[0]);
	std::cout << i++ << "\n";

	//Ear 2
	std::vector<std::vector<float>> ST6A = { {-8.5, 24.9, 0.0}, {-7.9, 15.27, 0.0} };
	std::vector<std::vector<float>> ST6B = { {-7.9, 15.27, 0.0}, {-2.62, 17.2, 0.0} };
	std::vector<std::vector<float>> ST6C = { {-2.62, 17.2, 0.0}, {-8.5, 24.9,0.0} };

	PolygonElement* p6[3] = { new StraightLine(ST6A[0], ST6A[1]), new StraightLine(ST6B[0], ST6B[1]), new StraightLine(ST6C[0], ST6C[1]) };

	POLYGONS[5] = new IrregularPolygon(p6, 3);
	POLYGONS[5]->normalizeControlPoints(maxX, maxY, minX, minY);
	bodyPartRenderers[1] = new Renderer(POLYGONS[5], *shaderArray[5], *shaderArray[0]);

	std::cout << i++ << "\n";

	std::vector<std::vector<float>> ST54C = { {-7.9, 15.27, 0.0}, {-2.62, 17.2, 0.0} };
	PolygonElement* p54[1] = { new StraightLine(ST54C[0], ST54C[1]) };

	POLYGONS[54] = new IrregularPolygon(p54, 1);	//ONLY skin BORDER...
	POLYGONS[54]->normalizeControlPoints(maxX, maxY, minX, minY);
	bodyPartRenderers[24] = new Renderer(POLYGONS[54], *shaderArray[2], *shaderArray[2]);
	std::cout << i++ << "\n";

	std::vector<std::vector<float>> ST55C = { {16.0, 17.3, 0.0}, {20.9, 15.5, 0.0} };
	PolygonElement* p55[1] = { new StraightLine(ST55C[0], ST55C[1]) };

	POLYGONS[55] = new IrregularPolygon(p55, 1);	//ONLY skin BORDER...
	POLYGONS[55]->normalizeControlPoints(maxX, maxY, minX, minY);
	bodyPartRenderers[25] = new Renderer(POLYGONS[55], *shaderArray[2], *shaderArray[2]);
	std::cout << i++ << "\n";



	// Starting Fresh-
	// Head:  [Face Structure]
	// 

	float CTRL7A[4][2] = { {-2.62, 17.2}, {2.2, 19.9}, {10.8, 19.6}, {16, 17.3} };
	std::vector<std::vector<float>> ST7A = { {16.0, 17.3, 0.0}, { 20.9, 15.5, 0.0 } };
	float CTRL7B[4][2] = { { 20.9, 15.5 }, {31.1, 9.9}, { 25.3, -0.8 }, { 15.46, 0.0 } };
	std::vector<std::vector<float>> ST7B = { { 15.46, 0.0 , 0.0 }, { 10.547, 0.264, 0.0 } };
	float CTRL7C[4][2] = { { 10.547, 0.264 }, { 8.07, -1.3 }, { 5.8, -1.27 }, { 3, 0.35 } };
	std::vector<std::vector<float>> ST7C = { { 3, 0.35 , 0.0}, { -2.36, 0.06 , 0.0} };
	float CTRL7D[4][2] = { { -2.36, 0.06 }, { -16.1, 2.4 }, { -12.2, 13.4 }, { -7.9, 15.27} };
	std::vector<std::vector<float>> ST7D = { { -7.9, 15.27, 0.0}, {-2.62, 17.2, 0.0} };

	PolygonElement* p7[8] = { new CubicBezierCurve(CTRL7A), new StraightLine(ST7A[0], ST7A[1]), new CubicBezierCurve(CTRL7B), new StraightLine(ST7B[0], ST7B[1]), new CubicBezierCurve(CTRL7C), new StraightLine(ST7C[0], ST7C[1]), new CubicBezierCurve(CTRL7D), new StraightLine(ST7D[0], ST7D[1]) };

	POLYGONS[6] = new IrregularPolygon(p7, 8);
	POLYGONS[6]->normalizeControlPoints(maxX, maxY, minX, minY);
	bodyPartRenderers[6] = new Renderer(POLYGONS[6], *shaderArray[5], *shaderArray[0]);

	std::cout << i++ << "\n";

	std::vector<std::vector<float>> ST1002 = { {-7.9, 15.27, 0.0}, {-2.62, 17.2, 0.0} };
	PolygonElement* p1002[1] = { new StraightLine(ST1002[0], ST1002[1]) };
	POLYGONS[115] = new IrregularPolygon(p1002, 1);
	POLYGONS[115]->normalizeControlPoints(maxX, maxY, minX, minY);
	bodyPartRenderers[26] = new Renderer(POLYGONS[115], *shaderArray[5], *shaderArray[5]);

	std::vector<std::vector<float>> ST1003 = { {16.0, 17.3, 0.0}, {20.9, 15.5, 0.0} };
	PolygonElement* p1003[1] = { new StraightLine(ST1003[0], ST1003[1]) };
	POLYGONS[116] = new IrregularPolygon(p1003, 1);
	POLYGONS[116]->normalizeControlPoints(maxX, maxY, minX, minY);
	bodyPartRenderers[27] = new Renderer(POLYGONS[116], *shaderArray[5], *shaderArray[5]);

	// black

	float CTRL1005[4][2] = { { -5.67, -19.027 }, { -5.47, -16.26 }, { -5.57, -14.46 }, { -3.47, -5.7} };
	PolygonElement* p1005[1] = { new CubicBezierCurve( CTRL1005 ) };
	POLYGONS[115] = new IrregularPolygon(p1005, 1);
	POLYGONS[115]->normalizeControlPoints(maxX, maxY, minX, minY);
	bodyPartRenderers[28] = new Renderer(POLYGONS[115], *shaderArray[0], *shaderArray[0]);

	float CTRL1006[4][2] = { { 19.8, -6.2 }, { 20.38, -9.03 }, { 20.65, -10.23 }, { 20.5, -13.8} };
	PolygonElement* p1006[1] = { new CubicBezierCurve( CTRL1006 ) };
	POLYGONS[116] = new IrregularPolygon(p1006, 1);
	POLYGONS[116]->normalizeControlPoints(maxX, maxY, minX, minY);
	bodyPartRenderers[29] = new Renderer(POLYGONS[116], *shaderArray[0], *shaderArray[0]);
	

	// 7-th Body allocate aro 8th also

	// BODY CODE BEGINS!
	// COLOR SKIN COLOR
	std::vector<std::vector<float>> ST120A = { {-3.47, -5.7, 0.0}, { -3.1, 6.8, 0.0 } };
	std::vector<std::vector<float>> ST121A = { {-3.1, 6.8, 0.0}, { 18.1, 6.93, 0.0} };
	std::vector<std::vector<float>> ST122A = { { 18.1, 6.93, 0.0}, { 19.8, -6.2, 0.0} };
	PolygonElement* p120[3] = { new StraightLine(ST120A[0], ST120A[1]), new StraightLine(ST121A[0], ST121A[1]), new StraightLine(ST122A[0], ST122A[1])};
	POLYGONS[86] = new IrregularPolygon(p120, 3);
	POLYGONS[86]->normalizeControlPoints(maxX, maxY, minX, minY);
	bodyPartRenderers[3] = new Renderer(POLYGONS[86], *shaderArray[5], *shaderArray[5]);



	std::vector<std::vector<float>> ST123A = { {-3.47, -5.7, 0.0}, { -3.1, 6.8, 0.0 } };
	std::vector<std::vector<float>> ST124A = { {-3.1, 6.8, 0.0}, { 18.1, 6.93, 0.0} };
	std::vector<std::vector<float>> ST125A = { { 18.1, 6.93, 0.0}, { 19.8, -6.2, 0.0} };
	float CTRL121[4][2] = { { 19.8, -6.2 }, { 20.38, -9.03 }, { 20.65, -10.23 }, { 20.5, -13.8} };
	std::vector<std::vector<float>> ST126A = { { 20.5, -13.8, 0.0}, { 18.43, -18.994, 0.0} };
	float CTRL122[4][2] = { { 18.43, -18.994 }, { 10.32, -19.13 }, { 6.36, -19.44 }, { -5.67, -19.027} };
	float CTRL123[4][2] = { { -5.67, -19.027 }, { -5.47, -16.26 }, { -5.57, -14.46 }, { -3.47, -5.7} };

	PolygonElement* p121[7] = { new StraightLine(ST123A[0], ST123A[1]), new StraightLine(ST124A[0], ST124A[1]), new StraightLine(ST125A[0], ST125A[1]), new CubicBezierCurve(CTRL121), new StraightLine(ST126A[0], ST126A[1]), new CubicBezierCurve(CTRL122), new CubicBezierCurve(CTRL123) };
	POLYGONS[85] = new IrregularPolygon(p121, 7);
	POLYGONS[85]->normalizeControlPoints(maxX, maxY, minX, minY);
	bodyPartRenderers[2] = new Renderer(POLYGONS[85], *shaderArray[5], *shaderArray[0]);
	// BODY CODE ENDS!


	//[Nose]
	float CTRL9A[4][2] = { {4.42, 0.98},  {-9.5, -5.58},  { -4.8, 14.95},  {4.5, 7.9} };
	float CTRL9B[4][2] = { {4.5, 7.9},  { 7.28, 4.94 }, { 6.12, 3.9 }, { 9.502, 7.998 } };
	float CTRL9C[4][2] = { { 9.502, 7.998 }, { 18.55, 14.52 },  { 21.05, -5.84 }, { 9.28, 0.91 } };
	float CTRL9D[4][2] = { {9.28, 0.91}, {7.4, 2.08}, {5.93,  1.86}, {4.42, 0.98} };

	PolygonElement* p10[4] = { new CubicBezierCurve(CTRL9A), new CubicBezierCurve(CTRL9B), new CubicBezierCurve(CTRL9C), new CubicBezierCurve(CTRL9D) };

	POLYGONS[9] = new IrregularPolygon(p10, 4);
	POLYGONS[9]->normalizeControlPoints(maxX, maxY, minX, minY);
	bodyPartRenderers[19] = new Renderer(POLYGONS[9], *shaderArray[5], *shaderArray[0]);
	std::cout << i++ << "\n";

	//[Nose – Left Circle]
	float c1 [3] = { 0.7f, 4.3f, 0.0f };
	POLYGONS[10] = new RegularPolygon(c1, 2.1, 500);
	POLYGONS[10]->normalizeControlPoints(maxX, maxY, minX, minY);
	bodyPartRenderers[20] = new Renderer(POLYGONS[10], *shaderArray[4], *shaderArray[0]);
	std::cout << i++ << "\n";

	//[Nose – Right Circle]
	float c2[3] =  { 12.7f, 4.3f, 0.0 };
	POLYGONS[11] = new RegularPolygon(c2, 1.2, 500);
	POLYGONS[11]->normalizeControlPoints(maxX, maxY, minX, minY);
	bodyPartRenderers[21] = new Renderer(POLYGONS[11], *shaderArray[4], *shaderArray[0]);
	std::cout << i++ << "\n";
	//[Eye – Left] 
	float c3[3] = { -3.0f, 11.5f, 0.0 };
	POLYGONS[12] = new RegularPolygon(c3, 1.4, 500);
	POLYGONS[12]->normalizeControlPoints(maxX, maxY, minX, minY);
	bodyPartRenderers[22] = new Renderer(POLYGONS[12], *shaderArray[0], *shaderArray[0]);
	std::cout << i++ << "\n";
	//[Eye – Right] 
	float c4[3] = { 17.0f, 11.0f, 0.0 };
	POLYGONS[13] = new RegularPolygon(c4, 1.7, 500);
	POLYGONS[13]->normalizeControlPoints(maxX, maxY, minX, minY);
	bodyPartRenderers[23] = new Renderer(POLYGONS[13], *shaderArray[0], *shaderArray[0]);
	std::cout << i++ << "\n";


	//[ Left Eyebrow ]
	float CTRL10A[4][2] = { {1.73, 12.98}, {  3.67, 12.2 }, { 2.1, 11.69 }, { 1.48, 12.08 } };
	std::vector<std::vector<float>> ST10A = { { 1.48, 12.08, 0.0 }, { -5.82, 14.23 , 0.0} };
	float CTRL10B[4][2] = { { -5.82, 14.23 }, { -7.103, 14.67 }, { -6.135, 16.55}, { -5.21, 16.16} };
	std::vector<std::vector<float>> ST10B = { {-5.21, 16.16, 0.0}, {1.73, 12.98, 0.0} };

	PolygonElement* p15[4] = { new CubicBezierCurve(CTRL10A), new StraightLine(ST10A[0], ST10A[1]), new CubicBezierCurve(CTRL10B), new StraightLine(ST10B[0], ST10B[1]) };

	POLYGONS[14] = new IrregularPolygon(p15, 4);
	POLYGONS[14]->normalizeControlPoints(maxX, maxY, minX, minY);
	bodyPartRenderers[24] = new Renderer(POLYGONS[14], *shaderArray[0], *shaderArray[0]);

	std::cout << i++ << "\n";


	//[Right Eyebrow] 
	float CTRL11A[4][2] = { {13.1, 11.3}, {12.1, 10.49}, {11.62, 11.77}, {12.3, 12.1} };
	std::vector<std::vector<float>> ST11A = { {12.3, 12.1, 0.0}, {16.72, 15.582, 0.0} };
	float CTRL11B[4][2] = { {16.72, 15.582}, {17.88, 16.95}, { 19.65, 16.03}, { 18.78, 14.96} };
	std::vector<std::vector<float>> ST11B = { { 18.78, 14.96, 0.0}, {13.1, 11.32 , 0.0} };
	PolygonElement* p16[4] = { new CubicBezierCurve(CTRL11A), new StraightLine(ST11A[0], ST11A[1]), new CubicBezierCurve(CTRL11B), new StraightLine(ST11B[0], ST11B[1]) };

	POLYGONS[15] = new IrregularPolygon(p16, 4);
	POLYGONS[15]->normalizeControlPoints(maxX, maxY, minX, minY);
	bodyPartRenderers[25] = new Renderer(POLYGONS[15], *shaderArray[0], *shaderArray[0]);


	std::cout << i++ << "\n";

	float CTRL50A[4][2] = { { -5.25, -35.9 }, { -14.1, -37.55 }, { 3.2, -39.83}, { -2, -35.6 } };
	std::vector<std::vector<float>> ST50F = { {-2, -35.6, 0.0}, {  -5.25, -35.9, 0.0  } };
	PolygonElement* p50[2] = { new CubicBezierCurve(CTRL50A), new StraightLine(ST50F[0], ST50F[1]) };

	POLYGONS[50] = new IrregularPolygon(p50, 2);
	POLYGONS[50]->normalizeControlPoints(maxX, maxY, minX, minY);
	bodyPartRenderers[11] = new Renderer(POLYGONS[50], *shaderArray[3], *shaderArray[0]);
	std::cout << i++ << "\n";

	float CTRL51A[4][2] = { { 15.53, -35.5}, { 11.34, -39.7 }, { 27.6, -37.17}, { 19.2, -35.6} };
	std::vector<std::vector<float>> ST51F = { {19.2, -35.6, 0.0}, {  15.53, -35.5, 0.0  } };
	PolygonElement* p51[2] = { new CubicBezierCurve(CTRL51A), new StraightLine(ST51F[0], ST51F[1]) };

	POLYGONS[51] = new IrregularPolygon(p51, 2);
	POLYGONS[51]->normalizeControlPoints(maxX, maxY, minX, minY);
	bodyPartRenderers[12] = new Renderer(POLYGONS[51], *shaderArray[3], *shaderArray[0]);
	std::cout << i++ << "\n";

	std::vector<std::vector<float>> ST52A = { { -2, -35.6, 0.0 } , {7.71, -27.75, 0.0} };
	std::vector<std::vector<float>> ST52B = { {7.71, -27.75, 0.0}, { 15.53, -35.5, 0.0} };
	std::vector<std::vector<float>> ST52C = { {15.53, -35.5, 0.0}, { -2, -35.6, 0.0   } };
	PolygonElement* p52[3] = { new StraightLine(ST52A[0], ST52A[1]) , new StraightLine(ST52B[0], ST52B[1]), new StraightLine(ST52C[0], ST52C[1]) };

	POLYGONS[52] = new IrregularPolygon(p52, 3);
	POLYGONS[52]->normalizeControlPoints(maxX, maxY, minX, minY);
	bodyPartRenderers[13] = new Renderer(POLYGONS[52], *shaderArray[8], *shaderArray[0]);
	std::cout << i++ << "\n";

	std::vector<std::vector<float>> ST53C = { {15.53, -35.5, 0.0}, { -2, -35.6, 0.0   } };
	PolygonElement* p53[1] = { new StraightLine(ST53C[0], ST53C[1]) };

	POLYGONS[53] = new IrregularPolygon(p53, 1);	//ONLY WHITE BORDER...
	POLYGONS[53]->normalizeControlPoints(maxX, maxY, minX, minY);
	bodyPartRenderers[14] = new Renderer(POLYGONS[53], *shaderArray[8], *shaderArray[8]);
	std::cout << i++ << "\n";
	// TESELLATED PANTS |^^^

	//[PANT]
	float CTRL12A[4][2] = { {-5.67, -19.027}, { -6.2, -23.0}, { -5.0, -31.46 }, { -5.25, -35.9 } };
	std::vector<std::vector<float>> ST12F = { {  -5.25, -35.9, 0.0  } , {-2, -35.6, 0.0} };
	std::vector<std::vector<float>> ST12A = { { -2, -35.6, 0.0 } , {7.71, -27.75, 0.0} };
	std::vector<std::vector<float>> ST12B = { {7.71, -27.75, 0.0}, { 15.53, -35.5, 0.0} };
	std::vector<std::vector<float>> ST12M = { {15.53, -35.5, 0.0}, { 19.2, -35.6, 0.0} };
	//float CTRL12C[4][2] = { { 15.53, -35.5}, { 11.34, -39.7 }, { 27.6, -37.17}, { 19.2, -35.6} };
	float CTRL12D[4][2] = { { 19.2, -35.6}, { 19.9, -30.05}, { 19.8, -26.57}, { 20.56, -19.676} };
	std::vector<std::vector<float>> ST12C = { { 20.56, -19.676, 0.0}, { 18.43, -18.995, 0.0} };
	float CTRL12E[4][2] = { { 18.43, -18.995}, {10.32, -19.13}, {6.36, -19.44}, {-5.67, -19.027} };

	PolygonElement* p17[8] = { new CubicBezierCurve(CTRL12A), new StraightLine(ST12F[0], ST12F[1]), new StraightLine(ST12A[0], ST12A[1]), new StraightLine(ST12B[0], ST12B[1]), new StraightLine(ST12M[0], ST12M[1]), new CubicBezierCurve(CTRL12D), new StraightLine(ST12C[0], ST12C[1]), new CubicBezierCurve(CTRL12E)};

	POLYGONS[16] = new IrregularPolygon(p17, 8);
	POLYGONS[16]->normalizeControlPoints(maxX, maxY, minX, minY);
	bodyPartRenderers[10] = new Renderer(POLYGONS[16], *shaderArray[3], *shaderArray[0]);
	std::cout << i++ << "\n";

	//[SWORD]
	//(Circular Disk)
	float CTRL13A[4][2] = { {18.77, -15.25}, { 20.8, -11.9},  {23.58, -15.13},  { 23.11, -17.11} };
	std::vector<std::vector<float>> ST13A = { { 23.11, -17.11, 0.0}, { 22.4, -18.755, 0.0} };
	float CTRL13B[4][2] = { { 22.4, -18.755},  { 18.54, -21.58},  {17.5, -17.7},  {18.13, -16.89} };
	std::vector<std::vector<float>> ST13B = { { 18.13, -16.89, 0.0}, {18.77, -15.25, 0.0} };

	PolygonElement* p18[4] = { new CubicBezierCurve(CTRL13A), new StraightLine(ST13A[0], ST13A[1]), new CubicBezierCurve(CTRL13B), new StraightLine(ST13B[0], ST13B[1]) };

	POLYGONS[17] = new IrregularPolygon(p18, 4);
	POLYGONS[17]->normalizeControlPoints(maxX, maxY, minX, minY);
	bodyPartRenderers[15] = new Renderer(POLYGONS[17], *shaderArray[9], *shaderArray[0]);
	std::cout << i++ << "\n";

	//(Top End)
	float CTRL14A[4][2] = { {13.44, -15}, {13.08, -14.11}, { 13.57, -13.5},  {14, -13.2} };
	float CTRL14B[4][2] = { {14, -13.2}, { 14.41, -13.31},  { 14.05, -15.03}, {13.44, -15} };
	PolygonElement* p78[2] = { new CubicBezierCurve(CTRL14A), new CubicBezierCurve(CTRL14B) };

	POLYGONS[78] = new IrregularPolygon(p78, 2);
	POLYGONS[78]->normalizeControlPoints(maxX, maxY, minX, minY);
	bodyPartRenderers[16] = new Renderer(POLYGONS[78], *shaderArray[2], *shaderArray[0]);


	std::vector<std::vector<float>> ST14A = { {14, -13.2, 0.0}, {21.25,-16.3, 0.0} };
	float CTRL14C[4][2] = { {21.25,-16.3}, { 21.68,  -16.99}, { 21.27, -17.81}, { 20.7, -17.93} };
	std::vector<std::vector<float>> ST14B = { { 20.7, -17.93, 0.0},  { 13.44, -15, 0.0 } };
	float CTRL14E[4][2] = {  {13.44, -15}, { 14.05, -15.03}, { 14.41, -13.31}, {14, -13.2} };
	PolygonElement* p19[4] = {  new StraightLine(ST14A[0], ST14A[1]), new CubicBezierCurve(CTRL14C), new StraightLine(ST14B[0], ST14B[1]), new CubicBezierCurve(CTRL14E)};

	POLYGONS[18] = new IrregularPolygon(p19, 4);
	POLYGONS[18]->normalizeControlPoints(maxX, maxY, minX, minY);
	bodyPartRenderers[17] = new Renderer(POLYGONS[18], *shaderArray[2], *shaderArray[0]);
	std::cout << i++ << "\n";

	//( Lower End) 
	std::vector<std::vector<float>> ST15A = { {23.11, -17.11, 0.0}, {  37.6, -23.34, 0.0} };
	float CTRL15[4][2] = { {  37.6, -23.34} ,  { 39.2, -24.6}, { 37.87, -25.2}, { 37.05, -24.896} };
	std::vector<std::vector<float>> ST15B = { { 37.05, -24.896, 0.0}, { 22.4, -18.75, 0.0} };
	std::vector<std::vector<float>> ST15C = { { 22.4, -18.75, 0.0}, { 23.11,  -17.11, 0.0} };

	PolygonElement* p20[4] = { new StraightLine(ST15A[0], ST15A[1]), new CubicBezierCurve(CTRL15), new StraightLine(ST15B[0], ST15B[1]), new StraightLine(ST15C[0], ST15C[1]) };

	POLYGONS[19] = new IrregularPolygon(p20, 4);
	POLYGONS[19]->normalizeControlPoints(maxX, maxY, minX, minY);
	bodyPartRenderers[18] = new Renderer(POLYGONS[19], *shaderArray[6], *shaderArray[0]);
	std::cout << i++ << "\n";

	return bodyPartRenderers;
}



