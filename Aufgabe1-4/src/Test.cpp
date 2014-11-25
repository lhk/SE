#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"

int berechneSemestergebuehr(int semester, double note){
	int gebuehr=200;
	if(semester>=3&&semester<=6){
		gebuehr=300;
	}else if(semester>6){
		gebuehr=400;
	}
	if(note<=1.5){
		gebuehr-=200;
	}else if(note<2.0){
		gebuehr-=100;
	}
	if(gebuehr<200){
		gebuehr=200;
	}
	return gebuehr;
}


// Minimale Termüberdeckung
void b1() {
	ASSERTM("Path 1: Z0 Z2 Z4 Z5 Z9", berechneSemestergebuehr(1,1.3)==200);
}
void b2(){
	ASSERTM("Path 2: Z0 Z1 Z6 Z7 Z10", berechneSemestergebuehr(4,1.7)==200);
}
void b3(){
	ASSERTM("Path 3: Z0 Z2 Z3 Z6 Z8 Z10", berechneSemestergebuehr(7,2.3)==400);
}

// vollständige Pfadüberdeckung

void path1(){
	ASSERTM("Path 1: Z0 Z1 Z5 Z9",berechneSemestergebuehr(4,1.0)==200);
}

void path2(){
	ASSERTM("Path 2: Z0 Z1 Z6 Z7 Z10",berechneSemestergebuehr(4,1.7)==200);
}

void path3(){
	ASSERTM("Path 3: Z0 Z1 Z6 Z8 Z10",berechneSemestergebuehr(4,2.3)==300);
}

void path4(){
	ASSERTM("Path 4: Z0 Z2 Z3 Z5 Z10",berechneSemestergebuehr(7,1.3)==200);
}

void path5(){
	ASSERTM("Path 5: Z0 Z2 Z3 Z6 Z7 Z10",berechneSemestergebuehr(7,1.7)==300);
}

void path6(){
	ASSERTM("Path 6: Z0 Z2 Z3 Z6 Z8 Z10",berechneSemestergebuehr(7,2.3)==400);
}

void path7(){
	ASSERTM("Path 7: Z0 Z2 Z4 Z5 Z9",berechneSemestergebuehr(1,1.0)==200);
}

void path8(){
	ASSERTM("Path 8: Z0 Z2 Z4 Z6 Z7 Z9",berechneSemestergebuehr(1,1.7)==200);
}

void path9(){
	ASSERTM("Path 9: Z0 Z2 Z4 Z6 Z8 Z10",berechneSemestergebuehr(1,2.3)==200);
}

void runAllTests(int argc, char const *argv[]){
	cute::suite s;
	//TODO add your test here
	s.push_back(CUTE(b1));
	s.push_back(CUTE(b2));
	s.push_back(CUTE(b3));


	cute::xml_file_opener xmlfile(argc,argv);
	cute::xml_listener<cute::ide_listener<> >  lis(xmlfile.out);
	cute::makeRunner(lis,argc,argv)(s, "Minimale Termüberdeckung");

	cute::suite s2;
	//TODO add your test here
	s2.push_back(CUTE(path1));
	s2.push_back(CUTE(path2));
	s2.push_back(CUTE(path3));
	s2.push_back(CUTE(path4));
	s2.push_back(CUTE(path5));
	s2.push_back(CUTE(path6));
	s2.push_back(CUTE(path7));
	s2.push_back(CUTE(path8));
	s2.push_back(CUTE(path9));

	cute::xml_file_opener xmlfile2(argc,argv);
	cute::xml_listener<cute::ide_listener<> >  lis2(xmlfile2.out);
	cute::makeRunner(lis,argc,argv)(s2, "Vollständige Pfadüberdeckung");
}

int main(int argc, char const *argv[]){
    runAllTests(argc,argv);
    return 0;
}

