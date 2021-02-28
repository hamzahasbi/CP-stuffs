function toCamelCase(str) {
    let delimiter = str.search('-') != -1 ? '-' : (str.search('_') != -1 ? '_' : '');
    let arrayOfStrings = str.split(delimiter);
    let answer = arrayOfStrings[0];
    arrayOfStrings.slice(1).forEach(element => {
        let f = element.charAt(0).toUpperCase();
        answer += f + element.slice(1);
    });
    return answer == null ? '' : answer;
}
console.log(toCamelCase(''), '');
console.log(toCamelCase("the_stealth_warrior"), "theStealthWarrior");
console.log(toCamelCase("The-Stealth-Warrior"), "TheStealthWarrior");
console.log(toCamelCase("A-B-C"), "ABC");
