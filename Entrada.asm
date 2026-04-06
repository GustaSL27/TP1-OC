lb   x1, 0(x2)
sb   x3, 4(x2) //TA DANDO PROBLEMA DE LEITURA PQ ESPERA 2 VIRGULAS
sub  x4, x1, x3
and  x5, x4, x1
ori  x6, x5, 15
srl  x7, x6, x5
beq  x7, x0, -243
sub  x4, x4, x1