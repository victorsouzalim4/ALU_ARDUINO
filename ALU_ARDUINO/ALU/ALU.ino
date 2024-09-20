void setup(){
	Serial.begin(9600);
}

using namespace std;

String map(char value){
  switch(value){
    case '0':
      return "0000";
    case '1':
      return "0001";
    case '2':
      return "0010";
    case '3':
      return "0011";
    case '4':
      return "0100";
    case '5':
      return "0101";
    case '6':
      return "0110";
    case '7':
      return "0111";
    case '8':
      return "1000";
    case '9':
      return "1001";
    case 'A':
      return "1010";
    case 'B':
      return "1011";
    case 'C':
      return "1100";
    case 'D':
      return "1101";
    case 'E':
      return "1110";
    case 'F':
      return "1111";
  }

};

class ALU{
  private:
  String* memory;
  int currentMemorySize;
  int maxMemorySize;
  const int PC = 0;
  const int X = 1;
  const int Y = 2;
  const int W = 3;
  
  public:
  ALU(){
	this->memory = new String[100];
    this->maxMemorySize = 100;
    this->currentMemorySize = 4;
    for(int i = 0; i < 4; i++){
      memory[i] = "0";
    }
  }
  ALU(int len){
	this->memory = new String[len];
    this->maxMemorySize = len;
    this->currentMemorySize = 4;
    for(int i = 0; i < 4; i++){
      memory[i] = "0";
    }
  }
  
  bool registerOperation(String expression){
    if(currentMemorySize < maxMemorySize){
      memory[currentMemorySize] = expression;
      currentMemorySize++;
      return true;
    }
    return false;
  }
  
  void printMemory(){
    for(int i = 0; i < currentMemorySize; i++){
      Serial.print(memory[i] + " ");
    }
    Serial.println();
  }
  
  String getPC(){
    return this->memory[PC];
  }
  void setPC(String newPC){
    this->memory[PC] = newPC;
  }
  
  String getX(){
    return this->memory[X];
  }
  void setX(String newX){
    this->memory[X] = newX;
  }
  
  String getY(){
    return this->memory[Y];
  }
  void setY(String newY){
    this->memory[Y] = newY;
  }
  
  String getW(){
    return this->memory[W];
  }
  void setW(String newW){
    this->memory[W] = newW;
  }
  
 
  
};

void loop(){
  ALU obj;
  
  while(true){
      
  	if(Serial.available() > 0){
    	char c = Serial.read();
  
  		String test = map(c);
  		Serial.println(test);
  
  		obj.registerOperation(test);
  		obj.printMemory(); 
  	}
  }
}