class ButtonManager {
  private:
    int _pin;
    boolean _lastIttButtonPushed = false;
    void (*_onPushed)();

    // Debouce returns the current state of the button after it debouced it 
    //(after press it is high than for a short time low and than finaly high)
    boolean debunceAndGetBtnPushed() {
      boolean current = digitalRead(_pin);
      // when button state changes check again
      if (_lastIttButtonPushed != current) {
        delay(5);
        current = digitalRead(_pin);
      }
    
      return current;
    }
    
  public: 
    ButtonManager(int pin, void (*onPushed)() ) {
      _pin = pin;
      _onPushed = onPushed;
    }

    // calling the passed Funktion if Button was Pushed
    void handleButton() {
      boolean btnPushed = debunceAndGetBtnPushed();
      if (btnPushed == true) {
        if (_lastIttButtonPushed == false) {
          _onPushed();
          _lastIttButtonPushed = true;
        }
      }
      else {
        _lastIttButtonPushed = false;
      }  
    }

    void changeFunction(void (*onPushed)()) {
      _onPushed = onPushed;
    }
};
