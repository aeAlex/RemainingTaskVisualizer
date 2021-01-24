#include "lcdManager.h"

// The parrent class of the commands (Command Pattern)
class Mode {
  private:
    
  protected:
    LcdManager* lcdMgr;
  public:
    Mode(LcdManager* manager) {
      lcdMgr = manager;
    }
    virtual void leftButtonPressed();
    virtual void rightButtonPressed();
    virtual void initialize();
};
