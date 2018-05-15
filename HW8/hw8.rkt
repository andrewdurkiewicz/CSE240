(display "Name: Andrew Durkiewicz") (newline) (display "CSE 240 Hw8") (newline)
(newline) (display "Part A") (newline)
(display "1)")
(+ 3 (- 5 7))
(display "2)")
(- (* 2 (+ 8 (+ 5 4))) 25)
(display "3)")
(- 10 (+ (* 3 5) (+ 2 (* 0 5))))
(display "4)")
(* 5 (+ 4 (/ (+ (+ 10 10) (* 5 8)) (+ 10 2))))
(display "5)")
(+ (+ (/ (- (/ (/ (* (+ 3 5) (+ 6 4)) 2) 2) 5) 3) (/ (+ (* 2 10) (* 5 4)) 2)) (* 4 5))

(newline) (display "Part B") (newline)
(define two 2)
(define three 3)
(define four 4)
(define five 5)
(define six 6)
(define ten 10)
(display "Before    ")
(display '(+ (+ (/ (- (/ (/ (* (+ 3 5) (+ 6 4)) 2) 2) 5) 3) (/ (+ (* 2 10) (* 5 4)) 2)) (* 4 5)))
(display " = ")
(+ (+ (/ (- (/ (/ (* (+ 3 5) (+ 6 4)) 2) 2) 5) 3) (/ (+ (* 2 10) (* 5 4)) 2)) (* 4 5))
(display "-------------------------------------------------------------------------------")(newline)
(display "After     ")
(display '(+ (+ (/ (- (/ (/ (* (+ three five) (+ six four)) two) two) five) three) (/ (+ (* two ten) (* five four)) two)) (* four five)))
(display " = ")
(+ (+ (/ (- (/ (/ (* (+ three five) (+ six four)) two) two) five) three) (/ (+ (* two ten) (* five four)) two)) (* four five))

(newline) (display "Part C") (newline)
(define Subtract (lambda (a b) (- a b)))
(display "(Subtract 120 50) outputs: ")
(Subtract 120 50)

(newline) (display "Part D") (newline)
(Define IntDivide (lambda (a b) (if (zero? b) (display "Error Div by Zero!") ;cant div by zero
                    (if (< (abs a) (abs b));is top larger than bottom?
                        0
                        (if (= (+ (abs a) (abs b)) (abs (+ a b)));if |a| + |b| = |a + b| then both have same sign +/-
                            (+ 1 (IntDivide (Subtract a b ) b)) ; recursive 
                             
                            (*(+ 1 (IntDivide (Subtract (abs a) (abs b) ) (abs b))) -1) ;if either a or b are negative we find the solution of -1*(|a|/|b|)
                         )
                        )
                    )
                    )
)
(Display "(IntDivide 8 3) outputs: ")
(IntDivide 8 3)
(Display "(IntDivide 8 -3) outputs: ")
(IntDivide 8 -3)
(Display "(IntDivide -8 3) outputs: ")
(IntDivide -8 3)
(Display "(IntDivide -8 -3) outputs: ")
(IntDivide -8 -3)
(Display "Special Case, DivZero: (IntDivide 8 0) outputs: ")
(IntDivide 8 0) (newline)

(newline) (display "Part E") (newline)
(Define ReadForIntDivide (lambda () (let ((a (read)) (b (read))) (IntDivide a b))))
(ReadForIntDivide) (newline)

(newline) (display "Part F") (newline)
(define Multiply (lambda (a b)          
                   (if (or (= b 0) (= a 0));base case
                       0
                       (if (or (and (negative? a) (negative? b)) (and (positive? a) (positive? b)))
                           (+ (abs a) (Multiply (abs a) (- (abs b) 1)))
                           (* (+ (abs a) (Multiply (abs a) (- (abs b) 1))) -1)
                           )
                       )
                   )
                   )
  
 
(Display "(Multiply 8 3) outputs: ")
(Multiply 8 3)
(Display "(Multiply 8 -3) outputs: ")
(Multiply 8 -3)
(Display "(Multiply -8 3) outputs: ")
(Multiply -8 3)
(Display "(Multiply -8 -3) outputs: ")
(Multiply -8 -3)
(Display "(Multiply 8 0) outputs: ")
(Multiply 8 0)

(newline) (display "Part G") (newline)
(define DiffDivide (lambda (x y) (Subtract x (Multiply (IntDivide x y) y))))
(display "(DiffDivide 8 3) outputs: ")
(DiffDivide 8 3)

(newline) (display "Part H") (newline)
(define explode-helper (lambda (str lst)
  (if (= (string-length str) 1) (append (list (string (string-ref str (- (string-length str) 1)))) lst)
        (explode-helper (substring str 0 (- (string-length str) 1)) (append (list (string (string-ref str (- (string-length str) 1))) ) lst))
                         )
                         )
  )
(define (explode str)
  (explode-helper str (list) ))

(write '(explode "Hello"))
(display " returns:" ) (newline)
(explode "Hello") (newline)
(display "Part I") (newline)
(define implode-helper (lambda (lst str)
  (if (= (length lst) 1) (string-append str (car lst))
        (implode-helper (cdr lst) (string-append str (car lst)))
                         )
                         )
  )
(define (implode lst)
  (implode-helper lst "" ))
(write '(implode '("H" "e" "l" "l" "o")))
(display " returns: ") (newline)
(implode '("H" "e" "l" "l" "o"))

                      

                           










                                                 