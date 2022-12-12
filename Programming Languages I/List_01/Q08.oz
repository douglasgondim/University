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
