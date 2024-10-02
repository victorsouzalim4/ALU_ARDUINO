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
    this->currentMemorySize = 4;    //first 4 array positions are reserved areas
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

  String fromHexaToBinary(char value){
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

  }

  char fromBinaryToHexa(String value){
   if(value.compareTo("0000") == 0){
      return '0';
   }else if(value.compareTo("0001") == 0){
       return '1';
   }else if(value.compareTo("0010") == 0){
       return '2';
   }else if(value.compareTo("0011") == 0){
       return '3';
   }else if(value.compareTo("0100") == 0){
       return '4';
   }else if(value.compareTo("0101") == 0){
       return '5';
   }else if(value.compareTo("0110") == 0){
       return '6';
   }else if(value.compareTo("0111") == 0){
       return '7';
   }else if(value.compareTo("1000") == 0){
       return '8';
   }else if(value.compareTo("1001") == 0){
       return '9';
   }else if(value.compareTo("1010") == 0){
       return 'A';
   }else if(value.compareTo("1011") == 0){
       return 'B';
   }else if(value.compareTo("1100") == 0){
       return 'C';
   }else if(value.compareTo("1101") == 0){
       return 'D';
   }else if(value.compareTo("1110") == 0){
       return 'E';
   }else if(value.compareTo("1111") == 0){
       return 'F';
   }else{
    return '0';
   }
   
  }

  
    
 
  
};


void loop(){
  ALU obj;
  while(true){ 
  	if(Serial.available() >= 3){
      String x((char)Serial.read());
      String y((char)Serial.read());
      String w((char)Serial.read());
    	String str = x+y+w;
  
  		Serial.println(str);
  		obj.registerOperation(str);
  		obj.printMemory();
      
      char c = Serial.read(); //get '\n' or 'space' between expressions
  	}
  }
}