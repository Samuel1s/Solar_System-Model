#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <GL/glew.h>
#include <GL/freeglut.h>

#ifndef VARIAVEIS_H
#define VARIAVEIS_H

/******************************************************************************
                        VARIAVEIS DO PROJETO
*******************************************************************************/

#define P_ROTACAO	5.0
#define P_OBSERVACAO	10.0
#define P_TRANSLACAO	10.0

int width = 10;
int height = 10;
int length = 10;

// Carrega Texturas.
GLuint lista_texturas[20];

// Ângulo da projeção perspectiva
GLfloat angulo_projecao_persp;

// Função Aspecto - Ajuste.
GLfloat funcao_aspecto;

// Esquema de Rotação do Sistema.
GLfloat rotacao_inicial_eixo_X, rotacao_inicial_eixo_Y;
GLfloat rotacao_eixo_X, rotacao_eixo_Y, rotacao_eixo_Z;

// Posicao do observador.
GLfloat eixo_inicial_observador_em_X, eixo_inicial_observador_em_Y, eixo_inicial_observador_em_Z;
GLfloat observador_virtual_eixo_X, observador_virtual_eixo_Y, observador_virtual_eixo_Z;

// Componentes de Iluminação Phong e parametros de iluminação do material.
GLfloat iluminacao_ambiente[] = {0, 0, 0, 1.0};
GLfloat iluminacao_difusa[] = {0, 0, 0, 1.0};
GLfloat iluminacao_especular[] = {0, 0, 0, 1.0};
GLfloat iluminacao_emissiva[] = {1.0, 0.0, 0.0, 1.0};

const GLfloat iluminacao_objeto_ambiente[] = {0.7f, 0.7f, 0.7f, 1.0f};
const GLfloat iluminacao_objeto_difusa[] = {0.8f, 0.8f, 0.8f, 1.0f};
const GLfloat iluminacao_objeto_especular[] = {1.0f, 1.0f, 1.0f, 1.0f};
const GLfloat alto_brilho[] = {100.0f};

// Flags de controle e inicializacao.
int posicao_inicial_x, posicao_inicial_y;
int flag_botao_mouse_pressionado;
int flag_ativacao_sol = 1;
int flag_ativacao_orbita = 1;


#endif 