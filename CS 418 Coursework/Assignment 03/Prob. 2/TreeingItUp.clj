; TreeingItUp.clj
; Joseph Gareri
; 00099183
; jgareri@my.athens.edu
; Asg 03 | Prob. 2
; Used GPT assistance && samples from internet




(defn insert-node [node lst]
  (if (empty? lst)
    (list node)
    (if (< (first node) (first (first lst)))
      (cons node lst)
      (cons (first lst) (insert-node node (rest lst))))))

(defn insert-tree [tree atom]
  (if (empty? tree)
    (list atom nil nil)
    (if (< atom (first tree))
      (list (first tree) (insert-tree (second tree) atom) (nth tree 2))
      (list (first tree) (second tree) (insert-tree (nth tree 2) atom)))))
          
(insert-tree '() 5)


(defn delete-tree [tree atom]
  (if (empty? tree) nil
      (if (= atom (first tree))
        (if (empty? (nth tree 2)) (second tree)
            (cons (first (nth tree 2))
                  (cons (second tree)
                        (delete-tree (nth tree 2) (first (nth tree 2))))))
        (cons (first tree)
              (cons (delete-tree (second tree) atom)
                    (nth tree 2))))))


(defn check-tree-empty [tree]
  (empty? tree))


(defn member? [tree atom]
  (if (empty? tree) 
    false
    (if (= atom (first tree)) 
      true
      (or (member? (second tree) atom) 
          (member? (nth tree 2) atom)))))


(defn in-order [tree]
  (if (seq (tree)) '()
    (concat (in-order (second tree))
            (cons (first tree)
                  (in-order (nth tree 2))))))


(defn pre-order [tree]
  (if (empty? tree) '()
      (cons (first tree)
            (concat (pre-order (second tree)) 
                    (pre-order (nth tree 2))))))


(defn post-order [tree]
  (if (empty? tree) '()
      (concat (post-order (first tree))
              (concat (post-order (nth tree 2)) 
                      (list (first tree))))))
                     
