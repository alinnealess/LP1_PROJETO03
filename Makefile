all: compile run

compile:
	g++ -o ImdCorpSys \
		./src/main.cpp \
		./src/body/classes/aggregated/endereco.cpp \
		./src/body/classes/base/pessoa.cpp \
		./src/body/classes/base/funcionario.cpp \
		./src/body/classes/derived/professor.cpp \
		./src/body/classes/derived/tecnicoAdm.cpp \
		./src/body/classes/standalone/bancoDao.cpp \
		./src/body/common/menu.cpp \
		./src/body/common/enums.cpp

run:
	./ImdCorpSys

limpar:
	rm -f ImdCorpSys