#include "./library/header.h"

void GerenciaMouse(int button, int state, int x, int y)
{
  if (state == GLUT_DOWN)
  {
    // Salva os parâmetros atuais
    posicao_inicial_x = x;
    posicao_inicial_y = y;
    eixo_inicial_observador_em_X = observador_virtual_eixo_X;
    eixo_inicial_observador_em_Y = observador_virtual_eixo_Y;
    eixo_inicial_observador_em_Z = observador_virtual_eixo_Z;
    rotacao_inicial_eixo_X = rotacao_eixo_X;
    rotacao_inicial_eixo_Y = rotacao_eixo_Y;
    flag_botao_mouse_pressionado = button;
  }
  else
    flag_botao_mouse_pressionado = -1;
}

void GerenciaMovimentacao(int x, int y)
{
  // Apertou o botão esquerdo do mouse.
  if (flag_botao_mouse_pressionado == GLUT_LEFT_BUTTON)
  {
    // Calcula diferenças
    int deltax = posicao_inicial_x - x;
    int deltay = posicao_inicial_y - y;

    // E modifica ângulos
    rotacao_eixo_Y = rotacao_inicial_eixo_Y - deltax / P_ROTACAO;
    rotacao_eixo_X = rotacao_inicial_eixo_X - deltay / P_ROTACAO;
  }
  
  // Apertou o botão direito do mouse.
  else if (flag_botao_mouse_pressionado == GLUT_RIGHT_BUTTON)
  {
    int deltax = posicao_inicial_x - x;
    int deltay = posicao_inicial_y - y;
    // Calcula diferença
    int deltaz = deltax - deltay;
    // E modifica distância do observador
    observador_virtual_eixo_Z = eixo_inicial_observador_em_Z + deltaz / P_OBSERVACAO;
  }

  // Apertou o botão do meio do mouse.
  else if (flag_botao_mouse_pressionado == GLUT_MIDDLE_BUTTON)
  {
    // Calcula diferenças
    int deltax = posicao_inicial_x - x;
    int deltay = posicao_inicial_y - y;
    // E modifica posições
    observador_virtual_eixo_X = eixo_inicial_observador_em_X + deltax / P_TRANSLACAO;
    observador_virtual_eixo_Y = eixo_inicial_observador_em_Y - deltay / P_TRANSLACAO;
  }
  PosicionaObservador();
  glutPostRedisplay();
}