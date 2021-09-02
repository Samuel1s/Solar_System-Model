#include "./library/header.h"

void SpecialKeyboard(int tecla, int x, int y)
{
    switch (tecla)
    {
    case GLUT_KEY_RIGHT:
        glRotatef(rotacao_eixo_X, 1, 0, 0);
        rotacao_eixo_X++;
        break;

    case GLUT_KEY_LEFT:
        glRotatef(rotacao_eixo_Y, 0, 1, 0);
        rotacao_eixo_Y++;
        break;

    case GLUT_KEY_DOWN:
        if (angulo_projecao_persp <= 150)
            angulo_projecao_persp += 5; //diminui zoom
        break;

    case GLUT_KEY_UP:
        if (angulo_projecao_persp >= 10)
            angulo_projecao_persp -= 5; //aumenta zoom
        break;
    }
    EspecificaParametrosVisualizacao();
    glutPostRedisplay();
}

void teclado(unsigned char key, int x, int y)
{
    switch (key)
    {
    // Tecla ESC
    case 27:
        exit(0);
        break;
    
    case 'l': //Ativa/Remove o Sol
    case 'L':
        flag_ativacao_sol = !flag_ativacao_sol;
        glutDisplayFunc(Sistema_Solar_com_orbitas);
        break;

    case 49: //numero 1 - visao de cima
        observador_virtual_eixo_Z = 1000;
        break;

    case 50: //numero 1 - visao de baixo
        observador_virtual_eixo_Z = -1000;
        break;

    case 'c': //centraliza no Sol
    case 'C':
        observador_virtual_eixo_Z = 50;
        break;

    case 'o': //Mostra as orbitas
    case 'O':
        flag_ativacao_orbita = !flag_ativacao_orbita;

        if (flag_ativacao_orbita == 1)
        {
            glutDisplayFunc(Sistema_Solar_com_orbitas);
        }
        else
        {
            //Mostra o sistema solar sem as orbitas
            glutDisplayFunc(Desenha);
        }

        break;
    }
    glLoadIdentity();
    gluLookAt(observador_virtual_eixo_X, observador_virtual_eixo_Y, observador_virtual_eixo_Z, 0, 0, 0, 0, 1, 0);
    glutPostRedisplay();
}
