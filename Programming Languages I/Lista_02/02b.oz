declare A B
A = 10

local MulByn in
   local N in
      N=3
      proc {MulByn X ?Y}
	     Y=X*N
      end
   end
   local N in
      N=12
      {MulByn A B}
    % N é 12 neste contexto
   end
end