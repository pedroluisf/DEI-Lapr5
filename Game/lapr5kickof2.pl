%------------------------------------------------------------------------
% Inicio da aplicacao
%------------------------------------------------------------------------

soma_tempo_a_relogio((H,M),T,(HS,MS)):-
						Tcontas is (T+M+H*60)//1,
						Horas is Tcontas//60, HS is Horas mod 24, MS is Tcontas mod 60.

relogio_para_minutos((H,M),Min):-Min is H*60+M.


inicio:-
%	consult('C:\Users\asus\Desktop\ISEP\LAPRV\algav\progresso\bcLapr5_simples.pl'),
	consult('exemplo.pl'),
	inicio(Percurso,Relogio),
	write('Percurso='),write(Percurso),nl,
	write('Encomendas entregues'),nl,
	write('Relogio='),
	write(Relogio),nl,
	write('Menos uma hora nos Açores'),nl,write('Percurso:'),nl,
	write(Percurso),nl.

inicio_clean:-
%	consult('C:\Users\asus\Desktop\ISEP\LAPRV\algav\progresso\bcLapr5_simples.pl'),
	consult('exemplo.pl'),
	inicio_clean(Percurso,Relogio),nl,
	write(Percurso),nl.

	
inicio(Percurso,RelogioFinal):-

	% juntar encomendas numa lista
	findall(IdEncomenda,encomenda(IdEncomenda,_,_),Encomendas),

	%ler camiao
	camiao(Matricula,NoInicio,Peso,Largura, Altura,VelocidadeMax),	

	write('O camionista Feliz inicia serviço com  o camiao '),write(Matricula),nl,

	%ler relogio	
	relogio(Hora,Minuto),

	write('Hora actual='),write((Hora,Minuto)),nl,
 	
	%na solucao fornecida nao é feito qualquer processamento da lista
	entregarEncomendas(NoInicio,(Peso,Largura, Altura,VelocidadeMax),(Hora,Minuto),RelogioFinal,Encomendas,Percurso).
	
	
inicio_clean(Percurso,RelogioFinal):-

	% juntar encomendas numa lista
	findall(IdEncomenda,encomenda(IdEncomenda,_,_),Encomendas),

	%ler camiao
	camiao(Matricula,NoInicio,Peso,Largura, Altura,VelocidadeMax),	
	%ler relogio	
	relogio(Hora,Minuto), 	
	%na solucao fornecida nao é feito qualquer processamento da lista
	entregarEncomendas_clean(NoInicio,(Peso,Largura, Altura,VelocidadeMax),(Hora,Minuto),RelogioFinal,Encomendas,Percurso).
	



/*------------------------------------------------------------------------------------
entregarEncomendas(NoInicio,Dados_Camiao,Relogio,Lista_Encomendas,Percurso)
------------------------------------------------------------------------------------*/
 
% condicao final - todas encomendas entregues
entregarEncomendas(_,_,Relogio,Relogio,[],[]).

entregarEncomendas_clean(_,_,Relogio,Relogio,[],[]).


entregarEncomendas(NodoInicio,Camiao,RelogioActual,RelogioFinal,[IdEncomenda|Encomendas],Percurso):-

	encomenda(IdEncomenda,Riscos,PontoEntrega),
	ponto_entrega(PontoEntrega,NodoEncomenda),


	write('A entregar encomenda '), write(IdEncomenda), write(' em '),write(PontoEntrega),nl,

	%calcular percurso da posicao inicial até posicao da ponto_entrega 
	percurso(NodoInicio,NodoEncomenda,Riscos,PercursoEnc,Tempo),

	%actualizar NovoRelogio = RelogioActual + Tempo
	% na solucao fornecida relogio mantem-se inalterado
	%NovoRelogio = RelogioActual + Tempo,
	soma_tempo_a_relogio(RelogioActual,Tempo,NovoRelogio),

	write('Hora actual='),write(NovoRelogio),nl,

	write('Percurso da encomenda='),write(PercursoEnc),nl,

	%processar resto das encomendas
	entregarEncomendas(NodoEncomenda,Camiao,NovoRelogio,RelogioFinal,Encomendas,PercursoR),
	
	%Calcular resultados finais
	append(PercursoEnc,PercursoR,Percurso).

entregarEncomendas_clean(NodoInicio,Camiao,RelogioActual,RelogioFinal,[IdEncomenda|Encomendas],Percurso):-

	encomenda(IdEncomenda,Riscos,PontoEntrega),
	ponto_entrega(PontoEntrega,NodoEncomenda),


	%calcular percurso da posicao inicial até posicao da ponto_entrega 
	percurso(NodoInicio,NodoEncomenda,Riscos,PercursoEnc,Tempo),

	%actualizar NovoRelogio = RelogioActual + Tempo
	% na solucao fornecida relogio mantem-se inalterado
	% NovoRelogio = RelogioActual + Tempo,
	soma_tempo_a_relogio(RelogioActual,Tempo,NovoRelogio),



	%processar resto das encomendas
	entregarEncomendas_clean(NodoEncomenda,Camiao,NovoRelogio,RelogioFinal,Encomendas,PercursoR),
	
	%Calcular resultados finais
	append(PercursoEnc,PercursoR,Percurso).


% o algoritmo que determina os percursos é intencionalmente pouco eficiente 
% na solucao a desenvolver deverão ser considerados algoritmos mais eficientes

%------------------------------------------------------------------------------------
% percurso(Origem,Destino,Riscos,Percurso,Tempo)
%------------------------------------------------------------------------------------

percurso(Origem,Destino,Riscos,Percurso,Tempo):-
%		percurso2(Origem,Destino,Riscos,[],Percurso,Tempo).
%		goi(Origem,Destino,Riscos,Percurso,Tempo).
%		procuraAstar(Origem,Destino,Riscos,Percurso,Tempo).
		procuraAstarTempo(Origem,Destino,Riscos,Percurso,0,Tempo).


%------------------------------------------------------------------------------------
% percurso2(Destino,Percurso,Distancia)
%------------------------------------------------------------------------------------


%condiçao final
percurso2(Destino, Destino,_,Ramos,Percurso,0):- 
		reverse(Ramos,Percurso),!.


percurso2(NoActual, Destino,Riscos,Ramos,Percurso,Tempo):- 
		
		%na solucao actual não sao consideradas restriçoes de transito nem limites de velocidade 
		% considerar riscos associados à encomenda 

		%escolher um ramo que liga o nó actual
		(ramo(IdRamo,NoActual,NoX,Distancia);ramo(IdRamo,NoX,NoActual,Distancia)),
		
		%nao repetir ramos no percurso
		not member(IdRamo,Ramos),

		% o tempo gasto em cada ramo deve ser calculado em funcao da distancia e velocidade
		% a velocidade a considerar é o minimo entre a velocidade máxima do camião e 
		% a velocidade máxima permitida no ramo indicada na restrição de velocidade, no caso
		% de nao existir restricao no ramo assume-se que o camiao se desloca à velocidade máxima
		% na solucao fornecida considera-se 0,
		camiao(_,_,_,_,_,VelocidadeCamiao),
		TempoRamo is Distancia/VelocidadeCamiao*60,

		percurso2(NoX, Destino,Riscos,[IdRamo|Ramos],Percurso,TempoR),

		Tempo  is TempoRamo	 + TempoR.


%------------------
% Primeiro Melhor  
%------------------

goi(Orig,Dest,_,Percurso,Tempo):-go(Orig,Dest,[],Percurso,Tempo).

go(Dest,Dest,_,[],0).
go(Orig,Dest,LA,[Resc|L],Tempo):- 
	findall((Rnome,EstX), ((ramo(Rnome,Orig,X,_);ramo(Rnome,X,Orig,_) ), not member(Rnome,LA), estimativa_tempo(Rnome,EstX)),LX), 
	melhor(LX,(Resc,_)),
	camiao(_,_,_,_,_,VelocidadeCamiao),
	(ramo(Resc,NE,Orig,Distancia);ramo(Resc,Orig,NE,Distancia)),
	TempoRamo is Distancia/VelocidadeCamiao*60,
	go(NE,Dest,[Resc|LA],L,TempoR),
	Tempo is TempoRamo + TempoR. 

melhor([(_,EstX)|T],(RM,M)):- 
	melhor(T,(RM,M)),
	M < EstX,!. 
melhor([(X,EstX)|_],(X,EstX)).

estimativa_tempo(Rnome,EstX):-ramo(Rnome,_,_,EstX).


%------------------
% A star           
%------------------

procuraAstar(Orig,Dest,_,PercursoR,Tempo):-
	estimativa(Orig,Dest,H),
	hbf1([c(H/0,[Orig])],Dest,P,Tempo),
	reverse(P,Percurso),
	passa_Nodos_Ramos(Percurso,PercursoR).	

hbf(Orig,Dest,Perc,Total):-
		time(0,Ti),
		estimativa(Orig,Dest,H),
		hbf1([c(H/0,[Orig])],Dest,P,Total),
		reverse(P,Perc),
		time(0,Tf),
		Ti=(_,Ii), Tf=(_,If), T is If-Ii,
		write('Tempo de execução: '),write(T),write('ms'),nl.

hbf1(Percursos,Dest,Percurso,Total):-
		menor_percursoh(Percursos,Menor,Restantes),
		percursos_seguintesh(Menor,Dest,Restantes,Percurso,Total).

percursos_seguintesh(c(_/Dist,Percurso),Dest,_,Percurso,Dist):-Percurso=[Dest|_].
percursos_seguintesh(c(_,[Dest|_]),Dest,Restantes,Percurso,Total):-!,
		hbf1(Restantes,Dest,Percurso,Total).
percursos_seguintesh(c(_/Dist,[Ult|T]),Dest,Percursos,Percurso,Total):-
		findall(c(H1/D1,[Z,Ult|T]),proximo_noh(Ult,T,Z,Dist,Dest,H1/D1),Lista),
		append(Lista,Percursos,NovosPercursos),
		hbf1(NovosPercursos,Dest,Percurso,Total).

menor_percursoh([Percurso|Percursos],Menor,[Percurso|Resto]):-menor_percursoh(Percursos,Menor,Resto),menorh(Menor,Percurso),!.
menor_percursoh([Percurso|Resto],Percurso,Resto).

menorh(c(H1/D1,_),c(H2/D2,_)):-C1 is H1+D1, C2 is H2+D2, C1<C2.

proximo_noh(X,T,Y,Dist,Dest,H/Dist1):-
		(ramo(NRamo,X,Y,Z);ramo(NRamo,Y,X,Z)),
		not member(Y,T),
		Dist1 is Dist + Z,
		estimativa(Y,Dest,H).

estimativa(C1,C2,Est):-
		nodo(C1,X1,Y1),
		nodo(C2,X2,Y2),
		DX is X1-X2,
		DY is Y1-Y2,
		Est is sqrt(DX*DX+DY*DY). % ‘Est is 0' para desprezar a heurística.

%----------------------------------
% Passar Nodos para Ramos          
%----------------------------------
%passa_Nodos_Ramos(ListaNodos, ListaRamos).
passa_Nodos_Ramos([Penultimo|[ Ultimo|[] ]],[Ramo]):-(ramo(Ramo,Penultimo,Ultimo,_);ramo(Ramo,Ultimo,Penultimo,_)).
passa_Nodos_Ramos([H1N|[H2N|TN]],[HR|TR]):-passa_Nodos_Ramos([H2N|TN],TR),(ramo(HR,H1N,H2N,_);ramo(HR,H2N,H1N,_)),!.

%--------------------------
% A star com Tempos        
%--------------------------

procuraAstarTempo(Orig,Dest,_,PercursoR, Tempoi, Tempof):-
	estimativat(Orig,Dest,H),
	hbf1t([c(H/0,[Orig])],Dest,P,Total,Tempoi),
	reverse(P,Percurso),
	passa_Nodos_Ramos(Percurso,PercursoR),
	Tempof is Total + Tempoi.	

hbfTempo(Orig,Dest,Perc,Total):-
		time(0,Ti),
		estimativat(Orig,Dest,H),
		hbf1t([c(H/0,[Orig])],Dest,P,Total),
		reverse(P,Perc),
		time(0,Tf),
		Ti=(_,Ii), Tf=(_,If), T is If-Ii,
		write('Tempo de execução: '),write(T),write('ms'),nl.

hbf1t(Percursos,Dest,Percurso,Total,Tempo):-
		menor_percursoht(Percursos,Menor,Restantes),
		percursos_seguintesht(Menor,Dest,Restantes,Percurso,Total,Tempo).

percursos_seguintesht(c(_/Dist,Percurso),Dest,_,Percurso,Dist,Tempo):-Percurso=[Dest|_].
percursos_seguintesht(c(_,[Dest|_]),Dest,Restantes,Percurso,Total,Tempo):-!,
		hbf1t(Restantes,Dest,Percurso,Total,Tempo).
percursos_seguintesht(c(_/Dist,[Ult|T]),Dest,Percursos,Percurso,Total,Tempo):-
		findall(c(H1/D1,[Z,Ult|T]),proximo_noht(Ult,T,Z,Dist,Dest,H1/D1,Tempo),Lista),
		append(Lista,Percursos,NovosPercursos),
		hbf1t(NovosPercursos,Dest,Percurso,Total,Tempo).

menor_percursoht([Percurso|Percursos],Menor,[Percurso|Resto]):-menor_percursoht(Percursos,Menor,Resto),menorht(Menor,Percurso),!.
menor_percursoht([Percurso|Resto],Percurso,Resto).

menorht(c(H1/D1,_),c(H2/D2,_)):-C1 is H1+D1, C2 is H2+D2, C1<C2.

proximo_noht(X,T,Y,Dist,Dest,H/Dist1,Tempo):-
%		(ramo(NRamo,X,Y,Z);ramo(NRamo,Y,X,Z)),
		ramot(X,Y,Z,Dist,Vel),
		not member(Y,T),
		Dist1 is Dist + Z/Vel*60,
		estimativat(Y,Dest,H).

estimativat(C1,C2,Est):-
		nodo(C1,X1,Y1),
		nodo(C2,X2,Y2),
		DX is X1-X2,
		DY is Y1-Y2,
		camiao(_,_,_,_,_,Vel),
		Est is (sqrt(DX*DX+DY*DY))/Vel*60. % ‘Est is 0' para desprezar a heurística.

ramot(O,D,Z,TempoDecorrido,VelRamo):-(ramo(NRamo,O,D,Z);ramo(NRamo,D,O,Z)),obtemVelocidade(NRamo,TempoDecorrido,VelRamo).

obtemVelocidade(NRamo,TempoDecorrido,VelRamo):-
					camiao(_,_,_,_,_,VelCam),
					relogio(Ha,Ma),
					soma_tempo_a_relogio((Ha,Ma),TempoDecorrido,RelA),
					relogio_para_minutos(RelA,TempoA),
					(restricao(NRamo,inicio,velocidade,VelRamo1,Hi,Mi), restricao(NRamo,fim,velocidade,VelRamo1,Hf,Mf),
					relogio_para_minutos((Hi,Mi),Ti),relogio_para_minutos((Hf,Mf),Tf),
					((TempoA > Ti, TempoA < Tf , VelRamo is VelRamo1);(VelRamo is VelCam))
					;
					restricao(NRamo,inicio,velocidade,VelRamo1,Hi,Mi),relogio_para_minutos((Hi,Mi),Ti),
					TempoA > Ti, VelRamo is VelRamo1
					;
					VelRamo is VelCam),!.


