#include <GL/glut.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include "std_image.h"

using namespace std;

GLuint texture; // хранит id текстуры

void loadTexture(const char* filename) {
    int width, height, nrChannels;
    unsigned char* data = stbi_load(filename, &width, &height, &nrChannels, 0);
    if (data) {
        glGenTextures(1, &texture); // генерируем id текстуры
        glBindTexture(GL_TEXTURE_2D, texture); // устанавливаем текстуру
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        stbi_image_free(data); // освобождаем память
    }
    else {
        std::cout << "Failed to load texture" << std::endl;
    }
}

void drawSquare() {
    glEnable(GL_TEXTURE_2D); // включаем текстурирование
    glBindTexture(GL_TEXTURE_2D, texture); // устанавливаем текстуру
    //1
    glBegin(GL_TRIANGLES); // начинаем рисовать четырехугольник
    glTexCoord2f(0.0f, 0.0f);    glVertex3f(0.2, 0.4, 0.0);
    glTexCoord2f(1.0f, 0.0f);    glVertex3f(0.6, 0.4, 0.0);
    glTexCoord2f(1.0f, 1.0f);    glVertex3f(0.4, 0.6, 0.0);
    glTexCoord2f(0.0f, 1.0f);    glVertex3f(0.2, 0.8, 0.0);
    glTexCoord2f(0.0f, 0.0f);    glVertex3f(0.6, 0.8, 0.0);
    glTexCoord2f(1.0f, 0.0f);    glVertex3f(0.4, 0.6, 0.0);
    glEnd();
    //низ
    glBegin(GL_QUADS); // начинаем рисовать четырехугольник
    glTexCoord2f(0.0f, 0.0f);    glVertex3f(0.2, 0.8, 0.0);
    glTexCoord2f(1.0f, 0.0f);    glVertex3f(0.6, 0.8, 0.0);
    glTexCoord2f(1.0f, 1.0f);    glVertex3f(0.6, 0.8, 0.3);
    glTexCoord2f(0.0f, 1.0f);    glVertex3f(0.2, 0.8, 0.3);
    glEnd();
    //верх
    glBegin(GL_QUADS); // начинаем рисовать четырехугольник
    glTexCoord2f(0.0f, 0.0f);    glVertex3f(0.2, 0.4, 0.0);
    glTexCoord2f(1.0f, 0.0f);    glVertex3f(0.6, 0.4, 0.0);
    glTexCoord2f(1.0f, 1.0f);    glVertex3f(0.6, 0.4, 0.3);
    glTexCoord2f(0.0f, 1.0f);    glVertex3f(0.2, 0.4, 0.3);
    glEnd();
    //левониз
    glBegin(GL_QUADS); // начинаем рисовать четырехугольник
    glTexCoord2f(0.0f, 0.0f);    glVertex3f(0.2, 0.4, 0.0);
    glTexCoord2f(1.0f, 0.0f);    glVertex3f(0.2, 0.4, 0.3);
    glTexCoord2f(1.0f, 1.0f);    glVertex3f(0.4, 0.6, 0.3);
    glTexCoord2f(0.0f, 1.0f);    glVertex3f(0.4, 0.6, 0.0);
    glEnd();
    //левоверх
    glBegin(GL_QUADS); // начинаем рисовать четырехугольник
    glTexCoord2f(0.0f, 0.0f);    glVertex3f(0.4, 0.6, 0.0);
    glTexCoord2f(1.0f, 0.0f);    glVertex3f(0.4, 0.6, 0.3);
    glTexCoord2f(1.0f, 1.0f);    glVertex3f(0.2, 0.8, 0.3);
    glTexCoord2f(0.0f, 1.0f);    glVertex3f(0.2, 0.8, 0.0);
    glEnd();
    //правониз
    glBegin(GL_QUADS); // начинаем рисовать четырехугольник
    glTexCoord2f(0.0f, 0.0f);    glVertex3f(0.6, 0.4, 0.0);
    glTexCoord2f(1.0f, 0.0f);    glVertex3f(0.6, 0.4, 0.3);
    glTexCoord2f(1.0f, 1.0f);    glVertex3f(0.4, 0.6, 0.3);
    glTexCoord2f(0.0f, 1.0f);    glVertex3f(0.4, 0.6, 0.0);
    glEnd();
    //право верх
    glBegin(GL_QUADS); // начинаем рисовать четырехугольник
    glTexCoord2f(0.0f, 0.0f);    glVertex3f(0.4, 0.6, 0.0);
    glTexCoord2f(1.0f, 0.0f);    glVertex3f(0.4, 0.6, 0.3);
    glTexCoord2f(1.0f, 1.0f);    glVertex3f(0.6, 0.8, 0.3);
    glTexCoord2f(0.0f, 1.0f);    glVertex3f(0.6, 0.8, 0.0);
    glEnd();
    glDisable(GL_TEXTURE_2D); // выключаем текстурирование
}

void display() {
    while(true){
    glClear(GL_COLOR_BUFFER_BIT); // очищаем буфер
    glTranslated(0.4, 0.6, 0.15);
    glRotated(0.1, 0.1, 1, 0);  // аним 2 вращение вокрук Y
    glTranslated(-0.4, -0.6, -0.15);
    drawSquare(); // рисуем квадрат
    glutSwapBuffers(); // обновляем экран
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(10, 20);
    glutCreateWindow("OpenGL texture example");
    glutDisplayFunc(display);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    loadTexture("textur.jpg"); // загружаем текстуру
    glutMainLoop();
    return 0;
}
