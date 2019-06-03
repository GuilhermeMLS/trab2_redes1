

<b>Trabalho 2 de Rede de Computadores I - UFPR - Ciência da Computação</b>

<b>Objetivo:</b>

Receber um texto ASCII como entrada e efetuar a condificação e
codificação hamming.
 
<b>Alunos:</b>
<ul>
    <li>Guilherme M. Lopes - GRR20163043</li>
    <li>Leonardo Stefan - GRR</li>
</ul>

<b>Como rodar:</b>
<ul>
    <li>MacOS: <code>clang main.c -o nome_do_executável</code></li>
    <li>Linux: <code>gcc main.c -o nome_do_executável</code></li>
</ul>

<b>Debugger:</b>

 Para mensagens de log mais precisas, compilar com <code>-DDEBUG</code>.
 
  
<b>Bugs conhecidos:</b>

 Por algum motivo, provavelmente a alocação de memória do vetor data, algumas vezes o programa
 entrega valores aleatórios que não correspondem com a sequência de bits gerada para
 codificação a partir das strings recebidas. Basta rodar novamente, e geralmente na segunda ou
 terceira tentativa, os valores vêm corretos.
 

 