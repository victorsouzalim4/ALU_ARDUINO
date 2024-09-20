void setup(){
	Serial.begin(9600);
}

using namespace std;

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
    Serial.println(currentMemorySize);
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
  obj.registerOperation("oi");
  obj.printMemory(); 
  obj.registerOperation("alow");
  obj.printMemory(); 
  delay(100000);
}