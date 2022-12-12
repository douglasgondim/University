let arr = []

for(let i=0; i <50000000; ++i){
    arr.push(Math.floor(Math.random() * 100));
}
arr.sort()

// console.log(arr);