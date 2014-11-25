#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"

int berechneLohn(int nStunden,
		int stundenLohn,
		bool praemie){
	int lohn=0;
	int limit=400;
	lohn=nStunden*stundenLohn;
	if(praemie){
		lohn=lohn+lohn/10;
	}
	else{
		lohn=lohn-lohn/100;
	}
	if(lohn>limit){
		lohn=lohn-(lohn-limit)/5;
	}
	return lohn;
}



void path1() {
	ASSERTM("Path 1: Z1 Z2 Z4", berechneLohn(40,20,true)==784);
}
void path2(){
	ASSERTM("Path 2: Z1 Z3 Z4", berechneLohn(40,20,false)==714);
}
void path3(){
	ASSERTM("Path 3: Z1 Z2 Z5", berechneLohn(10,30,true)==330);
}

void path4(){
	ASSERTM("Path 3: Z1 Z3 Z5", berechneLohn(10,30,false)==300);
}
void runAllTests(int argc, char const *argv[]){
	cute::suite s;
	//TODO add your test here
	s.push_back(CUTE(path1));
	s.push_back(CUTE(path2));
	s.push_back(CUTE(path3));
	s.push_back(CUTE(path4));

	cute::xml_file_opener xmlfile(argc,argv);
	cute::xml_listener<cute::ide_listener<> >  lis(xmlfile.out);
	cute::makeRunner(lis,argc,argv)(s, "AllTests");
}

int main(int argc, char const *argv[]){
    runAllTests(argc,argv);
    return 0;
}

