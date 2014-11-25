#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"

#include "GeldautomatTest.h"

void runSuite(int argc, char const *argv[]){
	cute::xml_file_opener xmlfile(argc, argv);
	cute::xml_listener<cute::ide_listener<> > lis(xmlfile.out);
	cute::runner<cute::xml_listener<cute::ide_listener<cute::null_listener> > > runner =
			cute::makeRunner(lis, argc, argv);
	runner(GeldautomatTest::makeSuite(),
			"Zinsen Ausdrucken Test");
}

int main(int argc, char const *argv[]){
	runSuite(argc, argv);
    return 0;
}
