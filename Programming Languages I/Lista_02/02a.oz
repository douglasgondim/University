declare A B
A = 10

local MulByn in
   local N in
      N=3
      proc {MulByn X ?Y}
         Y=X*N
      end
   end
   {MulByn A B}
   % N não existe neste contexto
end


