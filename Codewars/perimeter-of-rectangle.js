function cakes(recipe, available) {
    let answer = 10000000 + 9; 
    for (let key in recipe) {
        if (!available[key]) return 0;
        let curr = Math.floor(available[key] / recipe[key]);
        answer = Math.min(answer, curr);
    }
    return answer;
}
recipe = {flour: 500, sugar: 200, eggs: 1};
available = {flour: 1200, sugar: 1200, eggs: 5, milk: 200};
console.log(cakes(recipe, available));
recipe = {apples: 3, flour: 300, sugar: 150, milk: 100, oil: 100};
available = {sugar: 500, flour: 2000, milk: 2000};
console.log(cakes(recipe, available));
