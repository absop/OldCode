# [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
# [10, 18, 24, 28, 30]
# [300, 504, 24]
# [7200, 504]
# [3628800]
# 乘积不变，乘数位数差越小乘得越快
function vectorMul(vector::Vector{BigInt})
    len = length(vector)
    len == 0 && return 1
    # len < 100 && return prod(vector)
    while true
        len < 2 && return vector[1]
        for i = 1:fld(len, 2)
            vector[i] *= vector[len-i+1]
        end
        len = cld(len, 2)
    end
end

function vectorMul(section::OrdinalRange{Int64,Int64})
    return vectorMul(Vector{BigInt}(section))
end


# 2 是一个神奇的数字，我们可以通过不断平方来实现快速幂运算
# 通过二进制位，也可以对多个各具有不同幂次的数进行幂乘运算
#   a1^7 * a2^6 * a3^5 * a4^4 * a5^3 * a6^2 * a7^1
#    111,   110,   101,   100,   011,   010,   001
# = ((a1 * a2 * a3 * a4)^2 * (a1 * a2 * a5 * a6))^2
# * (a1 * a3 * a5 * a7)
function vectorPowMul(primes::Vector{BigInt}, exps::Vector{Int64})
    length(exps) == 0 && return 1
    result, marks = big(1), BitArray(undef, length(exps))

    for i in ndigits(exps[1], base=2)-1:-1:0
        marks .= (exps .>> i) .& 0x1
        result ^= 2
        result *= vectorMul(primes[marks])
    end
    return result
end
