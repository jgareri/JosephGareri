; TreeingItUp.rkt
; Joseph Gareri
; 00099183
; jgareri@my.athens.edu
; Asg 03 | Prob. 2
; Used GPT assistance && samples from internet

#lang racket


(define (insert-node node lst)
  (if (null? lst)
      (list node)
      (if (< (car node) (car (car lst)))
          (cons node lst)
          (cons (car lst) (insert-node node (cdr lst))))))
          

(define (insert-tree tree atom)
  (if (null? tree)
      (list atom null null)
      (if (< atom (car tree))
          (list (car tree) (insert-tree (cadr tree) atom) (caddr tree))
          (list (car tree) (cadr tree) (insert-tree (caddr tree) atom)))))
          
(insert-tree '() 5)


(define (delete-tree tree atom)
  (if (null? tree) null
      (if (equal? atom (car tree))
          (if (null? (caddr tree)) (cadr tree)
              (cons (caar (caddr tree)) 
                    (cons (cadr tree)
                          (delete-tree (caddr tree) (caar (caddr tree))))))
          (cons (car tree) 
                (cons (delete-tree (cadr tree) atom) 
                      (caddr tree))))))


(define (empty? tree)
  (null? tree))


(define (member? tree atom)
  (if (null? tree) #f
      (if (equal? atom (car tree)) #t
          (or (member? (cadr tree) atom) 
              (member? (caddr tree) atom)))))


(define (in-order tree)
  (if (null? tree) '()
      (append (in-order (cadr tree))
              (cons (car tree) (in-order (caddr tree))))))


(define (pre-order tree)
  (if (null? tree) '()
      (cons (car tree)
            (append (pre-order (cadr tree)) 
                    (pre-order (caddr tree))))))


(define (post-order tree)
  (if (null? tree) '()
      (append (post-order (cadr tree))
              (append (post-order (caddr tree)) 
                      (list (car tree))))))
                     
