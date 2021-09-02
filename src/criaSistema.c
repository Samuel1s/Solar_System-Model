#include "./library/header.h"

void Sistema_Solar()
{
  float t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
  float a = t;
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  if (flag_ativacao_sol == 1)
  {
    glShadeModel(GL_SMOOTH);

    // Propriedades da fonte de luz
    glLightfv(GL_LIGHT0, GL_AMBIENT, iluminacao_ambiente);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, iluminacao_difusa);
    glLightfv(GL_LIGHT0, GL_SPECULAR, iluminacao_especular);
    glLightfv(GL_LIGHT0, GL_POSITION, iluminacao_emissiva);

    glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);

    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);

    glPushMatrix();
    glRasterPos2f(0, 1.5);
    glutBitmapString(GLUT_BITMAP_9_BY_15, "Sol");
    GLUquadric *qobj = gluNewQuadric();
    gluQuadricTexture(qobj, GL_TRUE);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, lista_texturas[0]);
    glMaterialfv(GL_FRONT, GL_AMBIENT, iluminacao_objeto_ambiente);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, iluminacao_objeto_difusa);
    glMaterialfv(GL_FRONT, GL_SPECULAR, iluminacao_objeto_especular);
    glMaterialfv(GL_FRONT, GL_SHININESS, alto_brilho);
    glRotated(a * 7, 0, 0, 1);
    glScalef(3, 3, 3);
    gluSphere(qobj, 1, 25, 25);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
  }
  else
  {
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
  }

  desenha_Planeta("Mercurio", lista_texturas[6], 7, 7, 2, 0.48, 3.7);  // MERCÚRIO      
  desenha_Planeta("Venus", lista_texturas[7], 17, 17, 1.2, 1.21, 2.5); // VẼNUS
  desenha_Planetas_com_Satelites("Terra", lista_texturas[1], lista_texturas[2], 27, 27, 1.2, 1.27, 0.5, 1.9, 0.2); // TERRA 
  desenha_Planetas_com_Satelites("Marte", lista_texturas[3], lista_texturas[17], 41, 41, 1.2, 0.68, 0.5, 1.9, 1);  // MARTE
  desenha_Planetas_com_Satelites_e_Aneis("Jupiter", lista_texturas[4], lista_texturas[13], lista_texturas[11], 80, 80, 1.5, 1.43, 0.25, 1.9, 1); // JÚPITER
  desenha_Planetas_com_Satelites_e_Aneis("Saturno", lista_texturas[5], lista_texturas[12], lista_texturas[11], 97, 97, 1.5, 1.2, 0.25, 1.5, 1); // SATURNO
  desenha_Planetas_com_Satelites_e_Aneis("Urano", lista_texturas[8], lista_texturas[14], lista_texturas[11], 107, 107, 1.5, 0.51, 0.25, 1.2, 1.3); // URANO
  desenha_Planetas_com_Satelites_e_Aneis("Netuno", lista_texturas[9], lista_texturas[15], lista_texturas[11], 127, 127, 1.5, 0.495, 0.20, 1, 1); // NETUNO
  desenha_Planetas_com_Satelites("Plutao", lista_texturas[10], lista_texturas[16], 140, 140, -0.35, 2.3, 3, 0.8, 0.6); // PLUTÂO
}

void Desenha()
{
  glDrawBuffer(GL_BACK);
  // Limpa a janela de visualizao com a cor de fundo especificada
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  Sistema_Solar();
  glutSwapBuffers();
}

void mostraOrbitas()
{
  desenha_Orbita(7, 7);     // MERCÚRIO 
  desenha_Orbita(17, 17);   // VÊNUS 
  desenha_Orbita(27, 27);   // TERRA
  desenha_Orbita(41, 41);   // MARTE
  desenha_Orbita(80, 80);   // JÚPITER
  desenha_Orbita(97, 97);   // SATURNO
  desenha_Orbita(107, 107); // URANO
  desenha_Orbita(127, 127); // NETUNO
  desenha_Orbita(140, 140); // PLUTÃO
}

void Sistema_Solar_com_orbitas()
{
  glDrawBuffer(GL_BACK);
  // Limpa a janela de visualizao com a cor de fundo especificada
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  Sistema_Solar();
  glColor3f(0.0, 1.0, 1.0);
  mostraOrbitas();
  glutSwapBuffers();
}