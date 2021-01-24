#ifndef LcdManager_h
#define LcdManager_h

class LcdManager {
  private:
    String displayedText = "";
    boolean displayedTextChanged = false;
  protected:

  public:
    LcdManager() {}
    
    void setDisplayedText(String text) {
      displayedText = text;
      this->displayedTextChanged = true;
    }

    String getDisplayedText() {
      this->displayedTextChanged = false;
      return displayedText;
    }

    boolean hasDisplayedTextChanged() {
      return this->displayedTextChanged;
    }
};

#endif
