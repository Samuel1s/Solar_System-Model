
#include "./library/header.h"

Mix_Music *music = NULL;

void Inicializa(void)
{
  if (SDL_Init(SDL_INIT_AUDIO) < 0)
    return -1;

  //Initialize SDL_mixer
  if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
    return -1;

  // Load our music
  music = Mix_LoadMUS(MUS_PATH);
  if (music == NULL)
    return -1;

  if (Mix_PlayMusic(music, -1) == -1)
    return -1;

  // Inicializa variáveis.
  angulo_projecao_persp = 10;
  rotacao_eixo_X = 0;
  rotacao_eixo_Y = 0;
  rotacao_eixo_Z = 0;
  observador_virtual_eixo_X = observador_virtual_eixo_Y = 0;
  observador_virtual_eixo_Z = 150;

  carregaTextura(); //Inicializa as texturas

  // Não mostrar faces do lado de dentro
  glEnable(GL_CULL_FACE);
  glCullFace(GL_BACK);

  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glEnable(GL_DEPTH_TEST);
}
