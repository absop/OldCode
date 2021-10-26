

include("print210.jl")


function partition!(v::AbstractVector, lo::Int, hi::Int, shift::Int64)
    cur = lo
    @inbounds while lo <= hi
        if (v[lo] & shift) != 0
            j = max(cur, lo) + 1
            while j <= hi && (v[j] & shift) != 0; j += 1; end
            j > hi && return lo
            v[lo], v[j] = v[j], v[lo]
            cur = j
        end
        lo += 1
    end
    return lo
end

function BitSort!(v::AbstractVector, lo::Int, hi::Int, shift::Int64)
    if lo < hi && shift > 0
        j = partition!(v, lo, hi, shift)
        width = ndigits(maximum(v), base=2) * j
        println("shift:\t$(Int(log2(shift))),\tlo:\t$lo,\thi:\t$hi")
        print2(v, j)
        BitSort!(v, lo, j - 1, shift >> 1)
        BitSort!(v, j, hi, shift >> 1)
    end
    return v
end


function flp2(n::Int64)
    for i in (1, 2, 4, 8, 16, 32)
        n |= n >> i
    end
    n - (n >> 1)
end

function BitSort!(v::AbstractVector)
    shift = flp2(maximum(v))
    BitSort!(v, 1, length(v), shift)
end


number = 12
v = rand(1:number, number)
v = [9, 8, 7, 5, 5, 6, 3, 4, 10, 4, 2, 1]
print210(v, 12)
BitSort!(v)