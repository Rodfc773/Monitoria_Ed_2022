##  _Funções importantes  para o funcionamento do opengl e que não devem ser mexidas/devem estar presentes no código_:

* ### _Na Função main_:


1. ```glutInit(&argc, argv)```

__Função que inicia o glut__


2. ```glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB)```

 __configura o tipo estrutura de coloração que vai ser suportada__;


3. ```glutInitWindowSize(WINDOW_WIDTH,WINDOW_HEIGHT)```

 __Gera o tamanho da tela de exibição__;
 
4. ```glutCreateWindow("Bounce")```

__Cria a janela de exibição__;


5. ```setupRC()```

__Função que gera a cor de background da cena, essa aqui pode ser criado pelo proprio programador ou pegar um exemplo pronto__;

6. ```glutDisplayFunc(RenderScene)```

__Função responsável por renderizar a cena, a RenderScene ou display é a função onde realmente serão feitos as instruções ou seja, a verdadeira "main"__;

7. ```glutReshapeFunc(ChangeSize)```

__Tem como parametro uma função de recalculação da janela de exibição, permitindo que possa ser diminuida e aumentada, geralmente a ChangeSize deve ser feita pelo o usuario ou pegar um exemplo já predefinido__;

8. ```glutMainLoop();```

__Função que permite o loop da tela de exibição,sem ela a tela é fechada automaticamente em questão de instantes__

* ### _Na função Render scene/Display:_

1. ```glClear(GL_COLOR_BUFFER_BIT)```

__Função que limpa o buffer de cores__

2. ```glutSwapBuffers()```

__Função que atualiza o buffer de exibição, redesenhando na tela__

4. ```glPushMatrix()```

__Salva o estado da tela, essa no caso não é obrigado a ter, porém é bom caso trabaçhe com 3 dimensões ou animações__

5. ```glPopMatrix()```

__Atualiza o estado da tela, também usada para 3 dimensões ou animações__

