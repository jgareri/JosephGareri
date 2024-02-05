; Problem1.clj 
; Joseph Gareri
; 00099183
; jgareri@my.athens.edu
; Asg 03 | Prob. 1
; Used GPT assistance && samples from internet

(defn member-twice? [item coll]
  (>= (count (filter #{item} coll)) 2))

(user/member-twice? 5 [1 2 3 4 5 6 5 7 8]) 

(user/member-twice? 10 [1 2 3 4 5 6 7 8 9]) 