//Justin Sostmann
#include "Bauernhof.h"


Bauernhof::Bauernhof(Terminal& term) :
   
    _is_done(false),
    _term(term), 
    _controlled_animal(0)
{
    
}

bool Bauernhof::is_done() 
{
    return _is_done;
}

void Bauernhof::update() 
{
  
    //x=new Schwein
    //y= new Katze
    //q= terminal beenden
    //o= vorheriges Tier
    //l= nächstes Tier
    //wsda = steuern
    char pressed = _term.get_key();
    switch (pressed) {
        case 'x':
                controll();
                _tiere.push_back(new Schwein);
                
            break;
        case 'y':
                controll();
                _tiere.push_back(new Katze);
                
            break;
        case 'q':
            _is_done = true;
            break;
        case 'o':
            last_controll();
            break;
        case 'l':
            next_controll();
        break;
            default:
            //man kann nur ein Tier steuern, wenn auch eins existiert
        if (!_tiere.empty()){
            
            _tiere[_controlled_animal]->move(pressed);
        }
             break;
    }

}
//malt alle Tiere
void Bauernhof::draw() 
{
  
    _term.clear();
    for (unsigned i=0; i< _tiere.size(); i++){
        _tiere[i]->draw();
    }
    if (!_tiere.empty())
        _tiere[_controlled_animal]->draw_chosen();

    _term.sleep(16);
}

//check ob der vector leer ist, ansonsten zählt es den controll counter hoch
//bedeutet, neu erzeugte tiere werden gesteuert
void Bauernhof::controll(){
    if( _tiere.empty() ){
        _controlled_animal=0;
    }else {
        _controlled_animal++;
    }
}
//geht ein Tier in der Liste zurück, zum steuern
void Bauernhof::last_controll(){
    if (_controlled_animal==0){
        _controlled_animal= _tiere.size()-1;
    }else{
        _controlled_animal--;
    }
}
//geht ein Tier zum steuern vor.
void Bauernhof::next_controll(){
    if (_controlled_animal==_tiere.size()-1){
        _controlled_animal= 0;
    }else{
        _controlled_animal++;
    }
}