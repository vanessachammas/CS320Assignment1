
import sys
from another4_1 import * 
from another4_2 import * 

def main():
    print("Assignment #4-3, Vanessa Chammas, vvanessachammas@gmail.com")

    myfile = open(sys.argv[1], "r")

    allTheLines = [] #where my tokenized/parsed will be stored
    linecount = 0

    lines = myfile.readlines()
    allTheLines = [ Tokenize(l) for l in lines ]
    
    #print("hi")
#an array of lists within lists
    #print(allTheLines)
    for i in range (0,len(allTheLines)): 
        trynew = Parse(allTheLines[i])
        
    stack = StackMachine()
    linecount = stack.CurrentLine
    try: 
        while stack.CurrentLine < len(lines):
            #print(allTheLines[stack.CurrentLine])
            executed = stack.Execute(allTheLines[stack.CurrentLine])
            if executed is not None: 
                print(executed)
                    
            #linecount = stack.CurrentLine
   
            if linecount < 0:
                print("Trying to execute invalid line:", linecount)
                break
        print("Program terminated correctly")
        #print(executed)

    except IndexError as i: 
        print("Line " + str(stack.CurrentLine) + ": '" + str(lines) + "' caused " + str(i) + ".")
        sys.exit 



if __name__ == "__main__":
    main()
