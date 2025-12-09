
#include "behavior.h"
/// <summary>
/// ¹Ø¿¨Ñ¡Ôñ
/// </summary>
class UI_LevelSelect :
    public behavior
{
public :
    UI_LevelSelect(scene* _scene) :behavior(_scene) {

    }

    virtual void Start();
    virtual void Loop(double time);

};
