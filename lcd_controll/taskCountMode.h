#include "mode.h"  

class TaskCountMode: public Mode {
  private:
    int _taskCount = 0;

  protected:
    void incrementTasks() {
      _taskCount++;
    }

    void decrementTasks() {
      _taskCount--;
      if (_taskCount < 0) {
        _taskCount = 0;
      }
    }

    void displayTasks() {
      String taskCountString = String(_taskCount); 
      lcdMgr->setDisplayedText("Tasks to do: " + taskCountString);
    }
    
  public:
    TaskCountMode(LcdManager* m) : Mode(m) {

    }

    void leftButtonPressed() {
      decrementTasks();
      displayTasks();
    }

    void rightButtonPressed() {
      incrementTasks();
      displayTasks();
    }

    void initialize() {
      Serial.println("Task Counter Initialized!");
      lcdMgr->setDisplayedText("Task Counter");
    }

};
