
validTokens = ["push","pop","add","sub","mul", "div", "mod","skip","save", "get"]

def Tokenize(str):
    inputsplit = str.split() 

    for x in inputsplit: 
        if (x not in validTokens) and (isNumber(x) is False) :
            raise ValueError("Unexpected Token: " +x)
   
    return inputsplit

    #def isValid(str):
     #  return x in validTokens or x.isdigit() 
        

       #raise ValueError("Unexpect Token: " + invalid[0])
            
def isNumber(s): 
   try:
        int(s)
        return True
   except ValueError:
        return False

def isValid(str):
    return x in isNumber(x) or validTokens 

# --------

def Parse(tokens): 


    validTokens1 = ["pop","add","sub","mul","div","mod","skip"]
    validTokens2 = ["push","save","get"]
    for x in tokens:
       # next = tokens.index(x) + 1
        if len(tokens) == 1:
            if tokens[0] in validTokens1:
                return True
        
        if len(tokens) == 2 :
            if tokens[0] in validTokens2:
                if (isNumber(tokens[1]) is True) :
                    return True 

        else:
            raise ValueError("Parse error at: " +x)

    
