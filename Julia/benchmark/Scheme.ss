(define println
  (lambda x (for-each display x) (newline)))

(define sum1
  (lambda (n)
    (let loop ([s 0][i 0])
      (if (< i n)
          (loop (+ s (mod i 3)) (+ i 1))
          (+ s i)))))

(println (time (sum1 1000000000)))

; '[] as vector
; (push! vec e) => vec{length=length(vec)+1}
; (push vec e) ->  vec{length=length(vec)}, vec1{length=length(vec)+1}
; vec[1]
; (cons! a )

(define sum2
  (lambda (n)
    (let loop ([s 0][i 0])
      (if (< i n)
          (loop (+ s (mod i 3)) (+ i 1))
          (+ s i)))))

(println (time (sum2 1E9)))

; Scheme
