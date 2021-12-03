CXX = g++
CC  = $(CXX)

CXXFLAGS = `wx-config --cxxflags` -std=c++11  # C++11
LDLIBS   = `wx-config --libs gl,core,base` -lGLU	

vpath %.h include bonus tests/srctests
vpath %.cc src tests bonus tests/srctests
vpath %.o build

# Partie commentée : choisissez les options que vous voulez avoir
#                    en décommentant la/les lignes correspondantes
#
# CXXFLAGS += -pedantic -Wall         # pour les purs et durs
# CXXFLAGS += -g                      # pour debugger
# CXXFLAGS += -pg                     # pour profiler
# LDFLAGS  += -pg                     # pour profiler
# CXXFLAGS += -O2                     # pour optimiser la vitesse

all:: testVecteur testParticule testSysteme1 exerciceP9 exerciceP10 exerciceP11 exerciceP12 exerciceP13 ProjetSansBonus Projet ProjetTXT

######################### Projet Final ######################

Vecteur.o: Vecteur.cc
	$(CXX) $(CXXFLAGS) -c ./src/Vecteur.cc -o ./build/Vecteur.o

Particule.o: Particule.cc
	$(CXX) $(CXXFLAGS) -c ./src/Particule.cc -o ./build/Particule.o

Enceinte.o: Enceinte.cc
	$(CXX) $(CXXFLAGS) -c ./src/Enceinte.cc -o ./build/Enceinte.o

Dessinable.o: Dessinable.cc
	$(CXX) $(CXXFLAGS) -c ./src/Dessinable.cc -o ./build/Dessinable.o

TXTGaz.o: TXTGaz.cc
	$(CXX) $(CXXFLAGS) -c ./src/TXTGaz.cc -o ./build/TXTGaz.o
	
TXTEnceinte.o: TXTEnceinte.cc
	$(CXX) $(CXXFLAGS) -c ./src/TXTEnceinte.cc -o ./build/TXTEnceinte.o

Systeme.o: Systeme.cc
	$(CXX) $(CXXFLAGS) -c ./src/Systeme.cc -o ./build/Systeme.o

VueOpengl.o: VueOpengl.cc
	$(CXX) $(CXXFLAGS) -c ./src/VueOpengl.cc -o ./build/VueOpengl.o
	
Fenetre.o: Fenetre.cc
	$(CXX) $(CXXFLAGS) -c ./src/Fenetre.cc -o ./build/Fenetre.o

GlGaz.o: GlGaz.cc
	$(CXX) $(CXXFLAGS) -c ./src/GlGaz.cc -o ./build/GlGaz.o
	
GlEnceinte.o: GlEnceinte.cc
	$(CXX) $(CXXFLAGS) -c ./src/GlEnceinte.cc -o ./build/GlEnceinte.o
	
FenetreCTRL.o: FenetreCTRL.cc
	$(CXX) $(CXXFLAGS) -c ./bonus/FenetreCTRL.cc -o ./build/FenetreCTRL.o
	
Lettres.o: Lettres.cc
	$(CXX) $(CXXFLAGS) -c ./bonus/Lettres.cc -o ./build/Lettres.o

glSTAT.o: glSTAT.cc
	$(CXX) $(CXXFLAGS) -c ./bonus/glSTAT.cc -o ./build/glSTAT.o

FenetreSTAT.o: FenetreSTAT.cc
	$(CXX) $(CXXFLAGS) -c ./bonus/FenetreSTAT.cc -o ./build/FenetreSTAT.o

Mots.o: Mots.cc
	$(CXX) $(CXXFLAGS) -c ./bonus/Mots.cc -o ./build/Mots.o

Text.o: Text.cc
	$(CXX) $(CXXFLAGS) -c ./bonus/Text.cc -o ./build/Text.o
	
Tracable.o: Tracable.cc
	$(CXX) $(CXXFLAGS) -c ./src/Tracable.cc -o ./build/Tracable.o

FenetreOPT.o: FenetreOPT.cc
	$(CXX) $(CXXFLAGS) -c ./bonus/FenetreOPT.cc -o ./build/FenetreOPT.o
	
Projet: Projet.cc Systeme.o FenetreOPT.o GlGaz.o Tracable.o Dessinable.o Enceinte.o Particule.o Vecteur.o VueOpengl.o Fenetre.o GlEnceinte.o FenetreCTRL.o FenetreSTAT.o glSTAT.o Mots.o Lettres.o Text.o
	$(CXX) $(CXXFLAGS) ./src/Projet.cc ./build/FenetreOPT.o ./build/Tracable.o ./build/FenetreSTAT.o ./build/glSTAT.o ./build/Mots.o ./build/Lettres.o ./build/Text.o ./build/GlEnceinte.o ./build/FenetreCTRL.o ./build/VueOpengl.o ./build/Fenetre.o ./build/Systeme.o ./build/GlGaz.o ./build/Dessinable.o ./build/Enceinte.o ./build/Particule.o ./build/Vecteur.o $(LDLIBS) -o ./Projet


################## Tests #####################

testVecteur: testVecteur.cc Vecteur.o
	$(CXX) $(CXXFLAGS) ./tests/testVecteur.cc ./build/Vecteur.o -o ./bin/testVecteur
	
testParticule: testParticule.cc Vecteur.o ParticuleP5.o
	$(CXX) $(CXXFLAGS) ./tests/testParticule.cc ./build/Vecteur.o ./build/ParticuleP5.o -o ./bin/testParticule
	
testSysteme1: testSysteme1.cc SystemeP8.o TXTGaz.o Dessinable.o Enceinte.o Particule.o Vecteur.o
	$(CXX) $(CXXFLAGS) ./tests/testSysteme1.cc ./build/SystemeP8.o ./build/TXTGaz.o ./build/Dessinable.o ./build/Enceinte.o ./build/Particule.o ./build/Vecteur.o -o ./bin/testSysteme1

exerciceP9: exerciceP9.cc Systeme.o TXTGaz.o Dessinable.o TXTEnceinte.o EnceinteP6.o Particule.o Vecteur.o
	$(CXX) $(CXXFLAGS) ./tests/exerciceP9.cc ./build/Systeme.o ./build/TXTEnceinte.o ./build/TXTGaz.o ./build/Dessinable.o ./build/EnceinteP6.o ./build/Particule.o ./build/Vecteur.o -o ./bin/exerciceP9
	
exerciceP10: exerciceP10.cc Dessinable.o
	$(CXX) $(CXXFLAGS) ./tests/exerciceP10.cc ./build/Dessinable.o $(LDLIBS) -o ./bin/exerciceP10
	
exerciceP11: exerciceP11.cc Systeme.o GlGaz.o Dessinable.o Enceinte.o Particule.o Vecteur.o VueOpenglP11.o FenetreGlP11.o GlEnceinte.o Tracable.o
	$(CXX) $(CXXFLAGS) ./tests/exerciceP11.cc ./build/Tracable.o ./build/GlEnceinte.o ./build/VueOpenglP11.o ./build/FenetreGlP11.o ./build/Systeme.o ./build/GlGaz.o ./build/Dessinable.o ./build/Enceinte.o ./build/Particule.o ./build/Vecteur.o $(LDLIBS) -o ./bin/exerciceP11
	
exerciceP12: exerciceP12.cc Systeme.o GlGaz.o Dessinable.o Enceinte.o Particule.o Vecteur.o VueOpenglP12.o FenetreGlP11.o GlEnceinte.o Tracable.o 
	$(CXX) $(CXXFLAGS) ./tests/exerciceP12.cc ./build/Tracable.o ./build/GlEnceinte.o ./build/VueOpenglP12.o ./build/FenetreGlP11.o ./build/Systeme.o ./build/GlGaz.o ./build/Dessinable.o ./build/Enceinte.o ./build/Particule.o ./build/Vecteur.o $(LDLIBS) -o ./bin/exerciceP12

exerciceP13: exerciceP13.cc Systeme.o GlGaz.o Dessinable.o Enceinte.o Particule.o Vecteur.o VueOpenglP13.o FenetreGlP11.o GlEnceinte.o Tracable.o
	$(CXX) $(CXXFLAGS) ./tests/exerciceP13.cc ./build/GlEnceinte.o ./build/Tracable.o ./build/VueOpenglP13.o ./build/FenetreGlP11.o ./build/Systeme.o ./build/GlGaz.o ./build/Dessinable.o ./build/Enceinte.o ./build/Particule.o ./build/Vecteur.o $(LDLIBS) -o ./bin/exerciceP13
	
ProjetSansBonus: ProjetSansBonus.cc Systeme.o GlGaz.o Dessinable.o Enceinte.o Particule.o Vecteur.o VueOpenglP14.o FenetreGlP11.o GlEnceinte.o Tracable.o
	$(CXX) $(CXXFLAGS) ./tests/ProjetSansBonus.cc ./build/GlEnceinte.o ./build/Tracable.o ./build/VueOpenglP14.o ./build/FenetreGlP11.o ./build/Systeme.o ./build/GlGaz.o ./build/Dessinable.o ./build/Enceinte.o ./build/Particule.o ./build/Vecteur.o $(LDLIBS) -o ./bin/ProjetSansBonus
	
ProjetTXT: projetTXT.cc Systeme.o TXTGaz.o Dessinable.o Enceinte.o Particule.o Vecteur.o TXTEnceinte.o
	$(CXX) $(CXXFLAGS) ./tests/projetTXT.cc ./build/TXTEnceinte.o ./build/Systeme.o ./build/TXTGaz.o ./build/Dessinable.o ./build/Enceinte.o ./build/Particule.o ./build/Vecteur.o $(LDLIBS) -o ./bin/ProjetTXT

################# Etapes Intermédiaires #############

ParticuleP5.o: ParticuleP5.cc
	$(CXX) $(CXXFLAGS) -c ./tests/srctests/ParticuleP5.cc -o ./build/ParticuleP5.o
	
EnceinteP6.o: EnceinteP6.cc
	$(CXX) $(CXXFLAGS) -c ./tests/srctests/EnceinteP6.cc -o ./build/EnceinteP6.o
	
SystemeP8.o: SystemeP8.cc
	$(CXX) $(CXXFLAGS) -c ./tests/srctests/SystemeP8.cc -o ./build/SystemeP8.o
	
FenetreGlP11.o: FenetreGlP11.cc
	$(CXX) $(CXXFLAGS) -c ./tests/srctests/FenetreGlP11.cc -o ./build/FenetreGlP11.o

VueOpenglP11.o: VueOpenglP11.cc
	$(CXX) $(CXXFLAGS) -c ./tests/srctests/VueOpenglP11.cc -o ./build/VueOpenglP11.o
	
VueOpenglP12.o: VueOpenglP12.cc
	$(CXX) $(CXXFLAGS) -c ./tests/srctests/VueOpenglP12.cc -o ./build/VueOpenglP12.o
	
VueOpenglP13.o: VueOpenglP13.cc
	$(CXX) $(CXXFLAGS) -c ./tests/srctests/VueOpenglP13.cc -o ./build/VueOpenglP13.o
	
VueOpenglP14.o: VueOpenglP14.cc
	$(CXX) $(CXXFLAGS) -c ./tests/srctests/VueOpenglP14.cc -o ./build/VueOpenglP14.o
	
######################## Clean #####################	

clean: 
	rm build/*.o
