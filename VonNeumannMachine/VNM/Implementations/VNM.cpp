#include "VNM.h"

VonNeumannMachine::VonNeumannMachine() {
    this->memory = new String[100];
    this->maxMemorySize = 100;
    this->currentMemorySize = 4; // First 4 positions are reserved
    for (int i = 0; i < 4; i++) {
        memory[i] = "0";
    }
}

VonNeumannMachine::VonNeumannMachine(int len) {
    this->memory = new String[len];
    this->maxMemorySize = len;
    this->currentMemorySize = 4;
    for (int i = 0; i < 4; i++) {
        memory[i] = "0";
    }
}

char VonNeumannMachine::andGate(char a, char b) {
    int v1 = a - 48;
    int v2 = b - 48;
    int result = v1 & v2;
    return result == 0 ? '0' : '1';
}

char VonNeumannMachine::orGate(char a, char b) {
    int v1 = a - 48;
    int v2 = b - 48;
    int result = v1 | v2;
    return result == 0 ? '0' : '1';
}

char VonNeumannMachine::notGate(char a) {
    int v1 = a - 48;
    int result = (~v1);
    return result == -2 ? '0' : '1';
}

char VonNeumannMachine::xorGate(char a, char b) {
    int v1 = a - 48;
    int v2 = b - 48;
    int result = v1 ^ v2;
    return result == 0 ? '0' : '1';
}

char VonNeumannMachine::op0(char a, char b) { return orGate(a, notGate(a)); }
char VonNeumannMachine::op1(char a, char b) { return orGate(a, notGate(b)); }
char VonNeumannMachine::op2(char a, char b) { return andGate(a, a); }
char VonNeumannMachine::op3(char a, char b) { return xorGate(notGate(a), notGate(b)); }
char VonNeumannMachine::op4(char a, char b) { return notGate(andGate(a, b)); }
char VonNeumannMachine::op5(char a, char b) { return notGate(a); }
char VonNeumannMachine::op6(char a, char b) { return andGate(a, notGate(b)); }
char VonNeumannMachine::op7(char a, char b) { return orGate(notGate(a), notGate(b)); }
char VonNeumannMachine::op8(char a, char b) { return xorGate(a, b); }
char VonNeumannMachine::op9(char a, char b) { return andGate(a, notGate(a)); }
char VonNeumannMachine::opA(char a, char b) { return andGate(b, b); }
char VonNeumannMachine::opB(char a, char b) { return andGate(a, b); }
char VonNeumannMachine::opC(char a, char b) { return notGate(b); }
char VonNeumannMachine::opD(char a, char b) { return notGate(andGate(notGate(a), b)); }
char VonNeumannMachine::opE(char a, char b) { return orGate(a, b); }
char VonNeumannMachine::opF(char a, char b) { return andGate(notGate(a), b); }


String VonNeumannMachine::getPC() { return this->memory[PC]; }
void VonNeumannMachine::setPC(String newPC) { this->memory[PC] = newPC; }

String VonNeumannMachine::getX() { return this->memory[X]; }
void VonNeumannMachine::setX(String newX) { this->memory[X] = newX; }

String VonNeumannMachine::getY() { return this->memory[Y]; }
void VonNeumannMachine::setY(String newY) { this->memory[Y] = newY; }

String VonNeumannMachine::getW() { return this->memory[W]; }
void VonNeumannMachine::setW(String newW) { this->memory[W] = newW; }

bool VonNeumannMachine::registerOperation(String expression) {
    if (currentMemorySize < maxMemorySize) {
        memory[currentMemorySize] = expression;
        currentMemorySize++;
        return true;
    }
    return false;
}

void VonNeumannMachine::operate() {
    for (int i = 4; i < currentMemorySize; i++) {
        String temp = memory[i];
        memory[0] = String(i);
        memory[2] = temp[0];
        memory[3] = temp[1];

        String var0 = fromHexaToBinary(temp[0]);
        String var1 = fromHexaToBinary(temp[1]);
        String result = operate(var0, var1, temp[2]);

        memory[1] = fromBinaryToHexa(result);

        printMemory();
        Serial.println(result);
        //setLeds(result);  this function will be implemented later in this new logic
        delay(3000);
    }
}

String VonNeumannMachine::fromHexaToBinary(char value) {
    switch (value) {
        case '0': return "0000";
        case '1': return "0001";
        case '2': return "0010";
        case '3': return "0011";
        case '4': return "0100";
        case '5': return "0101";
        case '6': return "0110";
        case '7': return "0111";
        case '8': return "1000";
        case '9': return "1001";
        case 'A': return "1010";
        case 'B': return "1011";
        case 'C': return "1100";
        case 'D': return "1101";
        case 'E': return "1110";
        case 'F': return "1111";
    }
}

char VonNeumannMachine::fromBinaryToHexa(String value) {
    if (value == "0000") return '0';
    if (value == "0001") return '1';
    if (value == "0010") return '2';
    if (value == "0011") return '3';
    if (value == "0100") return '4';
    if (value == "0101") return '5';
    if (value == "0110") return '6';
    if (value == "0111") return '7';
    if (value == "1000") return '8';
    if (value == "1001") return '9';
    if (value == "1010") return 'A';
    if (value == "1011") return 'B';
    if (value == "1100") return 'C';
    if (value == "1101") return 'D';
    if (value == "1110") return 'E';
    if (value == "1111") return 'F';
}

String VonNeumannMachine::operate(String var0, String var1, char opCode) {
    String result = "";
    switch (opCode) {
      case '0': for (int i = 0; i < 4; i++) result += op0(var0[i], var1[i]); break;
      case '1': for (int i = 0; i < 4; i++) result += op1(var0[i], var1[i]); break;
      case '2': for (int i = 0; i < 4; i++) result += op2(var0[i], var1[i]); break;
      case '3': for (int i = 0; i < 4; i++) result += op3(var0[i], var1[i]); break;
      case '4': for (int i = 0; i < 4; i++) result += op4(var0[i], var1[i]); break;
      case '5': for (int i = 0; i < 4; i++) result += op5(var0[i], var1[i]); break;
      case '6': for (int i = 0; i < 4; i++) result += op6(var0[i], var1[i]); break;
      case '7': for (int i = 0; i < 4; i++) result += op7(var0[i], var1[i]); break;
      case '8': for (int i = 0; i < 4; i++) result += op8(var0[i], var1[i]); break;
      case '9': for (int i = 0; i < 4; i++) result += op9(var0[i], var1[i]); break;
      case 'A': for (int i = 0; i < 4; i++) result += opA(var0[i], var1[i]); break;
      case 'B': for (int i = 0; i < 4; i++) result += opB(var0[i], var1[i]); break;
      case 'C': for (int i = 0; i < 4; i++) result += opC(var0[i], var1[i]); break;
      case 'D': for (int i = 0; i < 4; i++) result += opD(var0[i], var1[i]); break;
      case 'E': for (int i = 0; i < 4; i++) result += opE(var0[i], var1[i]); break;
      case 'F': for (int i = 0; i < 4; i++) result += opF(var0[i], var1[i]); break;
    }
    return result;
}

void VonNeumannMachine::printMemory() {
    for (int i = 0; i < currentMemorySize; i++) {
        Serial.print(memory[i] + " ");
    }
    Serial.println();
}
