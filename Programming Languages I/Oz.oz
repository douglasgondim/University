declare
fun {ShiftLeft L}
   case L of H|T then
      H|{ShiftLeft T}
   else [0] end
end

declare
fun {ShiftRight L} 0|L end

declare
fun {OpList Op L1 L2}
   case L1 of H1|T1 then
      case L2 of H2|T2 then
	 {Op H1 H2}|{OpList Op T1 T2}
      end
else nil end
end

fun {GenericPascal Op N}
if N==1 then [1]
else L in
L={GenericPascal Op N-1}
{OpList Op {ShiftLeft L} {ShiftRight L}}
end
end


declare Add Subtract Multiply Mull
fun {Add X Y}
   X+Y
end
fun {Subtract X Y}
   X-Y
end
fun {Multiply X Y}
   X*Y
end
fun {Mull X Y}
   (X+1)*(Y+1)
end

declare GenericPascalList
fun {GenericPascalList Op N}
   if N==1 then [1]
   else {GenericPascal Op N}|{GenericPascalList Op N-1} end
end

{Browse {GenericPascalList Add 7}}
{Browse {GenericPascalList Subtract 7}} % 交互にマイナスが付いた
{Browse {GenericPascalList Multiply 7}} % 二行目以降は全て0
{Browse {GenericPascalList Mull 7}} % 中心ほど増え方が大きい

{Browse {GenericPascal Mull 10}}


local X in
X=23
local X in
X=44
end
{Browse X}
end

local X in
X={NewCell 23}
X:=44
{Browse @X}
end

declare Acc
Acc = {NewCell 0}
declare
fun {Accumulate N}
      Acc:=@Acc+N
      @Acc
end


{Browse {Accumulate 5}}
{Browse {Accumulate 100}}
{Browse {Accumulate 45}}

declare
C={NewCell 0}
thread
C:=1
end
thread
C:=2
end

{Browse @C}

declare
C={NewCell 0}
thread I in
   {Delay 3000}
I=@C
C:=I+1
end
thread J in
J=@C
C:=J+1

   {Browse @C}
end


declare
C={NewCell 0}
L={NewLock}
thread
   lock L then I in
      {Delay 3000}
      I=@C
C:=I+1
end
end
thread
lock L then J in
J=@C
   C:=J+1
   {Browse @C}
end
end
