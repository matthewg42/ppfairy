#pragma once

class Mode {
public:
    Mode();
    virtual ~Mode() {;}

    // All Modes must also implement a start() function
    virtual void start() = 0;

    // All Modes must also implement a stop() function
    virtual void stop() = 0;

    // Optionally over-ride reset
    virtual void reset() { start(); }

    // This is what should be called from the main program every cycle
    // this will call modeUpdate, which is where derived classed should
    // put their user udate code.  The update() function monitors input
    // voltage and calls enterBrownout() and exitBrownout()
    virtual void update();
    virtual void modeUpdate() = 0;

    // called when vIn drops below BROWNOUT_LOW
    virtual void enterBrownout() {;}
    // called when vIn rises above BROWNOUT_HIGH
    virtual void exitBrownout() {;}

    bool isBrownedOut() { return _brownedOut; }

private:
    bool _brownedOut;
    void _enterBrownout();
    void _exitBrownout();

};

