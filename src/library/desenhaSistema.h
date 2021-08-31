#ifndef SISTEMA_H
#define SISTEMA_H
void desenha_Planeta(char *planeta, GLuint textura[], float pos_y, float pos_x, float escala,float diametro,float raio);
void desenha_Orbita(float pos_y,float pos_x);
void desenha_Planetas_com_Satelites(char *planeta, GLuint textura1[], GLuint textura2[],float pos_y, float pos_x, float escala,float diametro1,float diametro2,float raio,float raio_lua);
void desenha_Planetas_com_Satelites_e_Aneis(char *planeta, GLuint textura1[], GLuint textura2[],GLuint textura3[],float pos_y, float pos_x, float escala,float diametro1,float diametro2,float raio,float raio_lua);
void desenha_Anel(float x, float y);
#endif