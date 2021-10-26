# 如果要考虑最坏的情况，从二进制的角度进行考虑

# 不稳定
function partition!(v::AbstractVector, lo::Int, hi::Int, shift::Int64)
    @inbounds while lo <= hi && (v[lo] & shift) == 0
        lo += 1
    end
    @inbounds while hi >= lo && (v[hi] & shift) != 0
        hi -= 1
    end
    if lo < hi
        v[lo], v[hi] = v[hi], v[lo]
        @inbounds while true
            lo += 1; hi -= 1
            while (v[lo] & shift) == 0; lo += 1; end
            while (v[hi] & shift) != 0; hi -= 1; end
            lo >= hi && break
            v[lo], v[hi] = v[hi], v[lo]
        end
    end
    return lo
end

# Slower!
# function partition!(v::AbstractVector, lo::Int, hi::Int, shift::Int64)
#     cur = lo
#     @inbounds while lo <= hi
#         if (v[lo] & shift) != 0
#             j = max(cur, lo) + 1
#             while j <= hi && (v[j] & shift) != 0; j += 1; end
#             j > hi && return lo
#             v[lo], v[j] = v[j], v[lo]
#             cur = j
#         end
#         lo += 1
#     end
#     return lo
# end


function bsort!(v::AbstractVector, lo::Int, hi::Int, shift::Int64)
    if lo < hi && shift > 0
        j = partition!(v, lo, hi, shift)
        bsort!(v, lo, j - 1, shift >> 1)
        bsort!(v, j, hi, shift >> 1)
    end
    return v
end


function bsort!(v::AbstractVector)
    shift = v[1]
    @inbounds for i in 2:length(v)
        shift |= v[i]
    end
    shift -= (shift >> 1)
    bsort!(v, 1, length(v), shift)
end

bsort(v::AbstractVector) = bsort!(copy(v))


using BenchmarkTools


# 他们是如何做到这么快的？
number = 10^7

u = rand(1:10^7, number)
@time sort!(u)
@assert issorted(u)
reverse!(u)
@time sort!(u)
@assert issorted(u)


v = rand(1:10^7, number)
@time bsort!(v)
@assert issorted(v)
reverse!(v)
@time bsort!(v)
@assert issorted(v)
