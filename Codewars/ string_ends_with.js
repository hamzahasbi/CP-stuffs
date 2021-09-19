function solution(str, ending){
  // limit testing api knowledge.
  // could also use endswith.
  return str.split('').reverse().join('').indexOf(ending.split('').reverse().join('')) === 0;
}