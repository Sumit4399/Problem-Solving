Idea:-
The way to solve this question is using a stack.
We initally push an element into tthe stack(non zero).
When we encounter the next element we check if it is smaller than the element present in the stack if so pop the element from
the stack and push this element.Why? because he current element has the cacpacity of producting a smaller number as compared to the latter.But we have to limit the pops upto k(cuz only k deletions allowed).
​