do
count = 0
dir = 0
value = 1

spider = {

id = 2,
fireRate = 60,
width = 20,
height = 20,
health = 40,
update = function(spider, player)
  --  count = count + dir * value
 --   print("count is ", count);
    if(dir == 0) then
        if count < 40 then
            count = count + 1
            player:move(0,1)
        else
            count = 0
            dir = 1
        end
    elseif(dir == 1) then
        if count < 40 then
            count = count + 1

        else
            count = 0
            dir = 2
        end
    elseif(dir == 2) then
        if count < 40 then
            count = count + 1
            player:move(0,-1)
        else
            count = 0
            dir = 3
        end
        
    elseif(dir == 3) then
        if count < 40 then
            count = count + 1

        else
            count = 0
            dir = 0
        end
    
    else
        dir = 0
        count = 0
     
    end
end
}

function printValue()
    print("Pos ", witch.pos, "Direction ", witch.direction, "Value", witch.value)
end

end
printValue()