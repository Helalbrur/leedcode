// 0020. Valid Parentheses
// Difficulty : Easy
// Tags       : string, stack
// Solved on  : 2022-07-06
// Attempt    : #1
// LeetCode   : https://leetcode.com/problems/valid-parentheses/

class Stack
{
        private $last = -1;
        private $arr = [];
        
        public function push($item)
        {
            $this->last++;
            $this->arr[$this->last] = $item;
        }
        public function pop()
        {
            if($this->last > -1)
            {
                $item = $this->arr[$this->last];
                $this->last--;
                return $item;
            }
            return 'h';
        }
       public function isEmpty()
        {
            if($this->last < 0) return true;
            return false;
        }
}
class Solution {

    /**
     * @param String $s
     * @return Boolean
     */
  
    function isValid($s) {
        $stack = new Stack();
        for($i = 0 ; $i < strlen($s) ; $i++)
        {
            if($s[$i] == '}')
            {
                $top = $stack->pop();
                if($top == '{')
                {
                    
                }
                else {
                    return false;
                }
            }
            else if($s[$i] == ']')
            {
                $top = $stack->pop();
                if($top == '[')
                {
                    
                }
                else {
                    return false;
                }
            }
            else if($s[$i] == ')')
            {
                $top = $stack->pop();
                if($top == '(')
                {
                    
                }
                else {
                    return false;
                }
            }
            else{
                $stack->push($s[$i]);
            }
        }
        if($stack->isEmpty()) return true;
        return false;
    }
}