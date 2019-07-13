//Justin Sostmann
#include "Terminal.h"
#include "Bauernhof.h"

int main()
{
    Terminal term(60, 30);
    Bauernhof bauernhof(term);

	while (!bauernhof.is_done()) {
    
        bauernhof.update();
        bauernhof.draw();
	}

    term.close();
	return 0;
}
