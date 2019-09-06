function pprint(t)
    for k,v in pairs(t)
    do  
        print(tostring(k)..': '..tostring(v))
    end
end


function InfixToPostfix(str)

operatorstack = {}
numberstack = {}
i=0

prec = {}
prec["*"] = 2
prec["/"] = 2
prec["+"] = 1
prec["-"] = 1




    for j in str:gmatch("%S+") do
    
        if(j == "*" or j== "/" or j == "+" or j == "-") then 
            while(#operatorstack > 0 and prec[ operatorstack[1] ]  >= prec[ j ]) do
                table.insert(numberstack, table.remove(operatorstack,1))
            end
            table.insert(operatorstack,1,j)
        else
            --not an operator
            table.insert(numberstack,j)
        end
    end
   -- print("nums")
   -- pprint(numberstack)
   -- print("ops")
    --pprint(operatorstack)
    --print(postfix)
    while operatorstack[1] ~= nil do
       -- change = table.remove(operatorstack,1)
        --table.insert(numberstack,1)
        table.insert(numberstack, table.remove(operatorstack,1))
    end
--print("nums")
  --  pprint(numberstack)
  --  print("ops")
  --  pprint(operatorstack)
    postfix = numberstack[1]
    for j = 2, #numberstack do 
        postfix = postfix.. " "..numberstack[j]
  --      print("in postfix builder ".. tostring(j) .. " " .. postfix)
    end
--print("hi")
--print(postfix)
        header = "Assignment #3-2, Vanessa Chammas, vvanessachammas@gmail.com \n"
        return header .. postfix
        end

