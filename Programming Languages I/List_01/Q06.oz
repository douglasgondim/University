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

declare Add Subtract Multiply Mul1
fun {Add X Y}
   X+Y
end
fun {Subtract X Y}
   X-Y
end
fun {Multiply X Y}
   X*Y
end
fun {Mul1 X Y}
   (X+1)*(Y+1)
end

declare GenericPascalList
fun {GenericPascalList Op N}
   if N==1 then [1]
   else {GenericPascal Op N}|{GenericPascalList Op N-1} end
end

{Browse {GenericPascal Mul1 10}}
