
#include "./library/header.h"

// Util para nao precisar gerar os .o
#include "teclado.c"
#include "inicializa.c"
#include "criaSistema.c"
#include "movimentacao.c"
#include "desenhaSistema.c"
#include "carregaTexturas.c"

// FONTE: http://www.inf.pucrs.br/~manssour/OpenGL/TeaPot3D.c 

void PosicionaObservador(void)
{
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  // Posiciona a camera e orienta o observador
  glTranslatef(-observador_virtual_eixo_X * 0.5, -observador_virtual_eixo_Y * 0.5, -observador_virtual_eixo_Z * 0.5);
  glRotatef(rotacao_eixo_X, 1, 0, 0);
  glRotatef(rotacao_eixo_Y, 0, 1, 0);
  glRotatef(rotacao_eixo_Z, 0, 0, 1);
}

void EspecificaParametrosVisualizacao(void)
{
  // Especifica sistema de coordenadas de projeção
  glMatrixMode(GL_PROJECTION);
  // Inicializa sistema de coordenadas de projeção
  glLoadIdentity();
  // Especifica a projeção perspectiva(angulo_projecao_persp,aspecto,zMin,zMax)
  gluPerspective(angulo_projecao_persp, funcao_aspecto, 0.5, 2000);
  PosicionaObservador();
}

void Redimensiona(GLsizei w, GLsizei h)
{
  // Para previnir uma divisão por zero
  if (h == 0)
    h = 1;

  // Especifica as dimensões da viewport
  glViewport(0, 0, w, h);

  // Calcula a correção de aspecto
  funcao_aspecto = (GLfloat)w / (GLfloat)h;

  EspecificaParametrosVisualizacao();
}

static void atualiza(void)
{
  glutPostRedisplay();
}

void imprimeGuia()
{
  printf("  ------------------------------- GUIA -----------------------------\n");
  printf("  SETAS (^,v): Aumentar ou diminuir ou zoom  \n");
  printf("  SETAS (>,<): Rotaciona o sistema solar  \n");
  printf("  O: Mostrar ou Remover as orbitas.  \n");
  printf("  L: Para remover o Sol e toda a luz do sistema. \n");
  printf("  C: Para centralizar a visão do observador no sol. \n");
  printf("  1: Para alternar para a visao superior do sistema. \n");
  printf("  2: Para alternar para a visao inferior do sistema. \n");
  printf("  MOUSE: Pressiona o botão para aproximar/afastar. \n");
  printf("  ESC: Sair.\n");
  printf("  ------------------------------------------------------------------\n");
}

int main(int argc, char *argv[])
{
  glutInit(&argc, argv);
  glutInitContextVersion(1, 1);
  glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
  glutInitWindowSize(1800, 1200);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("Sistema Solar");
  imprimeGuia();
  glutDisplayFunc(Sistema_Solar_com_orbitas);
  glutReshapeFunc(Redimensiona);
  glutSpecialFunc(SpecialKeyboard);
  glutKeyboardFunc(teclado);
  glutMouseFunc(GerenciaMouse);
  glutMotionFunc(GerenciaMovimentacao);
  Inicializa();

  /*Algoritmo para biblioteca SDL retirado de https://gist.github.com/armornick/3497064*/
  // Initialize SDL
  Mix_PlayingMusic();

  glutIdleFunc(atualiza);
  glutMainLoop();

  // clean up our resources
  Mix_FreeMusic(music);

  // quit SDL_mixer
  Mix_CloseAudio();

  return 0;
}
