class StackMachine:
    def __init__(self):
        self.CurrentLine = 0
        self.stack = [] #my stack
        self.save = {} #my dictionary
    #def __getitem__(self):
        #return self.stack[tokens]

    def Execute(self, tokens):

        self.CurrentLine += 1
        try:
            #functions with a number
            if tokens[0] == "push":
                self.stack.append(int(tokens[1]))
                return None
            elif tokens[0] == "save":
                val = self.stack.pop() 
                self.save[tokens[1]] = val
                return None
                #self.save.append(tokens[1]) = self.stack.append
            elif tokens[0] == "get":
                if  tokens[1] in self.save:
                    self.stack.append(int(self.save[tokens[1]]))
                    return None
                else:
                    raise IndexError ("Invalid Memory Access")
            #one word functions
            elif tokens[0] == "pop":
                val = self.stack.pop()
                return val 
            elif tokens[0] == "add":
                self.stack.append(self.stack.pop() + self.stack.pop())
                return None 
            elif tokens[0] == "sub":
                self.stack.append(self.stack.pop() - self.stack.pop()) 
                return None
            elif tokens[0] == "mul":
                self.stack.append(self.stack.pop() * self.stack.pop())
                return None
            elif tokens[0] == "div":
                self.stack.append(self.stack.pop() / self.stack.pop())
                return None
            elif tokens[0] == "mod":
                self.stack.append(self.stack.pop() % self.stack.pop())
                return None
            elif tokens[0] == "skip":
                temp1 =  self.stack.pop()
                temp2 =  self.stack.pop()
                if temp1 == 0: 
                    self.CurrentLine += temp2 
                return None
        
            
        except IndexError as error:
            print("Invalid Memory Acces")




