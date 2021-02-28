function validParentheses(parens) {
    let last = [];
    parens.split('').forEach(element => {
        if (last.length == 0) last.push(element);
        else {
            size = last.length;
            if (last[size - 1] == '(' && element == ')') {
                last.pop();
            }else last.push(element); 
        }
    });
    return last.length == 0;
}
console.log(validParentheses( "()" ) , true);
console.log(validParentheses( "())" ) , false);