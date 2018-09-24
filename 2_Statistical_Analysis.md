# Variáveis aleatórias

## 1. Funções de distribuição de probabilidades  

Uma variável aleatória $X$ tem suas propriedades estatísticas completamente determinadas pela sua função de probabilidade acumulada (fpa), $P_X(x)$, ou, opcionalmente, pela sua função de densidade de probabilidade (fdp), $p_X(x)$.

Seguindo uma abordagem conhecida como _frequentista_, o significado físico atribuído a estas funções matemáticas pode ser compreendido se um conjunto de  amostras independentes, $ \left\{ x_{1}, x_{2}, \dots, x_{i}, \dots, x_{N} \right\}$, é utilizado como ponto de partida para as definições. Sem perda de generalidade, admite-se a seguir que as amostras no conjunto estão ordenadas de forma ascendente, ou seja, $x_{1} < x_{2} < \dots < x_{N}$.

A partir deste conjunto de amostras é possível construir uma função em forma de escada que se denomina função empírica de probabilidade acumulada. Esta função adimensional é incrementada de $1/N$ nos pontos em que a abscissa $x$ coincide com os valores das amostras, atingindo valor máximo 1 a partir de $x = x_N$.

Vê-se na figura uma representação precisa e não tendenciosa do que foi observado a respeito da variável aleatória $X$. Até agora nenhuma hipótese foi feita e nenhum aspecto subjetivo foi incluído no procedimento, com exceção de eventuais peculiaridades do método de obtenção das amostras. Se esta abordagem fosse mantida e se fosse necessário estimar-se a propensão de  a assumir certos valores numéricos, tudo o que poderia ser dito pela abordagem frequentista é que:

\begin{align*}
{\rm Prob} \left\{ X = x_{i} \right\} &= 1/N \\
{\rm Prob} \left\{ X < x_{i} \right\} &= (i - 1)/N
\end{align*}

Acredita-se, contudo, que na medida que o número  de amostras disponíveis for aumentando, a função empírica de probabilidade acumulada irá convergir para uma função determinística, que corresponderia então à _função de probabilidade acumulada_ (fpa), $P_X(x)$. Esta crença em uma _convergência_ introduz um aspecto subjetivo na análise, pois jamais haverá um número de amostras grande o suficiente para que $P_X(x)$ seja perfeitamente conhecida, embora seja ela uma informação fundamental nos cálculos de probabilidade que envolvam a variável aleatória $X$. Na prática, escolhe-se para fpa geralmente funções contínuas, que tenham uma justificativa física associada ao fenômeno que contextualiza a variável aleatória. Os modelos mais comuns serão apresentados mais adiante (incluindo a função de Gauss, usada no exemplo da figura acima).

Na medida em que a função empírica aproxima uma função teórica (modelo) de probabilidade acumulada, a sua derivada aproxima o que se denomina _função de densidade de probabilidade_ (fdp), $p_X(x)$ , tal que:

\begin{align*}
&{\rm Prob} \left\{ X = x \right\}   = p_X(x) \, dx \\
&{\rm Prob} \left\{ X < x \right\}  = P_X(x) = \int_{-\infty}^{x} p_X(\chi) \, d\chi \\
&{\rm Prob} \left\{ x_{1} < X < x_{2} \right\}  = P_{X}(x_{2}) - P_{X}(x_{1})
                          = \int_{x_{1}}^{x_{2}} p_X(\chi) \, d\chi
\end{align*}

Observa-se que, devido à continuidade de domínio, a probabilidade de que a variável aleatória $X$ assuma um valor particular  é infinitesimal. Valores finitos de probabilidade são obtidos somente para intervalos no eixo das abscissas. 

Na acima pode-se ver, em linha tracejada, a f.d.p. associada à f.p.a. apresentada na fig. 1. Esta função suaviza o histograma de densidade de probabilidade, apresentado em linha cheia na mesma figura. A construção deste histograma é um pouco mais complexa que a da função empírica de probabilidade acumulada, uma vez que requer o arbítrio de um intervalo de discretização do eixo das abcissas. Uma vez definida esta discretização, o histograma é construído de forma a representar a fração de amostras pertencentes a cada intervalo, respeitando a condição de que a área total do histograma (sua integral) seja unitária. 

A passagem de funções empíricas para funções teóricas é tema da disciplina de Estatística, e não será aqui abordada em maiores detalhes. Entretanto, cumpre mencionar a existência de funções que são particularmente adequadas para o papel de distribuição de probabilidades, principalmente por estarem associadas a algum princípio físico pertinente ou simplesmente por respeitarem as propriedades axiomáticas:

\begin{align*}
\mbox{1)} & \;\;\; 0 < P_X(x) < 1 \\
\mbox{2)} & \;\;\; p_X(x) = \frac{dP_X(x)}{dx} \geq 0 \\
\mbox{3)} & \;\;\; \int_{-\infty}^{+\infty} p_X(x)  \, dx = 1
\end{align*}

Com base nestas definições, a rigor a função de densidade empírica deveria ser uma soma de funções tipo delta de Dirac (impulsos unitários nas coordenadas $x_i$):

$$  p_X(x) = \sum_{i = 1}^{N} {\frac{\delta(x - x_{i})}{N}} $$

mas dá-se preferência a uma apresentação mais suavizada, tal como a obtida do histograma normalizado apresentado na figura. 

Cabe salientar que a transição de funções empíricas para modelos teóricos representa um passo necessário para que, a partir de uma informação limitada, se possa levar a cabo um procedimento de análise que requer o conhecimento da propensão de ocorrência de valores muito grandes ou muito pequenos da variável aleatória (que sequer foram observados). Em suma, o uso de funções teóricas, $P_X(x)$ e $p_X(x)$, se dá em decorrência da necessidade de inter- e extrapolações a partir de dados disponíveis, para determinação de probabilidades que não foram obtidas experimentalmente.

## 2. Momentos estatísticos de uma variável aleatória

Define-se inicialmente como valor esperado, valor médio, ou simplesmente média de uma variável aleatória a coordenada de seu domínio obtida de uma ponderação de todo o domínio pela fdp: 
	(5)
Demonstra-se facilmente que o operador  é linear. Além disso, o seu uso pode ser aplicado também para quaisquer funções de variáveis aleatórias, , sendo de especial interesse a classe de funções , para a qual:
	(6)
onde  é denominado momento estatístico de ordem k da variável aleatória , ou simplesmente -ésimo momento de . O valor esperado de  é um caso particular em que , e portanto .

## Momentos estatísticos centrais

Os momentos estatísticos podem ser alternativamente definidos após um deslocamento da origem do eixo das abscissas para que este coincida com o valor médio da variável aleatória:
	(7)
onde  é denominado momento estatístico central de ordem  da variável aleatória , ou simplesmente -ésimo momento central de . Observa-se que por definição . Já o segundo momento central, , recebe a denominação de variância, e sua raiz quadrada é o desvio padrão, , que constitui uma medida da variabilidade de . Assim como o valor médio é análogo ao centro de área da fdp, o desvio padrão é análogo ao seu raio de giração. A relação  é denominada coeficiente de variação, e também constitui uma medida da variabilidade de , com a vantagem de ser adimensional e a desvantagem de tender ao infinito para variáveis aleatórias com média tendendo a zero.
É possível obter-se os momentos centrais  diretamente dos momentos  através da relação:
	(8)
Por exemplo, para  tem-se que:

e logo:

Este mesmo resultado pode ser obtido a partir das eqs. 6 e 7, com .
É de fundamental importância não confundir os momentos de uma distribuição de probabilidade (abordagem axiomática da teoria de probabilidades) com os estimadores de momentos de uma distribuição (abordagem frequentista). A definição de estimadores não será abordada aqui em maiores detalhes, visto que é um vasto campo de estudos por si só. Estimadores são a fronteira entre a teoria matemática e o mundo real, consequência natural da intenção de se estabelecer uma analogia entre os dois contextos. Contudo, não se pode prescindir de relacionar os dois principais estimadores que serão aqui utilizados. Pode ser demonstrado que os seguintes estimadores da média, , e do desvio padrão, :
	(9)
	(10)
são não tendenciosos (unbiased), pois tendem aos respectivos momentos quando  tende a infinito. Estes estimadores estão disponíveis no Matlab através dos comandos mean e std, respectivamente. Deve-se observar o uso do chapéu para diferenciar o momento estatístico de seu estimador.

4. A distribuição uniforme
Se uma variável aleatória, , é uniformemente distribuída entre 0 e 1, então  a sua função de densidade de probabilidade e a sua função de probabilidade acumulada são, respectivamente:
	(11)
O primeiro momento é calculado como:

enquanto o segundo momento central é:

Observa-se que  e  são, respectivamente, a coordenada do centro de área e o raio de giração de um retângulo de lado unitário. 
A distribuição uniforme é de fundamental importância para várias técnicas de simulação, tais como a Simulação de Monte Carlo, sendo que diversos ambientes computacionais já trazem alguma função capaz de gerar números aleatórios uniformemente distribuídos e não-correlacionados. Por exemplo, no Matlab utilizando-se o comando rand, e verificando-se média e desvio padrão através de estimadores internos:

>> u  = rand(1,1000);
>> mean(u)

ans =

    0.5127

>> std(u)

ans =

    0.2893

## A distribuição normal

No Teorema do Limite Central é deduzido que a soma de um grande número de variáveis aleatórias (por exemplo, erros acumulados) resulta ter uma função de distribuição de probabilidade que se denomina função de distribuição normal ou Gaussiana.
Curiosamente, a sua função de probabilidade acumulada não  pode ser conhecida em uma forma analítica fechada, embora a respectiva função de densidade seja:
	(12)
Os parâmetros da distribuição são  e , que correspondem à média e ao desvio padrão da variável , respectivamente. Esta correspondência direta entre os parâmetros da função e os momentos estatísticos é apenas mais uma das características que tornam a distribuição Gaussiana tão atrativa para fins práticos. Na verdade, é muito comum adotar-se a esta distribuição quando não se dispõe de nada além de estimativas de média e desvio padrão.
Ambientes computacionais, tais como o Matlab, geralmente disponibilizam recursos referentes à distribuição normal. Contudo, é comum que se o use o caso particular em que a variável aleatória tem média zero e desvio padrão unitário: 
	(13)
sendo a função  denominada função de densidade de probabilidade Gaussiana padrão. Esta função está graficada na fig. 2 com uma linha tracejada, para fins de avaliação da simulação realizada com o comando randn do Matlab. A correspondente função de probabilidade acumulada é:
	(14)
a qual, como já foi dito, não pode ser calculada analiticamente. A função  encontra-se geralmente tabelada em livros de estatística, ou pode ser calculada através de uma aproximação por expansão assimptótica.
Uma característica muito importante da distribuição normal, que será amplamente explorada na sequência, é o fato de que uma combinação linear de variáveis aleatórias gaussianas, correlacionadas ou não, resulta também em uma variável gaussiana. Mais do que isso, qualquer sistema (dinâmico) linear, submetido a uma excitação (input) gaussiano, apresentará também uma resposta (output) gaussiana. Essa propriedade facilita a estimativa de valores extremos da resposta, que são de grande interesse prático.
Para simular uma váriavel aleatória gaussiana com uma dada média e desvio padrão, basta inverter a normalização apresentada na eq. 13, tal como demonstrado na fig. 3.

 N   =  512;
 mx  =  3.0;
 sx  =  2.0;
 
 x   =  mx + sx*randn(1,N);
 
 nbin = round(1+3.3*log(N));
 hist(x,nbin); 
 grid on;


Figura 3. Simulação de uma variável gaussiana com média e desvio padrão dados. 


6. A distribuição determinística
Caso o desvio padrão na distribuição normal tenda a zero, a variável aleatória passa a ter seu único valor possível tendendo à média. Neste limite a função de densidade de probabilidade tende a uma importante função utilizada na física, chamada Delta de Dirac ou função impulso unitário:
	(14)
cuja integral total é por definição finita e unitária:
	(15)
Portanto, esta distribuição respeita as condições axiomáticas estabelecidas na eq. 3. A integral da função impulso unitário é a função passo unitário, ou função de Heaviside:
	(16)
Estas duas funções, ilustradas na fig. 4, são usadas em diversos contextos, além de representarem funções de distribuição de probabilidades. Elas também podem representar forças dinâmicas em sistemas estruturais, ou ainda autocorrelações e densidades espectrais na análise de sinais, como será visto mais adiante.

## Funções monotônicas de uma variável aleatória


