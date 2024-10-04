def hex_operation(X: str, Y: str, W: str) -> str:
    mnemonic_to_hex = {
        "umL": "0",
        "AonB": "1",
        "copiaA": "2",
        "nAxnB": "3",
        "AeBn": "4",
        "nA": "5",
        "AenB": "6",
        "nAonB": "7",
        "AxB": "8",
        "zeroL": "9",
        "copiaB": "A",
        "AeB": "B",
        "nB": "C",
        "nAeBn": "D",
        "AoB": "E",
        "nAeB": "F"
    }

    if W in mnemonic_to_hex:
        return mnemonic_to_hex[W]
    else:
        return "nao existe"

def process_file(file_path):
    X = None
    Y = None

    with open(file_path, 'r') as file:
        lines = file.readlines()

    for line in lines:
        line = line.strip() 

        if line.startswith("X="):
            X = line.split("=")[1].replace(";", "")  
        elif line.startswith("Y="):
            Y = line.split("=")[1].replace(";", "")  
        elif line.startswith("W="):
            W = line.split("=")[1].replace(";", "")  
            if X is not None and Y is not None:
                resultado = hex_operation(X, Y, W)
                print(X + Y + resultado)
            else:
                print("erro")
        elif line == "fim.":
            break 

file_path = "instrucoes.txt" 
process_file(file_path)
