let knapsack = []

function fillKnapSack(){
    for(let i=0;i<10;i++){
        knapsack.push({
            weight: Math.floor(Math.random() * 10) + 1
        })
    }
}





fillKnapSack()

console.log(knapsack)