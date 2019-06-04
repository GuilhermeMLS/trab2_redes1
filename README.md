

# <b>Trabalho 2 de Rede de Computadores I - UFPR - Ciência da Computação</b>

<b>Objetivo:</b>

Receber um texto ASCII como entrada e efetuar a codificação e
decodificação hamming.
 
<b>Alunos:</b>
<ul>
    <li>Guilherme M. Lopes - GRR20163043</li>
    <li>Leonardo Stefan - GRR20163052</li>
</ul>

<b>Como rodar:</b>
<ul>
    <li>
        Linux: <code>$ make</code> em seguida
        <code>$ ./main_exe aquivo_de_entrada.txt</code>
    </li>
    <li>MacOS: substituir <code>gcc</code> por <code>clang</code> no Makefile e rodar igual acima</li>
</ul>

Observação: por padrão, o programa rodará o hamming(11, 15). Entretanto, é possível configurar
outros tipos de codificação.

<b>Debugger:</b>

 Para mensagens de log mais precisas e mensagens de debug, compilar com <code>-DDEBUG</code>.
 
  
<b>Bugs conhecidos:</b>

Por algum motivo ainda desconhecido o programa não funciona como esperado para e
ntradas com mais de 12 mil caracteres. A solução em um cenário hipotético de uso
 da ferramenta seria codificar/decodificar textos de 12 mil em 12 mil caracteres. 
 Acreditamos que tenha a ver com o tamanho máximo do array que utilizamos como 
 substituto do buffer (mais detalhes no relatório em PDF).

 

 