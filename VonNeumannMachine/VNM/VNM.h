#ifndef VON_NEUMANN_MACHINE_H
#define VON_NEUMANN_MACHINE_H

#include <Arduino.h>

class VonNeumannMachine {
private:
    String* memory;
    int currentMemorySize;
    int maxMemorySize;
    const int PC = 0;
    const int W = 1;
    const int X = 2;
    const int Y = 3;

    char andGate(char a, char b);
    char orGate(char a, char b);
    char notGate(char a);
    char xorGate(char a, char b);

    char op0(char a, char b);
    char op1(char a, char b);
    char op2(char a, char b);
    char op3(char a, char b);
    char op4(char a, char b);
    char op5(char a, char b);
    char op6(char a, char b);
    char op7(char a, char b);
    char op8(char a, char b);
    char op9(char a, char b);
    char opA(char a, char b);
    char opB(char a, char b);
    char opC(char a, char b);
    char opD(char a, char b);
    char opE(char a, char b);
    char opF(char a, char b);

public:

    VonNeumannMachine();
    VonNeumannMachine(int len);

    String getPC();
    void setPC(String newPC);
    
    String getX();
    void setX(String newX);

    String getY();
    void setY(String newY);

    String getW();
    void setW(String newW);

    bool registerOperation(String expression);
    void operate();

    String fromHexaToBinary(char value);
    char fromBinaryToHexa(String value);
    String operate(String var0, String var1, char opCode);
    void printMemory();
};

#endif
