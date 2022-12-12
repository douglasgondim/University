function SubSeqMaxSum(a) {
    var max_vect_min = Number.MIN_VALUE, max_soma = 0
    init = 0, end = 0, s = 0

    for (i = 0; i < a.length; i++) {
        max_soma += a[i]
        if (max_soma < 0) {
            max_soma = 0
            s = i + 1
        }

        if (max_vect_min < max_soma) {
            max_vect_min = max_soma
            init = s
            end = i
        }

    }
    return [max_vect_min,a.slice(init,end+1)]
}      


let arr = [5, 1, -5, 7];

console.log(SubSeqMaxSum(arr));

