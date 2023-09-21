#include "sugarzas.h"
#include "plants.h"

Alfa* Alfa::_instance = nullptr;
Alfa* Alfa::instance()
{
    if(_instance == nullptr) {
        _instance = new Alfa(1);
    }
    return _instance;
}

Delta* Delta::_instance = nullptr;
Delta* Delta::instance()
{
    if(_instance == nullptr) {
        _instance = new Delta(2);
    }
    return _instance;
}

None* None::_instance = nullptr;
None* None::instance()
{
    if(_instance == nullptr) {
        _instance = new None(3);
    }
    return _instance;
}



