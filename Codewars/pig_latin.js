function isAlpha(ch) {
	return ch.match(/^[a-z]+$/i) !== null;
}
function pigIt(str){
    let str_array = str.split(' ');
    let answer = [];
    str_array.forEach(element => {
        if (!isAlpha(element) ) {
            answer.push(element);
        }
        else {
            var curr = element.slice(1) + element.charAt(0) + 'ay';
            answer.push(curr) ;
        }
    });
    return answer.join(' ');
}
console.assert(pigIt('Pig latin is cool'),'igPay atinlay siay oolcay')
console.assert(pigIt('This is my string'),'hisTay siay ymay tringsay')