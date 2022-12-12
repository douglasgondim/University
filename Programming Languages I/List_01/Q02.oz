declare Permutation FasterComb
fun {Permutation N K}
   if K==0 then 1
   else N*{Permutation N-1 K-1} end
End

fun {FasterComb N K}
   if K==0 then 1
   else {Permutation N K} div {Permutation K K} end
End




declare FastestComb
fun {FastestComb N K}
   if 2*K =< N then {Combination N K}
   else {Combination N N-K} end
end

{Browse {FastestComb 5 2}}

declare Fact Combination
fun {Fact N}
   if N==0 then 1
   else N*{Fact N-1} end
end
fun {Combination N K}
   if K==0 then 1
   else {Fact N}div({Fact N-K}*{Fact K}) end
end
